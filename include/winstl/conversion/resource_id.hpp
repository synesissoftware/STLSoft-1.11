/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/conversion/resource_id.hpp
 *
 * Purpose:     Shim type for conversion between integer and c-string resource
 *              identifiers.
 *
 * Created:     11th April 2005
 * Updated:     20th March 2025
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/conversion/resource_id.hpp
 *
 * \brief [C++] Definition of the winstl::resource_id class
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef WINSTL_INCL_WINSTL_CONVERSION_HPP_RESOURCE_ID
#define WINSTL_INCL_WINSTL_CONVERSION_HPP_RESOURCE_ID

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CONVERSION_HPP_RESOURCE_ID_MAJOR     2
# define WINSTL_VER_WINSTL_CONVERSION_HPP_RESOURCE_ID_MINOR     0
# define WINSTL_VER_WINSTL_CONVERSION_HPP_RESOURCE_ID_REVISION  4
# define WINSTL_VER_WINSTL_CONVERSION_HPP_RESOURCE_ID_EDIT      28
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
 * classes
 */

/** Shim type for conversion between integer and c-string resource
 *   identifiers.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
union basic_resource_id
{
/// \name Member Types
/// @{
public:
    typedef C                       char_type;
    typedef basic_resource_id<C>    class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Construct from a resource Id
    ss_explicit_k basic_resource_id(int id)
        : m_id(id)
    {}
    /// Constructs from a resource name
    ss_explicit_k basic_resource_id(C const* name)
        : m_name(name)
    {}
/// @}

/// \name Operators
/// @{
public:
    operator int() const
    {
        return m_id;
    }
    operator char_type const* () const
    {
        return m_name;
    }
/// @}

/// \name Members
/// @{
private:
    int                 m_id;
    char_type const*    m_name;
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

/** Specialisation for use with the ANSI \c char type.
 *
 * \ingroup group__library__Conversion
 */
typedef basic_resource_id<ws_char_a_t>  resource_id_a;
/** Specialisation for use with the Unicode \c wchar_t type.
 *
 * \ingroup group__library__Conversion
 */
typedef basic_resource_id<ws_char_w_t>  resource_id_w;
/** Specialisation for use with the Windows \c TCHAR type.
 *
 * \ingroup group__library__Conversion
 */
typedef basic_resource_id<TCHAR>        resource_id;

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

#endif /* !WINSTL_INCL_WINSTL_CONVERSION_HPP_RESOURCE_ID */

/* ///////////////////////////// end of file //////////////////////////// */

