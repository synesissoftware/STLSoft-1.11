
#ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_CIRCULAR_BUFFER
#define STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_CIRCULAR_BUFFER


#include <stlsoft/stlsoft.h>

#include <array>


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

    class iterator
    {
    private: // types
        friend class fixed_circular_buffer<T_value, V_capacity>;
    public:
        typedef iterator                                        class_type;

    public:
        bool
        operator == (
            class_type const& rhs
        ) const STLSOFT_NOEXCEPT
        {
            ((void)&rhs);

            return true;
        }
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


public: // iteration
    iterator
    begin()
    {
        return iterator();
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

