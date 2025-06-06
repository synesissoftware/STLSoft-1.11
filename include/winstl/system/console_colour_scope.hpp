/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/system/console_colour_scope.hpp
 *
 * Purpose: Scopes the console colour (and intensity).
 *
 * Created: 20th July 2006
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/system/console_colour_scope.hpp
 *
 * \brief [C++] Definition of the winstl::console_colour_scope class
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_CONSOLE_COLOUR_SCOPE
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_CONSOLE_COLOUR_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_CONSOLE_COLOUR_SCOPE_MAJOR    1
# define WINSTL_VER_WINSTL_SYSTEM_HPP_CONSOLE_COLOUR_SCOPE_MINOR    0
# define WINSTL_VER_WINSTL_SYSTEM_HPP_CONSOLE_COLOUR_SCOPE_REVISION 16
# define WINSTL_VER_WINSTL_SYSTEM_HPP_CONSOLE_COLOUR_SCOPE_EDIT     31
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

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
#  include <winstl/exception/winstl_exception.hpp>
# endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef WINSTL_INCL_WINSTL_API_external_h_Console
# include <winstl/api/external/Console.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Console */
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

/** Provides scoping of the colour (and intensity) of the console
 *
 * \ingroup group__library__Windows_Window
 *
 * This class provides scoping of the colour (and intensity) of the console
 * via the API functions <code>GetConsoleScreenBufferInfo()</code> and
 * <code>SetConsoleTextAttribute()</code>.
 */
class console_colour_scope
{
public:
    /// This type
    typedef console_colour_scope class_type;

// Construction
public:
    /// Sets the console text attribute(s), remembering the current
    ///   state so it can be reset in the destructor.
    ///
    /// The constructor applies the given text attributes to the given
    /// console screen buffer, after first recording the current state so
    /// that they can be reset when the instance is destroyed.
    ///
    /// \exception winstl::winstl_exception If \ref page__exception_agnostic "exception handling is enabled",
    ///   an instance of \link winstl::winstl_exception winstl_exception\endlink
    ///   will be thrown if the console text attributes cannot be elicited
    ///   or changed. If \ref page__exception_agnostic "exception handling is not enabled",
    ///   the console attributes are left as they are, and the destructor
    ///   makes no attempt at modification.
    ///
    /// \param hBuffer Handle the console screen buffer.
    /// \param textAttributes The text attributes to be applied to the console
    ss_explicit_k console_colour_scope(HANDLE hBuffer, WORD textAttributes)
        : m_hBuffer(hBuffer)
        , m_attributes(init_(hBuffer, textAttributes))
    {}

    /// Resets the console text attribute(s) to the original form.
    ~console_colour_scope() STLSOFT_NOEXCEPT
    {
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        if (0xffffffff != m_attributes)
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            WINSTL_API_EXTERNAL_Console_SetConsoleTextAttribute(m_hBuffer, static_cast<WORD>(m_attributes));
        }
    }
private:
    console_colour_scope(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

/// \name Implementation
/// @{
private:
    static ws_uint32_t init_(HANDLE hBuffer, WORD textAttributes)
    {
        ws_uint32_t                 attr = 0xffffffff;
        CONSOLE_SCREEN_BUFFER_INFO  bufferInfo;

        if (!WINSTL_API_EXTERNAL_Console_GetConsoleScreenBufferInfo(hBuffer, &bufferInfo))
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(winstl_exception("Could not retrieve console buffer information", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
        else
        {
            if (!WINSTL_API_EXTERNAL_Console_SetConsoleTextAttribute(hBuffer, textAttributes))
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                STLSOFT_THROW_X(winstl_exception("Could not set console text attributes", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                attr = bufferInfo.wAttributes;
            }
        }

        return attr;
    }
/// @}

/// \name Members
/// @{
private:
    HANDLE      m_hBuffer;
    ws_uint32_t m_attributes;
/// @}
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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_CONSOLE_COLOUR_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

