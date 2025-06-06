/* /////////////////////////////////////////////////////////////////////////
 * File:    wtlstl/wtlstl.hpp
 *
 * Purpose: Root header for the WTLSTL libraries. Performs compiler and
 *          platform discriminations, and definitions of types.
 *
 * Created: 12th May 2003
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


#ifndef WTLSTL_INCL_WTLSTL_HPP_WTLSTL
#define WTLSTL_INCL_WTLSTL_HPP_WTLSTL
#define WTLSTL_INCL_H_WTLSTL

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _WTLSTL_VER_WTLSTL_HPP_WTLSTL_MAJOR    2
# define _WTLSTL_VER_WTLSTL_HPP_WTLSTL_MINOR    4
# define _WTLSTL_VER_WTLSTL_HPP_WTLSTL_REVISION 3
# define _WTLSTL_VER_WTLSTL_HPP_WTLSTL_EDIT     63
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file wtlstl/wtlstl.hpp
 *
 * \brief [C++; requires WTL library] Root header for the
 * \ref group__project__wtlstl "WTLSTL" project.
 */

/* /////////////////////////////////////////////////////////////////////////
 * WTLSTL version
 *
 * The libraries version information is comprised of major, minor and revision
 * components.
 *
 * The major version is denoted by the _WTLSTL_VER_MAJOR preprocessor symbol.
 * A change to the major version component implies that a dramatic change has
 * occurred in the libraries, such that considerable changes to source dependent
 * on previous versions would need to be effected.
 *
 * The minor version is denoted by the _WTLSTL_VER_MINOR preprocessor symbol.
 * Changes to the minor version component imply that a significant change has
 * occurred to the libraries, either in the addition of new functionality or in
 * the destructive change to one or more components such that recomplilation and
 * code change may be necessitated.
 *
 * The revision version is denoted by the _WTLSTL_VER_REVISION preprocessor
 * symbol. Changes to the revision version component imply that a bug has been
 * fixed. Dependent code should be recompiled in order to pick up the changes.
 *
 * In addition to the individual version symbols - _WTLSTL_VER_MAJOR,
 * _WTLSTL_VER_MINOR and _WTLSTL_VER_REVISION - a composite symbol _WTLSTL_VER
 * is defined, where the upper 8 bits are 0, bits 16-23 represent the major
 * component,  bits 8-15 represent the minor component, and bits 0-7 represent
 * the revision component.
 *
 * Each release of the libraries will bear a different version, and that version
 * will also have its own symbol: Version 1.0.1 specifies _WTLSTL_VER_1_0_1.
 *
 * Thus the symbol _WTLSTL_VER may be compared meaningfully with a specific
 * version symbol, e.g. #if _WTLSTL_VER >= _WTLSTL_VER_1_0_1
 */

/** \def _WTLSTL_VER_MAJOR
 * The major version number of WTLSTL
 */

/** \def _WTLSTL_VER_MINOR
 * The minor version number of WTLSTL
 */

/** \def _WTLSTL_VER_REVISION
 * The revision version number of WTLSTL
 */

/** \def _WTLSTL_VER
 * The current composite version number of WTLSTL
 */

#define _WTLSTL_VER_1_0_1       0x00010001  /*!< Version 1.0.1 */
#define _WTLSTL_VER_1_1_1       0x00010101  /*!< Version 1.1.1 */
#define _WTLSTL_VER_1_1_2       0x00010102  /*!< Version 1.1.2 */
#define _WTLSTL_VER_1_2_1       0x00010201  /*!< Version 1.2.1 */
#define _WTLSTL_VER_1_2_2       0x00010202  /*!< Version 1.2.2 (with STLSoft 1.9.25) */
#define _WTLSTL_VER_1_2_3       0x00010203  /*!< Version 1.2.3 (with STLSoft 1.10.1 b1) */
#define _WTLSTL_VER_1_2_4       0x00010204  /*!< Version 1.2.4 (with STLSoft 1.10.1 b 26) */
#define _WTLSTL_VER_1_2_5       0x00010205  /*!< Version 1.2.5 (with STLSoft 1.11.1 alpha 8) */

#define _WTLSTL_VER_MAJOR       1
#define _WTLSTL_VER_MINOR       2
#define _WTLSTL_VER_REVISION    5
#define _WTLSTL_VER             _WTLSTL_VER_1_2_5


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

/* In order to be compatible with Visual C++ 5.0, we need to define a few
 * things before we include the WTL headers to convince WTL 3.1 that we are
 * valid.
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200

# ifndef MIDL_INTERFACE
#  define MIDL_INTERFACE(x)         struct
# endif /* !MIDL_INTERFACE */

# ifndef LONG_PTR
#  define LONG_PTR                                          LONG
# endif /* !LONG_PTR */

# ifndef UINT_PTR
#  define UINT_PTR                                          unsigned int
# endif /* !UINT_PTR */

# ifndef _ATL_NO_MSIMG
#  define _ATL_NO_MSIMG
# endif /* !_ATL_NO_MSIMG */

# ifndef ATLASSERT
#  define ATLASSERT                                         _ASSERTE
# endif /* !ATLASSERT */

# ifndef _WIN32_IE
#  define _WIN32_IE                                         0x0300
# endif /* !_WIN32_IE */

#endif /* _MSC_VER < 1200 */

/* Now we include AtlApp.h here
 *
 * NOTE: must include <atlbase.h> first
 */

#ifndef STLSOFT_INCL_H_ATLBASE
# define STLSOFT_INCL_H_ATLBASE
# include <atlbase.h>
#endif /* !STLSOFT_INCL_H_ATLBASE */

#ifndef STLSOFT_INCL_H_ATLAPP
# define STLSOFT_INCL_H_ATLAPP
# include <atlapp.h>    // WTL base header
#endif /* !STLSOFT_INCL_H_ATLAPP */


#if !defined(_WTL_VER) || \
    _WTL_VER < 0x0310
# error WTLSTL supports WTL version 3.1 and above only
#endif /* _WTL_VER < 0x0310 */


/* /////////////////////////////////////////////////////////////////////////
 * STLSoft version compatibility check(s)
 */

#if _STLSOFT_VER < 0x010a019a
# error This version of the WTLSTL libraries requires STLSoft version 1.10.1 beta 26, or later
#endif /* _STLSOFT_VER */

/* /////////////////////////////////////////////////////////////////////////
 * compiler compatibility
 *
 * Currently the only compilers supported by the WTLSTL libraries are
 *
 * Borland C++ 5.5, 5.51, 5.6
 * Digital Mars C/C++ 8.26 - 8.32
 * Metrowerks 2.4 & 3.0 (CodeWarrior 7.0 & 8.0)
 * Intel C/C++ 6.0
 * Visual C++ 5.0, 6.0, 7.0
 */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
/* Borland C++ */
# if __BORLANDC__ < 0x0550
#  error Versions of Borland C++ prior to 5.5 are not supported by the WTLSTL libraries
# endif /* __BORLANDC__ */

#elif defined(STLSOFT_COMPILER_IS_DMC)
/* Digital Mars C/C++ */
# if __DMC__ < 0x0826
#  error Versions of Digital Mars C/C++ prior to 8.26 are not supported by the WTLSTL libraries
# endif /* __DMC__ */

#elif defined(STLSOFT_COMPILER_IS_INTEL)
/* Intel C++ */
# if (__INTEL_COMPILER < 600)
#  error Versions of Intel C++ prior to 6.0 are not supported by the WTLSTL libraries
# endif /* __INTEL_COMPILER */

#elif defined(STLSOFT_COMPILER_IS_MWERKS)
/* Metrowerks C++ */
# if (__MWERKS__ & 0xFF00) < 0x2400
#  error Versions of Metrowerks CodeWarrior C++ prior to 7.0 are not supported by the WTLSTL libraries
# endif /* __MWERKS__ */

#elif defined(STLSOFT_COMPILER_IS_MSVC)
/* Visual C++ */
# if _MSC_VER < 1100
#  error Versions of Visual C++ prior to 5.0 are not supported by the WTLSTL libraries
# endif /* _MSC_VER */

#else /* ? compiler */
/* No recognised compiler */
# ifdef _STLSOFT_FORCE_ANY_COMPILER
#  define _WTLSTL_COMPILER_IS_UNKNOWN
#  ifdef STLSOFT_COMPILE_VERBOSE
#   pragma message("Compiler is unknown to WTLSTL")
#  endif /* STLSOFT_COMPILE_VERBOSE */
# else /* ? _STLSOFT_FORCE_ANY_COMPILER */
#  error Currently only Borland C++, Digital Mars C/C++, Intel C/C++, Metrowerks CodeWarrior and Visual C++ compilers are supported by the WTLSTL libraries
# endif /* _STLSOFT_FORCE_ANY_COMPILER */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * contract enforcement
 *
 * The macro wtlstl_assert provides standard debug-mode assert functionality.
 */

/** Defines a runtime assertion
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or an assertion will be fired
 */
#define WTLSTL_ASSERT(expr)                 STLSOFT_ASSERT(expr)

/** Defines a runtime assertion, with message
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or an assertion will be fired
 * \param msg The literal character string message to be included in the assertion
 */
#define WTLSTL_MESSAGE_ASSERT(msg, expr)    STLSOFT_MESSAGE_ASSERT(msg, expr)

/** Defines a compile-time assertion
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or compilation will fail
 */
#define WTLSTL_STATIC_ASSERT(expr)          STLSOFT_STATIC_ASSERT(expr)

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define wtlstl_assert(expr)                WTLSTL_ASSERT(expr)
# define wtlstl_message_assert(msg, expr)   WTLSTL_MESSAGE_ASSERT(msg, expr)
# define wtlstl_static_assert(expr)         WTLSTL_STATIC_ASSERT(expr)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The WTLSTL components are contained within the wtlstl namespace. This is
 * usually an alias for stlsoft::wtlstl_project,
 *
 * When compilers support namespaces they are defined by default. They can be
 * undefined using a cascasing system, as follows:
 *
 * If STLSOFT_NO_NAMESPACES is defined, then WTLSTL_NO_NAMESPACES is defined.
 *
 * If WTLSTL_NO_NAMESPACES is defined, then WTLSTL_NO_NAMESPACE is defined.
 *
 * If WTLSTL_NO_NAMESPACE is defined, then the WTLSTL constructs are defined
 * in the global scope.
 *
 * If STLSOFT_NO_NAMESPACES, WTLSTL_NO_NAMESPACES and WTLSTL_NO_NAMESPACE are
 * all undefined but the symbol STLSOFT_NO_NAMESPACE is defined (whence the
 * namespace stlsoft does not exist), then the WTLSTL constructs are defined
 * within the wtlstl namespace. The definition matrix is as follows:
 *
 * STLSOFT_NO_NAMESPACE     WTLSTL_NO_NAMESPACE     wtlstl definition
 * ---------------------    --------------------    -----------------
 *  not defined              not defined             = stlsoft::wtlstl_project
 *  not defined              defined                 not defined
 *  defined                  not defined             wtlstl
 *  defined                  defined                 not defined
 *
 *
 *
 * The macro wtlstl_ns_qual() macro can be used to refer to elements in the
 * WTLSTL libraries irrespective of whether they are in the
 * stlsoft::wtlstl_project (or wtlstl) namespace or in the global namespace.
 *
 * Furthermore, some compilers do not support the standard library in the std
 * namespace, so the STLSOFT_NS_QUAL_STD() macro can be used to refer to elements
 * in the standard library irrespective of whether they are in the std namespace
 * or in the global namespace.
 */


/* /////////////////////////////////////
 * obsolete preprocessor symbol detection
 */

