/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/containers/fixed_circular_buffer.hpp
 *
 * Purpose: fixed_circular_buffer class.
 *
 * Created: 10th March 2024
 * Updated: 15th March 2024
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2024, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/containers/fixed_circular_buffer.hpp
 *
 * \brief [C++] Definition of the stlsoft::fixed_circular_buffer class
 *  template
 *   (\ref group__library__Container "Container" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_CIRCULAR_BUFFER
#define STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_CIRCULAR_BUFFER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_FIXED_CIRCULAR_BUFFER_MAJOR     1
# define STLSOFT_VER_STLSOFT_STRING_HPP_FIXED_CIRCULAR_BUFFER_MINOR     0
# define STLSOFT_VER_STLSOFT_STRING_HPP_FIXED_CIRCULAR_BUFFER_REVISION  1
# define STLSOFT_VER_STLSOFT_STRING_HPP_FIXED_CIRCULAR_BUFFER_EDIT      1
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

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_GENERATORS
# include <stlsoft/util/std/iterator_generators.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_GENERATORS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */

#include <array>
#include <limits>
#include <stdexcept>


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft {
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/// Fixed-sized circular buffer
///
/// \tparam T_value The value type of the circular buffer
/// \tparam V_capacity The capacity of the circular buffer
template<
    ss_typename_param_k T_value
,   ss_size_t           V_capacity
>
class fixed_circular_buffer
{
public: // types
    /// The value type
    typedef T_value                                         value_type;
private:
    enum { internalSize = V_capacity };
public:
    /// The current specialisation of the type
    typedef fixed_circular_buffer<
        value_type
    ,   V_capacity
    >                                                       class_type;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The index type
    typedef ss_size_t                                       index_type;
    /// The difference type
    typedef ss_ptrdiff_t                                    difference_type;
    /// The pointer type
    typedef value_type*                                     pointer;
    /// The non-mutating (const) pointer type
    typedef value_type const*                               const_pointer;
    /// The reference type
    typedef value_type&                                     reference;
    /// The non-mutating (const) reference type
    typedef value_type const&                               const_reference;

    /// Class template defining container-specific iterator functionality
    ///
    /// \tparam T_pointer
    /// \tparam T_reference
    template <
        ss_typename_param_k T_pointer
    ,   ss_typename_param_k T_reference
    ,   ss_typename_param_k T_container_pointer
    >
    class iterator_base
        : public STLSOFT_NS_QUAL(iterator_base)<
                        STLSOFT_NS_QUAL_STD(input_iterator_tag)
                    ,   value_type
                    ,   difference_type
                    ,   T_pointer
                    ,   T_reference
                    >
    {
    private: // types
        friend class fixed_circular_buffer<T_value, V_capacity>;
        typedef fixed_circular_buffer<T_value, V_capacity>      cb_type_;
    public:
        /// The current specialisation of the type
        typedef iterator_base<
            T_pointer
        ,   T_reference
        ,   T_container_pointer
        >                                                       class_type;
        /// The pointer type
        typedef T_pointer                                       pointer_type;
        /// The reference type
        typedef T_reference                                     reference_type;
        /// The container pointer type
        typedef T_container_pointer                             container_pointer_type;

    private: // construction
        iterator_base(
            container_pointer_type  cb
        ,   size_type               iix
        )
            : cb(cb)
            , iix(iix)
        {}
    public:
        /// Constructs an unpositioned iterator instance
        iterator_base()
            : cb(ss_nullptr_k)
            , iix(std::numeric_limits<size_type>::max())
        {}

    public:
        /// Dereference operator
        reference_type
        operator *()
        {
            STLSOFT_MESSAGE_ASSERT("calling increment on an end-iterator", ss_nullptr_k != cb);

            return cb->at(iix);
        }

        /// Preincrement operator
        class_type&
        operator ++()
        {
            STLSOFT_MESSAGE_ASSERT("calling increment on an end-iterator", ss_nullptr_k != cb);

            if (++iix == cb->size())
            {
                cb = ss_nullptr_k;
                iix = std::numeric_limits<size_type>::max();
            }

            return *this;
        }

        /// Postincrement operator
        class_type
        operator ++(int)
        {
            class_type r(*this);

            operator ++();

            return r;
        }

    public:
        /// Predecrement operator
        class_type&
        operator --()
        {
            STLSOFT_MESSAGE_ASSERT("calling decrement on an end-iterator", ss_nullptr_k != cb);

            --iix;

            return *this;
        }

        /// Postdecrement operator
        class_type
        operator --(int)
        {
            class_type r(*this);

            operator --();

            return r;
        }

    public:
        /// Equality operator
        bool
        operator ==(
            class_type const& rhs
        ) const STLSOFT_NOEXCEPT
        {
            class_type const& lhs = *this;

            if (lhs.is_end())
            {
                if (rhs.is_end())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (rhs.is_end())
                {
                    return false;
                }
                else
                {
                    return lhs.iix == rhs.iix;
                }
            }
        }

        /// Inequality operator
        bool
        operator !=(
            class_type const& rhs
        ) const STLSOFT_NOEXCEPT
        {
            return !operator ==(rhs);
        }


    public:
        /// Addition operator
        class_type
        operator +(
            difference_type n
        ) const
        {
            STLSOFT_MESSAGE_ASSERT("iterator arithmetic on an end-iterator", ss_nullptr_k != cb);

            if (iix + n == cb->size())
            {
                return class_type();
            }
            else
            {
                return class_type(cb, iix + n);
            }
        }

        /// Subtraction operator
        class_type
        operator -(
            difference_type n
        ) const
        {
            STLSOFT_MESSAGE_ASSERT("iterator arithmetic on an end-iterator", ss_nullptr_k != cb);

            if (iix - n == cb->size())
            {
                return class_type();
            }
            else
            {
                return class_type(cb, iix - n);
            }
        }


    private: // implementation
        bool
        is_end() const STLSOFT_NOEXCEPT
        {
            if (ss_nullptr_k == cb)
            {
                return true;
            }

            STLSOFT_ASSERT(std::numeric_limits<size_type>::max() != iix);

            STLSOFT_ASSERT(iix <= cb->size());

            if (iix == cb->size())
            {
                return true;
            }

            return false;
        }


    private: // fields
        container_pointer_type  cb;
        size_type               iix;
    };

    /// The mutating (non-const) iterator type
    typedef iterator_base<
        pointer
    ,   reference
    ,   class_type*
    >                                                       iterator;
    /// The non-mutating (const) iterator type
    typedef iterator_base<
        const_pointer
    ,   const_reference
    ,   class_type const*
    >                                                       const_iterator;
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
    typedef std::array<
        value_type
    ,   internalSize
    >                                                       entries_type_;

public: // construction
    /// Default constructor
    fixed_circular_buffer() STLSOFT_NOEXCEPT
        : m_base_offset(0)
        , m_size(0)
    {}
    /// Constructs from an initialiser list
    fixed_circular_buffer(std::initializer_list<value_type> init)
        : m_base_offset(0)
        , m_size(0)
    {
        for (auto i = init.begin(); init.end() != i; ++i)
        {
            if (!try_push_back(*i))
            {
                STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(runtime_error)("`fixed_circular_buffer` too many"));
            }
        }
    }


public: // attributes
    /// The maximum number of elements that can be stored in the container
    constexpr
    size_type
    capacity() const STLSOFT_NOEXCEPT
    {
        return internalSize;
    }

#if 0

    static
    size_type
    capacity() STLSOFT_NOEXCEPT;
#endif

    /// Indicates whether the container is empty
    bool
    empty() const STLSOFT_NOEXCEPT
    {
        return 0 == size();
    }

    /// Indicates whether the container is full
    bool
    full() const STLSOFT_NOEXCEPT
    {
        return capacity() == size();
    }

    /// The number of elements in the container
    size_type
    size() const STLSOFT_NOEXCEPT
    {
        return m_size;
    }


public: // modifiers
    /// Removes all entries
    void
    clear()
    {
        clear_();
    }

    /// Erase element specified by the given iterator
    ///
    /// \param i The iterator specifying the element to be erased
    iterator
    erase(
        iterator i
    )
    {
        if (end() == i)
        {
            return i;
        }
        else
        {
            index_type const eix = i.iix;

            index_type const iix = translate_subscript_e2i_(eix);

            erase_at_(eix, iix);

            return iterator(this, eix);
        }
    }

    /// Erase elements specified by the given iterator range
    ///
    /// \param from The iterator specifying the start of the range
    /// \param to The iterator specifying the end of the range
    iterator
    erase(
        iterator from
    ,   iterator to
    )
    {
        if (from == to)
        {
            return from;
        }

        if (end() == from)
        {
            return from;
        }

        size_type const from_eix    =   from.iix;
        size_type const to_eix      =   (end() == to) ? size() : to.iix;

        index_type const from_iix   =   translate_subscript_e2i_(from_eix);
        index_type const to_iix     =   translate_subscript_e2i_(to_eix);

        erase_range_(from_eix, from_iix, to_eix, to_iix);

        return iterator(this, from_eix);
    }

    /// Removes the front-most element
    ///
    /// \pre !empty()
    void
    pop_front()
    {
        STLSOFT_ASSERT(!empty());

        erase(begin());
    }

    /// Removes the back-most element
    ///
    /// \pre !empty()
    void
    pop_back()
    {
        STLSOFT_ASSERT(!empty());

        erase(end() - 1);
    }

    bool
    try_push_back(
        value_type const& value
    )
    {
        if (full())
        {
            return false;
        }
        else
        {
            push_back_(value);

            return true;
        }
    }

    size_type
    try_push_back_range(
        std::initializer_list<value_type> init
    )
    {
        // TODO: replace this with a more efficient implementation

        size_type r = 0;

        for (auto i = init.begin(); init.end() != i; ++i, ++r)
        {
            if (!try_push_back(*i))
            {
                break;
            }
        }

        return r;
    }

    bool
    try_push_front(
        value_type const& value
    )
    {
        if (full())
        {
            return false;
        }
        else
        {
            push_front_(value);

            return true;
        }
    }


public: // accessors
    /// Returns a mutable (non-const) reference to the element at the given
    /// index
    ///
    /// \param index The requested index. If not in range [0, size()) then
    ///  an instance of std::out_of_range will be thrown
    ///
    /// \exception std::out_of_range Thrown if index not in range
    reference
    at(index_type index)
    {
        check_range_(index);

        return (*this)[index];
    }
    /// Returns an immutable (const) reference to the element at the given
    /// index
    ///
    /// \param index The requested index. If not in range [0, size()) then
    ///  an instance of std::out_of_range will be thrown
    ///
    /// \exception std::out_of_range Thrown if index not in range
    const_reference
    at(index_type index) const
    {
        check_range_(index);

        return (*this)[index];
    }

    /// Returns a mutable (non-const) reference to the element at the given
    /// index
    ///
    /// \param index The requested index. Must be less in range [0, size())
    ///
    /// \pre (index < size())
    reference
    operator [](index_type index) STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("`fixed_circular_buffer` index out of range", (index < m_size));

        size_type const iix = translate_subscript_e2i_(index);

        return m_elements[iix];
    }
    /// Returns an immutable (const) reference to the element at the given
    /// index
    ///
    /// \param index The requested index. Must be less in range [0, size())
    ///
    /// \pre (index < size())
    const_reference
    operator [](index_type index) const STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("`fixed_circular_buffer` index out of range", (index < m_size));

        size_type const iix = translate_subscript_e2i_(index);

        return m_elements[iix];
    }

    /// Returns a mutating (non-const) reference to the first element in the
    /// container
    reference
    front()
    {
        return at(0);
    }
    /// Returns a mutating (non-const) reference to the last element in the
    /// container
    reference
    back()
    {
        return at(size() - 1);
    }

    /// Returns a non-mutating (const) reference to the first element in the
    /// container
    const_reference
    front() const
    {
        return at(0);
    }
    /// Returns a non-mutating (const) reference to the last element in the
    /// container
    const_reference
    back() const
    {
        return at(size() - 1);
    }


