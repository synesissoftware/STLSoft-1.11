/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/string/char_traits.hpp
 *
 * Purpose: char_traits classes.
 *
 * Created: 19th November 1998
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/char_traits.hpp
 *
 * \brief [C++] Definition of the stlsoft::stlsoft_char_traits and
 *  stlsoft::stlsoft_char_traits_safe traits classes
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_CHAR_TRAITS_MAJOR       4
# define STLSOFT_VER_STLSOFT_STRING_HPP_CHAR_TRAITS_MINOR       3
# define STLSOFT_VER_STLSOFT_STRING_HPP_CHAR_TRAITS_REVISION    2
# define STLSOFT_VER_STLSOFT_STRING_HPP_CHAR_TRAITS_EDIT        101
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 *
 * There is a degree of complexity with respect to the definition and use of
 * char_traits in the STLSoft libraries, depending on whether the std and/or
 * stlsoft namespaces are defined.
 *
 * 1. If neither std nor stlsoft namespaces are defined, then the standard
 * library char_traits is visible in the global namespace, and no definition is
 * provided in the stlsoft namespace. This is necessary to avoid a clash.
 *
 * 2. If std is defined, and the stlsoft namespace is not defined, then the
 * STLSoft definition of char_traits is provided, and exists in the global
 * namespace.
 *
 * 3. If std is not defined, and the stlsoft namespace is defined, then the
 * STLSoft definition of char_traits is provided, and exists in the stlsoft
 * namespace.
 *
 * 4. If both std and stlsoft namespaces are not defined, then the
 * STLSoft definition of char_traits is provided, and exists in the stlsoft
 * namespace.
 *
 * Also influencing this is whether the compiler/std-library actually provide
 * a char_traits type. GCC 2.95 does not. Presence of this is indicated by the
 * definition of STLSOFT_CF_std_char_traits_AVAILABLE
 *
 * Finally, DMC++ has a problem whereby, with the SGI libs, the specialisation
 * of char_traits in the global namespace clashes with stlsoft::char_traits<>.
 * This is a combination compiler/library bug, so the only thing we can do is
 * indicate to the STLSoft libs that ("std::")char_traits is unavailable, and
 * "use" the standard library one.
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_SIGN_TRAITS
# include <stlsoft/util/sign_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_SIGN_TRAITS */

#if defined(STLSOFT_CF_std_char_traits_AVAILABLE) && \
    defined(STLSOFT_NO_NAMESPACE) && \
    !defined(STLSOFT_CF_std_NAMESPACE)
# include <string>                  // for std::char_traits
#elif defined(STLSOFT_COMPILER_IS_DMC) && \
      !defined(STLSOFT_CF_std_NAMESPACE)
# include <string>                  // for std::char_traits
#endif /* !::stlsoft && !::std */

#if !defined(STLSOFT_NO_CHAR_TRAITS_LIBRARY_CALLS) || \
    defined(STLSOFT_DEBUG)
# include <string.h>
# include <wchar.h>
# if defined(STLSOFT_COMPILER_IS_BORLAND) && \
     __BORLANDC__ >= 0x0560
#  include <mem.h>
#endif /* compiler */
#endif /* !STLSOFT_NO_CHAR_TRAITS_LIBRARY_CALLS || STLSOFT_DEBUG */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_memfns
# include <stlsoft/api/external/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_memfns */
#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * constraints
 */

// class stlsoft_char_traits
/** Character traits
 *
 * \param C The character type
 * \param N The integer type
 * \param Z The size type
 *
 * \ingroup group__library__String
 */
template<
    ss_typename_param_k C
>
struct stlsoft_char_traits
{
public:
    /// The char type
    typedef C                                               char_type;
    /// The current specialisation of the type
    typedef stlsoft_char_traits<
        C
    >                                                       class_type;
    /// The integer type
    typedef ss_int_t                                        int_type;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The position type
    typedef ss_streampos_t                                  pos_type;
    /// The offset type
    typedef ss_streamoff_t                                  off_type;

public:
    /// Assigns \c rhs to \c lhs
    static
    void
    assign(
        char_type&          lhs
    ,   char_type const&    rhs
    ) STLSOFT_NOEXCEPT
    {
        lhs = rhs;
    }

