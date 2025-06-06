/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/collections/CArray_traits.hpp (derived from mfcstl/CArray_adaptors.hpp)
 *
 * Purpose:     Definition of the CArray_traits traits class.
 *
 * Created:     1st December 2002
 * Updated:     20th March 2025
 *
 * Home:        http://stlsoft.org/
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


/** \file mfcstl/collections/CArray_traits.hpp
 *
 * \brief [C++] Definition of the mfcstl::CArray_traits traits class
 *   (\ref group__library__Collection "Collection" Library).
 */

#ifndef MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_CARRAY_TRAITS
#define MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_CARRAY_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_COLLECTIONS_HPP_CARRAY_TRAITS_MAJOR      2
# define MFCSTL_VER_MFCSTL_COLLECTIONS_HPP_CARRAY_TRAITS_MINOR      0
# define MFCSTL_VER_MFCSTL_COLLECTIONS_HPP_CARRAY_TRAITS_REVISION   6
# define MFCSTL_VER_MFCSTL_COLLECTIONS_HPP_CARRAY_TRAITS_EDIT       27
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

#if defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT) && \
    !defined(MFCSTL_NO_INCLUDE_AFXTEMPL_BY_DEFAULT)
# include <afxtempl.h>
#endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT && !MFCSTL_NO_INCLUDE_AFXTEMPL_BY_DEFAULT */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
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
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** Traits for CArray_adaptor_base
 *
 * \ingroup group__library__Collection
 */
template <ss_typename_param_k C>
struct CArray_traits
{
    /// Typedef that defines the type of the elements in the array
    typedef ????            value_type;
    /// Typedef that defines the type of the arguments to the methods of the array
    typedef ????            arg_type;
    /// Typedef that identifies the actual class type used to specialise the traits
    typedef ????            array_type;
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k C>
struct CArray_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_traits<CByteArray>
{
    typedef BYTE            value_type;
    typedef BYTE            arg_type;
    typedef CByteArray      array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_traits<CDWordArray>
{
    typedef DWORD           value_type;
    typedef DWORD           arg_type;
    typedef CDWordArray     array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_traits<CUIntArray>
{
    typedef UINT            value_type;
    typedef UINT            arg_type;
    typedef CUIntArray      array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_traits<CWordArray>
{
    typedef WORD            value_type;
    typedef WORD            arg_type;
    typedef CWordArray      array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_traits<CPtrArray>
{
    typedef void*           value_type;
    typedef void*           arg_type;
    typedef CPtrArray       array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_traits<CObArray>
{
    typedef CObject*        value_type;
    typedef CObject*        arg_type;
    typedef CObArray        array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_traits<CStringArray>
{
    typedef CString         value_type;
# if 0
    typedef CString const&  arg_type;
# else /* ? 0 */
    typedef LPCTSTR         arg_type;
# endif /* 0 */
    typedef CStringArray    array_type;
};

# if defined(__AFXTEMPL_H__) && \
     defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
template <class V, class A>
struct CArray_traits<CArray<V, A> >
{
    typedef V               value_type;
    typedef A               arg_type;
    typedef CArray<V, A>    array_type;
};
# endif /* __AFXTEMPL_H__ && STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Traits type for specific setting of value_type and arg_type
 *
 * \ingroup group__library__Collection
 */
template<   ss_typename_param_k V
        ,   ss_typename_param_k A
        ,   ss_typename_param_k C
        >
struct CArray_specific_traits
{
    typedef V               value_type;
    typedef A               arg_type;
    typedef C               array_type;
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace mfcstl
# else
} // namespace mfcstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_CARRAY_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

