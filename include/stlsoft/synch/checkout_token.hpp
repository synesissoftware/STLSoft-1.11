/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/synch/checkout_token.hpp
 *
 * Purpose: Scoped thread-safe access locking class.
 *
 * Created: 7th November 2004
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/synch/checkout_token.hpp
 *
 * \brief [C++] Definition of the stlsoft::checkout_token class
 *  template
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CHECKOUT_TOKEN
#define STLSOFT_INCL_STLSOFT_SYNCH_HPP_CHECKOUT_TOKEN

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_CHECKOUT_TOKEN_MAJOR     2
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_CHECKOUT_TOKEN_MINOR     0
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_CHECKOUT_TOKEN_REVISION  8
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_CHECKOUT_TOKEN_EDIT      37
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

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_LOCK_SCOPE
# include <stlsoft/synch/lock_scope.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_LOCK_SCOPE */


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

/** This class acts as a
 *
 * \ingroup group__library__Synch
 *
 * For example, consider that you have a class X whose resources are to be
 * accessible to multiple threads, defined as follows:
\code
  class X
  {
  public:
    typedef std::queue<int>   queue_type;

  public:
    void lock();
    void unlock();

  public:
    que
  };
\endcode
 *
 * Rather than relying on the good actions of the user, we can instead bind
 * the locking of X's resources with access to its queue, using
 * \link stlsoft::checkout_token checkout_token\endlink, as follows:
 *
\code


\endcode
 *
 */
template<   ss_typename_param_k CT  //!< Accessed class type
        ,   ss_typename_param_k MT  //!< Accessed member type
        >
class checkout_token
{
/// \name Member Types
/// @{
public:
    /// The type whose resources are to be protected
    typedef CT                      accessed_class_type;
    /// The type by which the resources are accessed
    typedef MT                      accessed_member_type;
    /// The current instantation of the type
    typedef checkout_token<CT, MT>  class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Locks
    checkout_token(accessed_class_type& ac, accessed_member_type am)
        : m_ac(ac)
        , m_am(am)
        , m_lock(ac)
    {}
    /// Cop
    checkout_token(class_type const& rhs)
        : m_ac(rhs.m_ac)
        , m_am(rhs.m_am)
        , m_lock(rhs.m_ac)
    {}
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Accessors
/// @{
public:
    accessed_member_type member()
    {
        return m_am;
    }

#if 0
    accessed_member_type *operator ->()
    {
        return &m_am;
    }
    accessed_member_type const* operator ->() const
    {
        return &m_am;
    }
#endif /* 0 */
/// @}

/// \name Members
/// @{
private:
    typedef lock_scope<accessed_class_type> lock_type;

    accessed_class_type     &m_ac;
    accessed_member_type    m_am;
    lock_type               m_lock;
/// @}
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

#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CHECKOUT_TOKEN */

/* ///////////////////////////// end of file //////////////////////////// */

