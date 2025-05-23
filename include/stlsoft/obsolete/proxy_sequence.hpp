/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/obsolete/proxy_sequence.hpp
 *
 * Purpose:     proxy_sequence template class.
 *
 * Created:     10th September 2003
 * Updated:     20th March 2025
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/// \file stlsoft/obsolete/proxy_sequence.hpp
///
/// proxy_sequence template class.

#ifndef STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_PROXY_SEQUENCE
#define STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_PROXY_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_PROXY_SEQUENCE_MAJOR      3
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_PROXY_SEQUENCE_MINOR      0
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_PROXY_SEQUENCE_REVISION   6
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_PROXY_SEQUENCE_EDIT       45
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

#ifndef STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_PROXY_ITERATOR
# include <stlsoft/obsolete/proxy_iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_PROXY_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */


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

/** Enables a non-STL sequence to provide an STL interface
 *
 * \ingroup group__library__Collection
 *
 * \param E The element type. This type is the element in the underlying sequence
 * \param V The value type. This is the type to which the element type is translated
 * \param T The traits_type. This type provides a static method \c make_value(), which
 * converts the element type to the value type
 *
 * \deprecated This is maintained for backwards compatibility with the
 *   recls/COM library. New users should instead use
 *   stlsoft::transform_iterator.
 */
template<   ss_typename_param_k E
        ,   ss_typename_param_k V
        ,   ss_typename_param_k T
        >
class proxy_sequence
    : public stl_collection_tag
{
private:
    typedef STLSOFT_NS_QUAL_STD(random_access_iterator_tag) tag_type;
public:
    typedef E                                               element_type;
    typedef V                                               value_type;
    typedef T                                               traits_type;
    typedef proxy_sequence<E, V, T>                         class_type;
    typedef proxy_iterator<E, V, T, tag_type>               iterator;
    typedef proxy_iterator<E, const V, T, tag_type>         const_iterator;
    typedef ss_size_t                                       size_type;

public:
    /// Constructs a default proxy_sequence
    proxy_sequence()
        : m_begin(0)
        , m_end(0)
    {}

#if !defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Constructs a proxy_sequence from a given range.
    proxy_sequence(element_type* first, element_type* last)
        : m_begin(first)
        , m_end(last)
    {}
#endif /* !STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Constructs a proxy_sequence from a given range.
    template <ss_typename_param_k P>
    proxy_sequence(P* first, P* last)
        : m_begin(first)
        , m_end(last)
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

#if !defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Constructs a proxy_sequence from a given range.
    proxy_sequence(element_type *first, size_type n)
        : m_begin(first)
        , m_end(&first[n])
    {}
#endif /* !STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Constructs a proxy_sequence from a given range.
    template <ss_typename_param_k P>
    proxy_sequence(P *first, size_type n)
        : m_begin(first)
        , m_end(&first[n])
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    iterator    begin()
    {
        return iterator(m_begin, m_end);
    }
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    iterator    end()
    {
        return iterator();
    }
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const
    {
        return const_iterator(m_begin, m_end);
    }
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const
    {
        return const_iterator();
    }
/// @}

/// \name Attributes
/// @{
public:
    /// Indicates whether the sequence is empty
    bool empty() const
    {
        return m_begin == m_end;
    }

    /// Indicates whether the sequence is empty
    size_type size() const
    {
        return m_end - m_begin;
    }
/// @}

// Members
private:
    element_type    *m_begin;
    element_type    *m_end;
};

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

#endif /* !STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_PROXY_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

