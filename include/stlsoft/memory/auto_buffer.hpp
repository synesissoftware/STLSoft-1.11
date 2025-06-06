/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/memory/auto_buffer.hpp (originally MTLocBfr.h, ::SynesisStl)
 *
 * Purpose: Contains the auto_buffer template class.
 *
 * Created: 19th January 2002
 * Updated: 31st May 2025
 *
 * Thanks:  To Magnificent Imbecil for pointing out error in documentation,
 *          and for suggesting swap() optimisation. To Thorsten Ottosen for
 *          pointing out that allocators were not swapped.
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


/** \file stlsoft/memory/auto_buffer.hpp
 *
 * \brief [C++] Definition of the stlsoft::auto_buffer class template
 *   (\ref group__library__Memory "Memory" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
#define STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_AUTO_BUFFER_MAJOR       5
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_AUTO_BUFFER_MINOR       9
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_AUTO_BUFFER_REVISION    0
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_AUTO_BUFFER_EDIT        232
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

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_FEATURES
# include <stlsoft/memory/util/allocator_features.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_FEATURES */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_BOUNDED
# include <stlsoft/algorithms/bounded.hpp>  // for stlsoft::copy_n()
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_BOUNDED */
#ifndef STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD
# include <stlsoft/algorithms/pod.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ALGORITHMS_POD */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */
#ifdef _STLSOFT_AUTO_BUFFER_ALLOW_UDT
# define _STLSOFT_AUTO_BUFFER_ALLOW_NON_POD
# ifdef STLSOFT_PPF_pragma_message_SUPPORT
#  pragma message("_STLSOFT_AUTO_BUFFER_ALLOW_UDT is deprecated. Use _STLSOFT_AUTO_BUFFER_ALLOW_NON_POD instead")
# endif /* STLSOFT_PPF_pragma_message_SUPPORT */
#endif /* _STLSOFT_AUTO_BUFFER_ALLOW_UDT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef _STLSOFT_AUTO_BUFFER_ALLOW_NON_POD
# ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_CONSTRAINTS
#  include <stlsoft/util/constraints.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_CONSTRAINTS */
#endif /* _STLSOFT_AUTO_BUFFER_ALLOW_NON_POD */

#if __cplusplus >= 202002L
# ifndef STLSOFT_INCL_TYPE_TRAITS
#  define STLSOFT_INCL_TYPE_TRAITS
#  include <type_traits>
# endif /* !STLSOFT_INCL_TYPE_TRAITS */
#endif
#ifndef STLSOFT_INCL_UTILITY
# define STLSOFT_INCL_UTILITY
# include <utility>
#endif /* !STLSOFT_INCL_UTILITY */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if defined(_MSC_VER) &&\
    _MSC_VER >= 1935

# pragma warning(push)
# pragma warning(disable : 26495)
#endif


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

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
     !defined(STLSOFT_COMPILER_IS_DMC)

struct auto_buffer_internal_default
{
    enum { min_value        =   32      };
    enum { max_value        =   256     };
    enum { division_factor  =   2       };
};

template <
    ss_typename_param_k T
>
struct auto_buffer_internal_size_calculator
    : private auto_buffer_internal_default
{
private:
    enum
    {
            min_value        =   auto_buffer_internal_default::min_value
        ,   max_value        =   auto_buffer_internal_default::max_value
        ,   division_factor  =   auto_buffer_internal_default::division_factor
        ,   divided_value_   =   static_cast<int>((int(division_factor) * int(max_value)) / sizeof(T))
        ,   divided_value    =   (max_value < divided_value_)
                                    ?   max_value
                                    :   divided_value_
    };
public:
    enum {  value            =   1 == sizeof(T)
                                    ?   max_value
                                    :   divided_value < min_value
                                        ?   min_value
                                        :   divided_value           };
};

STLSOFT_TEMPLATE_SPECIALISATION
struct auto_buffer_internal_size_calculator<ss_char_a_t>
{
    enum { value    =   auto_buffer_internal_default::max_value     };
};
#  if defined(STLSOFT_CF_NATIVE_WCHAR_T_SUPPORT) || \
      defined(STLSOFT_CF_TYPEDEF_WCHAR_T_SUPPORT)
