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

#ifndef _LVM_STR_LIST_H
#define _LVM_STR_LIST_H

struct list *str_list_create(struct dm_pool *mem);
int str_list_add(struct dm_pool *mem, struct list *sll, const char *str);
int str_list_del(struct list *sll, const char *str);
int str_list_match_item(struct list *sll, const char *str);
int str_list_match_list(struct list *sll, struct list *sll2);
int str_list_lists_equal(struct list *sll, struct list *sll2);
int str_list_dup(struct dm_pool *mem, struct list *sllnew, struct list *sllold);

#endif
