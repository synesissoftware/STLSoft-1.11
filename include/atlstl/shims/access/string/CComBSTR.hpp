/* /////////////////////////////////////////////////////////////////////////
 * File:    atlstl/shims/access/string/CComBSTR.hpp
 *
 * Purpose: Contains classes and functions for dealing with OLE/COM strings.
 *
 * Created: 27th May 2002
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file atlstl/shims/access/string/CComBSTR.hpp
 *
 * \brief [C++] Definition of the string access shims for
 *   <code>CComBSTR</code>
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef ATLSTL_INCL_ATLSTL_SHIMS_ACCESS_STRING_HPP_CCOMBSTR
#define ATLSTL_INCL_ATLSTL_SHIMS_ACCESS_STRING_HPP_CCOMBSTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ATLSTL_VER_ATLSTL_SHIMS_ACCESS_STRING_HPP_CCOMBSTR_MAJOR       4
# define ATLSTL_VER_ATLSTL_SHIMS_ACCESS_STRING_HPP_CCOMBSTR_MINOR       0
# define ATLSTL_VER_ATLSTL_SHIMS_ACCESS_STRING_HPP_CCOMBSTR_REVISION    7
# define ATLSTL_VER_ATLSTL_SHIMS_ACCESS_STRING_HPP_CCOMBSTR_EDIT        111
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef ATLSTL_INCL_ATLSTL_HPP_ATLSTL
# include <atlstl/atlstl.hpp>
#endif /* !ATLSTL_INCL_ATLSTL_HPP_ATLSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef ATLSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::atlstl */
namespace atlstl
{
# else
/* Define stlsoft::atlstl_project */
namespace stlsoft
{
namespace atlstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ATLSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/** \ref group__concept__Shim__string_access__c_str_data for CComBSTR
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
LPCOLESTR
c_str_data(ATLSTL_NS_QUAL_ATL(CComBSTR) const& s)
{
    return c_str_ptr(s);
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
LPCOLESTR
c_str_data_w(ATLSTL_NS_QUAL_ATL(CComBSTR) const& s)
{
    return c_str_data(s);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number
 * of characters in the character string in the expression.
 */

/* CComBSTR */

/** \ref group__concept__Shim__string_access__c_str_len for CComBSTR
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
as_size_t
c_str_len(ATLSTL_NS_QUAL_ATL(CComBSTR) const& s)
{
    return s.Length();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
as_size_t
c_str_len_w(ATLSTL_NS_QUAL_ATL(CComBSTR) const& s)
{
    return c_str_len(s);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* CComBSTR */

/** \ref group__concept__Shim__string_access__c_str_ptr for CComBSTR
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
LPCOLESTR
c_str_ptr(ATLSTL_NS_QUAL_ATL(CComBSTR) const& s)
{
    /* NULL is a valid BSTR value, so check for that */
    return (s.m_str != 0) ? s.m_str : L"";
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
LPCOLESTR
c_str_ptr_w(ATLSTL_NS_QUAL_ATL(CComBSTR) const& s)
{
    return c_str_ptr(s);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or \c nullptr.
 */

/* CComBSTR */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for CComBSTR
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
LPCOLESTR
c_str_ptr_null(ATLSTL_NS_QUAL_ATL(CComBSTR) const& s)
{
    /* NULL is a valid BSTR value, so may return that */
    return s.m_str;
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
LPCOLESTR
c_str_ptr_null_w(ATLSTL_NS_QUAL_ATL(CComBSTR) const& s)
{
    return c_str_ptr_null(s);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef ATLSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace atlstl
# else
} // namespace atlstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ATLSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef ATLSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::atlstl::c_str_data;
using ::atlstl::c_str_data_w;

using ::atlstl::c_str_len;
using ::atlstl::c_str_len_w;

using ::atlstl::c_str_ptr;
using ::atlstl::c_str_ptr_w;

using ::atlstl::c_str_ptr_null;
using ::atlstl::c_str_ptr_null_w;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !ATLSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !ATLSTL_INCL_ATLSTL_SHIMS_ACCESS_STRING_HPP_CCOMBSTR */

/* ///////////////////////////// end of file //////////////////////////// */