STLSOFT_TEMPLATE_SPECIALISATION
struct auto_buffer_internal_size_calculator<ss_char_w_t>
{
    enum { value    =   auto_buffer_internal_default::max_value     };
};
#  endif /* STLSOFT_CF_NATIVE_WCHAR_T_SUPPORT */
# endif /* compiler */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// class auto_buffer
//
/** This class template provides an efficient variable automatic buffer (as
 * documented in the article
 * "Efficient Variable Automatic Buffers", Matthew Wilson, C/C++ User's Journal, Volume 21 Number 12, December 2003
 * and the book
 * "Imperfect C++", Matthew Wilson, Addison-Wesley, 2004
 * ).
 *
 * \ingroup group__library__Memory
 *
 * \tparam T_value The type of the elements in the array
 * \tparam V_space The number of elements in the array. For translators that
 *   support default template arguments, this is defaulted to <b>256</b>
 * \tparam T_allocator The allocator type. Defaults to
 *   \link stlsoft::allocator_selector allocator_selector<T_value>::allocator_type\endlink
 *   for translators that support default template arguments.
 *
 * This class provides an efficient replacement for dynamic memory block
 * allocation when the block size generally falls under a predictable limit.
 * In such cases, significant performance benefits can be achieved by using
 * an instance of a specialisation of auto_buffer, whose size parameter
 * V_space is set to a level to cater for most of the requested sizes. Only
 * where the size of the buffer needs to be larger than this limit does an
 * allocation occur from the heap/free-store via the given allocator.
 *
 * Using <code>auto_buffer</code> means one can avoid use of heap memory in
 * circumstances where stack memory is unsuitable, i.e. where there is no
 * maximum size to a memory requirement, or the maximum size is potentially
 * very large (and considerably larger than the median size). Consider the
 * following code extract from the core of the
 * <a href = "http://pantheios.org/">Pantheios</a> logging library:
\code
int pantheios_log_n(
    pan_sev_t           severity
,   size_t              numSlices
,   pan_slice_t const*  slices
)
{
    typedef stlsoft::auto_buffer<char, 2048> buffer_t;

    // Calculate the total size of the log statement, by summation of the slice array
    size_t const    n = std::accumulate(
                            stlsoft::member_selector(slices, &pan_slice_t::len)
                        ,   stlsoft::member_selector(slices + numSlices, &pan_slice_t::len)
                        ,   size_t(0)
                        );
    buffer_t        buffer(1 + n);

    . . .
\endcode
 *
 * This use of auto_buffer illustrates two important features:
 * - there is no (compile-time) limit on the maximum size of a log statement
 * - memory is only allocated from the heap in the case where the total statement length >= 2047 bytes.
 *
 * Without auto_buffer, we would have three choices, all bad:
 *
 * 1. We could go to the heap in all cases:
\code
int pantheios_log_n(
    pan_sev_t           severity
,   size_t              numSlices
,   pan_slice_t const*  slices
)
{
    typedef stlsoft::vector<char> buffer_t;

    // Calculate the total size of the log statement, by summation of the slice array
    size_t const    n = std::accumulate(
                            stlsoft::member_selector(slices, &pan_slice_t::len)
                        ,   stlsoft::member_selector(slices + numSlices, &pan_slice_t::len)
                        ,   size_t(0)
                        );
    buffer_t        buffer(1 + n);

    . . .
\endcode
 * But this would have an unacceptable performance hit (since the vast
 * majority of log statements are less than 2K in extent).
 *
 * 2. We could use a stack buffer, and truncate any log statement exceeding
 *     the limit:
\code
int pantheios_log_n(  pan_sev_t           severity
                    ,  size_t              numSlices
                    ,  pan_slice_t const*  slices)
{
    // Calculate the total size of the log statement, by summation of the slice array
    size_t const    n = std::accumulate(
                            stlsoft::member_selector(slices, &pan_slice_t::len)
                        ,   stlsoft::member_selector(slices + numSlices, &pan_slice_t::len)
                        ,   size_t(0)
                        );
    char            buffer[2048];

    . . . // make sure to truncate the statement to a max 2047 characters
\endcode
 * But this would unnecessarily constrain users of the Pantheios logging
 * functionality.
 *
 * 3. Finally, we could synthesise the functionality of auto_buffer
 *     manually, as in:
\code
int pantheios_log_n(
    pan_sev_t           severity
,   size_t              numSlices
,   pan_slice_t const*  slices
)
{
    // Calculate the total size of the log statement, by summation of the slice array
    size_t const    n = std::accumulate(
                            stlsoft::member_selector(slices, &pan_slice_t::len)
                        ,   stlsoft::member_selector(slices + numSlices, &pan_slice_t::len)
                        ,   size_t(0)
                        );
    char            buff[2048];
    char* const     buffer = (n < 2048) ? &buff[0] : new char[1 + n];

    . . .

    if (buffer != &buff[0])
    {
        delete [] buffer;
    }

    . . .
\endcode
 * But this is onerous manual fiddling, and exception-unsafe. What would be
 * the point, when auto_buffer already does this (safely) for us?
 *
 * As a consequence of its blending of the best features of stack and heap
 * memory, auto_buffer is an invaluable component in the implementation of
 * many components within the STLSoft libraries, and in several other
 * open-source projects, including:
 * <a href = "http://synesis.com.au/software/b64.html">b64</a>,
 * <a href = "http://openrj.org/">Open-RJ</a>,
 * <a href = "http://pantheios.org/">Pantheios</a>,
 * <a href = "http://recls.org/">recls</a>,
 * and
 * <a href = "http://shwild.org/">shwild</a>.
 *
 * \remarks auto_buffer works correctly whether the given allocator throws
 *   an exception on allocation failure, or returns \c nullptr. In the
 *   latter case, construction failure to allocate is reflected by the
 *   size() method returning 0.
 *
 * \remarks The design of auto_buffer is described in Chapter 32 of
 *   <a href = "http://imperfectcplusplus.com">Imperfect C++</a>, and its
 *   interface is discussed in detail in Section 16.2 of
 *   <a href = "http://extendedstl.com">Extended STL, volume 1</a>.
 *
 * \note With version 1.9 of STLSoft, the order of the space and allocator
 *   arguments were reversed. Further, the allocator default changed from
 *   stlsoft::new_allocator to <code>std::allocator</code> for translators
 *   that support the standard library. If you need the old characteristics,
 *   you can <code>\#define</code> the symbol
 *   <b>STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS</b>.
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
# define STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS
#endif /* compiler */


#if defined(STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS)

# ifdef STLSOFT_AUTO_BUFFER_NEW_FORM
#  undef STLSOFT_AUTO_BUFFER_NEW_FORM
# endif /* STLSOFT_AUTO_BUFFER_NEW_FORM */

 // //////////////////////////////////////////////
 // This is the pre-1.9 template parameter list

template <
    ss_typename_param_k T_value
# ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k T_allocator = ss_typename_type_def_k allocator_selector<T_value>::allocator_type
# else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T_allocator
# endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
# ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT
#  if defined(STLSOFT_COMPILER_IS_BORLAND)
,   ss_size_t           space       =   256
#  elif defined(STLSOFT_COMPILER_IS_DMC)
,   ss_size_t           V_space     =   256
#  else /* ? compiler */
,   ss_size_t           V_space     =   auto_buffer_internal_size_calculator<T_value>::value
#  endif /* compiler */
# else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
#  if !defined(STLSOFT_COMPILER_IS_BORLAND)
,   ss_size_t           V_space  /* =   auto_buffer_internal_size_calculator<T_value>::value */
#  else /* ? compiler */
,   ss_size_t           space    /* =   256 */
#  endif /* compiler */
# endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT */
>

 // End of pre-1.9 template parameter list
 // //////////////////////////////////////////////

#else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */

 // //////////////////////////////////////////////
 // This is the 1.9+ template parameter list

# ifndef STLSOFT_AUTO_BUFFER_NEW_FORM
#  define STLSOFT_AUTO_BUFFER_NEW_FORM
# endif /* !STLSOFT_AUTO_BUFFER_NEW_FORM */

template <
    ss_typename_param_k T_value
# ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT
#  if 0
#  elif defined(STLSOFT_COMPILER_IS_BORLAND)
,   ss_size_t           space       =   256
#  elif defined(STLSOFT_COMPILER_IS_DMC)
,   ss_size_t           V_space     =   256
#  else /* ? compiler */
,   ss_size_t           V_space     =   auto_buffer_internal_size_calculator<T_value>::value
#  endif /* compiler */
# else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT */
#  if !defined(STLSOFT_COMPILER_IS_BORLAND)
,   ss_size_t           V_space  /* =   auto_buffer_internal_size_calculator<T_value>::value */
#  else /* ? compiler */
,   ss_size_t           space    /* =   256 */
#  endif /* compiler */
# endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT */
# ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k T_allocator = ss_typename_type_def_k allocator_selector<T_value>::allocator_type
# else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T_allocator
# endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>

 // End of 1.9+ template parameter list
 // //////////////////////////////////////////////

#endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */

class auto_buffer
#if !defined(STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE)
    : protected T_allocator
    , public stl_collection_tag
#else /* ? STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE */
    : public stl_collection_tag
