/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/string/simple_string.hpp (originally MSString.h, ::SynesisDev)
 *
 * Purpose: basic_simple_string class template.
 *
 * Created: 19th March 1993
 * Updated: 20th March 2024
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1993-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/simple_string.hpp
 *
 * \brief [C++] Definition of the stlsoft::basic_simple_string class
 *  template
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
#define STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_SIMPLE_STRING_MAJOR     4
# define STLSOFT_VER_STLSOFT_STRING_HPP_SIMPLE_STRING_MINOR     8
# define STLSOFT_VER_STLSOFT_STRING_HPP_SIMPLE_STRING_REVISION  1
# define STLSOFT_VER_STLSOFT_STRING_HPP_SIMPLE_STRING_EDIT      279
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS_FWD
# include <stlsoft/string/string_traits_fwd.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS_FWD */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE
# include <stlsoft/memory/allocator_base.hpp>       // for STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>       // for stlsoft::std_swap()
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_GENERATORS
# include <stlsoft/util/std/iterator_generators.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_GENERATORS */
#ifndef STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_BOUNDED
# include <stlsoft/algorithms/bounded.hpp>  // for stlsoft::copy_n()
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_BOUNDED */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX
# include <stlsoft/util/minmax.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST
# include <stlsoft/conversion/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION
# include <stlsoft/util/streams/string_insertion.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

#if defined(__BORLANDC__) && \
    __BORLANDC__ > 0x0580 && \
    defined(STLSOFT_DEBUG)
# include <stdio.h>
#endif /* compiler */

#ifndef STLSOFT_INCL_STDEXCEPT
# define STLSOFT_INCL_STDEXCEPT
# include <stdexcept>                       // for std::out_of_range
#endif /* !STLSOFT_INCL_STDEXCEPT */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
# define STLSOFT_SIMPLE_STRING_ITERATOR_METHODS_INLINE
#endif /* compiler */

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# error simple_string not currently compatible with compilation absent exception support
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

/** Simple string class
 *
 * \param C The character type
 * \param T The traits type. On translators that support default template arguments this is defaulted to char_traits<C>
 * \param A The allocator type. On translators that support default template arguments this is defaulted to allocator_selector<C>::allocator_type
 *
 * \ingroup group__library__String
 */
template<
    ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k T = stlsoft_char_traits<C>
,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T /* = stlsoft_char_traits<C> */
,   ss_typename_param_k A /* = allocator_selector<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>
// class basic_simple_string
class basic_simple_string
    : public stl_collection_tag
{
/// \name Member Types
/// @{
public:
    /// The value type
    typedef C                                               value_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The allocator type
    typedef A                                               allocator_type;
    /// The current specialisation of the type
    typedef basic_simple_string<
        C
    ,   T
    ,   A
    >                                                       class_type;
    /// The character type
    typedef value_type                                      char_type;
    /// The pointer type
    typedef value_type*                                     pointer;
    /// The non-mutable (const) pointer type
    typedef value_type const*                               const_pointer;
    /// The reference type
    typedef value_type&                                     reference;
    /// The non-mutable (const) reference type
    typedef value_type const&                               const_reference;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The difference type
    typedef ss_ptrdiff_t                                    difference_type;
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
    /// The mutating (non-const) reverse iterator type
    typedef ss_typename_type_k reverse_iterator_generator<
        iterator
    ,   value_type
    ,   reference
    ,   pointer
    ,   difference_type
    >::type                                                 reverse_iterator;
    /// The non-mutating (const) reverse iterator type
    typedef ss_typename_type_k const_reverse_iterator_generator<
        const_iterator
    ,   value_type
    ,   const_reference
    ,   const_pointer
    ,   difference_type
    >::type                                                 const_reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
private:
    /// The allocator type for allocating bytes
    ///
    /// \note This has to be defined here, rather than on a use-by-use basis, because
    /// Borland gets very upset.
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    typedef ss_typename_type_k A::ss_template_qual_k rebind<
        ss_byte_t
    >::other                                                byte_ator_type;
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    typedef ss_typename_type_k allocator_selector<
        ss_byte_t
    >::allocator_type                                       byte_ator_type;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
/// @}

/// \name Construction
/// @{
public:
    /// Default constructor
    basic_simple_string() STLSOFT_NOEXCEPT;
    /// Copy constructor
    basic_simple_string(class_type const& rhs);
    /// Construct from the given string at the specified position
    basic_simple_string(class_type const& s, size_type pos);
    /// Construct with \c cch characters from the given string at the specified position
    basic_simple_string(class_type const& s, size_type pos, size_type cch);
    /// Construct from the given character string
    basic_simple_string(char_type const* s); // Not, not explicit. Sigh
    /// Construct with \c cch characters from the given character string
    basic_simple_string(char_type const* s, size_type cch);
    /// Construct with \c cch characters each set to \c ch
    basic_simple_string(size_type cch, char_type ch);
    /// Construct from the range [first:last)
    template <ss_typename_param_k II>
    basic_simple_string(II first, II last)
        : m_buffer(class_type::empty_buffer_())
    {
        assign(first, last);
    }
#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

    /// Transfers the contents of the instance \c rhs
    basic_simple_string(class_type&& rhs) STLSOFT_NOEXCEPT;
#endif /* STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */

    /// Destructor
    ~basic_simple_string() STLSOFT_NOEXCEPT;
/// @}

/// \name Assignment
/// @{
public:
    /// Assigns from the given character string
    class_type& assign(char_type const* s);
    /// Assigns with \c cch characters from the given character string
    class_type& assign(char_type const* s, size_type cch);
    /// Assigns with \c cch characters from the given character string at the specified position
    class_type& assign(class_type const& str, size_type pos, size_type cch);
    /// Assigns from the given string
    class_type& assign(class_type const& str);
    /// Assigns \c cch characters with the value \c ch
    class_type& assign(size_type cch, char_type ch);
    /// Assigns from the range [first:last)
    template <ss_typename_param_k II>
    class_type& assign(II first, II last)
    {
# if (  defined(STLSOFT_COMPILER_IS_GCC) && \
        __GNUC__ < 3) || \
     (  defined(STLSOFT_COMPILER_IS_BORLAND) && \
        defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_BORLAND))

        typedef ss_typename_type_k std::iterator_traits<II> traits_t;

        return assign_(first, last, traits_t::iterator_category());
# elif defined(STLSOFT_COMPILER_IS_MWERKS) || \
       defined(STLSOFT_COMPILER_IS_DMC)

        return assign_(first, last, stlsoft_iterator_query_category_ptr(II, first));
# else /* ? compiler */

        return assign_(first, last, stlsoft_iterator_query_category(II, first));
# endif /* compiler */
    }

    /// Copy assignment operator
    class_type const& operator =(class_type const& rhs);
    /// Assignment operator
    class_type const& operator =(char_type const* s);
    /// Assignment operator
    class_type const& operator =(char_type ch);
/// @}

/// \name Appending
/// @{
public:
    /// Appends the given character string
    class_type& append(char_type const* s);
    /// Appends \c cch characters from the given character string
    class_type& append(char_type const* s, size_type cch);
    /// Assigns \c cch characters from the given character string at the specified position
    class_type& append(class_type const& str, size_type pos, size_type cch);
    /// Appends the given string
    class_type& append(class_type const& str);
    /// Appends \c cch characters with the value \c ch
    class_type& append(size_type cch, char_type ch);
    /// Appends the range [first:last)
    template <ss_typename_param_k II>
    class_type& append(II first, II last)
    {
# if (  defined(STLSOFT_COMPILER_IS_GCC) && \
        __GNUC__ < 3) || \
     (  defined(STLSOFT_COMPILER_IS_BORLAND) && \
        defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_BORLAND))

        typedef ss_typename_type_k std::iterator_traits<II> traits_t;

        return append_(first, last, traits_t::iterator_category());
