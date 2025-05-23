/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/shell/drophandle_sequence.hpp
 *
 * Purpose: Contains the basic_drophandle_sequence template class, and ANSI
 *          and Unicode specialisations thereof.
 *
 * Created: 13th November 2002
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
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


/** \file winstl/shell/drophandle_sequence.hpp
 *
 * \brief [C++] Definition of the winstl::basic_drophandle_sequence
 *  class template
 *   (\ref group__library__Windows_Shell "Windows Shell" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SHELL_HPP_DROPHANDLE_SEQUENCE
#define WINSTL_INCL_WINSTL_SHELL_HPP_DROPHANDLE_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHELL_HPP_DROPHANDLE_SEQUENCE_MAJOR      4
# define WINSTL_VER_WINSTL_SHELL_HPP_DROPHANDLE_SEQUENCE_MINOR      1
# define WINSTL_VER_WINSTL_SHELL_HPP_DROPHANDLE_SEQUENCE_REVISION   15
# define WINSTL_VER_WINSTL_SHELL_HPP_DROPHANDLE_SEQUENCE_EDIT       119
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

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#if defined(STLSOFT_CF_FRAME_STRING_SHIM_NOT_SUPPORTED) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1200)
# ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
#  include <winstl/memory/processheap_allocator.hpp>
# endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
# ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
#  include <stlsoft/string/simple_string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */
#else /* ? STLSOFT_CF_FRAME_STRING_SHIM_NOT_SUPPORTED */
# ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STATIC_STRING
#  include <stlsoft/string/static_string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STATIC_STRING */
#endif /* STLSOFT_CF_FRAME_STRING_SHIM_NOT_SUPPORTED */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_GENERATORS
# include <stlsoft/util/std/iterator_generators.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_GENERATORS */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */

#ifndef STLSOFT_INCL_H_SHELLAPI
# define STLSOFT_INCL_H_SHELLAPI
# include <shellapi.h>
#endif /* !STLSOFT_INCL_H_SHELLAPI */


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
 * typedefs
 */

#ifdef _STLSOFT_DROPHANDLE_SEQUENCE_VALUE_TYPE
# undef _STLSOFT_DROPHANDLE_SEQUENCE_VALUE_TYPE
#endif /* _STLSOFT_DROPHANDLE_SEQUENCE_VALUE_TYPE */

#if defined(STLSOFT_CF_FRAME_STRING_SHIM_NOT_SUPPORTED) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1200)
# define _STLSOFT_DROPHANDLE_SEQUENCE_VALUE_TYPE(C)     STLSOFT_NS_QUAL(basic_simple_string)<C, STLSOFT_NS_QUAL(char_traits)<C>, processheap_allocator<C> >
#else /* ? STLSOFT_CF_FRAME_STRING_SHIM_NOT_SUPPORTED */
# define _STLSOFT_DROPHANDLE_SEQUENCE_VALUE_TYPE(C)     STLSOFT_NS_QUAL(basic_static_string)<C, WINSTL_CONST_MAX_PATH>
#endif /* STLSOFT_CF_FRAME_STRING_SHIM_NOT_SUPPORTED */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C, ss_typename_param_k T>
class basic_drophandle_sequence;

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** Traits for accessing the correct drop-handle functions for a given character type
 *
 * \ingroup group__library__Windows_Shell
 *
 * drophandle_sequence_traits is a traits class for determining the correct
 * drop-handle structures and functions for a given character type.
 *
 * \param C The character type
 */
template <ss_typename_param_k C>
struct drophandle_sequence_traits
{
    /// Queries the information from the given drop handle
    ///
    /// \param hdrop The drop handle
    /// \param index The index of the requested item
    /// \param buffer The buffer within which to write the results
    /// \param cchBuffer The size of \c buffer in characters
    static ws_uint_t drag_query_file(HDROP hdrop, ws_uint_t index, C* buffer, ws_uint_t cchBuffer);
};

#else

template <ss_typename_param_k C>
struct drophandle_sequence_traits;

STLSOFT_TEMPLATE_SPECIALISATION

struct drophandle_sequence_traits<ws_char_a_t>
{
    static ws_uint_t drag_query_file(HDROP hdrop, ws_uint_t index, ws_char_a_t* buffer, ws_uint_t cchBuffer)
    {
        return DragQueryFileA(hdrop, index, buffer, cchBuffer);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct drophandle_sequence_traits<ws_char_w_t>
{
    static ws_uint_t drag_query_file(HDROP hdrop, ws_uint_t index, ws_char_w_t* buffer, ws_uint_t cchBuffer)
    {
        return DragQueryFileW(hdrop, index, buffer, cchBuffer);
    }
};

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */


// class basic_drophandle_sequence_const_iterator
/** Iterator for the basic_drophandle_sequence class
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param C The character type
 * \param T The traits type. For translators that support default template arguments this defaults to drophandle_sequence_traits<C>
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = drophandle_sequence_traits<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = drophandle_sequence_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_drophandle_sequence_const_iterator
    : public STLSOFT_NS_QUAL(iterator_base)<STLSOFT_NS_QUAL_STD(bidirectional_iterator_tag)
                                        ,   _STLSOFT_DROPHANDLE_SEQUENCE_VALUE_TYPE(C)
                                        ,   ws_ptrdiff_t
                                        ,   void                                        // By-Value Temporary reference
                                        ,   _STLSOFT_DROPHANDLE_SEQUENCE_VALUE_TYPE(C)  // By-Value Temporary reference category
                                        >
{
public:
    /// The character type
    typedef C                                                   char_type;
    /// The traits type
    typedef T                                                   traits_type;
    /// The string type
    typedef _STLSOFT_DROPHANDLE_SEQUENCE_VALUE_TYPE(C)          string_type;
    /// The current specialisation of the type
    typedef basic_drophandle_sequence_const_iterator<C, T>      class_type;
    /// The value type
    typedef string_type                                         value_type;
    /// The index type
    typedef ws_uint_t                                           index_type;

// Construction
protected:
    /// Create an iterator based on the given drop handle
    ss_explicit_k basic_drophandle_sequence_const_iterator(HDROP hdrop, index_type index);
public:
    // Default constructor
    basic_drophandle_sequence_const_iterator();
    /// Copy constructor
    basic_drophandle_sequence_const_iterator(class_type const& rhs);

    /// Copy assignment operator
    basic_drophandle_sequence_const_iterator& operator =(class_type const& rhs);

// Operators
public:
    /// Pre-increment operator
    class_type&         operator ++();
    /// Pre-decrement operator
    class_type&         operator --();
    /// Post-increment operator
    class_type          operator ++(int);
    /// Post-decrement operator
    class_type          operator --(int);
    /// Dereference
    const value_type    operator *() const;
    /// Evaluates whether \c this and \c rhs are equivalent
    ws_bool_t           equal(class_type const& rhs) const;

#if 0
private:
    value_type          *operator ->();
    value_type const    *operator ->() const;
#endif /* 0 */

// Implementation
private:
    static index_type sentinel_();

// Members
private:
    friend class basic_drophandle_sequence<C, T>;

    HDROP       m_hdrop;
    index_type  m_index;
};


// class basic_drophandle_sequence
/** This class wraps an STL-like sequence interface over a Win32 drop handle
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param C The character type
 * \param T The traits type. For translators that support default template arguments this defaults to drophandle_sequence_traits<C>
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = drophandle_sequence_traits<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = drophandle_sequence_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_drophandle_sequence
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
public:
    /// The character type
    typedef C                                                                               char_type;
    /// The traits type
    typedef T                                                                               traits_type;
    /// The current specialisation of the type
    typedef basic_drophandle_sequence<C, T>                                                 class_type;
    /// The non-mutating (const) iterator type
    typedef basic_drophandle_sequence_const_iterator<C, T>                                  const_iterator;
    /// The value type
    typedef ss_typename_type_k const_iterator::value_type                                   value_type;
    /// The difference type
    typedef ws_ptrdiff_t                                                                    difference_type;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
    /// The non-mutating (const) reverse iterator type
    typedef
#if !defined(STLSOFT_COMPILER_IS_BORLAND)
            ss_typename_type_k
#endif /* compiler */
                               STLSOFT_NS_QUAL(const_reverse_iterator_generator)<   const_iterator
                                                                                ,   value_type
                                                                                ,   value_type  // By-Value Temporary reference category
                                                                                ,   void        // By-Value Temporary reference category
                                                                                ,   difference_type
                                                                                >::type     const_reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

// Construction
public:
    /// Construct a sequence based on the contents of the given drop handle
    ss_explicit_k basic_drophandle_sequence(HDROP hdrop, ws_bool_t bOwnHandle = true);
    /// Release any resources acquired
    ~basic_drophandle_sequence() STLSOFT_NOEXCEPT;
private:
    basic_drophandle_sequence(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

// Attributes
public:
    /// The number of elements in the sequence
    ws_size_t       size() const;
    /// Indicates whether the sequence is empty
    ws_bool_t       empty() const;

// Iteration
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const;

#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
    /// Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    const_reverse_iterator  rbegin() const;
    /// Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    const_reverse_iterator  rend() const;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

// Members
private:
    HDROP           m_hdrop;
    const ws_bool_t m_bOwnHandle;

// Implementation
private:
};

/* Typedefs to commonly encountered types. */
/** Specialisation of the basic_drophandle_sequence template for the ANSI character type \c char
 *
 * \ingroup group__library__Windows_Shell
 */
typedef basic_drophandle_sequence<ws_char_a_t, drophandle_sequence_traits<ws_char_a_t> >    drophandle_sequence_a;
/** Specialisation of the basic_drophandle_sequence template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__Windows_Shell
 */
typedef basic_drophandle_sequence<ws_char_w_t, drophandle_sequence_traits<ws_char_w_t> >    drophandle_sequence_w;
/** Specialisation of the basic_drophandle_sequence template for the ANSI character type \c char
 *
 * \ingroup group__library__Windows_Shell
 */
typedef basic_drophandle_sequence<TCHAR, drophandle_sequence_traits<TCHAR> >                drophandle_sequence;


////////////////////////////////////////////////////////////////////////////
// Operators

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_bool_t operator ==(   basic_drophandle_sequence_const_iterator<C, T> const&   lhs
                            ,   basic_drophandle_sequence_const_iterator<C, T> const&   rhs)
{
    return lhs.equal(rhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_bool_t operator !=(   basic_drophandle_sequence_const_iterator<C, T> const&   lhs
                            ,   basic_drophandle_sequence_const_iterator<C, T> const&   rhs)
{
    return !lhs.equal(rhs);
}

////////////////////////////////////////////////////////////////////////////

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// basic_drophandle_sequence_const_iterator

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline /* static */ ss_typename_type_ret_k basic_drophandle_sequence_const_iterator<C, T>::index_type basic_drophandle_sequence_const_iterator<C, T>::sentinel_()
{
    return 0x7fffffff;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline /* ss_explicit_k */ basic_drophandle_sequence_const_iterator<C, T>::basic_drophandle_sequence_const_iterator(HDROP hdrop, ss_typename_type_k basic_drophandle_sequence_const_iterator<C, T>::index_type index)
    : m_hdrop(hdrop)
    , m_index(index)
{}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_drophandle_sequence_const_iterator<C, T>::basic_drophandle_sequence_const_iterator()
    : m_hdrop(0)
    , m_index(sentinel_())
{}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_drophandle_sequence_const_iterator<C, T>::basic_drophandle_sequence_const_iterator(ss_typename_type_k basic_drophandle_sequence_const_iterator<C, T>::class_type const& rhs)
    : m_hdrop(rhs.m_hdrop)
    , m_index(rhs.m_index)
{}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_ret_k basic_drophandle_sequence_const_iterator<C, T>::class_type& basic_drophandle_sequence_const_iterator<C, T>::operator =(ss_typename_type_k basic_drophandle_sequence_const_iterator<C, T>::class_type const& rhs)
{
    m_hdrop = rhs.m_hdrop;
    m_index = rhs.m_index;

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_ret_k basic_drophandle_sequence_const_iterator<C, T>::class_type& basic_drophandle_sequence_const_iterator<C, T>::operator ++()
{
    WINSTL_MESSAGE_ASSERT("Incrementing the end iterator", m_index != sentinel_());

    ws_uint_t const res = traits_type::drag_query_file(m_hdrop, static_cast<ws_uint_t>(m_index + 1), NULL, 0);

    if (res == 0)
    {
        // Failed, so become 'end'
        m_index = sentinel_();
    }
    else
    {
        // Fine, so increment to next
        ++m_index;
    }

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_ret_k basic_drophandle_sequence_const_iterator<C, T>::class_type& basic_drophandle_sequence_const_iterator<C, T>::operator --()
{
    // If currently at 'end' ....
    if (m_index == sentinel_())
    {
        // ... then determine the new end ...
        m_index = static_cast<index_type>(traits_type::drag_query_file(m_hdrop, static_cast<ws_uint_t>(0xFFFFFFFF), NULL, 0));

        if (m_index == 0xFFFFFFFF)
        {
            // ... failed. Must set to end again!
            m_index = sentinel_();
        }
        else
        {
            // ... decrement from end
            --m_index;
        }
    }
    else
    {
        // ... decrement from current position
        --m_index;
    }

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_ret_k basic_drophandle_sequence_const_iterator<C, T>::class_type basic_drophandle_sequence_const_iterator<C, T>::operator ++(int)
{
    class_type  ret(*this);

    operator ++();

    return ret;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_ret_k basic_drophandle_sequence_const_iterator<C, T>::class_type basic_drophandle_sequence_const_iterator<C, T>::operator --(int)
{
    class_type  ret(*this);

    operator --();

    return ret;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline const ss_typename_type_k basic_drophandle_sequence_const_iterator<C, T>::value_type basic_drophandle_sequence_const_iterator<C, T>::operator *() const
{
    WINSTL_MESSAGE_ASSERT("Dereferencing the end iterator", m_index != sentinel_());

    ws_uint_t                               cch =   traits_type::drag_query_file(m_hdrop, static_cast<ws_uint_t>(m_index), NULL, 0);
    STLSOFT_NS_QUAL(auto_buffer)<char_type> sz(1 + cch);

    if (0 == sz.size() ||
        0 == (cch = traits_type::drag_query_file(m_hdrop, static_cast<ws_uint_t>(m_index), &sz[0], ws_uint_t(sz.size()))))
    {
        sz[0] = '\0';
    }

    return value_type(sz.data());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_bool_t basic_drophandle_sequence_const_iterator<C, T>::equal(ss_typename_type_k basic_drophandle_sequence_const_iterator<C, T>::class_type const& rhs) const
{
    WINSTL_MESSAGE_ASSERT("Comparing iterators from different sequences", (m_hdrop == NULL || rhs.m_hdrop == NULL || m_hdrop == rhs.m_hdrop));

    return m_index == rhs.m_index;
}

// basic_drophandle_sequence

template <ss_typename_param_k C, ss_typename_param_k T>
inline basic_drophandle_sequence<C, T>::basic_drophandle_sequence(HDROP hdrop, ws_bool_t bOwnHandle /* = true */)
    : m_hdrop(hdrop)
    , m_bOwnHandle(bOwnHandle)
{}

template <ss_typename_param_k C, ss_typename_param_k T>
inline basic_drophandle_sequence<C, T>::~basic_drophandle_sequence() STLSOFT_NOEXCEPT
{
    if (m_bOwnHandle)
    {
        ::DragFinish(m_hdrop);
    }
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ws_size_t basic_drophandle_sequence<C, T>::size() const
{
    return traits_type::drag_query_file(m_hdrop, static_cast<ws_uint_t>(0xFFFFFFFF), NULL, 0);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ws_bool_t basic_drophandle_sequence<C, T>::empty() const
{
    return 0 == size();
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_ret_k basic_drophandle_sequence<C, T>::const_iterator basic_drophandle_sequence<C, T>::begin() const
{
    ws_uint_t const res = traits_type::drag_query_file(m_hdrop, 0, NULL, 0);

    return const_iterator(m_hdrop, (res == 0) ? const_iterator::sentinel_() : 0);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_ret_k basic_drophandle_sequence<C, T>::const_iterator basic_drophandle_sequence<C, T>::end() const
{
    return const_iterator(m_hdrop, const_iterator::sentinel_());
}

#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_ret_k basic_drophandle_sequence<C, T>::const_reverse_iterator basic_drophandle_sequence<C, T>::rbegin() const
{
    return const_reverse_iterator(end());
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_ret_k basic_drophandle_sequence<C, T>::const_reverse_iterator basic_drophandle_sequence<C, T>::rend() const
{
    return const_reverse_iterator(begin());
}
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !WINSTL_INCL_WINSTL_SHELL_HPP_DROPHANDLE_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