public: // iteration
    /// A non-mutating (const) iterator representing the start of the
    /// sequence
    iterator
    begin()
    {
        return iterator(this, 0);
    }
    /// A non-mutating (const) iterator representing the end-point of the
    /// sequence
    iterator
    end()
    {
        return iterator(this, size());
    }

    /// A non-mutating (const) iterator representing the start of the
    /// sequence
    const_iterator
    cbegin() const
    {
        return const_iterator(this, 0);
    }
    /// A non-mutating (const) iterator representing the end-point of the
    /// sequence
    const_iterator
    cend() const
    {
        return const_iterator(this, size());
    }

    /// A non-mutating (const) iterator representing the start of the
    /// reverse sequence
    reverse_iterator
    rbegin()
    {
        return reverse_iterator(end());
    }
    /// A non-mutating (const) iterator representing the end of the reverse
    /// sequence
    reverse_iterator
    rend()
    {
        return reverse_iterator(begin());
    }

    /// A non-mutating (const) iterator representing the start of the
    /// reverse sequence
    const_reverse_iterator
    crbegin() const
    {
        return const_reverse_iterator(cend());
    }
    /// A non-mutating (const) iterator representing the end of the reverse
    /// sequence
    const_reverse_iterator
    crend() const
    {
        return const_reverse_iterator(cbegin());
    }