# elif defined(STLSOFT_COMPILER_IS_MWERKS) || \
       defined(STLSOFT_COMPILER_IS_DMC)

        return append_(first, last, stlsoft_iterator_query_category_ptr(II, first));
# else /* ? compiler */

        return append_(first, last, stlsoft_iterator_query_category(II, first));
# endif /* compiler */
    }

    /// Concatenation operator
    class_type& operator +=(char_type ch);
    /// Concatenation operator
    class_type& operator +=(char_type const* s);
    /// Concatenation operator
    class_type& operator +=(class_type const& rhs);

    /// Appends a single character
    void push_back(char_type ch);
    /// Removes the last character
    void pop_back() STLSOFT_NOEXCEPT;
/// @}

/// \name Modifiers
/// @{
public:
    /// Reserves at least cch characters
    void reserve(size_type cch);
    /// Swaps the contents between \c this and \c other
    void swap(class_type& other) STLSOFT_NOEXCEPT;

    /// Resizes the string
    ///
    /// \param cch The new size of the string
    /// \param ch The value with which to initialise additional items if the string is expanded
    void resize(size_type cch, value_type ch = value_type());

    /// Empties the string
    void clear() STLSOFT_NOEXCEPT;
/// @}

/// \name Attributes
/// @{
public:
    /// The number of elements in the string
    size_type size() const STLSOFT_NOEXCEPT;
    /// The maximum number of elements that can be stored in the string
    size_type max_size() const STLSOFT_NOEXCEPT;
    /// The number of elements in the string
    size_type length() const STLSOFT_NOEXCEPT;
    /// The storage currently allocated by the string
    size_type capacity() const STLSOFT_NOEXCEPT;
    /// Indicates whether the string is empty
    ss_bool_t empty() const STLSOFT_NOEXCEPT;
/// @}

/// \name Comparison
/// @{
public:
    /// Equates the substring [pos, pos+cch) of \c this with the substring [0, cchRhs) of the given C-style string \c s
    ss_bool_t equal(size_type pos, size_type cch, value_type const* s, size_type cchRhs) const;
    /// Equates the substring [pos, pos+cch) of \c this with the given C-style string \c s
    ss_bool_t equal(size_type pos, size_type cch, value_type const* s) const;
    /// Equates \c this with the given C-style string \c s
    ss_bool_t equal(value_type const* s) const STLSOFT_NOEXCEPT;
    /// Equates the substring [pos, pos+cch) of \c this with the substring [posRhs, posRhs+cchRhs) of the given string \c rhs
    ss_bool_t equal(size_type pos, size_type cch, class_type const& rhs, size_type posRhs, size_type cchRhs) const;
    /// Equates the substring [pos, pos+cch) of \c this with the given string
    ss_bool_t equal(size_type pos, size_type cch, class_type const& rhs) const;
    /// Equates \c this with the given string \c rhs
    ss_bool_t equal(class_type const& rhs) const STLSOFT_NOEXCEPT;

    /// Compares the substring [pos, pos+cch) of \c this with the substring [0, cchRhs) of the given C-style string \c s
    ss_sint_t compare(size_type pos, size_type cch, value_type const* s, size_type cchRhs) const;
    /// Compares the substring [pos, pos+cch) of \c this with the given C-style string \c s
    ss_sint_t compare(size_type pos, size_type cch, value_type const* s) const;
    /// Compares \c this with the given C-style string \c s
    ss_sint_t compare(value_type const* s) const STLSOFT_NOEXCEPT;
    /// Compares the substring [pos, pos+cch) of \c this with the substring [posRhs, posRhs+cchRhs) of the given string \c rhs
    ss_sint_t compare(size_type pos, size_type cch, class_type const& rhs, size_type posRhs, size_type cchRhs) const;
    /// Compares the substring [pos, pos+cch) of \c this with the given string \c rhs
    ss_sint_t compare(size_type pos, size_type cch, class_type const& rhs) const;
    /// Compares \c this with the given string \c rhs
    ss_sint_t compare(class_type const& rhs) const STLSOFT_NOEXCEPT;

    /// Indicates whether the string contains the string \c s
    bool contains(class_type const& s) const STLSOFT_NOEXCEPT;
    /// Indicates whether the string contains the C-style string \c s
    bool contains(char_type const* s) const STLSOFT_NOEXCEPT;
    /// Indicates whether the string contains the character \c ch
    bool contains(char_type ch) const STLSOFT_NOEXCEPT;

    /// Indicates whether the string starts with the string \c s
    bool starts_with(class_type const& s) const STLSOFT_NOEXCEPT;
    /// Indicates whether the string starts with the C-style string \c s
    bool starts_with(char_type const* s) const STLSOFT_NOEXCEPT;
    /// Indicates whether the string starts with the character \c ch
    bool starts_with(char_type ch) const STLSOFT_NOEXCEPT;

    /// Indicates whether the string ends with the string \c s
    bool ends_with(class_type const& s) const STLSOFT_NOEXCEPT;
    /// Indicates whether the string ends with the C-style string \c s
    bool ends_with(char_type const* s) const STLSOFT_NOEXCEPT;
    /// Indicates whether the string ends with the character \c ch
    bool ends_with(char_type ch) const STLSOFT_NOEXCEPT;
/// @}

/// \name Accessors
/// @{
public:
    /// Returns mutable reference at the given index
    reference       operator [](size_type index) STLSOFT_NOEXCEPT;
    /// Returns non-mutable (const) reference at the given index
    const_reference operator [](size_type index) const STLSOFT_NOEXCEPT;

    /// Returns mutable (non-const) reference at the given index
    ///
    /// \note Throws std::out_of_range if index >= size()
    reference               at(size_type index);
    /// Returns non-mutable (const) reference at the given index
    ///
    /// \note Throws std::out_of_range if index >= size()
    const_reference         at(size_type index) const;

    /// Returns a string of maximum length cch, from the position pos
    class_type              substr(size_type pos, size_type cch) const;
    class_type              substr(size_type pos) const;
    class_type              substr() const;

    /// Returns null-terminated non-mutable (const) pointer to string data
    value_type const*       c_str() const STLSOFT_NOEXCEPT;
    /// Returns non-mutable (const) pointer to string data
    value_type const*       data() const STLSOFT_NOEXCEPT;

    /// Returns the first character in the string
    ///
    /// \note It is us to the user to ensure that the string is not empty
    reference               front() STLSOFT_NOEXCEPT;
    /// Returns the last character in the string
    ///
    /// \note It is us to the user to ensure that the string is not empty
    reference               back() STLSOFT_NOEXCEPT;
    /// Returns the first character in the string
    ///
    /// \note It is us to the user to ensure that the string is not empty
    const_reference         front() const STLSOFT_NOEXCEPT;
    /// Returns the last character in the string
    ///
    /// \note It is us to the user to ensure that the string is not empty
    const_reference         back() const STLSOFT_NOEXCEPT;

    /// Copies elements into the given destination
    size_type copy(
        value_type* dest
    ,   size_type   cch
    ,   size_type   pos = 0
    ) const STLSOFT_NOEXCEPT;
/// @}

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return A non-mutable (const) iterator representing the start of the sequence
#ifdef STLSOFT_SIMPLE_STRING_ITERATOR_METHODS_INLINE
    const_iterator          begin() const STLSOFT_NOEXCEPT
    {
        return const_cast<class_type*>(this)->begin_();
    }
#else /* ? STLSOFT_SIMPLE_STRING_ITERATOR_METHODS_INLINE */
    const_iterator          begin() const STLSOFT_NOEXCEPT;
#endif /* STLSOFT_SIMPLE_STRING_ITERATOR_METHODS_INLINE */
    /// Ends the iteration
    ///
    /// \return A non-mutable (const) iterator representing the end of the sequence
#ifdef STLSOFT_SIMPLE_STRING_ITERATOR_METHODS_INLINE
    const_iterator          end() const STLSOFT_NOEXCEPT
    {
        return const_cast<class_type*>(this)->end_();
    }
#else /* ? STLSOFT_SIMPLE_STRING_ITERATOR_METHODS_INLINE */
    const_iterator          end() const STLSOFT_NOEXCEPT;
#endif /* STLSOFT_SIMPLE_STRING_ITERATOR_METHODS_INLINE */
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    iterator                begin() STLSOFT_NOEXCEPT;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    iterator                end() STLSOFT_NOEXCEPT;

#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// Begins the reverse iteration
    ///
    /// \return A non-mutable (const) iterator representing the start of the reverse sequence
    const_reverse_iterator  rbegin() const STLSOFT_NOEXCEPT;
    /// Ends the reverse iteration
    ///
    /// \return A non-mutable (const) iterator representing the end of the reverse sequence
    const_reverse_iterator  rend() const STLSOFT_NOEXCEPT;
    /// Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    reverse_iterator        rbegin() STLSOFT_NOEXCEPT;
    /// Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    reverse_iterator        rend() STLSOFT_NOEXCEPT;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Implementation
/// @{
private:
    enum { alloc_quantum = 31 };    // Must be (2^n - 1)

    struct string_buffer
    {
        size_type   capacity;       // The number of char places in the buffer
        size_type   length;         // The number of chars in the string (<= capacity)
        char_type   contents[1];    // The first element in the array
    };

    typedef auto_buffer_old<
        char_type
    ,   allocator_type
    >                                                       buffer_type_;

    // creating buffer

    static string_buffer*       alloc_buffer_(char_type const* s, size_type cch, size_type cchReserve);
    static string_buffer*       alloc_buffer_(char_type const* s);
    static string_buffer*       alloc_buffer_(class_type const& rhs, size_type pos);
    static string_buffer*       alloc_buffer_(class_type const& rhs, size_type pos, size_type cch);

    // copying a buffer
    static string_buffer*       copy_buffer_(string_buffer* rhs_buffer);

    // destroying buffer
    static void                 destroy_buffer_(string_buffer*) STLSOFT_NOEXCEPT;

    // iteration
    pointer                     begin_() STLSOFT_NOEXCEPT;
    pointer                     end_() STLSOFT_NOEXCEPT;

    // invariance
    ss_bool_t is_valid() const STLSOFT_NOEXCEPT;

    // empty string
    static string_buffer*       empty_buffer_() STLSOFT_NOEXCEPT;

    // comparison
    static ss_sint_t compare_(
        char_type const*    lhs
    ,   size_type           lhs_len
    ,   char_type const*    rhs
    ,   size_type           rhs_len
    ) STLSOFT_NOEXCEPT;

    // testing same-known-length lhs and rhs
    static ss_bool_t equal_(
        char_type const*    lhs
    ,   char_type const*    rhs
    ,   size_type           len
    ) STLSOFT_NOEXCEPT;

    bool starts_with_(
        char_type const*    s
    ,   size_type           n
    ) const STLSOFT_NOEXCEPT;
    bool ends_with_(
        char_type const*    s
    ,   size_type           n
    ) const STLSOFT_NOEXCEPT;


    // assignment
    template <ss_typename_param_k II>
# if defined(STLSOFT_COMPILER_IS_MWERKS) || \
     defined(STLSOFT_COMPILER_IS_DMC)

    // there seems to be a bug in CodeWarrior that makes it have a cow with iterator tags by value, so we just use a ptr
    class_type& assign_(II first, II last, STLSOFT_NS_QUAL_STD(input_iterator_tag) const*)
# else /* ? compiler */

    class_type& assign_(II first, II last, STLSOFT_NS_QUAL_STD(input_iterator_tag))
# endif /* compiler */
    {
        STLSOFT_NS_QUAL_STD(copy)(first, last, STLSOFT_NS_QUAL_STD(back_inserter)(*this));

        STLSOFT_ASSERT(is_valid());

        return *this;
    }
    template <ss_typename_param_k II>
# if defined(STLSOFT_COMPILER_IS_MWERKS) || \
     defined(STLSOFT_COMPILER_IS_DMC)

    // there seems to be a bug in CodeWarrior that makes it have a cow with iterator tags by value, so we just use a ptr
    class_type& assign_(II first, II last, STLSOFT_NS_QUAL_STD(forward_iterator_tag) const*)
# else /* ? compiler */

    class_type& assign_(II first, II last, STLSOFT_NS_QUAL_STD(forward_iterator_tag))
# endif /* compiler */
    {
        ss_size_t const n   =   static_cast<ss_size_t>(STLSOFT_NS_QUAL_STD(distance)(first, last));
        buffer_type_    buffer(n);

        copy_n(first, buffer.size(), &buffer[0]);
        assign(buffer.data(), buffer.size());

        STLSOFT_ASSERT(is_valid());

        return *this;
    }

    // appending
    template <ss_typename_param_k II>
# if defined(STLSOFT_COMPILER_IS_MWERKS) || \
     defined(STLSOFT_COMPILER_IS_DMC)

    class_type& append_(II first, II last, STLSOFT_NS_QUAL_STD(input_iterator_tag) const*)
# else /* ? compiler */

    class_type& append_(II first, II last, STLSOFT_NS_QUAL_STD(input_iterator_tag))
# endif /* compiler */
    {
        STLSOFT_NS_QUAL_STD(copy)(first, last, STLSOFT_NS_QUAL_STD(back_inserter)(*this));

        STLSOFT_ASSERT(is_valid());

        return *this;
    }
    template <ss_typename_param_k II>
# if defined(STLSOFT_COMPILER_IS_MWERKS) || \
     defined(STLSOFT_COMPILER_IS_DMC)

    class_type& append_(II first, II last, STLSOFT_NS_QUAL_STD(forward_iterator_tag) const*)
# else /* ? compiler */

    class_type& append_(II first, II last, STLSOFT_NS_QUAL_STD(forward_iterator_tag))
# endif /* compiler */
    {
        buffer_type_  buffer(static_cast<ss_size_t>(STLSOFT_NS_QUAL_STD(distance)(first, last)));

        std_copy(first, last, &buffer[0]);
        append(buffer.data(), buffer.size());

        STLSOFT_ASSERT(is_valid());

        return *this;
    }
/// @}

/// \name Members
/// @{
private:
    string_buffer* m_buffer;
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT

typedef basic_simple_string<
    ss_char_a_t
>                                                           simple_string;
typedef basic_simple_string<
    ss_char_w_t
>                                                           simple_wstring;
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
typedef basic_simple_string<
    ss_char_a_t
,   stlsoft_char_traits<ss_char_a_t>
,   allocator_selector<ss_char_a_t>::allocator_type
>                                                           simple_string;
typedef basic_simple_string<
    ss_char_w_t
,   stlsoft_char_traits<ss_char_w_t>
,   allocator_selector<ss_char_w_t>::allocator_type
>                                                           simple_wstring;
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */


/* /////////////////////////////////////////////////////////////////////////
 * traits
 */

/** Specialisation for stlsoft::basic_simple_string<>
 */
# ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
struct string_traits<
   basic_simple_string<C, T, A>
>
{
    // NOTE: Originally, what is string_type_ was defined as value_type, but
    // Borland objects to value_type::value_type.
    typedef basic_simple_string<C>                                  string_type_;
    typedef ss_typename_type_k string_type_::value_type             char_type;
    typedef ss_typename_type_k string_type_::size_type              size_type;
    typedef char_type const                                         const_char_type;
    typedef string_type_                                            string_type;
    typedef string_type_                                            value_type;
    typedef ss_typename_type_k string_type::pointer                 pointer;
    typedef ss_typename_type_k string_type::const_pointer           const_pointer;
    typedef ss_typename_type_k string_type::iterator                iterator;
    typedef ss_typename_type_k string_type::const_iterator          const_iterator;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    typedef ss_typename_type_k string_type::reverse_iterator        reverse_iterator;
    typedef ss_typename_type_k string_type::const_reverse_iterator  const_reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
    enum
    {
            is_pointer          =   false
        ,   is_pointer_to_const =   false
        ,   char_type_size      =   sizeof(char_type)
    };

    static string_type empty_string() STLSOFT_NOEXCEPT
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
        // simple_string can assign in-place
        return str.assign(first, last);
    }
};
# else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

STLSOFT_TEMPLATE_SPECIALISATION
struct string_traits<simple_string>
{
    typedef basic_simple_string<ss_char_a_t>                value_type;
    typedef value_type::value_type                          char_type;
    typedef value_type::size_type                           size_type;
    typedef char_type const                                 const_char_type;
    typedef value_type                                      string_type;
    typedef string_type::pointer                            pointer;
    typedef string_type::const_pointer                      const_pointer;
    typedef string_type::iterator                           iterator;
    typedef string_type::const_iterator                     const_iterator;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    typedef string_type::reverse_iterator                   reverse_iterator;
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
        // simple_string can assign in-place
        return str.assign(first, last);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct string_traits<simple_wstring>
{
    typedef basic_simple_string<ss_char_w_t>                value_type;
    typedef value_type::value_type                          char_type;
    typedef value_type::size_type                           size_type;
    typedef char_type const                                 const_char_type;
    typedef value_type                                      string_type;
    typedef string_type::pointer                            pointer;
    typedef string_type::const_pointer                      const_pointer;
    typedef string_type::iterator                           iterator;
    typedef string_type::const_iterator                     const_iterator;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    typedef string_type::reverse_iterator                   reverse_iterator;
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
        // simple_string can assign in-place
        return str.assign(first, last);
    }
};
# endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */


/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// operator ==

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
operator ==(
    basic_simple_string<C, T, A> const& lhs
,   basic_simple_string<C, T, A> const& rhs
)
{
    return lhs.equal(rhs);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator ==(
    basic_simple_string<C, T, A> const&                                 lhs
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator ==(
    basic_simple_string<C, T, A> const& lhs
,   C const*                            rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return lhs.equal(rhs);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator ==(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   lhs
,   basic_simple_string<C, T, A> const&                                 rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator ==(
    C const*                            lhs
,   basic_simple_string<C, T, A> const& rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return rhs.equal(lhs);
}

// operator !=

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
operator !=(
    basic_simple_string<C, T, A> const& lhs
,   basic_simple_string<C, T, A> const& rhs
)
{
    return !lhs.equal(rhs);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator !=(
    basic_simple_string<C, T, A> const&                                 lhs
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator !=(
    basic_simple_string<C, T, A> const& lhs
,   C const*                            rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return !lhs.equal(rhs);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator !=(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   lhs
,   basic_simple_string<C, T, A> const&                                 rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator !=(
    C const*                            lhs
,   basic_simple_string<C, T, A> const& rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return !rhs.equal(lhs);
}

// operator <

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
operator <(
    basic_simple_string<C, T, A> const& lhs
,   basic_simple_string<C, T, A> const& rhs
)
{
    return lhs.compare(rhs) < 0;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator <(
    basic_simple_string<C, T, A> const&                                 lhs
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator <(
    basic_simple_string<C, T, A> const& lhs
,   C const*                            rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return lhs.compare(rhs) < 0;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator <(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   lhs
,   basic_simple_string<C, T, A> const&                                 rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator <(
    C const*                            lhs
,   basic_simple_string<C, T, A> const& rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return rhs.compare(lhs) > 0;
}

// operator <=

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
operator <=(
    basic_simple_string<C, T, A> const& lhs
,   basic_simple_string<C, T, A> const& rhs
)
{
    return lhs.compare(rhs) <= 0;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator <=(
    basic_simple_string<C, T, A> const&                                 lhs
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator <=(
    basic_simple_string<C, T, A> const& lhs
,   C const*                            rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return lhs.compare(rhs) <= 0;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator <=(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   lhs
,   basic_simple_string<C, T, A> const&                                 rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator <=(
    C const*                            lhs
,   basic_simple_string<C, T, A> const& rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return rhs.compare(lhs) >= 0;
}

// operator >

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
operator >(
    basic_simple_string<C, T, A> const& lhs
,   basic_simple_string<C, T, A> const& rhs
)
{
    return lhs.compare(rhs) > 0;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator >(
    basic_simple_string<C, T, A> const&                                 lhs
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator >(
    basic_simple_string<C, T, A> const& lhs
,   C const*                            rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return lhs.compare(rhs) > 0;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator >(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   lhs
,   basic_simple_string<C, T, A> const&                                 rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator >(
    C const*                            lhs
,   basic_simple_string<C, T, A> const& rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return rhs.compare(lhs) < 0;
}

// operator >=

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
operator >=(
    basic_simple_string<C, T, A> const& lhs
,   basic_simple_string<C, T, A> const& rhs
)
{
    return lhs.compare(rhs) >= 0;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator >=(
    basic_simple_string<C, T, A> const&                                 lhs
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator >=(
    basic_simple_string<C, T, A> const& lhs
,   C const*                            rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return lhs.compare(rhs) >= 0;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator >=(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   lhs
,   basic_simple_string<C, T, A> const&                                 rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator >=(
    C const*                            lhs
,   basic_simple_string<C, T, A> const& rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return rhs.compare(lhs) <= 0;
}

// operator +

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>
operator +(
    basic_simple_string<C, T, A> const& lhs
,   basic_simple_string<C, T, A> const& rhs
)
{
    return basic_simple_string<C, T, A>(lhs) += rhs;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator +(
    basic_simple_string<C, T, A> const&                                 lhs
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator +(
    basic_simple_string<C, T, A> const& lhs
,   C const*                            rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return basic_simple_string<C, T, A>(lhs) += rhs;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator +(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   lhs
,   basic_simple_string<C, T, A> const&                                 rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator +(
    C const*                            lhs
,   basic_simple_string<C, T, A> const& rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return basic_simple_string<C, T, A>(lhs) += rhs;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator +(
    basic_simple_string<C, T, A> const&                         lhs
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type  rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator +(
    basic_simple_string<C, T, A> const& lhs
,   C                                   rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return basic_simple_string<C, T, A>(lhs) += rhs;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>
#ifdef STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT
operator +(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type  lhs
,   basic_simple_string<C, T, A> const&                         rhs
)
#else /* ? STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
operator +(
    C                                   lhs
,   basic_simple_string<C, T, A> const& rhs
)
#endif /* STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT */
{
    return basic_simple_string<C, T, A>(1, lhs) += rhs;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/* c_str_ptr_null */

/** Returns the corresponding C-string pointer of \c s, or a null pointer
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
C const*
c_str_ptr_null(basic_simple_string<C, T, A> const& s)
{
    return (0 == s.length()) ? ss_nullptr_k : s.c_str();
}
/** char variant of c_str_ptr_null for basic_simple_string specialisations
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_char_a_t const*
c_str_ptr_null_a(basic_simple_string<ss_char_a_t, T, A> const& s)
{
    return c_str_ptr_null(s);
}
/** wchar_t variant of c_str_ptr_null for basic_simple_string specialisations
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_char_w_t const*
c_str_ptr_null_w(basic_simple_string<ss_char_w_t, T, A> const& s)
{
    return c_str_ptr_null(s);
}

/* c_str_ptr */

/** Returns the corresponding C-string pointer of \c s
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
C const*
c_str_ptr(basic_simple_string<C, T, A> const& s)
{
    return s.c_str();
}
/** char variant of c_str_ptr for basic_simple_string specialisations
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_char_a_t const*
c_str_ptr_a(basic_simple_string<ss_char_a_t, T, A> const& s)
{
    return c_str_ptr(s);
}
/** wchar_t variant of c_str_ptr for basic_simple_string specialisations
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_char_w_t const*
c_str_ptr_w(basic_simple_string<ss_char_w_t, T, A> const& s)
{
    return c_str_ptr(s);
}

/* c_str_data */

/** Returns the corresponding C-string pointer of \c s
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
C const*
c_str_data(basic_simple_string<C, T, A> const& s)
{
    return s.data();
}
/** char variant of c_str_data for basic_simple_string specialisations
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_char_a_t const*
c_str_data_a(basic_simple_string<ss_char_a_t, T, A> const& s)
{
    return c_str_data(s);
}
/** wchar_t variant of c_str_data for basic_simple_string specialisations
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_char_w_t const*
c_str_data_w(basic_simple_string<ss_char_w_t, T, A> const& s)
{
    return c_str_data(s);
}

/* c_str_ptr_len */

/** Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_size_t
c_str_len(basic_simple_string<C, T, A> const& s)
{
    return s.length();
}
/** char variant of c_str_len for basic_simple_string specialisations
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_size_t
c_str_len_a(basic_simple_string<ss_char_a_t, T, A> const& s)
{
    return c_str_len(s);
}
/** wchar_t variant of c_str_len for basic_simple_string specialisations
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_size_t
c_str_len_w(basic_simple_string<ss_char_w_t, T, A> const& s)
{
    return c_str_len(s);
}


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
,   basic_simple_string<C, T, A> const& s
)
{
    STLSOFT_NS_USING(util::string_insert);

    string_insert(stm, s.data(), s.size());

    return stm;
}


/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
void
swap(
    basic_simple_string<C, T, A>& lhs
,   basic_simple_string<C, T, A>& rhs
)
{
    lhs.swap(rhs);
}


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// implementation

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */
ss_typename_type_ret_k basic_simple_string<C, T, A>::string_buffer*
basic_simple_string<C, T, A>::alloc_buffer_(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cchCopy
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cchReserve
)
{
    if (0 == cchCopy &&
        0 == cchReserve)
    {
        return class_type::empty_buffer_();
    }
    else
    {
        size_type const         cb_members  =   0
                                            +   (STLSOFT_RAW_OFFSETOF(string_buffer, contents)
                                            +   (sizeof(char_type) - 1)) / sizeof(char_type)
                                            ;
        size_type               capacity    =   0
                                            +   cb_members
                                            +   maximum(cchCopy, cchReserve)
                                            +   1
                                            ;

        capacity = (alloc_quantum + capacity) & ~alloc_quantum; // round up to (alloc_quantum + 1)

        byte_ator_type          byte_ator;
# ifdef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
        void* const             raw_buffer  =   byte_ator.allocate(capacity * sizeof(char_type), ss_nullptr_k);
# else /* ? STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
        void* const             raw_buffer  =   byte_ator.allocate(capacity * sizeof(char_type));
# endif /* STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
        string_buffer* const    buffer      =   sap_cast<string_buffer*>(raw_buffer);

#ifndef STLSOFT_CF_THROW_BAD_ALLOC
# error Not compatible with translators that do not support bad_alloc
#endif

        traits_type::copy(buffer->contents, s, cchCopy);

        buffer->contents[cchCopy]   =   traits_type::to_char_type(0);
        buffer->length              =   cchCopy;
        buffer->capacity            =   capacity - cb_members;

        return buffer;
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */
ss_typename_type_ret_k basic_simple_string<C, T, A>::string_buffer*
basic_simple_string<C, T, A>::alloc_buffer_(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
)
{
    if (ss_nullptr_k == s ||
        '\0' == *s)
    {
        return class_type::empty_buffer_();
    }
    else
    {
        size_type len = traits_type::length(s);

        return class_type::alloc_buffer_(s, len, 0);
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */
ss_typename_type_ret_k basic_simple_string<C, T, A>::string_buffer*
basic_simple_string<C, T, A>::alloc_buffer_(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
)
{
    size_type const rhs_len = rhs.m_buffer->length;

    if (pos > rhs_len)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string::alloc_buffer_()` index out of range"));
    }

    return class_type::alloc_buffer_(rhs.m_buffer->contents + pos, rhs_len - pos, 0);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */
ss_typename_type_ret_k basic_simple_string<C, T, A>::string_buffer*
basic_simple_string<C, T, A>::alloc_buffer_(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
)
{
    size_type const rhs_len = rhs.m_buffer->length;

    if (pos > rhs_len)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string::alloc_buffer_()` index out of range"));
    }

    if (cch + pos > rhs_len)
    {
        cch = rhs_len - pos;
    }

    return class_type::alloc_buffer_(rhs.m_buffer->contents + pos, cch, 0);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */
ss_typename_type_ret_k basic_simple_string<C, T, A>::string_buffer*
basic_simple_string<C, T, A>::copy_buffer_(
    ss_typename_type_k basic_simple_string<C, T, A>::string_buffer* buffer
)
{
    STLSOFT_ASSERT(ss_nullptr_k != buffer);

    byte_ator_type          byte_ator;
    ss_size_t const         cb          =   buffer->capacity * sizeof(char_type) + STLSOFT_RAW_OFFSETOF(string_buffer, contents);
# ifdef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
    void* const             raw_buffer  =   byte_ator.allocate(cb, ss_nullptr_k);
# else /* ? STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
    void* const             raw_buffer  =   byte_ator.allocate(cb);
# endif /* STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
    string_buffer* const    new_buffer  =   sap_cast<string_buffer*>(raw_buffer);

    if (ss_nullptr_k != new_buffer)
    {
        STLSOFT_API_INTERNAL_memfns_memcpy(new_buffer, buffer, cb);
    }

    return new_buffer;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */
void
basic_simple_string<C, T, A>::destroy_buffer_(
    ss_typename_type_k basic_simple_string<C, T, A>::string_buffer* buffer
) STLSOFT_NOEXCEPT
{
    if (0 != buffer->capacity)
    {
        byte_ator_type byte_ator;

        byte_ator.deallocate(sap_cast<ss_byte_t*>(buffer), 0);
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::pointer
basic_simple_string<C, T, A>::begin_() STLSOFT_NOEXCEPT
{
    return m_buffer->contents;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::pointer
basic_simple_string<C, T, A>::end_() STLSOFT_NOEXCEPT
{
    return begin_() + length();
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::is_valid() const STLSOFT_NOEXCEPT
{
    if (0 != m_buffer->capacity &&
        m_buffer->capacity < 4)
    {
        return false;
    }
    else if (m_buffer->capacity < m_buffer->length)
    {
        return false;
    }
    else
    {
        size_type const len = traits_type::length(m_buffer->contents);

        if (m_buffer->length < len)
        {
            return false;
        }
    }

    return true;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */
ss_typename_type_ret_k basic_simple_string<C, T, A>::string_buffer*
basic_simple_string<C, T, A>::empty_buffer_() STLSOFT_NOEXCEPT
{
    // This instance is initialised to 0, which includes its capacity, that
    // value used throughout the class implementation as a sentinel
    static string_buffer s_empty = { 0, 0, { 0 } };

    return &s_empty;
}

// construction

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>::basic_simple_string() STLSOFT_NOEXCEPT
    : m_buffer(class_type::empty_buffer_())
{
    STLSOFT_ASSERT(is_valid());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>::basic_simple_string(class_type const& rhs)
    : m_buffer(copy_buffer_(rhs.m_buffer))
{
    STLSOFT_ASSERT(rhs.is_valid());
    STLSOFT_ASSERT(is_valid());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>::basic_simple_string(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
)
    : m_buffer(class_type::alloc_buffer_(rhs, pos))
{

    STLSOFT_ASSERT(is_valid());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>::basic_simple_string(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
)
    : m_buffer(class_type::alloc_buffer_(rhs, pos, cch))
{
    STLSOFT_ASSERT(is_valid());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>::basic_simple_string(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
)
    : m_buffer(class_type::alloc_buffer_(s))
{
    STLSOFT_ASSERT(is_valid());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>::basic_simple_string(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
)
    : m_buffer(class_type::alloc_buffer_(s, cch, 0))
{
    STLSOFT_ASSERT(is_valid());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>::basic_simple_string(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type  cch
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type  ch
)
    : m_buffer(class_type::empty_buffer_())
{
    STLSOFT_ASSERT(is_valid());

    assign(cch, ch);
}

#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>::basic_simple_string(class_type&& rhs) STLSOFT_NOEXCEPT
    : m_buffer(class_type::empty_buffer_())
{
    std_swap(m_buffer, rhs.m_buffer);
}
#endif /* STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_simple_string<C, T, A>::~basic_simple_string() STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    class_type::destroy_buffer_(m_buffer);
}

// comparison

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */
ss_sint_t
basic_simple_string<C, T, A>::compare_(
    ss_typename_type_k basic_simple_string<C, T, A>::value_type const*  lhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          lhs_len
,   ss_typename_type_k basic_simple_string<C, T, A>::value_type const*  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          rhs_len
) STLSOFT_NOEXCEPT
{
    size_type   cmp_len =   (lhs_len < rhs_len) ? lhs_len : rhs_len;
    ss_int_t    result  =   traits_type::compare(lhs, rhs, cmp_len);

    if (0 == result)
    {
        result = static_cast<ss_int_t>(lhs_len) - static_cast<ss_int_t>(rhs_len);
    }

    return result;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_sint_t
basic_simple_string<C, T, A>::compare(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
,   ss_typename_type_k basic_simple_string<C, T, A>::value_type const*  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cchRhs
) const
{
    size_type lhs_len = m_buffer->length;

    if (pos > lhs_len)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#compare()` index out of range"));
    }

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

    size_type rhs_len = (ss_nullptr_k == rhs) ? 0 : traits_type::length(rhs);

    if (cchRhs < rhs_len)
    {
        rhs_len = cchRhs;
    }

    return class_type::compare_(m_buffer->contents + pos, lhs_len, rhs, rhs_len);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_sint_t
basic_simple_string<C, T, A>::compare(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
,   ss_typename_type_k basic_simple_string<C, T, A>::value_type const*  rhs
) const
{
    size_type lhs_len = m_buffer->length;

    if (pos > lhs_len)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#compare()` index out of range"));
    }

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

    size_type rhs_len = (ss_nullptr_k == rhs) ? 0 : traits_type::length(rhs);

    return class_type::compare_(m_buffer->contents + pos, lhs_len, rhs, rhs_len);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_sint_t
basic_simple_string<C, T, A>::compare(
    ss_typename_type_k basic_simple_string<C, T, A>::value_type const*  s
) const STLSOFT_NOEXCEPT
{
    if (ss_nullptr_k == s ||
        '\0' == *s)
    {
        return empty();
    }
    else
    {
        return class_type::compare_(m_buffer->contents, m_buffer->length, s, traits_type::length(s));
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_sint_t
basic_simple_string<C, T, A>::compare(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
,   ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          posRhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cchRhs
) const
{
    size_type lhs_len = m_buffer->length;

    if (pos > lhs_len)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#compare()` index out of range"));
    }

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

    size_type rhs_len = rhs.m_buffer->length;

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

    return class_type::compare_(
        m_buffer->contents + pos, lhs_len
    ,   rhs.m_buffer->contents + posRhs, rhs_len
    );
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_sint_t
basic_simple_string<C, T, A>::compare(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
,   ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
) const
{
    if (pos > m_buffer->length)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#compare()` index out of range"));
    }

    size_type lhs_len = size();

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

    size_type rhs_len = rhs.m_buffer->length;

    return class_type::compare_(
        m_buffer->contents + pos, lhs_len
    ,   rhs.m_buffer->contents, rhs_len
    );
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_sint_t
basic_simple_string<C, T, A>::compare(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const& rhs
) const STLSOFT_NOEXCEPT
{
    // TODO: when performance has been proven, replace these dereferences with method calls (`data()`, `size()`)

    return class_type::compare_(
        m_buffer->contents, m_buffer->length
    ,   rhs.m_buffer->contents, rhs.m_buffer->length
    );
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
/* static */
ss_bool_t
basic_simple_string<C, T, A>::equal_(
    ss_typename_type_k basic_simple_string<C, T, A>::value_type const*  lhs
,   ss_typename_type_k basic_simple_string<C, T, A>::value_type const*  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          len
) STLSOFT_NOEXCEPT
{
    return 0 == traits_type::compare(lhs, rhs, len);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::equal(
    size_type           pos
,   size_type           cch
,   value_type const*   s
,   size_type           cchRhs
) const
{
    STLSOFT_ASSERT(0 == cchRhs || ss_nullptr_k != s);

    if (pos > m_buffer->length)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#equal()` index out of range"));
    }

    size_type const lhs_n   =   minimum(m_buffer->length - pos, cch);
    size_type const rhs_n   =   cchRhs;

    if (lhs_n != rhs_n)
    {
        return false;
    }
    else
    {
        return 0 == traits_type::compare(m_buffer->contents + pos, s, lhs_n);
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::equal(
    size_type           pos
,   size_type           cch
,   value_type const*   s
) const
{
    if (pos > m_buffer->length)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#equal()` index out of range"));
    }

    size_type const lhs_n   =   minimum(m_buffer->length - pos, cch);
    size_type const rhs_n   =   (ss_nullptr_k == s) ? 0 : traits_type::length(s);

    if (rhs_n != lhs_n)
    {
        return false;
    }
    else
    {
        return 0 == traits_type::compare(m_buffer->contents + pos, s, lhs_n);
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::equal(
    ss_typename_type_k basic_simple_string<C, T, A>::value_type const* s
) const STLSOFT_NOEXCEPT
{
    if (ss_nullptr_k == s)
    {
        return empty();
    }
    else
    {
        size_type const rhs_len = traits_type::length(s);

        if (m_buffer->length != rhs_len)
        {
            return false;
        }
        else
        {
            return 0 == traits_type::compare(m_buffer->contents, s, m_buffer->length);
        }
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::equal(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
,   ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          posRhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cchRhs
) const
{
    if (pos > m_buffer->length)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#equal()` index out of range"));
    }

    if (posRhs > rhs.m_buffer->length)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#equal()` index out of range"));
    }

    char_type const* const      lhs_ptr     =   m_buffer->contents + pos;
    size_type const             lhs_n       =   minimum(m_buffer->length - pos, cch);

    char_type const* const      rhs_ptr     =   rhs.m_buffer->contents + posRhs;
    size_type const             rhs_n       =   minimum(rhs.m_buffer->length - posRhs, cchRhs);

    if (lhs_n != rhs_n)
    {
        return false;
    }
    else
    {
        return 0 == traits_type::compare(lhs_ptr, rhs_ptr, lhs_n);
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::equal(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
,   ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
) const
{
    if (pos > m_buffer->length)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#equal()` index out of range"));
    }

    char_type const* const      lhs_ptr     =   m_buffer->contents + pos;
    size_type const             lhs_n       =   minimum(m_buffer->length - pos, cch);

    if (lhs_n != rhs.m_buffer->length)
    {
        return false;
    }
    else
    {
        return 0 == traits_type::compare(lhs_ptr, rhs.m_buffer->contents, rhs.m_buffer->length);
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::equal(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const& rhs
) const STLSOFT_NOEXCEPT
{
    string_buffer const* const  lhs_buffer  =   m_buffer;
    string_buffer const* const  rhs_buffer  =   rhs.m_buffer;

    if (lhs_buffer->length != rhs_buffer->length)
    {
        return false;
    }
    else
    {
        return 0 == traits_type::compare(lhs_buffer->contents, rhs_buffer->contents, lhs_buffer->length);
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::starts_with_(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          n
) const STLSOFT_NOEXCEPT
{
    if (m_buffer->length < n)
    {
        return false;
    }
    else
    {
        return class_type::equal_(
            m_buffer->contents
        ,   s
        ,   n
        );
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::ends_with_(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          n
) const STLSOFT_NOEXCEPT
{
    if (m_buffer->length < n)
    {
        return false;
    }
    else
    {
        return class_type::equal_(
            m_buffer->contents + (m_buffer->length - n)
        ,   s
        ,   n
        );
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::contains(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
) const STLSOFT_NOEXCEPT
{
    if (rhs.empty())
    {
        return true;
    }

    if (rhs.m_buffer->length > m_buffer->length)
    {
        return false;
    }

    return ss_nullptr_k != traits_type::find_string(m_buffer->contents, m_buffer->length, rhs.m_buffer->contents);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::contains(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const* s
) const STLSOFT_NOEXCEPT
{
    if (ss_nullptr_k == s ||
        '\0' == *s)
    {
        return true;
    }

    return ss_nullptr_k != traits_type::find_string(m_buffer->contents, m_buffer->length, s);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::contains(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type  ch
) const STLSOFT_NOEXCEPT
{
    if (empty())
    {
        return false;
    }

    return ss_nullptr_k != traits_type::find(data(), length(), ch);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::starts_with(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
) const STLSOFT_NOEXCEPT
{
    return starts_with_(rhs.m_buffer->contents, rhs.m_buffer->length);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::starts_with(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
) const STLSOFT_NOEXCEPT
{
    if (ss_nullptr_k == s ||
        '\0' == *s)
    {
        return true;
    }

    return class_type::starts_with_(s, traits_type::length(s));
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::starts_with(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type  ch
) const STLSOFT_NOEXCEPT
{
    return empty() ? false : (front() == ch);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::ends_with(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  s
) const STLSOFT_NOEXCEPT
{
    return class_type::ends_with_(s.data(), s.size());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::ends_with(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
) const STLSOFT_NOEXCEPT
{
    if (ss_nullptr_k == s ||
        '\0' == *s)
    {
        return true;
    }

    return class_type::ends_with_(s, traits_type::length(s));
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::ends_with(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type  ch
) const STLSOFT_NOEXCEPT
{
    return empty() ? false : (back() == ch);
}

// accessors

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::reference
basic_simple_string<C, T, A>::operator [](ss_typename_type_k basic_simple_string<C, T, A>::size_type index) STLSOFT_NOEXCEPT
{
    STLSOFT_MESSAGE_ASSERT("index access out of range in simple_string", index < size());

    STLSOFT_ASSERT(is_valid());

    return m_buffer->contents[index];
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::const_reference
basic_simple_string<C, T, A>::operator [](ss_typename_type_k basic_simple_string<C, T, A>::size_type index) const STLSOFT_NOEXCEPT
{
    STLSOFT_MESSAGE_ASSERT("index access out of range in simple_string", index < size() + 1); // Valid to return (const) reference to nul-terminator

    STLSOFT_ASSERT(is_valid());

    return m_buffer->contents[index];
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::reference
basic_simple_string<C, T, A>::at(ss_typename_type_k basic_simple_string<C, T, A>::size_type index)
{
    STLSOFT_ASSERT(is_valid());

    if (index >= size())
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("index out of range"));
    }

    STLSOFT_ASSERT(is_valid());

    return m_buffer->contents[index];
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::const_reference
basic_simple_string<C, T, A>::at(ss_typename_type_k basic_simple_string<C, T, A>::size_type index) const
{
    STLSOFT_ASSERT(is_valid());

    if (index >= size())
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("index out of range"));
    }

    STLSOFT_ASSERT(is_valid());

    return m_buffer->contents[index];
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type
basic_simple_string<C, T, A>::substr(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type  pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type  cch
) const
{
    STLSOFT_ASSERT(is_valid());

    size_type const len = m_buffer->length;

    if (pos > len)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("index out of range"));
    }

    STLSOFT_ASSERT(is_valid());

    if (cch > (len - pos))
    {
        cch = len - pos;
    }

    return class_type(m_buffer->contents + pos, cch);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type
basic_simple_string<C, T, A>::substr(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type pos
) const
{
    STLSOFT_ASSERT(is_valid());

    size_type const len = m_buffer->length;

    if (pos > len)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("index out of range"));
    }

    STLSOFT_ASSERT(is_valid());

    return class_type(m_buffer->contents + pos, len - pos);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type
basic_simple_string<C, T, A>::substr() const
{
    return *this;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::value_type const*
basic_simple_string<C, T, A>::c_str() const STLSOFT_NOEXCEPT
{
    return m_buffer->contents;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::value_type const*
basic_simple_string<C, T, A>::data() const STLSOFT_NOEXCEPT
{
    return m_buffer->contents;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::reference
basic_simple_string<C, T, A>::front() STLSOFT_NOEXCEPT
{
    return (*this)[0];
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::reference
basic_simple_string<C, T, A>::back() STLSOFT_NOEXCEPT
{
    return (*this)[size() - 1];
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::const_reference
basic_simple_string<C, T, A>::front() const STLSOFT_NOEXCEPT
{
    return (*this)[0];
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::const_reference
basic_simple_string<C, T, A>::back() const STLSOFT_NOEXCEPT
{
    return (*this)[size() - 1];
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::size_type
basic_simple_string<C, T, A>::copy(
    ss_typename_type_k basic_simple_string<C, T, A>::value_type*    dest
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type      cch
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type      pos /* = 0 */
) const STLSOFT_NOEXCEPT
{
    size_type const len = m_buffer->length;

    if (pos < len)
    {
        if (len < pos + cch)
        {
            cch = len - pos;
        }

        traits_type::copy(dest, m_buffer->contents + pos, cch);
    }
    else
    {
        cch = 0;
    }

    return cch;
}

// iteration

#ifndef STLSOFT_SIMPLE_STRING_ITERATOR_METHODS_INLINE

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::const_iterator
basic_simple_string<C, T, A>::begin() const STLSOFT_NOEXCEPT
{
    return const_cast<class_type*>(this)->begin_();
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::const_iterator
basic_simple_string<C, T, A>::end() const STLSOFT_NOEXCEPT
{
    return const_cast<class_type*>(this)->end_();
}
#endif /* !STLSOFT_SIMPLE_STRING_ITERATOR_METHODS_INLINE */

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::iterator
basic_simple_string<C, T, A>::begin() STLSOFT_NOEXCEPT
{
    return begin_();
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::iterator
basic_simple_string<C, T, A>::end() STLSOFT_NOEXCEPT
{
    return end_();
}

#ifdef STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::const_reverse_iterator
basic_simple_string<C, T, A>::rbegin() const STLSOFT_NOEXCEPT
{
    return const_reverse_iterator(end());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::const_reverse_iterator
basic_simple_string<C, T, A>::rend() const STLSOFT_NOEXCEPT
{
    return const_reverse_iterator(begin());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::reverse_iterator
basic_simple_string<C, T, A>::rbegin() STLSOFT_NOEXCEPT
{
    return reverse_iterator(end());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::reverse_iterator
basic_simple_string<C, T, A>::rend() STLSOFT_NOEXCEPT
{
    return reverse_iterator(begin());
}
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

// assignment

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::assign(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
)
{
    STLSOFT_ASSERT(is_valid());

    if (ss_nullptr_k == s)
    {
        class_type::destroy_buffer_(m_buffer);

        m_buffer = class_type::empty_buffer_();
    }
    else
    {
        // Here is an opportunity to optimise a bit. We will do more so in a
        // later release, but for the moment we will reuse our existing
        // buffer if its capacity is sufficient for our purposes

        // If:
        //
        // - the required size fits, AND
        // - the source string is not within the existing buffer

        if (cch < m_buffer->capacity &&
            (   s < &m_buffer->contents[0] ||
                s > &m_buffer->contents[cch]))
        {
            traits_type::copy(m_buffer->contents, s, cch);

            m_buffer->contents[cch] = 0;
            m_buffer->length = cch;
        }
        else
        {
            string_buffer* const new_buffer = class_type::alloc_buffer_(s, cch, 0);

            class_type::destroy_buffer_(m_buffer);

            m_buffer = new_buffer;
        }
    }

    STLSOFT_ASSERT(is_valid());

    return *this;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::assign(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
)
{
    return assign(s, (ss_nullptr_k == s) ? 0 : traits_type::length(s));
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::assign(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
)
{
    if (pos > rhs.m_buffer->length)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#assign()` index out of range"));
    }

    char_type const*    s   =   rhs.m_buffer->contents;
    size_type           len =   rhs.m_buffer->length;

    if (len - pos < cch)
    {
        cch = len - pos;
    }

    return assign(s + pos, cch);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::assign(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
)
{
    return assign(rhs.m_buffer->contents, rhs.m_buffer->length);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::assign(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type  cch
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type  ch
)
{
    buffer_type_ buffer(cch);

    static_cast<void>(STLSOFT_NS_QUAL_STD(fill)(buffer.begin(), buffer.end(), ch));

    return assign(buffer.data(), buffer.size());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type const&
basic_simple_string<C, T, A>::operator =(ss_typename_type_k basic_simple_string<C, T, A>::class_type const& rhs)
{
    return assign(rhs);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type const&
basic_simple_string<C, T, A>::operator =(ss_typename_type_k basic_simple_string<C, T, A>::char_type const* s)
{
    return assign(s);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type const&
basic_simple_string<C, T, A>::operator =(ss_typename_type_k basic_simple_string<C, T, A>::char_type ch)
{
    char_type   sz[2] = { ch, traits_type::to_char_type(0) };

    return assign(sz);
}


// appending

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::append(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
)
{
    STLSOFT_ASSERT(is_valid());

    if (empty())
    {
        assign(s, cch);
    }
    else
    {
        if (ss_nullptr_k == s ||
            0 == cch)
        {
            // Nothing to do
        }
        else
        {
            string_buffer*  old_buffer  =   ss_nullptr_k;
            size_type const buf_len     =   m_buffer->length;

            if (m_buffer->capacity - buf_len < 1 + cch)
            {
                // allocate a new buffer of sufficient size
                //
                // NOTE: need to call 3-parameter overload as specifying 2-arguments results in call to 1-parameter overload!!
                string_buffer* const new_buffer = class_type::alloc_buffer_(m_buffer->contents, buf_len + cch, 0);

                if (ss_nullptr_k == new_buffer) // some allocators do not throw on failure!
                {
                    cch = 0;
                }
                else
                {
                    old_buffer = m_buffer;    // mark for destruction, but hold around in case appending from self
                    m_buffer = new_buffer;
                }
            }
            else
            {
                m_buffer->length += cch;
            }

            traits_type::copy(m_buffer->contents + buf_len, s, cch);
            m_buffer->contents[m_buffer->length] = traits_type::to_char_type(0);

            if (ss_nullptr_k != old_buffer)
            {
                class_type::destroy_buffer_(old_buffer);
            }
        }
    }

    STLSOFT_ASSERT(is_valid());

    return *this;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::append(
    ss_typename_type_k basic_simple_string<C, T, A>::char_type const*   s
)
{
    if (ss_nullptr_k == s ||
        '\0' == *s)
    {
        return *this;
    }

    return append(s, traits_type::length(s));
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::append(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const&  rhs
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          pos
,   ss_typename_type_k basic_simple_string<C, T, A>::size_type          cch
)
{
    size_type const rhs_len = rhs.m_buffer->length;

    if (pos > rhs_len)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`basic_simple_string#append()` index out of range"));
    }

    char_type const* s = rhs.m_buffer->contents;

    if (rhs_len - pos < cch)
    {
        cch = rhs_len - pos;
    }

    s += pos;

    return append(s, cch);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::append(
    ss_typename_type_k basic_simple_string<C, T, A>::class_type const& str
)
{
    return append(str.m_buffer->contents, str.m_buffer->length);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::append(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type  cch
,   ss_typename_type_k basic_simple_string<C, T, A>::char_type  ch
)
{
    if (empty())
    {
        assign(cch, ch);
    }
    else
    {
        buffer_type_ buffer(cch);

        static_cast<void>(STLSOFT_NS_QUAL_STD(fill)(buffer.begin(), buffer.end(), ch));

        append(buffer.data(), buffer.size());
    }

    return *this;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::operator +=(ss_typename_type_k basic_simple_string<C, T, A>::char_type ch)
{
    return append(1, ch);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::operator +=(ss_typename_type_k basic_simple_string<C, T, A>::char_type const* s)
{
    return append(s);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::class_type&
basic_simple_string<C, T, A>::operator +=(ss_typename_type_k basic_simple_string<C, T, A>::class_type const& rhs)
{
    return append(rhs);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
void
basic_simple_string<C, T, A>::push_back(ss_typename_type_k basic_simple_string<C, T, A>::char_type ch)
{
    append(1, ch);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
void
basic_simple_string<C, T, A>::pop_back() STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    if (!empty())
    {
        m_buffer->contents[--m_buffer->length] = '\0';
    }
}

// modifiers

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
void
basic_simple_string<C, T, A>::reserve(ss_typename_type_k basic_simple_string<C, T, A>::size_type cch)
{
    if (size() < cch)
    {
        if (cch <= m_buffer->capacity)
        {
            ; // nothing to do
        }
        else
        {
            // allocate a new buffer of sufficient size
            string_buffer* const new_buffer = class_type::alloc_buffer_(data(), size(), cch);

            class_type::destroy_buffer_(m_buffer);

            if (ss_nullptr_k == new_buffer) // some allocators do not throw on failure!
            {
                m_buffer = class_type::empty_buffer_();
            }
            else
            {
                m_buffer = new_buffer;
            }
        }
    }
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
void
basic_simple_string<C, T, A>::swap(ss_typename_type_k basic_simple_string<C, T, A>::class_type& other) STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());
    STLSOFT_ASSERT(other.is_valid());

    std_swap(m_buffer, other.m_buffer);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
void
basic_simple_string<C, T, A>::resize(
    ss_typename_type_k basic_simple_string<C, T, A>::size_type  cch
,   ss_typename_type_k basic_simple_string<C, T, A>::value_type ch
)
{
    STLSOFT_ASSERT(is_valid());

    size_type const len = size();

    if (len < cch)
    {
        append(cch - len, ch);
    }
    else
    if (cch < len)
    {
        m_buffer->length        =   cch;
        m_buffer->contents[cch] =   traits_type::to_char_type(0);
    }

    STLSOFT_ASSERT(is_valid());
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
void
basic_simple_string<C, T, A>::clear() STLSOFT_NOEXCEPT
{
    if (0 != m_buffer->capacity)
    {
        m_buffer->length      =   0;
        m_buffer->contents[0] =   traits_type::to_char_type(0);
    }
}

// attributes

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::size_type
basic_simple_string<C, T, A>::size() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return m_buffer->length;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::size_type
basic_simple_string<C, T, A>::max_size() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return static_cast<size_type>(-1) / sizeof(char_type);
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::size_type
basic_simple_string<C, T, A>::length() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return size();
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_simple_string<C, T, A>::size_type
basic_simple_string<C, T, A>::capacity() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return m_buffer->capacity;
}

template <
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_bool_t
basic_simple_string<C, T, A>::empty() const STLSOFT_NOEXCEPT
{
    STLSOFT_ASSERT(is_valid());

    return 0 == size();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
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
    template <
        ss_typename_param_k C
    ,   ss_typename_param_k T
    ,   ss_typename_param_k A
    >
    inline
    void
    swap(
        STLSOFT_NS_QUAL(basic_simple_string)<C, T, A>&  lhs
    ,   STLSOFT_NS_QUAL(basic_simple_string)<C, T, A>&  rhs
    )
    {
        lhs.swap(rhs);
    }
} /* namespace std */
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

