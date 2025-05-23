/* /////////////////////////////////////////////////////////////////////////
 * File:    acestl/network/socket_functions.hpp
 *
 * Purpose: Helper functions for ACE_SOCK (and derived) classes
 *
 * Created: 28th November 2004
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


/** \file acestl/network/socket_functions.hpp
 *
 * \brief [C++; requires ACE] Socket helper functions
 *   (\ref group__library__Network "Network" Library).
 */

#ifndef ACESTL_INCL_ACESTL_NETWORK_HPP_SOCKET_FUNCTIONS
#define ACESTL_INCL_ACESTL_NETWORK_HPP_SOCKET_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_NETWORK_HPP_SOCKET_FUNCTIONS_MAJOR       2
# define ACESTL_VER_ACESTL_NETWORK_HPP_SOCKET_FUNCTIONS_MINOR       0
# define ACESTL_VER_ACESTL_NETWORK_HPP_SOCKET_FUNCTIONS_REVISION    6
# define ACESTL_VER_ACESTL_NETWORK_HPP_SOCKET_FUNCTIONS_EDIT        41
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

#ifndef STLSOFT_INCL_ACE_H_SOCK
# define STLSOFT_INCL_ACE_H_SOCK
# include <ace/SOCK.h>
#endif /* !STLSOFT_INCL_ACE_H_SOCK */
#ifndef STLSOFT_INCL_ACE_H_REACTOR
# define STLSOFT_INCL_ACE_H_REACTOR
# include <ace/Reactor.h>
#endif /* !STLSOFT_INCL_ACE_H_REACTOR */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef ACESTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::acestl */
namespace acestl
{
# else
/* Define stlsoft::acestl_project */
namespace stlsoft
{
namespace acestl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ACESTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Closes a socket and deregisters it from the reactor
 *
 * \ingroup group__library__Network
 *
 * \param sk Reference to the socket to close
 * \param reactor Reactor from which the socket will be deregistered. May be
 *   \c nullptr.
 *
 * \return true if the socket was previously closed, false otherwise. There
 *   is no error return
 *
 * Usage is simple. Just specify the socket to close and, optionally, the
 * reactor with which it is registered.
 *
\code

// close and deregister m_upstreamPeer and m_downstreamPeer (both ACE_SOCK_Stream)
acestl::close_and_deregister(m_peer, reactor());

\endcode
 */
inline as_bool_t close_and_deregister(ACE_SOCK &sk, ACE_Reactor *reactor)
{
    if (ACE_INVALID_HANDLE == sk.get_handle())
    {
        return false;
    }

    if (NULL != reactor)
    {
        const ACE_Reactor_Mask close_mask   =   ACE_Event_Handler::ALL_EVENTS_MASK
                                            |   ACE_Event_Handler::DONT_CALL;

        reactor->remove_handler(sk.get_handle(), close_mask);
    }

    sk.close();

    return true;
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef ACESTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace acestl
# else
} // namespace acestl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ACESTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !ACESTL_INCL_ACESTL_NETWORK_HPP_SOCKET_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

