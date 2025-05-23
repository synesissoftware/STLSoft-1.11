/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/guid.hpp (originally MOGuidGn.h/.cpp, ::SynesisCom)
 *
 * Purpose:     guid class.
 *
 * Created:     10th May 2000
 * Updated:     20th March 2025
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2000-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/util/guid.hpp
 *
 * \brief [C++; requires COM] Definition of the comstl::guid class
 *   (\ref group__library__COM_Utility "COM Utility" Library).
 */

#ifndef COMSTL_INCL_COMSTL_UTIL_HPP_COMSTL_GUID
#define COMSTL_INCL_COMSTL_UTIL_HPP_COMSTL_GUID

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _COMSTL_VER_COMSTL_UTIL_HPP_COMSTL_GUID_MAJOR      4
# define _COMSTL_VER_COMSTL_UTIL_HPP_COMSTL_GUID_MINOR      3
# define _COMSTL_VER_COMSTL_UTIL_HPP_COMSTL_GUID_REVISION   11
# define _COMSTL_VER_COMSTL_UTIL_HPP_COMSTL_GUID_EDIT       66
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef COMSTL_INCL_COMSTL_SHIMS_ACCESS_HPP_STRING
# include <comstl/shims/access/string.hpp>
#endif /* !COMSTL_INCL_COMSTL_SHIMS_ACCESS_HPP_STRING */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION
#  include <comstl/exception/comstl_exception.hpp>
# endif /* !COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION */
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_UnicodeAndCharacterSet
# include <winstl/api/external/UnicodeAndCharacterSet.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_UnicodeAndCharacterSet */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Facade for the COM GUID type
 *
 * \ingroup group__library__COM_Utility
 */
class guid
{
/// \name Types
/// @{
public:
    typedef guid            class_type;

    typedef GUID const&     resource_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs with a new, unique, GUID value
    ///
    /// \note If a new value cannot be acquired, then an instance of
    ///   comstl_exception is thrown if compiled under conditions where exceptions
    ///   are supported (STLSOFT_CF_EXCEPTION_SUPPORT is defined), or the
    ///   instance GUID is set to GUID_NULL otherwise.
    guid();
    /// Constructs with a GUID value equivalent to the given ANSI string
    ///
    /// \param s The string form of the desired GUID
    ///
    /// Example: \code
    ///  guid  g("{00000303-0000-0000-C000-000000000046}");
    /// \endcode
    ///
    /// \note If a new value cannot be determined, then an instance of
    ///   comstl_exception is thrown if compiled under conditions where exceptions
    ///   are supported (STLSOFT_CF_EXCEPTION_SUPPORT is defined), or the
    ///   instance GUID is set to GUID_NULL otherwise.
    ss_explicit_k guid(cs_char_a_t const* s);
    /// Constructs with a GUID value equivalent to the given Unicode string
    ///
    /// \param s The string form of the desired GUID
    ///
    /// Example: \code
    ///  guid  g(L"{00000303-0000-0000-C000-000000000046}");
    /// \endcode
    ///
    /// \note If a new value cannot be determined, then an instance of
    ///   comstl_exception is thrown if compiled under conditions where exceptions
    ///   are supported (STLSOFT_CF_EXCEPTION_SUPPORT is defined), or the
    ///   instance GUID is set to GUID_NULL otherwise.
    ss_explicit_k guid(cs_char_w_t const* s);
    /// Copy constructs from the given GUID
    ss_explicit_k guid(GUID const& g);
    /// Copy constructor
    guid(class_type const& rhs);

    /// Copies the given instance
    guid& operator =(class_type const& rhs);
    /// Assigns to a GUID value equivalent to the given string
    ///
    /// \param s The string form of the desired GUID
    ///
    /// Example: \code
    ///  guid  g;
    ///
    ///  g = "{00000303-0000-0000-C000-000000000046}";
    /// \endcode
    ///
    /// \note If a new value cannot be determined, then an instance of
    ///   comstl_exception is thrown if compiled under conditions where exceptions
    ///   are supported (STLSOFT_CF_EXCEPTION_SUPPORT is defined), or the
    ///   instance GUID is set to GUID_NULL otherwise.
    guid& operator =(cs_char_a_t const* s);
    /// Assigns to a GUID value equivalent to the given string
    ///
    /// \param s The string form of the desired GUID
    ///
    /// Example: \code
    ///  guid  g;
    ///
    ///  g = L"{00000303-0000-0000-C000-000000000046}";
    /// \endcode
    ///
    /// \note If a new value cannot be determined, then an instance of
    ///   comstl_exception is thrown if compiled under conditions where exceptions
    ///   are supported (STLSOFT_CF_EXCEPTION_SUPPORT is defined), or the
    ///   instance GUID is set to GUID_NULL otherwise.
    guid& operator =(cs_char_w_t const* s);
    /// Copies the given GUID value
    guid& operator =(GUID const& g);
/// @}

/// \name Accessors
/// @{
public:
    GUID const& get() const;
/// @}

/// \name Comparison
/// @{
public:
    /// Evaluates whether the value is equivalent to the given argument
    cs_bool_t equal(class_type const& rhs) const;
    /// Evaluates whether the value is equivalent to the given argument
    cs_bool_t equal(GUID const& rhs) const;
/// @}

/// \name Operations
/// @{
public:
    /// Swaps the contents with the given instance
    void swap(class_type& rhs) STLSOFT_NOEXCEPT;
/// @}

/// \name Members
/// @{
private:
    GUID    m_guid;
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

/** \ref group__concept__Shim__string_access__c_str_data for comstl::guid
 *
 * \ingroup group__concept__Shim__string_access
 */
inline c_str_ptr_GUID_proxy<TCHAR> c_str_data(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_data)(g.get());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline c_str_ptr_GUID_proxy<cs_char_a_t> c_str_data_a(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_data_a)(g.get());
}

inline c_str_ptr_GUID_proxy<cs_char_w_t> c_str_data_w(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_data_w)(g.get());
}

inline c_str_ptr_GUID_proxy<cs_char_o_t> c_str_data_o(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_data_o)(g.get());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for comstl::guid
 *
 * \ingroup group__concept__Shim__string_access
 */
inline cs_size_t c_str_len(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_len)(g.get());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline cs_size_t c_str_len_a(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_len_a)(g.get());
}

inline cs_size_t c_str_len_w(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_len_w)(g.get());
}

inline cs_size_t c_str_len_o(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_len_o)(g.get());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr for comstl::guid
 *
 * \ingroup group__concept__Shim__string_access
 */
inline c_str_ptr_GUID_proxy<TCHAR> c_str_ptr(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_ptr)(g.get());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline c_str_ptr_GUID_proxy<cs_char_a_t> c_str_ptr_a(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_ptr_a)(g.get());
}

inline c_str_ptr_GUID_proxy<cs_char_w_t> c_str_ptr_w(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_ptr_w)(g.get());
}

inline c_str_ptr_GUID_proxy<cs_char_o_t> c_str_ptr_o(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_ptr_o)(g.get());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for comstl::guid
 *
 * \ingroup group__concept__Shim__string_access
 */
inline c_str_ptr_GUID_proxy<TCHAR> c_str_ptr_null(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null)(g.get());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline c_str_ptr_GUID_proxy<cs_char_a_t> c_str_ptr_null_a(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null_a)(g.get());
}

inline c_str_ptr_GUID_proxy<cs_char_w_t> c_str_ptr_null_w(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null_w)(g.get());
}

inline c_str_ptr_GUID_proxy<cs_char_o_t> c_str_ptr_null_o(COMSTL_NS_QUAL(guid) const& g)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null_o)(g.get());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

inline cs_bool_t operator ==(guid const& lhs, guid const& rhs)
{
    return lhs.equal(rhs);
}

inline cs_bool_t operator !=(guid const& lhs, guid const& rhs)
{
    return !operator ==(lhs, rhs);
}

