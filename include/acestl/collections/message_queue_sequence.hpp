/* /////////////////////////////////////////////////////////////////////////
 * File:    acestl/collections/message_queue_sequence.hpp
 *
 * Purpose: Sequence class for adapting ACE_Message_Queue to an STL sequence.
 *
 * Created: 15th September 2004
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


/** \file acestl/collections/message_queue_sequence.hpp
 *
 * \brief [C++] Definition of the acestl::message_queue_sequence
 *   collection class template
 *   (\ref group__library__Collection "Collection" Library).
 */

#ifndef ACESTL_INCL_ACESTL_COLLECTIONS_HPP_MESSAGE_QUEUE_SEQUENCE
#define ACESTL_INCL_ACESTL_COLLECTIONS_HPP_MESSAGE_QUEUE_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_COLLECTIONS_HPP_MESSAGE_QUEUE_SEQUENCE_MAJOR     2
# define ACESTL_VER_ACESTL_COLLECTIONS_HPP_MESSAGE_QUEUE_SEQUENCE_MINOR     1
# define ACESTL_VER_ACESTL_COLLECTIONS_HPP_MESSAGE_QUEUE_SEQUENCE_REVISION  19
# define ACESTL_VER_ACESTL_COLLECTIONS_HPP_MESSAGE_QUEUE_SEQUENCE_EDIT      82
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST
# include <stlsoft/conversion/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST */
#ifndef STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_BOUNDED
# include <stlsoft/algorithms/bounded.hpp>  // for stlsoft::copy_n()
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_BOUNDED */

#if ACESTL_ACE_VERSION >= 0x00050004
  // This stinks, but appears to be necessary in ACE versions later than 5.3
#ifndef STLSOFT_INCL_ACE_H_CONDITION_THREAD_MUTEX
# define STLSOFT_INCL_ACE_H_CONDITION_THREAD_MUTEX
#  include <ace/Condition_Thread_Mutex.h>
#endif /* !STLSOFT_INCL_ACE_H_CONDITION_THREAD_MUTEX */
#ifndef STLSOFT_INCL_ACE_H_GUARD_T
# define STLSOFT_INCL_ACE_H_GUARD_T
#  include <ace/Guard_T.h>
#endif /* !STLSOFT_INCL_ACE_H_GUARD_T */
#ifndef STLSOFT_INCL_ACE_H_NULL_CONDITION
# define STLSOFT_INCL_ACE_H_NULL_CONDITION
#  include <ace/Null_Condition.h>
#endif /* !STLSOFT_INCL_ACE_H_NULL_CONDITION */
#ifndef STLSOFT_INCL_ACE_H_NULL_MUTEX
# define STLSOFT_INCL_ACE_H_NULL_MUTEX
#  include <ace/Null_Mutex.h>
#endif /* !STLSOFT_INCL_ACE_H_NULL_MUTEX */
#ifndef STLSOFT_INCL_ACE_H_THREAD_MUTEX
# define STLSOFT_INCL_ACE_H_THREAD_MUTEX
#  include <ace/Thread_Mutex.h>
#endif /* !STLSOFT_INCL_ACE_H_THREAD_MUTEX */
#endif /* ACESTL_ACE_VERSION */
#ifndef STLSOFT_INCL_ACE_H_MESSAGE_QUEUE_T
# define STLSOFT_INCL_ACE_H_MESSAGE_QUEUE_T
# include <ace/Message_Queue_T.h>
#endif /* !STLSOFT_INCL_ACE_H_MESSAGE_QUEUE_T */

