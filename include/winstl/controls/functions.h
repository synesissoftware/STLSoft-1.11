/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/controls/functions.h
 *
 * Purpose: Various Windows control functions.
 *
 * Created: 13th November 2002
 * Updated: 26th December 2024
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/controls/functions.h
 *
 * \brief [C, C++] Various Windows control functions
 *   (\ref group__library__Windows_Control "Windows Control" Library).
 */

#ifndef WINSTL_INCL_WINSTL_CONTROLS_H_FUNCTIONS
#define WINSTL_INCL_WINSTL_CONTROLS_H_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CONTROLS_H_FUNCTIONS_MAJOR       4
# define WINSTL_VER_WINSTL_CONTROLS_H_FUNCTIONS_MINOR       2
# define WINSTL_VER_WINSTL_CONTROLS_H_FUNCTIONS_REVISION    8
# define WINSTL_VER_WINSTL_CONTROLS_H_FUNCTIONS_EDIT        66
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

#ifndef WINSTL_INCL_WINSTL_WINDOW_H_MESSAGE_FUNCTIONS
# include <winstl/window/message_functions.h>
#endif /* !WINSTL_INCL_WINSTL_WINDOW_H_MESSAGE_FUNCTIONS */
#ifdef __cplusplus
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
#  include <stlsoft/shims/access/string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
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
 * C functions
 */

/** Adds an ANSI string to a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_addstring_a(
    HWND                hwnd
,   ws_char_a_t const*  s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageA(hwnd, CB_ADDSTRING, 0, stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Adds a Unicode string to a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_addstring_w(
    HWND                hwnd
,   ws_char_w_t const*  s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageW(hwnd, CB_ADDSTRING, 0, stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Adds a string (in the ambient char-encoding) to a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_addstring(
    HWND    hwnd
,   LPCTSTR s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, CB_ADDSTRING, 0, stlsoft_reinterpret_cast(LPARAM, s)));
}

/** Inserts an ANSI string into a combo-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_insertstring_a(
    HWND                hwnd
,   ws_char_a_t const*  s
,   int                 index
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageA(hwnd, CB_INSERTSTRING, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Inserts a Unicode string into a combo-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_insertstring_w(
    HWND                hwnd
,   ws_char_w_t const*  s
,   int                 index
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageW(hwnd, CB_INSERTSTRING, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Inserts a string (in the ambient char-encoding) into a combo-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_insertstring(
    HWND    hwnd
,   LPCTSTR s
,   int     index
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, CB_INSERTSTRING, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}

/** Gets the text length of an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_gettextlen(
    HWND        hwnd
,   ws_int_t    index
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, CB_GETLBTEXTLEN, stlsoft_static_cast(WPARAM, index), 0L));
}

/** Gets the text (in ANSI encoding) of an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_gettext_a(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_a_t*    s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageA(hwnd, CB_GETLBTEXT, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Gets the text (in Unicode encoding) of an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_gettext_w(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_w_t*    s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageW(hwnd, CB_GETLBTEXT, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Gets the text (in the ambient char-encoding) of an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_gettext(
    HWND        hwnd
,   ws_int_t    index
,   LPCSTR      s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, CB_GETLBTEXT, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}

/** Gets the data value associated with an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_dword_t
winstl__combobox_getitemdata(
    HWND        hwnd
,   ws_int_t    index
)
{
    return stlsoft_static_cast(ws_dword_t, winstl__SendMessage(hwnd, CB_GETITEMDATA, stlsoft_static_cast(WPARAM, index), 0L));
}

/** Gets the number of items in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__combobox_getcount(HWND hwnd)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, CB_GETCOUNT, 0, 0L));
}


/* LISTBOX functions
 */

