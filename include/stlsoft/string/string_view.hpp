/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/string/string_view.hpp
 *
 * Purpose: basic_string_view class.
 *
 * Created: 16th October 2004
 * Updated: 4th May 2025
 *
 * Thanks:  Bjorn Karlsson and Scott Patterson for discussions on various
 *          naming and design issues. Thanks also to Pablo Aguilar for
 *          his eagle eyed reviews of beta code. :-)
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/string_view.hpp
 *
 * \brief [C++] Definition of the stlsoft::basic_string_view class
 *  template
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW
#define STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MAJOR       4
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MINOR       0
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_REVISION    3
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_EDIT        124
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if 0
#elif defined(STLSOFT_OBSOLETE)

# ifndef STLSOFT_STRING_VIEW_PROVIDE_c_str
#  define STLSOFT_STRING_VIEW_PROVIDE_c_str
# endif
#endif

#ifdef STLSOFT_STRING_VIEW_NO_PROVIDE_c_str
# ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
#  undef STLSOFT_STRING_VIEW_PROVIDE_c_str
# endif
#endif


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(STLSOFT_COMPILER_IS_MWERKS) && \
    ((__MWERKS__ & 0xff00) < 0x3000)
# error stlsoft/string/string_view.hpp not compatible with Metrowerks 7.x (v2.4)
#endif /* compiler */

#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS_FWD
# include <stlsoft/string/string_traits_fwd.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS_FWD */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION
# include <stlsoft/util/streams/string_insertion.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef STLSOFT_INCL_STDEXCEPT
#  define STLSOFT_INCL_STDEXCEPT
#  include <stdexcept>                  // for std::out_of_range
# endif /* !STLSOFT_INCL_STDEXCEPT */
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class basic_string_view
/** A string class that holds no internal storage, and merely represents a
 * window into other string storage
 *
 * \ingroup group__library__String
 *
 * \param C The character type
 * \param T The traits type. On translators that support default template
 *   arguments this is defaulted to char_traits<C>
 * \param A The allocator type. On translators that support default template
 *   arguments this is defaulted to allocator_selector<C>::allocator_type.
 *   This is only used by the proxy generated by c_str()
 * \ingroup concepts_view
 */
template<
    ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k T = char_traits<C>
,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T /* = char_traits<C> */
,   ss_typename_param_k A /* = allocator_selector<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>
class basic_string_view
#if defined(STLSOFT_COMPILER_IS_DMC)
    : protected A
#else /* ? compiler */
    : private A
