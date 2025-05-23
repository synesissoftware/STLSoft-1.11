/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/clipboard/clipboard_scope.hpp
 *
 * Purpose: Clipboard scoping and facade class.
 *
 * Created: 26th May 2005
 * Updated: 20th March 2025
 *
 * Thanks:  To Martin Moene for reporting the problem with the data type in
 *          set_data_or_deallocate_and_throw_(), and for calling for
 *          clarification of the get_data() semantics
 *
 * Home:    http://stlsoft.org/
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


/** \file winstl/clipboard/clipboard_scope.hpp
 *
 * \brief [C++] Definition of the winstl::clipboard_scope class
 *   (\ref group__library__Windows_Clipboard "Windows Clipboard" Library).
 */

#ifndef WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE
#define WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE_MAJOR      2
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE_MINOR      1
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE_REVISION   4
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE_EDIT       60
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

#ifndef WINSTL_INCL_WINSTL_CLIPBOARD_ERROR_HPP_EXCEPTIONS
# include <winstl/clipboard/error/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_CLIPBOARD_ERROR_HPP_EXCEPTIONS */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_GLOBAL_ALLOCATOR
# include <winstl/memory/global_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_GLOBAL_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE
# include <stlsoft/memory/allocator_base.hpp>       // for STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_FEATURES
# include <stlsoft/memory/util/allocator_features.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_FEATURES */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_FUNCTIONS
# include <stlsoft/string/cstring_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_FUNCTIONS */

#ifndef STLSOFT_INCL_H_SHELLAPI
# define STLSOFT_INCL_H_SHELLAPI
# include <shellapi.h>
#endif /* !STLSOFT_INCL_H_SHELLAPI */

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

/** Indicates failure to access or manipulate the Windows clipboard.
 *
 * \ingroup group__library__Windows_Clipboard
 *
 * \see winstl::clipboard_scope
 */
class clipboard_scope_exception
    : public clipboard_exception
{
/// \name Member Types
/// @{
public:
    /// The parent class type
    typedef clipboard_exception                             parent_class_type;
    /// The class type
    typedef clipboard_scope_exception                       class_type;
/// @}

/// \name Construction
/// @{
public:
    clipboard_scope_exception(char const* reason, status_code_type sc)
        : clipboard_exception(reason, sc)
    {}
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

};

/** This class acquires access to the Win32 clipboard, and acts as
 *   a facade over the clipboard API.
 *
 * \ingroup group__library__Windows_Clipboard
 *
 * The class provides a simple and straightforward facade to the clipboard,
 * while at the same time acquiring and releasing ownership of the
 * clipboard. The following code acquires access to the clipboard, and sets
 * a string on to it:
\code
  // 1. Set the data on the clipboard
  {
    winstl::clipboard_scope     scope;

    scope.set_data("The data");
  }
\endcode
 *
 * As long as no other thread/process changes the clipboard contents in the
 * meanwhile, this can then be read back, as follows:
 *
\code
  // 2. Get the data from the clipboard
  {
    winstl::clipboard_scope     scope;
    char const*                 str;

    scope.get_data(str);

    std::cout << "Clipboard data: " << str << std::endl;
  }
\endcode
 *
 * In each case, the lifetime of the
 * \link winstl::clipboard_scope clipboard_scope\endlink is scoped with a
 * block - <code>{ }</code> - in order to release ownership of the
 * clipboard.
 *
 * \note All the methods throw an instance of
 *   \link winstl::clipboard_scope_exception clipboard_scope_exception\endlink
 *   if they fail.
 */
class clipboard_scope
#if defined(STLSOFT_COMPILER_IS_DMC)
    : protected global_allocator<void>
#else /* ? compiler */
    : private global_allocator<void>
#endif /* compiler */
{
/// \name Types
/// @{
private:
    typedef global_allocator<void>  parent_class_type;
public:
    typedef clipboard_scope         class_type;
    typedef global_allocator<void>  allocator_type;
/// @}

/// \name Construction
/// @{
public:
    /// Takes ownership of the clipboard
    ///
    /// \param hwndOwner Window to be associated as owner of the clipboard.
    ///   May be \c nullptr, in which case the current thread owns the
    ///   clipboard.
    ss_explicit_k clipboard_scope(HWND hwndOwner = NULL) stlsoft_throw_1(clipboard_scope_exception);
    /// Gives up ownership of the clipboard.
    ~clipboard_scope() STLSOFT_NOEXCEPT;
/// @}

/// \name Attributes
/// @{
public:
    /// Returns a copy of the allocator used by the class.
    allocator_type  get_allocator() const;
/// @}

/// \name Operations
/// @{
public:
    /// Empties the clipboard.
    void    clear() stlsoft_throw_1(clipboard_scope_exception);

    /// Returns the current owner of the clipboard.
    HWND    owner() const;

    /// Indicates whether a given format is available.
    ws_bool_t   is_fmt_available(UINT fmt) const;

    /// Sets the given data with the given format into the clipboard.
    void    set_data(UINT fmt, HANDLE hData) stlsoft_throw_1(clipboard_scope_exception);

    /// Sets the given text to the clipboard with CF_TEXT format.
    void    set_data(char const* str) stlsoft_throw_1(clipboard_scope_exception);
    /// Sets the given text to the clipboard with CF_TEXT format.
    void    set_data(char const* str, ws_size_t n) stlsoft_throw_1(clipboard_scope_exception);

    /// Sets the given text to the clipboard with CF_UNICODETEXT format.
    void    set_data(wchar_t const* str) stlsoft_throw_1(clipboard_scope_exception);
    /// Sets the given text to the clipboard with CF_UNICODETEXT format.
    void    set_data(wchar_t const* str, ws_size_t n) stlsoft_throw_1(clipboard_scope_exception);


    /// Sets the bitmap to the clipboard with CF_BITMAP format.
    void    set_bitmap_data(HBITMAP hBmp) stlsoft_throw_1(clipboard_scope_exception);
    /// Sets the bitmap to the clipboard with CF_HDROP format.
    void    set_drop_data(HDROP hDrop) stlsoft_throw_1(clipboard_scope_exception);
    /// Sets the bitmap to the clipboard with CF_ENHMETAFILE format.
    void    set_emf_data(HENHMETAFILE hEmf) stlsoft_throw_1(clipboard_scope_exception);
    /// Sets the bitmap to the clipboard with CF_PALETTE format.
    void    set_palette_data(HPALETTE hPal) stlsoft_throw_1(clipboard_scope_exception);

#ifdef STRICT

    /// Sets the bitmap to the clipboard with CF_BITMAP format.
    void    set_data(HBITMAP hBmp) stlsoft_throw_1(clipboard_scope_exception);
    /// Sets the bitmap to the clipboard with CF_HDROP format.
    void    set_data(HDROP hDrop) stlsoft_throw_1(clipboard_scope_exception);
    /// Sets the bitmap to the clipboard with CF_ENHMETAFILE format.
    void    set_data(HENHMETAFILE hEmf) stlsoft_throw_1(clipboard_scope_exception);
    /// Sets the bitmap to the clipboard with CF_PALETTE format.
    void    set_data(HPALETTE hPal) stlsoft_throw_1(clipboard_scope_exception);
#endif

    /// Gets the data with the requested format from the clipboard
    ///
    /// \note The handle must be used before the clipboard_scope destructor is
    ///   invoked, or its contents copied
    HANDLE  get_data(UINT fmt) const stlsoft_throw_1(clipboard_scope_exception);

    /// Gets the clipboard data with the CF_TEXT format.
    ///
    /// \note The string pointer must be used before the clipboard_scope destructor is
    ///   invoked, or its contents copied
    void    get_data(char const*& str) const stlsoft_throw_1(clipboard_scope_exception);

    /// Gets the clipboard data with the CF_UNICODETEXT format.
    ///
    /// \note The string pointer must be used before the clipboard_scope destructor is
    ///   invoked, or its contents copied
    void    get_data(wchar_t const*& str) const stlsoft_throw_1(clipboard_scope_exception);

    /// Gets the clipboard data with the CF_BITMAP format.
    ///
    /// \note The bitmap handle must be used before the clipboard_scope destructor is
    ///   invoked, or its contents copied
    void    get_bitmap_data(HBITMAP& hBmp) const stlsoft_throw_1(clipboard_scope_exception);
    /// Gets the clipboard data with the CF_HDROP format.
    ///
    /// \note The drop handle must be used before the clipboard_scope destructor is
    ///   invoked, or its contents copied
    void    get_drop_data(HDROP& hDrop) const stlsoft_throw_1(clipboard_scope_exception);
    /// Gets the clipboard data with the CF_ENHMETAFILE format.
    ///
    /// \note The metafile handle must be used before the clipboard_scope destructor is
    ///   invoked, or its contents copied
    void    get_emf_data(HENHMETAFILE& hEmf) const stlsoft_throw_1(clipboard_scope_exception);
    /// Gets the clipboard data with the CF_PALETTE format.
    ///
    /// \note The palette handle must be used before the clipboard_scope destructor is
    ///   invoked, or its contents copied
    void    get_palette_data(HPALETTE& hPal) const stlsoft_throw_1(clipboard_scope_exception);

#ifdef STRICT

    /// Gets the clipboard data with the CF_BITMAP format.
    ///
    /// \see get_bitmap_data()
    void    get_data(HBITMAP& hBmp) const stlsoft_throw_1(clipboard_scope_exception);
    /// Gets the clipboard data with the CF_HDROP format.
    ///
    /// \see get_drop_data()
    void    get_data(HDROP& hDrop) const stlsoft_throw_1(clipboard_scope_exception);
    /// Gets the clipboard data with the CF_ENHMETAFILE format.
    ///
    /// \see get_emf_data()
    void    get_data(HENHMETAFILE& hEmf) const stlsoft_throw_1(clipboard_scope_exception);
    /// Gets the clipboard data with the CF_PALETTE format.
    ///
    /// \see get_palette_data()
    void    get_data(HPALETTE& hPal) const stlsoft_throw_1(clipboard_scope_exception);
#endif
/// @}

/// \name Members
/// @{
private:
    template<
        ss_typename_param_k A
    ,   ss_typename_param_k T
    >
    void
    set_data_or_deallocate_and_throw_(
        UINT    fmt
    ,   T*      memory
    ,   size_t  n
    ,   A&      ator
    ) stlsoft_throw_1(clipboard_scope_exception)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

            set_data(fmt, static_cast<HANDLE>(memory));

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        }
        catch (...)
        {
# ifdef STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
            ator.deallocate(memory, n);
# else /* ? STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */
            STLSOFT_SUPPRESS_UNUSED(n);

            ator.deallocate(memory);
# endif /* STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */

            throw;
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
/// @}

/// \name Members
/// @{
private:
    clipboard_scope(class_type const&);
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */


/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline clipboard_scope::clipboard_scope(HWND hwndOwner /* = NULL */) stlsoft_throw_1(clipboard_scope_exception)
{
    if (!::OpenClipboard(hwndOwner))
    {
        STLSOFT_THROW_X(clipboard_scope_exception("Cannot open clipboard", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
    }
}

inline clipboard_scope::~clipboard_scope() STLSOFT_NOEXCEPT
{
    ::CloseClipboard();
}

inline clipboard_scope::allocator_type clipboard_scope::get_allocator() const
{
    allocator_type const& ator = *this;

    return ator;
}

inline void clipboard_scope::clear() stlsoft_throw_1(clipboard_scope_exception)
{
    if (!::EmptyClipboard())
    {
        STLSOFT_THROW_X(clipboard_scope_exception("Cannot empty clipboard", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
    }
}

inline HWND clipboard_scope::owner() const
{
    HWND hwnd = ::GetClipboardOwner();

    if (NULL == hwnd &&
        ERROR_SUCCESS != WINSTL_API_EXTERNAL_ErrorHandling_GetLastError())
    {
        STLSOFT_THROW_X(clipboard_scope_exception("Cannot get clipboard owner", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
    }

    return hwnd;
}

inline ws_bool_t clipboard_scope::is_fmt_available(UINT fmt) const
{
    return BOOL2bool(::IsClipboardFormatAvailable(fmt));
}

inline void clipboard_scope::set_data(UINT fmt, HANDLE hData) stlsoft_throw_1(clipboard_scope_exception)
{
    if (NULL == ::SetClipboardData(fmt, hData))
    {
        STLSOFT_THROW_X(clipboard_scope_exception("Cannot set clipboard data", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
    }
}

inline void clipboard_scope::set_data(char const* str) stlsoft_throw_1(clipboard_scope_exception)
{
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    allocator_type::rebind<char>::other     ator(*this);
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    global_allocator<char>                  ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    size_t                                  n;
    char*                                   memory = STLSOFT_NS_QUAL(string_dup)(str, ator, &n);

    set_data_or_deallocate_and_throw_(CF_TEXT, memory, n, ator);
}

inline void clipboard_scope::set_data(char const* str, ws_size_t n) stlsoft_throw_1(clipboard_scope_exception)
{
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    allocator_type::rebind<char>::other     ator(*this);
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    global_allocator<char>                  ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    char*                                   memory = STLSOFT_NS_QUAL(string_dup)(str, n, ator);

    set_data_or_deallocate_and_throw_(CF_TEXT, memory, n, ator);
}

inline void clipboard_scope::set_data(wchar_t const* str) stlsoft_throw_1(clipboard_scope_exception)
{
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    allocator_type::rebind<wchar_t>::other  ator(*this);
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    global_allocator<wchar_t>               ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    size_t                                  n;
    wchar_t*                                memory = STLSOFT_NS_QUAL(string_dup)(str, ator, &n);

    set_data_or_deallocate_and_throw_(CF_UNICODETEXT, memory, n, ator);
}

inline void clipboard_scope::set_data(wchar_t const* str, ws_size_t n) stlsoft_throw_1(clipboard_scope_exception)
{
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    allocator_type::rebind<wchar_t>::other  ator(*this);
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    global_allocator<wchar_t>               ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    wchar_t*                                memory = STLSOFT_NS_QUAL(string_dup)(str, n, ator);

    set_data_or_deallocate_and_throw_(CF_UNICODETEXT, memory, n, ator);
}

inline void clipboard_scope::set_bitmap_data(HBITMAP hBmp) stlsoft_throw_1(clipboard_scope_exception)
{
    set_data(CF_BITMAP, hBmp);
}

inline void clipboard_scope::set_drop_data(HDROP hDrop) stlsoft_throw_1(clipboard_scope_exception)
{
    set_data(CF_HDROP, hDrop);
}

inline void clipboard_scope::set_emf_data(HENHMETAFILE hEmf) stlsoft_throw_1(clipboard_scope_exception)
{
    set_data(CF_ENHMETAFILE, hEmf);
}

inline void clipboard_scope::set_palette_data(HPALETTE hPal) stlsoft_throw_1(clipboard_scope_exception)
{
    set_data(CF_PALETTE, hPal);
}

#ifdef STRICT

inline void clipboard_scope::set_data(HBITMAP hBmp) stlsoft_throw_1(clipboard_scope_exception)
{
    set_bitmap_data(hBmp);
}
inline void clipboard_scope::set_data(HDROP hDrop) stlsoft_throw_1(clipboard_scope_exception)
{
    set_drop_data(hDrop);
}
inline void clipboard_scope::set_data(HENHMETAFILE hEmf) stlsoft_throw_1(clipboard_scope_exception)
{
    set_emf_data(hEmf);
}
inline void clipboard_scope::set_data(HPALETTE hPal) stlsoft_throw_1(clipboard_scope_exception)
{
    set_palette_data(hPal);
}
#endif

inline HANDLE clipboard_scope::get_data(UINT fmt) const stlsoft_throw_1(clipboard_scope_exception)
{
    HANDLE hData = ::GetClipboardData(fmt);

    if (NULL == hData &&
        ERROR_SUCCESS != WINSTL_API_EXTERNAL_ErrorHandling_GetLastError())
    {
        STLSOFT_THROW_X(clipboard_scope_exception("Cannot get clipboard data", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
    }

    return hData;
}

inline void clipboard_scope::get_data(char const*& str) const stlsoft_throw_1(clipboard_scope_exception)
{
    str = static_cast<char const*>(get_data(CF_TEXT));
}

inline void clipboard_scope::get_data(wchar_t const*& str) const stlsoft_throw_1(clipboard_scope_exception)
{
    str = static_cast<wchar_t const*>(get_data(CF_UNICODETEXT));
}

inline void clipboard_scope::get_bitmap_data(HBITMAP& hBmp) const stlsoft_throw_1(clipboard_scope_exception)
{
    hBmp = static_cast<HBITMAP>(get_data(CF_BITMAP));
}

inline void clipboard_scope::get_drop_data(HDROP& hDrop) const stlsoft_throw_1(clipboard_scope_exception)
{
    hDrop = static_cast<HDROP>(get_data(CF_HDROP));
}

inline void clipboard_scope::get_emf_data(HENHMETAFILE& hEmf) const stlsoft_throw_1(clipboard_scope_exception)
{
    hEmf = static_cast<HENHMETAFILE>(get_data(CF_ENHMETAFILE));
}

inline void clipboard_scope::get_palette_data(HPALETTE& hPal) const stlsoft_throw_1(clipboard_scope_exception)
{
    hPal = static_cast<HPALETTE>(get_data(CF_PALETTE));
}

#ifdef STRICT

inline void clipboard_scope::get_data(HBITMAP& hBmp) const stlsoft_throw_1(clipboard_scope_exception)
{
    get_bitmap_data(hBmp);
}

inline void clipboard_scope::get_data(HDROP& hDrop) const stlsoft_throw_1(clipboard_scope_exception)
{
    get_drop_data(hDrop);
}

inline void clipboard_scope::get_data(HENHMETAFILE& hEmf) const stlsoft_throw_1(clipboard_scope_exception)
{
    get_emf_data(hEmf);
}

inline void clipboard_scope::get_data(HPALETTE& hPal) const stlsoft_throw_1(clipboard_scope_exception)
{
    get_palette_data(hPal);
}
#endif
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


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

#endif /* !WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

