/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/access/string/fwd.h
 *
 * Purpose:     Forward declarations for (C-string) string access shims c_str_ptr,
 *              c_str_ptr_null, c_str_data, c_str_len, c_str_size.
 *
 * Created:     11th April 2005
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/shims/access/string/fwd.h
 *
 * \brief [C, C++] Forward declaration of the degenerate string access shims
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
#define STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_H_FWD_MAJOR    2
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_H_FWD_MINOR    0
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_H_FWD_REVISION 6
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_H_FWD_EDIT     25
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

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

STLSOFT_INLINE ss_char_a_t const*   c_str_ptr_a(ss_char_a_t const* s);
STLSOFT_INLINE ss_char_w_t const*   c_str_ptr_w(ss_char_w_t const* s);
#ifdef __cplusplus
inline ss_char_a_t const*           c_str_ptr(ss_char_a_t const* s);
inline ss_char_w_t const*           c_str_ptr(ss_char_w_t const* s);
#endif /* __cplusplus */

STLSOFT_INLINE ss_char_a_t const*   c_str_ptr_null_a(ss_char_a_t const* s);
STLSOFT_INLINE ss_char_w_t const*   c_str_ptr_null_w(ss_char_w_t const* s);
#ifdef __cplusplus
inline ss_char_a_t const*           c_str_ptr_null(ss_char_a_t const* s);
inline ss_char_w_t const*           c_str_ptr_null(ss_char_w_t const* s);
#endif /* __cplusplus */

STLSOFT_INLINE ss_char_a_t const*   c_str_data_a(ss_char_a_t const* s);
STLSOFT_INLINE ss_char_w_t const*   c_str_data_w(ss_char_w_t const* s);
#ifdef __cplusplus
inline ss_char_a_t const*           c_str_data(ss_char_a_t const* s);
inline ss_char_w_t const*           c_str_data(ss_char_w_t const* s);
#endif /* __cplusplus */

STLSOFT_INLINE ss_size_t            c_str_len_a(ss_char_a_t const* s);
STLSOFT_INLINE ss_size_t            c_str_len_w(ss_char_w_t const* s);
#ifdef __cplusplus
inline ss_size_t                    c_str_len(ss_char_a_t const* s);
inline ss_size_t                    c_str_len(ss_char_w_t const* s);
#endif /* __cplusplus */

STLSOFT_INLINE ss_size_t            c_str_size_a(ss_char_a_t const* s);
STLSOFT_INLINE ss_size_t            c_str_size_w(ss_char_w_t const* s);
#ifdef __cplusplus
inline ss_size_t                    c_str_size(ss_char_a_t const* s);
inline ss_size_t                    c_str_size(ss_char_w_t const* s);
#endif /* __cplusplus */

#ifdef __cplusplus
template <ss_typename_param_k S>
inline ss_size_t                    c_str_size(S const& s);
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */

/* ///////////////////////////// end of file //////////////////////////// */