/** Adds an ANSI string to a list-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_addstring_a(
    HWND                hwnd
,   ws_char_a_t const*  s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageA(hwnd, LB_ADDSTRING, 0, stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Adds a Unicode string to a list-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_addstring_w(
    HWND                hwnd
,   ws_char_w_t const*  s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageW(hwnd, LB_ADDSTRING, 0, stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Adds a string (in the ambient char-encoding) to a list-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_addstring(
    HWND    hwnd
,   LPCTSTR s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, LB_ADDSTRING, 0, stlsoft_reinterpret_cast(LPARAM, s)));
}

/** Inserts an ANSI string into a list-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_insertstring_a(
    HWND                hwnd
,   ws_char_a_t const*  s
,   int                 index
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageA(hwnd, LB_INSERTSTRING, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Inserts a Unicode string into a list-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_insertstring_w(
    HWND                hwnd
,   ws_char_w_t const*  s
,   int                 index
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageW(hwnd, LB_INSERTSTRING, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Inserts a string (in the ambient char-encoding) into a list-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_insertstring(
    HWND    hwnd
,   LPCTSTR s
,   int     index
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, LB_INSERTSTRING, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}

/** Gets the text length of an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_gettextlen(
    HWND        hwnd
,   ws_int_t    index
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, LB_GETTEXTLEN, stlsoft_static_cast(WPARAM, index), 0L));
}

/** Gets the text (in ANSI encoding) of an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_gettext_a(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_a_t*    s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageA(hwnd, LB_GETTEXT, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Gets the text (in Unicode encoding) of an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_gettext_w(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_w_t*    s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessageW(hwnd, LB_GETTEXT, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}
/** Gets the text (in the ambient char-encoding) of an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_gettext(
    HWND        hwnd
,   ws_int_t    index
,   LPCSTR      s
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, LB_GETTEXT, stlsoft_static_cast(WPARAM, index), stlsoft_reinterpret_cast(LPARAM, s)));
}

/** Gets the data value associated with an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_dword_t
winstl__listbox_getitemdata(
    HWND        hwnd
,   ws_int_t    index
)
{
    return stlsoft_static_cast(ws_dword_t, winstl__SendMessage(hwnd, LB_GETITEMDATA, stlsoft_static_cast(WPARAM, index), 0L));
}

/** Gets the number of items in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__listbox_getcount(HWND hwnd)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, LB_GETCOUNT, 0, 0L));
}

/** Gets the number of lines in an edit-box
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__edit_getcount(HWND hwnd)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, EM_GETLINECOUNT, 0, 0L));
}

/** Gets the length of the line in which the given character resides.
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__edit_linelength(
    HWND        hwnd
,   ws_int_t    charIndex
)
{
    return stlsoft_static_cast(ws_int_t, winstl__SendMessage(hwnd, EM_LINELENGTH, stlsoft_static_cast(WPARAM, charIndex), 0L));
}

/** Gets a copy of the text of the given line.
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__edit_getline_a(
    HWND            hwnd
,   ws_int_t        lineIndex
,   ws_char_a_t*    buffer
,   ws_size_t       cchBuffer
)
{
    WINSTL_ASSERT(NULL != buffer);

    *stlsoft_reinterpret_cast(int*, buffer) = stlsoft_static_cast(int, cchBuffer);

    return stlsoft_static_cast(ws_int_t, winstl__SendMessageA(hwnd, EM_GETLINE, stlsoft_static_cast(WPARAM, lineIndex), stlsoft_reinterpret_cast(LPARAM, buffer)));
}

/** Gets a copy of the text of the given line.
 *
 * \ingroup group__library__Windows_Control
 */
