/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/filesystem/file_path_buffer.hpp
 *
 * Purpose: Contains the basic_file_path_buffer template class, and ANSI and
 *          Unicode specialisations thereof.
 *
 * Created: 7th February 2002
 * Updated: 20th March 2025
 *
 * Thanks:  Pablo Aguilar for discovering the Borland weirdness which is now
 *          addressed with the calc_path_max_() method.
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


/** \file winstl/filesystem/file_path_buffer.hpp
 *
 * \brief [C++] Definition of the winstl::basic_file_path_buffer class
 *  template
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_MAJOR    4
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_MINOR    6
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_REVISION 16
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_EDIT     155
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

#ifdef STLSOFT_PPF_pragma_message_SUPPORT
# pragma message(STLSOFT_FILELINE_MESSAGE("This file and the (basic_)file_path_buffer<> component are deprecated, and will be removed from a future version"))
#endif /* STLSOFT_PPF_pragma_message_SUPPORT */

#ifndef WINSTL_FILE_PATH_BUFFER_NO_USE_AUTO_BUFFER
# define WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER
#endif

#if defined(STLSOFT_COMPILER_IS_MSVC)
# if _MSC_VER < 1100
#  error winstl/filesystem/file_path_buffer.hpp is not compatible with Visual C++ prior to version 5.0
# elif _MSC_VER < 1200
#  undef WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER
# else /* ? _MSC_VER */
   /* Nothing to do */
# endif /* _MSC_VER */
#endif /* compiler */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifdef WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER
# ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
#  include <stlsoft/memory/auto_buffer.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#else /* ? WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER */
# include <vector>
#endif /* WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_COPY_FUNCTIONS
# include <stlsoft/string/copy_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_COPY_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION_
# include <winstl/internal/windows_version_.h>
#endif /* !WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION_ */

#ifdef STLSOFT_DEBUG
# include <stlsoft/algorithms/pod.hpp>
#endif /* STLSOFT_DEBUG */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_memfns
# include <stlsoft/api/external/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_memfns */


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

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template <ss_typename_param_k C>
struct is_ansi
{
    enum { value = 0 };
};

