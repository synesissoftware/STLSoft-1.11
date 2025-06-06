/* /////////////////////////////////////////////////////////////////////////
 * File:    comstl/collections/enumerator_sequence.hpp (originally MOEnSeq.h, ::SynesisCom)
 *
 * Purpose: STL sequence for IEnumXXXX enumerator interfaces.
 *
 * Created: 17th September 1998
 * Updated: 20th March 2025
 *
 * Thanks:  To Eduardo Bezerra and Vivi Orunitia for reporting
 *          incompatibilities with Borland's 5.82 (Turbo C++). The awful
 *          preprocessor hack around retrievalQuanta are the result. ;)
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/collections/enumerator_sequence.hpp
 *
 * \brief [C++] Definition of the comstl::enumerator_sequence
 *   collection class template
 *   (\ref group__library__Collection "Collection" Library).
 */

#ifndef COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATOR_SEQUENCE
#define COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATOR_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_ENUMERATOR_SEQUENCE_MAJOR    6
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_ENUMERATOR_SEQUENCE_MINOR    1
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_ENUMERATOR_SEQUENCE_REVISION 15
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_ENUMERATOR_SEQUENCE_EDIT     280
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES
# include <comstl/collections/enumeration_policies.hpp>
#endif /* !COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES
# include <stlsoft/meta/capabilities.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES */
#ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
# ifndef STLSOFT_INCL_STLSOFT_META_HPP_BASE_TYPE_TRAITS
#  include <stlsoft/meta/base_type_traits.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_META_HPP_BASE_TYPE_TRAITS */
# ifndef STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF
#  include <stlsoft/meta/select_first_type_if.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF */
#endif /* !STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

#ifndef STLSOFT_INCL_ALGORITHM
# define STLSOFT_INCL_ALGORITHM
# include <algorithm>
#endif /* !STLSOFT_INCL_ALGORITHM */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** A template for adapting COM enumerators to STL-compatible
 *    sequence iteration.
 *
 * \ingroup group__library__Collection
 *
 * \param I Interface
 * \param V Value type
 * \param VP Value policy type
 * \param R Reference type. The type returned by the iterator's dereference
 *   operator. Defaults to <code>V const&</code>. To make it mutable, set to
 *   <code>V&</code>
 * \param CP Cloning policy type. Defaults to cloneable_cloning_policy&lt;I>
 * \param Q Quanta. The number of elements retrieved from the enumerator
 *   with each invocation of Next(). Defaults to 10
 *
 * The various specialising types are used to stipulate the interface and
 * the value type, and how they are to be handled.
 *
 * For example, the following specialisation defines a sequence operating
 * over an <code>IEnumGUID</code> enumerator instance.
 *
\code
typedef enumerator_sequence<
    IEnumGUID
,   GUID
,   GUID_policy
,   GUID const&
,   forward_cloning_policy<IEnumGUID>
,   5
>           enum_sequence_t;
\endcode
 *
 * The value type is <code>GUID</code> and it is returned as a reference, as
 * the <code>GUID const&</code> in fact.
 *
 * The \ref group__project__comstl type
 * <code>GUID_policy</code> controls how the
 * <code>GUID</code> instances are initialised, copied and
 * destroyed.
 *
 * The \ref group__project__comstl type forward_cloning_policy allows the sequence to provide
 * <a href = "http://sgi.com/tech/stl/ForwardIterator.html">Forward Iterator</a>
 * semantics.
 *
 * And the <code>5</code> indicates that the sequence should
 * grab 5 values at a time, to save round trips to the enumerator.
 *
 * This would be used as follows:
 *
\code
void dump_GUID(GUID const&);

LPENUMGUID        penGUIDs = . . .;       // Create an instance from wherever
enum_sequence_t   guids(penGUIDs, false); // Consume the reference

std::for_each(guids.begin(), guids.end(), dump_GUID);
\endcode
 *
 * \note The iterator instances returned by begin() and end() are valid outside
 * the lifetime of the collection instance from which they are obtained
 *
 * \remarks A detailed examination of the design and implementation of this
 *   class template is described in Chapters 28 and 29 of
 *   <a href="http://www.extendedstl.com/"><b>Extended STL, volume 1</b></a>
 *   (published by Addison-Wesley, June 2007).
 *
 * \sa comstl::collection_sequence
 */
