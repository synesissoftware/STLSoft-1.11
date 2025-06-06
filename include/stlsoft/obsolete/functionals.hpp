/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/obsolete/functionals.hpp (originally MLCpp.h, ::SynesisStd)
 *
 * Purpose:     Basic functionals.
 *
 * Created:     19th January 2002
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


/// \file stlsoft/obsolete/functionals.hpp
///
/// Basic functionals.

#ifndef STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_FUNCTIONALS
#define STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_FUNCTIONALS_MAJOR     3
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_FUNCTIONALS_MINOR     0
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_FUNCTIONALS_REVISION  8
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_FUNCTIONALS_EDIT      59
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

#ifndef STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_NOOP
# include <stlsoft/functional/noop.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_NOOP */

#ifndef STLSOFT_INCL_FUNCTIONAL
# define STLSOFT_INCL_FUNCTIONAL
# include <functional>           // for std::unary_function
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

// struct delete_instance
//
/** This functional deletes an object instance, via scalar delete
 *
 * \ingroup group__library__Functional
 *
 * \deprecated
 */

template <ss_typename_param_k T>
// [[synesis:class:unary-functor: delete_instance]]
struct delete_instance
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T *, void>
#endif
{
public:
    /// The argument type
    typedef T*                                              argument_type;
    /// The result type
    typedef void                                            result_type;

public:
    /// The function call operator, which deletes the given instance
    ///
    /// \param pt A pointer to an instance of type T to be deleted
    void operator ()(T *pt) STLSOFT_NOEXCEPT
    {
        delete pt;
    }
};


// struct delete_array
//
/** This functional deletes an array of objects, via vector delete
 *
 * \ingroup group__library__Functional
 *
 * \deprecated
 */

template <ss_typename_param_k T>
// [[synesis:class:unary-functor: delete_array]]
struct delete_array
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<T [], void>
#endif
{
public:
    /// The argument type
    typedef T                                               argument_type[];
    /// The result type
    typedef void                                            result_type;

public:
    /// The function call operator, which deletes the given array
    ///
    /// \param t A pointer to an array of type T to be deleted
    void operator ()(T t[]) STLSOFT_NOEXCEPT
    {
        delete [] t;
    }
};


#if 0
// struct selector1st

/** Selects the <b><code>first</code></b> member of an instance and applies the
 * specialising functional to it. This functional selects the \c first member
 * of an instance (obviously this is usually the \c std::pair type), and
 * applies the specialising functional to it.
 *
 * \ingroup group__library__Functional
 *
 * \param F The specialising functional
 *
 * For example, if you have a std::map and wish to write out the keys
 * with a dump_key functional, you could achieve this with the following:
 *
 * &nbsp;&nbsp;<code>std::for_each(m.begin(), m.end(), stlsoft::selector1st<dump_key>());</code>
 *
 * \deprecated
 */
template<   ss_typename_param_k F
#ifndef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        ,   ss_typename_param_k T
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        >
// [[synesis:class:unary-functor: selector1st]]
struct selector1st
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<
                    ss_typename_type_k F::argument_type
                ,   ss_typename_type_k F::result_type
                >
#endif
{
public:
    typedef ss_typename_type_k F::argument_type             argument_type;
    typedef ss_typename_type_k F::result_type               result_type;

public:
    /// Default constructor
    selector1st()
        : m_f()
    {}

    /// Constructs from the given function class, which it will then apply
    /// via operator ()()
    ss_explicit_k
    selector1st(F f)
        : m_f(f)
    {}

    /// Function call operator, which applies the specialising function class
    /// to the \c first part of the pair \c t
    ///
    /// \param t An instance of a \c pair like type, to whose \c first member will be applied the function F
    // Regrettably, the current implementation only provides an instantiation
    // returning void
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k T>
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    result_type operator ()(T const& t) const
    {
        return m_f(t.first);
    }

// Members
private:
    F   m_f;
};

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
template<   ss_typename_param_k F
        >
inline selector1st<F> select1st(F f)
{
    return selector1st<F>(f);
}
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */

#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT

// struct selector2nd
//
/** Selects the <b><code>second</code></b> member of an instance and
 * applies the specialising functional to it.
 *
 * \ingroup group__library__Functional
 *
 * \param F The specialising functional
 *
 * This functional selects the "second" member of an instance (obviously
 * this is usually the std::pair type), and applies the specialising
 * functional to it.
 *
 * For example, if you have a std::map and wish to write out the values
 * with a dump_value functional, you could achieve this with the following:
 *
 * &nbsp;&nbsp;<code>std::for_each(m.begin(), m.end(), stlsoft::selector2nd<dump_value>());</code>
 *
 * \deprecated
 */

template<   ss_typename_param_k F
#ifndef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        ,   ss_typename_param_k T
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        >
// [[synesis:class:unary-functor: selector2nd]]
struct selector2nd
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<
                    ss_typename_type_k F::argument_type
                ,   ss_typename_type_k F::result_type
                >
#endif
{
public:
    typedef ss_typename_type_k F::argument_type             argument_type;
    typedef ss_typename_type_k F::result_type               result_type;

public:
    /// Default constructor
    selector2nd()
        : m_f()
    {}

    /// Constructs from the given function class, which it will then apply
    /// via operator ()()
    ss_explicit_k
    selector2nd(F f)
        : m_f(f)
    {}

    /// Function call operator, which applies the specialising function class
    /// to the \c second part of the pair \c t
    ///
    /// \param t An instance of a \c pair like type, to whose \c second member will be applied the function F
    // Regrettably, the current implementation only provides an instantiation
    // returning void
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k T>
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    result_type operator ()(T &t) const
    {
        return m_f(t.second);
    }

// Members
private:
    F   m_f;
};