private: // implementation
    void
    check_range_(
        index_type index
    ) const
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        if (!(index < m_size))
        {
            STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`fixed_circular_buffer` index out of range"));
        }
#else

        // TODO: STLSoft 1.12 non-exception abort functionality

        STLSOFT_SUPPRESS_UNUSED(index);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    size_type
    translate_subscript_e2i_(
        index_type eix
    ) const
    {
        STLSOFT_ASSERT(eix <= m_size);

        size_type const iix = (m_base_offset + eix) % capacity();

        return iix;
    }


    void
    clear_()
    {
        for (size_type i = 0; i != size(); ++i)
        {
            size_type const j = translate_subscript_e2i_(i);

            m_elements[j] = value_type();
        }

        m_size = 0;
        m_base_offset = 0;
    }

    void
    erase_at_(
        index_type eix
    ,   index_type iix
    )
    {
        STLSOFT_ASSERT(!empty());

        if (1 == size())
        {
            STLSOFT_ASSERT(eix == 0);

            m_elements[iix] = value_type();

            m_base_offset = 0;
            m_size = 0;
        }
        else
        {
            // determine whether to move up or down, favouring down if mid of odd-size()

            bool const move_up = ((eix + 1) * 2) < size();

            if (move_up)
            {
                // UP:

                size_type const n_u = eix;
                size_type const p = eix;

                for (size_type i = 0; i != n_u; ++i)
                {
                    size_type const src_iix     =   translate_subscript_e2i_(p - (1 + i));
                    size_type const dest_iix    =   translate_subscript_e2i_(p - (0 + i));

                    m_elements[dest_iix] = m_elements[src_iix];
                }

                size_type const def_iix =   translate_subscript_e2i_(p - n_u);

                m_elements[def_iix] = value_type();

                m_base_offset = (m_base_offset + 1) % capacity();
                --m_size;
            }
            else
            {
                // DOWN:

                size_type const n_v = size() - (eix + 1);
                size_type const p = eix;

                for (size_type i = 0; i != n_v; ++i)
                {
                    size_type const src_iix     =   translate_subscript_e2i_(p + (1 + i));
                    size_type const dest_iix    =   translate_subscript_e2i_(p + (0 + i));

                    m_elements[dest_iix] = m_elements[src_iix];
                }

                size_type const def_iix =   translate_subscript_e2i_(p + n_v);

                m_elements[def_iix] = value_type();

                --m_size;
            }
        }
    }

    void
    erase_range_(
        index_type  from_eix
    ,   index_type  from_iix
    ,   index_type  to_eix
    ,   index_type  to_iix
    )
    {
        if (from_eix == to_eix)
        {
            STLSOFT_ASSERT(from_iix == to_iix);

            return;
        }
        else
        {
            STLSOFT_ASSERT(!empty());

            if (0 == from_eix)
            {
                if (size() == to_eix)
                {
                    // removing all

                    clear_();

                    return;
                }
                else
                {
                    // removing from beginning

                    for (size_type i = 0; i != to_eix; ++i)
                    {
                        size_type const j = translate_subscript_e2i_(i);

                        m_elements[j] = value_type();
                    }

                    m_base_offset = (m_base_offset + to_eix) % capacity();
                    m_size -= to_eix;

                    return;
                }
            }

            if (to_eix == size())
            {
                STLSOFT_ASSERT(0 != from_eix);

                // removing to end

                for (size_type i = from_eix; i != to_eix; ++i)
                {
                    size_type const j = translate_subscript_e2i_(i);

                    m_elements[j] = value_type();
                }

                m_size -= (to_eix - from_eix);

                return;
            }


            size_type const n_r         =   (to_eix - from_eix);
            bool const      move_up     =   (from_eix * 2) < (size() - n_r);

            if (move_up)
            {
                // moving UP

                size_type const n_u = from_eix;
                size_type const n_v = to_eix - n_u;

                for (size_type i = 0; i != n_u; ++i)
                {
                    size_type const src_eix     =   from_eix - (1 + i);
                    size_type const dest_eix    =   to_eix - (1 + i);

                    size_type const src_iix     =   translate_subscript_e2i_(src_eix);
                    size_type const dest_iix    =   translate_subscript_e2i_(dest_eix);

                    m_elements[dest_iix] = m_elements[src_iix];
                }

                for (size_type i = 0; i != n_v; ++i)
                {
                    size_type const iix = translate_subscript_e2i_(i);

                    m_elements[iix] = value_type();;
                }

                m_base_offset = (m_base_offset + n_r) % capacity();
                m_size -= n_r;
            }
            else
            {
                // moving DOWN

                size_type const n_d = size() - to_eix;
                size_type const n_v = n_r;

                for (size_type i = 0; i != n_d; ++i)
                {
                    size_type const src_eix     =   to_eix + i;
                    size_type const dest_eix    =   from_eix + i;

                    size_type const src_iix     =   translate_subscript_e2i_(src_eix);
                    size_type const dest_iix    =   translate_subscript_e2i_(dest_eix);

                    m_elements[dest_iix] = m_elements[src_iix];
                }

                for (size_type i = 0; i != n_v; ++i)
                {
                    size_type const eix = size() - (1 + i);

                    size_type const iix = translate_subscript_e2i_(eix);

                    m_elements[iix] = value_type();;
                }

                m_size -= n_r;
            }
        }
    }

    void
    push_back_(
        value_type const& value
    )
    {
        STLSOFT_ASSERT(!full());

        size_type const eix = m_size;
        size_type const iix = translate_subscript_e2i_(eix);

        m_elements[iix] = value;

        ++m_size;
    }

    void
    push_front_(
        value_type const& value
    )
    {
        if (empty())
        {
            push_back_(value);
        }
        else
        {
            STLSOFT_ASSERT(!full());

            m_base_offset = (m_base_offset + (capacity() - 1)) % capacity();

            STLSOFT_ASSERT(m_base_offset < m_elements.size());

            m_elements[m_base_offset] = value;

            ++m_size;
        }
    }


private: // fields
    size_type       m_base_offset;
    size_type       m_size;
    entries_type_   m_elements;
};


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_CIRCULAR_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */

