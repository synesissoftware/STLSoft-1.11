/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/window/zorder_sequences.hpp
 *
 * Purpose: Collection of the peers of a given window.
 *
 * Created: 11th July 2005
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
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


/** \file winstl/window/zorder_sequences.hpp
 *
 * \brief [C++] Definition of the winstl::child_window_sequence and
 *   winstl::window_peer_sequence sequence classes
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_HPP_ZORDER_SEQUENCES
#define WINSTL_INCL_WINSTL_WINDOW_HPP_ZORDER_SEQUENCES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_HPP_ZORDER_SEQUENCES_MAJOR    2
# define WINSTL_VER_WINSTL_WINDOW_HPP_ZORDER_SEQUENCES_MINOR    0
# define WINSTL_VER_WINSTL_WINDOW_HPP_ZORDER_SEQUENCES_REVISION 10
# define WINSTL_VER_WINSTL_WINDOW_HPP_ZORDER_SEQUENCES_EDIT     34
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

#ifndef WINSTL_INCL_WINSTL_WINDOW_HPP_ZORDER_ITERATOR
# include <winstl/window/zorder_iterator.hpp>
#endif /* !WINSTL_INCL_WINSTL_WINDOW_HPP_ZORDER_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */


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

/** Window peer sequence
 *
 * \ingroup group__library__Windows_Window
 */
template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
class zorder_sequence_base
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
public: // types
    /// The mutating (non-const) iterator type
    typedef zorder_iterator                                 iterator;
    /// The value type
    typedef iterator::value_type                            value_type;
    /// The size type
    typedef iterator::size_type                             size_type;
    /// The difference type
    typedef iterator::difference_type                       difference_type;
    /// The non-mutating (const) iterator type
    typedef zorder_iterator                                 const_iterator;
    /// The mutating (non-const) reverse iterator type
    typedef iterator::base_iterator_type                    reverse_iterator;
    /// The non-mutating (const) reverse iterator type
    typedef const_iterator::base_iterator_type              const_reverse_iterator;
    /// This class
    typedef zorder_sequence_base<B, E>                      class_type;

public: // construction
    /// Constructs a sequence of peers of the given window
    ss_explicit_k zorder_sequence_base(HWND hwndRoot);
private:
    zorder_sequence_base(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

public: // iteration
    iterator                begin();
    iterator                end();
    const_iterator          begin() const;
    const_iterator          end() const;
    reverse_iterator        rbegin();
    reverse_iterator        rend();
    const_reverse_iterator  rbegin() const;
    const_reverse_iterator  rend() const;

public: // state
    ws_bool_t   empty() const;

private: // fields
    HWND    m_hwnd;
};


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** Specialisation of \link winstl::zorder_sequence_base zorder_sequence_base\endlink
 *    that searches the children of a given window.
 *
 * \ingroup group__library__Windows_Window
 */
typedef zorder_sequence_base<
    zorder_iterator_base::fromFirstChild
,   zorder_iterator_base::atLastChild
>                                                           child_window_sequence;

/** Specialisation of \link winstl::zorder_sequence_base zorder_sequence_base\endlink
 *    that searches the peers of a given window.
 *
 * \ingroup group__library__Windows_Window
 */
typedef zorder_sequence_base<
    zorder_iterator_base::fromFirstPeer
,   zorder_iterator_base::atLastPeer
>                                                           window_peer_sequence;


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
inline
/* ss_explicit_k */
zorder_sequence_base<B, E>::zorder_sequence_base(HWND hwndRoot)
    : m_hwnd(hwndRoot)
{}

template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
inline
ss_typename_type_ret_k zorder_sequence_base<B, E>::iterator
zorder_sequence_base<B, E>::begin()
{
    return iterator::create(m_hwnd, B);
}

template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
inline
ss_typename_type_ret_k zorder_sequence_base<B, E>::iterator
zorder_sequence_base<B, E>::end()
{
    return iterator::create(m_hwnd, E);
}

template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
inline
ss_typename_type_ret_k zorder_sequence_base<B, E>::const_iterator
zorder_sequence_base<B, E>::begin() const
{
    return const_iterator::create(m_hwnd, B);
}

template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
inline
ss_typename_type_ret_k zorder_sequence_base<B, E>::const_iterator
zorder_sequence_base<B, E>::end() const
{
    return const_iterator::create(m_hwnd, E);
}

template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
inline
ss_typename_type_ret_k zorder_sequence_base<B, E>::reverse_iterator
zorder_sequence_base<B, E>::rbegin()
{
    return reverse_iterator::create(m_hwnd, B);
}

template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
inline
ss_typename_type_ret_k zorder_sequence_base<B, E>::reverse_iterator
zorder_sequence_base<B, E>::rend()
{
    return reverse_iterator::create(m_hwnd, E);
}

template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
inline
ss_typename_type_ret_k zorder_sequence_base<B, E>::const_reverse_iterator
zorder_sequence_base<B, E>::rbegin() const
{
    return const_reverse_iterator::create(m_hwnd, B);
}

template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
inline
ss_typename_type_ret_k zorder_sequence_base<B, E>::const_reverse_iterator
zorder_sequence_base<B, E>::rend() const
{
    return const_reverse_iterator::create(m_hwnd, E);
}

template<
    zorder_iterator_base::search    B
,   zorder_iterator_base::search    E
>
inline
ws_bool_t
zorder_sequence_base<B, E>::empty() const
{
    return end() == begin();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

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

#endif /* !WINSTL_INCL_WINSTL_WINDOW_HPP_ZORDER_SEQUENCES */

/* ///////////////////////////// end of file //////////////////////////// */

