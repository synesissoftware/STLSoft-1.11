/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/internal/cccap/clang.h
 *
 * Purpose: Compiler feature discrimination for Clang C/C++.
 *
 * Created: 14th March 2015
 * Updated: 31st May 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2015-2019, Matthew Wilson and Synesis Software
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


/* STLSOFT:FILE_EXCEPTED */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# error This file must not be included independently of stlsoft/stlsoft.h
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/** \file stlsoft/internal/cccap/clang.h
 *
 * Compiler feature discrimination for Clang C/C++
 */

#ifdef STLSOFT_INCL_H_STLSOFT_CCCAP_CLANG
# error This file cannot be included more than once in any compilation unit
#endif /* STLSOFT_INCL_H_STLSOFT_CCCAP_CLANG */


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_CCCAP_CLANG_MAJOR    1
# define STLSOFT_VER_H_STLSOFT_CCCAP_CLANG_MINOR    11
# define STLSOFT_VER_H_STLSOFT_CCCAP_CLANG_REVISION 1
# define STLSOFT_VER_H_STLSOFT_CCCAP_CLANG_EDIT     32
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * Structure:
 *
 * - predefined macros extensions
 * - custom macros
 * - preprocessor features
 * - compiler-specific features
 * - support for built-in types
 * - built-in type characteristics
 * - size-specific integer types
 * - support for C/C++ language features
 * - support for C language features
 * - support for C++ language features - 1
 * - support for C++ language features - 2
 * - inline assembler
 * - linkage specification
 * - atomics support
 * - calling convention
 * - integer sizes
 * - integral types
 * - still-to-be-determined features
 * - quality assurance features
 * - compiler warning suppression
 * - obsolete features
 */


/* /////////////////////////////////////////////////////////////////////////
 * predefined macros extensions
 */


/* /////////////////////////////////////////////////////////////////////////
 * custom macros
 */


/* /////////////////////////////////////////////////////////////////////////
 * preprocessor features
 *
 * - #pragma message
 * - #pragma once
 * - __COUNTER__
 * - __func__
 * - __FUNCTION__
 * - variadic macros
 */

#define STLSOFT_PPF_pragma_message_SUPPORT

#define STLSOFT_PPF_pragma_once_SUPPORT

#define STLSOFT_PPF_COUNTER_SYMBOL_SUPPORT

#define STLSOFT_PPF_func_SYMBOL_SUPPORT

#define STLSOFT_PPF_FUNCTION_SYMBOL_SUPPORT

#define STLSOFT_PPF_PRETTY_FUNCTION_SYMBOL_SUPPORT

#define STLSOFT_PPF_VARIADIC_MACROS_SUPPORT


/* /////////////////////////////////////////////////////////////////////////
 * compiler-specific features
 */

#ifdef __GNUC__
# define STLSOFT_CF_gcc_pragma_diagnostic_pop
#endif


/* /////////////////////////////////////////////////////////////////////////
 * support for built-in types
 *
 * - bool
 * - wchar_t
 * - long long
 * - __int8
 * - __int16
 * - __int32
 * - __int64
 * - long double
 */

#ifdef __cplusplus
# define STLSOFT_CF_BUILTIN_bool_SUPPORT
#endif /* __cplusplus */

#ifdef __cplusplus
# define STLSOFT_CF_BUILTIN_wchar_t_SUPPORT
#endif /* __cplusplus */

#define STLSOFT_CF_BUILTIN_long_long_SUPPORT


/* /////////////////////////////////////////////////////////////////////////
 * built-in type characteristics
 *
 * - char is unsigned
 */

#if 0
#elif defined(_CHAR_UNSIGNED) ||\
      defined(__CHAR_UNSIGNED__)
# define STLSOFT_CF_char_IS_UNSIGNED
#endif /* __CHAR_UNSIGNED__ */


/* /////////////////////////////////////////////////////////////////////////
 * support for C/C++ language features
 *
 * - nullptr (C++11)
 * - return void
 * - static assertions
 * - anonymous unions
 * - -ve % +ve => -ve result
 *
 * nullptr (C++11)
 * ---------------
 *
 * nullptr keyword is recognised, represented by definition of the
 * preprocessor symbol STLSOFT_CF_BUILTIN_nullptr_SUPPORT
 *
 *
 * static assertions
 * -----------------
 *
 * Two questions:
 *
 * 1. Are STLSoft-style static assertions (see stlsoft/stlsoft.h)
 * supported by the compiler? This is indicated by the definition of the
 * preprocessor symbol STLSOFT_CF_STATIC_ASSERT_SUPPORT
 *
 * 2. Is the C++11 static_assert keyword supported? This is indicated by the
 * definition of the preprocessor symbol STLSOFT_CF_static_assert_SUPPORT
 */

#if __has_feature(cxx_nullptr)
# define STLSOFT_CF_nullptr_KEYWORD_SUPPORT
# define STLSOFT_CF_BUILTIN_nullptr_SUPPORT
#endif



#if __has_feature(cxx_static_assert)
# define STLSOFT_CF_STATIC_ASSERT_SUPPORT
# define STLSOFT_CF_static_assert_SUPPORT
#endif

#define STLSOFT_CF_NEGATIVE_MODULUS_POSITIVE_GIVES_NEGATIVE_RESULT


/* /////////////////////////////////////////////////////////////////////////
 * support for C language features
 *
 * - inline
 *    - C99 inline keyword
 *    - compiler-specific keyword
 */

#ifndef __cplusplus

# if defined(__STDC_VERSION__) &&\
     __STDC_VERSION__ >= 201112L

#  define STLSOFT_CUSTOM_C_INLINE                           static inline
# else /* ? C version */

#  define STLSOFT_CUSTOM_C_INLINE                           extern inline
# endif /* C version */
#endif


/* /////////////////////////////////////////////////////////////////////////
 * support for C++ language features - 1
 *
 * - exceptions
 *    - exception signatures
 *    - exception signatures expense
 *    - operator new throws bad_alloc
 * - RTTI
 * - namespaces
 *    - STLSoft namespace(s)?
 * - member constants
 * - explicit keyword
 * - mutable keyword
 * - override keyword
 * - template keyword
 * - typename keyword
 *    - in a template parameter
 *    - type disambiguation inside template bodies
 *    - disambiguation in default template arguments
 *    - type disambiguation inside initialiser lists in class template constructors
 *    - type disambiguation the return types in templates
 * - argument-dependent lookup
 * - rvalue references
 * - static array-size determination
 * - empty-derived optimisation
 *    -
 * - empty-base optimisation
 *    -
 * - move constructor support
 * - operators
 *    - operator bool implemented as pointer-to-member
 *    - operator ! implemented as pointer-to-member
 */

#if __has_feature(cxx_exceptions)
# define STLSOFT_CF_EXCEPTION_SUPPORT
# define STLSOFT_CF_EXCEPTION_SIGNATURE_SUPPORT
# define STLSOFT_CF_EXCEPTION_OPERATOR_NEW_THROWS_BAD_ALLOC
#endif

#if __has_feature(cxx_rtti)
# define STLSOFT_CF_RTTI_SUPPORT
#endif

#ifdef __cplusplus
# define STLSOFT_CF_NAMESPACE_SUPPORT
#endif

#define STLSOFT_CF_std_NAMESPACE

#define STLSOFT_CF_MEMBER_CONSTANT_SUPPORT

#define STLSOFT_CF_explicit_KEYWORD_SUPPORT

#define STLSOFT_CF_mutable_KEYWORD_SUPPORT

#if __has_feature(cxx_noexcept)
# define STLSOFT_CF_noexcept_KEYWORD_SUPPORT
#endif /* compiler */

#define STLSOFT_CF_noinline_KEYWORD_SUPPORT
#define STLSOFT_CUSTOM_NOINLINE                             __attribute__((noinline))

#if __has_feature(cxx_override_control)
# define STLSOFT_CF_override_KEYWORD_SUPPORT
#endif

#define STLSOFT_CF_TEMPLATE_QUALIFIER_KEYWORD_SUPPORT

#define STLSOFT_CF_TYPENAME_PARAM_KEYWORD_SUPPORT

#define STLSOFT_CF_TYPENAME_TYPE_KEYWORD_SUPPORT

#define STLSOFT_CF_TYPENAME_TYPE_DEF_KEYWORD_SUPPORT