    /// Assigns \c cch characters of value \c c to \c dest
    static
    char_type*
    assign(
        char_type*          dest
    ,   size_type           cch
    ,   char_type const&    c
    ) STLSOFT_NOEXCEPT
    {
        char_type* ret;

        STLSOFT_MESSAGE_ASSERT("char_traits<X>::assign called with NULL destination", (0 == cch || NULL != dest));

        for (ret = dest; 0 < cch; --cch, ++dest)
        {
            assign(*dest, c);
        }

        return ret;
    }

    /// Evaluates whether \c lhs is equivalent to \c rhs
    static
    ss_bool_t
    eq(
        char_type const&    lhs
    ,   char_type const&    rhs
    ) STLSOFT_NOEXCEPT
    {
        return lhs == rhs;
    }

    /// Evaluates whether \c lhs is less than \c rhs
    static
    ss_bool_t
    lt(
        char_type const&    lhs
    ,   char_type const&    rhs
    ) STLSOFT_NOEXCEPT
    {
        return lhs < rhs;
    }

    /// Compares \c cch characters of \c s1 with \c s2
    ///
    /// \param s1 The first string to compare
    /// \param s2 The second string to compare
    /// \param cch The number of characters to compare \c s1 with \c s2
    ///
    /// \retval <0 s1 is lexicographically less than s2
    /// \retval 0 s1 is lexicographically equal to s2
    /// \retval >0 s1 is lexicographically more than s2
    static
    int_type
    compare(
        char_type const*    s1
    ,   char_type const*    s2
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("char_traits<X>::compare called with NULL string", (0 == cch || NULL != s1));
        STLSOFT_MESSAGE_ASSERT("char_traits<X>::compare called with NULL string", (0 == cch || NULL != s2));

        for (size_type n = 0; n != cch; ++n, ++s1, ++s2)
        {
            if (!eq(*s1, *s2))
            {
                return lt(*s1, *s2) ? -1 : +1;
            }
        }

        return 0;
    }

    /// Compares up to \c cch characters of \c s1 with \c, stopping at the
    /// first difference or until the NUL-terminator is reached
    ///
    /// \param s1 The first string to compare
    /// \param s2 The second string to compare
    /// \param cch The number of characters to compare \c s1 with \c s2
    ///
    /// \retval <0 s1 is lexicographically less than s2
    /// \retval 0 s1 is lexicographically equal to s2
    /// \retval >0 s1 is lexicographically more than s2
    // TODO: rename this to something much discoverable, e.g. `compare_maybe_nul()`
    static
    int_type
    compare_max(
        char_type const*    s1
    ,   char_type const*    s2
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("char_traits<X>::compare_max called with NULL string", (0 == cch || NULL != s1));
        STLSOFT_MESSAGE_ASSERT("char_traits<X>::compare_max called with NULL string", (0 == cch || NULL != s2));

        for (size_type n = 0; n != cch; ++n, ++s1, ++s2)
        {
            if (!eq(*s1, *s2))
            {
                return lt(*s1, *s2) ? -1 : +1;
            }
            else if (eq(*s1, char_type(0)))
            {
                break;
            }
        }

        return 0;
    }

    /// Compares, using compare(), \c s1 with \c s2, either or both of which may be \c nullptr
    static
    int_type
    compare_null(
        char_type const*    s1
    ,   char_type const*    s2
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        int_type    result;

        if (NULL == s1)
        {
            result = (NULL == s2) ? 0 : -1;
        }
        else
        {
            result = (NULL == s2) ? 1 : compare(s1, s2, cch);
        }

        return result;
    }

    /// Compares, using compare_max(), \c s1 with \c s2, either or both of which may be \c nullptr
    static
    int_type
    compare_maxnull(
        char_type const*    s1
    ,   char_type const*    s2
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        int_type    result;

        if (NULL == s1)
        {
            result = (NULL == s2) ? 0 : -1;
        }
        else
        {
            result = (NULL == s2) ? 1 : compare_max(s1, s2, cch);
        }

        return result;
    }