#endif /* !STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE */
{
public: // constants
#if !defined(STLSOFT_COMPILER_IS_BORLAND)
    enum
    {
        /// The number of items in the internal buffer
        space = int(V_space) // int() required for 64-bit compatibility
    };
#endif /* compiler */

public: // types
    /// The value type
    typedef T_value                                         value_type;
    /// The allocator type
    typedef T_allocator                                     allocator_type;
#ifdef STLSOFT_LF_ALLOCATOR_TRAITS_SUPPORT
    /// The allocator traits type
    typedef std::allocator_traits<allocator_type>           allocator_traits_type;
#endif /* STLSOFT_LF_ALLOCATOR_TRAITS_SUPPORT */
    /// The current specialisation of the type
#ifdef STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS
    typedef auto_buffer<
        T_value
    ,   T_allocator
    ,   space
    >                                                       class_type;
#else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
    typedef auto_buffer<
        T_value
    ,   space
    ,   T_allocator
    >                                                       class_type;
#endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
#ifdef STLSOFT_LF_ALLOCATOR_TRAITS_SUPPORT
    /// The reference type
    typedef ss_typename_type_k allocator_traits_type::value_type&
                                                            reference;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k allocator_traits_type::value_type const&
                                                            const_reference;
    /// The pointer type
    typedef ss_typename_type_k allocator_traits_type::pointer
                                                            pointer;
    /// The non-mutating (const) pointer type
    typedef ss_typename_type_k allocator_traits_type::const_pointer
                                                            const_pointer;
#else /* ? STLSOFT_LF_ALLOCATOR_TRAITS_SUPPORT */
    /// The reference type
    typedef ss_typename_type_k allocator_type::reference    reference;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k allocator_type::const_reference
                                                            const_reference;
    /// The pointer type
    typedef ss_typename_type_k allocator_type::pointer      pointer;
    /// The non-mutating (const) pointer type
    typedef ss_typename_type_k allocator_type::const_pointer
                                                            const_pointer;
#endif /* STLSOFT_LF_ALLOCATOR_TRAITS_SUPPORT */
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The difference type
    typedef ss_ptrdiff_t                                    difference_type;
#if !defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// The iterator type
    typedef value_type*                                     iterator;
    /// The non-mutating (const) iterator type
    typedef value_type const*                               const_iterator;
#else /* ? !STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
    /// The iterator type
    typedef
# if !defined(STLSOFT_COMPILER_IS_BORLAND)
      ss_typename_type_k
# endif /* compiler */
        pointer_iterator<
            value_type
        ,   pointer
        ,   reference
        >::type                                             iterator;
    /// The non-mutating (const) iterator type
    typedef
# if !defined(STLSOFT_COMPILER_IS_BORLAND)
      ss_typename_type_k
# endif /* compiler */
        pointer_iterator<
            value_type const
        ,   const_pointer
        ,   const_reference
        >::type                                             const_iterator;

    /// The mutating (non-const) reverse iterator type
    typedef reverse_iterator_base<
        iterator
    ,   value_type
    ,   reference
    ,   pointer
    ,   difference_type
    >                                                       reverse_iterator;

    /// The non-mutating (const) reverse iterator type
    typedef const_reverse_iterator_base<
        const_iterator
    ,   value_type const
    ,   const_reference
    ,   const_pointer
    ,   difference_type
    >                                                       const_reverse_iterator;
#endif /* !STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

private: // implementation
    pointer allocate_(size_type cItems, void const* hint)
    {
#ifdef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
# ifdef STLSOFT_CF_STD_LIBRARY_IS_SUNPRO_RW
        return static_cast<pointer>(get_allocator().allocate(cItems, const_cast<void*>(hint)));
# else /* ? STLSOFT_CF_STD_LIBRARY_IS_SUNPRO_RW */
        return get_allocator().allocate(cItems, hint);
# endif /* STLSOFT_CF_STD_LIBRARY_IS_SUNPRO_RW */
#else /* ? STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
        STLSOFT_SUPPRESS_UNUSED(hint);

        return get_allocator().allocate(cItems);
#endif /* STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
    }

    pointer allocate_(size_type cItems)
    {
        return allocate_(cItems, NULL);
    }

    void deallocate_(pointer p, size_type cItems)
    {
        STLSOFT_ASSERT(NULL != p);

#ifdef STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
        get_allocator().deallocate(p, cItems);
#else /* ? STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */
        STLSOFT_SUPPRESS_UNUSED(cItems);

        get_allocator().deallocate(p);
#endif /* STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */
    }

    pointer reallocate_(pointer p, size_type cItems, size_type cNewItems)
    {
        pointer new_p = allocate_(cNewItems, p);

        // This test is needed, since some allocators may not throw
        // bad_alloc
        if (NULL != new_p)
        {
            block_copy(new_p, p, cItems);

            deallocate_(p, cItems);
        }

        return new_p;
    }

protected:
    static void block_copy(pointer dest, const_pointer src, size_type cItems)
    {
        pod_copy_n(dest, src, cItems);
    }
    static void block_set(pointer dest, size_type cItems, const_reference value)
    {
        pod_fill_n(dest, cItems, value);
    }

private:
#ifdef STLSOFT_CF_THROW_BAD_ALLOC

    // Iterator: input
    template <ss_typename_param_k I2>
# if defined(STLSOFT_COMPILER_IS_MWERKS)
    // There seems to be a bug in CodeWarrior that makes it have a cow with iterator tags by value, so we just use a ptr
    void init_from_range_(I2 first, I2 last, STLSOFT_NS_QUAL_STD(input_iterator_tag) const*)
# else /* ? compiler */
    void init_from_range_(I2 first, I2 last, STLSOFT_NS_QUAL_STD(input_iterator_tag))
# endif /* compiler */
    {
        m_buffer    =   &m_internal[0];
        m_cItems    =   space;
        m_cExternal =   0;

        size_type n = 0;

        for (; first != last; ++first, ++n)
        {
            if (n == m_cItems)
            {
                // simple geometric expansion as best notion to avoid many
                // repeated reallocations in what is a sequence of unknown
                // length - rate (x4) is aggressive, but shown to give good
                // performance in tests
                size_type new_size = m_cItems * 4;

                if (0 != m_cExternal)
                {
                    // already in external, so need to reallocate

# ifndef STLSOFT_CF_THROW_BAD_ALLOC
#  error This code is not compatible with translation that does not support throwing bad_alloc
# endif
                    m_buffer = reallocate_(m_buffer, m_cItems, new_size);

                    m_cItems = new_size;
                }
                else
                {
                    // in internal, so need to allocate and transfer

                    pointer const new_buffer = allocate_(new_size);

                    block_copy(new_buffer, m_buffer, m_cItems);

                    m_buffer = new_buffer;

                    m_cItems = new_size;

                    m_cExternal = new_size;
                }
            }

            m_buffer[n] = *first;
        }

        if (m_cItems != n)
        {
            m_cItems = n;
        }
    }
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */

    // Iterator: forward
    template <ss_typename_param_k I2>
# if defined(STLSOFT_COMPILER_IS_MWERKS)
    // There seems to be a bug in CodeWarrior that makes it have a cow with iterator tags by value, so we just use a ptr
    void init_from_range_(I2 first, I2 last, STLSOFT_NS_QUAL_STD(forward_iterator_tag) const*)
# else /* ? compiler */
    void init_from_range_(I2 first, I2 last, STLSOFT_NS_QUAL_STD(forward_iterator_tag))
# endif /* compiler */
    {
        size_type const d = std::distance(first, last);

        if (d > space)
        {
            m_buffer = allocate_(d);

            m_cExternal = d;
        }
        else
        {
            m_buffer = const_cast<pointer>(&m_internal[0]);

            m_cExternal = 0;
        }
        m_cItems = d;

        copy_n(first, d, m_buffer);
    }

    // Iterator: random-access
    template <ss_typename_param_k I2>
# if defined(STLSOFT_COMPILER_IS_MWERKS)
    // There seems to be a bug in CodeWarrior that makes it have a cow with iterator tags by value, so we just use a ptr
    void init_from_range_(I2 first, I2 last, STLSOFT_NS_QUAL_STD(random_access_iterator_tag) const*)
# else /* ? compiler */
    void init_from_range_(I2 first, I2 last, STLSOFT_NS_QUAL_STD(random_access_iterator_tag))
# endif /* compiler */
    {
        STLSOFT_MESSAGE_ASSERT("invalid range", first <= last);

        size_type const d = static_cast<size_type>(std::distance(first, last));

        if (d > space)
        {
            m_buffer = allocate_(d);

            m_cExternal = d;
        }
        else
        {
            m_buffer = const_cast<pointer>(&m_internal[0]);

            m_cExternal = 0;
        }
        m_cItems = d;

        if (0 != d)
        {
            STLSOFT_ASSERT(first != last);

            block_copy(m_buffer, &*first, d);
        }
    }

public: // construction
    /// Constructs an instance with the given number of **uninitialised**
    /// elements
    ///
    /// Constructs an instance with the given number of **uninitialised**
    /// elements. If the allocation fails by throwing an exception, that
    /// exception is passed through to the caller. If allocation fails by
    /// returning a null pointer the auto_buffer instance is correctly
    /// constructed, and the \link #size size() \endlink method returns 0.
    ///
    /// \param cItems The number of items in the constructed instance
    ///
    /// \see \link #size size() \endlink
    ss_explicit_k
    ss_constexpr_2014_k
    auto_buffer(
        size_type   cItems
    )
        : m_buffer((space < cItems) ? allocate_(cItems) : const_cast<pointer>(&m_internal[0]))
        , m_cItems((NULL != m_buffer) ? cItems : 0)
        , m_cExternal((space < cItems) ? cItems : 0)
    {
        // initialise `m_internal` iff we are being used constexpr, ...
#ifdef STLSOFT_IS_CONSTANT_EVALUATED

        if (STLSOFT_IS_CONSTANT_EVALUATED())
        {
            for (auto& i : m_internal)
            {
                i = value_type();
            }
        }
        else
#endif /* STLSOFT_IS_CONSTANT_EVALUATED */
        {

            // ... otherwise initialise zeroth element (for compilers that demand it, because the class invariant does not)
#ifdef STLSOFT_COMPILER_IS_GCC

            m_internal[0] = value_type();
#endif
        }


        // Can't create one with an empty buffer. Though such is not legal
        // it is supported by some compilers, so we must ensure it cannot be
        // so
        STLSOFT_STATIC_ASSERT(0 != space);

        // These assertions ensure that the member ordering is not
        // changed, invalidating the initialisation logic of m_buffer and
        // m_cItems. The runtime assert is included for those compilers that
        // do not implement compile-time asserts.
#ifdef STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT

        STLSOFT_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(class_type, m_buffer) < STLSOFT_RAW_OFFSETOF(class_type, m_cItems));
#endif /* STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT */
#ifdef STLSOFT_IS_CONSTANT_EVALUATED

        if (!STLSOFT_IS_CONSTANT_EVALUATED())
#endif /* STLSOFT_IS_CONSTANT_EVALUATED */
        {

            STLSOFT_MESSAGE_ASSERT("m_buffer must be before m_cItems in the auto_buffer definition", stlsoft_reinterpret_cast(ss_byte_t*, &m_buffer) < stlsoft_reinterpret_cast(ss_byte_t*, &m_cItems));
        }

#ifndef _STLSOFT_AUTO_BUFFER_ALLOW_NON_POD

        // Use the must_be_pod constraint to ensure that
        // no type is managed in auto_buffer which would result in
        // dangerous mismanagement of the lifetime of its instances.
        //
        // Preprocessor specification of _STLSOFT_AUTO_BUFFER_ALLOW_NON_POD
        // prevents this, but the natural rules of the language will
        // still prevent non POD types being placed in m_internal[].
        stlsoft_constraint_must_be_pod(value_type);
#endif /* _STLSOFT_AUTO_BUFFER_ALLOW_NON_POD */

        STLSOFT_ASSERT(is_valid());
    }

    /// Constructs an instance with the given number of **initialised**
    /// elements
    ///
    /// Constructs an instance with the given number of **initialised**
    /// elements. If the allocation fails by throwing an exception, that
    /// exception is passed through to the caller. If allocation fails by
    /// returning a null pointer the auto_buffer instance is correctly
    /// constructed, and the \link #size size() \endlink method returns 0.
    ///
    /// \param cItems The number of items in the constructed instance
    /// \param v The value to which the items will be initialised
    ///
    /// \see \link #size size() \endlink
    ss_constexpr_2014_k
    auto_buffer(
        size_type           cItems
    ,   value_type const&   v
    )
        : m_buffer((space < cItems) ? allocate_(cItems) : const_cast<pointer>(&m_internal[0]))
        , m_cItems((NULL != m_buffer) ? cItems : 0)
        , m_cExternal((space < cItems) ? cItems : 0)
    {
        // initialise `m_internal` iff we are being used constexpr, ...
#ifdef STLSOFT_IS_CONSTANT_EVALUATED

        if (STLSOFT_IS_CONSTANT_EVALUATED())
        {
            for (auto& i : m_internal)
            {
                i = value_type();
            }
        }
        else
#endif /* STLSOFT_IS_CONSTANT_EVALUATED */
        {

            // ... otherwise initialise zeroth element (for compilers that demand it, because the class invariant does not)
#ifdef STLSOFT_COMPILER_IS_GCC

            m_internal[0] = value_type();
#endif
        }

        // Can't create one with an empty buffer. Though such is not legal
        // it is supported by some compilers, so we must ensure it cannot be
        // so
        STLSOFT_STATIC_ASSERT(0 != space);

        // These assertions ensure that the member ordering is not
        // changed, invalidating the initialisation logic of m_buffer and
        // m_cItems. The runtime assert is included for those compilers that
        // do not implement compile-time asserts.
#ifdef STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT

        STLSOFT_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(class_type, m_buffer) < STLSOFT_RAW_OFFSETOF(class_type, m_cItems));
#endif /* STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT */
#ifdef STLSOFT_IS_CONSTANT_EVALUATED

        if (!STLSOFT_IS_CONSTANT_EVALUATED())
#endif /* STLSOFT_IS_CONSTANT_EVALUATED */
        {

            STLSOFT_MESSAGE_ASSERT("m_buffer must be before m_cItems in the auto_buffer definition", stlsoft_reinterpret_cast(ss_byte_t*, &m_buffer) < stlsoft_reinterpret_cast(ss_byte_t*, &m_cItems));
        }

#ifndef _STLSOFT_AUTO_BUFFER_ALLOW_NON_POD

        // Use the must_be_pod constraint to ensure that
        // no type is managed in auto_buffer which would result in
        // dangerous mismanagement of the lifetime of its instances.
        //
        // Preprocessor specification of _STLSOFT_AUTO_BUFFER_ALLOW_NON_POD
        // prevents this, but the natural rules of the language will
        // still prevent non POD types being placed in m_internal[].
        stlsoft_constraint_must_be_pod(value_type);
#endif /* _STLSOFT_AUTO_BUFFER_ALLOW_NON_POD */

#ifdef STLSOFT_IS_CONSTANT_EVALUATED

        if (STLSOFT_IS_CONSTANT_EVALUATED())
        {
            std::fill_n(&m_buffer[0], m_cItems, v);
        }
        else