#ifndef STLSOFT_INCL_ALGORITHM
# define STLSOFT_INCL_ALGORITHM
# include <algorithm>                // for std::copy
#endif /* !STLSOFT_INCL_ALGORITHM */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_memfns
# include <stlsoft/api/external/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_memfns */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef ACESTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::acestl */
namespace acestl
{
# else
/* Define stlsoft::acestl_project */
namespace stlsoft
{
namespace acestl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ACESTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** An \ref group__pattern__instance_adaptor "instance adaptor" that
 *    adapts an instance of \c ACE_Message_Queue to provide an STL
 *    input-sequence interface.
 *
 * \ingroup group__library__Collection
 *
 * It is used as follows:
\code
using acestl::message_queue_sequence;
using stlsoft::auto_buffer;

ACE_Message_Queue<ACE_NULL_SYNCH>       &mq = . . .

// Adapt the message queue into the sequence
message_queue_sequence<ACE_NULL_SYNCH>  mqs(mq);

// Allocate a contiguous buffer, using stlsoft::auto_buffer
auto_buffer<char>                       buff(mqs.size());

// Block copy into the buffer
std::copy(&buff[0], &buff[0] + (buff.size()), mqs.begin());
\endcode
 *
 * \note Although this class provides <i>Input Iterator</i>s, it
 *   uses customisations of \c std algorithms to effect very favourable
 *   performance, as described in chapter 31 of
 *   \ref section__publishing__books__xstlv1.
 */
// [[synesis:class:collection: acestl::message_queue_sequence<T<S>>]]
template <ACE_SYNCH_DECL>
class message_queue_sequence
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
/// \name Types
/// @{
public:
    /// The value type
    typedef char                                    value_type;
    /// The sequence type
    typedef ACE_Message_Queue<ACE_SYNCH_USE>        sequence_type;
    /// The current specialisation of the type
    typedef message_queue_sequence<ACE_SYNCH_USE>   class_type;
    /// The size type
    typedef ss_size_t                               size_type;