#endif /* 0 */

// struct select_1st

/** Selects the <b><code>first</code></b> member of an instance and applies the
 * specialising functional to it. This functional selects the \c first member
 * of an instance (obviously this is usually the \c std::pair type), and
 * applies the specialising functional to it.
 *
 * \ingroup group__library__Functional
 *
 * \param F The specialising functional
 *
 * For example, if you have a std::map and wish to write out the keys
 * with a dump_key functional, you could achieve this with the following:
 *
 * &nbsp;&nbsp;<code>std::for_each(m.begin(), m.end(), stlsoft::select_1st<dump_key>());</code>
 *
 * \deprecated
 */
template<   ss_typename_param_k F
#ifndef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        ,   ss_typename_param_k T
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        >
// [[synesis:class:unary-functor: select_1st]]
struct select_1st
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<
                    ss_typename_type_k F::argument_type
                ,   ss_typename_type_k F::result_type
                >
#endif
{
public:
    /// The argument type
    typedef ss_typename_type_k F::argument_type             argument_type;
    /// The result type
    typedef ss_typename_type_k F::result_type               result_type;

public:
    /// Default constructor
    select_1st()
        : m_f()
    {}

    /// Constructs from the given function class, which it will then apply
    /// via operator ()()
    ss_explicit_k
    select_1st(F f)
        : m_f(f)
    {}

    /// Function call operator, which applies the specialising function class
    /// to the \c first part of the pair \c t
    ///
    /// \param t An instance of a \c pair like type, to whose \c first member will be applied the function F
    ///
    /// \note Regrettably, the current implementation only provides an instantiation
    /// returning void
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k T>
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    void operator ()(T &t)
    {
        m_f(t.first);
    }

// Members
private:
    F   m_f;
};

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
template<   ss_typename_param_k F
        >
inline select_1st<F> make_1st_selector(F f)
{
    return select_1st<F>(f);
}
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */

#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT

// struct select_2nd
//
/** Selects the <b><code>second</code></b> member of an instance and
 * applies the specialising functional to it.
 *
 * \ingroup group__library__Functional
 *
 * \param F The specialising functional
 *
 * This functional selects the "second" member of an instance (obviously
 * this is usually the std::pair type), and applies the specialising
 * functional to it.
 *
 * For example, if you have a std::map and wish to write out the values
 * with a dump_value functional, you could achieve this with the following:
 *
 * &nbsp;&nbsp;<code>std::for_each(m.begin(), m.end(), stlsoft::select_2nd<dump_value>());</code>
 *
 * \deprecated
 */

template<   ss_typename_param_k F
#ifndef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        ,   ss_typename_param_k T
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        >
// [[synesis:class:unary-functor: select_2nd]]
struct select_2nd
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<
                    ss_typename_type_k F::argument_type
                ,   ss_typename_type_k F::result_type
                >
#endif
{
public:
    typedef ss_typename_type_k F::argument_type             argument_type;
    typedef ss_typename_type_k F::result_type               result_type;

public:
    /// Default constructor
    select_2nd()
        : m_f()
    {}

    /// Constructs from the given function class, which it will then apply
    /// via operator ()()
    ss_explicit_k
    select_2nd(F f)
        : m_f(f)
    {}

    /// Function call operator, which applies the specialising function class
    /// to the \c second part of the pair \c t
    ///
    /// \param t An instance of a \c pair like type, to whose \c second member will be applied the function F
    // Regrettably, the current implementation only provides an instantiation
    // returning void
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k T>
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    void operator ()(T &t)
    {
        m_f(t.second);
    }

// Members
private:
    F   m_f;
};


// struct select_both
//
/** This functional selects both the \c first and \c second members of an instance
 * (obviously this is usually the std::pair type), and applies the respective
 * specialising functionals to them.
 *
 * \ingroup group__library__Functional
 *
 * \param F1 The functional to apply to the <b><code>first</code></b> part of the elements
 * \param F2 The functional to apply to the <b><code>second</code></b> part of the elements
 *
 * For example, if you have a std::map and wish to write out the keys with the
 * dump_key functional and the values with the dump_value functional, you could
 * achieve this with the following:
 *
 * &nbsp;&nbsp;<code>std::for_each(m.begin(), m.end(), stlsoft::select_both<dump_key, dump_value>());</code>
 *
 * \deprecated
 */

template<   ss_typename_param_k F1
        ,   ss_typename_param_k F2
#ifndef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        ,   ss_typename_param_k T
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        >
// [[synesis:class:unary-functor: select_both]]
struct select_both
#if __cplusplus < 201103L
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    : public STLSOFT_NS_QUAL_STD(unary_function)<void, void>
# else
    : public STLSOFT_NS_QUAL_STD(unary_function)<T &, void>
# endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
#endif
{
public:
    typedef void                                            argument_type;
    typedef void                                            result_type;

public:
    /// Default constructor
    select_both()
        : m_f1()
        , m_f2()
    {}

    /// Constructs from the given function classes, which it will then apply
    /// via operator ()()
    ss_explicit_k
    select_both(F1 f1, F2 f2)
        : m_f1(f1)
        , m_f2(f2)
    {}

    /// Function call operator, which applies the specialising function classes
    /// to the \c first and \c second parts of the pair \c t
    ///
    /// \param t An instance of a \c pair like type, to whose \c first and \c second members will be applied the functions F1 and F2
    // Regrettably, the current implementation only provides an instantiation
    // returning void
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k T>
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    void operator ()(T &t)
    {
        m_f1(t.first);
        m_f2(t.second);
    }

// Members
private:
    F1  m_f1;
    F2  m_f2;
};


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

#endif /* !STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_FUNCTIONALS */

/* ///////////////////////////// end of file //////////////////////////// */

