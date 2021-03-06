/*
 * Copyright (C) 2001-2004 Sistina Software, Inc. All rights reserved.  
 * Copyright (C) 2004 Red Hat, Inc. All rights reserved.
 *
 * This file is part of LVM2.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU General Public License v.2.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 * Translates between disk and in-core formats.
 */

#include "lib.h"
#include "disk-rep.h"
#include "lvm-string.h"
#include "filter.h"
#include "toolcontext.h"
#include "segtype.h"
#include "pv_alloc.h"
#include "display.h"

#include <libdevmapper.h>

#include <time.h>

static int _check_vg_name(const char *name)
{
	return strlen(name) < NAME_LEN;
}

/*
 * Extracts the last part of a path.
 */
static char *_create_lv_name(struct dm_pool *mem, const char *full_name)
{
	const char *ptr = strrchr(full_name, '/');

	if (!ptr)
		ptr = full_name;
	else
		ptr++;

	return dm_pool_strdup(mem, ptr);
}

int import_pv(const struct format_type *fmt, struct dm_pool *mem,
	      struct device *dev, struct volume_group *vg,
	      struct physical_volume *pv, struct pv_disk *pvd,
	      struct vg_disk *vgd)
{
	uint64_t size;

	memset(pv, 0, sizeof(*pv));
	memcpy(&pv->id, pvd->pv_uuid, ID_LEN);

	pv->dev = dev;
	if (!(pv->vg_name = dm_pool_strdup(mem, (char *)pvd->vg_name))) {
		stack;
		return 0;
	}

	memcpy(&pv->vgid, vgd->vg_uuid, sizeof(vg->id));

	/* Store system_id from first PV if PV belongs to a VG */
	if (vg && !*vg->system_id)
		strncpy(vg->system_id, (char *)pvd->system_id, NAME_LEN);

	if (vg &&
	    strncmp(vg->system_id, (char *)pvd->system_id, sizeof(pvd->system_id)))
		    log_very_verbose("System ID %s on %s differs from %s for "
				     "volume group", pvd->system_id,
				     dev_name(pv->dev), vg->system_id);

	/*
	 * If exported, we still need to flag in pv->status too because
	 * we don't always have a struct volume_group when we need this.
	 */
	if (pvd->pv_status & VG_EXPORTED)
		pv->status |= EXPORTED_VG;

	if (pvd->pv_allocatable)
		pv->status |= ALLOCATABLE_PV;

	pv->size = pvd->pv_size;
	pv->pe_size = pvd->pe_size;
	pv->pe_start = pvd->pe_start;
	pv->pe_count = pvd->pe_total;
	pv->pe_alloc_count = 0;

	/* Fix up pv size if missing */
	if (!pv->size) {
		if (!dev_get_size(dev, &pv->size)) {
			log_error("%s: Couldn't get size.", dev_name(pv->dev));
			return 0;
		}
		log_verbose("Fixing up missing format1 size (%s) "
			    "for PV %s", display_size(fmt->cmd, pv->size),
			    dev_name(pv->dev));
		if (vg) {
			size = pv->pe_count * (uint64_t) vg->extent_size +
			       pv->pe_start;
			if (size > pv->size)
				log_error("WARNING: Physical Volume %s is too "
					  "large for underlying device",
					  dev_name(pv->dev));
		}
	}

	list_init(&pv->tags);
	list_init(&pv->segments);

	if (!alloc_pv_segment_whole_pv(mem, pv)) {
		stack;
		return 0;
	}

	return 1;
}

static int _system_id(struct cmd_context *cmd, char *s, const char *prefix)
{

	if (dm_snprintf(s, NAME_LEN, "%s%s%lu",
			 prefix, cmd->hostname, time(NULL)) < 0) {
		log_error("Generated system_id too long");
		return 0;
	}

	return 1;
}

int export_pv(struct cmd_context *cmd, struct dm_pool *mem,
	      struct volume_group *vg,
	      struct pv_disk *pvd, struct physical_volume *pv)
{
	memset(pvd, 0, sizeof(*pvd));

	pvd->id[0] = 'H';
	pvd->id[1] = 'M';
	pvd->version = 1;

	memcpy(pvd->pv_uuid, pv->id.uuid, ID_LEN);

	if (pv->vg_name) {
		if (!_check_vg_name(pv->vg_name)) {
			stack;
			return 0;
		}
		strncpy((char *)pvd->vg_name, pv->vg_name, sizeof(pvd->vg_name));
	}

