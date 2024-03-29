/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/slice_functions.hpp
 *
 * Purpose:     String slice functions.
 *
 * Created:     25th April 2005
 * Updated:     11th March 2024
 *
 * Thanks:      To Pablo Aguilar for inspiration for these functions, and
 *              collaboration on their implementation.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file stlsoft/string/slice_functions.hpp
 *
 * \brief [C++] String slice functions
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SLICE_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_SLICE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SLICE_FUNCTIONS_MAJOR      2
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SLICE_FUNCTIONS_MINOR      0
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SLICE_FUNCTIONS_REVISION   3
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SLICE_FUNCTIONS_EDIT       24
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(STLSOFT_COMPILER_IS_MWERKS) && \
    ((__MWERKS__ & 0xff00) < 0x3000)
# error stlsoft/string/slice_functions.hpp not compatible with Metrowerks 7.x (v2.4)
#endif /* compiler */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_VIEW_SLICE_FUNCTIONS
# include <stlsoft/string/view_slice_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_VIEW_SLICE_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CONTAINER_SLICE_FUNCTIONS
# include <stlsoft/string/container_slice_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CONTAINER_SLICE_FUNCTIONS */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SLICE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

