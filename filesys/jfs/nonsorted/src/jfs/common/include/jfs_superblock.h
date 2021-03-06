/* $Id: jfs_superblock.h,v 1.1 2000/04/21 10:57:59 ktk Exp $ */

/* static char *SCCSID = "@(#)1.9  7/30/98 14:07:37 src/jfs/common/include/jfs_superblock.h, sysjfs, w45.fs32, 990417.1";
 *
 *   Copyright (c) International Business Machines  Corp., 2000
 *
 *   This program is free software;  you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or 
 *   (at your option) any later version.
 * 
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY;  without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 *   the GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program;  if not, write to the Free Software 
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef	_H_JFS_SUPERBLOCK
#define _H_JFS_SUPERBLOCK	
/*
 *	jfs_superblock.h
 */

#ifndef _JFS_OS2
#include <sys/time.h>
#endif /* _JFS_OS2 */

/*
 * make the magic number something a human could read
 */
#define JFS_MAGIC "JFS1"	/* Magic word: Version 1 */

#define JFS_VERSION	1	/* Version number: Version 1 */

#define LV_NAME_SIZE	11	/* MUST BE 11 for OS/2 boot sector */

/* 
 *	aggregate superblock 
 */
struct superblock
{
	char	s_magic[4];	/* 4: magic number */
	uint32	s_version;	/* 4: version number */

	int64	s_size;		/* 8: aggregate size in hardware/LVM blocks;
				 * VFS+: number of blocks
				 */
	int32	s_bsize;	/* 4: aggregate block size in bytes; 
				 * VFS+: fragment size
				 */
	int16	s_l2bsize;	/* 2: log2 of s_bsize */
	int16	s_l2bfactor;	/* 2: log2(s_bsize/hardware block size) */
	int32	s_pbsize;	/* 4: hardware/LVM block size in bytes */
	int16	s_l2pbsize;	/* 2: log2 of s_pbsize */
	int16	pad;		/* 2: padding necessary for alignment */

	uint32	s_agsize;	/* 4: allocation group size in aggr. blocks */

	uint32	s_flag;		/* 4: aggregate attributes:
				 *    see jfs_filsys.h
				 */ 
	uint32	s_state;	/* 4: mount/unmount/recovery state: 
				 *    see jfs_filsys.h
				 */
	int32	s_compress;	/* 4: > 0 if data compression */

	pxd_t	s_ait2;		/* 8: first extent of secondary
				 *    aggregate inode table
				 */

	pxd_t	s_aim2;		/* 8: first extent of secondary
				 *    aggregate inode map
				 */
	dev_t	s_logdev;	/* 4: device address of log */
	int32	s_logserial;	/* 4: log serial number at aggregate mount */
	pxd_t	s_logpxd;	/* 8: inline log extent */

	pxd_t	s_fsckpxd;	/* 8: inline fsck work space extent */

	struct timestruc_t	s_time;	/* 8: time last updated */

        int32   s_fsckloglen;   /* 4: Number of filesystem blocks reserved for
                                 *    the fsck service log.  
                                 *    N.B. These blocks are divided among the
                                 *         versions kept.  This is not a per
                                 *         version size.
                                 *    N.B. These blocks are included in the 
                                 *         length field of s_fsckpxd.
                                 */
        int8    s_fscklog;      /* 1: which fsck service log is most recent
                                 *    0 => no service log data yet
                                 *    1 => the first one
                                 *    2 => the 2nd one
                                 */
	char	s_fpack[11];	/* 11: file system volume name 
                                 *     N.B. This must be 11 bytes to
                                 *          conform with the OS/2 BootSector
                                 *          requirements
                                 */

	/* extendfs() parameter under s_state & FM_EXTENDFS */
	int64	s_xsize;	/* 8: extendfs s_size */
	pxd_t	s_xfsckpxd;	/* 8: extendfs fsckpxd */
	pxd_t	s_xlogpxd;	/* 8: extendfs logpxd */
				/* - 128 byte boundary - */

	/*
	 *	DFS VFS+ support (preliminary) 
	 */
	char	s_attach;	/* 1: VFS+: flag: set when aggregate is attached
				 */
	uint8	rsrvd4[7];	/* 7: reserved - set to 0 */

	uint64	totalUsable;	/* 8: VFS+: total of 1K blocks which are
				 * available to "normal" (non-root) users.
				 */
	uint64	minFree;	/* 8: VFS+: # of 1K blocks held in reserve for 
				 * exclusive use of root.  This value can be 0,
				 * and if it is then totalUsable will be equal 
				 * to # of blocks in aggregate.  I believe this
				 * means that minFree + totalUsable = # blocks.
				 * In that case, we don't need to store both 
				 * totalUsable and minFree since we can compute
				 * one from the other.  I would guess minFree 
				 * would be the one we should store, and 
				 * totalUsable would be the one we should 
				 * compute.  (Just a guess...)
				 */

	uint64	realFree;	/* 8: VFS+: # of free 1K blocks can be used by 
				 * "normal" users.  It may be this is something
				 * we should compute when asked for instead of 
				 * storing in the superblock.  I don't know how
				 * often this information is needed.
				 */
	/*
	 *	graffiti area
	 */
};
#endif /*_H_JFS_SUPERBLOCK */	
