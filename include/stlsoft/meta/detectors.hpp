/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/meta/detectors.hpp
 *
 * Purpose:     Combined header file for STLSoft's TypeFixer utility components.
 *
 * Created:     15th July 2006
 * Updated:     16th February 2024
 *
 * Home:        http://stlsoft.org/
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


/** \file stlsoft/meta/detectors.hpp
 *
 * \brief [C++] Common include file for all member detector class
 *   templates
 *   (\ref group__library__Metaprogramming "Metaprogramming" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_DETECTORS
#define STLSOFT_INCL_STLSOFT_META_HPP_DETECTORS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_META_HPP_DETECTORS_MAJOR       1
# define STLSOFT_VER_STLSOFT_META_HPP_DETECTORS_MINOR       1
# define STLSOFT_VER_STLSOFT_META_HPP_DETECTORS_REVISION    1
# define STLSOFT_VER_STLSOFT_META_HPP_DETECTORS_EDIT        15
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-UNITTEST]>]
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC: _MSC_VER < 1310
[Incompatibilies-end]
*/


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_CONST_ITERATOR
# include <stlsoft/meta/detector/has_const_iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_CONST_ITERATOR */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_CONST_POINTER
# include <stlsoft/meta/detector/has_const_pointer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_CONST_POINTER */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_CONST_REFERENCE
# include <stlsoft/meta/detector/has_const_reference.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_CONST_REFERENCE */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_DIFFERENCE_TYPE
# include <stlsoft/meta/detector/has_difference_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_DIFFERENCE_TYPE */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_DISTANCE_TYPE
# include <stlsoft/meta/detector/has_distance_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_DISTANCE_TYPE */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_ITERATOR
# include <stlsoft/meta/detector/has_iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_ITERATOR */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_ITERATOR_CATEGORY
# include <stlsoft/meta/detector/has_iterator_category.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_ITERATOR_CATEGORY */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_KEY_TYPE
# include <stlsoft/meta/detector/has_key_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_KEY_TYPE */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_MAPPED_TYPE
# include <stlsoft/meta/detector/has_mapped_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_MAPPED_TYPE */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_POINTER
# include <stlsoft/meta/detector/has_pointer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_POINTER */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_POINTER_TYPE
# include <stlsoft/meta/detector/has_pointer_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_POINTER_TYPE */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_REFERENCE
# include <stlsoft/meta/detector/has_reference.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_REFERENCE */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_REFERENCE_TYPE
# include <stlsoft/meta/detector/has_reference_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_REFERENCE_TYPE */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_REFERENT_TYPE
# include <stlsoft/meta/detector/has_referent_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_REFERENT_TYPE */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_SENTRY
# include <stlsoft/meta/detector/has_sentry.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_SENTRY */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_VALUE_TYPE
# include <stlsoft/meta/detector/has_value_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_VALUE_TYPE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_DETECTORS */

/* ///////////////////////////// end of file //////////////////////////// */

