/* /////////////////////////////////////////////////////////////////////////
 * File:        inetstl/filesystem/functionals.hpp
 *
 * Purpose:     File-system functionals.
 *
 * Created:     19th January 2002
 * Updated:     21st March 2025
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


/** \file inetstl/filesystem/functionals.hpp
 *
 * \brief [C++] File-system functionals
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FUNCTIONALS
#define INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define INETSTL_VER_INETSTL_FILESYSTEM_HPP_FUNCTIONALS_MAJOR       4
# define INETSTL_VER_INETSTL_FILESYSTEM_HPP_FUNCTIONALS_MINOR       0
# define INETSTL_VER_INETSTL_FILESYSTEM_HPP_FUNCTIONALS_REVISION    12
# define INETSTL_VER_INETSTL_FILESYSTEM_HPP_FUNCTIONALS_EDIT        55
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef INETSTL_INCL_INETSTL_H_INETSTL
# include <inetstl/inetstl.h>
#endif /* !INETSTL_INCL_INETSTL_H_INETSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef INETSTL_OS_IS_WINDOWS
# error This file is currently compatible only with the Win32/Win64 API
#endif /* !INETSTL_OS_IS_WINDOWS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <inetstl/filesystem/filesystem_traits.hpp>
#endif /* !INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX
# include <stlsoft/util/minmax.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX */

#ifndef _INETSTL_FUNCTIONALS_NO_STD
# include <functional>
#else /* ? _INETSTL_FUNCTIONALS_NO_STD */
# error Now need to write that std_binary_function stuff!!
#endif /* _INETSTL_FUNCTIONALS_NO_STD */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::inetstl */
namespace inetstl
{
# else
/* Define stlsoft::inetstl_project */
namespace stlsoft
{
namespace inetstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** A function class that compares two file-system paths
 *
 * \ingroup group__library__FileSystem
 *
 * \param C The character type
 * \param A1 The left-hand argument type; defaults to C const*
 * \param A2 The right-hand argument type; defaults to C const*
 */
// [[synesis:class:function-class:binary-predicate: path_compare<T<C>, T<A1>, T<A2>>]]
template<   ss_typename_param_k C
        ,   ss_typename_param_k A1 = C const*
        ,   ss_typename_param_k A2 = C const*
        >
struct path_compare
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(binary_function)<A1, A2, is_bool_t>
#endif
{
public:
    /// The character type
    typedef C                                               char_type;
    /// The first argument type
    typedef A1                                              first_argument_type;
    /// The second argument type
    typedef A2                                              second_argument_type;
    /// The result type
    typedef is_bool_t                                       result_type;
    /// The traits type
    typedef filesystem_traits<C>                            traits_type;
    /// The current specialisation of the type
    typedef path_compare<
        C
    ,   A1
    ,   A2
    >                                                       class_type;

public:
    /// Function call, compares \c s1 with \c s2
    ///
    /// \note The comparison is determined by evaluation the full-paths of both \c s1 and \c s2
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template<
        ss_typename_param_k T1
    ,   ss_typename_param_k T2
    >
    result_type operator ()(T1 const& s1, T2 const& s2) const
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    result_type operator ()(first_argument_type s1, second_argument_type s2) const
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return compare_(STLSOFT_NS_QUAL(c_str_ptr)(s1), STLSOFT_NS_QUAL(c_str_ptr)(s2));
    }

// Implementation
private:
    static result_type compare_(char_type const* s1, char_type const* s2)
    {
        char_type       path1[INETSTL_CONST_MAX_PATH + 1];
        char_type       path2[INETSTL_CONST_MAX_PATH + 1];
        is_size_t const len1    =   traits_type::str_len(s1);
        is_size_t const len2    =   traits_type::str_len(s2);

        traits_type::char_copy(&path1[0], s1, STLSOFT_NS_QUAL(minimum)(STLSOFT_NUM_ELEMENTS(path1), len1));
        path1[len1] = '\0';
        traits_type::char_copy(&path2[0], s2, STLSOFT_NS_QUAL(minimum)(STLSOFT_NUM_ELEMENTS(path2), len2));
        path2[len2] = '\0';

        traits_type::remove_dir_end(&path1[0]);
        traits_type::remove_dir_end(&path2[0]);

        s1 = &path1[0];
        s2 = &path2[0];

        return 0 == traits_type::str_compare(s1, s2);
    }
};

/** Predicate that indicates whether a given path exists
 *
 * \ingroup group__library__FileSystem
 *
 * \param C The character type
 * \param A The argument type; defaults to C const*
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k A = C const*
        >
// [[synesis:class:function-class:unary-predicate: path_exists<T<C>, T<A>>]]
struct path_exists
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<A, is_bool_t>
#endif
{
public:
    /// The character type
    typedef C                                               char_type;
    /// The second argument type
    typedef A                                               argument_type;
    /// The result type
    typedef is_bool_t                                       result_type;
    /// The traits type
    typedef filesystem_traits<C>                            traits_type;
    /// The current specialisation of the type
    typedef path_exists<
        C
    ,   A
    >                                                       class_type;

public:
    ss_explicit_k
    path_exists(HINTERNET hConnection)
        : m_hConnection(hConnection)
    {}

public:
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k S>
    is_bool_t operator ()(S const& s) const
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    is_bool_t operator ()(argument_type s) const
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return exists_(STLSOFT_NS_QUAL(c_str_ptr)(s));
    }

private:
    is_bool_t exists_(char_type const* s) const
    {
        char_type   sz0[1 + INETSTL_CONST_MAX_PATH];
        is_dword_t  dw;

        if (!traits_type::get_full_path_name(m_hConnection, s, STLSOFT_NUM_ELEMENTS(sz0), sz0))
        {
            dw = 0xFFFFFFFF;
        }
        else
        {
            dw = ::GetFileAttributes(sz0);
        }

        return 0xFFFFFFFF != dw;
    }

private:
    HINTERNET   m_hConnection;
};


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace inetsl
# else
} // namespace inetstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FUNCTIONALS */

/* ///////////////////////////// end of file //////////////////////////// */

