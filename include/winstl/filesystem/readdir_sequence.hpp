/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/filesystem/readdir_sequence.hpp (formerly platformstl/filesystem/readdir_sequence.hpp)
 *
 * Purpose: Platform header for the readdir_sequence components.
 *
 * Created: 29th April 2006
 * Updated: 2nd May 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/filesystem/readdir_sequence.hpp
 *
 * \brief [C++] Definition of the winstl::readdir_sequence
 *  type
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_READDIR_SEQUENCE
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_READDIR_SEQUENCE

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_MAJOR    3
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_MINOR    2
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_REVISION 0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_EDIT     43
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

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE
# include <winstl/filesystem/findfile_sequence.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */


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


/* ////////////////////////////////////////////////////////////////////// */

class readdir_sequence
{
/// \name Member Types
/// @{
public:
    // This class
    typedef readdir_sequence                                class_type;
private:
    typedef ws_char_a_t                                     char_type;
    typedef basic_findfile_sequence<char_type>              underlying_sequence_type;
    typedef filesystem_traits<char_type>                    traits_type;
public:
    typedef underlying_sequence_type::const_iterator        underlying_sequence_const_iterator_type;
    typedef underlying_sequence_type::value_type            underlying_sequence_value_type;
public:
    // The size type
    typedef ws_size_t                                       size_type;
    // The non-mutating (const) iterator type
    class                                                   const_iterator;
    // The value type
    typedef char_type const*                                value_type;
    /// The flags type
    typedef ws_int_t                                        flags_type;
    /// The Boolean type
    typedef ws_bool_t                                       bool_type;

public:
/// @}

/// \name Member Constants
/// @{
public:
    enum search_flags
    {
            includeDots     =   0x0008  /*!< Requests that dots directories be included in the returned sequence. */
        ,   directories     =   0x0010  /*!< Causes the search to include directories. */
        ,   files           =   0x0020  /*!< Causes the search to include files. */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
        ,   devices         =   0x0000  /*!< This has no effect on Windows, but is here for structural conformance compatibility with unixstl::readdir_sequence. */
        ,   sockets         =   0x0000  /*!< This has no effect on Windows, but is here for structural conformance compatibility with unixstl::readdir_sequence. */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
        ,   skipHiddenFiles =   0x1000  //!< Causes the search to skip files marked hidden
        ,   skipHiddenDirs  =   0x2000  //!< Causes the search to skip directories marked hidden
        ,   fullPath        =   0x0100  /*!< Each file entry is presented as a full path relative to the search directory. */
        ,   absolutePath    =   0x0200  /*!< The search directory is converted to an absolute path. */
    };
/// @}

/// \name Construction
/// @{
public:
    /// Constructs a sequence according to the given criteria
    ///
    /// The constructor initialises a readdir_sequence instance on the given
    /// directory with the given flags.
    ///
    /// \param directory The directory whose contents are to be searched
    /// \param flags Flags to alter the behaviour of the search
    ///
    /// \note The \c flags parameter defaults to <code>directories | files</code> because
    /// this reflects the default behaviour of \c readdir(), and also because it is the
    /// most efficient.
    template <ss_typename_param_k S>
    ss_explicit_k readdir_sequence(S const& directory)
        : m_ffs(STLSOFT_NS_QUAL(c_str_ptr)(directory), "*.*", translate_flags_(directories | files))
        , m_flags(validate_flags_(directories | files))
    {}

    template <ss_typename_param_k S>
    readdir_sequence(S const& directory, flags_type flags)
        : m_ffs(STLSOFT_NS_QUAL(c_str_ptr)(directory), "*.*", translate_flags_(flags))
        , m_flags(validate_flags_(flags))
    {}