#endif /* compiler */
    , public stl_collection_tag
{
public:
    /// The value type
    typedef C                                               value_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The allocator type
    typedef A                                               allocator_type;
    /// The current specialisation of the type
    typedef basic_string_view<
        value_type
    ,   traits_type
    ,   allocator_type
    >                                                       class_type;
    /// The character type
    typedef value_type                                      char_type;
#if 0

    /// The pointer type
    ///
    /// \note This type is not used by any functions, but is here to
    ///   facilitate type detection
    typedef value_type const*                               pointer;
#endif /* 0 */
    /// The non-mutable (const) pointer type
    typedef value_type const*                               const_pointer;
#if 0

    /// The reference type
    typedef value_type&                                     reference;
#endif /* 0 */
    /// The non-mutable (const) reference type
    typedef value_type const&                               const_reference;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The difference type
    typedef ss_ptrdiff_t                                    difference_type;
#if 0

    /// The iterator type
    typedef
#if !defined(STLSOFT_COMPILER_IS_BORLAND)
           ss_typename_type_k
#endif /* compiler */
                       pointer_iterator<
        value_type
    ,   pointer
    ,   reference
    >::type                                                 iterator;
#endif /* 0 */
    /// The non-mutating (const) iterator type
    typedef
#if !defined(STLSOFT_COMPILER_IS_BORLAND)
         ss_typename_type_k
#endif /* compiler */
                       pointer_iterator<
        value_type const
    ,   const_pointer
    ,   const_reference
    >::type                                                 const_iterator;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
#if 0

    /// The reverse iterator type
    typedef reverse_iterator_base<
        iterator
    ,   value_type
    ,   reference
    ,   pointer
    ,   difference_type
    >                                                       reverse_iterator;
#endif /* 0 */

    /// The non-mutating (const) reverse iterator type
    typedef const_reverse_iterator_base<
        const_iterator
    ,   value_type const
    ,   const_reference
    ,   const_pointer
    ,   difference_type
    >                                                       const_reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

/// \name Construction
/// @{
public:
    /// Default constructor
    basic_string_view();
    /// Copy constructor
    basic_string_view(class_type const& rhs);
    /// Construct from the given string at the specified position
    basic_string_view(class_type const& s, size_type pos);
    /// Construct with \c cch characters from the given string at the
    /// specified position
    basic_string_view(class_type const& s, size_type pos, size_type cch);
    /// Construct from a null-terminated character string
    basic_string_view(char_type const* s); // No, not explicit! Sigh
    /// Construct with \c cch characters from the given character string
    basic_string_view(char_type const* s, size_type cch);
    /// Construct from the range [first:last)
    basic_string_view(char_type const* first, char_type const* last);
    /// Destructor
    ~basic_string_view() STLSOFT_NOEXCEPT;

    /// Copy assignment operator
    class_type& operator =(class_type const& rhs);
/// @}

/// \name Operations
/// @{
public:
    /// Swaps the contents between \c this and \c other
    void swap(class_type& other) STLSOFT_NOEXCEPT;

    /// Empties the string
    void clear() STLSOFT_NOEXCEPT;

    /// Clear c_str() representation
    ///
    /// Causes the c_str() representation, if currently allocated (see
    /// c_str() for details), to be destroyed, in order that the next call
    /// to c_str() will result in a fresh nul-terminated copy of the
    /// 'current' contents of the view.
    void refresh() STLSOFT_NOEXCEPT;
/// @}

/// \name Attributes
/// @{
public:
    /// The number of elements in the string
    size_type size() const STLSOFT_NOEXCEPT;
    /// The maximum number of elements that can be stored in the string
    static size_type max_size() STLSOFT_NOEXCEPT;
    /// The number of elements in the string
    size_type length() const STLSOFT_NOEXCEPT;
    /// The storage currently allocated by the string
    size_type capacity() const STLSOFT_NOEXCEPT;
    /// Indicates whether the string is empty
    ss_bool_t empty() const STLSOFT_NOEXCEPT;

    /// Returns an instance of the allocator type
    allocator_type get_allocator() const;
/// @}

/// \name Comparison
/// @{
public:
    /// Evaluates whether two strings are equal
    ss_bool_t equal(class_type const& rhs) const STLSOFT_NOEXCEPT;
    /// Evaluates whether two strings are equal
    ss_bool_t equal(value_type const* rhs, size_type cchRhs) const STLSOFT_NOEXCEPT;

    /// Compares \c this with the given string
    ss_sint_t compare(size_type pos, size_type cch, value_type const* s, size_type cchRhs) const STLSOFT_NOEXCEPT;
    /// Compares \c this with the given string
    ss_sint_t compare(size_type pos, size_type cch, value_type const* s) const STLSOFT_NOEXCEPT;
    /// Compares \c this with the given string
    ss_sint_t compare(value_type const* s) const STLSOFT_NOEXCEPT;
    /// Compares \c this with the given string
    ss_sint_t compare(size_type pos, size_type cch, class_type const& rhs, size_type posRhs, size_type cchRhs) const STLSOFT_NOEXCEPT;
    /// Compares \c this with the given string
    ss_sint_t compare(size_type pos, size_type cch, class_type const& rhs) const STLSOFT_NOEXCEPT;
    /// Compares \c this with the given string
    ss_sint_t compare(class_type const& rhs) const STLSOFT_NOEXCEPT;
/// @}

/// \name Accessors
/// @{
public:
#if 0

    /// Returns mutable reference at the given index
    reference               operator [](size_type index);
#endif /* 0 */
    /// Returns non-mutable (const) reference at the given index
    ///
    /// \note Follows the convention of std::basic_string in returning a
    ///   reference to char_type() if index == size(). This reference will
    ///   <b>not</b> be part of the block constituting the string's viewed
    ///   area.
    const_reference         operator [](size_type index) const;
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    /// Returns non-mutable (const) reference at the given index
    ///
    /// \note Throws std::out_of_range if index >= size()
    const_reference         at(size_type index) const;

    /// Returns a string of maximum length cch, from the position pos
    class_type              substr(size_type pos, size_type cch) const;
    class_type              substr(size_type pos) const;
    class_type              substr() const;
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    /// Returns null-terminated non-mutable (const) pointer to string data
    ///
    /// \note This returns a nul-terminated copy of the string. If the
    ///   view's underlying string changes after this point, this will not
    ///   be reflected in the value returned by c_str(), until such time as
    ///   refresh() is called.
    ///
    /// \note If the view's specialisation is with a no-throw allocator,
    ///   behaviour is undefined in con
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    value_type const*       c_str() const;
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
#if 0

    /// Facility for calling refresh() followed by c_str()
    ///
    /// \param bRefresh call refresh() before c_str()
    ///
    /// \note If bRefresh is \c false has identical semantics to c_str()
    value_type const*       c_str(ss_bool_t bRefresh) const;
#endif /* 0 */
    /// Returns non-mutable (const) pointer to string data
    value_type const*       data() const STLSOFT_NOEXCEPT;
    /// Returns value of base pointer
    value_type const*       base() const STLSOFT_NOEXCEPT;
#if 0

    /// Returns the first character in the string
    ///
    /// \note It is up to the user to ensure that the string is not empty
    reference               front();
    /// Returns the last character in the string
    ///
    /// \note It is up to the user to ensure that the string is not empty
    reference               back();
#endif /* 0 */
    /// Returns the first character in the string
    ///
    /// \note It is up to the user to ensure that the string is not empty
    const_reference         front() const;
    /// Returns the last character in the string
    ///
    /// \note It is up to the user to ensure that the string is not empty
    const_reference         back() const;

    /// Copies elements into the given destination
    size_type copy(value_type *dest, size_type cch, size_type pos = 0) const;
/// @}

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return A non-mutable (const) iterator representing the start of the
    ///   sequence
    const_iterator          begin() const;
    /// Ends the iteration
    ///
    /// \return A non-mutable (const) iterator representing the end of the
    ///   sequence
    const_iterator          end() const;
#if 0

    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    iterator                begin();
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    iterator                end();
#endif /* 0 */
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)

    /// Begins the reverse iteration
    ///
    /// \return A non-mutable (const) iterator representing the start of the
    ///   reverse sequence
    const_reverse_iterator  rbegin() const;
    /// Ends the reverse iteration
    ///
    /// \return A non-mutable (const) iterator representing the end of the
    ///   reverse sequence
    const_reverse_iterator  rend() const;
#if 0

    /// Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    reverse_iterator        rbegin();
    /// Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    reverse_iterator        rend();
#endif /* 0 */
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Invariant
/// @{
    ss_bool_t is_valid() const;

/// \name Implementation
/// @{
private:
    // Empty string
    static
    char_type const*
    empty_string_() STLSOFT_NOEXCEPT;

    // Comparison
    static
    ss_sint_t
    compare_(
        char_type const*    lhs
    ,   size_type           lhs_len
    ,   char_type const*    rhs
    ,   size_type           rhs_len
    ) STLSOFT_NOEXCEPT;

    // Closes the m_cstr member
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    void close_() STLSOFT_NOEXCEPT;
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */

    // Closes the m_cstr member and sets to \c nullptr
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    void close_set_null_() STLSOFT_NOEXCEPT;
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */

    const_iterator          begin_() const STLSOFT_NOEXCEPT;
    const_iterator          end_() const STLSOFT_NOEXCEPT;
#if 0
    iterator                begin_() STLSOFT_NOEXCEPT;
    iterator                end_() STLSOFT_NOEXCEPT;
#endif /* 0 */
/// @}

/// \name Members
/// @{
private:
    size_type           m_length;  // The number of elements in the view
    char_type const*    m_base;    // Pointer to the first element in the view, or NULL for a null view
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    char_type*          m_cstr;    // Pointer to a nul-terminated copy of the view, at the time of the c_str() call. Will be \c nullptr before c_str() is called
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT

typedef basic_string_view<ss_char_a_t>                      string_view;
typedef basic_string_view<ss_char_w_t>                      wstring_view;
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */

typedef basic_string_view<
    ss_char_a_t
,   stlsoft_char_traits<ss_char_a_t>
,   allocator_selector<ss_char_a_t>::allocator_type
>                                                           string_view;
typedef basic_string_view<
    ss_char_w_t
,   stlsoft_char_traits<ss_char_w_t>
,   allocator_selector<ss_char_w_t>::allocator_type
>                                                           wstring_view;
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */


/* /////////////////////////////////////////////////////////////////////////
 * traits
 */

/** Specialisation of stlsoft::string_traits<> for
 * stlsoft::basic_string_view<>
 */
# ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
struct string_traits<basic_string_view<C, T, A> >
{
    // NOTE: Originally, what is string_type_ was defined as value_type, but
    // Borland objects to value_type::value_type.
    typedef basic_string_view<C, T, A>                              string_type_;
    typedef ss_typename_type_k string_type_::value_type             char_type;
    typedef ss_typename_type_k string_type_::size_type              size_type;
    typedef char_type const                                         const_char_type;
    typedef string_type_                                            string_type;
    typedef string_type_                                            value_type;
//    typedef ss_typename_type_k string_type::pointer                 pointer;
    typedef ss_typename_type_k string_type::const_pointer           const_pointer;
//    typedef ss_typename_type_k string_type::iterator                iterator;
    typedef ss_typename_type_k string_type::const_iterator          const_iterator;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
//    typedef ss_typename_type_k string_type::reverse_iterator        reverse_iterator;
    typedef ss_typename_type_k string_type::const_reverse_iterator  const_reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
    enum
    {
            is_pointer          =   false
        ,   is_pointer_to_const =   false
        ,   char_type_size      =   sizeof(char_type)
    };

    static string_type empty_string()
    {
        return string_type();
    }
    static string_type construct(string_type const& src, size_type pos, size_type len)
    {
        return string_type(src, pos, len);
    }
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k I>
    static string_type& assign_inplace(string_type& str, I first, I last)
# else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    static string_type& assign_inplace(string_type& str, const_iterator first, const_iterator last)
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        // string view cannot assign in-place
        return (str = string_type(first, last), str);
    }
};
# else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

STLSOFT_TEMPLATE_SPECIALISATION
struct string_traits<string_view>
{
    typedef string_view                                     value_type;
    typedef value_type::value_type                          char_type;
    typedef value_type::size_type                           size_type;
    typedef char_type const                                 const_char_type;
    typedef value_type                                      string_type;
//    typedef string_type::pointer                            pointer;
    typedef string_type::const_pointer                      const_pointer;
//    typedef string_type::iterator                           iterator;
    typedef string_type::const_iterator                     const_iterator;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
//    typedef string_type::reverse_iterator                   reverse_iterator;
    typedef string_type::const_reverse_iterator             const_reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
    enum
    {
            is_pointer          =   false
        ,   is_pointer_to_const =   false
        ,   char_type_size      =   sizeof(char_type)
    };

    static string_type empty_string()
    {
        return string_type();
    }
    static string_type construct(string_type const& src, size_type pos, size_type len)
    {
        return string_type(src, pos, len);
    }
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k I>
    static string_type& assign_inplace(string_type& str, I first, I last)
# else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    static string_type& assign_inplace(string_type& str, const_iterator first, const_iterator last)
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        // string view cannot assign in-place
        return (str = string_type(first, last), str);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct string_traits<wstring_view>
{
    typedef wstring_view                                    value_type;
    typedef value_type::value_type                          char_type;
    typedef value_type::size_type                           size_type;
    typedef char_type const                                 const_char_type;
    typedef value_type                                      string_type;
//    typedef string_type::pointer                            pointer;
    typedef string_type::const_pointer                      const_pointer;
//    typedef string_type::iterator                           iterator;
    typedef string_type::const_iterator                     const_iterator;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
//    typedef string_type::reverse_iterator                   reverse_iterator;
    typedef string_type::const_reverse_iterator             const_reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
    enum
    {
            is_pointer          =   false
        ,   is_pointer_to_const =   false
        ,   char_type_size      =   sizeof(char_type)
    };

    static string_type empty_string()
    {
        return string_type();
    }
    static string_type construct(string_type const& src, size_type pos, size_type len)
    {
        return string_type(src, pos, len);
    }
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k I>
    static string_type& assign_inplace(string_type& str, I first, I last)
# else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    static string_type& assign_inplace(string_type& str, const_iterator first, const_iterator last)
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        // string view cannot assign in-place
        return (str = string_type(first, last), str);
    }
};
# endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */


/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// operator ==

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_bool_t operator ==(basic_string_view<C, T, A> const& lhs, basic_string_view<C, T, A> const& rhs)
{
    return lhs.equal(rhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator ==(basic_string_view<C, T, A> const& lhs, ss_typename_type_k basic_string_view<C, T, A>::char_type const* rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator ==(basic_string_view<C, T, A> const& lhs, C const* rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    typedef ss_typename_type_k basic_string_view<C, T, A>::size_type        size_type;
    typedef ss_typename_type_k basic_string_view<C, T, A>::traits_type      traits_type;

    size_type   rhs_len =   (NULL == rhs) ? 0 : traits_type::length(rhs);

    return lhs.equal(rhs, rhs_len);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator ==(ss_typename_type_k basic_string_view<C, T, A>::char_type const* lhs, basic_string_view<C, T, A> const& rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator ==(C *lhs, basic_string_view<C, T, A> const& rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    typedef ss_typename_type_k basic_string_view<C, T, A>::size_type        size_type;
    typedef ss_typename_type_k basic_string_view<C, T, A>::traits_type      traits_type;

    size_type   lhs_len =   (NULL == lhs) ? 0 : traits_type::length(lhs);

    return rhs.equal(lhs, lhs_len);
}

// operator !=

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_bool_t operator !=(basic_string_view<C, T, A> const& lhs, basic_string_view<C, T, A> const& rhs)
{
    return !lhs.equal(rhs);
}
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator !=(basic_string_view<C, T, A> const& lhs, ss_typename_type_k basic_string_view<C, T, A>::char_type const* rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator !=(basic_string_view<C, T, A> const& lhs, C const* rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    typedef ss_typename_type_k basic_string_view<C, T, A>::size_type        size_type;
    typedef ss_typename_type_k basic_string_view<C, T, A>::traits_type      traits_type;

    size_type   rhs_len =   (NULL == rhs) ? 0 : traits_type::length(rhs);

    return !lhs.equal(rhs, rhs_len);
}
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator !=(ss_typename_type_k basic_string_view<C, T, A>::char_type const* lhs, basic_string_view<C, T, A> const& rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator !=(C const* lhs, basic_string_view<C, T, A> const& rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    typedef ss_typename_type_k basic_string_view<C, T, A>::size_type        size_type;
    typedef ss_typename_type_k basic_string_view<C, T, A>::traits_type      traits_type;

    size_type   lhs_len =   (NULL == lhs) ? 0 : traits_type::length(lhs);

    return !rhs.equal(lhs, lhs_len);
}

// operator <

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_bool_t operator <(basic_string_view<C, T, A> const& lhs, basic_string_view<C, T, A> const& rhs)
{
    return lhs.compare(rhs) < 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator <(basic_string_view<C, T, A> const& lhs, ss_typename_type_k basic_string_view<C, T, A>::char_type const* rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator <(basic_string_view<C, T, A> const& lhs, C const* rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return lhs.compare(rhs) < 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator <(ss_typename_type_k basic_string_view<C, T, A>::char_type const* lhs, basic_string_view<C, T, A> const& rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator <(C const* lhs, basic_string_view<C, T, A> const& rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return rhs.compare(lhs) > 0;
}

// operator <=

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_bool_t operator <=(basic_string_view<C, T, A> const& lhs, basic_string_view<C, T, A> const& rhs)
{
    return lhs.compare(rhs) <= 0;
}
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator <=(basic_string_view<C, T, A> const& lhs, ss_typename_type_k basic_string_view<C, T, A>::char_type const* rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator <=(basic_string_view<C, T, A> const& lhs, C const* rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return lhs.compare(rhs) <= 0;
}
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator <=(ss_typename_type_k basic_string_view<C, T, A>::char_type const* lhs, basic_string_view<C, T, A> const& rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator <=(C const* lhs, basic_string_view<C, T, A> const& rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return rhs.compare(lhs) >= 0;
}

// operator >

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_bool_t operator >(basic_string_view<C, T, A> const& lhs, basic_string_view<C, T, A> const& rhs)
{
    return lhs.compare(rhs) > 0;
}
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator >(basic_string_view<C, T, A> const& lhs, ss_typename_type_k basic_string_view<C, T, A>::char_type const* rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator >(basic_string_view<C, T, A> const& lhs, C const* rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return lhs.compare(rhs) > 0;
}
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator >(ss_typename_type_k basic_string_view<C, T, A>::char_type const* lhs, basic_string_view<C, T, A> const& rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator >(C const* lhs, basic_string_view<C, T, A> const& rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return rhs.compare(lhs) < 0;
}

// operator >=

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_bool_t operator >=(basic_string_view<C, T, A> const& lhs, basic_string_view<C, T, A> const& rhs)
{
    return lhs.compare(rhs) >= 0;
}
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator >=(basic_string_view<C, T, A> const& lhs, ss_typename_type_k basic_string_view<C, T, A>::char_type const* rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator >=(basic_string_view<C, T, A> const& lhs, C const* rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return lhs.compare(rhs) >= 0;
}
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
inline ss_bool_t operator >=(ss_typename_type_k basic_string_view<C, T, A>::char_type const* lhs, basic_string_view<C, T, A> const& rhs)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
inline ss_bool_t operator >=(C const* lhs, basic_string_view<C, T, A> const& rhs)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return rhs.compare(lhs) <= 0;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * stream insertion
 */

template <
    ss_typename_param_k T_stream
,   ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
T_stream&
operator <<(
    T_stream&                           stm
,   basic_string_view<C, T, A> const&   s
)
{
    STLSOFT_NS_USING(util::string_insert);

    string_insert(stm, s.data(), s.size());

    return stm;
}


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// Implementation

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */ ss_typename_type_ret_k basic_string_view<C, T, A>::char_type const*
basic_string_view<C, T, A>::empty_string_() STLSOFT_NOEXCEPT
{
    // This character array is initialised to 0, which conveniently happens to
    // be the empty string, by the module/application load, so it is
    // guaranteed to be valid, and there are no threading/race conditions
    static char_type    s_empty[1];

    STLSOFT_ASSERT(s_empty[0] == '\0'); // Paranoid check

    return s_empty;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */ ss_sint_t
basic_string_view<C, T, A>::compare_(
    ss_typename_type_k basic_string_view<C, T, A>::value_type const*    lhs
,   ss_typename_type_k basic_string_view<C, T, A>::size_type            lhs_len
,   ss_typename_type_k basic_string_view<C, T, A>::value_type const*    rhs
,   ss_typename_type_k basic_string_view<C, T, A>::size_type            rhs_len
) STLSOFT_NOEXCEPT
{
    size_type   cmp_len =   (lhs_len < rhs_len) ? lhs_len : rhs_len;
    ss_int_t    result  =   traits_type::compare(lhs, rhs, cmp_len);

    if (0 == result)
    {
        if (lhs_len < rhs_len)
        {
            result = -1;
        }
        else
        if (lhs_len > rhs_len)
        {
            result = +1;
        }
    }

    return result;
}

#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */ void basic_string_view<C, T, A>::close_() STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(NULL != m_cstr);

    allocator_type& ator = *this;

    ator.deallocate(m_cstr, 1 + m_length);

#if defined(STLSOFT_COMPILER_IS_BORLAND)
    STLSOFT_SUPPRESS_UNUSED(ator);
#endif /* compiler */
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */ void basic_string_view<C, T, A>::close_set_null_() STLSOFT_NOEXCEPT
{
    if (NULL != m_cstr)
    {
        close_();

        m_cstr = NULL;
    }
}
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_string_view<C, T, A>::const_iterator
basic_string_view<C, T, A>::begin_() const STLSOFT_NOEXCEPT
{
    return m_base;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_string_view<C, T, A>::const_iterator
basic_string_view<C, T, A>::end_() const STLSOFT_NOEXCEPT
{
    return begin_() + m_length;
}

/** Invariant
 *
 * \ingroup group__library__String
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_bool_t basic_string_view<C, T, A>::is_valid() const
{
    // NOTE: Must not call any methods or ctors in this function!!

#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str

    if (0 == m_length &&
        NULL != m_cstr)
    {
        return false; // If the slice is empty, there should be no m_cstr
    }
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */

    if (0 != m_length &&
        NULL == m_base)
    {
        return false; // If the slice is non-empty, m_base should not be \c nullptr
    }

    return true;
}


// Construction

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline basic_string_view<C, T, A>::basic_string_view()
    : allocator_type()
    , stl_collection_tag()
    , m_length(0)
    , m_base(NULL)
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    , m_cstr(NULL)
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
{
    STLSOFT_ASSERT(is_valid());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline basic_string_view<C, T, A>::basic_string_view(basic_string_view<C, T, A> const& rhs)
    : allocator_type(rhs)
    , stl_collection_tag(rhs)
    , m_length(rhs.m_length)
    , m_base(rhs.m_base)
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    , m_cstr(NULL)
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
{
    STLSOFT_ASSERT(is_valid());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline basic_string_view<C, T, A>::basic_string_view(basic_string_view<C, T, A> const& rhs, ss_typename_type_k basic_string_view<C, T, A>::size_type pos)
    : allocator_type(rhs)
    , stl_collection_tag(rhs)
    , m_length(rhs.m_length - pos)
    , m_base(&rhs[pos]) // Use this so we get the debug-time invariant checking on the validity of pos
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    , m_cstr(NULL)
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
{
    STLSOFT_ASSERT(pos <= rhs.m_length);

    STLSOFT_ASSERT(is_valid());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline basic_string_view<C, T, A>::basic_string_view(   basic_string_view<C, T, A> const&                           rhs
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::size_type    pos
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::size_type    cch)
    : allocator_type(rhs)
    , stl_collection_tag(rhs)
    , m_length(cch)
    , m_base(&rhs[pos]) // Use this so we get the debug-time invariant checking on the validity of pos
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    , m_cstr(NULL)
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
{
    STLSOFT_ASSERT(is_valid());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline basic_string_view<C, T, A>::basic_string_view(ss_typename_type_k basic_string_view<C, T, A>::char_type const* s)
    : allocator_type()
    , stl_collection_tag()
    , m_length(T::length(s))
    , m_base(s)
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    , m_cstr(NULL)
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
{
    STLSOFT_ASSERT(is_valid());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline basic_string_view<C, T, A>::basic_string_view(   ss_typename_type_k basic_string_view<C, T, A>::char_type const* s
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::size_type cch)
    : allocator_type()
    , stl_collection_tag()
    , m_length(cch)
    , m_base(s)
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    , m_cstr(NULL)
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
{
    STLSOFT_ASSERT(is_valid());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline basic_string_view<C, T, A>::basic_string_view(   ss_typename_type_k basic_string_view<C, T, A>::char_type const* first
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::char_type const* last)
    : allocator_type()
    , stl_collection_tag()
    , m_length(static_cast<size_type>(last - first))
    , m_base(first)
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    , m_cstr(NULL)
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
{
    STLSOFT_ASSERT(first <= last);

    STLSOFT_ASSERT(is_valid());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline basic_string_view<C, T, A>::~basic_string_view() STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str

    if (NULL != m_cstr)
    {
        close_();
    }
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline basic_string_view<C, T, A> &basic_string_view<C, T, A>::operator =(basic_string_view<C, T, A> const& rhs)
{
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    close_set_null_();
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */

    m_length    =   rhs.m_length;
    m_base      =   rhs.m_base;

    return *this;
}

// Operations

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline void basic_string_view<C, T, A>::swap(ss_typename_type_k basic_string_view<C, T, A>::class_type& rhs) STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    std_swap(m_length, rhs.m_length);
    std_swap(m_base, rhs.m_base);
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    std_swap(m_cstr, rhs.m_cstr);
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */

    STLSOFT_ASSERT(is_valid());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline void basic_string_view<C, T, A>::clear() STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    close_set_null_();
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */

    m_length    =   0;
    m_base      =   NULL;

    STLSOFT_ASSERT(is_valid());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline void basic_string_view<C, T, A>::refresh() STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str
    close_set_null_();
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */

    STLSOFT_ASSERT(is_valid());
}

// Attributes

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::size_type basic_string_view<C, T, A>::size() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return m_length;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */ ss_typename_type_ret_k basic_string_view<C, T, A>::size_type basic_string_view<C, T, A>::max_size() STLSOFT_NOEXCEPT
{
    return static_cast<size_type>(-1) / sizeof(char_type);
}

//  size_type max_size() const;

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::size_type basic_string_view<C, T, A>::length() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return m_length;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::size_type basic_string_view<C, T, A>::capacity() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return m_length;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_bool_t basic_string_view<C, T, A>::empty() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return 0 == size();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::allocator_type basic_string_view<C, T, A>::get_allocator() const
{
    return *this;
}

// Comparison

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_bool_t basic_string_view<C, T, A>::equal(ss_typename_type_k basic_string_view<C, T, A>::class_type const& rhs) const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return (m_length == rhs.m_length) && ((m_base == rhs.m_base) || 0 == traits_type::compare(m_base, rhs.m_base, m_length));
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_bool_t basic_string_view<C, T, A>::equal(ss_typename_type_k basic_string_view<C, T, A>::value_type const* rhs, ss_typename_type_k basic_string_view<C, T, A>::size_type cchRhs) const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return (m_length == cchRhs) && ((m_base == rhs) || 0 == compare_(m_base, m_length, rhs, cchRhs));
}


template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_sint_t
basic_string_view<C, T, A>::compare(
    ss_typename_type_k basic_string_view<C, T, A>::size_type          pos
,   ss_typename_type_k basic_string_view<C, T, A>::size_type          cch
,   ss_typename_type_k basic_string_view<C, T, A>::value_type const*  rhs
,   ss_typename_type_k basic_string_view<C, T, A>::size_type          cchRhs
) const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    size_type   lhs_len =   size();

    if (pos >= lhs_len)
    {
        // pos is already at/beyond available lhs range

        pos = lhs_len;
        lhs_len = 0;
    }
    else
    {
        // adjust lhs_len based on cch requested

        if (lhs_len > pos + cch)
        {
            lhs_len = lhs_len - pos;
        }
    }

    size_type   rhs_len =   (NULL == rhs) ? 0 : traits_type::length(rhs);

    if (cchRhs < rhs_len)
    {
        rhs_len = cchRhs;
    }

    STLSOFT_ASSERT(is_valid());

    return compare_(m_base + pos, lhs_len, rhs, rhs_len);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_sint_t basic_string_view<C, T, A>::compare(   ss_typename_type_k basic_string_view<C, T, A>::size_type          pos
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::size_type          cch
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::value_type const*  rhs) const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    size_type   lhs_len =   size();

    if (!(pos < lhs_len))
    {
        pos = lhs_len;
    }
    else
    {
        lhs_len -= pos;
    }

    if (cch < lhs_len)
    {
        lhs_len = cch;
    }

    size_type   rhs_len =   (NULL == rhs) ? 0 : traits_type::length(rhs);

    STLSOFT_ASSERT(is_valid());

    return compare_(m_base + pos, lhs_len, rhs, rhs_len);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_sint_t basic_string_view<C, T, A>::compare(ss_typename_type_k basic_string_view<C, T, A>::value_type const* rhs) const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    size_type   lhs_len =   size();
    size_type   rhs_len =   (NULL == rhs) ? 0 : traits_type::length(rhs);

    return compare_(m_base, lhs_len, rhs, rhs_len);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_sint_t basic_string_view<C, T, A>::compare(   ss_typename_type_k basic_string_view<C, T, A>::size_type          pos
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::size_type          cch
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::class_type const&  rhs
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::size_type          posRhs
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::size_type          cchRhs) const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());
    STLSOFT_ASSERT(pos <= size());
    STLSOFT_ASSERT(posRhs <= rhs.size());

    size_type lhs_len = size();

    if (pos == lhs_len)
    {
        lhs_len = 0u;
    }
    else if (pos + cch > lhs_len)
    {
        lhs_len -= pos;
    }

    if (cch < lhs_len)
    {
        lhs_len = cch;
    }

    size_type rhs_len = rhs.size();

    if (posRhs == rhs_len)
    {
        rhs_len = 0u;
    }
    else if (posRhs + cchRhs > rhs_len)
    {
        rhs_len -= posRhs;
    }

    if (cchRhs < rhs_len)
    {
        rhs_len = cchRhs;
    }

    STLSOFT_ASSERT(is_valid());

    return compare_(m_base + pos, lhs_len, rhs.m_base + posRhs, rhs_len);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_sint_t basic_string_view<C, T, A>::compare(   ss_typename_type_k basic_string_view<C, T, A>::size_type          pos
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::size_type          cch
                                                    ,   ss_typename_type_k basic_string_view<C, T, A>::class_type const&  rhs) const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    size_type lhs_len = size();

    if (pos == lhs_len)
    {
        lhs_len = 0u;
    }
    else if (pos + cch > lhs_len)
    {
        lhs_len -= pos;
    }

    if (cch < lhs_len)
    {
        lhs_len = cch;
    }

    size_type rhs_len = rhs.size();

    STLSOFT_ASSERT(is_valid());

    return compare_(m_base + pos, lhs_len, rhs.m_base, rhs_len);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_sint_t basic_string_view<C, T, A>::compare(ss_typename_type_k basic_string_view<C, T, A>::class_type const& rhs) const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    size_type   lhs_len =   size();
    size_type   rhs_len =   rhs.size();

    STLSOFT_ASSERT(is_valid());

    return compare_(m_base, lhs_len, rhs.m_base, rhs_len);
}

// Accessors
#if 0

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::reference basic_string_view<C, T, A>::operator [](ss_typename_type_k basic_string_view<C, T, A>::size_type index)
{
    STLSOFT_ASSERT(is_valid());

    return m_base[index];
}
#endif /* 0 */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::const_reference basic_string_view<C, T, A>::operator [](ss_typename_type_k basic_string_view<C, T, A>::size_type index) const
{
    STLSOFT_MESSAGE_ASSERT("string_view index out of bounds", index <= size());

    STLSOFT_ASSERT(is_valid());

    return (index == size()) ? *empty_string_() : m_base[index];
}

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::const_reference basic_string_view<C, T, A>::at(ss_typename_type_k basic_string_view<C, T, A>::size_type index) const
{
    STLSOFT_ASSERT(is_valid());

    if (!(index < size()))
    {
        STLSOFT_THROW_X(stlsoft_ns_qual_std(out_of_range)("index out of range"));
    }

    STLSOFT_ASSERT(is_valid());

    return m_base[index];
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::class_type
  basic_string_view<C, T, A>::substr(
    ss_typename_type_k basic_string_view<C, T, A>::size_type pos
,   ss_typename_type_k basic_string_view<C, T, A>::size_type cch
) const
{
    STLSOFT_ASSERT(is_valid());

    if (pos > size())
    {
        STLSOFT_THROW_X(stlsoft_ns_qual_std(out_of_range)("index out of range"));
    }

    STLSOFT_ASSERT(is_valid());

    if (cch > (this->size() - pos))
    {
        cch = this->size() - pos;
    }

    return class_type(this->data() + pos, cch);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::class_type
  basic_string_view<C, T, A>::substr(
    ss_typename_type_k basic_string_view<C, T, A>::size_type pos
) const
{
    STLSOFT_ASSERT(is_valid());

    if (pos > size())
    {
        STLSOFT_THROW_X(stlsoft_ns_qual_std(out_of_range)("index out of range"));
    }

    STLSOFT_ASSERT(is_valid());

    return class_type(this->data() + pos, this->size() - pos);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::class_type
  basic_string_view<C, T, A>::substr() const
{
    return *this;
}
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::value_type const* basic_string_view<C, T, A>::c_str() const
{
    STLSOFT_ASSERT(is_valid());

    if (NULL != m_cstr)
    {
        // Already allocated, so return; if underlying
        return m_cstr;
    }
    else
    {
        if (0 == m_length)
        {
            return empty_string_();
        }
        else
        {
            // Must allocate the m_cstr member
            allocator_type& ator   =   const_cast<class_type&>(*this);
#ifdef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
            char_type*      s      =   ator.allocate(1 + size(), NULL);
#else /* ? STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
            char_type*      s      =   ator.allocate(1 + size());
#endif /* STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */

            STLSOFT_SUPPRESS_UNUSED(ator);  // Need this for silly old Borland

            // Because the class might be specialised with a no-throw allocator,
            // we'll check the result. This is really hokey, of course, since we're
            // returning a NULL string in the circumstances where memory has
            // failed to allocate. In such cases we can only hope that the memory
            // exhaustion is non-local and that the callee is going to suffer and die
            // anyway, irrespective of the fact that we've returned an invalid value
            // to it.
            if (NULL != s)
            {
                traits_type::copy(s, m_base, m_length);
                s[m_length] = '\0';

                remove_const(m_cstr) = s;

                STLSOFT_ASSERT(is_valid());
            }

            return m_cstr;
        }
    }
}
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
#if 0

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::value_type const* basic_string_view<C, T, A>::c_str(ss_bool_t bRefresh) const
{
    if (bRefresh)
    {
        const_cast<class_type*>(this)->refresh();
    }

    return c_str();
}
#endif /* 0 */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::value_type const* basic_string_view<C, T, A>::data() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return (0 == m_length) ? empty_string_() : m_base;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::value_type const* basic_string_view<C, T, A>::base() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return m_base;
}
#if 0

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::reference basic_string_view<C, T, A>::front()
{
    STLSOFT_ASSERT(is_valid());

    return (*this)[0];
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::reference basic_string_view<C, T, A>::back()
{
    STLSOFT_ASSERT(is_valid());

    return (*this)[size() - 1];
}
#endif /* 0 */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::const_reference basic_string_view<C, T, A>::front() const
{
    STLSOFT_ASSERT(is_valid());

    return (*this)[0];
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::const_reference basic_string_view<C, T, A>::back() const
{
    STLSOFT_ASSERT(is_valid());

    return (*this)[size() - 1];
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::size_type basic_string_view<C, T, A>::copy(   ss_typename_type_k basic_string_view<C, T, A>::value_type*  dest
                                                                                                ,   ss_typename_type_k basic_string_view<C, T, A>::size_type        cch
                                                                                                ,   ss_typename_type_k basic_string_view<C, T, A>::size_type        pos /* = 0 */) const
{
    STLSOFT_ASSERT(is_valid());

    size_type const len = size();

    if (pos < len)
    {
        if (len < pos + cch)
        {
            cch = len - pos;
        }

        traits_type::copy(dest, data() + pos, cch);
    }
    else
    {
        cch = 0;
    }

    STLSOFT_ASSERT(is_valid());

    return cch;
}


// Iteration

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::const_iterator basic_string_view<C, T, A>::begin() const
{
    STLSOFT_ASSERT(is_valid());

    return begin_();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::const_iterator basic_string_view<C, T, A>::end() const
{
    STLSOFT_ASSERT(is_valid());

    return end_();
}
#if 0

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::iterator basic_string_view<C, T, A>::begin()
{
    STLSOFT_ASSERT(is_valid());

    return begin_();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::iterator basic_string_view<C, T, A>::end()
{
    STLSOFT_ASSERT(is_valid());

    return end_();
}
#endif /* 0 */
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::const_reverse_iterator basic_string_view<C, T, A>::rbegin() const
{
    STLSOFT_ASSERT(is_valid());

    return const_reverse_iterator(end_());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::const_reverse_iterator basic_string_view<C, T, A>::rend() const
{
    STLSOFT_ASSERT(is_valid());

    return const_reverse_iterator(begin_());
}
#if 0

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::reverse_iterator basic_string_view<C, T, A>::rbegin()
{
    STLSOFT_ASSERT(is_valid());

    return reverse_iterator(end_());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_typename_type_ret_k basic_string_view<C, T, A>::reverse_iterator basic_string_view<C, T, A>::rend()
{
    STLSOFT_ASSERT(is_valid());

    return reverse_iterator(begin_());
}
#endif /* 0 */
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline void swap(basic_string_view<C, T, A>& lhs, basic_string_view<C, T, A>& rhs)
{
    lhs.swap(rhs);
}


/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

// c_str_data

/** \ref group__concept__Shim__string_access__c_str_data for stlsoft::basic_string_view
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline C const* c_str_data(STLSOFT_NS_QUAL(basic_string_view)<C, T, A> const& s)
{
    return s.data();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T, ss_typename_param_k A>
inline ss_char_a_t const* c_str_data_a(STLSOFT_NS_QUAL(basic_string_view)<ss_char_a_t, T, A> const& s)
{
    return s.data();
}
template <ss_typename_param_k T, ss_typename_param_k A>
inline ss_char_w_t const* c_str_data_w(STLSOFT_NS_QUAL(basic_string_view)<ss_char_w_t, T, A> const& s)
{
    return s.data();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// c_str_len

/** \ref group__concept__Shim__string_access__c_str_len for stlsoft::basic_string_view
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline ss_size_t c_str_len(STLSOFT_NS_QUAL(basic_string_view)<C, T, A> const& s)
{
    return s.length();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T, ss_typename_param_k A>
inline ss_size_t c_str_len_a(STLSOFT_NS_QUAL(basic_string_view)<ss_char_a_t, T, A> const& s)
{
    return s.length();
}
template <ss_typename_param_k T, ss_typename_param_k A>
inline ss_size_t c_str_len_w(STLSOFT_NS_QUAL(basic_string_view)<ss_char_w_t, T, A> const& s)
{
    return s.length();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// c_str_ptr

#ifdef STLSOFT_STRING_VIEW_PROVIDE_c_str

/** \ref group__concept__Shim__string_access__c_str_ptr for stlsoft::basic_string_view
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline C const* c_str_ptr(STLSOFT_NS_QUAL(basic_string_view)<C, T, A> const& s)
{
    return s.c_str();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T, ss_typename_param_k A>
inline ss_char_a_t const* c_str_ptr_a(STLSOFT_NS_QUAL(basic_string_view)<ss_char_a_t, T, A> const& s)
{
    return s.c_str();
}
template <ss_typename_param_k T, ss_typename_param_k A>
inline ss_char_w_t const* c_str_ptr_w(STLSOFT_NS_QUAL(basic_string_view)<ss_char_w_t, T, A> const& s)
{
    return s.c_str();
}
#endif /* STLSOFT_STRING_VIEW_PROVIDE_c_str */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// c_str_ptr_null

/** \ref group__concept__Shim__string_access__c_str_ptr_null for stlsoft::basic_string_view
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline C const* c_str_ptr_null(STLSOFT_NS_QUAL(basic_string_view)<C, T, A> const& s)
{
    return (0 != s.length()) ? s.c_str() : NULL;
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T, ss_typename_param_k A>
inline ss_char_a_t const* c_str_ptr_null_a(STLSOFT_NS_QUAL(basic_string_view)<ss_char_a_t, T, A> const& s)
{
    return (0 != s.length()) ? s.c_str() : NULL;
}
template <ss_typename_param_k T, ss_typename_param_k A>
inline ss_char_w_t const* c_str_ptr_null_w(STLSOFT_NS_QUAL(basic_string_view)<ss_char_w_t, T, A> const& s)
{
    return (0 != s.length()) ? s.c_str() : NULL;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* In the special case of Intel behaving as VC++ 7.0 or earlier on Win32, we
 * illegally insert into the std namespace.
 */
#if defined(STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template<
        ss_typename_param_k C
    ,   ss_typename_param_k T
    ,   ss_typename_param_k A
    >
    inline void swap(STLSOFT_NS_QUAL(basic_string_view)<C, T, A>& lhs, STLSOFT_NS_QUAL(basic_string_view)<C, T, A>& rhs)
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW */

/* ///////////////////////////// end of file //////////////////////////// */

