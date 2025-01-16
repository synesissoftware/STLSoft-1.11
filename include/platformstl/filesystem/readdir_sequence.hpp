/* /////////////////////////////////////////////////////////////////////////
 * File:    platformstl/filesystem/readdir_sequence.hpp
 *
 * Purpose: Platform header for the readdir_sequence components.
 *
 * Created: 29th April 2006
 * Updated: 19th December 2024
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file platformstl/filesystem/readdir_sequence.hpp
 *
 * \brief [C++] Definition of the platformstl::readdir_sequence
 *  type
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_READDIR_SEQUENCE
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_READDIR_SEQUENCE

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_MAJOR      2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_MINOR      2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_REVISION   13
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_EDIT       38
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE
#  include <unixstl/filesystem/readdir_sequence.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_READDIR_SEQUENCE
#  include <winstl/filesystem/readdir_sequence.hpp>
# endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_READDIR_SEQUENCE */
#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(STLSOFT_NO_NAMESPACE) || \
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
 * classes
 */

#if 0
#elif defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

    /** STL-like readonly sequence based on directory contents.
     *
     * \ingroup group__library__FileSystem
     *
     * The class is only defined in the \link ::platformstl platformstl\endlink
     * when the platform is not UNIX, in which case it uses the services
     * of another file-system enumeration type, e.g.
     * winstl::basic_findfile_sequence. For UNIX compilation, it
     * resolves to unixstl::readdir_sequence, relying on
     * \ref section__principle__conformance__intersecting_conformance "Intersecting Conformance"
     * of the resolved platform-specific types.
     */
    class readdir_sequence
    {};
#elif defined(PLATFORMSTL_OS_IS_UNIX)

# ifdef UNIXSTL_NO_NAMESPACE
    using ::readdir_sequence;
# else /* ? UNIXSTL_NO_NAMESPACE */
    using ::unixstl::readdir_sequence;
# endif /* UNIXSTL_NO_NAMESPACE */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

# ifdef WINSTL_NO_NAMESPACE
    using ::readdir_sequence;
# else /* ? WINSTL_NO_NAMESPACE */
    using ::winstl::readdir_sequence;
# endif /* WINSTL_NO_NAMESPACE */
#else /* ? operating system */

# error Operating system not discriminated
#endif /* operating system */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace platformstl */
#else
} /* namespace platformstl_project */
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_READDIR_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