    template <ss_typename_param_k S>
    readdir_sequence(S const& directory, search_flags flags)
        : m_ffs(STLSOFT_NS_QUAL(c_str_ptr)(directory), "*.*", translate_flags_(flags))
        , m_flags(validate_flags_(flags))
    {}
private:
    readdir_sequence(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const;
/// @}

/// \name Attributes
/// @{
public:
    /// Indicates whether the search sequence is empty
    bool_type           empty() const STLSOFT_NOEXCEPT;

    /// The search directory
    ///
    /// \note The value returned by this method always has a trailing path name separator, so
    /// you can safely concatenate this with the value returned by the iterator's operator *()
    /// with minimal fuss.
    char_type const*    get_directory() const STLSOFT_NOEXCEPT;

    /// The flags used by the sequence
    ///
    /// \note This value is the value used by the sequence, which may, as a result of the
    /// determination of defaults, be different from those specified in its constructor. In
    /// other words, if <code>includeDots</code> is specified, this function
    /// will return <code>includeDots | directories | files</code>
    flags_type          get_flags() const STLSOFT_NOEXCEPT;
/// @}

/// \name Implementation
/// @{
private:
    /// Ensures that the flags are correct
    static flags_type   validate_flags_(flags_type flags);

    /// Translates the flags to the underlying sequence
    static flags_type   translate_flags_(flags_type flags);
/// @}

/// \name Members
/// @{
private:
    underlying_sequence_type const  m_ffs;
    flags_type const                m_flags;
/// @}
};

/// Iterator for readdir_sequence class
///
/// This class performs as a non-mutating iterator (aka const iterator) for the
/// readdir_sequence class.

class readdir_sequence::const_iterator
    : public STLSOFT_NS_QUAL(iterator_base)<STLSOFT_NS_QUAL_STD(input_iterator_tag)
                                        ,   readdir_sequence::value_type
                                        ,   ss_ptrdiff_t
                                        ,   void
                                        ,   readdir_sequence::value_type
                                        >
{
/// \name Members
/// @{
public:
    /// The class type
    typedef const_iterator                          class_type;
    /// The value type
    typedef readdir_sequence::value_type            value_type;
    /// The flags type
    typedef readdir_sequence::flags_type            flags_type;
/// @}

/// \name Construction
/// @{
private:
    friend class readdir_sequence;

    /// Construct an instance and begin a sequence iteration on the given dir.
    const_iterator(underlying_sequence_const_iterator_type it, flags_type flags)
        : m_it(it)
        , m_flags(flags)
    {}
public:
    /// Default constructor
    const_iterator()
        : m_it()
        , m_flags(0)
    {}
    /// Copy constructor
    const_iterator(class_type const& rhs)
        : m_it(rhs.m_it)
        , m_flags(rhs.m_flags)
    {}
    /// Release the search handle
    ~const_iterator() STLSOFT_NOEXCEPT
    {}

    /// Copy assignment operator
    class_type const& operator =(class_type const& rhs)
    {
        m_it    =   rhs.m_it;
        m_flags =   rhs.m_flags;

        return *this;
    }
/// @}

/// \name Input Iterator Methods
/// @{
public:
    /// Returns the value representative
    value_type operator *() const
    {
        remove_const(m_value) = *m_it;

        return (fullPath & m_flags) ? m_value.get_path() : m_value.get_filename();
    }

    /// Moves the iteration on to the next point in the sequence, or end() if
    /// the sequence is exhausted
    class_type& operator ++()
    {
        ++m_it;

        return *this;
    }

    /// Post-increment form of operator ++().
    ///
    /// \note Because this version uses a temporary on which to call the
    /// pre-increment form it is thereby less efficient, and should not be used
    /// except where post-increment semantics are required.
    class_type operator ++(int)
    {
        class_type  r(*this);

        operator ++();

        return r;
    }

    /// Compares \c this for equality with \c rhs
    ///
    /// \param rhs The instance against which to test
    /// \retval true if the iterators are equivalent
    /// \retval false if the iterators are not equivalent
    bool equal(class_type const& rhs) const STLSOFT_NOEXCEPT
    {
        return m_it == rhs.m_it;
    }
/// @}

/// \name Members
/// @{
private:
    underlying_sequence_const_iterator_type m_it;
    underlying_sequence_value_type          m_value;
    flags_type                              m_flags;
/// @}
};


inline
/* static */
readdir_sequence::flags_type
readdir_sequence::validate_flags_(readdir_sequence::flags_type flags)
{
    flags_type const    validFlags  =   0
                                    |   includeDots
                                    |   0
                                    |   directories
                                    |   files
                                    |   devices
                                    |   sockets
                                    |   0
                                    |   skipHiddenFiles
                                    |   skipHiddenDirs
                                    |   0
                                    |   fullPath
                                    |   absolutePath
                                    |   0
                                    ;

    WINSTL_MESSAGE_ASSERT("Specification of unrecognised/unsupported flags", flags == (flags & validFlags));
    STLSOFT_SUPPRESS_UNUSED(validFlags);

    if (0 == (flags & (directories | files)))
    {
        flags |= (directories | files);
    }

    return flags;
}

inline
/* static */
readdir_sequence::flags_type
readdir_sequence::translate_flags_(readdir_sequence::flags_type flags)
{
    flags_type translatedFlags = 0;

    if (underlying_sequence_type::includeDots & flags)
    {
        translatedFlags |= underlying_sequence_type::includeDots;
    }

    if (directories & flags)
    {
        translatedFlags |= underlying_sequence_type::directories;
    }

    if (files & flags)
    {
        translatedFlags |= underlying_sequence_type::files;
    }

    if (skipHiddenFiles & flags)
    {
        translatedFlags |= underlying_sequence_type::skipHiddenFiles;
    }

    if (skipHiddenDirs & flags)
    {
        translatedFlags |= underlying_sequence_type::skipHiddenDirs;
    }

    if (fullPath == ((fullPath | absolutePath) & flags))
    {
        translatedFlags |= underlying_sequence_type::relativePath;
    }

    return translatedFlags;
}

inline
readdir_sequence::const_iterator
readdir_sequence::begin() const
{
    return const_iterator(m_ffs.begin(), m_flags);
}

inline
readdir_sequence::const_iterator
readdir_sequence::end() const
{
    return const_iterator(m_ffs.end(), m_flags);
}

inline
readdir_sequence::bool_type
readdir_sequence::empty() const STLSOFT_NOEXCEPT
{
    return m_ffs.empty();
}

inline
readdir_sequence::char_type const*
readdir_sequence::get_directory() const STLSOFT_NOEXCEPT
{
    return m_ffs.get_directory();
}

inline
readdir_sequence::flags_type
readdir_sequence::get_flags() const STLSOFT_NOEXCEPT
{
    return m_flags;
}

inline
ss_bool_t
operator ==(
    readdir_sequence::const_iterator const& lhs
,   readdir_sequence::const_iterator const& rhs
)
{
    return lhs.equal(rhs);
}

inline
ss_bool_t
operator !=(
    readdir_sequence::const_iterator const& lhs
,   readdir_sequence::const_iterator const& rhs
)
{
    return !lhs.equal(rhs);
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


#if 0
#elif defined(WINSTL_OS_IS_WINDOWS) && \
      (   defined(STLSOFT_COMPILER_IS_BORLAND) || \
          defined(STLSOFT_COMPILER_IS_DMC))

inline
int
operator ==(
    platformstl::readdir_sequence::const_iterator const&    lhs
,   platformstl::readdir_sequence::const_iterator const&    rhs
)
{
    return lhs.equal(rhs);
}

inline
int
operator !=(
    platformstl::readdir_sequence::const_iterator const&    lhs
,   platformstl::readdir_sequence::const_iterator const&    rhs
)
{
    return !lhs.equal(rhs);
}
#endif /* WIN32 && compiler */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_READDIR_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

