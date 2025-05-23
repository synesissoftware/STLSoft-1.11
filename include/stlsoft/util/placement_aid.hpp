/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/util/placement_aid.hpp
 *
 * Purpose: A scoping class to aid in placement new-ing.
 *
 * Created: 9th January 2002
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/placement_aid.hpp
 *
 * \brief [C++] Definition of the stlsoft::placement_aid class template
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_PLACEMENT_AID
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_PLACEMENT_AID

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_PLACEMENT_AID_MAJOR    4
# define STLSOFT_VER_STLSOFT_UTIL_HPP_PLACEMENT_AID_MINOR    0
# define STLSOFT_VER_STLSOFT_UTIL_HPP_PLACEMENT_AID_REVISION 9
# define STLSOFT_VER_STLSOFT_UTIL_HPP_PLACEMENT_AID_EDIT     49
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

#ifndef STLSOFT_INCL_NEW
# define STLSOFT_INCL_NEW
# include <new>
#endif /* !STLSOFT_INCL_NEW */


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

// class placement_aid

/** Scopes the lifetime of an object created by placement new
 *
 * \ingroup group__library__Utility
 *
 *
 *
 * \param T The type of the object created by placement new
 */
template <ss_typename_param_k T>
class placement_aid
{
public:
    /// The value type
    typedef T                   value_type;
    /// The current specialisation of the type
    typedef placement_aid<T>    class_type;

// Construction
public:
    /// Create an instance of the \c value_type at the given location
    ///
    /// \param pv The location at which to in-place construct the object instance
    ss_explicit_k
    placement_aid(void* pv)
        : m_t(*new(pv) T())
    {}

    /// In-place destroy the object instance
    ~placement_aid() STLSOFT_NOEXCEPT
    {
        m_t.~T();
    }
private:
    placement_aid(class_type const&);
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

// Accessors
public:
    /// Implicit conversion operator to a reference to the in-place object instance
    operator T&()
    {
        return m_t;
    }
    /// Implicit conversion operator to a non-mutable (const) reference to the in-place object instance
    operator T const& () const
    {
        return m_t;
    }

    /// Address-of operator, providing pointer access to the in-place object instance
    T* operator &()
    {
        return &m_t;
    }
    /// Address-of operator, providing non-mutable (const) pointer access to the in-place object instance
    T const* operator &() const
    {
        return &m_t;
    }

// Members
private:
    T   &m_t;
};


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

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_PLACEMENT_AID */

/* ///////////////////////////// end of file //////////////////////////// */

