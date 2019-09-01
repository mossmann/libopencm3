/** @defgroup dac_defines DAC Defines

@brief <b>Defined Constants and Types for the LPC43xx DAC</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2015

@date 09 June 2015

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

#ifndef LPC43XX_DAC_H
#define LPC43XX_DAC_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --- DAC registers ------------------------------------------------------- */

/* DAC register. Holds the conversion data */
#define DAC_CR                          MMIO32(DAC_BASE + 0x000)

/* DAC control register */
#define DAC_CTRL                        MMIO32(DAC_BASE + 0x004)

/* DAC counter value register */
#define DAC_CNTVAL                      MMIO32(DAC_BASE + 0x008)

/* --- DAC_CR values -------------------------------------------------- */

#define DAC_CR_BIAS             (1 << 16) /* Settling time */

/* --- DAC_CTRL values -------------------------------------------------- */

#define DAC_CTRL_INT_DMA_REQ    (1 << 0) /* DMA request */
#define DAC_CTRL_DBLBUF_ENA     (1 << 1) /* DMA double-buffering */
#define DAC_CTRL_CNT_ENA        (1 << 2) /* DMA time-out */
#define DAC_CTRL_DMA_ENA        (1 << 3) /* Combined DAC and DMA enable */

/* --- DAC function prototypes --------------------------------------------- */

BEGIN_DECLS

void dac_init(bool fast);

void dac_set(uint16_t v);

END_DECLS

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
