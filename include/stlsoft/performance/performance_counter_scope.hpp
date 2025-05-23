/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/performance/performance_counter_scope.hpp
 *
 * Purpose: Performance counter scope class.
 *
 * Created: 20th July 2002
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


/** \file stlsoft/performance/performance_counter_scope.hpp
 *
 * \brief [C++] Definition of the stlsoft::performance_counter_scope
 *  class template
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_HPP_PERFORMANCE_COUNTER_SCOPE
#define STLSOFT_INCL_STLSOFT_HPP_PERFORMANCE_COUNTER_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_PERFORMANCE_COUNTER_SCOPE_MAJOR    5
# define STLSOFT_VER_STLSOFT_HPP_PERFORMANCE_COUNTER_SCOPE_MINOR    0
# define STLSOFT_VER_STLSOFT_HPP_PERFORMANCE_COUNTER_SCOPE_REVISION 3
# define STLSOFT_VER_STLSOFT_HPP_PERFORMANCE_COUNTER_SCOPE_EDIT     55
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

#ifndef STLSOFT_INCL_STLSOFT_HPP_STOPWATCH_SCOPE
# include <stlsoft/diagnostics/stopwatch_scope.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STOPWATCH_SCOPE */


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

// class stlsoft::performance_counter_scope
/** Scopes the measurement period for a performance counter
 *
 * \ingroup group__library__Diagnostic
 *
 * \param C The performance counter type
 */
template <ss_typename_param_k C>
class performance_counter_scope
    : public stopwatch_scope<C>
{
public: // types
    /// The counter type
    typedef C                                               counter_type;
    /// The class type
    typedef performance_counter_scope<C>                    class_type;

public: // construction
    /// Constructs with the performance counter instance to manage, on which start() is called
    ss_explicit_k
    performance_counter_scope(counter_type& counter)
        : m_counter(counter)
    {
        m_counter.start();
    }
    /// Calls stop() on the managed counter
    ~performance_counter_scope() STLSOFT_NOEXCEPT
    {
        m_counter.stop();
    }
private:
    performance_counter_scope(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

public: // operations
    /// Calls stop() on the managed counter
    void stop()
    {
        m_counter.stop();
    }

public: // attributes
    // This method is const, to ensure that only the stop operation (via
    // performance_counter_scope::stop()) is accessible on the managed counter.
    /// Returns a non-mutable (const) reference to the managed counter
    counter_type const& get_counter() const
    {
        return m_counter;
    }

private: // fields
    C& m_counter;
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_PERFORMANCE_COUNTER_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

