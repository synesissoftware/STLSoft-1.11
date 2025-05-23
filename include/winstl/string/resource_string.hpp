/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/string/resource_string.hpp (was winstl_resource_string.h; originally MWResStr.h: ::SynesisWin)
 *
 * Purpose: basic_resource_string class.
 *
 * Created: 1st November 1994
 * Updated: 20th March 2025
 *
 * Thanks:  Ryan Ginstrom for suggesting the implementation for handling
 *          Unicode strings on Win9x.
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1994-2019, Matthew Wilson and Synesis Software
 * Copyright (c) 2004-2005, Ryan Ginstrom
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


/** \file winstl/string/resource_string.hpp
 *
 * \brief [C++] Definition of the winstl::basic_resource_string class
 *   template
 *   (\ref group__library__String "String" Library).
 */

#ifndef WINSTL_INCL_WINSTL_STRING_HPP_RESOURCE_STRING
#define WINSTL_INCL_WINSTL_STRING_HPP_RESOURCE_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_STRING_HPP_RESOURCE_STRING_MAJOR    4
# define WINSTL_VER_WINSTL_STRING_HPP_RESOURCE_STRING_MINOR    2
# define WINSTL_VER_WINSTL_STRING_HPP_RESOURCE_STRING_REVISION 14
# define WINSTL_VER_WINSTL_STRING_HPP_RESOURCE_STRING_EDIT     106
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

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES
# include <stlsoft/exception/throw_policies.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES */
#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES
# include <winstl/exception/throw_policies.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES */
#ifndef WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION_
# include <winstl/internal/windows_version_.h>
#endif /* !WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION_ */

#ifndef STLSOFT_INCL_EXCEPTION
# define STLSOFT_INCL_EXCEPTION
# include <exception>
#endif /* !STLSOFT_INCL_EXCEPTION */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */


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

/** Instances of this class represent Windows string resources, and are
 * constructed from instance identifiers.
 *
 * \ingroup group__library__String
 *
 * It is an adaptor template, so is specialised with the underlying string
 * type. For example, <code>winstl::basic_resource_string&lt;std::string&gt;</code>
 * is specialised from <code>std::string</code>, and can therefore use its methods
 * and is compatible with its client code:
 *
\code
winstl::basic_resource_string<std::string>  str(1024);

std::cout << "String with id 1024: " << str << std::endl;

printf("String with id 1024: %.*s\n", str.size(), str.data());
\endcode
 *
 * The second template parameter is the exception policy, which determines
 * how the string reacts to a failure to load a string resource corresponding
 * to the given Id. It is defaulted to stlsoft::null_exception_policy, which
 * means that, when a corresponding string resource is not loaded, the
 * resource string instance will be correctly constructed but will contain
 * the empty string, i.e.:
 *
\code
// Assuming 9999999 is not a valid string resource identifier in the
// module whose instance handle is in hinst ...
winstl::basic_resource_string<std::string>  str(hinst, 9999999);

assert(0 == str.size());
assert(str == "");
\endcode
 *
 * If you want your specialisation to throw an exception when the string
 * resource is not found, simply specify a policy that throws an exception
 * to the specialisation, as in:
 *
\code
// Assuming 9999999 is not a valid string resource identifier in the
// module whose instance handle is in hinst ...
try
{
  winstl::basic_resource_string<std::string, throw_MyX_policy>  str(hinst, 9999999);

  std::cerr << "Should never get here!!" << std::endl;
}
catch (MyX &x)
{
  std::cerr << "This is what's expected" << std::endl;
}
\endcode
 *
 * \note The handling of Unicode strings under Windows 9x family operating
 * systems eschews the use of LoadStringW(), instead manipulating the resource
 * information via FindResourceEx() / LoadResource() / LockResource(). This
 * code kindly provided by Ryan Ginstrom.
 *
 * \param S The string class, e.g. std::string, stlsoft::simple_string, etc.
 * \param X The exception class
 */