STLSOFT_TEMPLATE_SPECIALISATION
struct is_ansi<ws_char_a_t>
{
    enum { value = 1 };
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

// class basic_file_path_buffer
/** Acts as a buffer with sufficient size for any drive on the host machine
 *
 * \ingroup group__library__FileSystem
 *
 * This class is a non-template class primarily so that separate instantiations
 * are not created for each instantiation of the basic_file_path_buffer.
 *
 * This class provides a simple function, which is to provide the maximum path
 * length for the host. This information is then cached due to the static nature
 * of the get_drivesvar_() method, although it can be reset by calling the
 * refresh() method on the buffer class.
 *
 * \tparam C The character type
 * \tparam A The allocator type
 */
template <
    ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k A = processheap_allocator<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k A /* = processheap_allocator<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>
class basic_file_path_buffer
{
/// \name Member Constants
/// @{
private:
    enum
    {
        internalBufferSize = 1 + WINSTL_CONST_MAX_PATH
    };

    enum
    {
            CCH_9x = WINSTL_CONST_MAX_PATH
        ,   CCH_NT = (is_ansi<C>::value ? WINSTL_CONST_MAX_PATH : CONST_NT_MAX_PATH)
    };

    /// The buffer type
#ifdef WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        C
# if defined(STLSOFT_COMPILER_IS_BORLAND)
    // This is necessary, since Borland will attempt an auto_buffer with what
    // seems like 0 size, or maybe it just can't define the type. Who can tell?
    ,   1 + WINSTL_CONST_MAX_PATH
# else /* ? compiler */
    ,   internalBufferSize
# endif /* compiler */
    ,   A
    >                                                       buffer_type;
#else /* ? WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER */
    typedef STLSOFT_NS_QUAL_STD(vector)<C, A>               buffer_type;
#endif /* WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER */
/// @}

/// \name Member Types
/// @{
public:
    /// The character type
    typedef C                                               char_type;
    /// The allocator type
    typedef A                                               allocator_type;
    /// The current specialisation of the type
    typedef basic_file_path_buffer<C, A>                    class_type;
    /// The value type
    typedef ss_typename_type_k buffer_type::value_type      value_type;
    /// The reference type
    typedef value_type&                                     reference;
    /// The non-mutating (const) reference type
    typedef value_type const&                               const_reference;
    /// The size type
    typedef ss_typename_type_k buffer_type::size_type       size_type;
/// @}

/// \name Construction
/// @{
public:
    /// Default constructor
    STLSOFT_DEPRECATED_("basic_file_path_buffer is deprecated, and will be removed from a future release") // applied here rather than on template because above class_type precipitates
    basic_file_path_buffer()
        : m_buffer(1 + calc_path_max_internal_())
    {
#ifdef STLSOFT_DEBUG

        STLSOFT_NS_QUAL(pod_fill_n)(&m_buffer[0], external_size_(), static_cast<char_type>('?'));
        m_buffer[external_size_() - 1] = '\0';

        set_eyecatcher_();
#endif /* STLSOFT_DEBUG */

        WINSTL_ASSERT(is_valid_());
    }
    /// Copy constructor
    basic_file_path_buffer(class_type const& rhs)
        : m_buffer(rhs.internal_size_())
    {
        WINSTL_ASSERT(rhs.is_valid_());

#ifdef STLSOFT_DEBUG

        set_eyecatcher_();
#endif /* STLSOFT_DEBUG */

        STLSOFT_NS_QUAL(pod_copy_n)(&m_buffer[0], &rhs.m_buffer[0], external_size_());

        WINSTL_ASSERT(is_valid_());
    }
    /// Copy assignment operator
    class_type& operator =(class_type const& rhs)
    {
        WINSTL_ASSERT(is_valid_());

        m_buffer.resize(rhs.internal_size_());
        STLSOFT_NS_QUAL(pod_copy_n)(&m_buffer[0], &rhs.m_buffer[0], external_size_());

        WINSTL_ASSERT(is_valid_());

        return *this;
    }
/// @}

/// \name Operations
/// @{
public:
    /// Swaps the contents with those of another instance
    ///
    /// \param rhs The instance whose contents will be swapped with the
    ///  callee
    ///
    /// \note The complexity of this operation is not guaranteed
    ///  to be constant-time. See the documentation for
    ///  \link stlsoft::auto_buffer auto_buffer\endlink for
    ///  further details.
    void swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
        m_buffer.swap(rhs.m_buffer);
    }

    void resize(size_type )
    {}
/// @}

