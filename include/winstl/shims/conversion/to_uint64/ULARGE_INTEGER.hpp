/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/conversion/to_uint64/ULARGE_INTEGER.hpp
 *
 * Purpose:     Contains the to_uint64 access shim.
 *
 * Created:     6th June 2008
 * Updated:     20th March 2025
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/shims/conversion/to_uint64/ULARGE_INTEGER.hpp
 *
 * \brief [C++] Integer conversion shims for the Windows type ULARGE_INTEGER.
 *   \ref group__concept__Shim__Conversion__to_uint64 "to_uint64 Integer Attribute Shim".
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_UINT64_HPP_ULARGE_INTEGER
#define WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_UINT64_HPP_ULARGE_INTEGER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_UINT64_HPP_ULARGE_INTEGER_MAJOR      1
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_UINT64_HPP_ULARGE_INTEGER_MINOR      0
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_UINT64_HPP_ULARGE_INTEGER_REVISION   6
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_UINT64_HPP_ULARGE_INTEGER_EDIT       14
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_STLSOFT
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_CONVERSION_TO_UINT64_HPP_DEGENERATE
# include <stlsoft/shims/conversion/to_uint64/degenerate.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_CONVERSION_TO_UINT64_HPP_DEGENERATE */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
namespace stlsoft
{
#endif /* WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * to_uint64 functions
 */

/** Converts a ULARGE_INTEGER instance to an unsigned
 *    64-bit integer value.
 * \ingroup group__concept__Shim__Conversion__to_uint64
 */
inline STLSOFT_NS_QUAL(ss_uint64_t) to_uint64(ULARGE_INTEGER const& uli)
{
    return uli.QuadPart;
}

/** Converts a pointer to a ULARGE_INTEGER instance to an unsigned
 *    64-bit integer value.
 * \ingroup group__concept__Shim__Conversion__to_uint64
 */
inline STLSOFT_NS_QUAL(ss_uint64_t) to_uint64(ULARGE_INTEGER const* puli)
{
    return (NULL == puli) ? 0 : to_uint64(*puli);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
} // namespace stlsoft
#endif /* WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_UINT64_HPP_ULARGE_INTEGER */

/* ///////////////////////////// end of file //////////////////////////// */