    /** Iterator type for the message_queue_sequence class template
     *
     * \note Although this iterator class is an <i>Input Iterator</i>, it
     *   uses customisations of \c std algorithms to effect very favourable
     *   performance, as described in chapter 31 of <b>Extended STL,
     *   volume 1</b> (published by Addison-Wesley, June 2007).
     */
    class iterator
        : public STLSOFT_NS_QUAL(iterator_base)<STLSOFT_NS_QUAL_STD(input_iterator_tag)
                                            ,   char
                                            ,   ss_ptrdiff_t
                                            ,   char*
                                            ,   char&
                                            >
    {
    private:
        friend class message_queue_sequence<ACE_SYNCH_USE>;

        typedef ACE_Message_Queue_Iterator<ACE_SYNCH_USE>   mq_iterator_type;

    private:
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
        struct shared_handle
        {
        public:
            typedef shared_handle   class_type;

        // Members
        public:
            mq_iterator_type    m_mqi;
            ACE_Message_Block*  m_entry;
            as_size_t           m_entryLength;
            as_size_t           m_entryIndex;
        private:
            ss_sint32_t         m_refCount;

        /// Construction
        public:
            ss_explicit_k shared_handle(sequence_type &mq)
                : m_mqi(mq)
                , m_entry(NULL)
                , m_entryLength(0)
                , m_entryIndex(0)
                , m_refCount(1)
            {
                if (m_mqi.next(m_entry))
                {
                    for (;;)
                    {
                        if (0 != (m_entryLength = m_entry->length()))
                        {
                            break;
                        }
                        else if (NULL == (m_entry = nextEntry()))
                        {
                            break;
                        }
                    }
                }
            }
# if defined(STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR)
        protected:
# else /* ? STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
        private:
# endif /* STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
            ~shared_handle() STLSOFT_NOEXCEPT
            {
                ACESTL_MESSAGE_ASSERT("Shared search handle being destroyed with outstanding references!", 0 == m_refCount);
            }
        private:
            shared_handle(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
            void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

        /// Accessors
        public:
            ss_bool_t is_end_point() const
            {
                return m_entryIndex == m_entryLength;
            }
            char    &current()
            {
                ACESTL_ASSERT(NULL != m_entry);
                ACESTL_ASSERT(m_entryIndex != m_entryLength);

                return m_entryIndex[m_entry->rd_ptr()];
            }
            char    current() const
            {
                ACESTL_ASSERT(NULL != m_entry);
                ACESTL_ASSERT(m_entryIndex != m_entryLength);

                return m_entryIndex[m_entry->rd_ptr()];
            }

            ss_bool_t   advance()
            {
                ACESTL_MESSAGE_ASSERT("Invalid index", m_entryIndex < m_entryLength);

                if (++m_entryIndex == m_entryLength)
                {
                    m_entryIndex = 0;

                    for (;;)
                    {
                        if (NULL == (m_entry = nextEntry()))
                        {
                            return false;
                        }
                        else if (0 != (m_entryLength = m_entry->length()))
                        {
                            break;
                        }
                    }
                }

                return true;
            }

        /// Operations
        public:
            ss_sint32_t AddRef()
            {
                return ++m_refCount;
            }
            ss_sint32_t Release()
            {
                ss_sint32_t rc = --m_refCount;

                if (0 == rc)
                {
                    delete this;
                }

                return rc;
            }

            void fast_copy(char const* f, char const* l, size_type n)
            {
                ACESTL_ASSERT(0 != n);
                ACESTL_ASSERT(f != l);

                if (0 != n)
                {
                    size_type n1 = m_entryLength - m_entryIndex;

                    if (n <= n1)
                    {
                        // Terminal case

                        STLSOFT_API_EXTERNAL_memfns_memcpy(&m_entryIndex[m_entry->rd_ptr()], f, n);

                        ACESTL_ASSERT(n <= m_entryLength - m_entryIndex);

                        m_entryIndex += n;

                        ACESTL_ASSERT(m_entryIndex <= m_entryLength);
                    }
                    else
                    {
                        // Recursive case

                        STLSOFT_API_EXTERNAL_memfns_memcpy(&m_entryIndex[m_entry->rd_ptr()], f, n1);
                        f += n1;

                        m_entry = nextEntry();

                        ACESTL_MESSAGE_ASSERT("Attempt to walk off end of iterator's range", NULL != m_entry);

                        m_entryIndex    =   0;
                        m_entryLength   =   m_entry->length();

                        fast_copy(f, l, n - n1);
                    }
                }
            }
            void fast_copy(class_type const* l, char* o)
            {
                size_type n1 = m_entryLength - m_entryIndex;

                if (NULL != l &&
                    m_entry == l->m_entry)
                {
                    // Terminal case

                    STLSOFT_API_EXTERNAL_memfns_memcpy(o, &m_entryIndex[m_entry->rd_ptr()], n1);
                }
                else
                {
                    // Recursive case

                    STLSOFT_API_EXTERNAL_memfns_memcpy(o, &m_entryIndex[m_entry->rd_ptr()], n1);
                    o += n1;

                    m_entry = nextEntry();

                    if (NULL != m_entry)
                    {
                        m_entryIndex    =   0;
                        m_entryLength   =   m_entry->length();

                        fast_copy(l, o);
                    }
                }
            }
            void fast_copy(size_type n, char* o)
            {
                size_type n1 = m_entryLength - m_entryIndex;

                if (n <= n1)
                {
                    // Asking for less than (or equal to) the capacity
                    // of the current entry.
                    //
                    // Advance the m_entryIndex member.
                    //
                    // This is the terminating case.

                    STLSOFT_API_EXTERNAL_memfns_memcpy(o, &m_entryIndex[m_entry->rd_ptr()], n);

                    ACESTL_ASSERT(n <= m_entryLength - m_entryIndex);

                    m_entryIndex += n;

                    ACESTL_ASSERT(m_entryIndex <= m_entryLength);
                }
                else
                {
                    STLSOFT_API_EXTERNAL_memfns_memcpy(o, &m_entryIndex[m_entry->rd_ptr()], n1);
                    o += n1;

                    m_entry = nextEntry();

                    ACESTL_MESSAGE_ASSERT("Attempt to walk off end of iterator's range", (0 == n || NULL != m_entry));

                    if (NULL != m_entry)
                    {
                        m_entryIndex    =   0;
                        m_entryLength   =   m_entry->length();

                        fast_copy(n - n1, o);
                    }
                }
            }

        // Implementation
        private:
            ACE_Message_Block* nextEntry()
            {
                ACE_Message_Block* entry = NULL;

                return m_mqi.advance() ? (m_mqi.next(entry), entry) : NULL;
            }
        };
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    public:
        typedef iterator                                    class_type;
        /// The value type
        typedef char                                        value_type;

    private:
        iterator(sequence_type &mq)
            : m_handle(new shared_handle(mq))
        {}
    public:
        iterator()
            : m_handle(NULL)
        {}
        iterator(class_type const& rhs)
            : m_handle(rhs.m_handle)
        {
            if (NULL != m_handle)
            {
                m_handle->AddRef();
            }
        }
        ~iterator() STLSOFT_NOEXCEPT
        {
            if (NULL != m_handle)
            {
                m_handle->Release();
            }
        }

        class_type& operator =(class_type const& rhs)
        {
            shared_handle* this_handle = m_handle;

            m_handle = rhs.m_handle;

            if (NULL != m_handle)
            {
                m_handle->AddRef();
            }

            if (NULL != this_handle)
            {
                this_handle->Release();
            }

            return *this;
        }

    public:
        class_type& operator ++()
        {
            ACESTL_ASSERT(NULL != m_handle);

            if (!m_handle->advance())
            {
                m_handle->Release();

                m_handle = NULL;
            }

            return *this;
        }

        class_type operator ++(int)
        {
            class_type  ret(*this);

            operator ++();

            return ret;
        }

        value_type& operator *()
        {
            ACESTL_ASSERT(NULL != m_handle);

            return m_handle->current();
        }

        value_type operator *() const
        {
            ACESTL_ASSERT(NULL != m_handle);

            return m_handle->current();
        }

    public:
        ss_bool_t equal(class_type const& rhs) const
        {
            return class_type::equal_(*this, rhs, iterator_category());
        }
        ss_bool_t operator ==(class_type const& rhs) const
        {
            return equal(rhs);
        }
        ss_bool_t operator !=(class_type const& rhs) const
        {
            return !equal(rhs);
        }

    private:
        static ss_bool_t equal_(class_type const& lhs, class_type const& rhs, STLSOFT_NS_QUAL_STD(input_iterator_tag))
        {
            // Input iterator
            return lhs.is_end_point() == rhs.is_end_point();
        }
#if 0
        static ss_bool_t equal_(class_type const& lhs, class_type const& rhs, STLSOFT_NS_QUAL_STD(forward_iterator_tag));
            // Forward or above
            if (is_end_point())
            {
                return rhs.is_end_point();
            }
            else
            {
                if (rhs.is_end_point())
                {
                    return false;
                }
                else
                {
                    ACESTL_ASSERT(NULL != m_handle);
                    ACESTL_ASSERT(NULL != rhs.m_handle);
                }
            }
#endif /* 0 */

    private:
        ss_bool_t is_end_point() const
        {
            return NULL == m_handle || m_handle->is_end_point();
        }

    private:
        void fast_copy(char const* f, char const* l)
        {
            if (f != l)
            {
                ACESTL_ASSERT(NULL != m_handle);

                m_handle->fast_copy(f, l, static_cast<size_type>(l - f));
            }
        }
        void fast_copy(class_type const& l, char* o)
        {
            if (*this != l)
            {
                ACESTL_ASSERT(NULL != m_handle);

                m_handle->fast_copy(l.m_handle, o);
            }
        }
        void fast_copy(size_type n, char* o)
        {
            if (0 != n)
            {
                ACESTL_ASSERT(NULL != m_handle);

                m_handle->fast_copy(n, o);
            }
        }

    private:
        shared_handle* m_handle;
    };
/// @}

// Construction
public:
    /// Create an instance representing the given environment variable
    ss_explicit_k message_queue_sequence(sequence_type &mq)
        : m_mq(mq)
    {}
private:
    message_queue_sequence(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    iterator begin()
    {
        return iterator(m_mq);
    }
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    iterator end()
    {
        return iterator();
    }
/// @}

/// \name Attributes
/// @{
public:
    /// Returns the number of bytes in the message queue
    size_type size() const
    {
        return m_mq.message_length() /* - 1 */;
    }
    /// Indicates whethere there are any bytes in the message queue
    as_bool_t empty() const
    {
        return const_cast<sequence_type&>(m_mq).is_empty();
    }
/// @}

/// \name Operations
/// @{
public:
    static char* fast_copy(iterator f, iterator l, char* o)
    {
#if defined(ACESTL_MQS_NO_FAST_COPY_TO)
        for (; f != l; ++f, ++o)
        {
            *o = *f;
        }
#else /* ? ACESTL_MQS_NO_FAST_COPY_TO */
        f.fast_copy(l, o);
#endif /* ACESTL_MQS_NO_FAST_COPY_TO */

        return o;
    }
    static char* fast_copy(iterator f, size_type n, char* o)
    {
#if defined(ACESTL_MQS_NO_FAST_COPY_TO)
        for (; 0 != n; ++f, ++o, --n)
        {
            *o = *f;
        }
#else /* ? ACESTL_MQS_NO_FAST_COPY_TO */
        f.fast_copy(n, o);
#endif /* ACESTL_MQS_NO_FAST_COPY_TO */

        return o;
    }

    static iterator fast_copy(char const* f, char const* l, iterator o)
    {
#if defined(ACESTL_MQS_NO_FAST_COPY_FROM)
        for (; f != l; ++f, ++o)
        {
            *o = *f;
        }
#else /* ? ACESTL_MQS_NO_FAST_COPY_FROM */
        o.fast_copy(f, l);
#endif /* ACESTL_MQS_NO_FAST_COPY_FROM */

        return o;
    }
/// @}

/// \name Members
/// @{
private:
    sequence_type   &m_mq;
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef ACESTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace acestl
# else
} // namespace acestl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ACESTL_NO_NAMESPACE */

// define specialisations in the std namespace

#ifdef STLSOFT_CF_std_NAMESPACE
namespace std
{
#endif /* STLSOFT_CF_std_NAMESPACE */

STLSOFT_TEMPLATE_SPECIALISATION
inline char* copy(  ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    f
                ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    l
                ,   char*                                                               o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(f, l, o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline char* copy(  ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      f
                ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      l
                ,   char*                                                               o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(f, l, o);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline signed char* copy(   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    f
                        ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    l
                        ,   signed char*                                                        o)
{
    return reinterpret_cast<signed char*>(ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(f, l, reinterpret_cast<char*>(o)));
}
STLSOFT_TEMPLATE_SPECIALISATION
inline signed char* copy(   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      f
                        ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      l
                        ,   signed char*                                                        o)
{
    return reinterpret_cast<signed char*>(ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(f, l, reinterpret_cast<char*>(o)));
}

STLSOFT_TEMPLATE_SPECIALISATION
inline unsigned char* copy( ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    f
                        ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    l
                        ,   unsigned char*                                                      o)
{
    return reinterpret_cast<unsigned char*>(ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(f, l, reinterpret_cast<char*>(o)));
}
STLSOFT_TEMPLATE_SPECIALISATION
inline unsigned char* copy( ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      f
                        ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      l
                        ,   unsigned char*                                                      o)
{
    return reinterpret_cast<unsigned char*>(ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(f, l, reinterpret_cast<char*>(o)));
}



STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy(   char*                                                               f
                                                                            ,   char*                                                               l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(f, l, o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy(     char*                                                               f
                                                                            ,   char*                                                               l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(f, l, o);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy(   signed char*                                                        f
                                                                            ,   signed char*                                                        l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(l), o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy(     signed char*                                                        f
                                                                            ,   signed char*                                                        l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(l), o);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy(   unsigned char*                                                      f
                                                                            ,   unsigned char*                                                      l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(l), o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy(     unsigned char*                                                      f
                                                                            ,   unsigned char*                                                      l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(l), o);
}



STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy(   char const* f
                                                                            ,   char const* l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(f, l, o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy(     char const* f
                                                                            ,   char const* l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(f, l, o);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy(   signed char const* f
                                                                            ,   signed char const* l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(l), o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy(     signed char const* f
                                                                            ,   signed char const* l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(l), o);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy(   unsigned char const* f
                                                                            ,   unsigned char const* l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(l), o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy(     unsigned char const* f
                                                                            ,   unsigned char const* l
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(l), o);
}

#ifdef STLSOFT_CF_std_NAMESPACE
} // namespace std
#endif /* STLSOFT_CF_std_NAMESPACE */

// define specialisations in the stlsoft namespace

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* !STLSOFT_NO_NAMESPACE */

STLSOFT_TEMPLATE_SPECIALISATION
inline char* copy_n(ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    f
                ,   ss_size_t                                                           n
                ,   char*                                                               o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(f, n, o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline char* copy_n(ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      f
                ,   ss_size_t                                                           n
                ,   char*                                                               o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(f, n, o);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline signed char* copy_n( ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    f
                        ,   ss_size_t                                                           n
                        ,   signed char*                                                        o)
{
    return reinterpret_cast<signed char*>(ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(f, n, reinterpret_cast<char*>(o)));
}
STLSOFT_TEMPLATE_SPECIALISATION
inline signed char* copy_n( ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      f
                        ,   ss_size_t                                                           n
                        ,   signed char*                                                        o)
{
    return reinterpret_cast<signed char*>(ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(f, n, reinterpret_cast<char*>(o)));
}

STLSOFT_TEMPLATE_SPECIALISATION
inline unsigned char* copy_n(   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    f
                            ,   ss_size_t                                                           n
                            ,   unsigned char*                                                      o)
{
    return reinterpret_cast<unsigned char*>(ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(f, n, reinterpret_cast<char*>(o)));
}
STLSOFT_TEMPLATE_SPECIALISATION
inline unsigned char* copy_n(   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      f
                            ,   ss_size_t                                                           n
                            ,   unsigned char*                                                      o)
{
    return reinterpret_cast<unsigned char*>(ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(f, n, reinterpret_cast<char*>(o)));
}



STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy_n( char*                                                               f
                                                                            ,   ss_size_t                                                           n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(f, f + n, o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy_n(   char*                                                               f
                                                                            ,   ss_size_t                                                           n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(f, f + n, o);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy_n( signed char*                                                        f
                                                                            ,   ss_size_t                                                           n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(f) + n, o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy_n(   signed char*                                                        f
                                                                            ,   ss_size_t                                                           n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(f) + n, o);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy_n( unsigned char*                                                      f
                                                                            ,   ss_size_t                                                           n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(f) + n, o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy_n(   unsigned char*                                                      f
                                                                            ,   ss_size_t                                                           n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator      o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(f) + n, o);
}



STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy_n( char const*                                                         f
                                                                            ,   ss_size_t                                                           n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator    o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(f, f + n, o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy_n(   char const* f
                                                                            ,   ss_size_t n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(f, f + n, o);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy_n( signed char const* f
                                                                            ,   ss_size_t n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(f) + n, o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy_n(   signed char const* f
                                                                            ,   ss_size_t n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(f) + n, o);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator copy_n( unsigned char const* f
                                                                            ,   ss_size_t n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_NULL_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(f) + n, o);
}
STLSOFT_TEMPLATE_SPECIALISATION
inline ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator copy_n(   unsigned char const* f
                                                                            ,   ss_size_t n
                                                                            ,   ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::iterator o)
{
    return ACESTL_NS_QUAL(message_queue_sequence)<ACE_MT_SYNCH>::fast_copy(STLSOFT_NS_QUAL(sap_cast)<char const*>(f), STLSOFT_NS_QUAL(sap_cast)<char const*>(f) + n, o);
}

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* !STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !ACESTL_INCL_ACESTL_COLLECTIONS_HPP_MESSAGE_QUEUE_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

