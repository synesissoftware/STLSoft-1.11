/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/util/struct_initialisers.hpp
 *
 * Purpose: Functions for initialising Win32 structures.
 *
 * Created: 20th October 1994
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1994-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/util/struct_initialisers.hpp
 *
 * \brief [C++] Definition of the winstl::zero_struct and
 *   winstl::init_struct structure initialiser functions
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef WINSTL_INCL_WINSTL_UTIL_HPP_STRUCT_INITIALISERS
#define WINSTL_INCL_WINSTL_UTIL_HPP_STRUCT_INITIALISERS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_UTIL_HPP_STRUCT_INITIALISERS_MAJOR       4
# define WINSTL_VER_WINSTL_UTIL_HPP_STRUCT_INITIALISERS_MINOR       1
# define WINSTL_VER_WINSTL_UTIL_HPP_STRUCT_INITIALISERS_REVISION    11
# define WINSTL_VER_WINSTL_UTIL_HPP_STRUCT_INITIALISERS_EDIT        242
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_MemoryManagement
# include <winstl/api/external/MemoryManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_MemoryManagement */

#ifndef WINSTL_INCL_WINSTL_API_H_winstl_ntddi_
# include <winstl/api/winstl_ntddi_.h>
#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_ntddi_ */
#ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
# include <winstl/api/winstl_win32_winnt_.h>
#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */


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

/** Initialises all elements of a structure to zero
 *
 * \ingroup group__library__Utility
 */
template <ss_typename_param_k T>
inline
void
zero_struct(T& t)
{
    WINSTL_API_EXTERNAL_MemoryManagement_ZeroMemory(&t, sizeof(T));
}

template <ss_typename_param_k T>
struct struct_initialisation_traits;


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

struct struct_has
{
    struct no_init_member_type
    {};

    struct cb_member_type
    {};

    struct cBytes_member_type
    {};

    struct cbSize_member_type
    {};

    struct dwLength_member_type
    {};

    struct dwOSVersionInfoSize_member_type
    {};

    struct dwSize_member_type
    {};

    struct nLength_member_type
    {};

    struct uSize_member_type
    {};


    template <ss_typename_param_k T>
    static void init(T& t, no_init_member_type)
    {
        zero_struct(t);
    }

    template <ss_typename_param_k T>
    static void init(T& t, cb_member_type)
    {
        zero_struct(t);
        t.cb        =   sizeof(T);
    }

    template <ss_typename_param_k T>
    static void init(T& t, cBytes_member_type)
    {
        zero_struct(t);
        t.cBytes    =   sizeof(T);
    }

    template <ss_typename_param_k T>
    static void init(T& t, cbSize_member_type)
    {
        zero_struct(t);
        t.cbSize    =   sizeof(T);
    }

    template <ss_typename_param_k T>
    static void init(T& t, dwLength_member_type)
    {
        zero_struct(t);
        t.dwLength  =   sizeof(T);
    }

    template <ss_typename_param_k T>
    static void init(T& t, dwOSVersionInfoSize_member_type)
    {
        zero_struct(t);
        t.dwOSVersionInfoSize   =   sizeof(T);
    }

    template <ss_typename_param_k T>
    static void init(T& t, dwSize_member_type)
    {
        zero_struct(t);
        t.dwSize    =   sizeof(T);
    }

    template <ss_typename_param_k T>
    static void init(T& t, nLength_member_type)
    {
        zero_struct(t);
        t.nLength   =   sizeof(T);
    }