#endif /* STLSOFT_IS_CONSTANT_EVALUATED */
        {
            block_set(&m_buffer[0], m_cItems, v);
        }

        STLSOFT_ASSERT(is_valid());
    }
#if __cplusplus >= 201702L

    /// Range constructor
    template <ss_typename_param_k I2>
    auto_buffer(
        I2 first
    ,   I2 last
    )
        : m_buffer()
        , m_cItems()
        , m_cExternal(0)
    {
# ifdef STLSOFT_COMPILER_IS_GCC

        m_internal[0] = value_type();
# endif

        enum { argument_is_of_integral_type = is_integral_type<I2>::value };

        // NOTE: if this static assertion fires, you may be passing a signed
        // integer literal to the constructor (which fails to match the
        // overload `auto_buffer(size_type, value_type)`)
        STLSOFT_STATIC_ASSERT(!argument_is_of_integral_type);

        // Can't create one with an empty buffer. Though such is not legal
        // it is supported by some compilers, so we must ensure it cannot be
        // so
        STLSOFT_STATIC_ASSERT(0 != space);

        init_from_range_(first, last, stlsoft_iterator_query_category(I2, first));

        STLSOFT_ASSERT(is_valid());
    }
#else

    /// Range constructor
    auto_buffer(
        value_type const*   first
    ,   value_type const*   last
    )
        : m_buffer()
        , m_cItems()
        , m_cExternal(0)
    {
        // Can't create one with an empty buffer. Though such is not legal
        // it is supported by some compilers, so we must ensure it cannot be
        // so
        STLSOFT_STATIC_ASSERT(0 != space);

        init_from_range_(first, last, stlsoft_iterator_query_category(value_type const*, first));

        STLSOFT_ASSERT(is_valid());
    }
#endif
#if __cplusplus >= 201103L

    /** Constructs an instance to hold copies of the contents of the
     * initializer-list `init_list`, as in:
     *
     *
\code
  stlsoft::auto_buffer<int, 10> buff = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  assert(11 == buff.size());
\endcode
     */
    auto_buffer(
        std::initializer_list<T_value>  init_list
    )
        // TODO: determine if any performance advantage if use `init_list.size()`
        : m_buffer()
        , m_cItems()
        , m_cExternal(0)
    {
        // Can't create one with an empty buffer. Though such is not legal
        // it is supported by some compilers, so we must ensure it cannot be
        // so
        STLSOFT_STATIC_ASSERT(0 != space);

        init_from_range_(init_list.begin(), init_list.end(), stlsoft_iterator_query_category(T_value*, first));

        STLSOFT_ASSERT(is_valid());
    }
#endif
#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

    /// Constructs an instance by taking over the state of the instance
    /// \c rhs
    ///
    /// \param rhs The instance whose state will be taken over. Upon return
    ///   \c rhs will be <code>empty()</code>
    ///
    /// \note When \c rhs is using external memory, this is a (fast)
    ///   constant-time operation; when using internal memory, a memory copy
    ///   operation is required
    ss_constexpr_2014_k
    auto_buffer(class_type&& rhs) STLSOFT_NOEXCEPT
        : m_buffer(ss_nullptr_k)
        , m_cItems(rhs.m_cItems)
        , m_cExternal(rhs.m_cExternal)
    {
        if (0 != rhs.m_cExternal)
        {
            m_buffer        =   rhs.m_buffer;
            rhs.m_buffer    =   &rhs.m_internal[0];
            rhs.m_cExternal =   0;
        }
        else
        {
            m_buffer        =   &m_internal[0];

            block_copy(m_internal, rhs.m_internal, m_cItems);
        }

        rhs.m_cItems    =   0;
    }
#endif /* STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */

    /// Releases the allocated element array
    ///
    /// Releases any allocated memory. If the internal memory buffer was
    /// used, then nothing is done, otherwise the allocated memory is
    /// returned to the allocator.
    ss_constexpr_2020_k
#if defined(STLSOFT_CF_EXCEPTION_SIGNATURE_SUPPORT)
    ~auto_buffer()
#else /* ? STLSOFT_CF_EXCEPTION_SIGNATURE_SUPPORT */
    ~auto_buffer() STLSOFT_NOEXCEPT
#endif /* STLSOFT_CF_EXCEPTION_SIGNATURE_SUPPORT */
    {
        STLSOFT_ASSERT(is_valid());

        if (is_in_external_array_())
        {
            STLSOFT_ASSERT(NULL != m_buffer);
            STLSOFT_ASSERT(0 != m_cExternal);
            STLSOFT_ASSERT(&m_internal[0] != m_buffer);

            deallocate_(m_buffer, m_cItems);
        }
    }
private:
    auto_buffer(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

private: // operations
    // Policy functions
    ss_constexpr_2014_k
    ss_bool_t is_in_external_array_() const
    {
#if defined(STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK)

        // Old implementation always uses internal array if size() <= internal_size()

        STLSOFT_ASSERT((space < m_cItems) == (m_buffer != &m_internal[0]));

        return space < m_cItems;
#else /* ? STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK */

        STLSOFT_ASSERT((m_buffer != &m_internal[0]) == (0 != m_cExternal));
        STLSOFT_ASSERT(0 != m_cExternal || !(space < m_cItems));

        return 0 != m_cExternal;
#endif /* STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK */
    }

public:
    /// Expands or contracts the number of items in the buffer
    ///
    /// \param cItems The number of items to change in the buffer. If 0, the
    ///   external array (if allocated) will be deallocated.
    /// \return Returns \c true if successful. Function failure occurs when
    ///   sufficient storage for the requested items cannot be allocated. In
    ///   that case, std::bad_alloc will be throw for allocators that
    ///   support it, otherwise the function will return \c false. In either
    ///   case, the original storage and contents of the buffer will remain
    ///   unchanged.
    ///
    /// \note This obeys the strong exception guarantee
    ///
    /// \note When reducing the number of elements, the implementation
    ///   favours speed above memory consumption. If the new item size is
    ///   still larger than the internal storage size (\c internal_size())
    ///   then the heap allocated block will not be changed (i.e. it will
    ///   not be exchanged for a smaller block).
    ///
    /// \note As from STLSoft version 1.9, the external array is not
    ///   discarded in favour of the internal array when
    ///   <code>0 < cItems < internal_size()</code>.
    ///   Only <code>resize(0)</code> will deallocate the external array.
    ss_bool_t
    resize(
        size_type   cItems
    )
    {
        STLSOFT_ASSERT(is_valid());

        // There are six changes possible:
        //
        // 1. Expansion within the internal buffer;
        // 2. Contraction within the internal buffer;
        // 3. Expansion from the internal buffer to an allocated buffer;
        // 4. Contraction from an allocated buffer to the internal buffer:
        //  4.a Where n is 0, or when STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK is defined;
        //  4.b Where 0 < n <= internal_size() we do not go to the internal array;
        // 5. Expansion from the allocated buffer to another allocated buffer;
        // 6. Contraction from the allocated buffer to another allocated buffer;

        if (m_cItems < cItems)
        {
            // Expansion; cases 1, 3 & 5

            if (is_in_external_array_())
            {
                if (m_cExternal < cItems)
                {
                    // Current buffer is allocated: case 5
                    pointer const new_buffer = reallocate_(m_buffer, m_cItems, cItems);

                    // Still test for NULL here, since some allocators will
                    // not throw bad_alloc.
                    if (NULL == new_buffer)
                    {
                        return false;
                    }

                    // Now repoint to the new buffer
                    m_buffer = new_buffer;

                    m_cExternal = cItems;
                }
            }
            else
            {
                // Expanding from internal buffer; cases 1 & 3

                if (space < cItems)
                {
                    // Expanding to allocated buffer; case 3

                    pointer new_buffer = allocate_(cItems);

                    // Still test for NULL here, since some allocators will
                    // not throw bad_alloc.
                    if (NULL == new_buffer)
                    {
                        return false;
                    }

                    block_copy(new_buffer, m_buffer, m_cItems);

                    m_buffer = new_buffer;

                    m_cExternal = cItems;
                }
                else
                {
                    // Expanding to internal buffer; case 1

                    // Nothing to do
                    STLSOFT_ASSERT(!(space < cItems));
                }
            }
        }
        else
        {
            // Contraction; cases 2, 4 & 6

            if (is_in_external_array_())
            {
                // Current buffer is allocated: cases 4 & 6

                if (space < cItems)
                {
                    // Contracting within allocated buffer; case 6

                    // Nothing to do
                    STLSOFT_ASSERT(space < cItems);
                }
#if defined(STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK)
                else
#else /* ? STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK */
                else if (0 == cItems)
#endif /* STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK */
                {
                    // Contracting back to internal; case 4

                    block_copy(const_cast<pointer>(&m_internal[0]), m_buffer, cItems);

                    // TODO: must nail down whether this is an over-eager GCC (14.2 MinGW x64) or a defect in `auto_buffer`
#ifdef STLSOFT_MINGW
                    if (m_buffer != &m_internal[0])
#endif
                    {
                        deallocate_(m_buffer, m_cItems);
                    }

                    m_buffer = const_cast<pointer>(&m_internal[0]);

                    m_cExternal = 0;
                }
            }
            else
            {
                // Current buffer is internal; case 2

                // Nothing to do
                STLSOFT_ASSERT(!(space < cItems));
            }
        }

        m_cItems = cItems;

        STLSOFT_ASSERT(is_valid());

        return true;
    }

    /// Resizes and initialises the new items with the given value
    ///
    /// \param cItems The new size of the buffer
    /// \param v The value to which any <em>new</em> items will be
    ///   initialised
    ss_bool_t
    resize(
        size_type           cItems
    ,   value_type const&   v
    )
    {
        size_type const n0  =   m_cItems;
        ss_bool_t const r   =   resize(cItems);
        size_type const n1  =   m_cItems;

        if (r)
        {
            if (n1 > n0)
            {
                block_set(&m_buffer[0] + n0, n1 - n0, v);
            }
        }

        return r;
    }

    /// Copies the contents from \c rhs
    ///
    /// \note This obeys the strong exception guarantee
    ///
    /// \note Unlike <code>resize()</code>, this method always results in an
    ///   internal-storing copy if \c rhs is storing internally.
    void
    copy_from(
        class_type const& rhs
    )
    {
        if (rhs.is_in_external_array_())
        {
            resize(0);
        }

        resize(rhs.size());

        block_copy(&m_buffer[0], &rhs.m_buffer[0], rhs.size());
    }

    /// Swaps contents with the given buffer
    ///
    /// \note This method is only constant time when the memory for two
    /// buffers has been acquired via the allocator. Otherwise, it will
    /// depend on the costs of exchanging the memory
    ///
    /// \note Exception-safety: Provides the no-throw guarantee
    void swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(is_valid());

        // Swap:
        //
        // 1. Allocator
        // 2. Member variables

        // 1. Allocator
#if !defined(STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE)
        std_swap(static_cast<allocator_type&>(*this), static_cast<allocator_type&>(rhs));
#endif /* !STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE */

        // 2. Member variables
        if (is_in_external_array_() &&
            rhs.is_in_external_array_())
        {
            // Both are allocated, so just swap them
            std_swap(m_buffer, rhs.m_buffer);
        }
        else if (is_in_external_array_())
        {
            // *this is allocated on the heap, rhs is using m_internal

            // 1. Copy the contents of rhs.m_internal to this->m_internal
            block_copy(&m_internal[0], &rhs.m_internal[0], rhs.m_cItems);

            // 2. Move m_buffer from *this to rhs
            rhs.m_buffer = m_buffer;

            // 3. Tell *this to use its internal buffer
            m_buffer = &m_internal[0];
        }
        else if (rhs.is_in_external_array_())
        {
            // This is a lazy cheat, but eminently effective.
            rhs.swap(*this);

            return;
        }
        else
        {
            // Both are using internal buffers, so we exchange the contents
            value_type  t[space];

            if (rhs.m_cItems < m_cItems)
            {
                block_copy(&t[0],               &rhs.m_internal[0], rhs.m_cItems);
                block_copy(&rhs.m_internal[0],  &m_internal[0],     m_cItems);
                block_copy(&m_internal[0],      &t[0],              rhs.m_cItems);
            }
            else
            {
                block_copy(&t[0],               &m_internal[0],     m_cItems);
                block_copy(&m_internal[0],      &rhs.m_internal[0], rhs.m_cItems);
                block_copy(&rhs.m_internal[0],  &t[0],              m_cItems);
            }
        }

        std_swap(m_cItems,      rhs.m_cItems);
        std_swap(m_cExternal,   rhs.m_cExternal);

        STLSOFT_ASSERT(is_valid());
    }

public: // operators
    // NOTE: The following two const and non-const implicit conversion
    // operators are correctly implemented. However, GCC will pedantically
    // give a verbose warning describing its having selected one over the
    // other, and this is, in current versions of the compiler, not
    // suppressable. The warnings must, alas, simply be ignored.

#ifdef _STLSOFT_AUTO_BUFFER_ALLOW_NON_CONST_CONVERSION_OPERATOR
    /// An implicit conversion to a pointer to the start of the element
    /// array
    ///
    /// \deprecate This is deprecated
    operator pointer ()
    {
        STLSOFT_ASSERT(is_valid());

        return m_buffer;
    }
#else /* ? _STLSOFT_AUTO_BUFFER_ALLOW_NON_CONST_CONVERSION_OPERATOR */
    /// Subscript operator
    reference operator [](size_type index)
    {
        STLSOFT_MESSAGE_ASSERT("Index is out of bounds", index <= m_cItems);

        STLSOFT_ASSERT(is_valid());

        return m_buffer[index];
    }

    /// Subscript operator
    const_reference operator [](size_type index) const
    {
        STLSOFT_MESSAGE_ASSERT("Index is out of bounds", index <= m_cItems);

        STLSOFT_ASSERT(is_valid());

        return m_buffer[index];
    }
#endif /* _STLSOFT_AUTO_BUFFER_ALLOW_NON_CONST_CONVERSION_OPERATOR */

#ifdef _STLSOFT_AUTO_BUFFER_ALLOW_CONST_CONVERSION_OPERATOR
    /// An implicit conversion to a pointer-to-const to the start of the
    /// element array
    operator const_pointer () const
    {
        STLSOFT_ASSERT(is_valid());

        return m_buffer;
    }
#endif /* _STLSOFT_AUTO_BUFFER_ALLOW_CONST_CONVERSION_OPERATOR */

public: // accessors
    /// Returns a pointer to the element array
    ss_constexpr_2014_k
    pointer data()
    {
        STLSOFT_ASSERT(is_valid());

        return m_buffer;
    }
    /// Returns a pointer-to-const to the element array
    ss_constexpr_2014_k
    const_pointer data() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_buffer;
    }

    /// Returns a reference to the last element in the buffer
    ///
    /// \pre The buffer instance must not be empty
    ss_constexpr_2014_k
    reference front()
    {
        STLSOFT_ASSERT(is_valid());

        STLSOFT_MESSAGE_ASSERT("Cannot call front() on an empty buffer!", !empty());

        return m_buffer[0];
    }
    /// Returns a reference to the last element in the buffer
    ///
    /// \pre The buffer instance must not be empty
    ss_constexpr_2014_k
    reference back()
    {
        STLSOFT_ASSERT(is_valid());

        STLSOFT_MESSAGE_ASSERT("Cannot call back() on an empty buffer!", !empty());

        return m_buffer[size() - 1];
    }
    /// Returns a non-mutating (const) reference to the last element
    ///   in the buffer
    ///
    /// \pre The buffer instance must not be empty
    ss_constexpr_2014_k
    const_reference front() const
    {
        STLSOFT_ASSERT(is_valid());

        STLSOFT_MESSAGE_ASSERT("Cannot call front() on an empty buffer!", !empty());

        return m_buffer[0];
    }
    /// Returns a non-mutating (const) reference to the last element
    ///   in the buffer
    ///
    /// \pre The buffer instance must not be empty
    ss_constexpr_2014_k
    const_reference back() const
    {
        STLSOFT_ASSERT(is_valid());

        STLSOFT_MESSAGE_ASSERT("Cannot call back() on an empty buffer!", !empty());

        return m_buffer[size() - 1];
    }

public: // iteration
    /// Returns a non-mutating iterator representing the start of the
    /// sequence
    ss_constexpr_2014_k
    const_iterator begin() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_buffer;
    }
    /// Returns a non-mutating iterator representing the end of the sequence
    ///
    /// \note In the case where memory allocation has failed in the context
    /// where exceptions are not thrown for allocation failure, this method
    /// will return the same value as begin(). Hence, operations on the
    /// <i>empty</i> auto_buffer<> instance will be safe if made in respect
    /// of the range defined by [begin(), end()).
    ss_constexpr_2014_k
    const_iterator end() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_buffer + m_cItems;
    }

    /// Returns a non-mutating iterator representing the start of the
    /// sequence
    ss_constexpr_2014_k
    const_iterator cbegin() const
    {
        return begin();
    }
    /// Returns a non-mutating iterator representing the end of the sequence
    ///
    /// \note In the case where memory allocation has failed in the context
    /// where exceptions are not thrown for allocation failure, this method
    /// will return the same value as cbegin(). Hence, operations on the
    /// <i>empty</i> auto_buffer<> instance will be safe if made in respect
    /// of the range defined by [cbegin(), cend()).
    ss_constexpr_2014_k
    const_iterator cend() const
    {
        return end();
    }

    /// Returns a mutating iterator representing the start of the sequence
    ss_constexpr_2014_k
    iterator begin()
    {
        STLSOFT_ASSERT(is_valid());

        return m_buffer;
    }
    /// Returns a mutating iterator representing the end of the sequence
    ///
    /// \note In the case where memory allocation has failed in the context
    /// where exceptions are not thrown for allocation failure, this method
    /// will return the same value as begin(). Hence, operations on the
    /// <i>empty</i> auto_buffer<> instance will be safe if made in respect
    /// of the range defined by [begin(), end()).
    ss_constexpr_2014_k
    iterator end()
    {
        STLSOFT_ASSERT(is_valid());

        return m_buffer + m_cItems;
    }
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)

    /// Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    ss_constexpr_2014_k
    const_reverse_iterator rbegin() const
    {
        STLSOFT_ASSERT(is_valid());

        return const_reverse_iterator(end());
    }
    /// Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    ss_constexpr_2014_k
    const_reverse_iterator rend() const
    {
        STLSOFT_ASSERT(is_valid());

        return const_reverse_iterator(begin());
    }

    /// Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    ss_constexpr_2014_k
    const_reverse_iterator crbegin() const
    {
        STLSOFT_ASSERT(is_valid());

        return const_reverse_iterator(cend());
    }
    /// Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    ss_constexpr_2014_k
    const_reverse_iterator crend() const
    {
        STLSOFT_ASSERT(is_valid());

        return const_reverse_iterator(cbegin());
    }

    /// Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    ss_constexpr_2014_k
    reverse_iterator  rbegin()
    {
        STLSOFT_ASSERT(is_valid());

        return reverse_iterator(end());
    }
    /// Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    ss_constexpr_2014_k
    reverse_iterator  rend()
    {
        STLSOFT_ASSERT(is_valid());

        return reverse_iterator(begin());
    }
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

public: // attributes
    /// Returns the number of elements in the auto_buffer
    ///
    /// \note In the case where memory allocation has failed in the context
    /// where exceptions are not thrown for allocation failure in the
    /// constructor, this method will return 0. Hence, operations on the
    /// <i>empty</i> auto_buffer<> instance will be safe if made in respect
    /// of the value returned by this method.
    ss_constexpr_2014_k
    size_type size() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_cItems;
    }

    /// Returns the number of elements in the auto_buffer's internal buffer
    ss_constexpr_2014_k
    static size_type internal_size()
    {
        return space;
    }

    /// Indicates whether the buffer has any contents
    ss_constexpr_2014_k
    ss_bool_t empty() const
    {
        STLSOFT_ASSERT(is_valid());

        return 0 == m_cItems;
    }

#if defined(STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVEx)
    /// Returns an instance of the allocator used to specialise the
    ///  instance.
    static allocator_type& get_allocator()
    {
# if !defined(STLSOFT_STRICT) && \
     defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER >= 1310
#  pragma warning(push)
#  pragma warning(disable : 4640)   /* "construction of local static object is not thread-safe" - since it is here! (As long as one uses a 'conformant' allocator) - maybe use a spin_mutex in future */
# endif /* compiler */

        static allocator_type   s_allocator;

        return s_allocator;

# if !defined(STLSOFT_STRICT) && \
     defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER >= 1310
#  pragma warning(pop)
# endif /* compiler */
    }
#else /* ? STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE */
    /// Returns an instance of the allocator used to specialise the
    /// instance.
    allocator_type get_allocator() const
    {
# if defined(STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE)
        return allocator_type();
# else /* ? STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE */
        return *this;
# endif /* STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE */
    }
#endif /* STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE */

private: // implementation
    ss_constexpr_2014_k
    ss_bool_t is_valid() const
    {
        ss_bool_t   bRet    =   true;

#if defined(STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK)
        if (space < m_cItems &&
            0 == m_cExternal)
        {
            bRet = false;
        }
        if (!(space < m_cItems) &&
            0 != m_cExternal)
        {
            bRet = false;
        }
#else /* ? STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK */

        if (space < m_cItems &&
            0 == m_cExternal)
        {
            bRet = false;
        }
#endif /* STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK */

        if (0 != m_cExternal)
        {
            if (m_buffer == &m_internal[0])
            {
                bRet = false;
            }
        }
        else
        {
            if (m_buffer != &m_internal[0])
            {
                bRet = false;
            }
        }

        return bRet;
    }

private: // fields
    pointer     m_buffer;           // Pointer to used buffer
    size_type   m_cItems;           // Number of items in buffer
    size_type   m_cExternal;        // Number of items in allocated storage
    value_type  m_internal[space];  // Internal storage
};


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ss_typename_param_k T_value
# ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k T_allocator = ss_typename_type_def_k allocator_selector<T_value>::allocator_type
# else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T_allocator
# endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
# ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT
#  if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
!defined(STLSOFT_COMPILER_IS_DMC)
,   ss_size_t           V_space     =   auto_buffer_internal_size_calculator<T_value>::value
#  else /* ? compiler */
,   ss_size_t           V_space     =   256
#  endif /* compiler */
# else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT */
,   ss_size_t           V_space  /* =   auto_buffer_internal_size_calculator<T_value>::value */
# endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT */
>
class auto_buffer_old
# if defined(STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS)
    : public auto_buffer<T_value, T_allocator, V_space>
# else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
    : public auto_buffer<T_value, V_space, T_allocator>
# endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
{
private: // types
# if defined(STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS)
    typedef auto_buffer<
        T_value
    ,   T_allocator
    ,   V_space
    >                                                       parent_class_type;
# else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
    typedef auto_buffer<
        T_value
    ,   V_space
    ,   T_allocator
    >                                                       parent_class_type;
# endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
    typedef auto_buffer_old<
        T_value
    ,   T_allocator
    ,   V_space
    >                                                       class_type;

public:
    typedef ss_typename_type_k parent_class_type::value_type
                                                            value_type;
    typedef ss_typename_type_k parent_class_type::allocator_type
                                                            allocator_type;
    typedef ss_typename_type_k parent_class_type::reference reference;
    typedef ss_typename_type_k parent_class_type::const_reference
                                                            const_reference;
    typedef ss_typename_type_k parent_class_type::pointer   pointer;
    typedef ss_typename_type_k parent_class_type::const_pointer
                                                            const_pointer;
    typedef ss_typename_type_k parent_class_type::size_type size_type;
    typedef ss_typename_type_k parent_class_type::difference_type
                                                            difference_type;
    typedef ss_typename_type_k parent_class_type::iterator  iterator;
    typedef ss_typename_type_k parent_class_type::const_iterator
                                                            const_iterator;
# if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    typedef ss_typename_type_k parent_class_type::reverse_iterator
                                                            reverse_iterator;
    typedef ss_typename_type_k parent_class_type::const_reverse_iterator
                                                            const_reverse_iterator;
# endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

public: // construction
    ss_explicit_k
    ss_constexpr_2014_k
    auto_buffer_old(
        size_type   cItems
    )
        : parent_class_type(cItems)
    {}
private:
    auto_buffer_old(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)
template <
    ss_typename_param_k T_value
# ifdef STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS
,   ss_typename_param_k T_allocator
,   ss_size_t           V_space
# else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
,   ss_size_t           V_space
,   ss_typename_param_k T_allocator
# endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
>
inline
ss_constexpr_2014_k
void
# ifdef STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS
swap(
    auto_buffer<T_value, T_allocator, V_space>& lhs
,   auto_buffer<T_value, T_allocator, V_space>& rhs
)
# else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
swap(
    auto_buffer<T_value, V_space, T_allocator>& lhs
,   auto_buffer<T_value, V_space, T_allocator>& rhs
)
# endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
{
    lhs.swap(rhs);
}
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
  * operators
  */

/** Defines <code>operator -()</code> that facilitates the subtraction of a
 * (related) raw pointer from an \c auto_buffer instance - as
 * in <code>p - buff</code> - where previously the subtraction would have to
 * be against another raw pointer obtained from the buffer - as
 * in <code>p - &buff[0]</code>.
 *
 * \param lhs The (related) raw pointer
 * \param rhs The \c auto_buffer instance
 *
 * \note No validation is done to check that \c lhs is within the range of
 *   memory managed by \c rhs
 */
#if defined(STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS)

template <
    ss_typename_param_k             T_value
,   ss_typename_param_k             T_allocator
,   STLSOFT_NS_QUAL(ss_size_t)      V_space
>
#else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */

template <
    ss_typename_param_k             T_value
,   STLSOFT_NS_QUAL(ss_size_t)      V_space
,   ss_typename_param_k             T_allocator
>
#endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
STLSOFT_NS_QUAL(ss_ptrdiff_t)
operator -(
    T_value const*          lhs
,   auto_buffer<
        T_value
#if defined(STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS)

    ,   T_allocator
    ,   V_space
#else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */

    ,   V_space
    ,   T_allocator
#endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
    > const&                rhs
)
{
    return lhs - &rhs[0];
}


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#ifndef STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED

template <
    ss_typename_param_k T_value
# ifdef STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS
,   ss_typename_param_k T_allocator
,   ss_size_t           V_space
# else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
,   ss_size_t           V_space
,   ss_typename_param_k T_allocator
# endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
>
inline
ss_constexpr_2014_k
ss_bool_t
# ifdef STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS
is_empty(
    auto_buffer<T_value, T_allocator, V_space> const& b
) STLSOFT_NOEXCEPT
# else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
is_empty(
    auto_buffer<T_value, V_space, T_allocator> const& b
) STLSOFT_NOEXCEPT
# endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
{
    return b.empty();
}
#endif /* !STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED */


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
    template <
        ss_typename_param_k         T_value
#  ifdef STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS
    ,   ss_typename_param_k         T_allocator
    ,   STLSOFT_NS_QUAL(ss_size_t)  V_space
#  else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
    ,   STLSOFT_NS_QUAL(ss_size_t)  V_space
    ,   ss_typename_param_k         T_allocator
#  endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
    >
    inline
    void
#  ifdef STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS
    swap(
        STLSOFT_NS_QUAL(auto_buffer)<T_value, T_allocator, V_space>&    lhs
    ,   STLSOFT_NS_QUAL(auto_buffer)<T_value, T_allocator, V_space>&    rhs
    )
#  else /* ? STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
    swap(
        STLSOFT_NS_QUAL(auto_buffer)<T_value, V_space, T_allocator>&    lhs
    ,   STLSOFT_NS_QUAL(auto_buffer)<T_value, V_space, T_allocator>&    rhs
    )
#  endif /* STLSOFT_AUTO_BUFFER_USE_PRE_1_9_CHARACTERISTICS */
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if defined(_MSC_VER) &&\
    _MSC_VER >= 1935

# pragma warning(pop)
#endif


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */

