/* /////////////////////////////////////////////////////////////////////////
 * File:    rangelib/random_range.hpp
 *
 * Purpose: Random number range class.
 *
 * Created: 31st May 2004
 * Updated: 20th March 2025
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


/** \file rangelib/random_range.hpp Random number range class */

#ifndef RANGELIB_INCL_RANGELIB_HPP_RANDOM_RANGE
#define RANGELIB_INCL_RANGELIB_HPP_RANDOM_RANGE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define RANGELIB_VER_RANGELIB_HPP_RANDOM_RANGE_MAJOR      2
# define RANGELIB_VER_RANGELIB_HPP_RANDOM_RANGE_MINOR      2
# define RANGELIB_VER_RANGELIB_HPP_RANDOM_RANGE_REVISION   10
# define RANGELIB_VER_RANGELIB_HPP_RANDOM_RANGE_EDIT       46
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC:     _MSC_VER < 1200
STLSOFT_COMPILER_IS_MWERKS:   (__MWERKS__ & 0xFF00) < 0x3000
[Incompatibilies-end]
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef RANGELIB_INCL_RANGELIB_HPP_RANGELIB
# include <rangelib/rangelib.hpp>
#endif /* !RANGELIB_INCL_RANGELIB_HPP_RANGELIB */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef RANGELIB_INCL_RANGELIB_HPP_RANGE_CATEGORIES
# include <rangelib/range_categories.hpp>
#endif /* !RANGELIB_INCL_RANGELIB_HPP_RANGE_CATEGORIES */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_OPERATOR_BOOL
# include <stlsoft/util/operator_bool.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_OPERATOR_BOOL */

#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h>                     // for rand(), srand()
#endif /* !STLSOFT_INCL_H_STDLIB */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef RANGELIB_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::rangelib */
namespace rangelib
{
# else
/* Define stlsoft::rangelib_project */
namespace stlsoft
{
namespace rangelib_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !RANGELIB_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** This range class represents a range of random numbers.
 *
 * \ingroup group__library__Range
 *
 * It is categoried as a Notional Range
 *
 * It could be used as follows
\code
  // Create a range of 10 values, whose value are between -100 and +100
  stlsoft::random_range   r(10, -100, +100);

  // Dump them to stdout
  stlsoft::r_copy(r, std::ostream_iterator<int>(" "));
\endcode
 */
class random_range
    : public notional_range_tag
{
/// \name Types
/// @{
public:
    typedef int                 value_type;
    typedef notional_range_tag  range_tag_type;
    typedef random_range        class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs a random range
    ///
    /// \param numValues The number of values in the range
    /// \param minValue The lower limit of the random number range
    /// \param maxValue The upper limit of the random number range
    random_range(ss_size_t numValues, value_type minValue = 0, value_type maxValue = RAND_MAX)
        : m_numValues(numValues)
        , m_minValue(minValue)
        , m_maxValue(maxValue)
        , m_position(0)
        , m_value(next_value_(minValue, maxValue))
    {
        STLSOFT_ASSERT(minValue <= maxValue);
        STLSOFT_ASSERT((maxValue - minValue) <= RAND_MAX);
    }
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Notional Range methods
/// @{
private:
    STLSOFT_DEFINE_OPERATOR_BOOL_TYPES(class_type, operator_bool_generator_type, operator_bool_type);
public:
    /// Indicates whether the range is open
    ss_bool_t is_open() const
    {
        return m_position != m_numValues;
    }
    /// Returns the current value in the range
    value_type current() const
    {
        STLSOFT_MESSAGE_ASSERT("Attempting to access the value of a closed range", is_open());

        return m_value;
    }
    /// Advances the current position in the range
    class_type& advance()
    {
        STLSOFT_MESSAGE_ASSERT("Attempting to advance a closed range", is_open());

        ++m_position;
        m_value = next_value_(m_minValue, m_maxValue);

        return *this;
    }

    /// Indicates whether the range is open
    operator operator_bool_type() const
    {
        return operator_bool_generator_type::translate(is_open());
    }
    /// Returns the current value in the range
    value_type operator *() const
    {
        return current();
    }
    /// Advances the current position in the range
    class_type& operator ++()
    {
        return advance();
    }
    /// Advances the current position in the range, returning a copy of the
    /// range prior to its being advanced
    class_type operator ++(int)
    {
        class_type  ret(*this);

        operator ++();

        return ret;
    }
/// @}

/// \name Attributes
/// @{
public:
    /// The lower limit of the random number range
    value_type minimum() const
    {
        return m_minValue;
    }
    /// The upper limit of the random number range
    value_type maximum() const
    {
        return m_maxValue;
    }
/// @}

/// \name Comparison
/// @{
public:
    /// Evaluates whether two ranges are equal
    bool operator ==(class_type const& /* rhs */) const
    {
        return false;
    }
    /// Evaluates whether two ranges are unequal
    bool operator !=(class_type const& rhs) const
    {
        return ! operator ==(rhs);
    }
/// @}

/// \name Implementation
/// @{
private:
    static value_type next_value_(value_type minValue, value_type maxValue)
    {
        return (maxValue - minValue) ? minValue + (rand() % (maxValue - minValue)) : 0;
    }
/// @}

// Members
private:
    const ss_size_t m_numValues;
    const int       m_minValue;
    const int       m_maxValue;
    ss_size_t       m_position;
    int             m_value;
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef RANGELIB_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace rangelib
# else
} // namespace rangelib_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !RANGELIB_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !RANGELIB_INCL_RANGELIB_HPP_RANDOM_RANGE */

/* ///////////////////////////// end of file //////////////////////////// */