    template <ss_typename_param_k T>
    static void init(T& t, uSize_member_type)
    {
        zero_struct(t);
        t.uSize    =   sizeof(T);
    }
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** Initialises all members of a structure to zero, and
 *    sets the size member to the size of the structure.
 *
 * \ingroup group__library__Utility
 */
template <ss_typename_param_k T>
inline
void
init_struct(T& t)
{
    typedef ss_typename_type_k struct_initialisation_traits<
        T
    >::type                                                 discriminator_t;

    struct_has::init(t, discriminator_t());
}

// Specialisations

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# define WINSTL_THE_INITIALISABLE_STRUCTURE_(S, t)  \
                                                    \
    STLSOFT_TEMPLATE_SPECIALISATION                 \
    struct struct_initialisation_traits<S>          \
    {                                               \
        typedef struct_##t  type;                   \
    }

// WinBase.h:

WINSTL_THE_INITIALISABLE_STRUCTURE_(PROCESS_INFORMATION, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(OVERLAPPED, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(FILETIME, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(SYSTEMTIME, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(COMMPROP, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(COMSTAT, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(COMMTIMEOUTS, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(SYSTEM_INFO, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(EXCEPTION_DEBUG_INFO, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(CREATE_THREAD_DEBUG_INFO, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(CREATE_PROCESS_DEBUG_INFO, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(EXIT_THREAD_DEBUG_INFO, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(LOAD_DLL_DEBUG_INFO, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(UNLOAD_DLL_DEBUG_INFO, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(OUTPUT_DEBUG_STRING_INFO, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(RIP_INFO, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(DEBUG_EVENT, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(PROCESS_HEAP_ENTRY, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(BY_HANDLE_FILE_INFORMATION, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(TIME_ZONE_INFORMATION, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(WIN32_STREAM_ID, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(WIN32_FIND_DATAA, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(WIN32_FIND_DATAW, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(WIN32_FILE_ATTRIBUTE_DATA, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(SYSTEM_POWER_STATUS, has::no_init_member_type);
#ifdef _WINCON_
WINSTL_THE_INITIALISABLE_STRUCTURE_(CONSOLE_SCREEN_BUFFER_INFO, has::no_init_member_type);
# if !defined(_MSC_VER) ||\
     _MSC_VER >= 1600
WINSTL_THE_INITIALISABLE_STRUCTURE_(CONSOLE_SCREEN_BUFFER_INFOEX, has::cbSize_member_type);
# endif /* VC++ 10+ */
#endif /* _WINCON_ */
#ifdef WINTRUST_H
WINSTL_THE_INITIALISABLE_STRUCTURE_(WIN_CERTIFICATE, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(WIN_TRUST_ACTDATA_SUBJECT_ONLY, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(WIN_TRUST_SUBJECT_FILE, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(WIN_TRUST_SUBJECT_FILE_AND_DISPLAY, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(WIN_SPUB_TRUSTED_PUBLISHER_DATA, has::no_init_member_type);
#endif /* WINTRUST_H */


WINSTL_THE_INITIALISABLE_STRUCTURE_(STARTUPINFOA, has::cb_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(STARTUPINFOW, has::cb_member_type);

WINSTL_THE_INITIALISABLE_STRUCTURE_(OFSTRUCT, has::cBytes_member_type);

WINSTL_THE_INITIALISABLE_STRUCTURE_(MEMORYSTATUS, has::dwLength_member_type);

WINSTL_THE_INITIALISABLE_STRUCTURE_(OSVERSIONINFOA, has::dwOSVersionInfoSize_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(OSVERSIONINFOW, has::dwOSVersionInfoSize_member_type);
#if !defined(STLSOFT_COMPILER_IS_DMC) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1200)
WINSTL_THE_INITIALISABLE_STRUCTURE_(OSVERSIONINFOEXA, has::dwOSVersionInfoSize_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(OSVERSIONINFOEXW, has::dwOSVersionInfoSize_member_type);
#endif /* compiler */

WINSTL_THE_INITIALISABLE_STRUCTURE_(COMMCONFIG, has::dwSize_member_type);

WINSTL_THE_INITIALISABLE_STRUCTURE_(SECURITY_ATTRIBUTES, has::nLength_member_type);

inline
void
init_struct(DCB& dcb)
{
    zero_struct(dcb);

    dcb.DCBlength = sizeof(dcb);
}

// ShellApi.h

# if 1 &&\
     defined(_INC_SHELLAPI) ||\
     defined(_SHELLAPI_H) ||\
     !defined(WIN32_LEAN_AND_MEAN) &&\
     1

WINSTL_THE_INITIALISABLE_STRUCTURE_(SHFILEOPSTRUCTA, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(SHFILEOPSTRUCTW, has::no_init_member_type);
#  if !defined(STLSOFT_COMPILER_IS_GCC)
WINSTL_THE_INITIALISABLE_STRUCTURE_(SHNAMEMAPPINGA, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(SHNAMEMAPPINGW, has::no_init_member_type);
#  endif /* compiler */
WINSTL_THE_INITIALISABLE_STRUCTURE_(SHFILEINFOA, has::no_init_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(SHFILEINFOW, has::no_init_member_type);


#  if 1 &&\
      defined(WINVER) &&\
      WINVER >= 0x0400 &&\
      1

#   if 1 &&\
       !defined(STLSOFT_COMPILER_IS_DMC) &&\
       (   !defined(STLSOFT_COMPILER_IS_GCC) ||\
           __GNUC__ >= 14) &&\
       (   !defined(STLSOFT_COMPILER_IS_MSVC) ||\
           _MSC_VER >= 1200) &&\
       1

WINSTL_THE_INITIALISABLE_STRUCTURE_(DRAGINFOA, has::uSize_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(DRAGINFOW, has::uSize_member_type);
#   endif /* compiler */
#  endif /* WINVER */

WINSTL_THE_INITIALISABLE_STRUCTURE_(APPBARDATA, has::cbSize_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(SHELLEXECUTEINFOA, has::cbSize_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(SHELLEXECUTEINFOW, has::cbSize_member_type);
#  if 1 && \
      !defined(STLSOFT_COMPILER_IS_DMC) && \
      (   !defined(STLSOFT_COMPILER_IS_GCC) || \
          __GNUC__ > 3 || \
          (   __GNUC__ == 3 && \
              __GNUC_MINOR__ > 2)) && \
      (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
          _MSC_VER == 1200 || \
          WINSTL_NTDDI_VERSION >= WINSTL_NTDDI_WIN2K) && \
      1

WINSTL_THE_INITIALISABLE_STRUCTURE_(SHQUERYRBINFO, has::cbSize_member_type);
#  endif /* compiler */
WINSTL_THE_INITIALISABLE_STRUCTURE_(NOTIFYICONDATAA, has::cbSize_member_type);
WINSTL_THE_INITIALISABLE_STRUCTURE_(NOTIFYICONDATAW, has::cbSize_member_type);

# endif /* _INC_SHELLAPI || _SHELLAPI_H || !WIN32_LEAN_AND_MEAN */

# undef  WINSTL_THE_INITIALISABLE_STRUCTURE_
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

#endif /* !WINSTL_INCL_WINSTL_UTIL_HPP_STRUCT_INITIALISERS */

/* ///////////////////////////// end of file //////////////////////////// */

