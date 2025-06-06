/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/meta/yesno.hpp
 *
 * Purpose:     yes / no classes.
 *
 * Created:     16th May 2005
 * Updated:     20th March 2025
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/meta/yesno.hpp
 *
 * \brief [C++] Definition of the stlsoft::yes_type and
 *  stlsoft::no_type meta boolean "constants"
 *   (\ref group__library__Metaprogramming "Metaprogramming" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
#define STLSOFT_INCL_STLSOFT_META_HPP_YESNO

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_META_HPP_YESNO_MAJOR       1
# define STLSOFT_VER_STLSOFT_META_HPP_YESNO_MINOR       3
# define STLSOFT_VER_STLSOFT_META_HPP_YESNO_REVISION    4
# define STLSOFT_VER_STLSOFT_META_HPP_YESNO_EDIT        26
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
 * classes
 */

/** Meta boolean 'yes' type, which acts as a complement to the
 *   \link stlsoft::no_type no_type\endlink.
 *
 * \ingroup group__library__Metaprogramming
 */
struct yes_type
{
    char ar[32];
};

/** Meta boolean 'no' type, which acts as a complement to the
 *   \link stlsoft::yes_type yes_type\endlink.
 *
 * \ingroup group__library__Metaprogramming
 */
struct no_type
{
    char ar[1];
};


/** A type which translates a boolean (integral zero / non-zero)
 *   value into the appropriate type (no_type / yes_type).
 *
 * \ingroup group__library__Metaprogramming
 */
template <ss_bool_t B>
struct value_to_yesno_type
{
    enum { value = 1 };

    typedef yes_type    type;
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct value_to_yesno_type<0>
{
    enum { value = 0 };

    typedef no_type type;
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */

/* ///////////////////////////// end of file //////////////////////////// */

