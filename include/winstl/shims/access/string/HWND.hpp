/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/shims/access/string/HWND.hpp
 *
 * Purpose: Contains classes and functions for dealing with Win32 strings.
 *
 * Created: 24th May 2002
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


/** \file winstl/shims/access/string/HWND.hpp
 *
 * \brief [C++] Definition of the string access shims for
 *   <code>HWND</code>
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_HWND
#define WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_HWND

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_HWND_MAJOR       4
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_HWND_MINOR       1
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_HWND_REVISION    12
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_HWND_EDIT        133
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef WINSTL_INCL_WINSTL_WINDOW_H_FUNCTIONS
# include <winstl/window/functions.h>
#endif /* !WINSTL_INCL_WINSTL_WINDOW_H_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_WINDOW_UTIL_HPP_IDENT_
# include <winstl/window/util/ident_.hpp>
#endif /* !WINSTL_INCL_WINSTL_WINDOW_UTIL_HPP_IDENT_ */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER
# include <stlsoft/string/cstring_maker.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER */

#ifndef WINSTL_INCL_WINSTL_API_external_h_WindowsAndMessages
# include <winstl/api/external/WindowsAndMessages.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_WindowsAndMessages */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifdef NOUSER
# error This file cannot be used when NOUSER is specified (to suppress the Windows User API)
#endif /* NOUSER */
#ifdef NOWINOFFSETS
# error This file cannot be used when NOWINOFFSETS is specified (to suppress GWL_*, GCL_*, associated routines)
#endif /* NOWINOFFSETS */


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
 * functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
ws_size_t
GetWindowTextLength_T_(
    HWND            hwnd
,   int (WINAPI*    pfn)(HWND )
)
{
    using namespace ximpl_winstl_window_ident;

    WINSTL_ASSERT(NULL != pfn);

    WindowIdent const   ident       =   GetWindowIdent(hwnd);
    int                 sel;
# ifndef NOWINSTYLES
    long const          lbsStyle    =   LBS_MULTIPLESEL | LBS_EXTENDEDSEL;
# else /* ? NOWINSTYLES */
    long const          lbsStyle    =   0x0008L | 0x0800L;
# endif /* NOWINSTYLES */

    switch (ident)
    {
        case    WindowIdent_ListBox:
            if (0 == (GetStyle(hwnd) & lbsStyle))
            {
                sel = static_cast<int>(WINSTL_API_EXTERNAL_WindowsAndMessages_SendMessage(hwnd, LB_GETCURSEL, 0, 0l));

                if (LB_ERR != sel)
                {
                    return static_cast<ws_size_t>(WINSTL_API_EXTERNAL_WindowsAndMessages_SendMessage(hwnd, LB_GETTEXTLEN, static_cast<WPARAM>(sel), 0L));
                }
                else
                {
                    return 0;
                }
            }
            break;
#if 0
        case    WindowIdent_ListBox:
            if (1 == SendMessage(hwnd, LVM_GETSELECTEDCOUNT, 0, 0L))
            {
                sel =
            }
            break;
#endif /* 0 */
        case    WindowIdent_Generic:
        case    WindowIdent_ComboBox:
        case    WindowIdent_ListView:
        default:
            break;
    }

    return static_cast<ws_size_t>(pfn(hwnd));
}

inline
ws_size_t
GetWindowTextLength_T_(
    HWND hwnd
)
{
    return GetWindowTextLength_T_(hwnd, ::GetWindowTextLength);
}
inline
ws_size_t
GetWindowTextLength_A_(
    HWND hwnd
)
{
    return GetWindowTextLength_T_(hwnd, ::GetWindowTextLengthA);
}
inline
ws_size_t
GetWindowTextLength_W_(
    HWND hwnd
)
{
    return GetWindowTextLength_T_(hwnd, ::GetWindowTextLengthW);
}

