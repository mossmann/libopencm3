/** @defgroup adc_defines ADC Defines

@brief <b>Defined Constants and Types for the LPC43xx A/D Converter</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_ADC_H
#define LPC43XX_ADC_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --- Convenience macros -------------------------------------------------- */

/* ADC port base addresses (for convenience) */
#define ADC0                            ADC0_BASE
#define ADC1                            ADC1_BASE


/* --- ADC registers ------------------------------------------------------- */

/* A/D Control Register */
#define ADC_CR(port)                    MMIO32(port + 0x000)
#define ADC0_CR                         ADC_CR(ADC0)
#define ADC1_CR                         ADC_CR(ADC1)

/* A/D Global Data Register */
#define ADC_GDR(port)                   MMIO32(port + 0x004)
#define ADC0_GDR                        ADC_GDR(ADC0)
#define ADC1_GDR                        ADC_GDR(ADC1)

/* A/D Interrupt Enable Register */
#define ADC_INTEN(port)                 MMIO32(port + 0x00C)
#define ADC0_INTEN                      ADC_INTEN(ADC0)
#define ADC1_INTEN                      ADC_INTEN(ADC1)

/* A/D Channel 0 Data Register */
#define ADC_DR0(port)                   MMIO32(port + 0x010)
#define ADC0_DR0                        ADC_DR0(ADC0)
#define ADC1_DR0                        ADC_DR0(ADC1)

/* A/D Channel 1 Data Register */
#define ADC_DR1(port)                   MMIO32(port + 0x014)
#define ADC0_DR1                        ADC_DR1(ADC0)
#define ADC1_DR1                        ADC_DR1(ADC1)

/* A/D Channel 2 Data Register */
#define ADC_DR2(port)                   MMIO32(port + 0x018)
#define ADC0_DR2                        ADC_DR2(ADC0)
#define ADC1_DR2                        ADC_DR2(ADC1)

/* A/D Channel 3 Data Register */
#define ADC_DR3(port)                   MMIO32(port + 0x01C)
#define ADC0_DR3                        ADC_DR3(ADC0)
#define ADC1_DR3                        ADC_DR3(ADC1)

/* A/D Channel 4 Data Register */
#define ADC_DR4(port)                   MMIO32(port + 0x020)
#define ADC0_DR4                        ADC_DR4(ADC0)
#define ADC1_DR4                        ADC_DR4(ADC1)

/* A/D Channel 5 Data Register */
#define ADC_DR5(port)                   MMIO32(port + 0x024)
#define ADC0_DR5                        ADC_DR5(ADC0)
#define ADC1_DR5                        ADC_DR5(ADC1)

/* A/D Channel 6 Data Register */
#define ADC_DR6(port)                   MMIO32(port + 0x028)
#define ADC0_DR6                        ADC_DR6(ADC0)
#define ADC1_DR6                        ADC_DR6(ADC1)

/* A/D Channel 7 Data Register */
#define ADC_DR7(port)                   MMIO32(port + 0x02C)
#define ADC0_DR7                        ADC_DR7(ADC0)
#define ADC1_DR7                        ADC_DR7(ADC1)

/* A/D Status Register */
#define ADC_STAT(port)                  MMIO32(port + 0x030)
#define ADC0_STAT                       ADC_STAT(ADC0)
#define ADC1_STAT                       ADC_STAT(ADC1)


/* ADC_CR Values ----------------------------------------------------------- */

#define ADC_CR_CH0 (1<<0)
#define ADC_CR_CH1 (1<<1)
#define ADC_CR_CH2 (1<<2)
#define ADC_CR_CH3 (1<<3)
#define ADC_CR_CH4 (1<<4)
#define ADC_CR_CH5 (1<<5)
#define ADC_CR_CH6 (1<<6)
#define ADC_CR_CH7 (1<<7)

#define ADC_CR_CLKDIV(x) ((x&0xff)<<8)
#define ADC_CR_BURST (1<<16)

#define ADC_CR_10BITS (0<<17)
#define ADC_CR_9BITS  (1<<17)
#define ADC_CR_8BITS  (2<<17)
#define ADC_CR_7BITS  (3<<17)
#define ADC_CR_6BITS  (4<<17)
#define ADC_CR_5BITS  (5<<17)
#define ADC_CR_4BITS  (6<<17)
#define ADC_CR_3BITS  (7<<17)

#define ADC_CR_POWER (1<<21)

#define ADC_CR_START  (1<<24)
/* missing: add other start modes */

/* ADC_GDR and ADC_DR Values */
#define ADC_DR_VREF(x)    ((x>>6)&0b1111111111)
#define ADC_DR_CHN(x)     ((x>>24)&0b111)
#define ADC_DR_OVERRUN(x) (((x&(1<<30))!=0))
#define ADC_DR_DONE(x)    (((x&(1<<31))!=0))

uint16_t adc_get_single(uint32_t adc, uint32_t flags);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
