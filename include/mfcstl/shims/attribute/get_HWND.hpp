/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/shims/attribute/get_HWND.hpp
 *
 * Purpose:     Contains access shims for windows.
 *
 * Created:     10th January 2003
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


/** \file mfcstl/shims/attribute/get_HWND.hpp
 *
 * \brief [C++] Definition of stlsoft::get_HWND attribute shim
 *   functions for MFC types
 *   (\ref group__library__Shims_Attribute_Windows_Window "Window Attribute Shims").
 */

#ifndef MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_HWND
#define MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_HWND

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_HWND_MAJOR       4
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_HWND_MINOR       1
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_HWND_REVISION    5
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_HWND_EDIT        58
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
# include <mfcstl/mfcstl.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

# include <afxwin.h>


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::mfcstl */
namespace mfcstl
{
# else
/* Define stlsoft::mfcstl_project */
namespace stlsoft
{
namespace mfcstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * get_HWND
 *
 * This can be applied to an expression, and the return value is the
 * corresponding HWND.
 */

/* HWND */

/** Access the HWND of the given CWnd instance
 *
 * \ingroup group__library__Shims_Attribute_Windows_Window
 *
 * This access <a href = "http://stlsoft.org/white_papers.html#shims">shim</a> retrieves the
 * HWND window handle for the given CWnd instance.
 *
 * \param w A reference to the CWnd instance whose HWND will be retrieved
 * \return The HWND corresponding to the given CWnd instance \c w
 *
 */
inline HWND get_HWND(CWnd const& w)
{
    return w.m_hWnd;
}

/** Access the HWND of the given CWnd instance
 *
 * \ingroup group__library__Shims_Attribute_Windows_Window
 *
 * This access <a href = "http://stlsoft.org/white_papers.html#shims">shim</a> retrieves the
 * HWND window handle for the given CWnd instance.
 *
 * \param w A pointer to the CWnd instance whose HWND will be retrieved
 * \return The HWND corresponding to the given CWnd instance \c w
 *
 */
inline HWND get_HWND(CWnd const* w)
{
    return w->GetSafeHwnd();
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace mfcstl
# else
} // namespace mfcstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#else  /* ? MFCSTL_NO_NAMESPACE */
# if !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
#  if !defined(WINSTL_NO_NAMESPACE)
#   if defined(STLSOFT_NO_NAMESPACE)
namespace winstl
{
    using ::mfcstl::get_HWND;
} // namespace winstl
#   else /* ? STLSOFT_NO_NAMESPACE */
namespace stlsoft
{
namespace winstl_project
{
    using ::mfcstl::get_HWND;
} // namespace winstl_project
} // namespace stlsoft
#   endif /* STLSOFT_NO_NAMESPACE */
#  endif /* !WINSTL_NO_NAMESPACE */
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
#endif /* !MFCSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_HWND */

/* ///////////////////////////// end of file //////////////////////////// */

