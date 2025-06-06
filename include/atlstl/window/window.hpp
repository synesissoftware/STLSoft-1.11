/* /////////////////////////////////////////////////////////////////////////
 * File:    atlstl/window/window.hpp
 *
 * Purpose: Enhancement of ATL's CWindow, supporting shims for common
 *          operations.
 *
 * Created: 25th November 2006
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
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


/** \file atlstl/window/window.hpp
 * \brief [C++; requires ATL library] Definition of the
 *   atlstl::Window class, which is an enhancement of ATL's CWindow,
 *   supporting shims for common operations
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef ATLSTL_INCL_ATLSTL_WINDOW_HPP_WINDOW
#define ATLSTL_INCL_ATLSTL_WINDOW_HPP_WINDOW

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ATLSTL_VER_ATLSTL_WINDOW_HPP_WINDOW_MAJOR      1
# define ATLSTL_VER_ATLSTL_WINDOW_HPP_WINDOW_MINOR      0
# define ATLSTL_VER_ATLSTL_WINDOW_HPP_WINDOW_REVISION   11
# define ATLSTL_VER_ATLSTL_WINDOW_HPP_WINDOW_EDIT       26
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef ATLSTL_INCL_ATLSTL_HPP_ATLSTL
# include <atlstl/atlstl.hpp>
#endif /* !ATLSTL_INCL_ATLSTL_HPP_ATLSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef ATLSTL_INCL_ATLSTL_WINDOW_HPP_ENHANCED_WINDOW
# include <atlstl/window/enhanced_window.hpp>
#endif /* !ATLSTL_INCL_ATLSTL_WINDOW_HPP_ENHANCED_WINDOW */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

#ifndef STRICT
# error ATL window components are not compatible with non-STRICT configuration
#endif

#ifndef STLSOFT_INCL_SYS_H_ATLWIN
# define STLSOFT_INCL_SYS_H_ATLWIN
# include <atlwin.h>
#endif /* !STLSOFT_INCL_SYS_H_ATLWIN */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef ATLSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::atlstl */
namespace atlstl
{
# else
/* Define stlsoft::atlstl_project */
namespace stlsoft
{
namespace atlstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ATLSTL_NO_NAMESPACE */

using ::ATL::CWindow;


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** This class inherits from ATL's CWindow, and provides enhanced
 *    string operations (using string access shims) and additional
 *    functionality (via the EnhancedWindow mixin class template).
 *
 * \ingroup group__library__Windows_Window
 */
// [[synesis:class:ui-window: atlstl::Window]]
class Window
    : public CWindow
    , public EnhancedWindow<Window>
{
/// \name Member Types
/// @{
public:
    typedef CWindow         parent_class_type;
    typedef Window          class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance of Window
    ss_explicit_k
    Window(HWND hwnd = NULL)
        : parent_class_type(hwnd)
    {}
private:
    Window(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

public:
    /// Assigns a window handle to the instance
    class_type& operator =(HWND hwnd)
    {
        parent_class_type::operator =(hwnd);

        return *this;
    }

    /// Creates a window.
    template<   ss_typename_param_k S0
            ,   ss_typename_param_k S1
            >
    HWND Create(S0 const&   lpstrWndClass
            ,   HWND        hWndParent
            ,   RECT        &rcPos
            ,   S1 const    &szWindowName   =   NULL
            ,   DWORD       dwStyle         =   0
            ,   DWORD       dwExStyle       =   0
            ,   UINT        nID             =   0
            ,   LPVOID      lpCreateParam   =   NULL)
    {
        return parent_class_type::Create(stlsoft::c_str_ptr(lpstrWndClass), hWndParent, rcPos, stlsoft::c_str_ptr(szWindowName), dwStyle, dwExStyle, nID, lpCreateParam);
    }

    /// Creates a window.
    template<   ss_typename_param_k S0
            ,   ss_typename_param_k S1
            >
    HWND Create(S0 const&   lpstrWndClass
            ,   HWND        hWndParent
            ,   LPRECT      lpRect          =   NULL
            ,   S1 const&   szWindowName   =   NULL
            ,   DWORD       dwStyle         =   0
            ,   DWORD       dwExStyle       =   0
            ,   HMENU       hMenu           =   NULL
            ,   LPVOID      lpCreateParam   =   NULL)
    {
        return parent_class_type::Create(stlsoft::c_str_ptr(lpstrWndClass), hWndParent, lpRect, stlsoft::c_str_ptr(szWindowName), dwStyle, dwExStyle, nID, lpCreateParam);
    }
/// @}

/// \name Operations
/// @{
public:

    // Window Text Functions

    /// Invokes <code>CWindow::SetWindowText()</code> for an arbitrary string type.
    template <ss_typename_param_k S>
    BOOL SetWindowText(S const& lpszString)
    {
        return parent_class_type::SetWindowText(stlsoft::c_str_ptr(lpszString));
    }


    // Dialog Functions

    template <ss_typename_param_k S>
    BOOL SetDlgItemText(int nID, S const& lpszString)
    {
        return parent_class_type::SetDlgItemText(nID, stlsoft::c_str_ptr(lpszString));
    }


    // Alert Functions

    template <ss_typename_param_k S>
    int MessageBox(S const& lpszText)
    {
        return parent_class_type::MessageBox(stlsoft::c_str_ptr(lpszText));
    }
    template<   ss_typename_param_k S0
            ,   ss_typename_param_k S1
            >
    int MessageBox(S0 const& lpszText, S1 const& lpszCaption)
    {
        return parent_class_type::MessageBox(stlsoft::c_str_ptr(lpszText), stlsoft::c_str_ptr(lpszCaption));
    }

    template<   ss_typename_param_k S0
            ,   ss_typename_param_k S1
            >
    int MessageBox(S0 const& lpszText, S1 const& lpszCaption, UINT nType)
    {
        return parent_class_type::MessageBox(stlsoft::c_str_ptr(lpszText), stlsoft::c_str_ptr(lpszCaption), nType);
    }

    // Help Functions

    template <ss_typename_param_k S>
    BOOL WinHelp(S const& lpszHelp, UINT nCmd = HELP_CONTEXT, DWORD dwData = 0)
    {
        return parent_class_type::WinHelp(stlsoft::c_str_ptr(lpszHelp), nCmd, dwData);
    }
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef ATLSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace atlstl
# else
} // namespace atlstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ATLSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !ATLSTL_INCL_ATLSTL_WINDOW_HPP_WINDOW */

/* ///////////////////////////// end of file //////////////////////////// */

