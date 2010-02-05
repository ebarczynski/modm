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

#ifndef	XPCC__MODIFIER_HPP
#define	XPCC__MODIFIER_HPP

#include <xpcc/utils/macros.hpp>
#include <xpcc/hal/flash/flash_pointer.hpp>

namespace xpcc
{
	// forward declaration
	template<typename T>
	class FlashPointer;
	
	/**
	 * \ingroup		utils
	 * \defgroup	modifier
	 */
	namespace modifier
	{
		/**
		 * \brief	Add volatile modifier to T
		 * \ingroup	modifier
		 */
		template<typename T>
		ALWAYS_INLINE volatile T&
		asVolatile(T& value)
		{
			return (volatile T&) value;
		}
		
		/**
		 * \brief	Convert a normal pointer to a FlashPointer
		 * \ingroup	modifier
		 */
		template<typename T>
		ALWAYS_INLINE ::xpcc::FlashPointer<T>
		flash(const T* ptr)
		{
			return ::xpcc::FlashPointer<T>(ptr);
		}
	}
}

#endif	// XPCC__MODIFIER_HPP
