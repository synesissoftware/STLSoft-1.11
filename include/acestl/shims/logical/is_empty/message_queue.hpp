/* /////////////////////////////////////////////////////////////////////////
 * File:    acestl/shims/logical/is_empty/message_queue.hpp
 *
 * Purpose: Helper functions for ACE_Message_Queue class.
 *
 * Created: 16th December 2004
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


/** \file acestl/shims/logical/is_empty/message_queue.hpp
 *
 * \brief [C++] Primary include file for is_empty attribute shims
 *   for <code>ACE_Message_Queue</code>
 *   (\ref group__concept__Shim__Logical__is_empty "is_empty Collection Logical Shim").
 */

#ifndef ACESTL_INCL_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_MESSAGE_QUEUE
#define ACESTL_INCL_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_MESSAGE_QUEUE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_MESSAGE_QUEUE_MAJOR       3
# define ACESTL_VER_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_MESSAGE_QUEUE_MINOR       1
# define ACESTL_VER_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_MESSAGE_QUEUE_REVISION    1
# define ACESTL_VER_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_MESSAGE_QUEUE_EDIT        43
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_EMPTY_UTIL_HPP_FEATURES
# include <stlsoft/shims/logical/is_empty/util/features.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_EMPTY_UTIL_HPP_FEATURES */

#ifndef STLSOFT_INCL_ACE_H_MESSAGE_QUEUE
# define STLSOFT_INCL_ACE_H_MESSAGE_QUEUE
# include <ace/Message_Queue.h>             // for ACE_Message_Queue<>
#endif /* !STLSOFT_INCL_ACE_H_MESSAGE_QUEUE */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* !STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#ifdef STLSOFT_SHIM_LOGICAL_IS_EMPTY_NEEDS_HELP

STLSOFT_OPEN_WORKER_NS_(is_empty_ns)

    no_type
    is_empty_helper_assistant(
        ACE_Message_Queue_Base const*
    ,   ACE_Message_Queue_Base const*
    )
    {
        return no_type();
    }

    inline
    ss_bool_t
    is_empty_helper(ACE_Message_Queue_Base const& q, no_type) STLSOFT_NOEXCEPT
    {
        return 0 != const_cast<ACE_Message_Queue_Base&>(q).is_empty();
    }
STLSOFT_CLOSE_WORKER_NS_(is_empty_ns)
#else /* ? STLSOFT_SHIM_LOGICAL_IS_EMPTY_NEEDS_HELP */

/** Indicates whether the message queue is empty
 *
 * \ingroup group__concept__Shim__Logical__is_empty
 *
 */
inline
int
is_empty(ACE_Message_Queue_Base const& q) STLSOFT_NOEXCEPT
{
    // Have to cast this, as ACE is not const-correct with is_empty().

    return const_cast<ACE_Message_Queue_Base&>(q).is_empty();
}

/** Indicates whether the message queue is empty
 *
 * \ingroup group__concept__Shim__Logical__is_empty
 *
 */
template <ACE_SYNCH_DECL>
inline
int
is_empty(ACE_Message_Queue<ACE_SYNCH_USE> const& q) STLSOFT_NOEXCEPT
{
    // Have to cast this, as ACE is not const-correct with is_empty().

    return const_cast<ACE_Message_Queue<ACE_SYNCH_USE>&>(q).is_empty();
}
#endif /* STLSOFT_SHIM_LOGICAL_IS_EMPTY_NEEDS_HELP */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* !STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !ACESTL_INCL_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_MESSAGE_QUEUE */

/* ///////////////////////////// end of file //////////////////////////// */

