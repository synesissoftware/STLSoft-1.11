/* /////////////////////////////////////////////////////////////////////////
 * File:    mfcstl/shims/logical/is_empty/arrays.hpp
 *
 * Purpose: Helper functions for MFC array classes.
 *
 * Created: 18th December 2006
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file mfcstl/shims/logical/is_empty/arrays.hpp
 *
 * \brief [C++] Primary include file for is_empty attribute shims
 *   for MFC array classes
 *   (\ref group__concept__Shim__Logical__is_empty "is_empty Collection Logical Shim").
 */

#ifndef MFCSTL_INCL_MFCSTL_SHIMS_LOGICAL_IS_EMPTY_HPP_ARRAYS
#define MFCSTL_INCL_MFCSTL_SHIMS_LOGICAL_IS_EMPTY_HPP_ARRAYS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_SHIMS_LOGICAL_IS_EMPTY_HPP_ARRAYS_MAJOR      2
# define MFCSTL_VER_MFCSTL_SHIMS_LOGICAL_IS_EMPTY_HPP_ARRAYS_MINOR      1
# define MFCSTL_VER_MFCSTL_SHIMS_LOGICAL_IS_EMPTY_HPP_ARRAYS_REVISION   1
# define MFCSTL_VER_MFCSTL_SHIMS_LOGICAL_IS_EMPTY_HPP_ARRAYS_EDIT       21
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
# include <mfcstl/mfcstl.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_H_AFXCOLL
# define STLSOFT_INCL_H_AFXCOLL
# include <afxcoll.h>
#endif /* !STLSOFT_INCL_H_AFXCOLL */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef _MFCSTL_NO_NAMESPMFC
# if defined(_STLSOFT_NO_NAMESPMFC) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::mfcstl */
namespace mfcstl
{
# else
/* Define stlsoft::mfcstl_project */
namespace stlsoft
{
namespace mfcstl_project
{
# endif /* _STLSOFT_NO_NAMESPMFC */
#endif /* !_MFCSTL_NO_NAMESPMFC */


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** Indicates whether the array is empty
 *
 * \ingroup group__concept__Shim__Logical__is_empty
 *
 */
inline
int
is_empty(CByteArray const& ar) STLSOFT_NOEXCEPT
{
    return 0 == ar.GetSize();
}

/** Indicates whether the array is empty
 *
 * \ingroup group__concept__Shim__Logical__is_empty
 *
 */
inline
int
is_empty(CWordArray const& ar) STLSOFT_NOEXCEPT
{
    return 0 == ar.GetSize();
}

/** Indicates whether the array is empty
 *
 * \ingroup group__concept__Shim__Logical__is_empty
 *
 */
inline
int
is_empty(CDWordArray const& ar) STLSOFT_NOEXCEPT
{
    return 0 == ar.GetSize();
}

/** Indicates whether the array is empty
 *
 * \ingroup group__concept__Shim__Logical__is_empty
 *
 */
inline
int
is_empty(CUIntArray const& ar) STLSOFT_NOEXCEPT
{
    return 0 == ar.GetSize();
}

/** Indicates whether the array is empty
 *
 * \ingroup group__concept__Shim__Logical__is_empty
 *
 */
inline
int
is_empty(CPtrArray const& ar) STLSOFT_NOEXCEPT
{
    return 0 == ar.GetSize();
}

/** Indicates whether the array is empty
 *
 * \ingroup group__concept__Shim__Logical__is_empty
 *
 */
inline
int
is_empty(CObArray const& ar) STLSOFT_NOEXCEPT
{
    return 0 == ar.GetSize();
}

/** Indicates whether the array is empty
 *
 * \ingroup group__concept__Shim__Logical__is_empty
 *
 */
inline
int
is_empty(CStringArray const& ar) STLSOFT_NOEXCEPT
{
    return 0 == ar.GetSize();
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef _MFCSTL_NO_NAMESPMFC
# if defined(_STLSOFT_NO_NAMESPMFC) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace mfcstl
# else
} // namespace mfcstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPMFC */

namespace stlsoft
{

    using ::mfcstl::is_empty;

} // namespace stlsoft
#endif /* !_MFCSTL_NO_NAMESPMFC */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !MFCSTL_INCL_MFCSTL_SHIMS_LOGICAL_IS_EMPTY_HPP_ARRAYS */

/* ///////////////////////////// end of file //////////////////////////// */

