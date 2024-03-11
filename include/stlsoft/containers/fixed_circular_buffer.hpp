
#ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_CIRCULAR_BUFFER
#define STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_CIRCULAR_BUFFER


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

namespace stlsoft {


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

    class iterator
        : public STLSOFT_NS_QUAL(iterator_base)<
                        STLSOFT_NS_QUAL_STD(input_iterator_tag)
                    ,   value_type
                    ,   difference_type
                    ,   pointer
                    ,   reference
                    >
    {
    private: // types
        friend class fixed_circular_buffer<T_value, V_capacity>;
        typedef fixed_circular_buffer<T_value, V_capacity>      cb_type_;
    public:
        typedef iterator                                        class_type;

    private: // construction
        iterator(
            cb_type_*   cb
        ,   size_type   ix
        )
            : cb(cb)
            , ix(ix)
        {}
    public:
        iterator()
            : cb(ss_nullptr_k)
            , ix(std::numeric_limits<size_type>::max())
        {}

    public:
        value_type&
        operator *()
        {
            STLSOFT_MESSAGE_ASSERT("calling increment on an end-iterator", ss_nullptr_k != cb);

            return cb->at(ix);
        }

        class_type&
        operator ++()
        {
            STLSOFT_MESSAGE_ASSERT("calling increment on an end-iterator", ss_nullptr_k != cb);

            if (++ix == cb->size())
            {
                cb = ss_nullptr_k;
                ix = std::numeric_limits<size_type>::max();
            }

            return *this;
        }
        class_type
        operator ++(int)
        {
            STLSOFT_MESSAGE_ASSERT("calling increment on an end-iterator", ss_nullptr_k != cb);

            if (ix + 1 == cb->size())
            {
                return class_type();
            }
            else
            {
                return class_type(cb, ix + 1);
            }
        }

    public:
        bool
        operator == (
            class_type const& rhs
        ) const STLSOFT_NOEXCEPT
        {
            if (ss_nullptr_k == cb)
            {
                STLSOFT_ASSERT(std::numeric_limits<size_type>::max() == ix);

                if (ss_nullptr_k == rhs.cb)
                {
                    STLSOFT_ASSERT(std::numeric_limits<size_type>::max() == rhs.ix);

                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (ss_nullptr_k == rhs.cb)
                {
                    STLSOFT_ASSERT(std::numeric_limits<size_type>::max() == rhs.ix);

                    return false;
                }
                else
                {
                    return true;
                }
            }
        }

        bool
        operator != (
            class_type const& rhs
        ) const STLSOFT_NOEXCEPT
        {
            // TODO: `return !operator ==(rhs);`

            if (ss_nullptr_k == cb)
            {
                STLSOFT_ASSERT(std::numeric_limits<size_type>::max() == ix);

                if (ss_nullptr_k == rhs.cb)
                {
                    STLSOFT_ASSERT(std::numeric_limits<size_type>::max() == rhs.ix);

                    return false;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                if (ss_nullptr_k == rhs.cb)
                {
                    STLSOFT_ASSERT(std::numeric_limits<size_type>::max() == rhs.ix);

                    return true;
                }
                else
                {
                    return true;
                }
            }
        }


    public:
        class_type
        operator +(
            difference_type n
        )
        {
            STLSOFT_ASSERT(n >= 0);

            STLSOFT_MESSAGE_ASSERT("iterator arithmetic on an end-iterator", ss_nullptr_k != cb);

            if (ix + n == cb->size())
            {
                return class_type();
            }
            else
            {
                return class_type(cb, ix + n);
            }
        }


    private:
        cb_type_*   cb;
        size_type   ix;
    };

    class const_iterator;

#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// The mutating (non-const) reverse iterator type
    typedef ss_typename_type_k reverse_iterator_generator<
        iterator
    ,   value_type
    ,   reference
    ,   pointer
    ,   difference_type
    >::type                                                 reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

    class const_reverse_iterator;
private:
    typedef std::array<
        value_type
    ,   internalSize
    >                                                       entries_type_;

public: // construction
    fixed_circular_buffer() STLSOFT_NOEXCEPT
        : m_base_offset(0)
        , m_size(0)
    {}
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
            index_type const eix = i.ix;

            index_type iix = translate_subscript_e2i_(eix);

            erase_at_(iix);

            return iterator(this, eix);
        }
    }

    bool
    try_push_back(
        value_type const& value
    )
    {
        if (capacity() == size())
        {
            return false;
        }
        else
        {

            size_type const iix = translate_subscript_e2i_(m_size);

            m_elements[iix] = value;

            ++m_size;


            return true;
        }
    }

    size_type
    try_push_range(
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


public: // accessors
    reference
    at(index_type index)
    {
        check_range_(index);

        return (*this)[index];
    }

    const_reference
    at(index_type index) const
    {
        check_range_(index);

        return (*this)[index];
    }

    reference
    operator [](index_type index) STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("`fixed_circular_buffer` index out of range", (index < m_size));

        size_type const iix = translate_subscript_e2i_(index);

        return m_elements[iix];
    }

    const_reference
    operator [](index_type index) const STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("`fixed_circular_buffer` index out of range", (index < m_size));

        size_type const iix = translate_subscript_e2i_(index);

        return m_elements[iix];
    }

    reference
    front()
    {
        return at(0);
    }

    reference
    back()
    {
        return at(size() - 1);
    }

    const_reference
    front() const
    {
        return at(0);
    }

    const_reference
    back() const
    {
        return at(size() - 1);
    }


public: // iteration
    iterator
    begin()
    {
        if (empty())
        {
            return end();
        }
        else
        {
            return iterator(this, 0);
        }
    }

    iterator
    end()
    {
        return iterator();
    }

    const_iterator
    cbegin();
    const_iterator
    cend();

    const_reverse_iterator
    crbegin();
    const_reverse_iterator
    crend();


private: // implementation
    void
    check_range_(index_type index)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        if (!(index < m_size))
        {
            STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`fixed_circular_buffer` index out of range"));
        }
#else

        STLSOFT_SUPPRESS_UNUSED(index);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    size_type
    translate_subscript_e2i_(
        index_type eix
    )
    {
        STLSOFT_ASSERT(eix < m_size);

        size_type const iix = (eix + m_base_offset) % capacity();

        return iix;
    }

    void
    erase_at_(index_type iix)
    {
        STLSOFT_ASSERT(iix < size());


        // TODO: use traits to memmove() where can, use `std::move()` where can, ...


        if (0 == iix)
        {
            // we can just bump the base

            m_elements[iix] = value_type();

            m_base_offset += 1;

            --m_size;

            return;
        }


        if (iix == size() - 1)
        {
            // we can just drop the top

            m_elements[iix] = value_type();

            --m_size;

            return;
        }


        if (m_base_offset == 0)
        {
            // not wrapped

            for (size_type i = iix; i != size() - 1; ++i)
            {
                m_elements[i] = m_elements[i + 1];
            }

            m_elements[size() - 1] = value_type();

            --m_size;

            return;
        }
        else
        {
            // wrapped - determine from which side to be removed

            // for example:
            //
            // consider the example of <int, 10> 1, 2, 3, 4, 5, 6, 7, 8
            //
            // then could be:
            //
            //     |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |
            //     | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
            //
            // a:  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |    |    |
            //
            // b:  |    |    |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |
            //
            // c:  |  5 |  6 |  7 |  8 |    |    |  1 |  2 |  3 |  4 |
            //

            ;
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

} /* namespace stlsoft */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_CIRCULAR_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */

