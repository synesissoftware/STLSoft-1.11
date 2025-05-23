/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/conversion/char_conversions.hpp (originally MLStrCnv.h, ::SynesisStd)
 *
 * Purpose: Type conversions for Windows.
 *
 * Created: 31st May 2003
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


/** \file winstl/conversion/char_conversions.hpp
 *
 * \brief [C++] Definition of the winstl::multibyte2wide and
 *  winstl::wide2multibyte class templates
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef WINSTL_INCL_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS
#define WINSTL_INCL_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS_MAJOR    5
# define WINSTL_VER_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS_MINOR    4
# define WINSTL_VER_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS_REVISION 15
# define WINSTL_VER_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS_EDIT     120
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(STLSOFT_COMPILER_IS_GCC) && \
    __GNUC__ < 3
# error winstl/conversion/char_conversions.hpp is not compatible with GNU C++ prior to 3.0
#endif /* compiler */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1100
# error winstl/conversion/char_conversions.hpp is not compatible with Visual C++ 5.0 or earlier
#endif /* compiler */

#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING
# include <winstl/shims/access/string.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR
#  include <winstl/error/conversion_error.hpp>
# endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR */
# include <errno.h>
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_memfns
# include <stlsoft/api/external/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_memfns */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_UnicodeAndCharacterSet
# include <winstl/api/external/UnicodeAndCharacterSet.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_UnicodeAndCharacterSet */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Converts a multibyte (<code>char</code>-based) string to a wide
 *   (<code>whar_t</code>-based) string.
 *
 * \ingroup group__library__Conversion
 */
template <
    ws_size_t V_internalSize
>
class multibyte2wide
    : private auto_buffer<ws_char_w_t, V_internalSize, processheap_allocator<ws_char_w_t> >
{
/// \name Member Types
/// @{
private:
    typedef auto_buffer<
        ws_char_w_t
    ,   V_internalSize
    ,   processheap_allocator<ws_char_w_t>
    >                                                       parent_class_type;
public:
    /// The character type
    typedef ws_char_w_t                                     char_type;
    /// The alternate character type
    typedef ws_char_a_t                                     alt_char_type;
    /// The size type
    typedef ss_typename_type_k parent_class_type::size_type size_type;
    /// The pointer type
    typedef ss_typename_type_k parent_class_type::pointer   pointer;
    /// This type
    typedef multibyte2wide<
        V_internalSize
    >                                                       class_type;
/// @}

/// \name Construction
/// @{
public:
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k T_string>
    ss_explicit_k multibyte2wide(T_string const& s)
#else
    ss_explicit_k multibyte2wide(alt_char_type const* s)
#endif // STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        : parent_class_type(STLSOFT_NS_QUAL(c_str_len)(s) + 1)
    {
        prepare_(STLSOFT_NS_QUAL(c_str_ptr_a)(s));
    }

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# ifdef STLSOFT_COMPILER_IS_GCC
    multibyte2wide(class_type const& s)
        : parent_class_type(s.size() + 1)
    {
        char_type* const p = &static_cast<parent_class_type&>(*this)[0];

        STLSOFT_API_EXTERNAL_memfns_memcpy(p, s, sizeof(char_type) * (1u + s.size()));
        STLSOFT_ASSERT('\0' == (*this)[s.size()]);
    }
# endif /* compiler */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k T_string>
    multibyte2wide(T_string const& s, size_type cch)
#else
    multibyte2wide(alt_char_type const* s, size_type cch)
#endif // STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        : parent_class_type(cch + 1)
    {
        prepare_(STLSOFT_NS_QUAL(c_str_ptr_a)(s));
    }

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/// @}

/// \name Implementation
/// @{
private:
    void prepare_(alt_char_type const* s)
    {
        const size_type size    =   parent_class_type::size();
        const pointer   data    =   parent_class_type::data();

        // If the auto_buffer failed to allocate the required memory, and
        // we're not in an exception-environment, then size() will be zero
        if (0 == size)
        {
            // Since we know that auto_buffer's specialising size must
            // always be greater that 0, then
            data[0] = '\0';
        }
        else
        {
            // NOTE: cannot use -1 for length, since s might be a type that
            // could change length
            if (0 == WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_MultiByteToWideChar(0, 0, s, static_cast<int>(size), data, static_cast<int>(size)))
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                STLSOFT_THROW_X(conversion_error("failed to convert multibyte string to wide string", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                data[0] = '\0';
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                data[size - 1] = '\0';
            }
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    char_type const* data() const
    {
        return parent_class_type::data();
    }
    char_type const* c_str() const
    {
        return parent_class_type::data();
    }

    size_type size() const
    {
        size_type n = parent_class_type::size();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        WINSTL_ASSERT(0 != n);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        if (0 == n)
        {
            return 0;
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return n - 1;
    }
/// @}

/// \name Operators
/// @{
public:
    operator char_type const* () const
    {
        return parent_class_type::data();
    }
/// @}

/// \name Not to be implemented
/// @{
private:
#ifndef STLSOFT_COMPILER_IS_GCC
    multibyte2wide(class_type const&);
#endif /* compiler */
    multibyte2wide& operator =(class_type const&);
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}
};

/** Converts a wide (<code>whar_t</code>-based) string to a
 *    multibyte (<code>char</code>-based) string.
 *
 * \ingroup group__library__Conversion
 */
template <ws_size_t V_internalSize>
class wide2multibyte
    : private auto_buffer<ws_char_a_t, V_internalSize, processheap_allocator<ws_char_a_t> >
{
/// \name Member Types
/// @{
private:
    typedef auto_buffer<
        ws_char_a_t
    ,   V_internalSize
    ,   processheap_allocator<ws_char_a_t>
    >                                                       parent_class_type;
public:
    /// The character type
    typedef ws_char_a_t                                     char_type;
    /// The alternate character type
    typedef ws_char_w_t                                     alt_char_type;
    /// The size type
    typedef ss_typename_type_k parent_class_type::size_type size_type;
    /// The pointer type
    typedef ss_typename_type_k parent_class_type::pointer   pointer;
    /// This type
    typedef wide2multibyte<
        V_internalSize
    >                                                       class_type;
/// @}

/// \name Construction
/// @{
public:
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k T_string>
    ss_explicit_k wide2multibyte(T_string const& s)
#else
    ss_explicit_k wide2multibyte(alt_char_type const* s)
#endif // STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        : parent_class_type(STLSOFT_NS_QUAL(c_str_len)(s) + 1)
    {
        prepare_(STLSOFT_NS_QUAL(c_str_ptr_w)(s));
    }

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# ifdef STLSOFT_COMPILER_IS_GCC
    wide2multibyte(class_type const& s)
        : parent_class_type(s.size() + 1)
    {
        char_type* const p = &static_cast<parent_class_type&>(*this)[0];

        STLSOFT_API_EXTERNAL_memfns_memcpy(p, s, sizeof(char_type) * (1u + s.size()));
        STLSOFT_ASSERT('\0' == (*this)[s.size()]);
    }
# endif /* compiler */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k T_string>
    ss_explicit_k wide2multibyte(T_string const& s, size_type cch)
#else
    ss_explicit_k wide2multibyte(alt_char_type const* s, size_type cch)
#endif // STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        : parent_class_type(cch + 1)
    {
        prepare_(STLSOFT_NS_QUAL(c_str_ptr_w)(s));
    }
/// @}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

/// \name Implementation
/// @{
private:
    void prepare_(alt_char_type const* s)
    {
        const size_type size    =   parent_class_type::size();
        const pointer   data    =   parent_class_type::data();

        // If the auto_buffer failed to allocate the required memory, and
        // we're not in an exception-environment, then size() will be zero
        if (0 == size)
        {
            // Since we know that auto_buffer's specialising size must
            // always be greater that 0, then
            data[0] = '\0';
        }
        else
        {
            // NOTE: cannot use -1 for length, since s might be a type that
            // could change length
            if (0 == WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_WideCharToMultiByte(0, 0, s, static_cast<int>(size), data, static_cast<int>(size), NULL, NULL))
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                STLSOFT_THROW_X(conversion_error("failed to convert multibyte string to wide string", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                data[0] = '\0';
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                data[size - 1] = '\0';
            }
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    char_type const* data() const
    {
        return parent_class_type::data();
    }
    char_type const* c_str() const
    {
        return parent_class_type::data();
    }

    size_type size() const
    {
        size_type n = parent_class_type::size();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        WINSTL_ASSERT(0 != n);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        if (0 == n)
        {
            return 0;
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return n - 1;
    }
/// @}

/// \name Operators
/// @{
public:
    operator char_type const* () const
    {
        return parent_class_type::data();
    }
/// @}

// Not to be implemented
private:
#ifndef STLSOFT_COMPILER_IS_GCC
    wide2multibyte(class_type const&);
#endif /* compiler */
    wide2multibyte& operator =(class_type const&);
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ss_typename_param_k S
,   ss_typename_param_k C
>
struct encoding2encoding_traits
{
    static C const* elicit_ccs(S const& s)
    {
        return s.c_str();
    }
};

#ifdef __ATLBASE_H__

STLSOFT_TEMPLATE_SPECIALISATION
inline
wchar_t const*
encoding2encoding_traits< ::ATL::CComBSTR, wchar_t>::elicit_ccs( ::ATL::CComBSTR const& s)
{
    return s.m_str;
}
#endif /* __ATLBASE_H__ */



template <ss_typename_param_k C>
class encoding2encoding
{
public:
    encoding2encoding(C const* s)
        : m_s(s)
    {}
    encoding2encoding(C *s)
        : m_s(s)
    {}
    template <ss_typename_param_k S>
    encoding2encoding(S const& s)
        : m_s(encoding2encoding_traits<S, C>::elicit_ccs(s))
    {}

public:
    C const* c_str() const
    {
        return m_s;
    }
    operator C const* () const
    {
        return m_s;
    }

private:
    C const* m_s;
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

/** Type that converts a multibyte string to a wide string.
 *
 * \ingroup group__library__Conversion
 */
typedef multibyte2wide<256>                                 m2w;
/** Type that converts a wide string to a multibyte string.
 *
 * \ingroup group__library__Conversion
 */
typedef wide2multibyte<256>                                 w2m;

/** [Deprecated] Type that converts a multibyte string to a wide string.
 *
 * \ingroup group__library__Conversion
 *
 * \deprecated This name is deprecated in favour of winstl::m2w
 */
typedef multibyte2wide<256>                                 a2w;
/** [Deprecated] Type that converts a wide string to a multibyte string.
 *
 * \ingroup group__library__Conversion
 *
 * \deprecated This name is deprecated in favour of winstl::w2m
 */
typedef wide2multibyte<256>                                 w2a;

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if defined(UNICODE)
typedef encoding2encoding<ws_char_w_t>                      t2w;
typedef encoding2encoding<ws_char_w_t>                      w2t;
typedef w2m                                                 t2m;
typedef m2w                                                 m2t;
typedef w2a                                                 t2a;
typedef a2w                                                 a2t;
# else /* ? UNICODE */
typedef encoding2encoding<ws_char_a_t>                      t2a;
typedef encoding2encoding<ws_char_a_t>                      a2t;
typedef encoding2encoding<ws_char_a_t>                      t2m;
typedef encoding2encoding<ws_char_a_t>                      m2t;
typedef m2w                                                 t2w;
typedef w2m                                                 w2t;
typedef a2w                                                 t2w;
typedef w2a                                                 w2t;
# endif /* UNICODE */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for winstl::multibyte2wide
 *
 * \ingroup group__concept__Shim__string_access
 */
template <
    ws_size_t   V_internalSize
>
inline ws_char_w_t const* c_str_ptr_null(WINSTL_NS_QUAL(multibyte2wide)<V_internalSize> const& c)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null)(c.c_str());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ws_size_t   V_internalSize
>
inline ws_char_w_t const* c_str_ptr_null_w(WINSTL_NS_QUAL(multibyte2wide)<V_internalSize> const& c)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null)(c.c_str());
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \ref group__concept__Shim__string_access__c_str_ptr for winstl::multibyte2wide
 *
 * \ingroup group__concept__Shim__string_access
 */
template <
    ws_size_t   V_internalSize
>
inline ws_char_w_t const* c_str_ptr(WINSTL_NS_QUAL(multibyte2wide)<V_internalSize> const& c)
{
    return c.c_str();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ws_size_t   V_internalSize
>
inline ws_char_w_t const* c_str_ptr_w(WINSTL_NS_QUAL(multibyte2wide)<V_internalSize> const& c)
{
    return c.c_str();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_data for winstl::multibyte2wide
 *
 * \ingroup group__concept__Shim__string_access
 */
template <
    ws_size_t   V_internalSize
>
inline ws_char_w_t const* c_str_data(WINSTL_NS_QUAL(multibyte2wide)<V_internalSize> const& c)
{
    return c.data();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ws_size_t   V_internalSize
>
inline ws_char_w_t const* c_str_data_w(WINSTL_NS_QUAL(multibyte2wide)<V_internalSize> const& c)
{
    return c.data();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for winstl::multibyte2wide
 *
 * \ingroup group__concept__Shim__string_access
 */
template <
    ws_size_t   V_internalSize
>
inline ws_size_t c_str_len(WINSTL_NS_QUAL(multibyte2wide)<V_internalSize> const& c)
{
    return c.size();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ws_size_t   V_internalSize
>
inline ws_size_t c_str_len_w(WINSTL_NS_QUAL(multibyte2wide)<V_internalSize> const& c)
{
    return c.size();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



/** \ref group__concept__Shim__string_access__c_str_ptr_null for winstl::wide2multibyte
 *
 * \ingroup group__concept__Shim__string_access
 */
template <
    ws_size_t   V_internalSize
>
inline ws_char_a_t const* c_str_ptr_null(WINSTL_NS_QUAL(wide2multibyte)<V_internalSize> const& c)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null)(c.c_str());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ws_size_t   V_internalSize
>
inline ws_char_a_t const* c_str_ptr_null_a(WINSTL_NS_QUAL(wide2multibyte)<V_internalSize> const& c)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null)(c.c_str());
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr for winstl::wide2multibyte
 *
 * \ingroup group__concept__Shim__string_access
 */
template <
    ws_size_t   V_internalSize
>
inline ws_char_a_t const* c_str_ptr(WINSTL_NS_QUAL(wide2multibyte)<V_internalSize> const& c)
{
    return c.c_str();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ws_size_t   V_internalSize
>
inline ws_char_a_t const* c_str_ptr_a(WINSTL_NS_QUAL(wide2multibyte)<V_internalSize> const& c)
{
    return c.c_str();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_data for winstl::wide2multibyte
 *
 * \ingroup group__concept__Shim__string_access
 */
template <
    ws_size_t   V_internalSize
>
inline ws_char_a_t const* c_str_data(WINSTL_NS_QUAL(wide2multibyte)<V_internalSize> const& c)
{
    return c.data();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ws_size_t   V_internalSize
>
inline ws_char_a_t const* c_str_data_a(WINSTL_NS_QUAL(wide2multibyte)<V_internalSize> const& c)
{
    return c.data();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for winstl::wide2multibyte
 *
 * \ingroup group__concept__Shim__string_access
 */
template <
    ws_size_t   V_internalSize
>
inline ws_size_t c_str_len(WINSTL_NS_QUAL(wide2multibyte)<V_internalSize> const& c)
{
    return c.size();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ws_size_t   V_internalSize
>
inline ws_size_t c_str_len_a(WINSTL_NS_QUAL(wide2multibyte)<V_internalSize> const& c)
{
    return c.size();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */




/** \ref group__concept__Shim__stream_insertion "stream insertion shim" for winstl::multibyte2wide
 *
 * \ingroup group__concept__Shim__stream_insertion
 *
 * \tparam T_stream The stream type
 * \tparam V_internalSize The internal size of the multibyte2wide specialisation
 *
 * \param stm The stream
 * \param c The converter
 */
template <
    ss_typename_param_k T_stream
,   ws_size_t           V_internalSize
>
inline
T_stream&
operator <<(
    T_stream&                                               stm
,   WINSTL_NS_QUAL(multibyte2wide)<V_internalSize> const&   c
)
{
    stm << c.c_str();

    return stm;
}

/** \ref group__concept__Shim__stream_insertion "stream insertion shim" for winstl::wide2multibyte
 *
 * \ingroup group__concept__Shim__stream_insertion
 *
 * \tparam T_stream The stream type
 * \tparam V_internalSize The internal size of the wide2multibyte specialisation
 *
 * \param stm The stream
 * \param c The converter
 */
template <
    ss_typename_param_k T_stream
,   ws_size_t           V_internalSize
>
inline
T_stream&
operator <<(
    T_stream&                                               stm
,   WINSTL_NS_QUAL(wide2multibyte)<V_internalSize> const&   c
)
{
    stm << c.c_str();

    return stm;
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef WINSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::winstl::c_str_data;
using ::winstl::c_str_data_a;
using ::winstl::c_str_data_w;

using ::winstl::c_str_len;
using ::winstl::c_str_len_a;
using ::winstl::c_str_len_w;

using ::winstl::c_str_ptr;
using ::winstl::c_str_ptr_a;
using ::winstl::c_str_ptr_w;

using ::winstl::c_str_ptr_null;
using ::winstl::c_str_ptr_null_a;
using ::winstl::c_str_ptr_null_w;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * global namespace shims
 */

/* This defines stream inserter shim function templates for the converters
 * for use with the Visual C++ <7.1 standard library.
 */

#if defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
    STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION < STLSOFT_CF_DINKUMWARE_VC_VERSION_7_1

# include <iosfwd>

template <
    WINSTL_NS_QUAL(ws_size_t) V_internalSize
>
inline
STLSOFT_NS_QUAL_STD(basic_ostream)<char>&
operator <<(
    STLSOFT_NS_QUAL_STD(basic_ostream)<char>&               stm
,   WINSTL_NS_QUAL(wide2multibyte)<V_internalSize> const&   c
)
{
    return stm << c.c_str();
}

template <
    WINSTL_NS_QUAL(ws_size_t) V_internalSize
>
inline
STLSOFT_NS_QUAL_STD(basic_ostream)<wchar_t>&
operator <<(
    STLSOFT_NS_QUAL_STD(basic_ostream)<wchar_t>&            stm
,   WINSTL_NS_QUAL(multibyte2wide)<V_internalSize> const&   c
)
{
    return stm << c.c_str();
}
#endif /* library */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS */

/* ///////////////////////////// end of file //////////////////////////// */