#ifdef _WTLSTL_NO_NAMESPACES
# if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#  pragma message("You have defined _WTLSTL_NO_NAMESPACES. This symbol is now deprecated, and may be ignored by a future release : instead define WTLSTL_NO_NAMESPACES")
# endif
# if !defined(WTLSTL_NO_NAMESPACES)
#  define WTLSTL_NO_NAMESPACES
# endif /* !WTLSTL_NO_NAMESPACES */
#endif /* _WTLSTL_NO_NAMESPACES */

#ifdef _WTLSTL_NO_NAMESPACE
# if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#  pragma message("You have defined _WTLSTL_NO_NAMESPACE. This symbol is now deprecated, and may be ignored by a future release : instead define WTLSTL_NO_NAMESPACE")
# endif
# if !defined(WTLSTL_NO_NAMESPACE)
#  define WTLSTL_NO_NAMESPACE
# endif /* !WTLSTL_NO_NAMESPACE */
#endif /* _WTLSTL_NO_NAMESPACE */


/* /////////////////////////////////////
 * namespace support discrimination
 */

/* No STLSoft namespaces means no WTLSTL namespaces */
#ifdef STLSOFT_NO_NAMESPACES
# define WTLSTL_NO_NAMESPACES
#endif /* STLSOFT_NO_NAMESPACES */

/* No WTLSTL namespaces means no wtlstl namespace */
#ifdef WTLSTL_NO_NAMESPACES
# define WTLSTL_NO_NAMESPACE
#endif /* WTLSTL_NO_NAMESPACES */

#ifdef WTLSTL_NO_NAMESPACES
# ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
#  if !defined(_WTLSTL_NO_NAMESPACES)
#   define _WTLSTL_NO_NAMESPACES
#  endif /* !_WTLSTL_NO_NAMESPACES */
# endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
#endif /* WTLSTL_NO_NAMESPACES */

#ifdef WTLSTL_NO_NAMESPACE
# ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
#  if !defined(_WTLSTL_NO_NAMESPACE)
#   define _WTLSTL_NO_NAMESPACE
#  endif /* !_WTLSTL_NO_NAMESPACE */
# endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
#endif /* WTLSTL_NO_NAMESPACE */


/* /////////////////////////////////////
 * declaration '*stl*' namespace
 */

#ifndef WTLSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::wtlstl */
/** The \c wtlstl namespace contains all components
 *   in the \ref group__project__wtlstl "WTLSTL" project.
 *
 * By default, the \c wtlstl namespace is actually an alias for
 * the namespace <code>stlsoft::wtlstl_project</code>, which is where all
 * the \ref group__project__wtlstl "WTLSTL" components actually reside. This
 * measure allows all components within the main the
 * \ref group__project__stlsoft "STLSoft" project (which are defined within
 * the \c stlsoft namespace) to be visible to all components
 * "within" the \c wtlstl namespace. (Otherwise, there would be a
 * whole lot of onerous qualification throughout the code of all
 * \ref group__projects "sub-projects".)
 *
 * \note If either/both of the symbols \c STLSOFT_NO_NAMESPACES
 * and \c WTLSTL_NO_NAMESPACE are defined, all
 * \ref group__project__wtlstl "WTLSTL" components will be defined in the
 * global namespace. Conversely, if the \c STLSOFT_NO_NAMESPACE
 * symbol (not to be confused with the
 * \c STLSOFT_NO_NAMESPACES symbol!) is defined - meaning that
 * all \ref group__project__stlsoft "main project" components are to be
 * defined in the global namespace, and \c WTLSTL_NO_NAMESPACE
 * is <b>not</b> defined, then all \ref group__project__wtlstl "WTLSTL"
 * components will be defined within a bona fide \c wtlstl
 * namespace.
 *
 * \note This is a vestige of compatibility with compilers with
 * no (or no sensible) namespace support that is maintained for reasons of
 * backwards compatiblity and because it is, in <i>rare circumstances</i>, a
 * useful facility.
 */
namespace wtlstl
{
# else
/* Define stlsoft::wtlstl_project */

namespace stlsoft
{

/** The WTLSTL namespace - \c wtlstl (aliased to \c stlsoft::wtlstl_project) - is
 * the namespace for the WTLSTL project.
 *
 */
namespace wtlstl_project
{

# endif /* STLSOFT_NO_NAMESPACE */
#else
STLSOFT_NS_USING(move_lhs_from_rhs)
#endif /* !WTLSTL_NO_NAMESPACE */

/** \def wtlstl_ns_qual(x)
 * Qualifies with <b>wtlstl::</b> if WTLSTL is using namespaces or, if not, does not qualify
 */

/** \def wtlstl_ns_using(x)
 * Declares a using directive (with respect to <b>wtlstl</b>) if WTLSTL is using namespaces or, if not, does nothing
 */

#ifndef WTLSTL_NO_NAMESPACE
# define WTLSTL_NS_QUAL(x)          ::wtlstl::x
# define WTLSTL_NS_USING(x)         using ::wtlstl::x;
#else
# define WTLSTL_NS_QUAL(x)          x
# define WTLSTL_NS_USING(x)
#endif /* !WTLSTL_NO_NAMESPACE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define wtlstl_ns_qual(x)                                  WTLSTL_NS_QUAL(x)
# define wtlstl_ns_using(x)                                 WTLSTL_NS_USING(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define wtlstl_ns_qual_std(x)                              STLSOFT_NS_QUAL_STD(x)
# define wtlstl_ns_using_std(x)                             STLSOFT_NS_USING_STD(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */

/** \def wtlstl_ns_qual_atl(x)
 * Qualifies with <b>ATL::</b> if WTLSTL is being translated in the context of ATL being within the <b>ATL</b> namespace or, if not, does not qualify
 */

/** \def wtlstl_ns_using_atl(x)
 * Declares a using directive (with respect to <b>ATL</b>) if WTLSTL is being translated in the context of ATL being within the <b>ATL</b> namespace or, if not, does nothing
 */

#ifndef ATL_NO_NAMESPACE
# define WTLSTL_NS_QUAL_ATL(x)       ::ATL::x
# define WTLSTL_NS_USING_ATL(x)      using ::ATL::x;
#else
# define WTLSTL_NS_QUAL_ATL(x)       x
# define WTLSTL_NS_USING_ATL(x)
#endif /* !ATL_NO_NAMESPACE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define wtlstl_ns_qual_atl(x)                              WTLSTL_NS_QUAL_ATL(x)
# define wtlstl_ns_using_atl(x)                             WTLSTL_NS_USING_ATL(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 *
 * The WTLSTL uses a number of typedefs to aid in compiler-independence in the
 * libraries' main code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

typedef STLSOFT_NS_QUAL(ss_char_a_t)        ws_char_a_t;    //!< Ansi char type
typedef STLSOFT_NS_QUAL(ss_char_w_t)        ws_char_w_t;    //!< Unicode char type
typedef STLSOFT_NS_QUAL(ss_sint8_t)         ws_sint8_t;     //!< 8-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint8_t)         ws_uint8_t;     //!< 8-bit unsigned integer
typedef STLSOFT_NS_QUAL(ss_int16_t)         ws_int16_t;     //!< 16-bit integer
typedef STLSOFT_NS_QUAL(ss_sint16_t)        ws_sint16_t;    //!< 16-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint16_t)        ws_uint16_t;    //!< 16-bit unsigned integer
typedef STLSOFT_NS_QUAL(ss_int32_t)         ws_int32_t;     //!< 32-bit integer
typedef STLSOFT_NS_QUAL(ss_sint32_t)        ws_sint32_t;    //!< 32-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint32_t)        ws_uint32_t;    //!< 32-bit unsigned integer
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
typedef STLSOFT_NS_QUAL(ss_int64_t)         ws_int64_t;     //!< 64-bit integer
typedef STLSOFT_NS_QUAL(ss_sint64_t)        ws_sint64_t;    //!< 64-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint64_t)        ws_uint64_t;    //!< 64-bit unsigned integer
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
typedef STLSOFT_NS_QUAL(ss_int_t)           ws_int_t;       //!< integer
typedef STLSOFT_NS_QUAL(ss_sint_t)          ws_sint_t;      //!< signed integer
typedef STLSOFT_NS_QUAL(ss_uint_t)          ws_uint_t;      //!< unsigned integer
typedef STLSOFT_NS_QUAL(ss_long_t)          ws_long_t;      //!< long
typedef STLSOFT_NS_QUAL(ss_bool_t)          ws_bool_t;      //!< bool
typedef DWORD                               ws_dword_t;     //!< dword
typedef STLSOFT_NS_QUAL(ss_size_t)          ws_size_t;      //!< size
typedef STLSOFT_NS_QUAL(ss_ptrdiff_t)       ws_ptrdiff_t;   //!< ptr diff
typedef STLSOFT_NS_QUAL(ss_streampos_t)     ws_streampos_t; //!< streampos
typedef STLSOFT_NS_QUAL(ss_streamoff_t)     ws_streamoff_t; //!< streamoff

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * values
 *
 * Since the boolean type may not be supported natively on all compilers, the
 * values of true and false may also not be provided. Hence the values of
 * ws_true_v and ws_false_v are defined, and are used in all code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#define ws_true_v                                           ss_true_v
#define ws_false_v                                          ss_false_v

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/* /////////////////////////////////////////////////////////////////////////
 * code modification macros
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/* Exception signatures. */
# define wtlstl_throw_0()                               stlsoft_throw_0()
# define wtlstl_throw_1(x1)                             stlsoft_throw_1(x1)
# define wtlstl_throw_2(x1, x2)                         stlsoft_throw_2(x1, x2)
# define wtlstl_throw_3(x1, x2, x3)                     stlsoft_throw_3(x1, x2, x3)
# define wtlstl_throw_4(x1, x2, x3, x4)                 stlsoft_throw_4(x1, x2, x3, x4)
# define wtlstl_throw_5(x1, x2, x3, x4, x5)             stlsoft_throw_5(x1, x2, x3, x4, x5)
# define wtlstl_throw_6(x1, x2, x3, x4, x5, x6)         stlsoft_throw_6(x1, x2, x3, x4, x5, x6)
# define wtlstl_throw_7(x1, x2, x3, x4, x5, x6, x7)     stlsoft_throw_7(x1, x2, x3, x4, x5, x6, x7)
# define wtlstl_throw_8(x1, x2, x3, x4, x5, x6, x7, x8) stlsoft_throw_8(x1, x2, x3, x4, x5, x6, x7, x8)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WTLSTL_NUM_ELEMENTS(ar)                        STLSOFT_NUM_ELEMENTS(ar)
# define wtlstl_num_elements(ar)                        WTLSTL_NUM_ELEMENTS(ar)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** [DEPRECATED] Destroys the given instance \c p of the given type (\c t and \c type)
 *
 * \deprecated This is <b>heavily</b> deprecated in favour of \ref STLSOFT_DESTROY_INSTANCE().
 */
#define wtlstl_destroy_instance(t, type, p)             STLSOFT_DESTROY_INSTANCE(t, type, p)

/** [DEPRECATED] Generates an opaque type with the name \c _htype
 *
 * \deprecated This is <b>heavily</b> deprecated in favour of \ref STLSOFT_GEN_OPAQUE().
 */
#define wtlstl_gen_opaque(htype)                        STLSOFT_GEN_OPAQUE(htype)

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WTLSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace wtlstl
# else
} // namespace wtlstl_project
} // namespace stlsoft
namespace wtlstl = ::stlsoft::wtlstl_project;
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WTLSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WTLSTL_INCL_WTLSTL_HPP_WTLSTL */

/* ///////////////////////////// end of file //////////////////////////// */

