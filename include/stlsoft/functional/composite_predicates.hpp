/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/functional/composite_predicates.hpp
 *
 * Purpose:     Definition of composite predicates function templates.
 *
 * Created:     27th March 2007
 * Updated:     20th March 2025
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/functional/composite_predicates.hpp
 *
 * \brief [C++] Definition of the composite predicates function templates
 *   (\ref group__library__Functional "Functional" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_COMPOSITE_PREDICATES
#define STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_COMPOSITE_PREDICATES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_COMPOSITE_PREDICATES_MAJOR      1
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_COMPOSITE_PREDICATES_MINOR      1
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_COMPOSITE_PREDICATES_REVISION   6
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_COMPOSITE_PREDICATES_EDIT       17
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

#ifdef STLSOFT_CF_std_NAMESPACE
# include <functional>
#endif /* STLSOFT_CF_std_NAMESPACE */


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

/** Composite predicate providing logical OR for two individual
 *    predicate types.
 *
 * \ingroup group__library__Functional
 *
 */
template<
    ss_typename_param_k P1
,   ss_typename_param_k P2
>
// [[synesis:class:function-class:unary-predicate: any_of]]
struct any_of_tester
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<ss_typename_type_k P1::argument_type, ss_bool_t>
#endif
{
public:
    typedef ss_bool_t                                       bool_type;
    typedef ss_typename_type_k P1::argument_type            argument_type;
    typedef bool_type                                       result_type;

public:
    any_of_tester(P1 p1, P2 p2)
        : m_p1(p1)
        , m_p2(p2)
    {}

public:
    /// Returns true if either predicate is satisfied
    bool_type operator ()(argument_type a) const
    {
        return m_p1(a) || m_p2(a);
    }

private:
    P1  m_p1;
    P2  m_p2;
};

template<
    ss_typename_param_k P1
,   ss_typename_param_k P2
>
inline
any_of_tester<P1, P2> any_of(P1 p1, P2 p2)
{
    return any_of_tester<P1, P2>(p1, p2);
}

template<
    ss_typename_param_k P1
,   ss_typename_param_k P2
,   ss_typename_param_k P3
>
inline
any_of_tester<P1, any_of_tester<P2, P3> > any_of(P1 p1, P2 p2, P3 p3)
{
    return any_of(p1, any_of(p2, p3));
}

template<
    ss_typename_param_k P1
,   ss_typename_param_k P2
,   ss_typename_param_k P3
,   ss_typename_param_k P4
>
inline
any_of_tester<any_of_tester<P1, P2>, any_of_tester<P3, P4> > any_of(P1 p1, P2 p2, P3 p3, P4 p4)
{
    return any_of(any_of(p1, p2), any_of(p3, p4));
}

/** Composite predicate providing logical AND for two individual
 *    predicate types.
 *
 * \ingroup group__library__Functional
 *
 */
template<
    ss_typename_param_k P1
,   ss_typename_param_k P2
>
// [[synesis:class:function-class:unary-predicate: all_of]]
struct all_of_tester
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<ss_typename_type_k P1::argument_type, ss_bool_t>
#endif
{
public:
    typedef ss_bool_t                                       bool_type;
    typedef ss_typename_type_k P1::argument_type            argument_type;
    typedef bool_type                                       result_type;

public:
    all_of_tester(P1 p1, P2 p2)
        : m_p1(p1)
        , m_p2(p2)
    {}

public:
    /// Returns true if both predicates are satisfied
    bool_type operator ()(argument_type a) const
    {
        return m_p1(a) && m_p2(a);
    }

private:
    P1  m_p1;
    P2  m_p2;
};

template<
    ss_typename_param_k P1
,   ss_typename_param_k P2
>
inline
all_of_tester<P1, P2> all_of(P1 p1, P2 p2)
{
    return all_of_tester<P1, P2>(p1, p2);
}

template<
    ss_typename_param_k P1
,   ss_typename_param_k P2
,   ss_typename_param_k P3
>
inline
all_of_tester<P1, all_of_tester<P2, P3> > all_of(P1 p1, P2 p2, P3 p3)
{
    return all_of(p1, all_of(p2, p3));
}

template<
    ss_typename_param_k P1
,   ss_typename_param_k P2
,   ss_typename_param_k P3
,   ss_typename_param_k P4
>
inline
all_of_tester<all_of_tester<P1, P2>, all_of_tester<P3, P4> > all_of(P1 p1, P2 p2, P3 p3, P4 p4)
{
    return all_of(all_of(p1, p2), all_of(p3, p4));
}


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

#endif /* !STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_COMPOSITE_PREDICATES */

/* ///////////////////////////// end of file //////////////////////////// */

