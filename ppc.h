/*
 * Various PPC accessors.
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

#ifndef PPC_H
#define PPC_H

#include <types.h>
#include <ppc-regs.h>
#include <defs.h>


static inline void
lwsync(void)
{
	asm volatile ("lwsync" : : : "memory");
}


static inline void
isync(void)
{
	asm volatile ("isync" : : : "memory");
}


#define REG_READ_FN(reg)			\
	static inline uint64_t			\
	get_##reg(void)				\
	{					\
		uint64_t reg = 0;				\
		asm volatile("mfspr %0, " S(SPRN_##reg) : "=r" (reg));	\
		return reg;						\
	}								\

#define REG_WRITE_FN(reg)						\
	static inline void						\
	set_##reg(uint64_t reg)						\
	{								\
		asm volatile("mtspr "S(SPRN_##reg)", %0" :: "r" (reg));	\
	}								\

REG_READ_FN(HRMOR)
REG_READ_FN(LPCR)
REG_READ_FN(HID0)
REG_WRITE_FN(HID0)

#endif /* PPC_H */