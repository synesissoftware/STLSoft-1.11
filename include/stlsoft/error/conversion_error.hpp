/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/error/conversion_error.hpp
 *
 * Purpose: Definition of the stlsoft::conversion_error exception class.
 *
 * Created: 15th December 2006
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


/** \file stlsoft/error/conversion_error.hpp
 *
 * \brief [C++] Definition of the stlsoft::conversion_error
 *   exception class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_CONVERSION_ERROR
#define STLSOFT_INCL_STLSOFT_ERROR_HPP_CONVERSION_ERROR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ERROR_HPP_CONVERSION_ERROR_MAJOR       1
# define STLSOFT_VER_STLSOFT_ERROR_HPP_CONVERSION_ERROR_MINOR       0
# define STLSOFT_VER_STLSOFT_ERROR_HPP_CONVERSION_ERROR_REVISION    13
# define STLSOFT_VER_STLSOFT_ERROR_HPP_CONVERSION_ERROR_EDIT        27
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STDEXCEPT
# define STLSOFT_INCL_STDEXCEPT
# include <stdexcept>
#endif /* !STLSOFT_INCL_STDEXCEPT */
#ifndef STLSOFT_INCL_STRING
# define STLSOFT_INCL_STRING
# include <string>
#endif /* !STLSOFT_INCL_STRING */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Root
 *
 * \ingroup group__library__Exception
 *
 * This class is designed to be a parent class to other, more specific,
 * conversion exception classes.
 */
class conversion_error_base
    : public STLSOFT_NS_QUAL_STD(runtime_error)
{
/// \name Types
/// @{
public:
    /// The parent type
    typedef STLSOFT_NS_QUAL_STD(runtime_error)  parent_class_type;
    /// The type of the current instantiation
    typedef conversion_error_base               class_type;
    /// The string argument type
    typedef STLSOFT_NS_QUAL_STD(string)         string_type;
/// @}

/// \name Construction
/// @{
protected:
    ss_explicit_k conversion_error_base(string_type const& message)
        : parent_class_type(message)
    {}
    ss_explicit_k conversion_error_base(char const* message)
        : parent_class_type(message)
    {}
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER > 1200

    // There's a defect in the VC++ 6 compiler that causes the throwing of
    // any derived class to cause an ICE
    virtual ~conversion_error_base() STLSOFT_NOEXCEPT_STDOVR = 0;
#endif /* compiler */
/// @}
};

/** Represents a failed conversion
 *
 * \ingroup group__library__Exception
 */
class conversion_error
    : public conversion_error_base
{
/// \name Types
/// @{
public:
    /// The parent type
    typedef conversion_error_base                           parent_class_type;
    /// The type of the current instantiation
    typedef conversion_error                                class_type;
    /// The string argument type
    typedef STLSOFT_NS_QUAL_STD(string)                     string_type;
    /// The status code type
    typedef int                                             status_code_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef status_code_type                                error_code_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance from the given message and error code
    conversion_error(string_type const& message, status_code_type code)
        : parent_class_type(message)
        , m_statusCode(code)
    {}
    /// Constructs an instance from the given message and error code
    conversion_error(char const* message, status_code_type code)
        : parent_class_type(message)
        , m_statusCode(code)
    {}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
public:
    conversion_error(class_type const& rhs)
        : parent_class_type(rhs)
        , m_statusCode(rhs.m_statusCode)
    {}
    virtual ~conversion_error() STLSOFT_NOEXCEPT_STDOVR
    {}
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Accessors
/// @{
public:
    status_code_type get_error_code() const
    {
        return m_statusCode;
    }

    status_code_type get_last_error() const
    {
        return get_error_code();
    }
/// @}

/// \name Members
/// @{
private:
    status_code_type const  m_statusCode;
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER > 1200
inline /* virtual */ conversion_error_base::~conversion_error_base() STLSOFT_NOEXCEPT_STDOVR
{}
# endif /* compiler */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_CONVERSION_ERROR */

/* ///////////////////////////// end of file //////////////////////////// */