    /// Evaluates the length of the string \c s
    static
    size_type
    length(
        char_type const* s
    ) STLSOFT_NOEXCEPT
    {
        size_type cch;

        STLSOFT_MESSAGE_ASSERT("char_traits<X>::length called with NULL string", NULL != s);

        for (cch = 0; !eq(*s, char_type(0)); ++s)
        {
            ++cch;
        }

        return cch;
    }

    /// Evaluates the length of the string \c s, which may be \c nullptr
    static
    size_type
    length_null(
        char_type const* s
    ) STLSOFT_NOEXCEPT
    {
        return (NULL != s) ? length(s) : 0;
    }

    /// Evaluates the length of the string \c s up to a given number of characters
    ///
    /// \param s The string to be evaluated. It may <b>not</b> be null
    /// \param limit The maximum number of characters to evaluate
    /// \return The length of the string (in characters) not including the null-terminator
    static
    size_type
    length_max(
        char_type const*    s
    ,   size_type           limit
    ) STLSOFT_NOEXCEPT
    {
        size_type cch;

        STLSOFT_MESSAGE_ASSERT("char_traits<X>::length_max called with NULL string", NULL != s);

        for (cch = 0; cch < limit && !eq(*s, char_type(0)); ++s)
        {
            ++cch;
        }

        return cch;
    }

    /// Evaluates the length of the string \c s, which may be \c nullptr, up to a given number of characters
    ///
    /// \param s The string to be evaluated. It may be null
    /// \param limit The maximum number of characters to evaluate
    /// \return The length of the string (in characters) not including the null-terminator
    static
    size_type
    length_max_null(
        char_type const*    s
    ,   size_type           limit
    ) STLSOFT_NOEXCEPT
    {
        return (NULL != s) ? length_max(s, limit) : 0;
    }

    /// Copies \c cch characters from \c src to \c dest
    static
    char_type*
    copy(
        char_type*          dest
    ,   char_type const*    src
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        char_type* ret;

        STLSOFT_MESSAGE_ASSERT("char_traits<X>::copy called with NULL destination", (0 == cch || NULL != dest));
        STLSOFT_MESSAGE_ASSERT("char_traits<X>::copy called with NULL source", (0 == cch || NULL != src));

#ifdef STLSOFT_DEBUG

        STLSOFT_API_INTERNAL_memfns_memset(dest, '~', cch * sizeof(char_type));
#endif /* STLSOFT_DEBUG */

        for (ret = dest; 0 < cch; --cch, ++dest, ++src)
        {
            assign(*dest, *src);
        }

        return ret;
    }

    /// Copies \c cch characters from \c src to \c dest, accounting for whether the ranges overlap
    static
    char_type*
    move(
        char_type*          dest
    ,   char_type const*    src
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        char_type* const ret = dest;

        STLSOFT_MESSAGE_ASSERT("char_traits<X>::move called with NULL destination", (0 == cch || NULL != dest));
        STLSOFT_MESSAGE_ASSERT("char_traits<X>::move called with NULL source", (0 == cch || NULL != src));

        if (src < dest &&
            dest < src + cch)
        {
            for (dest += cch, src += cch; 0 < cch; --cch)
            {
                assign(*--dest, *--src);
            }
        }
        else
        {
            for (; 0 < cch; --cch, ++dest, ++src)
            {
                assign(*dest, *src);
            }
        }

        return ret;
    }

    /// Finds the first \c c in \c cch elements in \c s, or \c nullptr if
    /// not found
    static
    char_type const*
    find(
        char_type const*    s
    ,   size_type           cch
    ,   char_type const&    c
    ) STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("char_traits<X>::find called with NULL string", (0 == cch || NULL != s));

        for (; 0 < cch; --cch, ++s)
        {
            if (eq(*s, c))
            {
                break;
            }
        }

