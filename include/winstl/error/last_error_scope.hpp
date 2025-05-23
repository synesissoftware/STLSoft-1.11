/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/error/last_error_scope.hpp (originally MWTErrScp.h, ::SynesisWin)
 *
 * Purpose: Win32 last error scoping class.
 *
 * Created: 27th November 1998
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/error/last_error_scope.hpp
 *
 * \brief [C++] Definition of the winstl::last_error_scope class
 *  template
 *   (\ref group__library__error "Error" Library).
 */

#ifndef WINSTL_INCL_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE
#define WINSTL_INCL_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE_MAJOR       4
# define WINSTL_VER_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE_MINOR       0
# define WINSTL_VER_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE_REVISION    9
# define WINSTL_VER_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE_EDIT        62
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

/** A \ref group__pattern__scoping_class "scoping class" that scopes
 *    the thread's last error.
 *
 * \ingroup group__library__error
 *
\code
  DWORD   err = ::GetLastError();
  { winstl::last_error_scope  scope; // Scope the error while we change it

    // Some code that changes (or may change) the last error
    . . .

    ::SetLastError(ERROR_ACCESS_DENIED); // ... we just do this for pedagogical purposes

  } // End of scope - error value replaced to former value

  assert(::GetLastError() == err);
\endcode
 */
class last_error_scope
{
public: // types
    typedef last_error_scope                                class_type;

public: // construction
    /// Takes a copy of the current thread error, which will be reset
    /// on destruction of this instance
    last_error_scope() STLSOFT_NOEXCEPT
        : m_dwErr(WINSTL_API_EXTERNAL_ErrorHandling_GetLastError())
    {}
    /// Takes a copy of the current thread error, which will be reset
    /// on destruction of this instance. The current thread error is
    /// set to the given value.
    ///
    /// \param dwErr The value to which the current thread error is set
    ss_explicit_k last_error_scope(ws_dword_t dwErr) STLSOFT_NOEXCEPT
        : m_dwErr(WINSTL_API_EXTERNAL_ErrorHandling_GetLastError())
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(dwErr);
    }
    /// Resets the thread error value current at the epoque of
    /// construction of this instance
    ~last_error_scope() STLSOFT_NOEXCEPT
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(m_dwErr);
    }
private:
    last_error_scope(last_error_scope const&);
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

public: // attributes
    /// Returns the value of the recorded thread error, which will be
    /// reset on destruction of this instance
    operator ws_dword_t() const
    {
        return m_dwErr;
    }

private: // fields
    ws_dword_t const m_dwErr;
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

#endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