template<   ss_typename_param_k I                                   /* Interface */
        ,   ss_typename_param_k V                                   /* Value type */
        ,   ss_typename_param_k VP                                  /* Value policy type */
        ,   ss_typename_param_k R   =   V const&                    /* Reference type */
        ,   ss_typename_param_k CP  =   cloneable_cloning_policy<I> /* Cloning policy type */
        ,   cs_size_t           Q   =   10                          /* Quanta */
        >
class enumerator_sequence
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
/// \name Member Types
/// @{
public:
    /// Interface type
    typedef I                                               interface_type;
    /// Value type
    typedef V                                               value_type;
    /// Value policy type
    typedef value_policy_adaptor<VP>                        value_policy_type;
    /// Reference type
    typedef R                                               reference;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef R                                               reference_type; // For backwards compatiblity
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// The mutating (non-const) pointer type
#if defined(STLSOFT_META_HAS_SELECT_FIRST_TYPE_IF) && \
       !defined(STLSOFT_COMPILER_IS_BORLAND)
    typedef ss_typename_type_k STLSOFT_NS_QUAL(select_first_type_if)<
        value_type const*
    ,   value_type*
    ,   STLSOFT_NS_QUAL(base_type_traits)<R>::is_const
    >::type                                                 pointer;
#else /* ? STLSOFT_META_HAS_SELECT_FIRST_TYPE_IF */
    typedef value_type*                                     pointer;
#endif /* !STLSOFT_META_HAS_SELECT_FIRST_TYPE_IF */
    /// The non-mutating (const) pointer type
    typedef value_type const*                               const_pointer;
    /// Cloning policy type
    typedef CP                                              cloning_policy_type;
    /// Iterator tag type
    typedef ss_typename_type_k cloning_policy_type::iterator_tag_type
                                                            iterator_tag_type;
#ifdef STLSOFT_COMPILER_IS_BORLAND
# define retrievalQuanta                                    Q
#else /* ? compiler */
    /// Retrieval quanta
    enum                                                    { retrievalQuanta = Q };
#endif /* compiler */
    /// The current specialisation of the type
    typedef enumerator_sequence<
        I
    ,   V
    ,   VP
    ,   R
    ,   CP
    ,   Q
    >                                                       class_type;
    /// The current specialisation of the type
    typedef class_type                                      sequence_type;
    /// The size type
    typedef cs_size_t                                       size_type;
    /// The difference type
    typedef cs_ptrdiff_t                                    difference_type;
    /// The Boolean type
    typedef cs_bool_t                                       bool_type;
/// @}

public:
    /// Conversion constructor
    ///
    /// \param i The enumeration interface pointer to adapt
    /// \param bAddRef Causes a reference to be added if \c true, otherwise the sequence is deemed to <i>sink</i>, or consume, the interface pointer
    /// \param quanta The actual quanta required for this instance. Must be <= Q. Defaults to 0, which causes it to be Q
    /// \param bReset Determines whether the Reset() method is invoked on the enumerator instance upon construction. Defaults to true
    ///
    /// \note This does not throw an exception, so it is safe to be used to "eat" the
    /// reference. The only possible exception to this is if COMSTL_ASSERT() or COMSTL_MESSAGE_ASSERT(), which are
    /// used to validate that the given quanta size is within the limit specified in
    /// the specialisation, has been redefined to throw an exception. But since
    /// precondition violations are no more recoverable than any others (see the article
    /// "The Nuclear Reactor and the Deep Space Probe"), this does not represent
    /// a concerning contradiction to the no-throw status of the constructor.
    enumerator_sequence(interface_type* i, bool_type bAddRef, size_type quanta = 0, bool_type bReset = true)
        : m_root(i)
        , m_enumerator(NULL)
        , m_quanta(validate_quanta_(quanta))
        , m_bFirst(true)
    {
        COMSTL_MESSAGE_ASSERT("Precondition violation: interface cannot be NULL!", NULL != i);

        if (bAddRef)
        {
            m_root->AddRef();
        }
        if (bReset)
        {
            m_root->Reset();
        }

        // Here we instantiate m_enumerator
        //
        // If noncloneable, then just AddRef()
        // Otherwise Clone() and fail
        //
        // At this point, m_enumerator will be non-NULL, and
        // can be used in all invocations of begin(), or it
        // will be \c nullptr, in which case the 2nd or subsequent
        // invocations of begin() must be directed to throw.
        m_enumerator = cloning_policy_type::get_working_instance(m_root);

        if (NULL != m_enumerator)
        {
            m_bFirst = false;
        }

        COMSTL_ASSERT(is_valid());
    }
    /// Releases the adapted interface pointer
    ~enumerator_sequence() STLSOFT_NOEXCEPT
    {
        COMSTL_ASSERT(is_valid());

        m_root->Release();
        if (NULL != m_enumerator)
        {
            m_enumerator->Release();
        }
    }
