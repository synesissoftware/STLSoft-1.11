/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/error/throw_policies.hpp (formerly platformstl/error/exceptions.hpp)
 *
 * Purpose:     Exception throwing policy classes.
 *
 * Created:     20th March 2005
 * Updated:     11th March 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


#ifndef PLATFORMSTL_INCL_PLATFORMSTL_EXCEPTION_HPP_THROW_POLICIES
#define PLATFORMSTL_INCL_PLATFORMSTL_EXCEPTION_HPP_THROW_POLICIES

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_EXCEPTION_HPP_THROW_POLICIES_MAJOR     3
# define PLATFORMSTL_VER_PLATFORMSTL_EXCEPTION_HPP_THROW_POLICIES_MINOR     0
# define PLATFORMSTL_VER_PLATFORMSTL_EXCEPTION_HPP_THROW_POLICIES_REVISION  3
# define PLATFORMSTL_VER_PLATFORMSTL_EXCEPTION_HPP_THROW_POLICIES_EDIT      30
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file platformstl/exception/throw_policies.hpp
 *
 * \brief [C++] Definition of the
 *   platformstl::platform_exception_policy class
 *   (\ref group__library__Exception "Exception" Library).
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_THROW_POLICIES
#  include <unixstl/exception/throw_policies.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_THROW_POLICIES */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES
#  include <winstl/exception/throw_policies.hpp>
# endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES */
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

/* ////////////////////////////////////////////////////////////////////// */

#if defined(PLATFORMSTL_OS_IS_UNIX)

typedef UNIXSTL_NS_QUAL(unix_exception_policy)              platform_exception_policy;

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

typedef WINSTL_NS_QUAL(windows_exception_policy)            platform_exception_policy;

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

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_EXCEPTION_HPP_THROW_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

