/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/meta/is_numeric_type.hpp (originally MTBase.h, ::SynesisStl)
 *
 * Purpose:     is_numeric_type meta class.
 *
 * Created:     19th November 1998
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


/** \file stlsoft/meta/is_numeric_type.hpp
 *
 * \brief [C++] Definition of the stlsoft::is_numeric_type meta class
 *  template
 *   (\ref group__library__Metaprogramming "Metaprogramming" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_NUMERIC_TYPE
#define STLSOFT_INCL_STLSOFT_META_HPP_IS_NUMERIC_TYPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_META_HPP_IS_NUMERIC_TYPE_MAJOR     1
# define STLSOFT_VER_STLSOFT_META_HPP_IS_NUMERIC_TYPE_MINOR     2
# define STLSOFT_VER_STLSOFT_META_HPP_IS_NUMERIC_TYPE_REVISION  6
# define STLSOFT_VER_STLSOFT_META_HPP_IS_NUMERIC_TYPE_EDIT      23
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

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#ifndef STLSOFT_INCL_STLSOFT_META_UTIL_HPP_META_
# include <stlsoft/meta/util/meta_.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_UTIL_HPP_META_ */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Traits type used to determine whether the given type is a
 *    numeric type.
 *
 * \ingroup group__library__Metaprogramming
 */
template <ss_typename_param_k T>
struct is_numeric_type
{
    enum { value = 0 };

    typedef no_type     type;
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, ss_sint8_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, ss_uint8_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, ss_sint16_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, ss_uint16_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, ss_sint32_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, ss_uint32_t, 1, yes_type)
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, ss_sint64_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, ss_uint64_t, 1, yes_type)
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_CHAR_DISTINCT_INT_TYPE
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, signed char, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, unsigned char, 1, yes_type)
#endif /* STLSOFT_CF_CHAR_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, signed short, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, unsigned short, 1, yes_type)
#endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, signed int, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, unsigned int, 1, yes_type)
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, signed long, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, unsigned long, 1, yes_type)
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */


STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, float, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, double, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_numeric_type, long double, 1, yes_type)

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


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

#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_NUMERIC_TYPE */

/* ///////////////////////////// end of file //////////////////////////// */

