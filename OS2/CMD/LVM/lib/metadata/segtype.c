/*
 * Copyright (C) 2003-2004 Sistina Software, Inc. All rights reserved.
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

#include "lib.h"
#include "toolcontext.h"
#include "segtype.h"

struct segment_type *get_segtype_from_string(struct cmd_context *cmd,
                                             const char *str)
{
        struct segment_type *segtype;

        //list_iterate_items(segtype, &cmd->segtypes) {
        list_iterate_items(segtype, struct segment_type, &cmd->segtypes) {
                if (!strcmp(segtype->name, str))
                        return segtype;
        }

        log_error("Unrecognised segment type %s", str);
        return NULL;
}
