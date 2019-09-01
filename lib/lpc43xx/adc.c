/** @defgroup adc_file ADC

@ingroup LPC43xx

@brief <b>libopencm3 LPC43xx ADC</b>

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

#include <libopencm3/lpc43xx/adc.h>
#include <libopencm3/lpc43xx/ccu.h>

uint16_t adc_get_single(uint32_t adc, uint32_t flags)
{
	uint32_t result;
	ADC_CR(adc)=flags | ADC_CR_CLKDIV((uint8_t)(208/4.5))|ADC_CR_10BITS|ADC_CR_POWER|ADC_CR_START;

	do {
		result=ADC_GDR(adc);
	} while( (!ADC_DR_DONE(result)) );

	return ADC_DR_VREF(result);
};

/**@}*/