#define STLSOFT_CF_TYPENAME_TYPE_RET_KEYWORD_SUPPORT

#define STLSOFT_CF_ADL_SUPPORT

#if __has_feature(cxx_rvalue_references)
# define STLSOFT_CF_RVALUE_REFERENCES_SUPPORT
#endif

#define STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT


/* /////////////////////////////////////////////////////////////////////////
 * support for C++ language features - 2
 *
 * - templates
 *    - specialisation syntax (template <>)
 *    - partial specialisation
 *    - function template
 *    - class template
 *    - member class template
 *    - member function template
 *    - member range function template
 *    - constructor template
 *    - template template
 *    - class template fundamental argument
 *    - class template type argument
 *    - class template member function argument
 *    - class template default fundamental argument
 *    - class template default type argument
 *    - function template parameter list requires template parameter
 *    - member function template overload is properly discriminated against
 *      other non-template member function
 *    - constructor template overload is properly discriminated against
 *      other non-template constructor
 *    - copy-constructor template overload is properly discriminated against
 *      other non-template copy-constructor
 *    - template void type parameter
 *    - variadic templates
 */

#define STLSOFT_CF_TEMPLATE_SUPPORT

#define STLSOFT_CF_TEMPLATE_SPECIALISATION_SYNTAX_SUPPORT

#define STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

#define STLSOFT_CF_TEMPLATE_FUNCTION_TEMPLATE_SUPPORT

#define STLSOFT_CF_TEMPLATE_CLASS_TEMPLATE_SUPPORT

#define STLSOFT_CF_TEMPLATE_MEMBER_CLASS_TEMPLATE_SUPPORT

#define STLSOFT_CF_TEMPLATE_MEMBER_FUNCTION_TEMPLATE_SUPPORT

#define STLSOFT_CF_TEMPLATE_MEMBER_RANGE_FUNCTION_TEMPLATE_SUPPORT

#define STLSOFT_CF_TEMPLATE_CTOR_TEMPLATE_SUPPORT

#define STLSOFT_CF_TEMPLATE_TEMPLATE_SUPPORT

#define STLSOFT_CF_TEMPLATE_FUNDAMENTAL_PARAMETER_SUPPORT

#define STLSOFT_CF_TEMPLATE_TYPE_PARAMETER_SUPPORT

#define STLSOFT_CF_TEMPLATE_MEMBER_FUNCTION_PARAMETER_SUPPORT

#define STLSOFT_CF_TEMPLATE_DEFAULT_FUNDAMENTAL_PARAMETER_SUPPORT

#define STLSOFT_CF_TEMPLATE_DEFAULT_TYPE_PARAMETER_SUPPORT

#define STLSOFT_CF_TEMPLATE_MEMBER_FUNCTION_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_MEMBER_FUNCTION

#define STLSOFT_CF_TEMPLATE_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_CONSTRUCTOR

#define STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR

#define STLSOFT_CF_TEMPLATE_VOID_TYPE_PARAMETER

#if __has_feature(cxx_variadic_templates)
# define STLSOFT_CF_VARIADIC_TEMPLATE_SUPPORT
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * inline assembler
 */


/* /////////////////////////////////////////////////////////////////////////
 * linkage specification
 */


/* /////////////////////////////////////////////////////////////////////////
 * atomics support
 */

#define STLSOFT_CF_SUPPORT_ATOMIC_GCC_BUILTINS


/* /////////////////////////////////////////////////////////////////////////
 * calling convention
 *
 * As far as is currently known, there is only a single calling convention
 * for Clang - cdecl. If that's not so, update in a similar vein to that
 * shown in stlsoft/internal/cccap/msvc.h
 */

#define STLSOFT_CF_CDECL_SUPPORTED

#ifdef STLSOFT_CF_CDECL_SUPPORTED
# define STLSOFT_CDECL
#endif /* STLSOFT_CF_CDECL_SUPPORTED */


/* /////////////////////////////////////////////////////////////////////////
 * integer sizes
 */

