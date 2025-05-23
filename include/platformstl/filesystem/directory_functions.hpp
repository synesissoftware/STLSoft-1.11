/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/directory_functions.hpp
 *
 * Purpose:     Platform header for directory manipulation functions.
 *
 * Created:     29th May 2006
 * Updated:     20th March 2025
 *
 * Home:        http://stlsoft.org/
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


/** \file platformstl/filesystem/directory_functions.hpp
 *
 * \brief [C++] Functions for manipulating directories
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_MAJOR       1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_MINOR       1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_REVISION    5
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_EDIT        25
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL
# include <platformstl/platformstl.h>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS
#  include <unixstl/filesystem/directory_functions.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS
#  include <winstl/filesystem/directory_functions.hpp>
# endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS */
#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(__cplusplus)
 /* Nothing defined in C */
#elif defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
#else
/* Define stlsoft::platformstl_project */
namespace stlsoft
{
namespace platformstl_project
{
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Creates the given directory, and any intermediate directories
 *   that do not exist
 *
 * \ingroup group__library__FileSystem
 */
template <ss_typename_param_k S>
inline bool_t create_directory_recurse(S const& dir)
{
# if defined(PLATFORMSTL_OS_IS_UNIX)

    return unixstl::create_directory_recurse(dir);

# elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    return winstl::create_directory_recurse(dir);

# else /* ? operating system */
#  error Operating system not discriminated
# endif /* operating system */
}

/** Removes the given directory, and all its subdirectories.
 *
 * \ingroup group__library__FileSystem
 */
template <ss_typename_param_k S>
inline bool_t remove_directory_recurse(S const& dir)
{
# if defined(PLATFORMSTL_OS_IS_UNIX)

    return unixstl::remove_directory_recurse(dir);

# elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    return winstl::remove_directory_recurse(dir);

# else /* ? operating system */
#  error Operating system not discriminated
# endif /* operating system */
}

/* ////////////////////////////////////////////////////////////////////// */

#if !defined(__cplusplus)
 /* Nothing defined in C */
#elif defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace platformstl
#else
} // namespace platformstl_project
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