private:
    enumerator_sequence(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

/// \name Iteration
/// @{
public:
    /// Iterator for the enumerator_sequence class
    class iterator
        : public STLSOFT_NS_QUAL(iterator_base)<iterator_tag_type
                                            ,   value_type
                                            ,   difference_type
                                            ,   pointer
                                            ,   reference
                                            >
    {
    public:
        typedef iterator                                                    class_type;
#if defined(STLSOFT_COMPILER_IS_GCC)
        typedef ss_typename_type_k sequence_type::cloning_policy_type       cloning_policy_type;
        typedef ss_typename_type_k sequence_type::value_type                value_type;
#endif /* compiler */

    private:
        struct enumeration_context
        {
        /// \name Member Types
        /// @{
        public:
            typedef enumeration_context     class_type;
            typedef V                       value_type;
            typedef CP                      cloning_policy_type;
        /// @}

        /// \name Construction
        /// @{
        private:
            /// Copying constructor
            ///
            /// This constructor copies the state of rhs, and is given a new
            /// cloned enumerator instance pointer.
            enumeration_context(interface_type* i, class_type const& rhs)
                : m_enumerator(i)
                , m_acquired(rhs.m_acquired)
                , m_current(rhs.m_current)
                , m_quanta(rhs.m_quanta)
                , m_refCount(1)
                , m_previousBlockTotal(rhs.m_previousBlockTotal)
            {
                COMSTL_ASSERT(rhs.m_acquired <= m_quanta);

                // Initialise all elements first, so that if a copy() throws an exception
                // all is cleared up simply.
                init_elements_(m_quanta);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                {
                    value_type*         begin      =   &m_values[0];
                    value_type*         end        =   &m_values[0] + m_quanta;
                    value_type const*   src_begin  =   &rhs.m_values[0];
                    value_type const*   src_end    =   &rhs.m_values[0] + rhs.m_acquired;

                    // Copy each element up to the common extent ...
                    for (; src_begin != src_end; ++begin, ++src_begin)
                    {
                        value_policy_type::copy(begin, src_begin);
                    }

                    COMSTL_ASSERT(begin <= end);
                    STLSOFT_SUPPRESS_UNUSED(end);
                }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                catch (...)
                {
                    // Must clear everything up here, since the enumeration_context will
                    // not be destroyed (because it is not fully constructed).
                    clear_elements_();

                    throw;
                }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

                COMSTL_ASSERT(is_valid());

                COMSTL_ASSERT(this->index() == rhs.index());
            }
        public:
            /// Sharing constructor
            ///
            /// The iterator is
            enumeration_context(interface_type* i, size_type quanta, bool_type bFirst)
                : m_enumerator(bFirst ? (i->AddRef(), i) : cloning_policy_type::share(i))
                , m_acquired(0)
                , m_current(0)
                , m_quanta(static_cast<ULONG>(quanta))
                , m_refCount(1)
                , m_previousBlockTotal(0)
            {
                COMSTL_ASSERT(quanta <= STLSOFT_NUM_ELEMENTS(m_values));

                init_elements_(m_quanta);

                // NOTE: We don't add a reference here, because share() increments the reference count.

                acquire_next_();

                COMSTL_ASSERT(is_valid());
            }

            ~enumeration_context() STLSOFT_NOEXCEPT
            {
                ++m_refCount;
                COMSTL_ASSERT(is_valid());
                --m_refCount;

                clear_elements_();

                if (NULL != m_enumerator)
                {
                    m_enumerator->Release();
                }
            }
        private:
            enumeration_context(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
            void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

        public:
            void AddRef()
            {
                ++m_refCount;
            }
            void Release()
            {
                if (0 == --m_refCount)
                {
                    delete this;
                }
            }

            static class_type* make_clone(class_type* ctxt)
            {
                if (NULL == ctxt)
                {
                    return NULL;
                }
                else
                {
                    COMSTL_ASSERT(NULL != ctxt->m_enumerator);   // Must always have one, so can test its cloneability

                    interface_type* copy;
                    const bool      bTrueClone  =   cloning_policy_type::clone(ctxt->m_enumerator, &copy);

                    if (!bTrueClone)
                    {
                        COMSTL_ASSERT(NULL == copy);

                        // Either forward_cloning_policy/input_cloning_policy that failed, or input_cloning_policy
                        //
                        // No reference will have been taken on m_ctxt->m_enumerator
                        //
                        // Just add ref on context, and return

                        ctxt->AddRef();

                        return ctxt;
                    }
                    else
                    {
                        COMSTL_ASSERT(NULL != copy);

                        // Either forward_cloning_policy that succeeded, or degenerate_cloning_policy that succeeded
                        //
                        //

                        class_type* newCtxt;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                        {
                            newCtxt = new class_type(copy, *ctxt);

                            if (NULL == newCtxt)
                            {
                                copy->Release();
                            }
                        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                        catch (...)
                        {
                            copy->Release();

                            throw;
                        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

                        return newCtxt;
                    }
                }
            }
        /// @}

        /// \name Iteration
        /// @{
        public:
            void advance() STLSOFT_NOEXCEPT
            {
                COMSTL_ASSERT(NULL != m_enumerator);

                // Four possibilities here:
                //
                // 1. Called when in an invalid state. This is determined by:
                //   -
                //   -
                //   -
                // 2. next iteration point is within the number acquired
                // 3. need to acquire more elements from IEnumXXXX::Next()

                // 1.
                COMSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator: m_refCount < 1", 0 < m_refCount);
                COMSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator: 0 == m_acquired", 0 != m_acquired);
                COMSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator: m_current >= m_acquired", m_current < m_acquired);
                COMSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator: m_acquired > m_quanta", m_acquired <= m_quanta);
                COMSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator: m_quanta > dimensionof(m_values)", m_quanta <= STLSOFT_NUM_ELEMENTS(m_values));

                if (++m_current < m_acquired)
                {
                    // 2.

                    // Do nothing
                }
                else
                {
                    COMSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator", NULL != m_enumerator);

                    clear_elements_();

                    // Reset enumeration
                    m_current = 0;

                    acquire_next_();
                }
            }

            value_type &current() STLSOFT_NOEXCEPT
            {
                COMSTL_ASSERT(!empty());

                return m_values[m_current];
            }

            size_type index() const STLSOFT_NOEXCEPT
            {
                return m_previousBlockTotal + m_current;
            }

            bool empty() const STLSOFT_NOEXCEPT
            {
                return 0 == m_acquired /* && NULL == m_enumerator */;
            }
        /// @}

        /// \name Invariant
        /// @{
        public:
            bool_type is_valid() const
            {
                if (m_refCount < 1)
                {
                    return false;
                }

                if (NULL == m_enumerator &&
                    0 == m_quanta)
                {
                    if (0 != m_acquired)
                    {
                        return false;
                    }
                    if (0 != m_current)
                    {
                        return false;
                    }
                    if (0 != m_quanta)
                    {
                        return false;
                    }
                }
                else
                {
                    if (m_acquired < m_current)
                    {
                        return false;
                    }
                    if (m_quanta < m_current)
                    {
                        return false;
                    }
                    if (m_quanta < m_acquired)
                    {
                        return false;
                    }
                }

                return true;
            }
        /// @}

        /// \name Implementation
        /// @{
        private:
            void acquire_next_() STLSOFT_NOEXCEPT
            {
//              COMSTL_ASSERT(0 == m_acquired);
                COMSTL_ASSERT(0 == m_current);

                ULONG   cFetched    =   0;

                m_enumerator->Next(m_quanta, &m_values[0], &cFetched);

                m_acquired              =   cFetched;
                m_previousBlockTotal    +=  cFetched;

                // We no longer checked for a FAILED(hr), since some enumerators
                // return invalid results. We rely on cFetched, which is the
                // only reliable guide when marshalling anyway
            }

            void clear_elements_() STLSOFT_NOEXCEPT
            {
                COMSTL_ASSERT(m_acquired <= STLSOFT_NUM_ELEMENTS(m_values));

                typedef ss_typename_type_k value_policy_type::clear_element clear_t;

                STLSOFT_NS_QUAL_STD(for_each)(&m_values[0], &m_values[0] + m_acquired, clear_t());
            }

            void init_elements_(size_type n) STLSOFT_NOEXCEPT
            {
                COMSTL_ASSERT(n <= STLSOFT_NUM_ELEMENTS(m_values));

                typedef ss_typename_type_k value_policy_type::init_element  init_t;

                STLSOFT_NS_QUAL_STD(for_each)(&m_values[0], &m_values[0] + n, init_t());
            }
        /// @}

        /// \name Members
        /// @{
        private:
            interface_type* m_enumerator;
            size_type       m_acquired;
            size_type       m_current;
            ULONG const     m_quanta;
            value_type      m_values[retrievalQuanta];
            long            m_refCount;
            size_type       m_previousBlockTotal;
        /// @}
        };


    /// \name Construction
    /// @{
    private:
        friend class enumerator_sequence<I, V, VP, R, CP, Q>;

        /// Constructor
        iterator(interface_type* i, size_type quanta, bool_type &bFirst)
            : m_ctxt(new enumeration_context(i, quanta, bFirst))
        {
            bFirst = false;

            COMSTL_ASSERT(is_valid());
        }
    public:
        /// Default constructor
        iterator()
            : m_ctxt(NULL)
        {
            COMSTL_ASSERT(is_valid());
        }
        /// Copy constructor
        iterator(class_type const& rhs)
            : m_ctxt(enumeration_context::make_clone(rhs.m_ctxt))
        {
            COMSTL_ASSERT(is_valid());
        }

        /// Releases any internal storage
        ~iterator() STLSOFT_NOEXCEPT
        {
            COMSTL_ASSERT(is_valid());

            if (NULL != m_ctxt)
            {
                m_ctxt->Release();
            }
        }

        class_type& operator =(class_type const& rhs)
        {
            enumeration_context *newCtxt    =   enumeration_context::make_clone(rhs.m_ctxt);

            if (NULL != m_ctxt)
            {
                m_ctxt->Release();
            }

            m_ctxt = newCtxt;

            return *this;
        }
    /// @}

    /// \name Forward Iterator Methods
    /// @{
    public:
        /// Pre-increment operator
        class_type& operator ++()
        {
            COMSTL_ASSERT(is_valid());

            m_ctxt->advance();

            COMSTL_ASSERT(is_valid());

            return *this;
        }

        /// Post-increment operator
        class_type operator ++(int)
        {
            COMSTL_ASSERT(is_valid());

            class_type  r(*this);

            operator ++();

            COMSTL_ASSERT(is_valid());

            return r;
        }

        /// Returns the value represented by the current iteration position
        reference operator *()
        {
            COMSTL_ASSERT(is_valid());
            COMSTL_MESSAGE_ASSERT("Attempting to dereference an invalid iterator", (NULL != m_ctxt && !m_ctxt->empty()));

            return m_ctxt->current();
        }

        /// Returns the value represented by the current iteration position
        pointer operator ->()
        {
            COMSTL_ASSERT(is_valid());
            COMSTL_MESSAGE_ASSERT("Attempting to dereference an invalid iterator", (NULL != m_ctxt && !m_ctxt->empty()));

            return &m_ctxt->current();
        }

    private:
        static bool_type equal_(class_type const& lhs, class_type const& rhs, STLSOFT_NS_QUAL_STD(input_iterator_tag))
        {
            // The only valid comparison is when they both represent the end values.
            return lhs.is_end_point() && rhs.is_end_point();
        }
        static bool_type equal_(class_type const& lhs, class_type const& rhs, STLSOFT_NS_QUAL_STD(forward_iterator_tag))
        {
            // The iterators can be equal under two conditions:
            //
            // 1. The end iterator (as in the case for input iterators)
            // 2. Both have a context, and the index of both contexts are the same
            //
            // otherwise:
            //
            // 3. They're not equal

            if (lhs.is_end_point())
            {
                return rhs.is_end_point(); // 1 or 3
            }
            else
            {
                if (rhs.is_end_point())
                {
                    return false; // 3
                }
                else
                {
                    COMSTL_ASSERT(NULL != lhs.m_ctxt);
                    COMSTL_ASSERT(NULL != rhs.m_ctxt);

                    return lhs.m_ctxt->index() == rhs.m_ctxt->index(); // 2 or 3
                }
            }
        }
    public:

        /// Evaluates whether \c this and \c rhs are equivalent
        bool_type equal(class_type const& rhs) const
        {
            COMSTL_ASSERT(is_valid());

            return class_type::equal_(*this, rhs, iterator_tag_type());
        }
        /// Evaluates whether \c this and \c rhs are equivalent
        bool_type operator ==(class_type const& rhs) const
        {
            COMSTL_ASSERT(is_valid());

            return this->equal(rhs);
        }
        /// Evaluates whether \c this and \c rhs are not equivalent
        bool_type operator !=(class_type const& rhs) const
        {
            COMSTL_ASSERT(is_valid());

            return !this->equal(rhs);
        }
    /// @}

    /// \name Invariant
    /// @{
    private:
        bool_type is_valid() const
        {
            return (NULL == m_ctxt) || m_ctxt->is_valid();
        }
    /// @}

    /// \name Implementation
    /// @{
    private:
        bool_type is_end_point() const
        {
            return NULL == m_ctxt || m_ctxt->empty();
        }
    /// @}

    /// \name Members
    /// @{
    private:
        enumeration_context *m_ctxt;
    /// @}
    };
    /// The non-mutating (const) iterator type
    typedef iterator                                                            const_iterator;

public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    ///
    /// \note The first time this is called, the iterated range represented by [begin(), end())
    /// directly uses that of the enumerator interface pointer passed to the constructor. When
    /// specialised with cloneable_cloning_policy and forward_cloning_policy policies, all
    /// subsequent calls to begin() will use a cloned enumerator instance, retrieved via
    /// I::Clone(). If the enumerator instance is not cloneable, then begin() will throw an
    /// instance of clone_failure on all subsequent invocations.
    iterator begin() const
    {
        COMSTL_ASSERT(is_valid());

        interface_type* en = NULL;

        if (NULL != m_enumerator)
        {
            en = m_enumerator;
        }
        else
        {
            if (!m_bFirst)
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                STLSOFT_THROW_X(clone_failure(E_NOTIMPL));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                return end();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                en = m_root;
            }
        }

        COMSTL_ASSERT(NULL != en);

        return iterator(en, m_quanta, m_bFirst);
    }
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    iterator end() const
    {
        COMSTL_ASSERT(is_valid());

        return iterator();
    }
/// @}

/// \name Attributes
/// @{
public:
    static size_type quanta()
    {
        return retrievalQuanta;
    }
/// @}

/// \name Invariant
/// @{
private:
    bool_type is_valid() const
    {
        if (NULL == m_root)
        {
            return false;
        }

        return true;
    }
/// @}

// Implementation
private:
    static size_type validate_quanta_(size_type quanta)
    {
        COMSTL_MESSAGE_ASSERT("Cannot set a quantum that exceeds the value specified in the template specialisation", quanta <= retrievalQuanta); // Could have named these things better!

        if (0 == quanta ||
            quanta > retrievalQuanta)
        {
            quanta = retrievalQuanta;
        }

        return quanta;
    }

// Members
private:
    interface_type*         m_root;
    interface_type*         m_enumerator;
    size_type const         m_quanta;
    ss_mutable_k bool_type  m_bFirst;
};


/* /////////////////////////////////////////////////////////////////////////
 * compiler compatibility
 */

#ifdef STLSOFT_COMPILER_IS_BORLAND
# undef retrievalQuanta
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace comstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATOR_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

