/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/window/window_enable_scope.hpp (originally MWWndScp.h; ::SynesisWin)
 *
 * Purpose: Window enable-state scoping class.
 *
 * Created: 5th January 1996
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1996-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/window/window_enable_scope.hpp
 *
 * \brief [C++] Definition of the winstl::window_enable_scope class
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_HPP_WINDOW_ENABLE_SCOPE
#define WINSTL_INCL_WINSTL_WINDOW_HPP_WINDOW_ENABLE_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_HPP_WINDOW_ENABLE_SCOPE_MAJOR    4
# define WINSTL_VER_WINSTL_WINDOW_HPP_WINDOW_ENABLE_SCOPE_MINOR    1
# define WINSTL_VER_WINSTL_WINDOW_HPP_WINDOW_ENABLE_SCOPE_REVISION 8
# define WINSTL_VER_WINSTL_WINDOW_HPP_WINDOW_ENABLE_SCOPE_EDIT     108
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

#ifndef WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND
# include <winstl/shims/attribute/get_HWND.hpp>
#endif /* !WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND */


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

// window_enable_scope
/** Provides scoping of the enable status of a window.
 *
 * \ingroup group__library__Windows_Window
 *
 * This class provides scoping of the enable status of a window via the API
 * function EnableWindow().
 */
class window_enable_scope
{
public:
    /// This type
    typedef window_enable_scope class_type;

// Construction
public:
    /// Toggles the window enable state
    ///
    /// Takes a HWND and changes it's current enable-status, which is set back to
    /// the original state in the destructor.
    ///
    /// \param wnd The window whose enable state is to be controlled
    ss_explicit_k window_enable_scope(HWND wnd)
        : m_hwnd(wnd)
        , m_bEnableOnDtor(::IsWindowEnabled(m_hwnd) != false)
    {
        ::EnableWindow(m_hwnd, !m_bEnableOnDtor);
    }

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    /// Toggles the window enable state
    ///
    /// Takes a HWND and changes it's current enable-status, which is set back to
    /// the original state in the destructor.
    ///
    /// \param wnd The window whose enable state is to be controlled
    template <ss_typename_param_k W>
    ss_explicit_k window_enable_scope(W &wnd)
        : m_hwnd(get_HWND(wnd))
        , m_bEnableOnDtor(::IsWindowEnabled(m_hwnd) != false)
    {
        ::EnableWindow(m_hwnd, !m_bEnableOnDtor);
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

    /// Modifies the window enable state
    ///
    /// \param wnd The window whose enable state is to be controlled
    /// \param bEnableOnCtor The state to set in the constructor
    /// \param bEnableOnDtor The state it is reset to in the destructor
    window_enable_scope(HWND wnd, ws_bool_t bEnableOnCtor, ws_bool_t bEnableOnDtor)
        : m_hwnd(wnd)
        , m_bEnableOnDtor(bEnableOnDtor)
    {
        ::EnableWindow(m_hwnd, bEnableOnCtor);
    }
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    /// Modifies the window enable state
    ///
    /// \param wnd The window whose enable state is to be controlled
    /// \param bEnableOnCtor The state to set in the constructor
    /// \param bEnableOnDtor The state it is reset to in the destructor
    template <ss_typename_param_k W>
    window_enable_scope(W &wnd, ws_bool_t bEnableOnCtor, ws_bool_t bEnableOnDtor)
        : m_hwnd(get_HWND(wnd))
        , m_bEnableOnDtor(bEnableOnDtor)
    {
        ::EnableWindow(m_hwnd, bEnableOnCtor);
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

    /// Resets the enable status
    ~window_enable_scope() STLSOFT_NOEXCEPT
    {
#ifdef STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT
        WINSTL_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(class_type, m_hwnd) < STLSOFT_RAW_OFFSETOF(class_type, m_bEnableOnDtor));
#endif /* STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT */

        ::EnableWindow(m_hwnd, m_bEnableOnDtor);
    }
private:
    window_enable_scope(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

// Members
private:
    HWND        m_hwnd;
    ws_bool_t   m_bEnableOnDtor;
};

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

#endif /* !WINSTL_INCL_WINSTL_WINDOW_HPP_WINDOW_ENABLE_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

