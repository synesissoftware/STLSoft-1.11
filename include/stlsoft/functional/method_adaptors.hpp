/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/functional/method_adaptors.hpp (originally ::SynesisStd)
 *
 * Purpose:     Contains the stlsoft::mem_fun calling convention-aware function adaptors.
 *
 * Created:     13th June 1999
 * Updated:     20th March 2025
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1999-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/functional/method_adaptors.hpp
 *
 * \brief [C++] Function classes that adapt member functions (and
 *   handle different calling conventions), and their creator functions:
 *   stlsoft::mem_fun() and stlsoft::mem_fun_ref()
 *   (\ref group__library__Functional "Functional" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_METHOD_ADAPTORS
#define STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_METHOD_ADAPTORS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_METHOD_ADAPTORS_MAJOR      4
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_METHOD_ADAPTORS_MINOR      1
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_METHOD_ADAPTORS_REVISION   7
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_METHOD_ADAPTORS_EDIT       74
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

#if defined(STLSOFT_COMPILER_IS_GCC) && \
    (   __GNUC__ < 3 || \
        (   __GNUC__ == 3 && \
            __GNUC_MINOR__ < 3))
# error This file is not compatible with GCC <3.3
#endif /* compiler */

#ifndef STLSOFT_INCL_FUNCTIONAL
# define STLSOFT_INCL_FUNCTIONAL
# include <functional>
#endif /* !STLSOFT_INCL_FUNCTIONAL */


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

// thiscall
#ifdef STLSOFT_CF_THISCALL_SUPPORTED
/** A function class that invokes a <b>cdecl</b> calling convention
 *    0-parameter mutating (non-const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: thiscall_mem_fun_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct thiscall_mem_fun_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
    typedef result_type                (operand_class_type::*method_type)();
public:
    ss_explicit_k thiscall_mem_fun_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type *pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

/** A function class that invokes a <b>cdecl</b> calling convention
 *    0-parameter non-mutating (const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: thiscall_mem_fun_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct thiscall_mem_fun_const_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
# ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type (operand_class_type::*method_type)() const;
# else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (operand_class_type::*method_type)() const;
# endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k thiscall_mem_fun_const_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type const* pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

# ifndef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

template< ss_typename_param_k T
        >
struct thiscall_mem_fun_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#  ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type (operand_class_type::*method_type)();
#  else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (operand_class_type::*method_type)();
#  endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k thiscall_mem_fun_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type *pt) const
    {
        (pt->*m_func)();
    }
private:
    method_type m_func;
};

template< ss_typename_param_k T
        >
struct thiscall_mem_fun_const_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
    typedef result_type (operand_class_type::*method_type)() const;
public:
    ss_explicit_k thiscall_mem_fun_const_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type const* pt) const
    {
        (pt->*m_func)();
    }
private:
    method_type m_func;
};

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
#endif /* STLSOFT_CF_THISCALL_SUPPORTED */

// cdecl

#ifdef STLSOFT_CF_CDECL_SUPPORTED
/** A function class that invokes a <b>cdecl</b> calling convention
 *    0-parameter mutating (non-const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: cdecl_mem_fun_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct cdecl_mem_fun_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
# ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_CDECL (operand_class_type::*method_type)();
# else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_CDECL operand_class_type::*method_type)();
# endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k cdecl_mem_fun_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type *pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

/** A function class that invokes a <b>cdecl</b> calling convention
 *    0-parameter non-mutating (const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: cdecl_mem_fun_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct cdecl_mem_fun_const_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
# ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_CDECL (operand_class_type::*method_type)() const;
# else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_CDECL operand_class_type::*method_type)() const;
# endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k cdecl_mem_fun_const_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type const* pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

# ifndef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

template< ss_typename_param_k T
        >
struct cdecl_mem_fun_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#  ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_CDECL (operand_class_type::*method_type)();
#  else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_CDECL operand_class_type::*method_type)();
#  endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k cdecl_mem_fun_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type *pt) const
    {
        (pt->*m_func)();
    }
private:
    method_type m_func;
};

template< ss_typename_param_k T
        >
struct cdecl_mem_fun_const_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#  ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_CDECL (operand_class_type::*method_type)() const;
#  else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_CDECL operand_class_type::*method_type)() const;
#  endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k cdecl_mem_fun_const_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type const* pt) const
    {
        (pt->*m_func)();
    }
private:
    method_type m_func;
};

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
#endif /* STLSOFT_CF_CDECL_SUPPORTED */



// fastcall

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED

/** A function class that invokes a <b>fastcall</b> calling convention
 *    0-parameter mutating (non-const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: fastcall_mem_fun_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct fastcall_mem_fun_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_FASTCALL   (operand_class_type::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_FASTCALL   operand_class_type::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k fastcall_mem_fun_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type *pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

/** A function class that invokes a <b>fastcall</b> calling convention
 *    0-parameter non-mutating (const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: fastcall_mem_fun_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct fastcall_mem_fun_const_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_FASTCALL   (operand_class_type::*method_type)() const;
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_FASTCALL   operand_class_type::*method_type)() const;
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k fastcall_mem_fun_const_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type const* pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

# ifndef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

template< ss_typename_param_k T
        >
struct fastcall_mem_fun_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_FASTCALL    (operand_class_type::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_FASTCALL   operand_class_type::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k fastcall_mem_fun_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type *pt) const
    {
        (pt->*m_func)();
    }
private:
    method_type m_func;
};

template< ss_typename_param_k T
        >
struct fastcall_mem_fun_const_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_FASTCALL    (operand_class_type::*method_type)() const;
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_FASTCALL   operand_class_type::*method_type)() const;
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k fastcall_mem_fun_const_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type const* pt) const
    {
        (pt->*m_func)();
    }
private:
    method_type m_func;
};

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */



// stdcall

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/** A function class that invokes a <b>stdcall</b> calling convention
 *    0-parameter mutating (non-const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: stdcall_mem_fun_t<T<T>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct stdcall_mem_fun_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_STDCALL    (operand_class_type::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_STDCALL    operand_class_type::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k stdcall_mem_fun_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type *pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

/** A function class that invokes a <b>stdcall</b> calling convention
 *    0-parameter non-mutating (const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: stdcall_mem_fun_t<T<T>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct stdcall_mem_fun_const_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_STDCALL    (operand_class_type::*method_type)() const;
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_STDCALL    operand_class_type::*method_type)() const;
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k stdcall_mem_fun_const_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type const* pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

# ifndef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

template< ss_typename_param_k T
        >
struct stdcall_mem_fun_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_STDCALL     (operand_class_type::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_STDCALL    operand_class_type::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k stdcall_mem_fun_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type *pt) const
    {
        (pt->*m_func)();
    }
private:
    method_type m_func;
};

template< ss_typename_param_k T
        >
struct stdcall_mem_fun_const_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_STDCALL (operand_class_type::*method_type)() const;
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_STDCALL operand_class_type::*method_type)() const;
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k stdcall_mem_fun_const_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type const* pt) const
    {
        (pt->*m_func)();
    }
private:
    method_type m_func;
};

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */



#ifdef STLSOFT_CF_THISCALL_SUPPORTED
/** A function class that invokes a <b>cdecl</b> calling convention
 *    0-parameter mutating (non-const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: thiscall_mem_fun_ref_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct thiscall_mem_fun_ref_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
    typedef result_type               (operand_class_type::*method_type)();
public:
    ss_explicit_k thiscall_mem_fun_ref_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type& rt) const
    {
        return (rt.*m_func)();
    }
private:
    method_type m_func;
};

/** A function class that invokes a <b>thiscall</b> calling convention
 *    0-parameter non-mutating (const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: thiscall_mem_fun_ref_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct thiscall_mem_fun_ref_const_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
    typedef result_type               (operand_class_type::*method_type)() const;
public:
    ss_explicit_k thiscall_mem_fun_ref_const_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type const& rt) const
    {
        return (rt.*m_func)();
    }
private:
    method_type m_func;
};

# ifndef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

template< ss_typename_param_k T
        >
struct thiscall_mem_fun_ref_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
    typedef result_type               (operand_class_type::*method_type)();
public:
    ss_explicit_k thiscall_mem_fun_ref_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type& rt) const
    {
        (rt.*m_func)();
    }
private:
    method_type m_func;
};

template< ss_typename_param_k T
        >
struct thiscall_mem_fun_ref_const_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
    typedef result_type               (operand_class_type::*method_type)() const;
public:
    ss_explicit_k thiscall_mem_fun_ref_const_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type const& rt) const
    {
        (rt.*m_func)();
    }
private:
    method_type m_func;
};

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
#endif /* STLSOFT_CF_THISCALL_SUPPORTED */



#ifdef STLSOFT_CF_CDECL_SUPPORTED

/** A function class that invokes a <b>cdecl</b> calling convention
 *    0-parameter mutating (non-const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: cdecl_mem_fun_ref_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct cdecl_mem_fun_ref_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
# ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_CDECL (operand_class_type::*method_type)();
# else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_CDECL operand_class_type::*method_type)();
# endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k cdecl_mem_fun_ref_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type& rt) const
    {
        return (rt.*m_func)();
    }
private:
    method_type m_func;
};

/** A function class that invokes a <b>cdecl</b> calling convention
 *    0-parameter non-mutating (const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: cdecl_mem_fun_ref_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct cdecl_mem_fun_ref_const_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
# ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_CDECL  (operand_class_type::*method_type)() const;
# else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_CDECL  operand_class_type::*method_type)() const;
# endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k cdecl_mem_fun_ref_const_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type const& rt) const
    {
        return (rt.*m_func)();
    }
private:
    method_type m_func;
};

# ifndef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

template< ss_typename_param_k T
        >
struct cdecl_mem_fun_ref_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#  ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_CDECL  (operand_class_type::*method_type)();
#  else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_CDECL  operand_class_type::*method_type)();
#  endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k cdecl_mem_fun_ref_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type& rt) const
    {
        (rt.*m_func)();
    }
private:
    method_type m_func;
};

template< ss_typename_param_k T
        >
struct cdecl_mem_fun_ref_const_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#  ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_CDECL  (operand_class_type::*method_type)() const;
#  else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_CDECL  operand_class_type::*method_type)() const;
#  endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k cdecl_mem_fun_ref_const_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type const& rt) const
    {
        (rt.*m_func)();
    }
private:
    method_type m_func;
};

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
#endif /* STLSOFT_CF_CDECL_SUPPORTED */


#ifdef STLSOFT_CF_FASTCALL_SUPPORTED

/** A function class that invokes a <b>fastcall</b> calling convention
 *    0-parameter mutating (non-const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: fastcall_mem_fun_ref_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct fastcall_mem_fun_ref_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_FASTCALL   (operand_class_type::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_FASTCALL   operand_class_type::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k fastcall_mem_fun_ref_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type& rt) const
    {
        return (rt.*m_func)();
    }
private:
    method_type m_func;
};

/** A function class that invokes a <b>fastcall</b> calling convention
 *    0-parameter non-mutating (const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: fastcall_mem_fun_ref_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct fastcall_mem_fun_ref_const_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_FASTCALL   (operand_class_type::*method_type)() const;
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_FASTCALL   operand_class_type::*method_type)() const;
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k fastcall_mem_fun_ref_const_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type const& rt) const
    {
        return (rt.*m_func)();
    }
private:
    method_type m_func;
};

# ifndef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

template< ss_typename_param_k T
        >
struct fastcall_mem_fun_ref_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_FASTCALL   (operand_class_type::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_FASTCALL   operand_class_type::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k fastcall_mem_fun_ref_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type& rt) const
    {
        (rt.*m_func)();
    }
private:
    method_type m_func;
};

template< ss_typename_param_k T
        >
struct fastcall_mem_fun_ref_const_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_FASTCALL   (operand_class_type::*method_type)() const;
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_FASTCALL   operand_class_type::*method_type)() const;
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k fastcall_mem_fun_ref_const_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type const& rt) const
    {
        (rt.*m_func)();
    }
private:
    method_type m_func;
};

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */



#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/** A function class that invokes a <b>stdcall</b> calling convention
 *    0-parameter mutating (non-const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: stdcall_mem_fun_ref_t<T<T>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct stdcall_mem_fun_ref_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_STDCALL    (operand_class_type::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_STDCALL    operand_class_type::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k stdcall_mem_fun_ref_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type& rt) const
    {
        return (rt.*m_func)();
    }
private:
    method_type m_func;
};

/** A function class that invokes a <b>stdcall</b> calling convention
 *    0-parameter non-mutating (const) member function on its pointer argument.
 *
 * \ingroup group__library__Functional
 */
// [[synesis:class:function-class:unary-function: stdcall_mem_fun_ref_t<T<T>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct stdcall_mem_fun_ref_const_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef R                                               result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_STDCALL    (operand_class_type::*method_type)() const;
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_STDCALL    operand_class_type::*method_type)() const;
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k stdcall_mem_fun_ref_const_t(method_type func)
        : m_func(func)
    {}
    result_type operator ()(operand_class_type const& rt) const
    {
        return (rt.*m_func)();
    }
