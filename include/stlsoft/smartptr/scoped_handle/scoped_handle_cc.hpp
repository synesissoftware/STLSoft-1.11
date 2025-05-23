/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/smartptr/scoped_handle_cc.hpp (evolved from MLResPtr.h, ::SynesisStd)
 *
 * Purpose: scoped_handle - specialisable RAII class for arbitrary resource
 *          types.
 *
 * Created: 1st November 1994
 * Updated: 20th March 2025
 *
 * Thanks:  Adi Shavit, for requesting the indirect functionality
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1994-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/smartptr/scoped_handle/scoped_handle_cc.hpp
 *
 * \brief [C++] Definition of the stlsoft::scoped_handle smart
 *   pointer class template
 *   (\ref group__library__SmartPointer "Smart Pointer" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_SCOPED_HANDLE_HPP_SCOPED_HANDLE_CC
#define STLSOFT_INCL_STLSOFT_SMARTPTR_SCOPED_HANDLE_HPP_SCOPED_HANDLE_CC

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SMARTPTR_SCOPED_HANDLE_HPP_SCOPED_HANDLE_CC_MAJOR      5
# define STLSOFT_VER_STLSOFT_SMARTPTR_SCOPED_HANDLE_HPP_SCOPED_HANDLE_CC_MINOR      7
# define STLSOFT_VER_STLSOFT_SMARTPTR_SCOPED_HANDLE_HPP_SCOPED_HANDLE_CC_REVISION   3
# define STLSOFT_VER_STLSOFT_SMARTPTR_SCOPED_HANDLE_HPP_SCOPED_HANDLE_CC_EDIT       694
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

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# include <stlsoft/smartptr/scoped_handle/scoped_handle_borland_.hpp>
#else /* ? compiler */

/* /////////////////////////////////////////////////////////////////////////
 * compiler warnings
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400

# pragma warning(push)
# pragma warning(disable : 4191)
#endif /* compiler */


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

template <ss_typename_param_k H>
struct H_holder
{
/// \name Member Types
/// @{
public:
    typedef H                                               resource_type;
    typedef H                                               handle_type;
    typedef H_holder<H>                                     class_type;
/// @}

/// \name Construction
/// @{
public:
    H_holder(H h)
        : bPointer(false)
    {
        this->u.h = h;
    }
    H_holder(H* ph)
        : bPointer(true)
    {
        this->u.ph = ph;
    }

private:
    H_holder(class_type const&);
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Operations
/// @{
public:
    H   get() const
    {
        return bPointer ? *u.ph : u.h;
    }
    void set(H h)
    {
        (bPointer ? *u.ph : u.h) = h;
    }
/// @}

/// \name Member Variables
/// @{
public:
    union
    {
        H   h;
        H*  ph;
    }           u;
    bool const  bPointer;
/// @}
};

# ifdef STLSOFT_CF_CDECL_SUPPORTED
template<
    ss_typename_param_k H
,   ss_typename_param_k R
>
struct function_translator_cdecl
{
private:
    typedef void                            (STLSOFT_CDECL* degenerate_function_type)();    // C++-98; 5.2.10;6
public:
    typedef R                               (STLSOFT_CDECL* function_type)(H);
    typedef R                               (STLSOFT_CDECL* indirect_function_type)(H*);
    typedef H_holder<H>                                     holder_type;

    static void translate(holder_type& h, degenerate_function_type pv)
    {
        function_type   fn  =   reinterpret_cast<function_type>(pv);

        STLSOFT_ASSERT(!h.bPointer);
        STLSOFT_MESSAGE_ASSERT("function pointer must not be NULL", NULL != fn);

        fn(h.u.h);
    }

    static void translate_indirect(holder_type& h, degenerate_function_type pv)
    {
        indirect_function_type  fn  =   reinterpret_cast<indirect_function_type>(pv);

        STLSOFT_ASSERT(h.bPointer);
        STLSOFT_MESSAGE_ASSERT("function pointer must not be NULL", NULL != fn);

        fn(h.u.ph);
    }
};
# endif /* STLSOFT_CF_CDECL_SUPPORTED */

# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template<
    ss_typename_param_k H
,   ss_typename_param_k R
>
struct function_translator_fastcall
{
private:
    typedef void                         (STLSOFT_CDECL*    degenerate_function_type)();
public:
    typedef R                            (STLSOFT_FASTCALL* function_type)(H);
    typedef R                            (STLSOFT_FASTCALL* indirect_function_type)(H*);
    typedef H_holder<H>                                     holder_type;

    static void translate(holder_type& h, degenerate_function_type pv)
    {
        function_type   fn  =   reinterpret_cast<function_type>(pv);

        STLSOFT_ASSERT(!h.bPointer);
        STLSOFT_MESSAGE_ASSERT("function pointer must not be NULL", NULL != fn);

        fn(h.u.h);
    }

    static void translate_indirect(holder_type& h, degenerate_function_type pv)
    {
        indirect_function_type  fn  =   reinterpret_cast<indirect_function_type>(pv);

        STLSOFT_ASSERT(h.bPointer);
        STLSOFT_MESSAGE_ASSERT("function pointer must not be NULL", NULL != fn);

        fn(h.u.ph);
    }
};
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template<
    ss_typename_param_k H
,   ss_typename_param_k R
>
struct function_translator_stdcall
{
private:
    typedef void                          (STLSOFT_CDECL*   degenerate_function_type)();
public:
    typedef R                             (STLSOFT_STDCALL* function_type)(H);
    typedef R                             (STLSOFT_STDCALL* indirect_function_type)(H*);
    typedef H_holder<H>                                     holder_type;

    static void translate(holder_type& h, degenerate_function_type pv)
    {
        function_type   fn  =   reinterpret_cast<function_type>(pv);

        STLSOFT_ASSERT(!h.bPointer);
        STLSOFT_MESSAGE_ASSERT("function pointer must not be NULL", NULL != fn);

        fn(h.u.h);
    }

    static void translate_indirect(holder_type& h, degenerate_function_type pv)
    {
        indirect_function_type  fn  =   reinterpret_cast<indirect_function_type>(pv);

        STLSOFT_ASSERT(h.bPointer);
        STLSOFT_MESSAGE_ASSERT("function pointer must not be NULL", NULL != fn);

        fn(h.u.ph);
    }
};
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */

# ifdef STLSOFT_CF_CDECL_SUPPORTED
template <ss_typename_param_k R>
struct function_translator_cdecl_void
{
private:
    typedef void                            (STLSOFT_CDECL* degenerate_function_type)();    // C++-98; 5.2.10;6
public:
    typedef R                               (STLSOFT_CDECL* function_type)(void);

    static void translate(degenerate_function_type pv)
    {
        function_type   fn  =   reinterpret_cast<function_type>(pv);

        STLSOFT_MESSAGE_ASSERT("function pointer must not be NULL", NULL != fn);

        fn();
    }
};
# endif /* STLSOFT_CF_CDECL_SUPPORTED */

# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template <ss_typename_param_k R>
struct function_translator_fastcall_void
{
private:
    typedef void                            (STLSOFT_CDECL* degenerate_function_type)();
public:
    typedef R                            (STLSOFT_FASTCALL* function_type)(void);

    static void translate(degenerate_function_type pv)
    {
        function_type   fn  =   reinterpret_cast<function_type>(pv);

        STLSOFT_MESSAGE_ASSERT("function pointer must not be NULL", NULL != fn);

        fn();
    }
};
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template <ss_typename_param_k R>
struct function_translator_stdcall_void
{
private:
    typedef void                            (STLSOFT_CDECL* degenerate_function_type)();
public:
    typedef R                             (STLSOFT_STDCALL* function_type)(void);

    static void translate(degenerate_function_type pv)
    {
        function_type   fn  =   reinterpret_cast<function_type>(pv);

        STLSOFT_MESSAGE_ASSERT("function pointer must not be NULL", NULL != fn);

        fn();
    }
};
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** Provides automated scope-based cleanup of arbitrary resource types
 * without any memory allocation required to implement the generic support.
 *
 * \ingroup group__library__SmartPointer
 *
 * The template is specialised on the resource type (e.g. FILE*, int, void*)
 * and instances are initialised from a resource handle and the address of a
 * (single-parameter) cleanup function, as in:
 *
\code
 ::stlsoft::scoped_handle<void*>  h3(::malloc(100), ::free);
\endcode
 *
 * or:
 *
\code
 ::stlsoft::scoped_handle<int>    h1(::open("file.ext"), ::close);
\endcode
 *
 * or:
 *
\code
 FILE*                            file = ::fopen("file.ext", "r");
 ::stlsoft::scoped_handle<FILE*>  h2(file, ::fclose);
\endcode
 *
 * \note This class provides externally-initialised immutable-RAII (see
 * section 3.5 of Imperfect C++; http://imperfectcplusplus.com/). The
 * managed resource must be provided in the constructor, and the managing
 * instance cannot be set to manage another resource. However, there is a
 * nod to convenience in so far as there is a detach() method, which can be
 * used to clear the resource from the managing instance and return it to
 * the calling context.
 */

template <ss_typename_param_k H>
class scoped_handle
{
/// \name Types
/// @{
private:
    typedef void                            (STLSOFT_CDECL* degenerate_function_type)();
    typedef H_holder<H>                                     holder_type;
public:
    /// The resource type
    typedef H                                               resource_type;
    /// The handle type
    typedef H                                               handle_type;
    /// The instantiation of the type
    typedef scoped_handle<H>                                class_type;
/// @}

/// \name Construction
/// @{
public:
#ifdef STLSOFT_CF_CDECL_SUPPORTED
# if !defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
     defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Construct from a resource handle and a clean-up function with void return type
    scoped_handle(  resource_type   h
                ,   void            (STLSOFT_CDECL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_hh(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_cdecl<H, void>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }

    /// Construct from a resource handle and an indirect clean-up function with void return type
    scoped_handle(  resource_type*  ph
                ,   void            (STLSOFT_CDECL *f)(resource_type*)
                ,   resource_type   hNull = 0)
        : m_hh(ph)
        , m_hNull(hNull)
        , m_tfn(&function_translator_cdecl<H, void>::translate_indirect)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* !STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

# if defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Construct from a resource handle and a clean-up function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  resource_type   h
                ,   R               (STLSOFT_CDECL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_hh(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_cdecl<H, R>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
    /// Construct from a resource handle and an indirect clean-up function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  resource_type*  ph
                ,   R               (STLSOFT_CDECL *f)(resource_type*)
                ,   resource_type   hNull = 0)
        : m_hh(ph)
        , m_hNull(hNull)
        , m_tfn(&function_translator_cdecl<H, R>::translate_indirect)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED
# if !defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
     defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Construct from a resource handle and a clean-up "fastcall" function with void return type
    scoped_handle(  resource_type   h
                ,   void            (STLSOFT_FASTCALL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_hh(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_fastcall<H, void>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
    /// Construct from a resource handle and an indirect clean-up "fastcall" function with void return type
    scoped_handle(  resource_type   h
                ,   void            (STLSOFT_FASTCALL *f)(resource_type *)
                ,   resource_type   hNull = 0)
        : m_hh(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_fastcall<H, void>::translate_indirect)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* !STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

# if defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Construct from a resource handle and a clean-up "fastcall" function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  resource_type   h
                ,   R               (STLSOFT_FASTCALL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_hh(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_fastcall<H, R>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
    /// Construct from a resource handle and an indirect clean-up "fastcall" function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  resource_type*  ph
                ,   R               (STLSOFT_FASTCALL *f)(resource_type*)
                ,   resource_type   hNull = 0)
        : m_hh(ph)
        , m_hNull(hNull)
        , m_tfn(&function_translator_fastcall<H, R>::translate_indirect)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */


#ifdef STLSOFT_CF_STDCALL_SUPPORTED
# if !defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
     defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Construct from a resource handle and a clean-up "stdcall" function with void return type
    scoped_handle(  resource_type   h
                ,   void            (STLSOFT_STDCALL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_hh(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_stdcall<H, void>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
    /// Construct from a resource handle and an indirect clean-up "stdcall" function with void return type
    scoped_handle(  resource_type*  ph
                ,   void            (STLSOFT_STDCALL *f)(resource_type*)
                ,   resource_type   hNull = 0)
        : m_hh(ph)
        , m_hNull(hNull)
        , m_tfn(&function_translator_stdcall<H, void>::translate_indirect)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* !STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

# if defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Construct from a resource handle and a clean-up "stdcall" function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  resource_type   h
                ,   R               (STLSOFT_STDCALL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_hh(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_stdcall<H, R>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
    /// Construct from a resource handle and an indirect clean-up "stdcall" function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  resource_type*  ph
                ,   R               (STLSOFT_STDCALL *f)(resource_type*)
                ,   resource_type   hNull = 0)
        : m_hh(ph)
        , m_hNull(hNull)
        , m_tfn(&function_translator_stdcall<H, R>::translate_indirect)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

    /// Constructs an instance by taking over the state of the
    /// instance \c rhs
    ///
    /// \param rhs The instance whose state will be taken over. Upon return
    ///   \c rhs will be <code>empty()</code>
    scoped_handle(class_type&& rhs) STLSOFT_NOEXCEPT
        : m_hh(rhs.detach())
        , m_hNull(rhs.m_hNull)
        , m_tfn(rhs.m_tfn)
        , m_fn(rhs.m_fn)
    {}
#endif /* STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */

    /// "Releases" the managed resource.
    ///
    /// Invokes the cleanup function, unless close() or detach() have
    /// already been called
    ~scoped_handle() STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("Invariant violation: function pointer must not be NULL", NULL != m_fn);

        if (!empty())
        {
            m_tfn(m_hh, m_fn);
        }
    }

private:
    scoped_handle(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Attributes
/// @{
public:
    /// Indicates whether the instance holds a non-"null" resource
    bool empty() const STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("Invariant violation: function pointer must not be NULL", NULL != m_fn);

        return get_null_value_() == m_hh.get();
    }
/// @}

/// \name Operations
/// @{
public:
    /// Closes the handle immediately
    ///
    /// \note Calling this method more than once has no effect.
    void close()
    {
        STLSOFT_MESSAGE_ASSERT("Invariant violation: function pointer must not be NULL", NULL != m_fn);

        if (!empty())
        {
            m_tfn(m_hh, m_fn);

            m_hh.set(get_null_value_());
        }
    }

    /// Detaches the resource, and returns it to the caller.
    ///
    /// \remarks Calling this method removes the resource from the managing
    ///   instance, so it will not be automatically closed.
    resource_type detach() STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("Invariant violation: function pointer must not be NULL", NULL != m_fn);

        resource_type   h   =   m_hh.get();

        m_hh.set(get_null_value_());

        return h;
    }
/// @}

/// \name Accessors
/// @{
public:
    /// Provides the bare resource handle to the caller. Does not
    ///   detach the handle from the managing instance.
    ///
    /// \deprecated Deprecated in favour of get()
    resource_type handle() const STLSOFT_NOEXCEPT
    {
#if defined(STLSOFT_COMPILER_IS_WATCOM)
        return (resource_type)(m_hh.get());
#else /* ? compiler */
        return const_cast<resource_type>(m_hh.get());
#endif /* compiler */
    }
    /// Provides the bare resource handle to the caller. Does not detach the
    /// handle from the managing instance.
    resource_type get() const STLSOFT_NOEXCEPT
    {
        return const_cast<class_type&>(*this).m_hh.get();
    }
/// @}

/// \name Implementation
/// @{
private:
    resource_type get_null_value_() const
    {
        return m_hNull;
    }
/// @}

/// \name Members
/// @{
private:
    holder_type                 m_hh;                                           //!< The handle to the managed resource
    resource_type /* const */   m_hNull;                                        //!< The value for the null handle
    void                      (*m_tfn)(holder_type&, degenerate_function_type); //!< The function translator function
    degenerate_function_type    m_fn;                                           //!< The actual resource release function
/// @}
};


// scoped_handle<void>

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
class scoped_handle<void>
{
/// \name Types
/// @{
private:
    typedef void                            (STLSOFT_CDECL* degenerate_function_type)();
public:
    /// The resource type
    typedef void                                            resource_type;
    /// The handle type
    typedef void                                            handle_type;
    /// The instantiation of the type
    typedef scoped_handle<void>                             class_type;
/// @}

/// \name Construction
/// @{
public:
#ifdef STLSOFT_CF_CDECL_SUPPORTED
# if !defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
     defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Construct from a resource handle and a clean-up function with void return type
    scoped_handle(  void            (STLSOFT_CDECL *f)())
        : m_bInvoked(false)
        , m_tfn(&function_translator_cdecl_void<void>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* !STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

# if defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Construct from a resource handle and a clean-up function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  R               (STLSOFT_CDECL *f)())
        : m_bInvoked(false)
        , m_tfn(&function_translator_cdecl_void<R>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
#endif /* STLSOFT_CF_CDECL_SUPPORTED */

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED
# if !defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
     defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Construct from a resource handle and a clean-up "fastcall" function with void return type
    scoped_handle(  void            (STLSOFT_FASTCALL *f)())
        : m_bInvoked(false)
        , m_tfn(&function_translator_fastcall_void<void>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* !STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

# if defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Construct from a resource handle and a clean-up "fastcall" function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  R               (STLSOFT_FASTCALL *f)())
        : m_bInvoked(false)
        , m_tfn(&function_translator_fastcall_void<R>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */


#ifdef STLSOFT_CF_STDCALL_SUPPORTED
# if !defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
     defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Construct from a resource handle and a clean-up "stdcall" function with void return type
    scoped_handle(  void            (STLSOFT_STDCALL *f)())
        : m_bInvoked(false)
        , m_tfn(&function_translator_stdcall_void<void>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* !STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

# if defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Construct from a resource handle and a clean-up "stdcall" function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  R               (STLSOFT_STDCALL *f)())
        : m_bInvoked(false)
        , m_tfn(&function_translator_stdcall_void<R>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {
        STLSOFT_MESSAGE_ASSERT("Precondition violation: cannot initialise with a NULL function pointer", NULL != f);
    }
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

    /// Constructs an instance by taking over the state of the
    /// instance \c rhs
    ///
    /// \param rhs The instance whose state will be taken over. Upon return
    ///   \c rhs will be <code>empty()</code>
    scoped_handle(class_type&& rhs) STLSOFT_NOEXCEPT
        : m_bInvoked(rhs.m_bInvoked)
        , m_tfn(rhs.m_tfn)
        , m_fn(rhs.m_fn)
    {
        rhs.detach();
    }
#endif /* STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */

    /// "Releases" the managed resource.
    ///
    /// Invokes the cleanup function, unless close() or detach() have
    /// already been called
    ~scoped_handle() STLSOFT_NOEXCEPT
    {
        close();
    }

private:
    scoped_handle(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Attributes
/// @{
public:
    /// Indicates whether the instance holds a non-"null" resource
    bool empty() const STLSOFT_NOEXCEPT
    {
        return m_bInvoked;
    }
/// @}

/// \name Operations
/// @{
public:
    /// Closes the handle immediately
    ///
    /// \note Calling this method more than once has no effect.
    void close()
    {
        if (!empty())
        {
            m_tfn(m_fn);
            m_bInvoked = true;
        }
    }

    /// Detaches the resource, and returns it to the caller.
    ///
    /// \remarks Calling this method removes the resource from the managing
    ///   instance, so it will not be automatically closed.
    resource_type detach() STLSOFT_NOEXCEPT
    {
        m_bInvoked = true;
    }
/// @}

/// \name Accessors
/// @{
public:
    /// Provides the bare resource handle to the caller. Does not
    ///   detach the handle from the managing instance.
    ///
    /// \deprecated Deprecated in favour of get()
    resource_type handle() const STLSOFT_NOEXCEPT
    {
    }
    /// Provides the bare resource handle to the caller. Does not detach the
    /// handle from the managing instance.
    resource_type get() const STLSOFT_NOEXCEPT
    {
    }
/// @}

/// \name Members
/// @{
private:
    ss_bool_t                   m_bInvoked;                         //!< Indicates whether the cleanup function has been invoked
    void                      (*m_tfn)(degenerate_function_type);   //!< The function translator function
    degenerate_function_type    m_fn;                               //!< The actual resource release function
/// @}
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template <ss_typename_param_k H>
inline
void
swap(
    scoped_handle<H>& lhs
,   scoped_handle<H>& rhs
) STLSOFT_NOEXCEPT
{
    lhs.swap(rhs);
}


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

template <ss_typename_param_k H>
inline
#if defined(STLSOFT_COMPILER_IS_WATCOM)
H
#else /* ? compiler */
ss_typename_type_ret_k scoped_handle<H>::handle_type
#endif /* compiler */
get_handle(
    scoped_handle<H> const& h
) STLSOFT_NOEXCEPT
{
    return h.get();
}

/** is_null shim
 *
 * \ingroup group__library__SmartPointer
 */
template <ss_typename_param_k H>
inline
bool
is_null(
    scoped_handle<H> const& h
) STLSOFT_NOEXCEPT
{
    return h.empty();
}


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
    template <ss_typename_param_k H>
    inline
    void
    swap(
        STLSOFT_NS_QUAL(scoped_handle)<H>& lhs
    ,   STLSOFT_NS_QUAL(scoped_handle)<H>& rhs
    )
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* ? compiler */


/* /////////////////////////////////////////////////////////////////////////
 * compiler warnings
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400

# pragma warning(pop)
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_SCOPED_HANDLE_HPP_SCOPED_HANDLE_CC */

/* ///////////////////////////// end of file //////////////////////////// */