inline cs_bool_t operator ==(guid const& lhs, GUID const& rhs)
{
    return lhs.equal(rhs);
}

inline cs_bool_t operator !=(guid const& lhs, GUID const& rhs)
{
    return !operator ==(lhs, rhs);
}

inline cs_bool_t operator ==(GUID const& lhs, guid const& rhs)
{
    return rhs.equal(lhs);
}

inline cs_bool_t operator !=(GUID const& lhs, guid const& rhs)
{
    return !operator ==(lhs, rhs);
}


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline guid::guid()
{
    HRESULT hr  =   ::CoCreateGuid(&m_guid);

    if (FAILED(hr))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(comstl_exception("Could not allocate GUID", hr));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_guid = GUID_NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

inline /* ss_explicit_k */ guid::guid(cs_char_a_t const* s)
{
    OLECHAR     osz[1 + COMSTL_CCH_GUID];
    HRESULT     hr  =   S_OK;

    switch (WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_MultiByteToWideChar(0, 0, s, -1, &osz[0], 1 + COMSTL_CCH_GUID))
    {
        case    1 + COMSTL_CCH_GUID:
            osz[COMSTL_CCH_GUID] = L'\0';
            hr = ::CLSIDFromString(osz, &m_guid);
            break;
        default:
            if (S_OK == (hr = HRESULT_FROM_WIN32(WINSTL_API_EXTERNAL_ErrorHandling_GetLastError())))
            {
                hr = E_INVALIDARG;
            }
            break;
    }

    if (FAILED(hr))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(comstl_exception("Could not convert string to valid GUID", hr));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_guid = GUID_NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

inline /* ss_explicit_k */ guid::guid(cs_char_w_t const* s)
{
    HRESULT hr  =   ::CLSIDFromString(const_cast<LPOLESTR>(s), &m_guid);

    if (FAILED(hr))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(comstl_exception("Could not convert string to valid GUID", hr));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_guid = GUID_NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

inline guid::guid(GUID const& g)
    : m_guid(g)
{}

inline guid::guid(guid const& rhs)
    : m_guid(rhs.m_guid)
{}

inline guid &guid::operator =(guid const& rhs)
{
    m_guid = rhs.m_guid;

    return *this;
}

inline guid &guid::operator =(cs_char_a_t const* s)
{
    guid    t(s);

    t.swap(*this);

    return *this;
}

inline guid &guid::operator =(cs_char_w_t const* s)
{
    guid    t(s);

    t.swap(*this);

    return *this;
}

inline guid &guid::operator =(GUID const& g)
{
    guid    t(g);

    t.swap(*this);

    return *this;
}

inline GUID const& guid::get() const
{
    return m_guid;
}

inline cs_bool_t guid::equal(class_type const& rhs) const
{
    return 0 != IsEqualGUID(m_guid, rhs.m_guid);
}

inline cs_bool_t guid::equal(GUID const& rhs) const
{
    return 0 != IsEqualGUID(m_guid, rhs);
}

inline void guid::swap(guid::class_type& rhs) STLSOFT_NOEXCEPT
{
    STLSOFT_NS_QUAL(std_swap)(m_guid, rhs.m_guid);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace comstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef COMSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::comstl::c_str_data;
using ::comstl::c_str_data_a;
using ::comstl::c_str_data_w;
using ::comstl::c_str_data_o;

using ::comstl::c_str_len;
using ::comstl::c_str_len_a;
using ::comstl::c_str_len_w;
using ::comstl::c_str_len_o;

using ::comstl::c_str_ptr;
using ::comstl::c_str_ptr_a;
using ::comstl::c_str_ptr_w;
using ::comstl::c_str_ptr_o;

using ::comstl::c_str_ptr_null;
using ::comstl::c_str_ptr_null_a;
using ::comstl::c_str_ptr_null_w;
using ::comstl::c_str_ptr_null_o;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_UTIL_HPP_COMSTL_GUID */

/* ///////////////////////////// end of file //////////////////////////// */

