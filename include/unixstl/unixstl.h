/* /////////////////////////////////////////////////////////////////////////
 * File:    unixstl/unixstl.h
 *
 * Purpose: Root header for the UNIXSTL libraries. Performs compiler and
 *          platform discriminations, and definitions of types.
 *
 * Created: 15th January 2002
 * Updated: 28th May 2025
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


#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
#define UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
#define UNIXSTL_INCL_H_UNIXSTL

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_H_UNIXSTL_MAJOR    3
# define UNIXSTL_VER_UNIXSTL_H_UNIXSTL_MINOR    11
# define UNIXSTL_VER_UNIXSTL_H_UNIXSTL_REVISION 1
# define UNIXSTL_VER_UNIXSTL_H_UNIXSTL_EDIT     127
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file unixstl/unixstl.h
 *
 * \brief [C, C++] Root header for the
 * \ref group__project__unixstl "UNIXSTL" project.
 */


/* /////////////////////////////////////////////////////////////////////////
 * UNIXSTL version
 *
 * The libraries version information is comprised of major, minor and revision
 * components.
 *
 * The major version is denoted by the _UNIXSTL_VER_MAJOR preprocessor symbol.
 * A change to the major version component implies that a dramatic change has
 * occurred in the libraries, such that considerable changes to source dependent
 * on previous versions would need to be effected.
 *
 * The minor version is denoted by the _UNIXSTL_VER_MINOR preprocessor symbol.
 * Changes to the minor version component imply that a significant change has
 * occurred to the libraries, either in the addition of new functionality or in
 * the destructive change to one or more components such that recomplilation and
 * code change may be necessitated.
 *
 * The revision version is denoted by the _UNIXSTL_VER_REVISION preprocessor
 * symbol. Changes to the revision version component imply that a bug has been
 * fixed. Dependent code should be recompiled in order to pick up the changes.
 *
 * In addition to the individual version symbols - _UNIXSTL_VER_MAJOR,
 * _UNIXSTL_VER_MINOR and _UNIXSTL_VER_REVISION - a composite symbol _UNIXSTL_VER
 * is defined, where the upper 8 bits are 0, bits 16-23 represent the major
 * component,  bits 8-15 represent the minor component, and bits 0-7 represent
 * the revision component.
 *
 * Each release of the libraries will bear a different version, and that version
 * will also have its own symbol: Version 1.0.1 specifies _UNIXSTL_VER_1_0_1.
 *
 * Thus the symbol _UNIXSTL_VER may be compared meaningfully with a specific
 * version symbol, e.g.# if _UNIXSTL_VER >= _UNIXSTL_VER_1_0_1
 */

/** \def _UNIXSTL_VER_MAJOR
 * The major version number of UNIXSTL
 */

/** \def _UNIXSTL_VER_MINOR
 * The minor version number of UNIXSTL
 */

/** \def _UNIXSTL_VER_REVISION
 * The revision version number of UNIXSTL
 */

/** \def _UNIXSTL_VER
 * The current composite version number of UNIXSTL
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _UNIXSTL_VER_0_9_1     0x00000901  /*!< Version 0.9.1 */
# define _UNIXSTL_VER_0_9_2     0x00000902  /*!< Version 0.9.2 */
# define _UNIXSTL_VER_1_0_1     0x00010001  /*!< Version 1.0.1 */
# define _UNIXSTL_VER_1_0_2     0x00010002  /*!< Version 1.0.2 */
# define _UNIXSTL_VER_1_0_3     0x00010003  /*!< Version 1.0.3 */
# define _UNIXSTL_VER_1_1_1     0x00010101  /*!< Version 1.1.1 */
# define _UNIXSTL_VER_1_2_1     0x00010201  /*!< Version 1.2.1 */
# define _UNIXSTL_VER_1_3_1     0x00010301  /*!< Version 1.3.1 */
# define _UNIXSTL_VER_1_4_1     0x00010401  /*!< Version 1.4.1 */
# define _UNIXSTL_VER_1_5_1     0x00010501  /*!< Version 1.5.1 */
# define _UNIXSTL_VER_1_6_1     0x00010601  /*!< Version 1.6.1 (with STLSoft 1.9.1) */
# define _UNIXSTL_VER_1_6_2     0x00010602  /*!< Version 1.6.2 (with STLSoft 1.9.7) */
# define _UNIXSTL_VER_1_6_3     0x00010603  /*!< Version 1.6.3 (with STLSoft 1.9.9) */
# define _UNIXSTL_VER_1_6_4     0x00010604  /*!< Version 1.6.4 (with STLSoft 1.9.17) */
# define _UNIXSTL_VER_1_6_5     0x00010605  /*!< Version 1.6.5 (with STLSoft 1.9.25) */
# define _UNIXSTL_VER_1_6_6     0x00010606  /*!< Version 1.6.6 (with STLSoft 1.9.29) */
# define _UNIXSTL_VER_1_6_7     0x010607ff  /*!< Version 1.6.7 (with STLSoft 1.9.31) */
# define _UNIXSTL_VER_1_6_8     0x010608ff  /*!< Version 1.6.8 (with STLSoft 1.9.32) */
# define _UNIXSTL_VER_1_7_1     0x010701ff  /*!< Version 1.7.1 (with STLSoft 1.9.33) */
# define _UNIXSTL_VER_1_7_2     0x010702ff  /*!< Version 1.7.2 (with STLSoft 1.9.37) */
# define _UNIXSTL_VER_1_7_3     0x010703ff  /*!< Version 1.7.3 (with STLSoft 1.9.92) */
# define _UNIXSTL_VER_1_7_4     0x010704ff  /*!< Version 1.7.4 (with STLSoft 1.9.108) */
# define _UNIXSTL_VER_1_7_5     0x010705ff  /*!< Version 1.7.5 (with STLSoft 1.9.113) */
# define _UNIXSTL_VER_1_7_6     0x010706ff  /*!< Version 1.7.6 (with STLSoft 1.9.119) */
# define _UNIXSTL_VER_1_8_1_B01 0x01080181  /*!< Version 1.8.1 beta 1 (with STLSoft 1.10.1 beta 1) */
# define _UNIXSTL_VER_1_8_1_B02 0x01080182  /*!< Version 1.8.1 beta 2 (with STLSoft 1.10.1 beta 23) */
# define _UNIXSTL_VER_1_8_1_B03 0x01080183  /*!< Version 1.8.1 beta 3 (with STLSoft 1.10.1 beta 25) */
# define _UNIXSTL_VER_1_8_1_B04 0x01080184  /*!< Version 1.8.1 beta 4 (with STLSoft 1.10.1 beta 26) */
# define _UNIXSTL_VER_1_8_1     0x010801ff  /*!< Version 1.8.1 (with STLSoft 1.10.3) */
# define _UNIXSTL_VER_1_8_2     0x010802ff  /*!< Version 1.8.2 (with STLSoft 1.10.4) */
# define _UNIXSTL_VER_1_8_3     0x010803ff  /*!< Version 1.8.3 (with STLSoft 1.10.5) */
# define _UNIXSTL_VER_1_8_3     0x010803ff  /*!< Version 1.8.3 (with STLSoft 1.10.5) */
# define _UNIXSTL_VER_1_8_4     0x010804ff  /*!< Version 1.8.4 (with STLSoft 1.11.1 alpha 8) */
# define _UNIXSTL_VER_1_8_5     0x010805ff  /*!< Version 1.8.5 (with STLSoft 1.11.1 alpha 12) */
# define _UNIXSTL_VER_1_8_6_A01 0x01080641  /*!< Version 1.8.8 alpha 1 (with STLSoft 1.11.1 alpha 17) */
# define _UNIXSTL_VER_1_8_6_B01 0x01080681  /*!< Version 1.8.8 beta 1 (with STLSoft 1.11.1 beta 2) */
# define _UNIXSTL_VER_1_8_6_B02 0x01080682  /*!< Version 1.8.8 beta 2 (with STLSoft 1.11.1 beta 3) */
# define _UNIXSTL_VER_1_8_6_B03 0x01080683  /*!< Version 1.8.8 beta 3 (with STLSoft 1.11.1 beta 7) */
# define _UNIXSTL_VER_1_8_6_B04 0x01080684  /*!< Version 1.8.8 beta 4 (with STLSoft 1.11.1 beta 8) */
# define _UNIXSTL_VER_1_8_6_B05 0x01080685  /*!< Version 1.8.8 beta 5 (with STLSoft 1.11.1 release candidate 2) */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#define _UNIXSTL_VER_MAJOR      1
#define _UNIXSTL_VER_MINOR      8
#define _UNIXSTL_VER_REVISION   6
#define _UNIXSTL_VER            _UNIXSTL_VER_1_8_6_B05


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
 * STLSoft version compatibility check(s)
 */

#if _STLSOFT_VER < 0x010b0187
# error This version of the UNIXSTL libraries requires STLSoft version 1.11.1 beta 7, or later
#endif /* _STLSOFT_VER */


/* /////////////////////////////////////////////////////////////////////////
 * compiler compatibility
 *
 * Currently the only compilers supported by the UNIXSTL libraries are
 *
 * GCC version 2.95 or later
 * Intel C/C++ 6.0 or later
 * Sun Pro C & Sun Pro C++ versions 5.9.x or later
 */

#if 0

#elif defined(STLSOFT_COMPILER_IS_CLANG)
 /* ******************************* Clang ****************************** */
# if __clang_major__ < 6
#  error Versions of Clang C++ prior to 6 are not supported by the UNIXSTL libraries
# endif /* __COMO_VERSION__ */

#elif defined(STLSOFT_COMPILER_IS_COMO)
 /* ******************************* Comeau ****************************** */
# if __COMO_VERSION__ < 4300
#  error Versions of Comeau C++ prior to 4.3.0.1 are not supported by the UNIXSTL libraries
# endif /* __COMO_VERSION__ */

#elif defined(STLSOFT_COMPILER_IS_GCC)
 /* ******************************** GCC ******************************** */
# if __GNUC__ < 2 || \
     (  __GNUC__ == 2 && \
        __GNUC_MINOR__ < 95)
#  error Versions of GNU C/C++ prior to 2.95 are not supported by the UNIXSTL libraries
# endif /* __GNUC__ */

#elif defined(STLSOFT_COMPILER_IS_INTEL)
 /* ******************************* Intel ******************************* */
# if (__INTEL_COMPILER < 700)
#  error Versions of Intel C++ prior to 7.0 are not supported by the UNIXSTL libraries
# endif /* __INTEL_COMPILER */

#elif defined(STLSOFT_COMPILER_IS_SUNPRO)
 /* ******************************* Sun Pro ***************************** */
# ifdef __cplusplus
#  if ((__SUNPRO_CC & 0xFFF0) < 0x0590)
#   error Versions of Sun Pro C++ prior to 5.9 are not supported by the UNIXSTL libraries
#  endif /* __SUNPRO_CC */
# else /* ? __cplusplus */
#  if ((__SUNPRO_C & 0xFFF0) < 0x0590)
#   error Versions of Sun Pro C prior to 5.9 are not supported by the UNIXSTL libraries
#  endif /* __SUNPRO_CC */
# endif /* __cplusplus */

#else
 /* *********************** No recognised compiler ********************** */
# ifdef _STLSOFT_FORCE_ANY_COMPILER
#  define _UNIXSTL_COMPILER_IS_UNKNOWN
#  ifdef STLSOFT_COMPILE_VERBOSE
#   pragma message("Compiler is unknown to UNIXSTL")
#  endif /* STLSOFT_COMPILE_VERBOSE */
# else
#  error Currently only the Clang, Comeau, GCC, Intel and Sun Pro C/C++ compilers are supported by the UNIXSTL libraries. To use other, possibly untested, compilers, define _STLSOFT_FORCE_ANY_COMPILER
# endif /* _STLSOFT_FORCE_ANY_COMPILER */
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * architecture
 *
 * The UNIX architecture.
 */

#ifdef UNIXSTL_ARCH_IS_ARM64
# undef UNIXSTL_ARCH_IS_ARM64
#endif /* UNIXSTL_ARCH_IS_ARM64 */
#ifdef UNIXSTL_ARCH_IS_IA64
# undef UNIXSTL_ARCH_IS_IA64
#endif /* UNIXSTL_ARCH_IS_IA64 */
#ifdef UNIXSTL_ARCH_IS_X86
# undef UNIXSTL_ARCH_IS_X86
#endif /* UNIXSTL_ARCH_IS_X86 */
#ifdef UNIXSTL_ARCH_IS_X64
# undef UNIXSTL_ARCH_IS_X64
#endif /* UNIXSTL_ARCH_IS_X64 */

#ifdef UNIXSTL_ARCH_IS_INTEL
# undef UNIXSTL_ARCH_IS_INTEL
#endif /* UNIXSTL_ARCH_IS_INTEL */
#ifdef UNIXSTL_ARCH_IS_POWERPC
# undef UNIXSTL_ARCH_IS_POWERPC
#endif /* UNIXSTL_ARCH_IS_POWERPC */
#ifdef UNIXSTL_ARCH_IS_ALPHA
# undef UNIXSTL_ARCH_IS_ALPHA
#endif /* UNIXSTL_ARCH_IS_ALPHA */
#ifdef UNIXSTL_ARCH_IS_HPPA
# undef UNIXSTL_ARCH_IS_HPPA
#endif /* UNIXSTL_ARCH_IS_HPPA */
#ifdef UNIXSTL_ARCH_IS_SPARC
# undef UNIXSTL_ARCH_IS_SPARC
#endif /* UNIXSTL_ARCH_IS_SPARC */
#ifdef UNIXSTL_ARCH_IS_UNKNOWN
# undef UNIXSTL_ARCH_IS_UNKNOWN
#endif /* UNIXSTL_ARCH_IS_UNKNOWN */

/*
Alpha
ARM64
HP/PA
IA-64
PowerPC
Sparc
x86-64

80x86
*/

#if 0
#elif 0 ||\
      defined(__alpha__) ||\
      defined(__alpha) ||\
      defined(_M_ALPHA) ||\
      0

# define UNIXSTL_ARCH_IS_ALPHA
# define UNIXSTL_ARCH_LABEL_STRING                          "Alpha"
#elif 0 ||\
      defined(__aarch64__) ||\
      defined(_M_ARM64) ||\
      0

# define UNIXSTL_ARCH_IS_INTEL
# define UNIXSTL_ARCH_IS_ARM64
# define UNIXSTL_ARCH_LABEL_STRING                          "ARM64"
#elif 0 ||\
      defined(__hppa__) ||\
      defined(__hppa) ||\
      0

# define UNIXSTL_ARCH_IS_HPPA
# define UNIXSTL_ARCH_LABEL_STRING                          "HP/PA"
#elif 0 ||\
      defined(__ia64__) ||\
      defined(__ia64) ||\
      defined(_IA64_) ||\
      defined(_M_IA64) ||\
      0

# define UNIXSTL_ARCH_IS_INTEL
# define UNIXSTL_ARCH_IS_IA64
# define UNIXSTL_ARCH_LABEL_STRING                          "IA-64"
#elif 0 ||\
      defined(__POWERPC__) ||\
      defined(__ppc__) ||\
      defined(__ppc) ||\
      defined(_M_PPC) ||\
      defined(_POWER) ||\
      0

# define UNIXSTL_ARCH_IS_POWERPC
# define UNIXSTL_ARCH_LABEL_STRING                          "PowerPC"
#elif 0 ||\
      defined(__sparc__) ||\
      defined(__sparc) ||\
      0

 /* TODO: Separate out arch-family and archs (incl. Sparc32 and Sparc64) */
# define UNIXSTL_ARCH_IS_SPARC
# define UNIXSTL_ARCH_LABEL_STRING                          "Sparc"
#elif 0 ||\
      defined(__amd64__) ||\
      defined(__amd64) ||\
      defined(__x86_64__) ||\
      defined(__x86_64) ||\
      defined(_AMD64_) ||\
      defined(_M_AMD64) ||\
      defined(_M_X64) ||\
      0

# define UNIXSTL_ARCH_IS_INTEL
# define UNIXSTL_ARCH_IS_X64
# define UNIXSTL_ARCH_LABEL_STRING                          "x86-64"
#elif 0 ||\
      defined(__i386__) ||\
      defined(__i386) ||\
      defined(__X86__) ||\
      defined(_M_IX86) ||\
      defined(_X86_) ||\
      0

# define UNIXSTL_ARCH_IS_INTEL
# define UNIXSTL_ARCH_IS_X86
# define UNIXSTL_ARCH_LABEL_STRING                          "80x86"
#else /* ? arch */

# define UNIXSTL_ARCH_IS_UNKNOWN
# define UNIXSTL_ARCH_LABEL_STRING                          "Unknown"
#endif /* ? arch */


/* /////////////////////////////////////////////////////////////////////////
 * operating system family
 *
 * In some circumstances more than one of these may be defined.
 *
 * Some of this os-discrimination is provided by SourceForge (http://predef.sourceforge.net/preos.html)
 */

#ifdef UNIXSTL_OSFAMILY_IS_BSD
# undef UNIXSTL_OSFAMILY_IS_BSD
#endif /* UNIXSTL_OSFAMILY_IS_BSD */
#ifdef UNIXSTL_OSFAMILY_IS_SVR4
# undef UNIXSTL_OSFAMILY_IS_SVR4
#endif /* UNIXSTL_OSFAMILY_IS_SVR4 */


#if 0 ||\
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    defined(__bsdi__) || \
    defined(_SYSTYPE_BSD) ||\
    0
# define UNIXSTL_OSFAMILY_IS_BSD
#endif /* bsd */

#if 0 ||\
    defined(__sysv__) || \
    defined(__SVR4) || \
    defined(__svr4__) || \
    defined(_SYSTYPE_SVR4) ||\
    0
# define UNIXSTL_OSFAMILY_IS_SVR4
#endif /* SVR4 */


/* /////////////////////////////////////////////////////////////////////////
 * operating system
 *
 * The UNIX operating system.
 *
 * Some of this os-discrimination is provided by SourceForge (http://predef.sourceforge.net/preos.html)
 */

#ifdef UNIXSTL_OS_IS_APPLE
# undef UNIXSTL_OS_IS_APPLE
#endif /* UNIXSTL_OS_IS_APPLE */
#ifdef UNIXSTL_OS_IS_AIX
# undef UNIXSTL_OS_IS_AIX
#endif /* UNIXSTL_OS_IS_AIX */
#ifdef UNIXSTL_OS_IS_FREEBSD
# undef UNIXSTL_OS_IS_FREEBSD
#endif /* UNIXSTL_OS_IS_FREEBSD */
#ifdef UNIXSTL_OS_IS_HPUX
# undef UNIXSTL_OS_IS_HPUX
#endif /* UNIXSTL_OS_IS_HPUX */
#ifdef UNIXSTL_OS_IS_LINUX
# undef UNIXSTL_OS_IS_LINUX
#endif /* UNIXSTL_OS_IS_LINUX */
#ifdef UNIXSTL_OS_IS_MACOSX
# undef UNIXSTL_OS_IS_MACOSX
#endif /* UNIXSTL_OS_IS_MACOSX */
#ifdef UNIXSTL_OS_IS_NETBSD
# undef UNIXSTL_OS_IS_NETBSD
#endif /* UNIXSTL_OS_IS_NETBSD */
#ifdef UNIXSTL_OS_IS_OPENBSD
# undef UNIXSTL_OS_IS_OPENBSD
#endif /* UNIXSTL_OS_IS_OPENBSD */
#ifdef UNIXSTL_OS_IS_SOLARIS
# undef UNIXSTL_OS_IS_SOLARIS
#endif /* UNIXSTL_OS_IS_SOLARIS */
#ifdef UNIXSTL_OS_IS_FREEBSD
# undef UNIXSTL_OS_IS_FREEBSD
#endif /* UNIXSTL_OS_IS_FREEBSD */
#ifdef UNIXSTL_OS_IS_UNKNOWN
# undef UNIXSTL_OS_IS_UNKNOWN
#endif /* UNIXSTL_OS_IS_UNKNOWN */

#if 0
#elif 0 ||\
      defined(__APPLE__) ||\
      defined(__MACH__) ||\
      defined(__MACOSX__) ||\
      0
# define UNIXSTL_OS_IS_APPLE
# define UNIXSTL_OS_IS_MACOSX
#elif defined(_AIX)
# define UNIXSTL_OS_IS_AIX
#elif defined(__FreeBSD__)
# define UNIXSTL_OS_IS_FREEBSD
#elif 0 ||\
      defined(hpux) ||\
      defined(_hpux) ||\
      0
# define UNIXSTL_OS_IS_HPUX
#elif 0 ||\
      defined(__linux__) ||\
      defined(__linux) ||\
      defined(linux) ||\
      0
# define UNIXSTL_OS_IS_LINUX
#elif defined(__NetBSD__)
# define UNIXSTL_OS_IS_NETBSD
#elif defined(__OpenBSD__)
# define UNIXSTL_OS_IS_OPENBSD
#elif 0 ||\
      defined(sun) ||\
      defined(__sun) ||\
      0
# if defined(UNIXSTL_OSFAMILY_IS_SVR4)
#  define UNIXSTL_OS_IS_SOLARIS
# else /* ? UNIXSTL_OSFAMILY_IS_SVR4 */
#  define UNIXSTL_OS_IS_SUNOS
# endif /* UNIXSTL_OSFAMILY_IS_SVR4 */
#else /* ? operating system */
# define UNIXSTL_OS_IS_UNKNOWN
#endif /* ? operating system */


/* /////////////////////////////////////////////////////////////////////////
 * contract enforcement
 *
 * The macro unixstl_assert provides standard debug-mode assert functionality.
 */

/** Defines a runtime assertion
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or an assertion will be fired
 */
#if defined(UNIXSTL_OS_IS_MACOSX) && \
    defined(__assert)
# define UNIXSTL_ASSERT(expr)                               ((void)((expr) ? 0 : (__assert(#expr, __FILE__, __LINE__), 0)))
#else /* ? UNIXSTL_OS_IS_MACOSX */
# define UNIXSTL_ASSERT(expr)                               STLSOFT_ASSERT(expr)
#endif /* UNIXSTL_OS_IS_MACOSX */

/** Defines a runtime assertion, with message
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or an assertion will be fired
 * \param msg The literal character string message to be included in the assertion
 */
#define UNIXSTL_MESSAGE_ASSERT(msg, expr)                   STLSOFT_MESSAGE_ASSERT(msg, expr)

/** Defines a compile-time assertion
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or compilation will fail
 */
#define UNIXSTL_STATIC_ASSERT(expr)                         STLSOFT_STATIC_ASSERT(expr)


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define unixstl_assert(expr)                               UNIXSTL_ASSERT(expr)
# define unixstl_message_assert(msg, expr)                  UNIXSTL_MESSAGE_ASSERT(msg, expr)
# define unixstl_static_assert(expr)                        UNIXSTL_STATIC_ASSERT(expr)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The UNIXSTL components are contained within the unixstl namespace. This is
 * usually an alias for stlsoft::unixstl_project,
 *
 * When compilers support namespaces they are defined by default. They can be
 * undefined using a cascasing system, as follows:
 *
 * If STLSOFT_NO_NAMESPACES is defined, then UNIXSTL_NO_NAMESPACES is defined.
 *
 * If UNIXSTL_NO_NAMESPACES is defined, then UNIXSTL_NO_NAMESPACE is defined.
 *
 * If UNIXSTL_NO_NAMESPACE is defined, then the UNIXSTL constructs are defined
 * in the global scope.
 *
 * If STLSOFT_NO_NAMESPACES, UNIXSTL_NO_NAMESPACES and UNIXSTL_NO_NAMESPACE are
 * all undefined but the symbol STLSOFT_NO_NAMESPACE is defined (whence the
 * namespace stlsoft does not exist), then the UNIXSTL constructs are defined
 * within the unixstl namespace. The definition matrix is as follows:
 *
 * STLSOFT_NO_NAMESPACE     UNIXSTL_NO_NAMESPACE    unixstl definition
 * ---------------------    --------------------    -----------------
 *  not defined              not defined             = stlsoft::unixstl_project
 *  not defined              defined                 not defined
 *  defined                  not defined             unixstl
 *  defined                  defined                 not defined
 *
 *
 *
 * The macro UNIXSTL_NS_QUAL() macro can be used to refer to elements in the
 * UNIXSTL libraries irrespective of whether they are in the
 * stlsoft::unixstl_project (or unixstl) namespace or in the global namespace.
 *
 * Furthermore, some compilers do not support the standard library in the std
 * namespace, so the STLSOFT_NS_QUAL_STD() macro can be used to refer to elements
 * in the standard library irrespective of whether they are in the std namespace
 * or in the global namespace.
 */


/* /////////////////////////////////////
 * obsolete preprocessor symbol detection
 */

#ifdef _UNIXSTL_NO_NAMESPACES
# if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#  pragma message("You have defined _UNIXSTL_NO_NAMESPACES. This symbol is now deprecated, and may be ignored by a future release : instead define UNIXSTL_NO_NAMESPACES")
# endif
# if !defined(UNIXSTL_NO_NAMESPACES)
#  define UNIXSTL_NO_NAMESPACES
# endif /* !UNIXSTL_NO_NAMESPACES */
#endif /* _UNIXSTL_NO_NAMESPACES */

#ifdef _UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#  pragma message("You have defined _UNIXSTL_NO_NAMESPACE. This symbol is now deprecated, and may be ignored by a future release : instead define UNIXSTL_NO_NAMESPACE")
# endif
# if !defined(UNIXSTL_NO_NAMESPACE)
#  define UNIXSTL_NO_NAMESPACE
# endif /* !UNIXSTL_NO_NAMESPACE */
#endif /* _UNIXSTL_NO_NAMESPACE */


/* /////////////////////////////////////
 * namespace support discrimination
 */

/* No STLSoft namespaces means no UNIXSTL namespaces */
#ifdef STLSOFT_NO_NAMESPACES
# define UNIXSTL_NO_NAMESPACES
#endif /* STLSOFT_NO_NAMESPACES */

/* No UNIXSTL namespaces means no unixstl namespace */
#ifdef UNIXSTL_NO_NAMESPACES
# define UNIXSTL_NO_NAMESPACE
#endif /* UNIXSTL_NO_NAMESPACES */

#ifdef UNIXSTL_NO_NAMESPACES
# ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
#  if !defined(_UNIXSTL_NO_NAMESPACES)
#   define _UNIXSTL_NO_NAMESPACES
#  endif /* !_UNIXSTL_NO_NAMESPACES */
# endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
#endif /* UNIXSTL_NO_NAMESPACES */

#ifdef UNIXSTL_NO_NAMESPACE
# ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
#  if !defined(_UNIXSTL_NO_NAMESPACE)
#   define _UNIXSTL_NO_NAMESPACE
#  endif /* !_UNIXSTL_NO_NAMESPACE */
# endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
#endif /* UNIXSTL_NO_NAMESPACE */


/* /////////////////////////////////////
 * declaration '*stl*' namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
/** The \c unixstl namespace contains all components
 *   in the \ref group__project__unixstl "UNIXSTL" project.
 *
 * By default, the \c unixstl namespace is actually an alias for
 * the namespace <code>stlsoft::unixstl_project</code>, which is where all
 * the \ref group__project__unixstl "UNIXSTL" components actually reside. This
 * measure allows all components within the main the
 * \ref group__project__stlsoft "STLSoft" project (which are defined within
 * the \c stlsoft namespace) to be visible to all components
 * "within" the \c unixstl namespace. (Otherwise, there would be a
 * whole lot of onerous qualification throughout the code of all
 * \ref group__projects "sub-projects".)
 *
 * \note If either/both of the symbols \c STLSOFT_NO_NAMESPACES
 * and \c UNIXSTL_NO_NAMESPACE are defined, all
 * \ref group__project__unixstl "UNIXSTL" components will be defined in the
 * global namespace. Conversely, if the \c STLSOFT_NO_NAMESPACE
 * symbol (not to be confused with the
 * \c STLSOFT_NO_NAMESPACES symbol!) is defined - meaning that
 * all \ref group__project__stlsoft "main project" components are to be
 * defined in the global namespace, and \c UNIXSTL_NO_NAMESPACE
 * is <b>not</b> defined, then all \ref group__project__unixstl "UNIXSTL"
 * components will be defined within a bona fide \c unixstl
 * namespace.
 *
 * \note This is a vestige of compatibility with compilers with
 * no (or no sensible) namespace support that is maintained for reasons of
 * backwards compatiblity and because it is, in <i>rare circumstances</i>, a
 * useful facility.
 */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */
namespace stlsoft
{
namespace unixstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#else
STLSOFT_NS_USING(move_lhs_from_rhs)
#endif /* !UNIXSTL_NO_NAMESPACE */

/** \def UNIXSTL_NS_QUAL(x)
 * Qualifies with <b>unixstl::</b> if UNIXSTL is using namespaces or, if not, does not qualify
 */

/** \def UNIXSTL_NS_USING(x)
 * Declares a using directive (with respect to <b>unixstl</b>) if UNIXSTL is using namespaces or, if not, does nothing
 */

#ifndef UNIXSTL_NO_NAMESPACE
# define UNIXSTL_NS_QUAL(x)                                 ::unixstl::x
# define UNIXSTL_NS_USING(x)                                using ::unixstl::x;
#else
# define UNIXSTL_NS_QUAL(x)                                 x
# define UNIXSTL_NS_USING(x)
#endif /* !UNIXSTL_NO_NAMESPACE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define unixstl_ns_qual(x)                                 UNIXSTL_NS_QUAL(x)
# define unixstl_ns_using(x)                                UNIXSTL_NS_USING(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define unixstl_ns_qual_std(x)                             STLSOFT_NS_QUAL_STD(x)
# define unixstl_ns_using_std(x)                            STLSOFT_NS_USING_STD(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 *
 * The UNIXSTL uses a number of typedefs to aid in compiler-independence in the
 * libraries' main code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
typedef STLSOFT_NS_QUAL(ss_char_a_t)                        us_char_a_t;    /*!< Ansi char type */
typedef STLSOFT_NS_QUAL(ss_char_w_t)                        us_char_w_t;    /*!< Unicode char type */
typedef STLSOFT_NS_QUAL(ss_sint8_t)                         us_sint8_t;     /*!< 8-bit signed integer */
typedef STLSOFT_NS_QUAL(ss_uint8_t)                         us_uint8_t;     /*!< 8-bit unsigned integer */
typedef STLSOFT_NS_QUAL(ss_int16_t)                         us_int16_t;     /*!< 16-bit integer */
typedef STLSOFT_NS_QUAL(ss_sint16_t)                        us_sint16_t;    /*!< 16-bit signed integer */
typedef STLSOFT_NS_QUAL(ss_uint16_t)                        us_uint16_t;    /*!< 16-bit unsigned integer */
typedef STLSOFT_NS_QUAL(ss_int32_t)                         us_int32_t;     /*!< 32-bit integer */
typedef STLSOFT_NS_QUAL(ss_sint32_t)                        us_sint32_t;    /*!< 32-bit signed integer */
typedef STLSOFT_NS_QUAL(ss_uint32_t)                        us_uint32_t;    /*!< 32-bit unsigned integer */
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
typedef STLSOFT_NS_QUAL(ss_int64_t)                         us_int64_t;     /*!< 64-bit integer */
typedef STLSOFT_NS_QUAL(ss_sint64_t)                        us_sint64_t;    /*!< 64-bit signed integer */
typedef STLSOFT_NS_QUAL(ss_uint64_t)                        us_uint64_t;    /*!< 64-bit unsigned integer */
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
typedef STLSOFT_NS_QUAL(ss_sint64_t)                        us_intptr_t;    /*!< integer capable of holding pointer without loss */
typedef STLSOFT_NS_QUAL(ss_sint64_t)                        us_sintptr_t;   /*!< signed integer capable of holding pointer without loss */
typedef STLSOFT_NS_QUAL(ss_uint64_t)                        us_uintptr_t;   /*!< unsigned integer capable of holding pointer without loss */
# else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
typedef STLSOFT_NS_QUAL(ss_sint32_t)                        us_intptr_t;    /*!< integer capable of holding pointer without loss */
typedef STLSOFT_NS_QUAL(ss_sint32_t)                        us_sintptr_t;   /*!< signed integer capable of holding pointer without loss */
typedef STLSOFT_NS_QUAL(ss_uint32_t)                        us_uintptr_t;   /*!< unsigned integer capable of holding pointer without loss */
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
typedef STLSOFT_NS_QUAL(ss_int_t)                           us_int_t;       /*!< integer */
typedef STLSOFT_NS_QUAL(ss_sint_t)                          us_sint_t;      /*!< signed integer */
typedef STLSOFT_NS_QUAL(ss_uint_t)                          us_uint_t;      /*!< unsigned integer */
typedef STLSOFT_NS_QUAL(ss_long_t)                          us_long_t;      /*!< long */
# if defined(__cplusplus)
typedef STLSOFT_NS_QUAL(ss_bool_t)                          us_bool_t;      /*!< bool */
# endif /* __cplusplus */
typedef STLSOFT_NS_QUAL(ss_size_t)                          us_size_t;      /*!< size */
typedef STLSOFT_NS_QUAL(ss_ptrdiff_t)                       us_ptrdiff_t;   /*!< ptr diff */
typedef STLSOFT_NS_QUAL(ss_streampos_t)                     us_streampos_t; /*!< streampos */
typedef STLSOFT_NS_QUAL(ss_streamoff_t)                     us_streamoff_t; /*!< streamoff */
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
typedef STLSOFT_NS_QUAL(ss_sint64_t)                        us_sptrint_t;
typedef STLSOFT_NS_QUAL(ss_uint64_t)                        us_uptrint_t;
# else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
typedef STLSOFT_NS_QUAL(ss_sint32_t)                        us_sptrint_t;
typedef STLSOFT_NS_QUAL(ss_uint32_t)                        us_uptrint_t;
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef UNIXSTL_NO_NAMESPACE
typedef us_char_a_t                                         char_a_t;       /*!< Ansi char type */
typedef us_char_w_t                                         char_w_t;       /*!< Unicode char type */
/* typedef us_int8_t                                           int8_t; */         /*!< 8-bit integer */
typedef us_sint8_t                                          sint8_t;        /*!< 8-bit signed integer */
typedef us_uint8_t                                          uint8_t;        /*!< 8-bit unsigned integer */
typedef us_int16_t                                          int16_t;        /*!< 16-bit integer */
typedef us_sint16_t                                         sint16_t;       /*!< 16-bit signed integer */
typedef us_uint16_t                                         uint16_t;       /*!< 16-bit unsigned integer */
typedef us_int32_t                                          int32_t;        /*!< 32-bit integer */
typedef us_sint32_t                                         sint32_t;       /*!< 32-bit signed integer */
typedef us_uint32_t                                         uint32_t;       /*!< 32-bit unsigned integer */
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
 typedef us_int64_t                                         int64_t;        /*!< 64-bit integer */
 typedef us_sint64_t                                        sint64_t;       /*!< 64-bit signed integer */
 typedef us_uint64_t                                        uint64_t;       /*!< 64-bit unsigned integer */
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
/* typedef us_short_t                                          short_t; */        /*!< short integer */
typedef us_int_t                                            int_t;          /*!< integer */
typedef us_sint_t                                           sint_t;         /*!< signed integer */
typedef us_uint_t                                           uint_t;         /*!< unsigned integer */
typedef us_long_t                                           long_t;         /*!< long integer */
/* typedef us_byte_t                                           byte_t; */         /*!< Byte */
typedef us_bool_t                                           bool_t;         /*!< bool */
# if !defined(STLSOFT_COMPILER_IS_DMC)
typedef us_streampos_t                                      streampos_t;    /*!< streampos */
typedef us_streamoff_t                                      streamoff_t;    /*!< streamoff */
# endif /* compiler */
#endif /* !UNIXSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * values
 *
 * Since the boolean type may not be supported natively on all compilers, the
 * values of true and false may also not be provided. Hence the values of
 * us_true_v and us_false_v are defined, and are used in all code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# define us_true_v                                          ss_true_v
# define us_false_v                                         ss_false_v
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * code modification macros
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/* Exception signatures. */
#define unixstl_throw_0()                                   stlsoft_throw_0()
#define unixstl_throw_1(x1)                                 stlsoft_throw_1(x1)
#define unixstl_throw_2(x1, x2)                             stlsoft_throw_2(x1, x2)
#define unixstl_throw_3(x1, x2, x3)                         stlsoft_throw_3(x1, x2, x3)
#define unixstl_throw_4(x1, x2, x3, x4)                     stlsoft_throw_4(x1, x2, x3, x4)
#define unixstl_throw_5(x1, x2, x3, x4, x5)                 stlsoft_throw_5(x1, x2, x3, x4, x5)
#define unixstl_throw_6(x1, x2, x3, x4, x5, x6)             stlsoft_throw_6(x1, x2, x3, x4, x5, x6)
#define unixstl_throw_7(x1, x2, x3, x4, x5, x6, x7)         stlsoft_throw_7(x1, x2, x3, x4, x5, x6, x7)
#define unixstl_throw_8(x1, x2, x3, x4, x5, x6, x7, x8)     stlsoft_throw_8(x1, x2, x3, x4, x5, x6, x7, x8)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_NUM_ELEMENTS(ar)                           STLSOFT_NUM_ELEMENTS(ar)
# define unixstl_num_elements(ar)                           UNIXSTL_NUM_ELEMENTS(ar)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** [DEPRECATED] Destroys the given instance \c p of the given type (\c t and \c type)
 *
 * \deprecated This is <b>heavily</b> deprecated in favour of \ref STLSOFT_DESTROY_INSTANCE().
 */
#define unixstl_destroy_instance(t, type, p)                STLSOFT_DESTROY_INSTANCE(t, type, p)

/** [DEPRECATED] Generates an opaque type with the name \c _htype
 *
 * \deprecated This is <b>heavily</b> deprecated in favour of \ref STLSOFT_GEN_OPAQUE().
 */
#define unixstl_gen_opaque(htype)                           STLSOFT_GEN_OPAQUE(htype)

/* ////////////////////////////////////////////////////////////////////// */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
namespace unixstl = ::stlsoft::unixstl_project;
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */

/* ///////////////////////////// end of file //////////////////////////// */

