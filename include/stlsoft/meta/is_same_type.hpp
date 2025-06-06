/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/meta/is_same_type.hpp (originally MTBase.h, ::SynesisStl)
 *
 * Purpose:     is_same_type class.
 *
 * Created:     19th November 1998
 * Updated:     20th March 2025
 *
 * Thanks to:   Pablo Aguilar for providing the basis for the version that
 *              works for the Borland compiler.
 *
 *              Nevin Liber, for pointing out missing 'type' member.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/meta/is_same_type.hpp
 *
 * \brief [C++] Definition of the stlsoft::is_same_type meta class
 *  template
 *   (\ref group__library__Metaprogramming "Metaprogramming" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE
#define STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_META_HPP_IS_SAME_TYPE_MAJOR       4
# define STLSOFT_VER_STLSOFT_META_HPP_IS_SAME_TYPE_MINOR       4
# define STLSOFT_VER_STLSOFT_META_HPP_IS_SAME_TYPE_REVISION    6
# define STLSOFT_VER_STLSOFT_META_HPP_IS_SAME_TYPE_EDIT        135
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

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES
# include <stlsoft/meta/capabilities.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES */

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
# error This file is not compatible with Visual C++ 5.0 or earlier
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * Meta-classes
 */

#if defined(STLSOFT_COMPILER_IS_BORLAND)

struct is_same_type_helper
{
    template <ss_typename_param_k A>
    static yes_type is_same_type_function(A const&, A const&);

    template<   ss_typename_param_k A
            ,   ss_typename_param_k B
            >
    static no_type is_same_type_function(A const&, B const&);
};

template<   ss_typename_param_k A
        ,   ss_typename_param_k B
        >
struct is_same_type
{
    enum { value = (sizeof(yes_type) == sizeof(is_same_type_helper::is_same_type_function(A(), B()))) };
};

template <ss_typename_param_k A>
struct is_same_type<void, A>
{
    enum { value = 0 };

    typedef no_type     type;
};

template <ss_typename_param_k A>
struct is_same_type<A, void>
{
    enum { value = 0 };

    typedef no_type     type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct is_same_type<void, void>
{
    enum { value = 1 };

    typedef yes_type    type;
};

#elif defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)

/** Traits type used to determine whether two types are the same
 *   type.
 *
 * \ingroup group__library__Metaprogramming
 */
template<   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
struct is_same_type
{
    enum { value = 0 };

    typedef no_type     type;
};

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
struct is_same_type<T, T>
{
    enum { value = 1 };

    typedef yes_type    type;
};

# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

template<   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
struct is_same_type
{
private:
    template <ss_typename_param_k >
    struct same_
    {
        enum { value = 0 };

        typedef no_type     type;
    };
    STLSOFT_TEMPLATE_SPECIALISATION
    struct same_<T1>
    {
        enum { value = 1 };

        typedef yes_type    type;
    };

public:
    enum { value = same_<T2>::value };

    typedef ss_typename_type_k same_<T2>::type  type;
};

#endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE */

/* ///////////////////////////// end of file //////////////////////////// */