template <ss_typename_param_k C>
struct WindowTextLength_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct WindowTextLength_traits<ws_char_a_t>
{
    static
    ws_size_t
    get_length(
        HWND hwnd
    )
    {
        return GetWindowTextLength_A_(hwnd);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct WindowTextLength_traits<ws_char_w_t>
{
    static
    ws_size_t
    get_length(
        HWND hwnd
    )
    {
        return GetWindowTextLength_W_(hwnd);
    }
};

inline
ws_size_t
GetWindowText_A_(
    HWND            hwnd
,   ws_char_a_t*    buffer
,   ws_size_t       cchBuffer
)
{
    using namespace ximpl_winstl_window_ident;

    WindowIdent const   ident   =   GetWindowIdent(hwnd);
    int                 sel;
    ws_size_t           cch;

    switch (ident)
    {
        case    WindowIdent_ListBox:
            if (0 == (GetStyle(hwnd) & (LBS_MULTIPLESEL | LBS_EXTENDEDSEL)))
            {
                sel = static_cast<int>(WINSTL_API_EXTERNAL_WindowsAndMessages_SendMessage(hwnd, LB_GETCURSEL, 0, 0l));

                if (LB_ERR != sel)
                {
                    cch =   static_cast<ws_size_t>(WINSTL_API_EXTERNAL_WindowsAndMessages_SendMessage(hwnd, LB_GETTEXT, static_cast<WPARAM>(sel), reinterpret_cast<LPARAM>(buffer)));

                    // Some programs using list-boxes do not null-terminate - Visual
                    // SourceSafe Explorer, anyone? - so we must do so here.
                    buffer[cch] = '\0';
                }
                else
                {
                    buffer[0] = '\0';

                    cch = 0;
                }

                WINSTL_MESSAGE_ASSERT("Buffer overwrite", !(cchBuffer < cch));

                return cch;
            }
            break;
        case    WindowIdent_Generic:
        case    WindowIdent_ComboBox:
        case    WindowIdent_ListView:
        default:
            break;
    }

    return static_cast<ws_size_t>(::GetWindowTextA(hwnd, buffer, static_cast<int>(cchBuffer)));
}

inline
ws_size_t
GetWindowText_W_(
    HWND            hwnd
,   ws_char_w_t*    buffer
,   ws_size_t       cchBuffer
)
{
    using namespace ximpl_winstl_window_ident;

    WindowIdent const   ident   =   GetWindowIdent(hwnd);
    int                 sel;

    switch (ident)
    {
        case    WindowIdent_ListBox:
            if (0 == (GetStyle(hwnd) & (LBS_MULTIPLESEL | LBS_EXTENDEDSEL)))
            {
                ws_size_t  cch;

                sel = static_cast<int>(WINSTL_API_EXTERNAL_WindowsAndMessages_SendMessage(hwnd, LB_GETCURSEL, 0, 0l));

                if (LB_ERR != sel)
                {
                    cch =   static_cast<ws_size_t>(WINSTL_API_EXTERNAL_WindowsAndMessages_SendMessage(hwnd, LB_GETTEXT, static_cast<WPARAM>(sel), reinterpret_cast<LPARAM>(buffer)));
                }
                else
                {
                    buffer[0] = '\0';

                    cch = 0;
                }

                WINSTL_MESSAGE_ASSERT("Buffer overwrite", !(cchBuffer < cch));

                return cch;
            }
            break;
        case    WindowIdent_Generic:
        case    WindowIdent_ComboBox:
        case    WindowIdent_ListView:
        default:
            break;
    }

    return static_cast<ws_size_t>(::GetWindowTextW(hwnd, buffer, static_cast<int>(cchBuffer)));
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/* HWND */
/** This class provides an intermediary object that may be returned by the
 * c_str_ptr_null() function, such that the window text of a given window
 * may be accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
template <ss_typename_param_k C>
class c_str_ptr_null_HWND_proxy
{
private: // types
    typedef cstring_maker<C>                                cstring_maker_type_;
    typedef ss_typename_type_k cstring_maker_type_::block   block_type_;
public:
    /// The character type
    typedef C                                               char_type;
    /// This type
    typedef c_str_ptr_null_HWND_proxy<C>                    class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given HWND
    ///
    /// \param hwnd The HWND from which the text will be retrieved
    ss_explicit_k
    c_str_ptr_null_HWND_proxy(
        HWND hwnd
    )
        : m_block(make_block_(hwnd))
    {}

    // Copy constructor
    c_str_ptr_null_HWND_proxy(class_type const& rhs)
        : m_block(cstring_maker_type_::share(rhs.m_block))
    {}

    /// Releases any storage acquired by the proxy
    ~c_str_ptr_null_HWND_proxy() STLSOFT_NOEXCEPT
    {
        cstring_maker_type_::free(m_block);
    }
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

// Accessors
public:
    /// Returns a null-terminated string representing the window contents,
    /// or the empty string "" if the window contains no text.
    operator char_type const* () const
    {
        if (NULL == m_block)
        {
            return NULL;
        }

        return &m_block->data[0];
    }

private: // implementation
    static
    block_type_*
    make_block_(
        HWND hwnd
    )
    {
        ws_size_t const length = WindowTextLength_traits<C>::get_length(hwnd);

        if (0 == length)
        {
            return NULL;
        }
        else
        {
            block_type_* block = cstring_maker_type_::alloc(NULL, length);

            if (NULL != block)
            {
                get_window_text(hwnd, block->data, length + 1);
            }

            return block;
        }
    }

    static
    ws_size_t get_window_text(HWND hwnd, char_type* buffer, ws_size_t cchBuffer);

private: // fields
    block_type_* const m_block;
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
inline
ws_size_t
c_str_ptr_null_HWND_proxy<ws_char_a_t>::get_window_text(
    HWND            hwnd
,   ws_char_a_t*    buffer
,   ws_size_t       cchBuffer
)
{
    return GetWindowText_A_(hwnd, buffer, cchBuffer);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
ws_size_t
c_str_ptr_null_HWND_proxy<ws_char_w_t>::get_window_text(
    HWND            hwnd
,   ws_char_w_t*    buffer
,   ws_size_t       cchBuffer
)
{
    return GetWindowText_W_(hwnd, buffer, cchBuffer);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** This class provides an intermediary object that may be returned by the
 * c_str_ptr() function, such that the window text of a given window may be
 * accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
template <ss_typename_param_k C>
class c_str_ptr_HWND_proxy
{
private: // types
    typedef cstring_maker<C>                                cstring_maker_type_;
    typedef ss_typename_type_k cstring_maker_type_::block   block_type_;
public:
    /// The character type
    typedef C                                               char_type;
    /// This type
    typedef c_str_ptr_HWND_proxy<C>                         class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given HWND
    ///
    /// \param hwnd The HWND from which the text will be retrieved
    ss_explicit_k
    c_str_ptr_HWND_proxy(
        HWND hwnd
    )
        : m_block(make_block_(hwnd))
    {}

    // Copy constructor
    c_str_ptr_HWND_proxy(class_type const& rhs)
        : m_block(cstring_maker_type_::share(rhs.m_block))
    {}

    /// Releases any storage acquired by the proxy
    ~c_str_ptr_HWND_proxy() STLSOFT_NOEXCEPT
    {
        cstring_maker_type_::free(m_block);
    }
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

// Accessors
public:
    /// Returns a null-terminated string representing the window contents,
    /// or the empty string "" if the window contains no text.
    operator char_type const* () const
    {
        return &m_block->data[0];
    }

private: // implementation
    static
    block_type_*
    make_block_(
        HWND hwnd
    )
    {
        ws_size_t const length = WindowTextLength_traits<C>::get_length(hwnd);

        block_type_* const block = cstring_maker_type_::alloc(NULL, length);

        if (NULL != block)
        {
            get_window_text(hwnd, &block->data[0], length + 1);
        }

        return block;
    }

    static
    ws_size_t get_window_text(HWND hwnd, char_type* buffer, ws_size_t cchBuffer);

private: // fields
    block_type_* const m_block;
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
inline
ws_size_t
c_str_ptr_HWND_proxy<ws_char_a_t>::get_window_text(
    HWND            hwnd
,   ws_char_a_t*    buffer
,   ws_size_t       cchBuffer
)
{
    return GetWindowText_A_(hwnd, buffer, cchBuffer);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
ws_size_t
c_str_ptr_HWND_proxy<ws_char_w_t>::get_window_text(
    HWND            hwnd
,   ws_char_w_t*    buffer
,   ws_size_t       cchBuffer
)
{
    return GetWindowText_W_(hwnd, buffer, cchBuffer);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * iostream compatibility
 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k S
        >
inline
S&
operator <<(
    S&                                  s
,   c_str_ptr_null_HWND_proxy<C> const& shim
)
{
    s << static_cast<C const*>(shim);

    return s;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k S
        >
inline
S&
operator <<(
    S&                                  s
,   c_str_ptr_HWND_proxy<C> const&      shim
)
{
    s << static_cast<C const*>(shim);

    return s;
}


/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
c_str_ptr_HWND_proxy<ws_char_a_t>
c_str_data_a(
    HWND hwnd
)
{
    return c_str_ptr_HWND_proxy<ws_char_a_t>(hwnd);
}
inline
c_str_ptr_HWND_proxy<ws_char_w_t>
c_str_data_w(
    HWND hwnd
)
{
    return c_str_ptr_HWND_proxy<ws_char_w_t>(hwnd);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_data for HWND
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
c_str_ptr_HWND_proxy<TCHAR>
c_str_data(
    HWND hwnd
)
{
    return c_str_ptr_HWND_proxy<TCHAR>(hwnd);
}


/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/* HWND */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
ws_size_t
c_str_len_a(
    HWND hwnd
)
{
    return GetWindowTextLength_A_(hwnd);
}
inline
ws_size_t
c_str_len_w(
    HWND hwnd
)
{
    return GetWindowTextLength_W_(hwnd);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for HWND
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
ws_size_t
c_str_len(
    HWND hwnd
)
{
    return GetWindowTextLength_T_(hwnd);
}


/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* HWND */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
c_str_ptr_HWND_proxy<ws_char_a_t>
c_str_ptr_a(
    HWND hwnd
)
{
    return c_str_ptr_HWND_proxy<ws_char_a_t>(hwnd);
}
inline
c_str_ptr_HWND_proxy<ws_char_w_t>
c_str_ptr_w(
    HWND hwnd
)
{
    return c_str_ptr_HWND_proxy<ws_char_w_t>(hwnd);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr for HWND
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
c_str_ptr_HWND_proxy<TCHAR>
c_str_ptr(
    HWND hwnd
)
{
    return c_str_ptr_HWND_proxy<TCHAR>(hwnd);
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or \c nullptr.
 */

/* HWND */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
c_str_ptr_null_HWND_proxy<ws_char_a_t>
c_str_ptr_null_a(
    HWND hwnd
)
{
    return c_str_ptr_null_HWND_proxy<ws_char_a_t>(hwnd);
}
inline
c_str_ptr_null_HWND_proxy<ws_char_w_t>
c_str_ptr_null_w(
    HWND hwnd
)
{
    return c_str_ptr_null_HWND_proxy<ws_char_w_t>(hwnd);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for HWND
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
c_str_ptr_null_HWND_proxy<TCHAR>
c_str_ptr_null(
    HWND hwnd
)
{
    return c_str_ptr_null_HWND_proxy<TCHAR>(hwnd);
}


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
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef WINSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::winstl::c_str_data;
using ::winstl::c_str_data_a;
using ::winstl::c_str_data_w;

using ::winstl::c_str_len;
using ::winstl::c_str_len_a;
using ::winstl::c_str_len_w;

using ::winstl::c_str_ptr;
using ::winstl::c_str_ptr_a;
using ::winstl::c_str_ptr_w;

using ::winstl::c_str_ptr_null;
using ::winstl::c_str_ptr_null_a;
using ::winstl::c_str_ptr_null_w;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_HWND */

/* ///////////////////////////// end of file //////////////////////////// */

