/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/window/zorder_iterator.hpp
 *
 * Purpose: Z-order iteration.
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


/** \file winstl/window/zorder_iterator.hpp
 *
 * \brief [C++] Definition of the winstl::zorder_iterator class
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_HPP_ZORDER_ITERATOR
#define WINSTL_INCL_WINSTL_WINDOW_HPP_ZORDER_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_HPP_ZORDER_ITERATOR_MAJOR     2
# define WINSTL_VER_WINSTL_WINDOW_HPP_ZORDER_ITERATOR_MINOR     0
# define WINSTL_VER_WINSTL_WINDOW_HPP_ZORDER_ITERATOR_REVISION  13
# define WINSTL_VER_WINSTL_WINDOW_HPP_ZORDER_ITERATOR_EDIT      63
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

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_EXTERNAL_ITERATOR_INVALIDATION
# include <stlsoft/error/external_iterator_invalidation.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_EXTERNAL_ITERATOR_INVALIDATION */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */


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

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

struct zorder_iterator_base
{
public:
    enum search
    {
            fromFirstPeer   =   1   //!< Positions the iterator at the start of the list of peers of the given window
        ,   fromCurrent     =   2   //!< Positions the iterator at point of the given window in its list of window peers
        ,   atLastPeer      =   3   //!< Positions the iterator at the end of the list of peers of the given window
        ,   fromFirstChild  =   4   //!< Positions the iterator at the start of the list of children of the given window
        ,   atLastChild     =   5   //!< Positions the iterator at the end of the list of children of the given window
    };
};

struct zorder_iterator_forward_traits;
struct zorder_iterator_reverse_traits;

struct zorder_iterator_forward_traits
{
public:
    typedef zorder_iterator_forward_traits                  this_type;
    typedef zorder_iterator_reverse_traits                  alternate_type;

public:
    static HWND get_first_child(HWND hwnd)
    {
        return ::GetWindow(hwnd, GW_CHILD);
    }
    static HWND get_first_peer(HWND hwnd)
    {
        return ::GetWindow(hwnd, GW_HWNDFIRST);
    }
    static HWND get_next_peer(HWND hwnd)
    {
        return ::GetWindow(hwnd, GW_HWNDNEXT);
    }
    static HWND get_previous_peer(HWND hwnd)
    {
        return ::GetWindow(hwnd, GW_HWNDPREV);
    }
    static HWND get_last_peer(HWND hwnd)
    {
        return ::GetWindow(hwnd, GW_HWNDLAST);
    }
};

struct zorder_iterator_reverse_traits
{
public:
    typedef zorder_iterator_reverse_traits                  this_type;
    typedef zorder_iterator_forward_traits                  alternate_type;

public:
    static HWND get_first_child(HWND hwnd)
    {
        return ::GetWindow(::GetWindow(hwnd, GW_CHILD), GW_HWNDLAST);
    }
    static HWND get_first_peer(HWND hwnd)
    {
        return ::GetWindow(hwnd, GW_HWNDLAST);
    }
    static HWND get_next_peer(HWND hwnd)
    {
        return ::GetWindow(hwnd, GW_HWNDPREV);
    }
    static HWND get_previous_peer(HWND hwnd)
    {
        return ::GetWindow(hwnd, GW_HWNDNEXT);
    }
    static HWND get_last_peer(HWND hwnd)
    {
        return ::GetWindow(hwnd, GW_HWNDFIRST);
    }
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Iterates over the Z-order of window peers
 *
 * \ingroup group__library__Windows_Window
 */
template <ss_typename_param_k T>
class zorder_iterator_tmpl
    : public zorder_iterator_base
#if 0
    , public STLSOFT_NS_QUAL(iterator_base)<STLSOFT_NS_QUAL_STD(bidirectional_iterator_tag)
#else /* ? 0 */
    , public STLSOFT_NS_QUAL(iterator_base)<STLSOFT_NS_QUAL_STD(input_iterator_tag)
#endif /* 0 */
,   HWND
,   ws_ptrdiff_t
,   void    // By-Value Temporary reference
,   HWND    // By-Value Temporary reference: This has to be non-void, otherwise reverse_iterator::operator *() will return void
>
{
/// \name Types
/// @{
public:
    typedef T                                               traits_type;
    typedef HWND                                            value_type;
    typedef ws_size_t                                       size_type;
    typedef ws_ptrdiff_t                                    difference_type;
    typedef zorder_iterator_tmpl<
        traits_type
    >                                                       class_type;
    typedef zorder_iterator_tmpl<
        ss_typename_type_k traits_type::alternate_type
    >                                                       base_iterator_type;
    typedef base_iterator_type                              iterator_type;
/// @}

/// \name Construction
/// @{
private:
    zorder_iterator_tmpl(
        HWND    hwndRoot
    ,   HWND    hwndCurrent
    );
public:
    zorder_iterator_tmpl();
    ~zorder_iterator_tmpl() STLSOFT_NOEXCEPT;

    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

    static
    class_type
    create(
        HWND    hwndRoot
    ,   search  from
    );
/// @}

/// \name Iteration
/// @{
public:
    /// \name Input Iterator Methods
    /// @{
    class_type& operator ++();
    class_type  operator ++(int);
    value_type  operator *() const;
    /// @}

    /// \name Bidirectional Iterator Methods
    /// @{
    class_type& operator --();
    class_type  operator --(int);
    /// @}
    base_iterator_type base() const;
/// @}

/// \name Comparison
/// @{
public:
    bool equal(class_type const& rhs) const;
/// @}

/// \name Implementation
/// @{
private:
    static
    HWND
    get_next_window_(
        HWND    hwnd
    ,   HWND  (*pfn)(HWND )
    ) /* throw(stlsoft::external_iterator_invalidation) */;
/// @}

/// \name Members
/// @{
private:
    HWND    m_hwndRoot;
    HWND    m_hwndCurrent;
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** Specialisation of \link winstl::zorder_iterator_tmpl zorder_iterator_tmpl\endlink
 *    that searches a set of window peers in the forward direction.
 *
 * \ingroup group__library__Windows_Window
 */
typedef zorder_iterator_tmpl<zorder_iterator_forward_traits>    zorder_iterator;


/* /////////////////////////////////////////////////////////////////////////
 * Proscribe the use of std::reverse_iterator
 */

#if 0
STLSOFT_TEMPLATE_SPECIALISATION
class std::ostream_iterator<zorder_iterator_tmpl<zorder_iterator_forward_traits> >;

STLSOFT_TEMPLATE_SPECIALISATION
class std::ostream_iterator<zorder_iterator_tmpl<zorder_iterator_reverse_traits> >;
#endif /* 0 */


/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template <ss_typename_param_k T>
inline
bool
operator ==(
    zorder_iterator_tmpl<T> const&  lhs
,   zorder_iterator_tmpl<T> const&  rhs
)
{
    return lhs.equal(rhs);
}
template <ss_typename_param_k T>
inline
bool
operator !=(
    zorder_iterator_tmpl<T> const&  lhs
,   zorder_iterator_tmpl<T> const&  rhs
)
{
    return !lhs.equal(rhs);
}


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
inline
/* static */
HWND
zorder_iterator_tmpl<T>::get_next_window_(
    HWND    hwnd
,   HWND  (*pfn)(HWND )
) /* throw(stlsoft::external_iterator_invalidation) */
{
    hwnd = (*pfn)(hwnd);

    if (NULL == hwnd)
    {
        DWORD const dwErr = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

//        if (ERROR_INVALID_WINDOW_HANDLE == dwErr)
        if (ERROR_SUCCESS != dwErr)
        {
            STLSOFT_THROW_X(STLSOFT_NS_QUAL(external_iterator_invalidation)("z-order search failed: window has been destroyed", static_cast<long>(dwErr)));
        }
    }

    return hwnd;
}

template <ss_typename_param_k T>
inline
zorder_iterator_tmpl<T>::zorder_iterator_tmpl()
    : m_hwndRoot(NULL)
    , m_hwndCurrent(NULL)
{}

template <ss_typename_param_k T>
inline
zorder_iterator_tmpl<T>::zorder_iterator_tmpl(
    HWND    hwndRoot
,   HWND    hwndCurrent
)
    : m_hwndRoot(hwndRoot)
    , m_hwndCurrent(hwndCurrent)
{}

template <ss_typename_param_k T>
inline
zorder_iterator_tmpl<T>::~zorder_iterator_tmpl() STLSOFT_NOEXCEPT
{}

/*
template <ss_typename_param_k T>
inline
ss_typename_type_ret_k zorder_iterator_tmpl<T>::class_type&
zorder_iterator_tmpl<T>::operator =(ss_typename_type_k zorder_iterator_tmpl<T>::class_type const& rhs)
{
    WINSTL_ASSERT(NULL == m_hwndRoot || NULL == rhs.m_hwndRoot || (rhs.m_hwndRoot == m_hwndRoot));

    m_hwndCurrent = rhs.m_hwndCurrent;

    return *this;
}
 */

template <ss_typename_param_k T>
inline
/* static */
zorder_iterator_tmpl<T>
zorder_iterator_tmpl<T>::create(
    HWND    hwndRoot
,   search  from
)
{
    HWND    hwndCurrent;

    switch (from)
    {
    case    fromFirstChild:
    case    atLastChild:

        hwndRoot = get_next_window_(hwndRoot, traits_type::get_first_child);
    default:

        break;
    }

    switch (from)
    {
    case    fromCurrent:

        hwndCurrent = hwndRoot;
        break;
    case    fromFirstPeer:
    case    fromFirstChild:

        hwndCurrent = get_next_window_(hwndRoot, traits_type::get_first_peer);
        break;
    case    atLastChild:
    case    atLastPeer:

        hwndCurrent = NULL;
        break;
    }

    return zorder_iterator_tmpl<T>(hwndRoot, hwndCurrent);
}

template <ss_typename_param_k T>
inline
ss_typename_type_ret_k zorder_iterator_tmpl<T>::class_type&
zorder_iterator_tmpl<T>::operator ++()
{
    WINSTL_MESSAGE_ASSERT("Attempt to increment an invalid / out-of-range iterator", NULL != m_hwndCurrent);

    m_hwndCurrent  = class_type::get_next_window_(m_hwndCurrent, traits_type::get_next_peer);

    return *this;
}

template <ss_typename_param_k T>
inline
ss_typename_type_ret_k zorder_iterator_tmpl<T>::class_type
zorder_iterator_tmpl<T>::operator ++(int)
{
    class_type ret(*this);

    operator ++();

    return ret;
}

template <ss_typename_param_k T>
inline
ss_typename_type_ret_k zorder_iterator_tmpl<T>::class_type&
zorder_iterator_tmpl<T>::operator --()
{
    WINSTL_MESSAGE_ASSERT("Attempt to decrement an invalid / out-of-range iterator", NULL != m_hwndRoot);

    if (NULL != m_hwndCurrent)
    {
        m_hwndCurrent = class_type::get_next_window_(m_hwndCurrent, traits_type::get_previous_peer);
    }
    else
    {
        m_hwndCurrent = class_type::get_next_window_(m_hwndRoot, traits_type::get_last_peer);
    }

    return *this;
}

template <ss_typename_param_k T>
inline
ss_typename_type_ret_k zorder_iterator_tmpl<T>::class_type
zorder_iterator_tmpl<T>::operator --(int)
{
    class_type ret(*this);

    operator --();

    return ret;
}

template <ss_typename_param_k T>
inline
ss_typename_type_ret_k zorder_iterator_tmpl<T>::base_iterator_type
zorder_iterator_tmpl<T>::base() const
{
    base_iterator_type it = base_iterator_type::create(m_hwndCurrent, fromCurrent);

    return ++it;
}

template <ss_typename_param_k T>
inline
ss_typename_type_ret_k zorder_iterator_tmpl<T>::value_type
zorder_iterator_tmpl<T>::operator *() const
{
    return m_hwndCurrent;
}

template <ss_typename_param_k T>
inline
bool
zorder_iterator_tmpl<T>::equal(ss_typename_type_k zorder_iterator_tmpl<T>::class_type const& rhs) const
{
    WINSTL_MESSAGE_ASSERT("Iterators are not endpoint iterators, and refer to different collections", (NULL == m_hwndRoot || NULL == rhs.m_hwndRoot || (rhs.m_hwndRoot == m_hwndRoot)));

    return m_hwndCurrent == rhs.m_hwndCurrent;
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

#endif /* !WINSTL_INCL_WINSTL_WINDOW_HPP_ZORDER_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */

