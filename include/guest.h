/*
 * Guest state.
 *
 * Copyright (C) 2015 Andrei Warkentin <andrey.warkentin@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef GUEST_H
#define GUEST_H

#include <types.h>
#include <assert.h>
#include <ppc-defs.h>
#include <rom.h>

extern struct guest_t *guest;

typedef struct guest_t
{
  uint32_t msr;
  length_t ram_size;
  void     *ram;
  rom_t    rom;
} guest_t;

static inline bool_t
guest_is_mmu_off(void)
{
  BUG_ON(guest == NULL, "guest NULL");
  BUG_ON(((guest->msr >> MSR_IR_LG) & 1) !=
         ((guest->msr >> MSR_DR_LG) & 1), "inconsistent IR/DR");

  return (guest->msr >> MSR_IR_LG) & 1;
}

err_t guest_init(length_t ram_size);

#endif /* GUEST_H */