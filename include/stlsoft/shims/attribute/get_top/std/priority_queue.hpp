/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/shims/attribute/get_top/std/priority_queue.hpp
 *
 * Purpose: Contains the get_top attribute shim.
 *
 * Created: 8th September 2019
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/shims/attribute/get_top/std/priority_queue.hpp
 *
 * \brief [C++] get_top attribute shims for std::priority_queue
 *   (\ref group__concept__Shim__Attribute__get_top "Top Attribute Shims").
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_PRIORITY_QUEUE
#define STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_PRIORITY_QUEUE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_PRIORITY_QUEUE_MAJOR       1
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_PRIORITY_QUEUE_MINOR       0
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_PRIORITY_QUEUE_REVISION    1
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_PRIORITY_QUEUE_EDIT        6
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

#ifndef STLSOFT_INCL_QUEUE
# define STLSOFT_INCL_QUEUE
# include <queue>
#endif /* !STLSOFT_INCL_QUEUE */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * get_top functions
 */

/* std::priority_queue */
/**
 * \ingroup group__concept__Shim__Attribute__get_top
 */
template <
    typename T_value
,   typename T_container
,   typename T_compare
>
inline
T_value const&
get_top(
    STLSOFT_NS_QUAL_STD(priority_queue)<
        T_value
    ,   T_container
    ,   T_compare
    > const& pq
)
{
    STLSOFT_ASSERT(!pq.empty());

    return pq.top();
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_PRIORITY_QUEUE */

/* ///////////////////////////// end of file //////////////////////////// */