#define _STLSOFT_SIZEOF_CHAR                                (1)
#define _STLSOFT_SIZEOF_SHORT                               __SIZEOF_SHORT__
#define _STLSOFT_SIZEOF_INT                                 __SIZEOF_INT__
#define _STLSOFT_SIZEOF_LONG                                __SIZEOF_LONG__
#define _STLSOFT_SIZEOF_LONG_LONG                           __SIZEOF_LONG_LONG__


/* /////////////////////////////////////////////////////////////////////////
 * size-specific integer types
 *
 * The purpose of this section is to define the following types:
 *
 *  - 8-bit signed and unsigned integers
 *  - 16-bit signed and unsigned integers
 *  - 32-bit signed and unsigned integers
 *  - (optionally) 64-bit signed and unsigned integers
 */


/* /////////////////////////////////////////////////////////////////////////
 * integral types
 */

/* 8-bit integer */
#define STLSOFT_CF_8BIT_INT_SUPPORT
#define STLSOFT_SI08_T_BASE_TYPE                            __INT8_TYPE__
#define STLSOFT_UI08_T_BASE_TYPE                            __UINT8_TYPE__

/* 16-bit integer */
#define STLSOFT_CF_16BIT_INT_SUPPORT
#define STLSOFT_SI16_T_BASE_TYPE                            __INT16_TYPE__
#define STLSOFT_UI16_T_BASE_TYPE                            __UINT16_TYPE__

/* 32-bit integer */
#define STLSOFT_CF_32BIT_INT_SUPPORT
#define STLSOFT_SI32_T_BASE_TYPE                            __INT32_TYPE__
#define STLSOFT_UI32_T_BASE_TYPE                            __UINT32_TYPE__
#define STLSOFT_CF_LONG_DISTINCT_INT_TYPE

/* 64-bit integer */
#if 0
#elif 0 ||\
      defined(STLSOFT_LONGLONG_SUPPORT) ||\
      0 ||\
      defined(__aarch64__) ||\
      defined(_M_ARM64) ||\
      0 ||\
      defined(__ia64__) ||\
      defined(__ia64) ||\
      defined(_IA64_) ||\
      defined(_M_IA64) ||\
      0 ||\
      defined(__amd64__) ||\
      defined(__amd64) ||\
      defined(__x86_64__) ||\
      defined(__x86_64) ||\
      defined(_AMD64_) ||\
      defined(_M_AMD64) ||\
      defined(_M_X64) ||\
      0 ||\
      0

# define STLSOFT_CF_64BIT_INT_SUPPORT
# ifdef STLSOFT_LONGLONG_SUPPORT
#  define STLSOFT_CF_64BIT_INT_IS_long_long
# endif /* STLSOFT_LONGLONG_SUPPORT */

# define STLSOFT_SI64_T_BASE_TYPE                           __INT64_TYPE__
# define STLSOFT_UI64_T_BASE_TYPE                           __UINT64_TYPE__
#endif /* STLSOFT_LONGLONG_SUPPORT */

/* ptr-bit integer */
#define STLSOFT_SPTR_T_BASE_TYPE                            __INTPTR_TYPE__
#define STLSOFT_UPTR_T_BASE_TYPE                            __UINTPTR_TYPE__


/* /////////////////////////////////////////////////////////////////////////
 * still-to-be-determined features
 */

#define STLSOFT_CF_FUNCTION_SIGNATURE_FULL_ARG_QUALIFICATION_REQUIRED

#define STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT


/* /////////////////////////////////////////////////////////////////////////
 * quality assurance features
 */

#define STLSOFT_CF_ASSERT_SUPPORT
#if STLSOFT_HEAD_VER >= 0x010c0000
# ifdef __cplusplus
#  define STLSOFT_STOCK_ASSERT_INCLUDE_                     <cassert>
# else /* ? __cplusplus */
#  define STLSOFT_STOCK_ASSERT_INCLUDE_                     <assert.h>
# endif /* __cplusplus */
# define STLSOFT_STOCK_ASSERT_(expr)                        assert(expr)
#else
# define __STLSOFT_CF_USE_cassert
#endif


/* /////////////////////////////////////////////////////////////////////////
 * compiler warning suppression
 */


/* /////////////////////////////////////////////////////////////////////////
 * obsolete features
 */

#include <stlsoft/internal/cccap/obsolete.h>


/* ///////////////////////////// end of file //////////////////////////// */