/// \name Accessors
/// @{
public:
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    value_type const* data() const
    {
        WINSTL_ASSERT(is_valid_());

#ifdef WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER
        return m_buffer.data();
#else /* ? WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER */
        return &m_buffer[0];
#endif /* WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER */
    }
    value_type* data()
    {
        WINSTL_ASSERT(is_valid_());

#ifdef WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER
        return m_buffer.data();
#else /* ? WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER */
        return &m_buffer[0];
#endif /* WINSTL_FILE_PATH_BUFFER_USE_AUTO_BUFFER */
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    /// Returns a pointer to a nul-terminated string
    value_type const* c_str() const
    {
        WINSTL_ASSERT(is_valid_());

        return this->data();
    }

    /// Returns a mutable (non-const) pointer to an element in the buffer
    reference operator [](ws_size_t index)
    {
        WINSTL_ASSERT(is_valid_());

        buffer_type& this_ = m_buffer;

        return this_[index];
    }
#if !defined(STLSOFT_COMPILER_IS_COMO) || \
    __COMO_VERSION__ >= 4303
    /// Returns a non-mutable (const) pointer to an element in the buffer
    const_reference operator [](ws_size_t index) const
    {
        WINSTL_MESSAGE_ASSERT("Index out of range", !(size() < index));

        return data()[index];
    }
#else /* ? compiler */
#endif /* compiler */

    /// Returns the size of the buffer
    size_type size() const
    {
        WINSTL_ASSERT(is_valid_());

        return external_size_();
    }

    /// Returns the capacity of the buffer
    size_type capacity() const
    {
        WINSTL_ASSERT(is_valid_());

        return external_size_();
    }

    /// Returns the maximum size of the buffer
    static size_type max_size()
    {
        return calc_path_max_external_();
    }

    /// Copies the contents into a caller supplied buffer
    ///
    /// \param buffer Pointer to character buffer to receive the contents.
    ///  May be \c nullptr, in which case the method returns size().
    /// \param cchBuffer Number of characters of available space in \c buffer.
    size_type copy(char_type *buffer, size_type cchBuffer) const
    {
        WINSTL_ASSERT(is_valid_());

        return STLSOFT_NS_QUAL(copy_contents)(buffer, cchBuffer, m_buffer.data(), external_size_());
    }
/// @}

/// \name Operations
/// @{
public:
    /// Causes the drives to be examined again for the next instance.
    ///
    /// \deprecated
    static void refresh() STLSOFT_NOEXCEPT
    {}
/// @}

/// \name Implementation
/// @{
private:
#ifdef STLSOFT_DEBUG

    static
    char_type const*
    get_eyecatcher_(
        size_type*  size
    )
    {
        static char_type const s_eyeCatcher[] = { 'd', 'e', 'a', 'd', 'b', 'e', 'e', 'f' };

        *size = STLSOFT_NUM_ELEMENTS(s_eyeCatcher);

        return s_eyeCatcher;
    }

    void
    set_eyecatcher_()
    {
        size_type               ecs;
        char_type const* const  ec  =   get_eyecatcher_(&ecs);
        size_type const         n   =   m_buffer.size() - ecs;
        char_type *             p   =   &m_buffer[0] + n;

        STLSOFT_API_EXTERNAL_memfns_memcpy(p, ec, sizeof(char_type) * ecs);
    }

    static
    size_type
    get_eyecatcher_size_()
    {
        size_type ecs;

        get_eyecatcher_(&ecs);

        return ecs;
    }
#endif

    bool is_valid_() const
    {
#ifdef STLSOFT_DEBUG

        {
            size_type               ecs;
            char_type const* const  ec  =   get_eyecatcher_(&ecs);
            size_type const         n   =   m_buffer.size() - ecs;
            char_type const*        p   =   &m_buffer[0] + n;

            if (0 != STLSOFT_API_EXTERNAL_memfns_memcmp(p, ec, sizeof(char_type) * ecs))
            {
                return false;
            }
        }
#endif

        return true;
    }

    // Have to do it this way, as an inline, in-MIL tertiary operator causes
    // Borland C++ to think that the answer's 5! 'tis a mysterious beastie,
    // the old Borland compiler, is it not?
    static size_type calc_path_max_external_()
    {
        size_type   n;

        if (winstl_C_internal_IsWindows9x(NULL, NULL, NULL))
        {
            n = CCH_9x;
        }
        else
        {
            n = CCH_NT;
        }

        return n;
    }

    static size_type calc_path_max_internal_()
    {
        size_type n = calc_path_max_external_();

#ifdef STLSOFT_DEBUG

        // add bytes for eye catcher
        n += get_eyecatcher_size_();
#endif

        return n;
    }

    size_type
    internal_size_() const
    {
        return m_buffer.size();
    }

    size_type
    external_size_() const
    {
        size_type n = internal_size_();

#ifdef STLSOFT_DEBUG

        // add bytes for eye catcher
        n -= get_eyecatcher_size_();
#endif

        return n;
    }
/// @}

/// \name Members
/// @{
private:
    buffer_type         m_buffer;
/// @}
};

/* Typedefs to commonly encountered types. */
/** Specialisation of the basic_file_path_buffer template for the ANSI character type \c char
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_file_path_buffer<
    ws_char_a_t
,   processheap_allocator<ws_char_a_t>
>                                                           file_path_buffer_a;
/** Specialisation of the basic_file_path_buffer template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_file_path_buffer<
    ws_char_w_t
,   processheap_allocator<ws_char_w_t>
>                                                           file_path_buffer_w;
/** Specialisation of the basic_file_path_buffer template for the ambient character type \c TCHAR
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_file_path_buffer<
    TCHAR
,   processheap_allocator<TCHAR>
>                                                           file_path_buffer;

/* /////////////////////////////////////////////////////////////////////////
 * Support for PlatformSTL redefinition by inheritance+namespace, for confused
 * compilers (e.g. VC++ 6)
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
            ,   ss_typename_param_k A = WINSTL_NS_QUAL(processheap_allocator)<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            ,   ss_typename_param_k A /* = processheap_allocator<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            >
    class basic_file_path_buffer__
        : public WINSTL_NS_QUAL(basic_file_path_buffer)<C, A>
    {
    private:
        typedef WINSTL_NS_QUAL(basic_file_path_buffer)<C, A>            parent_class_type;
    public:
        typedef basic_file_path_buffer__<C, A>                          class_type;
        typedef ss_typename_type_k parent_class_type::value_type        value_type;
        typedef ss_typename_type_k parent_class_type::reference         reference;
        typedef ss_typename_type_k parent_class_type::const_reference   const_reference;
        typedef ss_typename_type_k parent_class_type::size_type         size_type;
    };

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline void swap(basic_file_path_buffer<C, A>& lhs, basic_file_path_buffer<C, A>& rhs)
{
    lhs.swap(rhs);
}


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k A>
inline ws_char_a_t const* c_str_data_a(WINSTL_NS_QUAL(basic_file_path_buffer)<ws_char_a_t, A> const& b)
{
    return b.c_str();
}
template <ss_typename_param_k A>
inline ws_char_w_t const* c_str_data_w(WINSTL_NS_QUAL(basic_file_path_buffer)<ws_char_w_t, A> const& b)
{
    return b.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_data for winstl::basic_file_path_buffer
 *
 * \ingroup group__concept__Shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C const* c_str_data(WINSTL_NS_QUAL(basic_file_path_buffer)<C, A> const& b)
{
    return b.c_str();
}


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k A>
inline ws_size_t c_str_len_a(WINSTL_NS_QUAL(basic_file_path_buffer)<ws_char_a_t, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_len_a)(b.c_str());
}
template <ss_typename_param_k A>
inline ws_size_t c_str_len_w(WINSTL_NS_QUAL(basic_file_path_buffer)<ws_char_w_t, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_len_w)(b.c_str());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for winstl::basic_file_path_buffer
 *
 * \ingroup group__concept__Shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline ws_size_t c_str_len(WINSTL_NS_QUAL(basic_file_path_buffer)<C, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_len)(b.c_str());
}


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k A>
inline ws_char_a_t const* c_str_ptr_a(WINSTL_NS_QUAL(basic_file_path_buffer)<ws_char_a_t, A> const& b)
{
    return b.c_str();
}
template <ss_typename_param_k A>
inline ws_char_w_t const* c_str_ptr_w(WINSTL_NS_QUAL(basic_file_path_buffer)<ws_char_w_t, A> const& b)
{
    return b.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr for winstl::basic_file_path_buffer
 *
 * \ingroup group__concept__Shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C const* c_str_ptr(WINSTL_NS_QUAL(basic_file_path_buffer)<C, A> const& b)
{
    return b.c_str();
}



#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k A>
inline ws_char_a_t const* c_str_ptr_null_a(WINSTL_NS_QUAL(basic_file_path_buffer)<ws_char_a_t, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null)(b.c_str());
}
template <ss_typename_param_k A>
inline ws_char_w_t const* c_str_ptr_null_w(WINSTL_NS_QUAL(basic_file_path_buffer)<ws_char_w_t, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null)(b.c_str());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for winstl::basic_file_path_buffer
 *
 * \ingroup group__concept__Shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C const* c_str_ptr_null(WINSTL_NS_QUAL(basic_file_path_buffer)<C, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null)(b.c_str());
}




/** \ref group__concept__Shim__stream_insertion "stream insertion shim" for winstl::basic_file_path_buffer
 *
 * \ingroup group__concept__Shim__stream_insertion
 */
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline S& operator <<(S& s, WINSTL_NS_QUAL(basic_file_path_buffer)<C, A> const& b)
{
    s << b.c_str();

    return s;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* In the special case of Intel behaving as VC++ 7.0 or earlier on Win32, we
 * illegally insert into the std namespace.
 */
#if defined(STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template<   ss_typename_param_k C
            ,   ss_typename_param_k A
            >
    inline void swap(WINSTL_NS_QUAL(basic_file_path_buffer)<C, A>& lhs, WINSTL_NS_QUAL(basic_file_path_buffer)<C, A>& rhs)
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */


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

using ::winstl::c_str_ptr_null;
using ::winstl::c_str_ptr_null_a;
using ::winstl::c_str_ptr_null_w;

using ::winstl::c_str_ptr;
using ::winstl::c_str_ptr_a;
using ::winstl::c_str_ptr_w;

using ::winstl::c_str_data;
using ::winstl::c_str_data_a;
using ::winstl::c_str_data_w;

using ::winstl::c_str_len;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */

