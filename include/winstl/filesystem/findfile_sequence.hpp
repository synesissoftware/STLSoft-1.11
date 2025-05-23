/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/filesystem/findfile_sequence.hpp
 *
 * Purpose: Contains the basic_findfile_sequence template class, and ANSI
 *          and Unicode specialisations thereof.
 *
 * Notes:   1. The original implementation of the class had the
 *          const_iterator and value_type as nested classes. Unfortunately,
 *          Visual C++ 5 & 6 both had either compilation or linking problems
 *          so these are regretably now implemented as independent classes.
 *
 *          2. This class was described in detail in the article "Adapting
 *          Windows Enumeration Models to STL Iterator Concepts"
 *          (http://www.windevnet.com/documents/win0303a/), in the March
 *          2003 issue of Windows Developer Network (http://windevnet.com).
 *          Note that later implementations use a shared-enumeration
 *          context, and therefore do not suffer any of the copying/moving
 *          ownership issues described in the article.
 *
 * Created: 15th January 2002
 * Updated: 30th April 2025
 *
 * Thanks:  To Nevin Liber for pressing upon me the need to lead by example
 *          when writing books about good design/implementation; to Florin L
 *          for DMC++ missing standard symbols.
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


/** \file winstl/filesystem/findfile_sequence.hpp
 *
 * \brief [C++] Definition of the winstl::basic_findfile_sequence class
 *  template
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE_MAJOR       4
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE_MINOR       12
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE_REVISION    0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE_EDIT        277
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1100
# error winstl/findfile_sequence.hpp is not compatible with Visual C++ 4.2 or earlier
#endif /* compiler */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1500

# define WINSTL_FFS_NO_LONG_PATH_SUPPORT_
#endif


/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_VERSION
# include <winstl/system/system_version.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_VERSION */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_ACCESS_EXCEPTION
#  include <winstl/exception/access_exception.hpp>
# endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_ACCESS_EXCEPTION */
# ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
#  include <winstl/exception/winstl_exception.hpp>
# endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_COMPILER_IS_WATCOM
# ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
#  include <stlsoft/util/std/iterator_helper.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#endif /* compiler */
#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE
# include <stlsoft/smartptr/scoped_handle.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_TOKENISER_FUNCTIONS
# include <stlsoft/string/tokeniser_functions.hpp> // for find_next_token
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_TOKENISER_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_memfns
# include <stlsoft/api/external/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_memfns */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_FileManagement
# include <winstl/api/external/FileManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_FileManagement */

#ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
# include <winstl/api/winstl_win32_winnt_.h>
#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */


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
 * forward declarations
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C, ss_typename_param_k T>
class basic_findfile_sequence_value_type;

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
class basic_findfile_sequence_const_input_iterator;

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class basic_findfile_sequence
/** Presents an STL-like sequence interface over the items on the file-system
 *
 * \ingroup group__library__FileSystem
 *
 * \param C The character type
 * \param T The traits type. On translators that support default template arguments this defaults to filesystem_traits<C>
 *
 * \note  This class was described in detail in the article
 * "Adapting Windows Enumeration Models to STL Iterator Concepts"
 * (http://www.windevnet.com/documents/win0303a/), in the March 2003 issue of
 * Windows Developer Network (http://windevnet.com).
 */
template<
    ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k T = filesystem_traits<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T /* = filesystem_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>
class basic_findfile_sequence
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
/// \name Member Types
/// @{
public:
    /// The character type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The current specialisation of the type
    typedef basic_findfile_sequence<C, T>                   class_type;
    /// The value type
    typedef basic_findfile_sequence_value_type<C, T>        value_type;
    /// The non-mutating (const) iterator type
    typedef basic_findfile_sequence_const_input_iterator<
        C
    ,   T
    ,   value_type
    >                                                       const_iterator;
    /// The reference type
    typedef value_type const                                reference;
    /// The non-mutable (const) reference type
    typedef value_type const                                const_reference;
    /// The find-data type
    typedef ss_typename_type_k traits_type::find_data_type  find_data_type;
    /// The difference type
    typedef ws_ptrdiff_t                                    difference_type;
    /// The size type
    typedef ws_size_t                                       size_type;
    /// The Boolean type
    typedef ws_bool_t                                       bool_type;
    /// The flags type
    typedef int                                             flags_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    // For backwards compatibility
    typedef const_iterator                                  const_input_iterator;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
private:
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        char_type
    ,   1 + WINSTL_CONST_MAX_PATH
    ,   processheap_allocator<char_type>
    >                                                       buffer_type_;
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        char_type
    ,   64
    ,   processheap_allocator<char_type>
    >                                                       patterns_buffer_type_;
/// @}

/// \name Member Constants
/// @{
public:
    enum search_flags
    {
            includeDots                 =   0x0008  //!< Causes the search to include the "." and ".." directories, which are elided by default
        ,   directories                 =   0x0010  //!< Causes the search to include directories
        ,   files                       =   0x0020  //!< Causes the search to include files
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
        ,   devices                     =   0x0000  /*!< This has no effect on Windows, but is here for structural conformance compatibility with unixstl::glob_sequence. */
        ,   sockets                     =   0x0000  /*!< This has no effect on Windows, but is here for structural conformance compatibility with unixstl::glob_sequence. */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
        ,   skipReparseDirs             =   0x0100  //!< Causes the search to skip directories that are reparse points
        ,   skipHiddenFiles             =   0x0200  //!< Causes the search to skip files marked hidden
        ,   skipHiddenDirs              =   0x0400  //!< Causes the search to skip directories marked hidden
        ,   relativePath                =   0x0800  //!< Each file entry is presented as relative to the search directory.
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        ,   throwOnAccessFailure        =   0x2000  //!< Causes an exception to be thrown if a directory cannot be accessed
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef WINSTL_FFS_NO_LONG_PATH_SUPPORT_
        ,   allowLongPathTranslation    =   0x4000  //!< For wide-string specialisations, allows translation of paths to long-path forms - beginning with <code>"\\?\"</code> - when appropriate
#endif /* !WINSTL_FFS_NO_LONG_PATH_SUPPORT_*/
    };
/// @}

/// \name Construction
/// @{
public:
    /// Commence a search according to the given search pattern and flags, relative to the current directory
    ss_explicit_k
    basic_findfile_sequence(
        char_type const*    pattern
    ,   flags_type          flags = directories | files
    );
    /// Commence a search according to the given search composite pattern and delimiter, flags, relative to the current directory
    basic_findfile_sequence(
        char_type const*    patterns
    ,   char_type           delim
    ,   flags_type          flags = directories | files
    );
    /// Commence a search according to the given search pattern and flags, relative to \c directory
    basic_findfile_sequence(
        char_type const*    directory
    ,   char_type const*    pattern
    ,   flags_type          flags = directories | files
    );
    /// Commence a search according to the given search composite pattern and delimiter, flags, relative to \c directory
    basic_findfile_sequence(
        char_type const*    directory
    ,   char_type const*    patterns
    ,   char_type           delim
    ,   flags_type          flags = directories | files
    );
    /// Destructor
    ~basic_findfile_sequence() STLSOFT_NOEXCEPT;

private:
    basic_findfile_sequence(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator      begin() const;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator      end() const;
/// @}

/// \name Attributes
/// @{
public:
    /// Returns the directory of the search
    ///
    /// \note Will be the empty string for instances created with the first constructor
    char_type const*    get_directory(size_type* plen = NULL) const;
/// @}

/// \name State
/// @{
public:
    /// Indicates whether the sequence is empty
    ws_bool_t           empty() const;
    /// Returns the maximum number of items in the sequence
    static size_type    max_size();
/// @}

/// \name Members
/// @{
private:
    char_type const         m_delim;
    flags_type const        m_flags;
    buffer_type_            m_directory;    // The directory, as specified to the constructor
    patterns_buffer_type_   m_patterns;     // The pattern(s) specified to the constructor
/// @}

/// \name Invariant
/// @{
private:
    ws_bool_t is_valid() const;
/// @}

/// \name Implementation
/// @{
private:
    static flags_type   validate_flags_(flags_type flags);
    static size_type    validate_directory_(char_type const* directory, buffer_type_& dir, flags_type flags);
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * typedefs for commonly encountered types
 */

/** Specialisation of the basic_findfile_sequence template for the ANSI character type \c char
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_findfile_sequence<
    ws_char_a_t
,   filesystem_traits<ws_char_a_t>
>                                                           findfile_sequence_a;
/** Specialisation of the basic_findfile_sequence template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_findfile_sequence<
    ws_char_w_t
,   filesystem_traits<ws_char_w_t>
>                                                           findfile_sequence_w;
/** Specialisation of the basic_findfile_sequence template for the Win32 character type \c TCHAR
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_findfile_sequence<
    TCHAR
,   filesystem_traits<TCHAR>
>                                                           findfile_sequence;


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class basic_findfile_sequence_value_type
/** Value type for the basic_findfile_sequence
 *
 * \ingroup group__library__FileSystem
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
class basic_findfile_sequence_value_type
{
/// \name Member Types
/// @{
private:
    typedef basic_findfile_sequence<C, T>                   sequence_type;
public:
    /// The character type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The current specialisation of the type
    typedef basic_findfile_sequence_value_type<C, T>        class_type;
    /// The find-data type
    typedef ss_typename_type_k traits_type::find_data_type  find_data_type;
    /// The size type
    typedef ss_typename_type_k sequence_type::size_type     size_type;
private:
    typedef ss_typename_type_k sequence_type::bool_type     bool_type;
    typedef ss_typename_type_k sequence_type::flags_type    flags_type;
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        char_type
    ,   1 + WINSTL_CONST_MAX_PATH
    ,   processheap_allocator<char_type>
    >                                                       buffer_type_;
/// @}

/// \name Construction
/// @{
public:
    /// Default constructor
    basic_findfile_sequence_value_type();
private:
    basic_findfile_sequence_value_type(
        find_data_type const&   data
    ,   char_type const*        directory
    ,   size_type               cchDirectory
    );
public:
    /// Copy constructor
    basic_findfile_sequence_value_type(class_type const& rhs);

    /// Copy assignment operator
    class_type& operator =(class_type const& rhs);
/// @}

/// \name Accessors
/// @{
public:
    /// Returns a non-mutating reference to find-data
    find_data_type const&   get_find_data() const;
#ifdef STLSOFT_OBSOLETE
    /// Returns a non-mutating reference to find-data
    ///
    /// \deprecated This method may be removed in a future release. get_find_data() should be used instead
    find_data_type const&   GetFindData() const;   // Deprecated
#endif /* STLSOFT_OBSOLETE */

    /// Returns the filename part of the item
    char_type const*        get_filename() const;
    /// Returns the short form of the filename part of the item
    char_type const*        get_short_filename() const;
    /// Returns the full path of the item
    ///
    /// \note The path is not canonicalised, so will not be in canonical form if the filename is a
    /// dots directory. For this you should use winstl::path, and call canonicalise()
    char_type const*        get_path() const;
    /// Returns the full path of the item
    ///
    /// \note The path is not canonicalised, so will not be in canonical form if the filename is a
    /// dots directory. For this you should use winstl::path, and call canonicalise()
    char_type const*        c_str() const;
    /// Returns the length of the full path
    ws_size_t               length() const; // NOTE: The return type must be ws_size_t, due to a defect in VC++ 7.1

    /// Implicit conversion to a pointer-to-const of the full path
    ///
    /// \note The path is not canonicalised, so will not be in canonical form if the filename is a
    /// dots directory. For this you should use winstl::path, and call canonicalise()
    ///
    /// \deprecated This is provided for backwards compatibility with an earlier version, but since this
    /// class does not have an implicit conversion constructor, it's pretty harmless.
    operator char_type const* () const;

    /// Indicates whether the entry is a directory
    ws_bool_t               is_directory() const;
    /// Indicates whether the entry is a file
    ws_bool_t               is_file() const;
    /// Indicates whether the entry is compressed
    ws_bool_t               is_compressed() const;
#ifdef FILE_ATTRIBUTE_REPARSE_POINT
    /// Indicates whether the entry is a reparse point
    ws_bool_t               is_reparse_point() const;
#endif /* FILE_ATTRIBUTE_REPARSE_POINT */
    /// Indicates whether the entry is read-only
    ws_bool_t               is_read_only() const;
    /// Indicates whether the entry is a system file/directory
    ws_bool_t               is_system() const;
    /// Indicates whether the entry is hidden
    ws_bool_t               is_hidden() const;
/// @}

/// \name Comparison
/// @{
public:
    /// Determines whether the instance is equal to the given path
    ws_bool_t               equal(char_type const* rhs) const;
    /// Determines whether two instances are equal
    ws_bool_t               equal(class_type const& rhs) const;
/// @}

/// \name Members
/// @{
private:
    friend class basic_findfile_sequence_const_input_iterator<C, T, class_type>;

    find_data_type  m_data;
    buffer_type_    m_path;
/// @}
};

// class basic_findfile_sequence_const_input_iterator
/** Iterator type for the basic_findfile_sequence supporting the Input Iterator concept
 *
 * \ingroup group__library__FileSystem
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k V
>
class basic_findfile_sequence_const_input_iterator
#ifndef STLSOFT_COMPILER_IS_WATCOM
    : public STLSOFT_NS_QUAL(iterator_base)<
            STLSOFT_NS_QUAL_STD(input_iterator_tag)
        ,   V
        ,   ws_ptrdiff_t
        ,   void    // By-Value Temporary reference
        ,   V       // By-Value Temporary reference
        >
#endif /* compiler */
{
/// \name Member Types
/// @{
private:
    typedef basic_findfile_sequence<C, T>                   sequence_type;
public:
    /// The character type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The value type
    typedef V                                               value_type;
    /// The current specialisation of the type
    typedef basic_findfile_sequence_const_input_iterator<
        C
    ,   T
    ,   V
    >                                                       class_type;
    /// The find-data type
    typedef ss_typename_type_k traits_type::find_data_type  find_data_type;
    /// The size type
    typedef ss_typename_type_k sequence_type::size_type     size_type;
private:
    typedef ss_typename_type_k sequence_type::bool_type     bool_type;
    typedef ss_typename_type_k sequence_type::flags_type    flags_type;
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        char_type
    ,   1 + WINSTL_CONST_MAX_PATH
    ,   processheap_allocator<char_type>
    >                                                       buffer_type_;
/// @}

/// \name Utility classes
/// @{
private:
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    struct shared_handle
    {
    /// \name Member Types
    /// @{
    public:
        typedef shared_handle                               class_type;
        typedef HANDLE                                      handle_type;
    /// @}

    /// \name Members
    /// @{
    public:
        handle_type     hSrch;
    private:
        ss_sint32_t     m_refCount;
    /// @}

    /// \name Construction
    /// @{
    public:
        ss_explicit_k shared_handle(handle_type h)
            : hSrch(h)
            , m_refCount(1)
        {}
# if defined(STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR)
    protected:
# else /* ? STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
    private:
# endif /* STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
        ~shared_handle() STLSOFT_NOEXCEPT
        {
            WINSTL_MESSAGE_ASSERT("Shared search handle being destroyed with outstanding references!", 0 == m_refCount);

            if (INVALID_HANDLE_VALUE != hSrch)
            {
                traits_type::find_file_close(hSrch);
            }
        }
    private:
        shared_handle(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
        void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
    /// @}

    /// \name Operations
    /// @{
    public:
        ss_sint32_t AddRef()
        {
            return ++m_refCount;
        }
        ss_sint32_t Release()
        {
            ss_sint32_t rc = --m_refCount;

            if (0 == rc)
            {
                delete this;
            }

            return rc;
        }
    /// @}
    };
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Construction
/// @{
private:
    basic_findfile_sequence_const_input_iterator(
        sequence_type const&    l
    ,   char_type const*        patterns
    ,   char_type               delim
    ,   flags_type              flags
    );
    basic_findfile_sequence_const_input_iterator(sequence_type const& l);
public:
    /// Default constructor
    basic_findfile_sequence_const_input_iterator();
    /// <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">Move constructor</a>
    basic_findfile_sequence_const_input_iterator(class_type const& rhs);
    /// Destructor
    ~basic_findfile_sequence_const_input_iterator() STLSOFT_NOEXCEPT;

    // Copy assignment operator
    basic_findfile_sequence_const_input_iterator& operator =(class_type const& rhs);
/// @}

/// \name Input Iterator methods
/// @{
public:
    /// Pre-increment operator
    class_type& operator ++();
    /// Post-increment operator
    class_type operator ++(int);
    /// Dereference to return the value at the current position
    const value_type operator *() const;
    /// Evaluates whether \c this and \c rhs are equivalent
    ws_bool_t equal(class_type const& rhs) const;
/// @}

/// \name Implementation
/// @{
private:
    static
    HANDLE
    find_first_file_(
        buffer_type_ const& searchSpec
    ,   flags_type          flags
    ,   find_data_type*     findData
    );
/// @}

/// \name Members
/// @{
private:
    friend class basic_findfile_sequence<C, T>;

    sequence_type const* const                      m_list;
    shared_handle*                                  m_handle;
    ss_typename_type_k traits_type::find_data_type  m_data;
    buffer_type_                                    m_subpath;
    char_type const*                                m_pattern0;
    char_type const*                                m_pattern1;
    char_type                                       m_delim;
    flags_type                                      m_flags;
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

// basic_findfile_sequence_const_input_iterator

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
ws_bool_t
operator ==(
    basic_findfile_sequence_const_input_iterator<C, T, V> const&    lhs
,   basic_findfile_sequence_const_input_iterator<C, T, V> const&    rhs
)
{
    return lhs.equal(rhs);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
ws_bool_t
operator !=(
    basic_findfile_sequence_const_input_iterator<C, T, V> const&    lhs
,   basic_findfile_sequence_const_input_iterator<C, T, V> const&    rhs
)
{
    return !lhs.equal(rhs);
}

// basic_findfile_sequence_value_type

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
operator ==(
    basic_findfile_sequence_value_type<C, T> const& lhs
,   basic_findfile_sequence_value_type<C, T> const& rhs
)
{
    return lhs.equal(rhs);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
operator ==(
    basic_findfile_sequence_value_type<C, T> const& lhs
,   C const*                                        rhs
)
{
    return lhs.equal(rhs);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
operator ==(
    C const*                                        lhs
,   basic_findfile_sequence_value_type<C, T> const& rhs
)
{
    return rhs.equal(lhs);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
operator !=(
    basic_findfile_sequence_value_type<C, T> const& lhs
,   basic_findfile_sequence_value_type<C, T> const& rhs
)
{
    return !lhs.equal(rhs);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
operator !=(
    basic_findfile_sequence_value_type<C, T> const& lhs
,   C const*                                        rhs
)
{
    return !lhs.equal(rhs);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
operator !=(
    C const*                                        lhs
,   basic_findfile_sequence_value_type<C, T> const& rhs
)
{
    return !rhs.equal(lhs);
}


/* /////////////////////////////////////////////////////////////////////////
 * iostream compatibility
 */

template <ss_typename_param_k S, ss_typename_param_k C, ss_typename_param_k T>
inline
S&
operator <<(
    S&                                              s
,   basic_findfile_sequence_value_type<C, T> const& value
)
{
    s << value.get_path();

    return s;
}


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

// c_str_data

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
inline
ws_char_a_t const*
c_str_data_a(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<ws_char_a_t, T> const& v)
{
    return v.get_path();
}

template <ss_typename_param_k T>
inline
ws_char_w_t const*
c_str_data_w(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<ws_char_w_t, T> const& v)
{
    return v.get_path();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_data for winstl::basic_findfile_sequence_value_type
 *
 * \ingroup group__concept__Shim__string_access
 */
template <ss_typename_param_k C, ss_typename_param_k T>
inline
C const*
c_str_data(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<C, T> const& v)
{
    return v.get_path();
}

// c_str_len

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
inline
ws_size_t
c_str_len_a(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<ws_char_a_t, T> const& v)
{
    return v.length();
}

template <ss_typename_param_k T>
inline
ws_size_t
c_str_len_w(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<ws_char_w_t, T> const& v)
{
    return v.length();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for winstl::basic_findfile_sequence_value_type
 *
 * \ingroup group__concept__Shim__string_access
 */
template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_size_t
c_str_len(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<C, T> const& v)
{
    return v.length();
}

// c_str_ptr

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
inline
ws_char_a_t const*
c_str_ptr_a(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<ws_char_a_t, T> const& v)
{
    return v.get_path();
}

template <ss_typename_param_k T>
inline
ws_char_w_t const*
c_str_ptr_w(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<ws_char_w_t, T> const& v)
{
    return v.get_path();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr for winstl::basic_findfile_sequence_value_type
 *
 * \ingroup group__concept__Shim__string_access
 */
template <ss_typename_param_k C, ss_typename_param_k T>
inline
C const*
c_str_ptr(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<C, T> const& v)
{
    return v.get_path();
}

// c_str_ptr_null

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
inline
ws_char_a_t const*
c_str_ptr_null_a(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<ws_char_a_t, T> const& v)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null_a(v.get_path()));
}

template <ss_typename_param_k T>
inline
ws_char_w_t const*
c_str_ptr_null_w(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<ws_char_w_t, T> const& v)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null_w(v.get_path()));
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for winstl::basic_findfile_sequence_value_type
 *
 * \ingroup group__concept__Shim__string_access
 */
template <ss_typename_param_k C, ss_typename_param_k T>
inline
C const*
c_str_ptr_null(WINSTL_NS_QUAL(basic_findfile_sequence_value_type)<C, T> const& v)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null(v.get_path()));
}


/* /////////////////////////////////////////////////////////////////////////
 * deprecated shims
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
is_empty(basic_findfile_sequence<C, T> const& s) STLSOFT_NOEXCEPT
{
    return s.empty();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_OPEN_WORKER_NS_(ximpl_winstl_ffs_)

#ifndef WINSTL_FFS_NO_LONG_PATH_SUPPORT_

// fff_traits_

template<
    ss_typename_param_k T_character
>
struct fff_traits_
{
    template<
        ss_typename_param_k T_fs_traits
    ,   ss_typename_param_k T_buffer
    ,   ss_typename_param_k T_findData
    >
    static
    HANDLE
    find_first_file_l(
        T_buffer const&
    ,   T_findData*
    ,   T_fs_traits const*
    )
    {
        return INVALID_HANDLE_VALUE;
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct fff_traits_<ws_char_w_t>
{
    template<
        ss_typename_param_k T_fs_traits
    ,   ss_typename_param_k T_buffer
    ,   ss_typename_param_k T_findData
    >
    static
    HANDLE
    find_first_file_l(
        T_buffer const& searchSpec
    ,   T_findData*     findData
    ,   T_fs_traits const*
    )
    {
        T_buffer searchSpec_l(4 + searchSpec.size());

        searchSpec_l[0] =   L'\\';
        searchSpec_l[1] =   L'\\';
        searchSpec_l[2] =   L'?';
        searchSpec_l[3] =   L'\\';

        STLSOFT_API_EXTERNAL_memfns_memcpy(&searchSpec_l[0] + 4, &searchSpec[0], sizeof(ws_char_w_t) * searchSpec.size());

        return T_fs_traits::find_first_file(searchSpec_l.data(), findData);
    }
};
#endif /* !WINSTL_FFS_NO_LONG_PATH_SUPPORT_*/

STLSOFT_CLOSE_WORKER_NS_(ximpl_winstl_ffs_)


// basic_findfile_sequence

template <ss_typename_param_k C, ss_typename_param_k T>
inline /* static */
ss_typename_type_ret_k basic_findfile_sequence<C, T>::flags_type basic_findfile_sequence<C, T>::validate_flags_(
    ss_typename_type_k basic_findfile_sequence<C, T>::flags_type flags
)
{
    const flags_type    validFlags  =   0
                                    |   includeDots
                                    |   directories
                                    |   files
                                    |   skipReparseDirs
                                    |   skipHiddenFiles
                                    |   skipHiddenDirs
                                    |   relativePath
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                                    |   throwOnAccessFailure
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef WINSTL_FFS_NO_LONG_PATH_SUPPORT_
                                    |   allowLongPathTranslation
#endif /* !WINSTL_FFS_NO_LONG_PATH_SUPPORT_*/
                                    |   0;

    WINSTL_MESSAGE_ASSERT("Specification of unrecognised/unsupported flags", flags == (flags & validFlags));
    STLSOFT_SUPPRESS_UNUSED(validFlags);

    if (0 == (flags & (directories | files)))
    {
        flags |= (directories | files);
    }

    return flags;
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline /* static */
ws_bool_t
basic_findfile_sequence<C, T>::is_valid() const
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    if ('\0' == m_directory[0])
    {
        return false;
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    // m_directory should either be empty, or should end with a slash
    if ('\0' != m_directory[0] &&
        !traits_type::has_dir_end(m_directory.data()))
    {
        return false;
    }

    return true;
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline /* static */
ss_typename_type_ret_k basic_findfile_sequence<C, T>::size_type
basic_findfile_sequence<C, T>::validate_directory_(
    char_type const*    directory
,   buffer_type_&       dir
,   flags_type          flags
)
{
    if (NULL == directory ||
        '\0' == *directory)
    {
        static const char_type  s_cwd[] = { '.', '\0' };

        directory = &s_cwd[0];
    }

    size_type directoryLen = traits_type::str_len(directory);

    if (relativePath & flags)
    {
        dir.resize(directoryLen + 1);

        traits_type::char_copy(&dir[0], directory, directoryLen + 1);
    }
    else if (0 == (directoryLen = traits_type::get_full_path_name(directory, dir)))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        DWORD const le = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        STLSOFT_THROW_X(winstl_exception(le));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        return validate_directory_(directory, dir, flags | relativePath);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    WINSTL_ASSERT(directoryLen == traits_type::str_len(dir.data()));

    if (0u != directoryLen &&
        !traits_type::has_dir_end(dir))
    {
        traits_type::ensure_dir_end(dir);
        ++directoryLen;
    }

    WINSTL_ASSERT(directoryLen == traits_type::str_len(dir.data()));

    return directoryLen;
}

// Construction
template <ss_typename_param_k C, ss_typename_param_k T>
inline
basic_findfile_sequence<C, T>::basic_findfile_sequence(
    char_type const*    pattern
,   flags_type          flags /* = directories | files */
)
    : m_delim(0)
    , m_flags(validate_flags_(flags))
    , m_directory(1)
    , m_patterns(1 + traits_type::str_len(pattern))
{
    validate_directory_(NULL, m_directory, m_flags);

    traits_type::char_copy(&m_patterns[0], pattern, m_patterns.size());

    WINSTL_ASSERT(is_valid());
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
basic_findfile_sequence<C, T>::basic_findfile_sequence(
    char_type const*    patterns
,   char_type           delim
,   flags_type          flags /* = directories | files */
)
    : m_delim(delim)
    , m_flags(validate_flags_(flags))
    , m_directory(1)
    , m_patterns(1 + traits_type::str_len(patterns))
{
    validate_directory_(NULL, m_directory, m_flags);

    traits_type::char_copy(&m_patterns[0], patterns, m_patterns.size());

    WINSTL_ASSERT(is_valid());
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
basic_findfile_sequence<C, T>::basic_findfile_sequence(
    char_type const*    directory
,   char_type const*    pattern
,   flags_type          flags /* = directories | files */
)
    : m_delim(0)
    , m_flags(validate_flags_(flags))
    , m_directory(1)
    , m_patterns(1 + traits_type::str_len(pattern))
{
    validate_directory_(directory, m_directory, m_flags);

    traits_type::char_copy(&m_patterns[0], pattern, m_patterns.size());

    WINSTL_ASSERT(is_valid());
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
basic_findfile_sequence<C, T>::basic_findfile_sequence(
    char_type const*    directory
,   char_type const*    patterns
,   char_type           delim
,   flags_type          flags /* = directories | files */
)
    : m_delim(delim)
    , m_flags(validate_flags_(flags))
    , m_directory()
    , m_patterns(1 + traits_type::str_len(patterns))
{
    validate_directory_(directory, m_directory, m_flags);

    traits_type::char_copy(&m_patterns[0], patterns, m_patterns.size());

    WINSTL_ASSERT(is_valid());
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
basic_findfile_sequence<C, T>::~basic_findfile_sequence() STLSOFT_NOEXCEPT
{
    WINSTL_ASSERT(is_valid());

#ifdef STLSOFT_DEBUG

    m_directory[0]  =   '\0';
    m_patterns[0]   =   '\0';
#endif /* STLSOFT_DEBUG */
}

// Iteration
template <ss_typename_param_k C, ss_typename_param_k T>
inline
ss_typename_type_ret_k basic_findfile_sequence<C, T>::const_iterator
basic_findfile_sequence<C, T>::begin() const
{
    WINSTL_ASSERT(is_valid());

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT

    if ('\0' == m_directory[0])
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_INVALID_NAME);

        return const_iterator(*this);
    }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return const_iterator(*this, m_patterns.data(), m_delim, m_flags);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ss_typename_type_ret_k basic_findfile_sequence<C, T>::const_iterator
basic_findfile_sequence<C, T>::end() const
{
    WINSTL_ASSERT(is_valid());

    return const_iterator(*this);
}

// Attributes
template <ss_typename_param_k C, ss_typename_param_k T>
ss_typename_type_k basic_findfile_sequence<C, T>::char_type const* basic_findfile_sequence<C, T>::get_directory(size_type* plen /* = NULL */) const
{
    WINSTL_ASSERT(is_valid());

    // Null Object (variable) pattern
    size_type len_;

    if (NULL == plen)
    {
        plen = &len_;
    }

    WINSTL_ASSERT(0 != m_directory.size());

    *plen = m_directory.size() - 1;

    return m_directory.data();
}

// State

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
basic_findfile_sequence<C, T>::empty() const
{
    WINSTL_ASSERT(is_valid());

    return end() == begin();
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline /* static */
ss_typename_type_ret_k basic_findfile_sequence<C, T>::size_type
basic_findfile_sequence<C, T>::max_size()
{
    return static_cast<size_type>(-1);
}

// basic_findfile_sequence_value_type

template <ss_typename_param_k C, ss_typename_param_k T>
inline
basic_findfile_sequence_value_type<C, T>::basic_findfile_sequence_value_type()
    : m_path(1)
{
    m_data.dwFileAttributes         =   0xFFFFFFFF;
    m_data.cFileName[0]             =   '\0';
    m_data.cAlternateFileName[0]    =   '\0';
    m_path[0]                       =   '\0';
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
basic_findfile_sequence_value_type<C, T>::basic_findfile_sequence_value_type(
    find_data_type const&   data
,   char_type const*        directory
,   size_type               cchDirectory
)
    : m_data(data)
    , m_path(1)
{
    WINSTL_ASSERT(NULL != directory);
    WINSTL_ASSERT(0 != cchDirectory);
    WINSTL_ASSERT(traits_type::is_path_name_separator(directory[cchDirectory - 1]));
    WINSTL_ASSERT(traits_type::has_dir_end(directory, cchDirectory));

    size_type const cchFilename =   traits_type::str_len(data.cFileName);
    size_type const cchTotal    =   cchDirectory + cchFilename;

    m_path.resize(1 + cchTotal);

    traits_type::char_copy(&m_path[0], directory, cchDirectory);
    traits_type::char_copy(&m_path[0] + cchDirectory, data.cFileName, cchFilename);
    m_path[cchDirectory + cchFilename] = '\0';
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
basic_findfile_sequence_value_type<C, T>::basic_findfile_sequence_value_type(
    class_type const& rhs
)
    : m_data(rhs.m_data)
    , m_path(1)
{
    m_path.copy_from(rhs.m_path);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ss_typename_type_ret_k basic_findfile_sequence_value_type<C, T>::class_type&
basic_findfile_sequence_value_type<C, T>::operator =(
    ss_typename_type_k basic_findfile_sequence_value_type<C, T>::class_type const& rhs
)
{
    m_data      =   rhs.m_data;
    m_path.copy_from(rhs.m_path);

    return *this;
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ss_typename_type_ret_k basic_findfile_sequence_value_type<C, T>::find_data_type const&
basic_findfile_sequence_value_type<C, T>::get_find_data() const
{
    return m_data;
}

#ifdef STLSOFT_OBSOLETE
template <ss_typename_param_k C, ss_typename_param_k T>
inline
ss_typename_type_ret_k basic_findfile_sequence_value_type<C, T>::find_data_type const&
basic_findfile_sequence_value_type<C, T>::GetFindData() const
{
    return get_find_data();
}
#endif /* STLSOFT_OBSOLETE */

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ss_typename_type_ret_k basic_findfile_sequence_value_type<C, T>::char_type const*
basic_findfile_sequence_value_type<C, T>::get_filename() const
{
    return m_data.cFileName;
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ss_typename_type_ret_k basic_findfile_sequence_value_type<C, T>::char_type const*
basic_findfile_sequence_value_type<C, T>::get_short_filename() const
{
    return m_data.cAlternateFileName[0] != '\0' ? m_data.cAlternateFileName : m_data.cFileName;
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ss_typename_type_ret_k basic_findfile_sequence_value_type<C, T>::char_type const*
basic_findfile_sequence_value_type<C, T>::get_path() const
{
    return m_path.data();
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ss_typename_type_ret_k basic_findfile_sequence_value_type<C, T>::char_type const*
basic_findfile_sequence_value_type<C, T>::c_str() const
{
    return get_path();
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_size_t
basic_findfile_sequence_value_type<C, T>::length() const
{
    WINSTL_ASSERT(traits_type::str_len(get_path()) == m_path.size() - 1);

    return m_path.size() - 1;
}

template <ss_typename_param_k C, ss_typename_param_k T>
#if defined(STLSOFT_COMPILER_IS_GCC) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1100)
inline
basic_findfile_sequence_value_type<C, T>::operator C const* () const
#else /* ? compiler */
inline
basic_findfile_sequence_value_type<C, T>::operator ss_typename_type_k
basic_findfile_sequence_value_type<C, T>::char_type const* () const
#endif /* compiler */
{
    return get_path();
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
basic_findfile_sequence_value_type<C, T>::is_directory() const
{
    return traits_type::is_directory(&m_data);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
basic_findfile_sequence_value_type<C, T>::is_file() const
{
    return traits_type::is_file(&m_data);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
basic_findfile_sequence_value_type<C, T>::is_compressed() const
{
    return 0 != (m_data.dwFileAttributes & FILE_ATTRIBUTE_COMPRESSED);
}

#ifdef FILE_ATTRIBUTE_REPARSE_POINT

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
basic_findfile_sequence_value_type<C, T>::is_reparse_point() const
{
    return 0 != (m_data.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT);
}
#endif /* FILE_ATTRIBUTE_REPARSE_POINT */

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
basic_findfile_sequence_value_type<C, T>::is_read_only() const
{
    return 0 != (m_data.dwFileAttributes & FILE_ATTRIBUTE_READONLY);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
basic_findfile_sequence_value_type<C, T>::is_system() const
{
    return 0 != (m_data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
basic_findfile_sequence_value_type<C, T>::is_hidden() const
{
    return 0 != (m_data.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
basic_findfile_sequence_value_type<C, T>::equal(char_type const* rhs) const
{
    return 0 == traits_type::str_compare_no_case(this->get_path(), rhs);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline
ws_bool_t
basic_findfile_sequence_value_type<C, T>::equal(basic_findfile_sequence_value_type<C, T> const& rhs) const
{
    return equal(rhs.get_path());
}

// basic_findfile_sequence_const_input_iterator

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline /* static */
HANDLE
basic_findfile_sequence_const_input_iterator<C, T, V>::find_first_file_(
    ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::buffer_type_ const&   searchSpec
,   flags_type                                                                                      flags
,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::find_data_type*       findData
)
{
    HANDLE      hSrch = INVALID_HANDLE_VALUE;

    // A constant makes Borland weep the tears of unfathomable sadness, so an enum is used instead
//    const DWORD reparsePointConstant    =   0x00000400;

    enum
    {
#ifdef FILE_ATTRIBUTE_REPARSE_POINT
        reparsePointConstant    =   FILE_ATTRIBUTE_REPARSE_POINT
#else /* ? FILE_ATTRIBUTE_REPARSE_POINT */
        reparsePointConstant    =   0x00000400
#endif /* FILE_ATTRIBUTE_REPARSE_POINT */
    };

#if WINSTL_WIN32_WINNT >= WINSTL_WIN32_WINNT_NT4

    if ((sequence_type::directories == (flags & (sequence_type::directories | sequence_type::files))) &&
        system_version::winnt() &&
        system_version::major() >= 4)
    {
        hSrch = traits_type::find_first_file_ex(searchSpec.data(), FindExSearchLimitToDirectories, findData);
    }
    else
#endif /* _WIN32_WINNT >= _WIN32_WINNT_NT4 */

    if (INVALID_HANDLE_VALUE == hSrch)
    {
        hSrch = traits_type::find_first_file(searchSpec.data(), findData);
    }

    if (INVALID_HANDLE_VALUE == hSrch)
    {
        DWORD const dw = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        if (ERROR_ACCESS_DENIED == dw)
        {
            if (flags & sequence_type::throwOnAccessFailure)
            {
                STLSOFT_THROW_X(access_exception("Could not execute search", dw));
            }
        }
        else
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef WINSTL_FFS_NO_LONG_PATH_SUPPORT_

        if (STLSOFT_ALWAYS_FALSE() ||
            ERROR_PATH_NOT_FOUND == dw ||
            ERROR_FILE_NOT_FOUND == dw ||
            ERROR_FILENAME_EXCED_RANGE == dw ||
            STLSOFT_ALWAYS_FALSE())
        {
            if (flags & sequence_type::allowLongPathTranslation)
            {
                typedef STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_ffs_, fff_traits_)<char_type>  fff_traits_t_;

                typedef traits_type                                                         traits_t_;

                hSrch = fff_traits_t_::find_first_file_l(searchSpec, findData, static_cast<traits_t_*>(0));
            }
        }
#else /* ? WINSTL_FFS_NO_LONG_PATH_SUPPORT_*/
        {}
#endif /* !WINSTL_FFS_NO_LONG_PATH_SUPPORT_*/
    }

    // Now need to validate against the flags
    for (; INVALID_HANDLE_VALUE != hSrch; )
    {
        if (traits_type::is_file(findData) &&
            (   0 == (flags & sequence_type::skipHiddenFiles) ||
                0 == (findData->dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)))
        {
            // A file, and files requested, so break
            if (flags & sequence_type::files)
            {
                break;
            }
        }
        else
        {
            if (0 == (flags & sequence_type::skipHiddenDirs) ||
                0 == (findData->dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
            {
                if (traits_type::is_dots(findData->cFileName))
                {
                    if (flags & sequence_type::includeDots)
                    {
                        // A dots file, and dots are requested
                        break;
                    }
                }
                else if (flags & sequence_type::directories)
                {
                    // A directory, and directories requested
                    if (0 == (flags & sequence_type::skipReparseDirs) ||
                        0 == (findData->dwFileAttributes & reparsePointConstant))
                    {
                        // Either not requested to skip reparse points, or not a reparse point
                        break;
                    }
                }
            }
        }

        if (!traits_type::find_next_file(hSrch, findData))
        {
            WINSTL_API_EXTERNAL_FileManagement_FindClose(hSrch);

            hSrch = INVALID_HANDLE_VALUE;

            break;
        }
    }

    return hSrch;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
basic_findfile_sequence_const_input_iterator<C, T, V>::basic_findfile_sequence_const_input_iterator()
    : m_list(NULL)
    , m_handle(NULL)
    , m_subpath(1)
    , m_pattern0(NULL)
    , m_pattern1(NULL)
    , m_delim('\0')
    , m_flags(0)
{
    m_subpath[0] = '\0';
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
basic_findfile_sequence_const_input_iterator<C, T, V>::basic_findfile_sequence_const_input_iterator(
    sequence_type const&                                                                        l
#if 0
,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::char_type const*  rootDir
#endif /* 0 */
,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::char_type const*  patterns
,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::char_type         delim
,   flags_type                                                                                  flags
)
    : m_list(&l)
    , m_handle(NULL)
    , m_subpath(1)
    , m_pattern0(patterns)
    , m_pattern1(patterns)
    , m_delim(delim)
    , m_flags(flags)
{
    m_subpath[0] = '\0';

    operator ++();
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
basic_findfile_sequence_const_input_iterator<C, T, V>::basic_findfile_sequence_const_input_iterator(
    sequence_type const& l
)
    : m_list(&l)
    , m_handle(NULL)
    , m_subpath(1)
    , m_pattern0(NULL)
    , m_pattern1(NULL)
    , m_delim('\0')
    , m_flags(0)
{
    m_subpath[0] = '\0';
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
basic_findfile_sequence_const_input_iterator<C, T, V>::basic_findfile_sequence_const_input_iterator(
    class_type const& rhs
)
    : m_list(rhs.m_list)
    , m_handle(rhs.m_handle)
    , m_data(rhs.m_data)
    , m_subpath(rhs.m_subpath.size())
    , m_pattern0(rhs.m_pattern0)
    , m_pattern1(rhs.m_pattern1)
    , m_delim(rhs.m_delim)
    , m_flags(rhs.m_flags)
{
    m_subpath.copy_from(rhs.m_subpath);

    if (NULL != m_handle)
    {
        m_handle->AddRef();
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
#ifndef STLSOFT_COMPILER_IS_WATCOM
inline
ss_typename_type_ret_k basic_findfile_sequence_const_input_iterator<C, T, V>::class_type&
basic_findfile_sequence_const_input_iterator<C, T, V>::operator =(
    ss_typename_param_k basic_findfile_sequence_const_input_iterator<C, T, V>::class_type const& rhs
)
#else /* ? compiler */
inline
basic_findfile_sequence_const_input_iterator<C, T, V>&
basic_findfile_sequence_const_input_iterator<C, T, V>::operator =(
    basic_findfile_sequence_const_input_iterator<C, T, V> const& rhs
)
#endif /* compiler */
{
    WINSTL_MESSAGE_ASSERT("Assigning iterators from separate sequences", (m_list == NULL || rhs.m_list == NULL || rhs.m_list));    // Should only be comparing iterators from same container

    shared_handle* this_handle = m_handle;

    m_handle        =   rhs.m_handle;
    m_data          =   rhs.m_data;
    m_subpath.copy_from(rhs.m_subpath);
    m_pattern0      =   rhs.m_pattern0;
    m_pattern1      =   rhs.m_pattern1;
    m_delim         =   rhs.m_delim;
    m_flags         =   rhs.m_flags;

    if (NULL != m_handle)
    {
        m_handle->AddRef();
    }

    if (NULL != this_handle)
    {
        this_handle->Release();
    }

    return *this;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
basic_findfile_sequence_const_input_iterator<C, T, V>::~basic_findfile_sequence_const_input_iterator() STLSOFT_NOEXCEPT
{
    if (NULL != m_handle)
    {
        m_handle->Release();
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
ss_typename_type_ret_k basic_findfile_sequence_const_input_iterator<C, T, V>::class_type&
basic_findfile_sequence_const_input_iterator<C, T, V>::operator ++()
{
    // Pre-condition enforcements
    WINSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator!", '\0' != *m_pattern0);
    WINSTL_ASSERT(NULL != m_pattern0);
    WINSTL_ASSERT(NULL != m_pattern1);

    enum
    {
#ifdef FILE_ATTRIBUTE_REPARSE_POINT
        reparsePointConstant    =   FILE_ATTRIBUTE_REPARSE_POINT
#else /* ? FILE_ATTRIBUTE_REPARSE_POINT */
        reparsePointConstant    =   0x00000400
#endif /* FILE_ATTRIBUTE_REPARSE_POINT */
    };

    STLSOFT_SUPPRESS_UNUSED(reparsePointConstant); // Suppress silly Borland's warnings

    for (; '\0' != *m_pattern0 || '\0' != *m_pattern1;)
    {
        if (NULL == m_handle)
        {
            // Walk through the patterns

            while (STLSOFT_NS_QUAL(find_next_token)(m_pattern0, m_pattern1, m_delim))
            {
                WINSTL_ASSERT(m_pattern0 <= m_pattern1);

                if (m_pattern1 != m_pattern0)    // Will return m_pattern0 == m_pattern1 for empty tokens
                {
                    size_type const         n1  =   static_cast<size_type>(m_pattern1 - m_pattern0);

                    // We now have a non-empty pattern, so we need to concatenate
                    // it with the directory to form a search-spec for
                    // FindFirstFile()
                    //
                    // From this path we must also determine the sub-path for any items retrieved from
                    // this search, since WIN32_FIND_DATA will contain only the file-name. Since the
                    // sequence is tolerant of both slashes and backslashes, we need to find the last
                    // of each and take the endmost.

                    buffer_type_    search(n1 + 1); // Buffer in which to prepare the search-spec for FindFirstFile()
                    size_type       cch;            // Used to make the strrchr operations faster

                    if (traits_type::is_path_rooted(m_pattern0))
                    {
                        cch = 0;
                    }
                    else
                    {
                        char_type const* directory = m_list->get_directory(&cch);

                        WINSTL_ASSERT(NULL != directory);
                        WINSTL_ASSERT(0 != cch);
                        WINSTL_ASSERT(traits_type::has_dir_end(directory));

                        search.resize(cch + n1 + 1);

                        traits_type::char_copy(&search[0], directory, cch + 1);
                    }

                    traits_type::char_copy(&search[0] + cch, m_pattern0, n1);
                    search[cch + n1] = '\0';

                    // NOTE: At this point, cch may be 1 under, because ensure_dir_end() may have added
                    // a character that we've not counted. But that's ok, because we don't use it as an
                    // exact value, just a minimum value

                    char_type const* slash  =   traits_type::str_rchr(&search[0] + cch, '/');
                    char_type const* bslash =   traits_type::str_rchr(&search[0] + cch, '\\');

                    WINSTL_ASSERT(!traits_type::is_path_rooted(m_pattern0) || ((NULL != slash) || (NULL != bslash)));

                    if (NULL != slash ||
                        NULL != bslash)
                    {
                        if (NULL == slash)
                        {
                            slash = bslash;
                        }
                        else if (NULL != bslash &&
                                slash < bslash)
                        {
                            slash = bslash;
                        }

                        size_type const n2 = static_cast<size_type>(slash - &search[0]) + 1;

                        m_subpath.resize(1 + n2);
                        traits_type::char_copy(&m_subpath[0], &search[0], n2);
                        m_subpath[n2] = '\0';
                    }

                    HANDLE hSrch = find_first_file_(search, m_flags, &m_data);

                    if (INVALID_HANDLE_VALUE != hSrch)
                    {
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200

                        STLSOFT_NS_QUAL(scoped_handle)<HANDLE>  cleanup(hSrch, (void (STLSOFT_STDCALL *)(HANDLE))&WINSTL_API_EXTERNAL_FileManagement_FindClose, INVALID_HANDLE_VALUE);

#else /* ? compiler */

                        STLSOFT_NS_QUAL(scoped_handle)<HANDLE>  cleanup(hSrch, WINSTL_API_EXTERNAL_FileManagement_FindClose, INVALID_HANDLE_VALUE);
#endif /* compiler */

                        // Special case, where the pattern specified is either "." or ".."
                        // the API will return the directory name, but we want to keep the
                        // dot name.
                        if ('.' == m_pattern0[0] &&
                            (   m_pattern1 == m_pattern0 + 1 ||
                                (   '.' == m_pattern0[1] &&
                                    m_pattern1 == m_pattern0 + 2)))
                        {
                            size_type const n3 = static_cast<size_type>(m_pattern1 - m_pattern0);

                            traits_type::char_copy(&m_data.cFileName[0], m_pattern0, n3);
                            m_data.cFileName[n3] = '\0';
                        }

                        m_handle = new shared_handle(hSrch);

                        if (NULL != m_handle)
                        {
                            cleanup.detach();
                        }

                        return *this;
                    }
                    else
                    {
#ifdef STLSOFT_DEBUG

                        DWORD const dwErr = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

                        STLSOFT_SUPPRESS_UNUSED(dwErr);
#endif /* STLSOFT_DEBUG */
                    }
                }
            }
        }

        if (NULL != m_handle)
        {
            for (; INVALID_HANDLE_VALUE != m_handle->hSrch; )
            {
                if (!traits_type::find_next_file(m_handle->hSrch, &m_data))
                {
                    m_handle->Release();

                    m_handle = NULL;

                    break;
                }
                else
                {
                    if (traits_type::is_file(&m_data) &&
                        (   0 == (m_flags & sequence_type::skipHiddenFiles) ||
                            0 == (m_data.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)))
                    {
                        // A file, and files requested, so break
                        if (m_flags & sequence_type::files)
                        {
                            return *this;
                        }
                    }
                    else
                    {
                        if (0 == (m_flags & sequence_type::skipHiddenDirs) ||
                            0 == (m_data.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
                        {
                            if (traits_type::is_dots(m_data.cFileName))
                            {
                                if (m_flags & sequence_type::includeDots)
                                {
                                    // A dots file, and dots are requested
                                    return *this;
                                }
                            }
                            else if (m_flags & sequence_type::directories)
                            {
                                // A directory, and directories requested
                                if (0 == (m_flags & sequence_type::skipReparseDirs) ||
                                    0 == (m_data.dwFileAttributes & reparsePointConstant))
                                {
                                    // Either not requested to skip reparse points, or not a reparse point
                                    return *this;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return *this;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
ss_typename_type_ret_k basic_findfile_sequence_const_input_iterator<C, T, V>::class_type
basic_findfile_sequence_const_input_iterator<C, T, V>::operator ++(int)
{
    class_type  ret(*this);

    operator ++();

    return ret;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
const ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::value_type
basic_findfile_sequence_const_input_iterator<C, T, V>::operator *() const
{
    WINSTL_MESSAGE_ASSERT("Dereferencing end()-valued iterator", NULL != m_handle);

    if (char_type(0) == m_subpath[0])
    {
        size_type               cchDirectory;
        char_type const* const  directory   =   m_list->get_directory(&cchDirectory);

        return value_type(m_data, directory, cchDirectory);
    }
    else
    {
        return value_type(m_data, m_subpath.data(), m_subpath.size() - 1);
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline
ws_bool_t
basic_findfile_sequence_const_input_iterator<C, T, V>::equal(
    basic_findfile_sequence_const_input_iterator<C, T, V> const& rhs
) const
{
    // Should only be comparing iterators from same container
    WINSTL_MESSAGE_ASSERT("Comparing iterators from separate sequences", (m_list == rhs.m_list || NULL == m_list || NULL == rhs.m_list));

    return m_handle == rhs.m_handle;
}
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

using ::winstl::c_str_len;
using ::winstl::c_str_len_a;
using ::winstl::c_str_len_w;

using ::winstl::c_str_data;
using ::winstl::c_str_data_a;
using ::winstl::c_str_data_w;

using ::winstl::c_str_ptr;
using ::winstl::c_str_ptr_a;
using ::winstl::c_str_ptr_w;

using ::winstl::c_str_ptr_null;
using ::winstl::c_str_ptr_null_a;
using ::winstl::c_str_ptr_null_w;

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

using ::winstl::is_empty;

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

