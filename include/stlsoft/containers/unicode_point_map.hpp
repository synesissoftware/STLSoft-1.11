/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/containers/unicode_point_map.hpp
 *
 * Purpose: A container that measures the frequencies of the unique Unicode
 *          character points it contains.
 *
 * Created: 5th November 2024
 * Updated: 5th November 2024
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


/** \file stlsoft/containers/unicode_point_map.hpp
 *
 * \brief [C++] Definition of the stlsoft::unicode_point_map container class
 *   template
 *   (\ref group__library__Container "Container" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_UNICODE_POINT_MAP
#define STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_UNICODE_POINT_MAP

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_UNICODE_POINT_MAP_MAJOR     1
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_UNICODE_POINT_MAP_MINOR     0
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_UNICODE_POINT_MAP_REVISION  1
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_UNICODE_POINT_MAP_EDIT      1
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <stlsoft/memory/auto_buffer.hpp>

#ifndef STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD
# include <stlsoft/algorithms/pod.hpp>          // for pod_copy_n(), etc.
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

#if __cplusplus >= 201103L
# include <initializer_list>
#endif
#include <unordered_map>


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

/** A container that measures the frequencies of the unique Unicode
 *  character points it contains.
 *
 * \ingroup group__library__Container
 */
class unicode_point_map
{
public: // types
    /// This type
    typedef unicode_point_map                               class_type;
    /// The char type
    typedef char                                            char_type;
    //// The unicode-point type
    typedef ss_uint32_t                                     unicode_point_type;
    /// The count type
    typedef ss_sint64_t                                     count_type;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The key type
    struct                                                  key_type;

private:
    typedef auto_buffer<
        count_type
    >                                                       vec_type_;
    typedef std::unordered_map<
        unicode_point_type
    ,   count_type
    >                                                       map_type_;

public:
    /// The iterator type
    struct const_iterator;

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    struct key_type
    {
    public: // construction
        key_type(char_type c)
        {
            union
            {
                char c;
                ss_uint8_t u8;
                ss_uint32_t u32;
            } u;

            u.c = c;

            STLSOFT_MESSAGE_ASSERT("`c` may not contain a non-ASCII value", 0 == (u.u32 & 0xFFFFFF80));

            this->key = u.u32;
        }
        key_type(unicode_point_type upt)
        {
            this->key = upt;
        }
    private:
        template <ss_typename_param_k T_unacceptable>
        ss_explicit_k
        key_type(T_unacceptable const&) = delete;

    public: // fields
        unicode_point_type  key;
    };
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


public: // construction
    /// Constructs an empty instance
    unicode_point_map();
    /// Constructs an empty instance with the requisite extent of contiguous
    /// storage
    ss_explicit_k
    unicode_point_map(
        unicode_point_type default_contiguous_ceiling
    );
#if __cplusplus >= 201103L
    unicode_point_map(
        std::initializer_list<key_type> init_list
    );
    unicode_point_map(
        unicode_point_type              default_contiguous_ceiling
    ,   std::initializer_list<key_type> init_list
    );
#endif


public: // operations
    void
    clear() STLSOFT_NOEXCEPT;

    class_type&
    merge(class_type const& rhs);

    class_type&
    operator +=(class_type const& rhs);

    void
    push(key_type key);

    count_type
    push_n(
        key_type    key
    ,   count_type  count
    );

    void
    swap(class_type& rhs) STLSOFT_NOEXCEPT;


public: // lookup
    bool
    contains(key_type c) const;

    count_type
    count(key_type key) const;

    const_iterator
    find(key_type c) const;

    count_type
    operator [](key_type key) const;


public: // attributes
    bool
    empty() const STLSOFT_NOEXCEPT;

    size_type
    size() const STLSOFT_NOEXCEPT;

    count_type
    total() const STLSOFT_NOEXCEPT;


public: // fields
    size_type   m_len;
    count_type  m_total;
    vec_type_   m_vec;
    map_type_   m_map;
};


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// constructors

inline
unicode_point_map::unicode_point_map()
    : m_len(0)
    , m_total(0)
    , m_vec(0)
    , m_map()
{}

inline
unicode_point_map::unicode_point_map(
    unicode_point_type default_contiguous_ceiling
)
    : m_len(0)
    , m_total(0)
    , m_vec(default_contiguous_ceiling)
    , m_map()
{}

#if __cplusplus >= 201103L

inline
unicode_point_map::unicode_point_map(
    std::initializer_list<key_type> init_list
)
    : m_len(0)
    , m_total(0)
    , m_vec(0)
    , m_map()
{
    for (auto k : init_list)
    {
        push(k);
    }
}

inline
unicode_point_map::unicode_point_map(
    unicode_point_type              default_contiguous_ceiling
,   std::initializer_list<key_type> init_list
)
    : m_len(0)
    , m_total(0)
    , m_vec(default_contiguous_ceiling)
    , m_map()
{
    for (auto k : init_list)
    {
        push(k);
    }
}
#endif


// operations

inline
void
unicode_point_map::clear() STLSOFT_NOEXCEPT
{
    m_len = 0;
    m_total = 0;
    pod_fill_n(m_vec.begin(), m_vec.size(), count_type());
    m_map.clear();
}

#if 0

class_type&
merge(class_type const& rhs);

class_type&
operator +=(class_type const& rhs);
#endif

inline
void
unicode_point_map::push(key_type key)
{
    push_n(key, 1);
}

inline
unicode_point_map::count_type
unicode_point_map::push_n(
    key_type    key
,   count_type  count
)
{
    if (key.key < m_vec.size())
    {
        count_type const prev = m_vec[key.key];
        count_type const curr = prev + count;

        m_vec[key.key] = curr;

        if (0 == prev)
        {
            if (0 != curr)
            {
                ++m_len;
            }
        }
        else
        {
            if (0 == curr)
            {
                --m_len;
            }
        }

        m_total += count;

        return prev;
    }
    else
    {
        map_type_::iterator it = m_map.find(key.key);

        if (m_map.end() == it)
        {
            if (0 != count)
            {
                m_map.insert(std::make_pair(key.key, count));

                ++m_len;
            }

            m_total += count;

            return 0;
        }
        else
        {
            count_type const prev = (*it).second;

            if (0 == ((*it).second += count))
            {
                m_map.erase(it);

                --m_len;
            }

            m_total += count;

            return prev;
        }
    }
}

inline
void
unicode_point_map::swap(class_type& rhs) STLSOFT_NOEXCEPT
{
    std_swap(m_len, rhs.m_len);
    std_swap(m_total, rhs.m_total);
    std_swap(m_vec, rhs.m_vec);
    std_swap(m_map, rhs.m_map);
}


// lookup

inline
bool
unicode_point_map::contains(key_type key) const
{
    if (key.key < m_vec.size())
    {
        return 0 != m_vec[key.key];
    }
    else
    {
        map_type_::const_iterator it = m_map.find(key.key);

        if (m_map.end() == it)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

inline
unicode_point_map::count_type
unicode_point_map::count(key_type key) const
{
    if (key.key < m_vec.size())
    {
        return m_vec[key.key];
    }
    else
    {
        map_type_::const_iterator it = m_map.find(key.key);

        if (m_map.end() == it)
        {
            return 0;
        }
        else
        {
            return (*it).second;
        }
    }
}

#if 0
    const_iterator
    find(key_type c) const;
#endif

inline
unicode_point_map::count_type
unicode_point_map::operator [](key_type key) const
{
    return count(key);
}

// attributes

inline
bool
unicode_point_map::empty() const STLSOFT_NOEXCEPT
{
    return 0 == m_len;
}

inline
unicode_point_map::size_type
unicode_point_map::size() const STLSOFT_NOEXCEPT
{
    return m_len;
}

inline
unicode_point_map::count_type
unicode_point_map::total() const STLSOFT_NOEXCEPT
{
    return m_total;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


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

#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_UNICODE_POINT_MAP */

/* ///////////////////////////// end of file //////////////////////////// */