private:
    method_type m_func;
};

# ifndef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

template< ss_typename_param_k T
        >
struct stdcall_mem_fun_ref_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_STDCALL    (operand_class_type::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_STDCALL    operand_class_type::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k stdcall_mem_fun_ref_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type& rt) const
    {
        (rt.*m_func)();
    }
private:
    method_type m_func;
};

template< ss_typename_param_k T
        >
struct stdcall_mem_fun_ref_const_void_t
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
#endif
{
public:
    typedef T*                                              argument_type;
    typedef void                                            result_type;
    typedef result_type                                     return_type;
    typedef T                                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef result_type STLSOFT_STDCALL (operand_class_type::*method_type)() const;
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef result_type (STLSOFT_STDCALL operand_class_type::*method_type)() const;
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k stdcall_mem_fun_ref_const_void_t(method_type func)
        : m_func(func)
    {}
    void operator ()(operand_class_type const& rt) const
    {
        (rt.*m_func)();
    }
private:
    method_type m_func;
};
# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */


/* /////////////////////////////////////////////////////////////////////////
 * creator functions
 */

// cdecl
#ifdef STLSOFT_CF_CDECL_SUPPORTED

/** Creator function to adapt a pointer to a 0-parameter mutating
 *    (non-const) member function, for use with a pointer to the class.
 *
 * \ingroup group__library__Functional
 */
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_t<R, T> mem_fun(R (T::*STLSOFT_CDECL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_t<R, T> mem_fun(R (STLSOFT_CDECL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_t<R, T>(func);
}

#if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_t<void, T> mem_fun_void(void (T::*STLSOFT_CDECL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_t<void, T> mem_fun_void(void (STLSOFT_CDECL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_t<void, T>(func);
}

#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_void_t<T> mem_fun(void (T::*STLSOFT_CDECL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_void_t<T> mem_fun(void (STLSOFT_CDECL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_void_t<T> mem_fun_void(void (T::*STLSOFT_CDECL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_void_t<T> mem_fun_void(void (STLSOFT_CDECL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_void_t<T>(func);
}

#endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */


/** Creator function to adapt a pointer to a 0-parameter non-mutating
 *    (const) member function, for use with a pointer to the class.
 *
 * \ingroup group__library__Functional
 */
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_const_t<R, T> mem_fun(R (T::*STLSOFT_CDECL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_const_t<R, T> mem_fun(R (STLSOFT_CDECL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_const_t<R, T>(func);
}

#if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_const_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_const_t<void, T> mem_fun_void(void (T::*STLSOFT_CDECL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_const_t<void, T> mem_fun_void(void (STLSOFT_CDECL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_const_t<void, T>(func);
}

#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_const_void_t<T> mem_fun(void (T::*STLSOFT_CDECL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_const_void_t<T> mem_fun(void (STLSOFT_CDECL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_const_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_const_void_t<T> mem_fun_void(void (T::*STLSOFT_CDECL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_const_void_t<T> mem_fun_void(void (STLSOFT_CDECL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_const_void_t<T>(func);
}

#endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
#endif /* STLSOFT_CF_CDECL_SUPPORTED */


// fastcall
#ifdef STLSOFT_CF_FASTCALL_SUPPORTED

/** Creator function to adapt a pointer to a 0-parameter mutating
 *    (non-const) member function, for use with a pointer to the class.
 *
 * \ingroup group__library__Functional
 */

template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_t<R, T> mem_fun(R (T::*STLSOFT_FASTCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_t<R, T> mem_fun(R (STLSOFT_FASTCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_t<R, T>(func);
}

# if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_t<void, T> mem_fun_void(void (T::*STLSOFT_FASTCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_t<void, T> mem_fun_void(void (STLSOFT_FASTCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_t<void, T>(func);
}

# else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_void_t<T> mem_fun(void (T::*STLSOFT_FASTCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_void_t<T> mem_fun(void (STLSOFT_FASTCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_void_t<T> mem_fun_void(void (T::*STLSOFT_FASTCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_void_t<T> mem_fun_void(void (STLSOFT_FASTCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_void_t<T>(func);
}

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */


/** Creator function to adapt a pointer to a 0-parameter non-mutating
 *    (const) member function, for use with a pointer to the class.
 *
 * \ingroup group__library__Functional
 */
#ifdef STLSOFT_CF_FASTCALL_SUPPORTED

template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_const_t<R, T> mem_fun(R (T::*STLSOFT_FASTCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_const_t<R, T> mem_fun(R (STLSOFT_FASTCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_const_t<R, T>(func);
}

# if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_const_t<void, T> mem_fun_void(void (T::*STLSOFT_FASTCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_const_t<void, T> mem_fun_void(void (STLSOFT_FASTCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_const_t<void, T>(func);
}

# else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_const_void_t<T> mem_fun(void (T::*STLSOFT_FASTCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_const_void_t<T> mem_fun(void (STLSOFT_FASTCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_const_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_const_void_t<T> mem_fun_void(void (T::*STLSOFT_FASTCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_const_void_t<T> mem_fun_void(void (STLSOFT_FASTCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_const_void_t<T>(func);
}

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */


// stdcall

/** Creator function to adapt a pointer to a 0-parameter mutating
 *    (non-const) member function, for use with a pointer to the class.
 *
 * \ingroup group__library__Functional
 */
#ifdef STLSOFT_CF_STDCALL_SUPPORTED

template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_t<R, T> mem_fun(R (T::*STLSOFT_STDCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_t<R, T> mem_fun(R (STLSOFT_STDCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_t<R, T>(func);
}

# if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_t<void, T> mem_fun_void(void (T::*STLSOFT_STDCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_t<void, T> mem_fun_void(void (STLSOFT_STDCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_t<void, T>(func);
}

# else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_void_t<T> mem_fun(void (T::*STLSOFT_STDCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_void_t<T> mem_fun(void (STLSOFT_STDCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_void_t<T> mem_fun_void(void (T::*STLSOFT_STDCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_void_t<T> mem_fun_void(void (STLSOFT_STDCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_void_t<T>(func);
}

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */


/** Creator function to adapt a pointer to a 0-parameter non-mutating
 *    (const) member function, for use with a pointer to the class.
 *
 * \ingroup group__library__Functional
 */
#ifdef STLSOFT_CF_STDCALL_SUPPORTED

template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_const_t<R, T> mem_fun(R (T::*STLSOFT_STDCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_const_t<R, T> mem_fun(R (STLSOFT_STDCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_const_t<R, T>(func);
}

# if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_const_t<void, T> mem_fun_void(void (T::*STLSOFT_STDCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_const_t<void, T> mem_fun_void(void (STLSOFT_STDCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_const_t<void, T>(func);
}

# else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_const_void_t<T> mem_fun(void (T::*STLSOFT_STDCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_const_void_t<T> mem_fun(void (STLSOFT_STDCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_const_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_const_void_t<T> mem_fun_void(void (T::*STLSOFT_STDCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_const_void_t<T> mem_fun_void(void (STLSOFT_STDCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_const_void_t<T>(func);
}

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */




#ifdef STLSOFT_CF_THISCALL_SUPPORTED

/** Creator function to adapt a pointer to a 0-parameter mutating
 *    (non-const) member function, for use with a reference to the class.
 *
 * \ingroup group__library__Functional
 */
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
thiscall_mem_fun_ref_t<R, T> mem_fun_ref(R (T::*func)())
{
    return thiscall_mem_fun_ref_t<R, T>(func);
}

#if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_ref_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
thiscall_mem_fun_ref_t<void, T> mem_fun_ref_void(void (T::*func)())
{
    return thiscall_mem_fun_ref_t<void, T>(func);
}

#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
thiscall_mem_fun_ref_void_t<T> mem_fun_ref(void (T::*func)())
{
    return thiscall_mem_fun_ref_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
thiscall_mem_fun_ref_void_t<T> mem_fun_ref_void(void (T::*func)())
{
    return thiscall_mem_fun_ref_void_t<T>(func);
}

#endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */


/** Creator function to adapt a pointer to a 0-parameter non-mutating
 *    (const) member function, for use with a reference to the class.
 *
 * \ingroup group__library__Functional
 */
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
thiscall_mem_fun_ref_const_t<R, T> mem_fun_ref(R (T::*func)() const)
{
    return thiscall_mem_fun_ref_const_t<R, T>(func);
}

#if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_ref_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
thiscall_mem_fun_ref_const_t<void, T> mem_fun_ref_void(void (T::*func)() const)
{
    return thiscall_mem_fun_ref_const_t<void, T>(func);
}

#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
thiscall_mem_fun_ref_const_void_t<T> mem_fun_ref(void (T::*func)() const)
{
    return thiscall_mem_fun_ref_const_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
thiscall_mem_fun_ref_const_void_t<T> mem_fun_ref_void(void (T::*func)() const)
{
    return thiscall_mem_fun_ref_const_void_t<T>(func);
}

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
#endif /* STLSOFT_CF_THISCALL_SUPPORTED */

// cdecl
#ifdef STLSOFT_CF_CDECL_SUPPORTED

/** Creator function to adapt a pointer to a 0-parameter mutating
 *    (non-const) member function, for use with a reference to the class.
 *
 * \ingroup group__library__Functional
 */
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_ref_t<R, T> mem_fun_ref(R (T::*STLSOFT_CDECL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_ref_t<R, T> mem_fun_ref(R (STLSOFT_CDECL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_ref_t<R, T>(func);
}

#if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_ref_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_ref_t<void, T> mem_fun_ref_void(void (T::*STLSOFT_CDECL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_ref_t<void, T> mem_fun_ref_void(void (STLSOFT_CDECL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_ref_t<void, T>(func);
}

#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_ref_void_t<T> mem_fun_ref(void (T::*STLSOFT_CDECL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_ref_void_t<T> mem_fun_ref(void (STLSOFT_CDECL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_ref_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_ref_void_t<T> mem_fun_ref_void(void (T::*STLSOFT_CDECL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_ref_void_t<T> mem_fun_ref_void(void (STLSOFT_CDECL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_ref_void_t<T>(func);
}

#endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */


/** Creator function to adapt a pointer to a 0-parameter non-mutating
 *    (const) member function, for use with a reference to the class.
 *
 * \ingroup group__library__Functional
 */
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_ref_const_t<R, T> mem_fun_ref(R (T::*STLSOFT_CDECL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_ref_const_t<R, T> mem_fun_ref(R (STLSOFT_CDECL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_ref_const_t<R, T>(func);
}

#if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_ref_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_ref_const_t<void, T> mem_fun_ref_void(void (T::*STLSOFT_CDECL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_ref_const_t<void, T> mem_fun_ref_void(void (STLSOFT_CDECL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_ref_const_t<void, T>(func);
}

#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_ref_const_void_t<T> mem_fun_ref(void (T::*STLSOFT_CDECL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_ref_const_void_t<T> mem_fun_ref(void (STLSOFT_CDECL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_ref_const_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
cdecl_mem_fun_ref_const_void_t<T> mem_fun_ref_void(void (T::*STLSOFT_CDECL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
cdecl_mem_fun_ref_const_void_t<T> mem_fun_ref_void(void (STLSOFT_CDECL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_ref_const_void_t<T>(func);
}

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
#endif /* STLSOFT_CF_CDECL_SUPPORTED */


// fastcall

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED

/** Creator function to adapt a pointer to a 0-parameter mutating
 *    (non-const) member function, for use with a reference to the class.
 *
 * \ingroup group__library__Functional
 */
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_ref_t<R, T> mem_fun_ref(R (T::*STLSOFT_FASTCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_ref_t<R, T> mem_fun_ref(R (STLSOFT_FASTCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_ref_t<R, T>(func);
}

# if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_ref_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_ref_t<void, T> mem_fun_ref_void(void (T::*STLSOFT_FASTCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_ref_t<void, T> mem_fun_ref_void(void (STLSOFT_FASTCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_ref_t<void, T>(func);
}

# else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_ref_void_t<T> mem_fun_ref(void (T::*STLSOFT_FASTCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_ref_void_t<T> mem_fun_ref(void (STLSOFT_FASTCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_ref_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_ref_void_t<T> mem_fun_ref_void(void (T::*STLSOFT_FASTCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_ref_void_t<T> mem_fun_ref_void(void (STLSOFT_FASTCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_ref_void_t<T>(func);
}

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */


#ifdef STLSOFT_CF_FASTCALL_SUPPORTED

/** Creator function to adapt a pointer to a 0-parameter non-mutating
 *    (const) member function, for use with a reference to the class.
 *
 * \ingroup group__library__Functional
 */
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_ref_const_t<R, T> mem_fun_ref(R (T::*STLSOFT_FASTCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_ref_const_t<R, T> mem_fun_ref(R (STLSOFT_FASTCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_ref_const_t<R, T>(func);
}

# if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_ref_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_ref_const_t<void, T> mem_fun_ref_void(void (T::*STLSOFT_FASTCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_ref_const_t<void, T> mem_fun_ref_void(void (STLSOFT_FASTCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_ref_const_t<void, T>(func);
}

# else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_ref_const_void_t<T> mem_fun_ref(void (T::*STLSOFT_FASTCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_ref_const_void_t<T> mem_fun_ref(void (STLSOFT_FASTCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_ref_const_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
fastcall_mem_fun_ref_const_void_t<T> mem_fun_ref_void(void (T::*STLSOFT_FASTCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
fastcall_mem_fun_ref_const_void_t<T> mem_fun_ref_void(void (STLSOFT_FASTCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_ref_const_void_t<T>(func);
}

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */


// stdcall

#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/** Creator function to adapt a pointer to a 0-parameter mutating
 *    (non-const) member function, for use with a reference to the class.
 *
 * \ingroup group__library__Functional
 */
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_ref_t<R, T> mem_fun_ref(R (T::*STLSOFT_STDCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_ref_t<R, T> mem_fun_ref(R (STLSOFT_STDCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_ref_t<R, T>(func);
}

# if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_ref_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_ref_t<void, T> mem_fun_ref_void(void (T::*STLSOFT_STDCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_ref_t<void, T> mem_fun_ref_void(void (STLSOFT_STDCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_ref_t<void, T>(func);
}

# else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_ref_void_t<T> mem_fun_ref(void (T::*STLSOFT_STDCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_ref_void_t<T> mem_fun_ref(void (STLSOFT_STDCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_ref_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_ref_void_t<T> mem_fun_ref_void(void (T::*STLSOFT_STDCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_ref_void_t<T> mem_fun_ref_void(void (STLSOFT_STDCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_ref_void_t<T>(func);
}

# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */


#ifdef STLSOFT_CF_STDCALL_SUPPORTED

/** Creator function to adapt a pointer to a 0-parameter non-mutating
 *    (const) member function, for use with a reference to the class.
 *
 * \ingroup group__library__Functional
 */
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_ref_const_t<R, T> mem_fun_ref(R (T::*STLSOFT_STDCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_ref_const_t<R, T> mem_fun_ref(R (STLSOFT_STDCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_ref_const_t<R, T>(func);
}

# if defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)

/* We just provide mem_fun_ref_void() that returns 'normal' type. */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_ref_const_t<void, T> mem_fun_ref_void(void (T::*STLSOFT_STDCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_ref_const_t<void, T> mem_fun_ref_void(void (STLSOFT_STDCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_ref_const_t<void, T>(func);
}

# else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_ref_const_void_t<T> mem_fun_ref(void (T::*STLSOFT_STDCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_ref_const_void_t<T> mem_fun_ref(void (STLSOFT_STDCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_ref_const_void_t<T>(func);
}

template< ss_typename_param_k T
        >
inline
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
stdcall_mem_fun_ref_const_void_t<T> mem_fun_ref_void(void (T::*STLSOFT_STDCALL func)() const)
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
stdcall_mem_fun_ref_const_void_t<T> mem_fun_ref_void(void (STLSOFT_STDCALL T::*func)() const)
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_ref_const_void_t<T>(func);
}
# endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */


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

#endif /* !STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_METHOD_ADAPTORS */

/* ///////////////////////////// end of file //////////////////////////// */