STLSOFT_INLINE
ws_int_t
winstl__edit_getline_w(
    HWND            hwnd
,   ws_int_t        lineIndex
,   ws_char_w_t*    buffer
,   ws_size_t       cchBuffer
)
{
    WINSTL_ASSERT(NULL != buffer);

    *stlsoft_reinterpret_cast(int*, buffer) = stlsoft_static_cast(int, cchBuffer);

    return stlsoft_static_cast(ws_int_t, winstl__SendMessageW(hwnd, EM_GETLINE, stlsoft_static_cast(WPARAM, lineIndex), stlsoft_reinterpret_cast(LPARAM, buffer)));
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/* COMBOBOX functions
 */

/** Adds an ANSI string to a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_addstring_a(
    HWND                hwnd
,   ws_char_a_t const*  s
)
{
    return winstl__combobox_addstring_a(hwnd, s);
}

/** Adds a Unicode string to a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_addstring_w(
    HWND                hwnd
,   ws_char_w_t const*  s
)
{
    return winstl__combobox_addstring_w(hwnd, s);
}

/** Adds a string to a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_addstring(
    HWND                hwnd
,   ws_char_a_t const*  s
)
{
    return winstl__combobox_addstring_a(hwnd, s);
}
/** Adds a string to a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_addstring(
    HWND                hwnd
,   ws_char_w_t const*  s
)
{
    return winstl__combobox_addstring_w(hwnd, s);
}
/** Adds a string to a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
template <ss_typename_param_k S>
inline
ws_int_t
combobox_addstring(
    HWND        hwnd
,   S const&    s
)
{
    return combobox_addstring(hwnd, STLSOFT_NS_QUAL(c_str_ptr)(s));
}

/** Inserts an ANSI string into a combo-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_insertstring_a(
    HWND                hwnd
,   ws_char_a_t const*  s
,   int                 index
)
{
    return winstl__combobox_insertstring_a(hwnd, s, index);
}

/** Inserts a Unicode string into a combo-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_insertstring_w(
    HWND                hwnd
,   ws_char_w_t const*  s
,   int                 index
)
{
    return winstl__combobox_insertstring_w(hwnd, s, index);
}

/** Inserts a string into a combo-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_insertstring(
    HWND                hwnd
,   ws_char_a_t const*  s
,   int                 index
)
{
    return winstl__combobox_insertstring_a(hwnd, s, index);
}
/** Inserts a string into a combo-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_insertstring(
    HWND                hwnd
,   ws_char_w_t const*  s
,   int                 index
)
{
    return winstl__combobox_insertstring_w(hwnd, s, index);
}
/** Inserts a string into a combo-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
template <ss_typename_param_k S>
inline
ws_int_t
combobox_insertstring(
    HWND        hwnd
,   S const&    s
,   int         index
)
{
    return combobox_insertstring_a(hwnd, STLSOFT_NS_QUAL(c_str_ptr)(s), index);
}

/** Gets the text length of an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_gettextlen(
    HWND        hwnd
,   ws_int_t    index
)
{
    return winstl__combobox_gettextlen(hwnd, index);
}

/** Gets the text (in ANSI encoding) of an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_gettext_a(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_a_t*    s
)
{
    return winstl__combobox_gettext_a(hwnd, index, s);
}
/** Gets the text (in Unicode encoding) of an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_gettext_w(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_w_t*    s
)
{
    return winstl__combobox_gettext_w(hwnd, index, s);
}
/** Gets the text of an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_gettext(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_a_t*    s
)
{
    return combobox_gettext_a(hwnd, index, s);
}
/** Gets the text (in Unicode encoding) of an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_gettext(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_w_t*    s
)
{
    return combobox_gettext_w(hwnd, index, s);
}

/** Gets the data value associated with an item in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_dword_t
combobox_getitemdata(
    HWND        hwnd
,   ws_int_t    index
)
{
    return winstl__combobox_getitemdata(hwnd, index);
}

/** Gets the number of items in a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
combobox_getcount(HWND hwnd)
{
    return winstl__combobox_getcount(hwnd);
}


/* LISTBOX functions
 */

/** Adds an ANSI string to a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_addstring_a(
    HWND                hwnd
,   ws_char_a_t const*  s
)
{
    return winstl__listbox_addstring_a(hwnd, s);
}

/** Adds a Unicode string to a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_addstring_w(
    HWND                hwnd
,   ws_char_w_t const*  s
)
{
    return winstl__listbox_addstring_w(hwnd, s);
}

/** Adds a string to a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_addstring(
    HWND                hwnd
,   ws_char_a_t const*  s
)
{
    return winstl__listbox_addstring_a(hwnd, s);
}
/** Adds a string to a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_addstring(
    HWND                hwnd
,   ws_char_w_t const*  s
)
{
    return winstl__listbox_addstring_w(hwnd, s);
}
/** Adds a string to a list-box
 *
 * \ingroup group__library__Windows_Control
 */
template <ss_typename_param_k S>
inline
ws_int_t
listbox_addstring(
    HWND        hwnd
,   S const&    s
)
{
    return listbox_addstring(hwnd, STLSOFT_NS_QUAL(c_str_ptr)(s));
}

/** Inserts an ANSI string into a list-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_insertstring_a(
    HWND                hwnd
,   ws_char_a_t const*  s
,   int                 index
)
{
    return winstl__listbox_insertstring_a(hwnd, s, index);
}

/** Inserts a Unicode string into a list-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_insertstring_w(
    HWND                hwnd
,   ws_char_w_t const*  s
,   int                 index
)
{
    return winstl__listbox_insertstring_w(hwnd, s, index);
}

/** Inserts a string into a list-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_insertstring(
    HWND                hwnd
,   ws_char_a_t const*  s
,   int                 index
)
{
    return winstl__listbox_insertstring_a(hwnd, s, index);
}
/** Inserts a string into a list-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_insertstring(
    HWND                hwnd
,   ws_char_w_t const*  s
,   int                 index
)
{
    return winstl__listbox_insertstring_w(hwnd, s, index);
}
/** Inserts a string into a list-box at the given index
 *
 * \ingroup group__library__Windows_Control
 */
template <ss_typename_param_k S>
inline
ws_int_t
listbox_insertstring(
    HWND        hwnd
,   S const&    s
,   int         index
)
{
    return listbox_insertstring_a(hwnd, STLSOFT_NS_QUAL(c_str_ptr)(s), index);
}

/** Gets the text length of an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_gettextlen(
    HWND        hwnd
,   ws_int_t    index
)
{
    return winstl__listbox_gettextlen(hwnd, index);
}

/** Gets the text (in ANSI encoding) of an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_gettext_a(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_a_t*    s
)
{
    return winstl__listbox_gettext_a(hwnd, index, s);
}
/** Gets the text (in Unicode encoding) of an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_gettext_w(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_w_t*    s
)
{
    return winstl__listbox_gettext_w(hwnd, index, s);
}
/** Gets the text of an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_gettext(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_a_t*    s
)
{
    return listbox_gettext_a(hwnd, index, s);
}
/** Gets the text (in Unicode encoding) of an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_gettext(
    HWND            hwnd
,   ws_int_t        index
,   ws_char_w_t*    s
)
{
    return listbox_gettext_w(hwnd, index, s);
}

/** Gets the data value associated with an item in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_dword_t
listbox_getitemdata(
    HWND        hwnd
,   ws_int_t    index
)
{
    return winstl__listbox_getitemdata(hwnd, index);
}

/** Gets the number of items in a list-box
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
listbox_getcount(HWND hwnd)
{
    return winstl__listbox_getcount(hwnd);
}


/** Gets the number of lines in an edit-box.
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
edit_getcount(HWND hwnd)
{
    return winstl__edit_getcount(hwnd);
}

/** Gets the length of the line in which the given character resides.
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
edit_linelength(
    HWND        hwnd
,   ws_int_t    charIndex
)
{
    return winstl__edit_linelength(hwnd, charIndex);
}

/** Gets a copy of the text of the given line.
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
edit_getline(
    HWND            hwnd
,   ws_int_t        lineIndex
,   ws_char_a_t*    buffer
,   ws_size_t       cchBuffer
)
{
    return winstl__edit_getline_a(hwnd, lineIndex, buffer, cchBuffer);
}

/** Gets a copy of the text of the given line.
 *
 * \ingroup group__library__Windows_Control
 */
inline
ws_int_t
edit_getline(
    HWND            hwnd
,   ws_int_t        lineIndex
,   ws_char_w_t*    buffer
,   ws_size_t       cchBuffer
)
{
    return winstl__edit_getline_w(hwnd, lineIndex, buffer, cchBuffer);
}
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_CONTROLS_H_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

