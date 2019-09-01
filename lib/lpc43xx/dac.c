/** @defgroup dac_file DAC

@ingroup LPC43xx

@brief <b>libopencm3 LPC43xx DAC</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2015 

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

/**@{*/

#include <libopencm3/lpc43xx/dac.h>
#include <libopencm3/lpc43xx/ccu.h>

static bool dac_fast = false;

void dac_init(bool fast)
{
    CCU1_CLK_APB3_DAC_CFG |= 1; /* Enable DAC Clock */
    DAC_CTRL = DAC_CTRL_DMA_ENA;
    dac_fast = fast;
}

void dac_set(uint16_t v)
{
    DAC_CR = (v & 0x3FF) << 6 | (dac_fast ? 0 : DAC_CR_BIAS);
}


/**@}*/

