// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2009, Roboterclub Aachen e.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
// ----------------------------------------------------------------------------

#ifndef XPCC__MCP23S17_HPP
#define XPCC__MCP23S17_HPP

#include <xpcc/architecture/platform.hpp>
#include <xpcc/architecture/driver/gpio.hpp>

namespace xpcc
{
	/**
	 * \brief	16-Bit I/O Expander with Serial Interface
	 * 
	 * A2, A1 and A0 need to be tided low.
	 * 
	 * GPB is the high byte, GPA the low byte.
	 * 
	 * \author	Fabian Greif
	 * \ingroup	gpio
	 */
	template <typename Spi, typename Cs, typename Int>
	class Mcp23s17
	{
	public:
		void
		initialize();
		
		void
		configure(uint16_t inputMask, uint16_t pullupMask);
		
		//void
		//configureInterrupt();
		
		uint16_t
		read();
		
		void
		write(uint16_t output);
		
	protected:
		enum RegisterAddress
		{
			IODIR = 0x00,		//!< Port direction (1=input, 0=output)
			IPOL = 0x02,		//!< Invert polarity
			GPINTEN = 0x04,		//!< Enable interrupt
			DEFVAL = 0x06,		//!< Compare register for interrupt
			INTCON = 0x08,
			IOCON = 0x0A,		//!< Configuration
			GPPU = 0x0C,		//!< Enable pullups
			INTF = 0x0E,		//!< Interrupt flag register
			INTCAP = 0x10,		//!< Interrupt capture register
			GPIO = 0x12,		//!< Port values
			OLAT = 0x14			//!< Output latch register
		};
		
		enum RW
		{
			WRITE = 0,
			READ = 1
		};
		
		static const uint8_t deviceAddress = 0x40;
		
		static Spi spi;
		static Cs cs;
		static Int interrupt;
	};
}

#include "mcp23s17_impl.hpp"

#endif	// XPCC__MCP23S17_HPP