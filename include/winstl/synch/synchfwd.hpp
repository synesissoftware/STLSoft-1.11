/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/synchfwd.hpp
 *
 * Purpose:     Forward declarations for the WinSTL components in the
 *              Synchronisation library.
 *
 * Created:     9th June 2006
 * Updated:     20th March 2025
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/synchfwd.hpp
 *
 * \brief [C++] Definition of the winstl::event class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_SYNCHFWD
#define WINSTL_INCL_WINSTL_SYNCH_HPP_SYNCHFWD

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_SYNCHFWD_MAJOR     1
# define WINSTL_VER_WINSTL_SYNCH_HPP_SYNCHFWD_MINOR     1
# define WINSTL_VER_WINSTL_SYNCH_HPP_SYNCHFWD_REVISION  2
# define WINSTL_VER_WINSTL_SYNCH_HPP_SYNCHFWD_EDIT      18
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_COMMON
# include <winstl/synch/common.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_COMMON */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * functions
 */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

class event;
class process_mutex;
class semaphore;

#if 0
template <typename SP>
class spin_mutex_base;
#endif

class thread_mutex;
class tss_index;

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_SYNCHFWD */

/* ///////////////////////////// end of file //////////////////////////// */