        return (0 < cch) ? s : NULL;
    }

    /// Represents the character \c in the character type \c char_type
    static
    char_type
    to_char_type(
        int_type const& c
    ) STLSOFT_NOEXCEPT
    {
        return static_cast<char_type>(c);
    }

    /// Represents the character \c in the integer type \c int_type
    static
    int_type
    to_int_type(
        char_type const& c
    ) STLSOFT_NOEXCEPT
    {
#if defined(STLSOFT_COMPILER_IS_WATCOM)

        return (int_type)(c);
#else /* ? compiler */

        return static_cast<int_type>(static_cast<ss_typename_type_k sign_traits<char_type>::unsigned_type>(c));
#endif /* compiler */
    }

    /// Evaluates whether \c lhs and \c rhs are equivalent
    static
    ss_bool_t
    eq_int_type(
        int_type const& lhs
    ,   int_type const& rhs
    ) STLSOFT_NOEXCEPT
    {
        return lhs == rhs;
    }

    /// Returns the value representing the end-of-file.
    static
    int_type
    eof() STLSOFT_NOEXCEPT
    {
        return static_cast<int_type>(-1);
    }

    /// Evaluates whether the given character is the end-of-file.
    static
    int_type
    not_eof(
        int_type const& c
    ) STLSOFT_NOEXCEPT
    {
        return (c != eof() ? c : !eof());
    }
};

// class stlsoft_char_traits_safe
/** Character traits, all of the operations of which can work with null pointers
 *
 * \param C The character type
 * \param N The integer type
 * \param Z The size type
 *
 * \ingroup group__library__String
 */
template<
    ss_typename_param_k C
>
struct stlsoft_char_traits_safe
    : private stlsoft_char_traits<C>
{
private:
    typedef stlsoft_char_traits<
        C
    >                                                       parent_class_type;
public:
    /// The character type
    typedef C                                               char_type;
    /// The current specialisation of the type
    typedef stlsoft_char_traits_safe<
        C
    >                                                       class_type;
    /// The integer type
    typedef ss_int_t                                        int_type;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The position type
    typedef ss_streampos_t                                  pos_type;
    /// The offset type
    typedef ss_streamoff_t                                  off_type;

public:
    /// Assigns \c rhs to \c lhs
    static
    void
    assign(
        char_type&          lhs
    ,   char_type const&    rhs
    ) STLSOFT_NOEXCEPT
    {
        parent_class_type::assign(lhs, rhs);
    }

    /// Assigns \c cch characters of value \c c to \c dest
    static
    char_type*
    assign(
        char_type*          dest
    ,   size_type           cch
    ,   char_type const&    c
    ) STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("char_traits_safe<X>::assign called with NULL destination", NULL != dest);

        return parent_class_type::assign(dest, cch, c);
    }

    /// Evaluates whether \c lhs is equivalent to \c rhs
    static
    ss_bool_t
    eq(
        char_type const&    lhs
    ,   char_type const&    rhs
    ) STLSOFT_NOEXCEPT
    {
        return parent_class_type::eq(lhs, rhs);
    }

    /// Evaluates whether \c lhs is less than \c rhs
    static
    ss_bool_t
    lt(
        char_type const&    lhs
    ,   char_type const&    rhs
    ) STLSOFT_NOEXCEPT
    {
        return parent_class_type::lt(lhs, rhs);
    }

    /// Compares \c cch characters of \c s1 with \c s2
    ///
    /// \param s1 The first string to compare
    /// \param s2 The second string to compare
    /// \param cch The number of characters to compare \c s1 with \c s2
    ///
    /// \retval <0 s1 is lexicographically less than s2
    /// \retval 0 s1 is lexicographically equal to s2
    /// \retval >0 s1 is lexicographically more than s2
    static
    int_type
    compare(
        char_type const*    s1
    ,   char_type const*    s2
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        return compare_null(s1, s2, cch);
    }

    static
    int_type
    compare_max(
        char_type const*    s1
    ,   char_type const*    s2
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        return compare_maxnull(s1, s2, cch);
    }

    /// Compares, using compare(), \c s1 with \c s2, either or both of which may be \c nullptr
    static
    int_type
    compare_null(
        char_type const*    s1
    ,   char_type const*    s2
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        return parent_class_type::compare(s1, s2, cch);
    }

    /// Compares, using compare_max(), \c s1 with \c s2, either or both of which may be \c nullptr
    static
    int_type
    compare_maxnull(
        char_type const*    s1
    ,   char_type const*    s2
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        return parent_class_type::compare_maxnull(s1, s2, cch);
    }

    /// Evaluates the length of the string \c s up to a given number of characters
    ///
    /// \param s The string to be evaluated. It may be null
    /// \param limit The maximum number of characters to evaluate
    /// \return The length of the string (in characters) not including the null-terminator
    static
    size_type
    length_max_null(
        char_type const*    s
    ,   size_type           limit
    ) STLSOFT_NOEXCEPT
    {
        return (NULL == s) ? 0 : parent_class_type::length_max(s, limit);
    }

    /// Evaluates the length of the string \c s, which may be \c nullptr, up to a given number of characters
    ///
    /// \param s The string to be evaluated. It may be null
    /// \param limit The maximum number of characters to evaluate
    /// \return The length of the string (in characters) not including the null-terminator
    static
    size_type
    length_max(
        char_type const*    s
    ,   size_type           limit
    ) STLSOFT_NOEXCEPT
    {
        return length_max_null(s, limit);
    }

    /// Evaluates the length of the string \c s, which may be \c nullptr
    static
    size_type
    length_null(
        char_type const* s
    ) STLSOFT_NOEXCEPT
    {
        return (NULL == s) ? 0 : parent_class_type::length(s);
    }

    /// Evaluates the length of the string \c s
    static
    size_type
    length(
        char_type const* s
    ) STLSOFT_NOEXCEPT
    {
        return length_null(s);
    }

    /// Copies \c cch characters from \c src to \c dest
    static
    char_type*
    copy(
        char_type*          dest
    ,   char_type const*    src
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("char_traits_safe<X>::copy called with NULL destination", NULL != dest);
        STLSOFT_MESSAGE_ASSERT("char_traits_safe<X>::copy called with NULL source", NULL != src);

        return parent_class_type::copy(dest, src, cch);
    }

    /// Copies \c cch characters from \c src to \c dest, accounting for whether the ranges overlap
    static
    char_type*
    move(
        char_type*          dest
    ,   char_type const*    src
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("char_traits_safe<X>::move called with NULL destination", NULL != dest);
        STLSOFT_MESSAGE_ASSERT("char_traits_safe<X>::move called with NULL source", NULL != src);

        return parent_class_type::move(dest, src, cch);
    }

    /// Finds the first \c c in \c cch elements in \c s, or \c nullptr if
    /// not found
    static
    char_type const*
    find(
        char_type const*    s
    ,   size_type           cch
    ,   char_type const&    c
    ) STLSOFT_NOEXCEPT
    {
        return (NULL == s) ? NULL : parent_class_type::find(s, cch, c);
    }

    /// Represents the character \c in the character type \c char_type
    static
    char_type
    to_char_type(
        int_type const& c
    ) STLSOFT_NOEXCEPT
    {
        return parent_class_type::to_char_type(c);
    }

    /// Represents the character \c in the integer type \c int_type
    static
    int_type
    to_int_type(
        char_type const& c
    ) STLSOFT_NOEXCEPT
    {
        return parent_class_type::to_int_type(c);
    }

    /// Evaluates whether \c lhs and \c rhs are equivalent
    static
    ss_bool_t
    eq_int_type(
        int_type const& lhs
    ,   int_type const& rhs
    ) STLSOFT_NOEXCEPT
    {
        return parent_class_type::eq_int_type(lhs, rhs);
    }

    /// Returns the value representing the end-of-file.
    static
    int_type
    eof() STLSOFT_NOEXCEPT
    {
        return parent_class_type::eof();
    }

    /// Evaluates whether the given character is the end-of-file.
    static
    int_type
    not_eof(
        int_type const& c
    ) STLSOFT_NOEXCEPT
    {
        return parent_class_type::not_eof(c);
    }
};

// class char_traits
/** Character traits, all of the operations of which can work with null pointers
 *
 * \param C The character type
 * \param N The integer type
 * \param Z The size type
 *
 * \ingroup group__library__String
 */

/* DMC++ special handling */
#if defined(STLSOFT_COMPILER_IS_DMC) &&   /* compiler is DMC++ */ \
    !defined(STLSOFT_CF_std_NAMESPACE)    /* std namespace is not defined */

# if !defined(__SGI_STL_STRING_FWD_H)
#  error Unexpected
# endif /* !__SGI_STL_STRING_FWD_H */
# if !defined(__SGI_STL_CHAR_TRAITS_H)
#  error Unexpected
# endif /* !__SGI_STL_CHAR_TRAITS_H */

using ::char_traits;
#else /* ? comp/lib */

/* We only define (stlsoft::)char_traits if no std::char_traits is available, or
 * the stlsoft namespace is defined, or the std namespace is defined.
 */
# if !defined(STLSOFT_CF_std_char_traits_AVAILABLE) || /* std does not define char_traits */ \
     !defined(STLSOFT_NO_NAMESPACE) ||                 /* stlsoft namespace is defined */ \
     defined(STLSOFT_CF_std_NAMESPACE)
template<
    ss_typename_param_k C
>
struct char_traits
    : public stlsoft_char_traits<C>
{
    typedef stlsoft_char_traits<
        C
    >                                                       parent_class_type;
public:
    /// The current specialisation of the type
    typedef char_traits<
        C
    >                                                       class_type;
    /// The character type
    typedef ss_typename_type_k parent_class_type::char_type char_type;
    typedef ss_typename_type_k parent_class_type::int_type  int_type;
    typedef ss_typename_type_k parent_class_type::size_type size_type;
    typedef ss_typename_type_k parent_class_type::pos_type  pos_type;
    typedef ss_typename_type_k parent_class_type::off_type  off_type;
};
# endif /* !::stlsoft && !::std */
#endif /* comp/lib */

// class char_traits_safe
/** Character traits, all of the operations of which can work with null pointers
 *
 * \param C The character type
 * \param N The integer type
 * \param Z The size type
 *
 * \ingroup group__library__String
 */
template<
    ss_typename_param_k C
>
struct char_traits_safe
    : public stlsoft_char_traits_safe<C>
{
    typedef stlsoft_char_traits_safe<
        C
    >                                                       parent_class_type;
public:
    /// The current specialisation of the type
    typedef char_traits_safe<
        C
    >                                                       class_type;
    /// The character type
    typedef ss_typename_type_k parent_class_type::char_type char_type;
    typedef ss_typename_type_k parent_class_type::int_type  int_type;
    typedef ss_typename_type_k parent_class_type::size_type size_type;
    typedef ss_typename_type_k parent_class_type::pos_type  pos_type;
    typedef ss_typename_type_k parent_class_type::off_type  off_type;
};


/* /////////////////////////////////////////////////////////////////////////
 * specialisations
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#if !defined(STLSOFT_NO_CHAR_TRAITS_LIBRARY_CALLS) && \
    !defined(STLSOFT_COMPILER_IS_DMC) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1100) && \
    !defined(STLSOFT_COMPILER_IS_VECTORC) && \
    !defined(STLSOFT_COMPILER_IS_WATCOM)

/* char */

STLSOFT_TEMPLATE_SPECIALISATION
inline
char*
stlsoft_char_traits<char>::assign(
    char*       dest
,   ss_size_t   cch
,   char const& c
) STLSOFT_NOEXCEPT
{
    return static_cast<char*>(STLSOFT_API_INTERNAL_memfns_memset(dest, c, cch));
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
ss_int_t
stlsoft_char_traits<char>::compare(
    char const* s1
,   char const* s2
,   ss_size_t   cch
) STLSOFT_NOEXCEPT
{
    return STLSOFT_API_EXTERNAL_memfns_memcmp(s1, s2, cch);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
ss_int_t
stlsoft_char_traits<char>::compare_max(
    char const* s1
,   char const* s2
,   ss_size_t   cch
) STLSOFT_NOEXCEPT
{
    return STLSOFT_NS_GLOBAL(strncmp)(s1, s2, cch);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
char const*
stlsoft_char_traits<char>::find(
    char const* s
,   size_type   cch
,   char const& c
) STLSOFT_NOEXCEPT
{
#if defined(STLSOFT_COMPILER_IS_BORLAND) && \
    __BORLANDC__ < 0x0560

    return static_cast<char const*>(memchr(s, c, cch));
#else /* ? compiler */

    void const* const p = STLSOFT_NS_GLOBAL(memchr)(s, c, cch);

    return static_cast<char const*>(p);
#endif /* compiler */
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
char*
stlsoft_char_traits<char>::copy(
    char*       dest
,   char const* src
,   ss_size_t   cch
) STLSOFT_NOEXCEPT
{
#ifdef STLSOFT_DEBUG

    STLSOFT_API_INTERNAL_memfns_memset(dest, '~', cch);
#endif /* STLSOFT_DEBUG */

    return static_cast<char*>(STLSOFT_API_INTERNAL_memfns_memcpy(dest, src, cch));
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
ss_size_t
stlsoft_char_traits<char>::length(
    char const* s
) STLSOFT_NOEXCEPT
{
    return STLSOFT_NS_GLOBAL(strlen)(s);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
ss_size_t
stlsoft_char_traits<char>::length_max(
    char const* s
,   ss_size_t   limit
) STLSOFT_NOEXCEPT
{
    return STLSOFT_NS_GLOBAL(strnlen)(s, limit);
}

/* wchar_t */

STLSOFT_TEMPLATE_SPECIALISATION
inline
wchar_t*
stlsoft_char_traits<wchar_t>::assign(
    wchar_t*        dest
,   ss_size_t       cch
,   wchar_t const&  c
) STLSOFT_NOEXCEPT
{
    return STLSOFT_API_INTERNAL_memfns_wmemset(dest, c, cch);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
ss_int_t
stlsoft_char_traits<wchar_t>::compare(
    wchar_t const*  s1
,   wchar_t const*  s2
,   ss_size_t       cch
) STLSOFT_NOEXCEPT
{
    return STLSOFT_API_EXTERNAL_memfns_wmemcmp(s1, s2, cch);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
ss_int_t
stlsoft_char_traits<wchar_t>::compare_max(
    wchar_t const*  s1
,   wchar_t const*  s2
,   ss_size_t       cch
) STLSOFT_NOEXCEPT
{
    return STLSOFT_NS_GLOBAL(wcsncmp)(s1, s2, cch);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
wchar_t const*
stlsoft_char_traits<wchar_t>::find(
    wchar_t const*  s
,   size_type       cch
,   wchar_t const&  c
) STLSOFT_NOEXCEPT
{
#if defined(STLSOFT_COMPILER_IS_BORLAND) && \
    __BORLANDC__ < 0x0560

    return static_cast<wchar_t const*>(wmemchr(s, c, cch));
#else /* ? compiler */

    void const* const p = STLSOFT_NS_GLOBAL(wmemchr)(s, c, cch);

    return static_cast<wchar_t const*>(p);
#endif /* compiler */
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
wchar_t*
stlsoft_char_traits<wchar_t>::copy(
    wchar_t*        dest
,   wchar_t const*  src
,   ss_size_t       cch
) STLSOFT_NOEXCEPT
{
#ifdef STLSOFT_DEBUG

    STLSOFT_API_INTERNAL_memfns_memset(dest, '~', cch * sizeof(wchar_t));
#endif /* STLSOFT_DEBUG */

    return STLSOFT_API_INTERNAL_memfns_wmemcpy(dest, src, cch);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
ss_size_t
stlsoft_char_traits<wchar_t>::length(
    wchar_t const* s
) STLSOFT_NOEXCEPT
{
    return STLSOFT_NS_GLOBAL(wcslen)(s);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
ss_size_t
stlsoft_char_traits<wchar_t>::length_max(
    wchar_t const*  s
,   ss_size_t       limit
) STLSOFT_NOEXCEPT
{
    return STLSOFT_NS_GLOBAL(wcsnlen)(s, limit);
}
#endif /* !STLSOFT_NO_CHAR_TRAITS_LIBRARY_CALLS && !STLSOFT_COMPILER_IS_DMC */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