	/* Preserve existing system_id if it exists */
	if (vg && *vg->system_id)
		strncpy((char *)pvd->system_id, vg->system_id, sizeof(pvd->system_id));

	/* Is VG already exported or being exported? */
	if (vg && (vg->status & EXPORTED_VG)) {
		/* Does system_id need setting? */
		if (!*vg->system_id ||
		    strncmp(vg->system_id, EXPORTED_TAG,
			    sizeof(EXPORTED_TAG) - 1)) {
			if (!_system_id(cmd, (char *)pvd->system_id, EXPORTED_TAG)) {
				stack;
				return 0;
			}
		}
		if (strlen((char *)pvd->vg_name) + sizeof(EXPORTED_TAG) >
		    sizeof(pvd->vg_name)) {
			log_error("Volume group name %s too long to export",
				  pvd->vg_name);
			return 0;
		}
		strcat((char *)pvd->vg_name, EXPORTED_TAG);
	}

	/* Is VG being imported? */
	if (vg && !(vg->status & EXPORTED_VG) && *vg->system_id &&
	    !strncmp(vg->system_id, EXPORTED_TAG, sizeof(EXPORTED_TAG) - 1)) {
		if (!_system_id(cmd, (char *)pvd->system_id, IMPORTED_TAG)) {
			stack;
			return 0;
		}
	}

	/* Generate system_id if PV is in VG */
	if (!pvd->system_id || !*pvd->system_id)
		if (!_system_id(cmd, (char *)pvd->system_id, "")) {
			stack;
			return 0;
		}

	/* Update internal system_id if we changed it */
	if (vg &&
	    (!*vg->system_id ||
	     strncmp(vg->system_id, (char *)pvd->system_id, sizeof(pvd->system_id))))
		    strncpy(vg->system_id, (char *)pvd->system_id, NAME_LEN);

	//pvd->pv_major = MAJOR(pv->dev);

	if (pv->status & ALLOCATABLE_PV)
		pvd->pv_allocatable = PV_ALLOCATABLE;

	pvd->pv_size = pv->size;
	pvd->lv_cur = 0;	/* this is set when exporting the lv list */
	if (vg)
		pvd->pe_size = vg->extent_size;
	else
		pvd->pe_size = pv->pe_size;
	pvd->pe_total = pv->pe_count;
	pvd->pe_allocated = pv->pe_alloc_count;
	pvd->pe_start = pv->pe_start;

	return 1;
}

int import_vg(struct dm_pool *mem,
	      struct volume_group *vg, struct disk_list *dl, int partial)
{
	struct vg_disk *vgd = &dl->vgd;
	memcpy(vg->id.uuid, vgd->vg_uuid, ID_LEN);

	if (!_check_vg_name((char *)dl->pvd.vg_name)) {
		stack;
		return 0;
	}

	if (!(vg->name = dm_pool_strdup(mem, (char *)dl->pvd.vg_name))) {
		stack;
		return 0;
	}

	if (!(vg->system_id = dm_pool_alloc(mem, NAME_LEN))) {
		stack;
		return 0;
	}

	*vg->system_id = '\0';

	if (vgd->vg_status & VG_EXPORTED)
		vg->status |= EXPORTED_VG;

	if (vgd->vg_status & VG_EXTENDABLE)
		vg->status |= RESIZEABLE_VG;

	if (partial || (vgd->vg_access & VG_READ))
		vg->status |= LVM_READ;

	if (!partial && (vgd->vg_access & VG_WRITE))
		vg->status |= LVM_WRITE;

	if (vgd->vg_access & VG_CLUSTERED)
		vg->status |= CLUSTERED;

	if (vgd->vg_access & VG_SHARED)
		vg->status |= SHARED;

	vg->extent_size = vgd->pe_size;
	vg->extent_count = vgd->pe_total;
	vg->free_count = vgd->pe_total;
	vg->max_lv = vgd->lv_max;
	vg->max_pv = vgd->pv_max;
	vg->alloc = ALLOC_NORMAL;

	if (partial)
		vg->status |= PARTIAL_VG;

	return 1;
}

int export_vg(struct vg_disk *vgd, struct volume_group *vg)
{
	memset(vgd, 0, sizeof(*vgd));
	memcpy(vgd->vg_uuid, vg->id.uuid, ID_LEN);

	if (vg->status & LVM_READ)
		vgd->vg_access |= VG_READ;

	if (vg->status & LVM_WRITE)
		vgd->vg_access |= VG_WRITE;

	if (vg->status & CLUSTERED)
		vgd->vg_access |= VG_CLUSTERED;

	if (vg->status & SHARED)
		vgd->vg_access |= VG_SHARED;

	if (vg->status & EXPORTED_VG)
		vgd->vg_status |= VG_EXPORTED;

	if (vg->status & RESIZEABLE_VG)
		vgd->vg_status |= VG_EXTENDABLE;

	vgd->lv_max = vg->max_lv;
	vgd->lv_cur = vg->lv_count;

	vgd->pv_max = vg->max_pv;
	vgd->pv_cur = vg->pv_count;

	vgd->pe_size = vg->extent_size;
	vgd->pe_total = vg->extent_count;
	vgd->pe_allocated = vg->extent_count - vg->free_count;

	return 1;
}

int import_lv(struct dm_pool *mem, struct logical_volume *lv, struct lv_disk *lvd)
{
	lvid_from_lvnum(&lv->lvid, &lv->vg->id, lvd->lv_number);

	if (!(lv->name = _create_lv_name(mem, (char *)lvd->lv_name))) {
		stack;
		return 0;
	}

	lv->status |= VISIBLE_LV;

	if (lvd->lv_status & LV_SPINDOWN)
		lv->status |= SPINDOWN_LV;

	if (lvd->lv_status & LV_PERSISTENT_MINOR) {
		lv->status |= FIXED_MINOR;
		lv->minor = MINOR(lvd->lv_dev);
		lv->major = MAJOR(lvd->lv_dev);
	} else {
		lv->major = -1;
		lv->minor = -1;
	}

	if (lvd->lv_access & LV_READ)
		lv->status |= LVM_READ;

	if (lvd->lv_access & LV_WRITE)
		lv->status |= LVM_WRITE;

	if (lvd->lv_badblock)
		lv->status |= BADBLOCK_ON;

	/* Drop the unused LV_STRICT here */
	if (lvd->lv_allocation & LV_CONTIGUOUS)
		lv->alloc = ALLOC_CONTIGUOUS;
	else
		lv->alloc = ALLOC_NORMAL;

	lv->read_ahead = lvd->lv_read_ahead;
	lv->size = lvd->lv_size;
	lv->le_count = lvd->lv_allocated_le;

	lv->snapshot = NULL;
	list_init(&lv->snapshot_segs);
	list_init(&lv->segments);
	list_init(&lv->tags);

	return 1;
}

static void _export_lv(struct lv_disk *lvd, struct volume_group *vg,
		       struct logical_volume *lv, const char *dev_dir)
{
	memset(lvd, 0, sizeof(*lvd));
	snprintf((char *)lvd->lv_name, sizeof(lvd->lv_name), "%s%s/%s",
		 dev_dir, vg->name, lv->name);

	strcpy((char *)lvd->vg_name, vg->name);

	if (lv->status & LVM_READ)
		lvd->lv_access |= LV_READ;

	if (lv->status & LVM_WRITE)
		lvd->lv_access |= LV_WRITE;

	if (lv->status & SPINDOWN_LV)
		lvd->lv_status |= LV_SPINDOWN;

	if (lv->status & FIXED_MINOR) {
		lvd->lv_status |= LV_PERSISTENT_MINOR;
		lvd->lv_dev = MKDEV(lv->major, lv->minor);
	} else {
		lvd->lv_dev = MKDEV(LVM_BLK_MAJOR, lvnum_from_lvid(&lv->lvid));
	}

	lvd->lv_read_ahead = lv->read_ahead;
	lvd->lv_stripes =
	    list_item(lv->segments.n, struct lv_segment)->area_count;
	lvd->lv_stripesize =
	    list_item(lv->segments.n, struct lv_segment)->stripe_size;

	lvd->lv_size = lv->size;
	lvd->lv_allocated_le = lv->le_count;

	if (lv->status & BADBLOCK_ON)
		lvd->lv_badblock = LV_BADBLOCK_ON;

	if (lv->alloc == ALLOC_CONTIGUOUS)
		lvd->lv_allocation |= LV_CONTIGUOUS;
}

int export_extents(struct disk_list *dl, uint32_t lv_num,
		   struct logical_volume *lv, struct physical_volume *pv)
{
	struct pe_disk *ped;
	struct lv_segment *seg;
	uint32_t pe, s;

	list_iterate_items(seg, struct lv_segment, &lv->segments) {
		for (s = 0; s < seg->area_count; s++) {
			if (!(seg->segtype->flags & SEG_FORMAT1_SUPPORT)) {
				log_error("Segment type %s in LV %s: "
					  "unsupported by format1",
					  seg->segtype->name, lv->name);
				return 0;
			}
			if (seg_type(seg, s) != AREA_PV) {
				log_error("Non-PV stripe found in LV %s: "
					  "unsupported by format1", lv->name);
				return 0;
			}
			if (seg_pv(seg, s) != pv)
				continue;	/* not our pv */

			for (pe = 0; pe < (seg->len / seg->area_count); pe++) {
				ped = &dl->extents[pe + seg_pe(seg, s)];
				ped->lv_num = lv_num;
				ped->le_num = (seg->le / seg->area_count) + pe +
				    s * (lv->le_count / seg->area_count);
			}
		}
	}

	return 1;
}

int import_pvs(const struct format_type *fmt, struct dm_pool *mem,
	       struct volume_group *vg,
	       struct list *pvds, struct list *results, uint32_t *count)
{
	struct disk_list *dl;
	struct pv_list *pvl;

	*count = 0;
	list_iterate_items(dl, struct disk_list, pvds) {
		if (!(pvl = dm_pool_zalloc(mem, sizeof(*pvl))) ||
		    !(pvl->pv = dm_pool_alloc(mem, sizeof(*pvl->pv)))) {
			stack;
			return 0;
		}

		if (!import_pv(fmt, mem, dl->dev, vg, pvl->pv, &dl->pvd, &dl->vgd)) {
			stack;
			return 0;
		}

		pvl->pv->fmt = fmt;
		list_add(results, &pvl->list);
		(*count)++;
	}

	return 1;
}

static struct logical_volume *_add_lv(struct dm_pool *mem,
				      struct volume_group *vg,
				      struct lv_disk *lvd)
{
	struct lv_list *ll;
	struct logical_volume *lv;

	if (!(ll = dm_pool_zalloc(mem, sizeof(*ll))) ||
	    !(ll->lv = dm_pool_zalloc(mem, sizeof(*ll->lv)))) {
		stack;
		return NULL;
	}
	lv = ll->lv;
	lv->vg = vg;

	if (!import_lv(mem, lv, lvd)) {
		stack;
		return NULL;
	}

	list_add(&vg->lvs, &ll->list);
	vg->lv_count++;

	return lv;
}

int import_lvs(struct dm_pool *mem, struct volume_group *vg, struct list *pvds)
{
	struct disk_list *dl;
	struct lvd_list *ll;
	struct lv_disk *lvd;

	list_iterate_items(dl, struct disk_list, pvds) {
		list_iterate_items(ll, struct lvd_list, &dl->lvds) {
			lvd = &ll->lvd;

			if (!find_lv(vg, (char *)lvd->lv_name) &&
			    !_add_lv(mem, vg, lvd)) {
				stack;
				return 0;
			}
		}
	}

	return 1;
}

/* FIXME: tidy */
int export_lvs(struct disk_list *dl, struct volume_group *vg,
	       struct physical_volume *pv, const char *dev_dir)
{
	int r = 0;
	struct lv_list *ll;
	struct lvd_list *lvdl;
	size_t len;
	uint32_t lv_num;
	struct dm_hash_table *lvd_hash;

	if (!_check_vg_name(vg->name)) {
		stack;
		return 0;
	}

	if (!(lvd_hash = dm_hash_create(32))) {
		stack;
		return 0;
	}

	/*
	 * setup the pv's extents array
	 */
	len = sizeof(struct pe_disk) * dl->pvd.pe_total;
	if (!(dl->extents = dm_pool_alloc(dl->mem, len))) {
		stack;
		goto out;
	}
	memset(dl->extents, 0, len);

	list_iterate_items(ll, struct lv_list, &vg->lvs) {
		if (ll->lv->status & SNAPSHOT)
			continue;

		if (!(lvdl = dm_pool_alloc(dl->mem, sizeof(*lvdl)))) {
			stack;
			goto out;
		}

		_export_lv(&lvdl->lvd, vg, ll->lv, dev_dir);

		lv_num = lvnum_from_lvid(&ll->lv->lvid);
		lvdl->lvd.lv_number = lv_num;

		if (!dm_hash_insert(lvd_hash, ll->lv->name, &lvdl->lvd)) {
			stack;
			goto out;
		}

		if (!export_extents(dl, lv_num + 1, ll->lv, pv)) {
			stack;
			goto out;
		}

		if (lv_is_origin(ll->lv))
			lvdl->lvd.lv_access |= LV_SNAPSHOT_ORG;

		if (lv_is_cow(ll->lv)) {
			lvdl->lvd.lv_access |= LV_SNAPSHOT;
			lvdl->lvd.lv_chunk_size = ll->lv->snapshot->chunk_size;
			lvdl->lvd.lv_snapshot_minor =
			    lvnum_from_lvid(&ll->lv->snapshot->origin->lvid);
		}

		list_add(&dl->lvds, &lvdl->list);
		dl->pvd.lv_cur++;
	}

	r = 1;

      out:
	dm_hash_destroy(lvd_hash);
	return r;
}

/*
 * FIXME: More inefficient code.
 */
int import_snapshots(struct dm_pool *mem, struct volume_group *vg,
		     struct list *pvds)
{
	struct logical_volume *lvs[MAX_LV];
	struct disk_list *dl;
	struct lvd_list *ll;
	struct lv_disk *lvd;
	int lvnum;
	struct logical_volume *org, *cow;

	/* build an index of lv numbers */
	memset(lvs, 0, sizeof(lvs));
	list_iterate_items(dl, struct disk_list, pvds) {
		list_iterate_items(ll, struct lvd_list, &dl->lvds) {
			lvd = &ll->lvd;

			lvnum = lvd->lv_number;

			if (lvnum >= MAX_LV) {
				log_err("Logical volume number "
					"out of bounds.");
				return 0;
			}

			if (!lvs[lvnum] &&
			    !(lvs[lvnum] = find_lv(vg, (char *)lvd->lv_name))) {
				log_err("Couldn't find logical volume '%s'.",
					lvd->lv_name);
				return 0;
			}
		}
	}

	/*
	 * Now iterate through yet again adding the snapshots.
	 */
	list_iterate_items(dl, struct disk_list, pvds) {
		list_iterate_items(ll, struct lvd_list, &dl->lvds) {
			lvd = &ll->lvd;

			if (!(lvd->lv_access & LV_SNAPSHOT))
				continue;

			lvnum = lvd->lv_number;
			cow = lvs[lvnum];
			if (!(org = lvs[lvd->lv_snapshot_minor])) {
				log_err("Couldn't find origin logical volume "
					"for snapshot '%s'.", lvd->lv_name);
				return 0;
			}

			/* we may have already added this snapshot */
			if (lv_is_cow(cow))
				continue;

			/* insert the snapshot */
			if (!vg_add_snapshot(vg->fid, NULL, org, cow, NULL,
					     org->le_count, 
					     lvd->lv_chunk_size)) {
				log_err("Couldn't add snapshot.");
				return 0;
			}
		}
	}

	return 1;
}

int export_uuids(struct disk_list *dl, struct volume_group *vg)
{
	struct uuid_list *ul;
	struct pv_list *pvl;

	list_iterate_items(pvl, struct pv_list, &vg->pvs) {
		if (!(ul = dm_pool_alloc(dl->mem, sizeof(*ul)))) {
			stack;
			return 0;
		}

		memset(ul->uuid, 0, sizeof(ul->uuid));
		memcpy(ul->uuid, pvl->pv->id.uuid, ID_LEN);

		list_add(&dl->uuids, &ul->list);
	}
	return 1;
}

/*
 * This calculates the nasty pv_number field
 * used by LVM1.
 */
void export_numbers(struct list *pvds, struct volume_group *vg)
{
	struct disk_list *dl;
	int pv_num = 1;

	list_iterate_items(dl, struct disk_list, pvds)
		dl->pvd.pv_number = pv_num++;
}

/*
 * Calculate vg_disk->pv_act.
 */
void export_pv_act(struct list *pvds)
{
	struct disk_list *dl;
	int act = 0;

	list_iterate_items(dl, struct disk_list, pvds)
		if (dl->pvd.pv_status & PV_ACTIVE)
			act++;

	list_iterate_items(dl, struct disk_list, pvds)
		dl->vgd.pv_act = act;
}

int export_vg_number(struct format_instance *fid, struct list *pvds,
		     const char *vg_name, struct dev_filter *filter)
{
	struct disk_list *dl;
	int vg_num;

	if (!get_free_vg_number(fid, filter, vg_name, &vg_num)) {
		stack;
		return 0;
	}

	list_iterate_items(dl, struct disk_list, pvds)
		dl->vgd.vg_number = vg_num;

	return 1;
}
