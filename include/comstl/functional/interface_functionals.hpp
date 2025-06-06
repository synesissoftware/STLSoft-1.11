/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/functional/interface_functionals.hpp
 *
 * Purpose:     Interface-specific predicates and functions.
 *
 * Created:     14th June 2002
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


/** \file comstl/functional/interface_functionals.hpp
 *
 * \brief [C++] Function classes for manipulating interfaces pointers
 *   (\ref group__library__Functional "Functional" Library).
 */

#ifndef COMSTL_INCL_COMSTL_FUNCTIONAL_HPP_INTERFACE_FUNCTIONALS
#define COMSTL_INCL_COMSTL_FUNCTIONAL_HPP_INTERFACE_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_HPP_INTERFACE_FUNCTIONALS_MAJOR     4
# define COMSTL_VER_HPP_INTERFACE_FUNCTIONALS_MINOR     0
# define COMSTL_VER_HPP_INTERFACE_FUNCTIONALS_REVISION  8
# define COMSTL_VER_HPP_INTERFACE_FUNCTIONALS_EDIT      84
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[Incompatibilies-start]
[Incompatibilies-end]
STLSOFT_COMPILER_IS_GCC:     __GNUC__ < 3 || (__GNUC__ == 3 && __GNUC_MINOR__ < 4)
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef COMSTL_INCL_COMSTL_UTIL_H_REFCOUNT_FUNCTIONS
# include <comstl/util/refcount_functions.h>
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_REFCOUNT_FUNCTIONS */

#ifndef STLSOFT_INCL_FUNCTIONAL
# define STLSOFT_INCL_FUNCTIONAL
# include <functional>
#endif /* !STLSOFT_INCL_FUNCTIONAL */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * functionals
 */

/** A function class that releases COM interfaces
 *
 * \ingroup group__library__Functional
 *
 * This function class releases COM interfaces by calling Release()
 * on them. Note that the function class benignly ignores null interface
 * pointers.
 *
 * \param I The COM interface on which to specialise the template
 */
template <ss_typename_param_k I>
// [[synesis:class:unary-functor: interface_release]]
struct interface_release
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<I*, void>
#endif
{
public:
    typedef I                                               interface_type;
    typedef interface_type*                                 argument_type;
    typedef void                                            result_type;

public:
    /// Function call operator
    ///
    /// \param pi The interface pointer to release
    void operator ()(interface_type* pi)
    {
        safe_release(pi);
    }
};

/** A function class that adds references to COM interfaces
 *
 * \ingroup group__library__Functional
 *
 * This function class adds a reference to COM interfaces by calling AddRef()
 * on them. Note that the function class benignly ignores null interface
 * pointers.
 *
 * \param I The COM interface on which to specialise the template
 */
template <ss_typename_param_k I>
// [[synesis:class:unary-functor: interface_addref]]
struct interface_addref
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<I*, void>
#endif
{
public:
    typedef I                                               interface_type;
    typedef interface_type*                                 argument_type;
    typedef void                                            result_type;

public:
    /// Function call operator
    ///
    /// \param pi The interface pointer on which to add a reference
    void operator ()(interface_type* pi)
    {
        safe_addref(pi);
    }
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace comstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_FUNCTIONAL_HPP_INTERFACE_FUNCTIONALS */

/* ///////////////////////////// end of file //////////////////////////// */