template<   ss_typename_param_k S
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        ,   ss_typename_param_k X = resource_exception_policy
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        ,   ss_typename_param_k X = STLSOFT_NS_QUAL(null_exception_policy)
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k X /* = STLSOFT_NS_QUAL(null_exception_policy) */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
// class basic_resource_string
class basic_resource_string
    : public S
    , protected X
{
private:
    typedef S                                          parent_class_type;
public:
    /// The type of the underlying string
    typedef S                                          string_type;
    /// The current specialisation of the type
    typedef basic_resource_string<S, X>                class_type;
    /// The exception policy type
    typedef X                                          exception_policy_type;
    /// The exception policy type
    ///
    /// \deprecated
    typedef exception_policy_type                      exception_type;
//    typedef STLSOFT_NS_QUAL(string_traits)<S>          string_traits_type;

    /// The value type
    typedef ss_typename_type_k string_type::value_type value_type;

/// \name Construction
/// @{
public:
    /// Constructs an around the string loaded from the given \c id
    ss_explicit_k basic_resource_string(ws_int_t id) stlsoft_throw_1(ss_typename_type_k exception_policy_type::thrown_type)
    {
        this->load_(::GetModuleHandle(NULL), id, NULL);
    }

    /// Constructs an around the string loaded from the given \c id and \c hinst
    basic_resource_string(HINSTANCE hinst, ws_int_t id) stlsoft_throw_1(ss_typename_type_k exception_policy_type::thrown_type)
    {
        this->load_(hinst, id, NULL);
    }

    /// Constructs an around the string loaded from the given \c id, or uses the given default
    ss_explicit_k basic_resource_string(ws_int_t id, value_type const* defaultValue)
    {
        this->load_(::GetModuleHandle(NULL), id, defaultValue);
    }

    /// Constructs an around the string loaded from the given \c id and \c hinst
    basic_resource_string(HINSTANCE hinst, ws_int_t id, value_type const* defaultValue)
    {
        this->load_(hinst, id, defaultValue);
    }

    /// Copy constructor
    basic_resource_string(class_type const& rhs)
        : parent_class_type(rhs)
    {}

    /// Copy constructor
    basic_resource_string(string_type const& rhs)
        : parent_class_type(rhs)
    {}

    /// Copy assignment operator
    class_type& operator =(class_type const& rhs)
    {
        parent_class_type::operator =(rhs);

        return *this;
    }
    /// Copy assignment operator
    class_type& operator =(string_type const& rhs)
    {
        parent_class_type::operator =(rhs);

        return *this;
    }
/// @}

// Implementation
private:
    ws_int_t load_string_(HINSTANCE hinst, int uID, ws_char_a_t *buffer, ws_size_t cchBuffer)
    {
        return ::LoadStringA(hinst, static_cast<UINT>(uID), buffer, static_cast<int>(cchBuffer));
    }
    ws_int_t load_string_(HINSTANCE hinst, int uID, ws_char_w_t *buffer, ws_size_t cchBuffer)
    {
        if (winstl_C_internal_IsWindows9x(NULL, NULL, NULL))
        {
            // This block of code kindly provided by Ryan Ginstrom
            int     block   =   (uID >> 4) + 1; // Compute block number.
            int     num     =   uID & 0xf;      // Compute offset into block.
            HRSRC   hRC     =   ::FindResourceEx(   hinst
                                                ,   RT_STRING
                                                ,   MAKEINTRESOURCE(block)
                                                ,   MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL));

            if (NULL != hRC)
            {
                HGLOBAL hgl = ::LoadResource(hinst, hRC);

                if (NULL != hgl)
                {
                    LPWSTR  res_str =   (LPWSTR)::LockResource(hgl);

                    if (NULL != res_str)
                    {
                        for (int i = 0; i < num; ++i)
                        {
                            res_str += *res_str + 1;
                        }

                        const LPCWSTR   ptr =   res_str + 1;
                        const ws_size_t cch =   static_cast<ws_size_t>(*res_str);

                        if (cch < cchBuffer)
                        {
                            cchBuffer = cch + 1; // This is +1, since lstrcpyn 'uses' a character for the nul character
                            buffer[cch] = L'\0';
                        }

                        ::lstrcpynW(buffer, ptr, static_cast<int>(cchBuffer));

                        return static_cast<ws_int_t>(cchBuffer);
                    }
                }
            }

            return 0;
        }

        return ::LoadStringW(hinst, static_cast<UINT>(uID), buffer, static_cast<int>(cchBuffer));
    }

    void load_(HINSTANCE hinst, ws_int_t id, value_type const* defaultValue) stlsoft_throw_1(ss_typename_type_k exception_policy_type::thrown_type)
    {
        // TODO: Verify that it's not possible to load string resources of >256. If that's
        // wrong, then need to fix this to use auto_buffer
        value_type  sz[1024];

        if (0 == this->load_string_(hinst, id, sz, STLSOFT_NUM_ELEMENTS(sz)))
        {
            if (NULL != defaultValue)
            {
                parent_class_type::operator =(defaultValue);
            }
            else
            {
                exception_policy_type()("string did not load", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError(), MAKEINTRESOURCE(id), RT_STRING);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# if defined(STLSOFT_COMPILER_IS_MSVC)
#  if _MSC_VER >= 1200
#   pragma warning(push)
#   pragma warning(disable : 4702)
#  endif /* _MSC_VER */
# endif /* compiler */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

                this->parent_class_type::clear();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# if defined(STLSOFT_COMPILER_IS_MSVC)
#  if _MSC_VER >= 1200
#   pragma warning(pop)
#  endif /* _MSC_VER */
# endif /* compiler */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
        }
        else
        {
            parent_class_type::operator =(sz);
        }
    }
};


/* /////////////////////////////////////////////////////////////////////////
 * creator functions
 */

//inline make_resource_string


/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

#if 0
/* c_str_ptr_null */

/** Returns the corresponding C-string pointer of \c s, or a null pointer
 *
 * \ingroup group__library__String
 */
template<   ss_typename_param_k S
        ,   ss_typename_param_k X
        >
inline C const* c_str_ptr_null(basic_resource_string<S, X> const& s)
{
    return (s.length() == 0) ? 0 : s.c_str();
}

/* c_str_ptr */

/** Returns the corresponding C-string pointer of \c s
 *
 * \ingroup group__library__String
 */
template<   ss_typename_param_k S
        ,   ss_typename_param_k X
        >
inline C const* c_str_ptr(basic_resource_string<S, X> const& s)
{
    return s.c_str();
}

/* c_str_ptr */

/** Returns the corresponding C-string pointer of \c s
 *
 * \ingroup group__library__String
 */
template<   ss_typename_param_k S
        ,   ss_typename_param_k X
        >
inline C const* c_str_data(basic_resource_string<S, X> const& s)
{
    return s.c_str();
}

/* c_str_ptr_len */

/** Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
 *
 * \ingroup group__library__String
 */
template<   ss_typename_param_k S
        ,   ss_typename_param_k X
        >
inline ss_size_t c_str_len(basic_resource_string<S, X> const& s)
{
    return s.length();
}
#endif /* 0 */


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
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_STRING_HPP_RESOURCE_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

