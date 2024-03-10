
#ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_CIRCULAR_BUFFER
#define STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_CIRCULAR_BUFFER


#include <stlsoft/stlsoft.h>

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
    typedef T_value                                         value_type;
    enum { internalSize = V_capacity };
    typedef fixed_circular_buffer<
        value_type
    ,   V_capacity
    >                                                       class_type;
    typedef ss_size_t                                       size_type;
    typedef ss_size_t                                       index_type;
    typedef value_type&                                     reference;
    typedef value_type const&                               const_reference;

    class iterator
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

    private:
        cb_type_* const cb;
        size_type       ix;
    };

    class const_iterator;

    class reverse_iterator;

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

    bool
    empty() const STLSOFT_NOEXCEPT
    {
        return 0 == size();
    }

    bool
    full() const STLSOFT_NOEXCEPT
    {
        return capacity() == size();
    }

    size_type
    size() const STLSOFT_NOEXCEPT
    {
        return m_size;
    }


public: // modifiers
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

            size_type const iix = translate_subscript_e2i_(m_base_offset + m_size);

            m_elements[iix] = value;

            ++m_size;


            return true;
        }
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
    operator [](index_type ix) STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("`fixed_circular_buffer` index out of range", (ix < m_size));

        size_type const ix_internal = translate_subscript_e2i_(ix);

        return m_elements[ix_internal];
    }

    const_reference
    operator [](index_type ix) const STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("`fixed_circular_buffer` index out of range", (ix < m_size));

        size_type const ix_internal = translate_subscript_e2i_(ix);

        return m_elements[ix_internal];
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
            return iterator();
        }

        return iterator(this, m_base_offset);
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
    check_range_(index_type ix)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    if (!(ix < m_size))
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("`fixed_circular_buffer` index out of range"));
    }
#else

    STLSOFT_SUPPRESS_UNUSED(ix);
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

