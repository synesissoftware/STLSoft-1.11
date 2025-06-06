/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/memory/auto_destructor.hpp
 *
 * Purpose: Contains the auto_destructor and auto_array_destructor template
 *          classes.
 *
 * Created: 1st November 1994
 * Updated: 20th March 2025
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


/** \file stlsoft/memory/auto_destructor.hpp
 *
 * \brief [C++] Definition of the stlsoft::auto_destructor and
 *  stlsoft::auto_array_destructor class templates
 *   (\ref group__library__Memory "Memory" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_DESTRUCTOR
#define STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_DESTRUCTOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_AUTO_DESTRUCTOR_MAJOR       5
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_AUTO_DESTRUCTOR_MINOR       3
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_AUTO_DESTRUCTOR_REVISION    1
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_AUTO_DESTRUCTOR_EDIT        95
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

#ifdef _STLSOFT_RETURN_VALUE_DESTRUCTOR_ENABLE_DIRECT_CTOR
# define STLSOFT_RETURN_VALUE_DESTRUCTOR_ENABLE_DIRECT_CTOR
#endif /* _STLSOFT_RETURN_VALUE_DESTRUCTOR_ENABLE_DIRECT_CTOR */

#ifdef _STLSOFT_RETURN_VALUE_DESTRUCTOR_DISABLE_UNUSED_ASSERT
# define STLSOFT_RETURN_VALUE_DESTRUCTOR_DISABLE_UNUSED_ASSERT
#endif /* _STLSOFT_RETURN_VALUE_DESTRUCTOR_DISABLE_UNUSED_ASSERT */


/* /////////////////////////////////////////////////////////////////////////
 * warnings
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1300
# pragma warning(disable : 4284)
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
class auto_destructor;

template <ss_typename_param_k T>
class return_value_destructor;

template <ss_typename_param_k T>
class auto_array_destructor;

template <ss_typename_param_k T>
class return_value_array_destructor;

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** A simple proxy class that supports the movement of pointers
 *    between the various destructor classes.
 *
 * \ingroup group__library__Memory
 *
 * \see stlsoft::auto_destructor |
 *      stlsoft::return_value_destructor |
 *      stlsoft::auto_array_destructor |
 *      stlsoft::return_value_array_destructor
 */
template<   ss_typename_param_k T
        ,   ss_typename_param_k U
        >
struct move_proxy
{
    move_proxy(T *value)
        : m_value(value)
    {}

    T* m_value;
};


// class auto_destructor
/** This class acts as an automatic frame scope variable that manages
 *   heap-allocated object instances.
 *
 * \ingroup group__library__Memory
 *
 * \param T The value type
 *
 * A heap-allocated resource to be managed is placed into an instance of
 * \link stlsoft::auto_destructor auto_destructor\endlink
 * in its constructor, as in:
\code
  {
    stlsoft::auto_destructor<MyClass>  adi(new MyClass(1, 2));

    . . .
  } // The MyClass instance is deleted here
\endcode
 *
 * The horrendous, and widely lamented, problems with
 * <code>std::auto_ptr</code> are avoided by proscribing copy
 * operations. Hence:
\code
    stlsoft::auto_destructor<MyClass>  adi(new MyClass(1, 2));
    stlsoft::auto_destructor<MyClass>  adi2(adi); // Compile error!
\endcode
 *
 * But resources can be returned out of
 * \link stlsoft::auto_destructor auto_destructor\endlink
 * instances from functions by virtue of
 * \link stlsoft::return_value_destructor return_value_destructor\endlink,
 * as in:
 *
\code
  stlsoft::return_value_destructor<MyClass> f(int i, int j)
  {
    stlsoft::auto_destructor<MyClass>  adi(new MyClass(i, j));

    . . .
  } // The MyClass instance is deleted here

  stlsoft::auto_destructor<MyClass>  adi2 = f(1, 2);
\endcode
 *
 * In this way, the resource is completely safely managed, without there
 * being any unfortunate side-effects (as is the case with
 * <code>std::auto_ptr</code>).
 *
 * \see stlsoft::return_value_destructor
 */
template <ss_typename_param_k T>
class auto_destructor
{
/// \name Types
/// @{
public:
    /// The value type
    typedef T                                               value_type;
    /// The current specialisation of the type
    typedef auto_destructor<T>                              class_type;
    /// The return value type
    typedef return_value_destructor<T>                      return_value_type;
private:
    /// The proxy type
    typedef move_proxy<T, return_value_type>                proxy_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs from the pointer to an instance whose lifetime will be managed
    ss_explicit_k auto_destructor(value_type* t)
        : m_value(t)
    {}
#if 0
    /// Move constructor
    auto_destructor(return_value_type& rhs)
        : m_value(rhs.detach())
    {}
#endif /* 0 */
    /// Proxy move constructor
    auto_destructor(proxy_type rhs)
        : m_value(rhs.m_value)
    {}
    /// Destroys the managed instance
    ~auto_destructor() STLSOFT_NOEXCEPT
    {
        delete m_value;
    }
private:
    auto_destructor(class_type const& rhs) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Operations
/// @{
public:
    /// Detaches the managed instance from the auto_destructor and returns a pointer to it to the caller
    ///
    /// \note The caller becomes responsible for destroying the instance.
    value_type* detach() STLSOFT_NOEXCEPT
    {
        value_type* t = m_value;

        m_value = ss_nullptr_k;

        return t;
    }
/// @}

/// \name Accessors
/// @{
public:
    /// Implicit conversion to pointer to the managed instance
    value_type* operator ->()
    {
        return m_value;
    }
    /// Implicit conversion to pointer-to-const to the managed instance
    value_type const* operator ->() const
    {
        return m_value;
    }
    /// Returns the pointer
    ///
    /// \deprecated This function will be removed in a future release. Users
    ///   should instead invoke get()
    value_type* get_ptr() const STLSOFT_NOEXCEPT
    {
        return get();
    }
    /// Returns the pointer
    value_type* get() const STLSOFT_NOEXCEPT
    {
        return m_value;
    }
/// @}

/// \name Members
/// @{
private:
    value_type* m_value;
/// @}
};

// class auto_array_destructor
/** This class acts as an automatic frame scope variable that manages
 *   heap-allocated object arrays.
 *
 * \ingroup group__library__Memory
 *
 * \param T The value type
 *
 * A detailed explanation of the use of resource management is given for
 * stlsoft::auto_destructor. The same explanation applies directly to
 * auto_array_destructor, substituting
 * \link stlsoft::auto_array_destructor auto_array_destructor\endlink
 * for
 * \link stlsoft::auto_destructor auto_destructor\endlink,
 * \link stlsoft::return_value_destructor return_value_destructor\endlink
 * for
 * \link stlsoft::return_value_array_destructor return_value_array_destructor\endlink,
 * and
 * vector <code>new</code> for scalar <code>new</code>.
 *
 * \see stlsoft::return_value_array_destructor
 */
template <ss_typename_param_k T>
class auto_array_destructor
{
/// \name Types
/// @{
public:
    /// The value type
    typedef T                                               value_type;
    /// The current specialisation of the type
    typedef auto_array_destructor<T>                        class_type;
    /// The return value type
    typedef return_value_array_destructor<T>                return_value_type;
    /// The size type
    typedef STLSOFT_NS_QUAL(ss_size_t)                      size_type;
private:
    /// The proxy type
    typedef move_proxy<T, return_value_type>                proxy_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs from the pointer to the array whose lifetimes will be managedd
    ss_explicit_k auto_array_destructor(value_type t[])
        : m_value(t)
    {}
#if 0
    /// Move constructor
    auto_array_destructor(return_value_type& rhs)
        : m_value(rhs.detach())
    {}
#endif /* 0 */
    /// Proxy move constructor
    auto_array_destructor(proxy_type rhs)
        : m_value(rhs.m_value)
    {}
    /// Destroys the managed array
    ~auto_array_destructor() STLSOFT_NOEXCEPT
    {
        delete [] m_value;
    }
private:
    auto_array_destructor(class_type const& rhs) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Operations
/// @{
public:
    /// Detaches the managed instance from the auto_array_destructor and returns a pointer to it to the caller
    ///
    /// \note The caller becomes responsible for destroying the instance.
    value_type* detach() STLSOFT_NOEXCEPT
    {
        value_type* t = m_value;

        m_value = ss_nullptr_k;

        return t;
    }
/// @}

/// \name Accessors
/// @{
public:
    /// Implicit conversion to pointer to the managed instance
    value_type* operator ->()
    {
        return m_value;
    }
    /// Implicit conversion to pointer-to-const to the managed instance
    value_type const* operator ->() const
    {
        return m_value;
    }
    /// Returns the pointer
    ///
    /// \deprecated This function will be removed in a future release. Users
    ///   should instead invoke get()
    value_type* get_ptr() const STLSOFT_NOEXCEPT
    {
        return get();
    }
    /// Returns the pointer
    value_type* get() const STLSOFT_NOEXCEPT
    {
        return m_value;
    }

    /// Obtains a mutating reference to the given element
    ///
    /// \param index The 0-based index of the element within the array
    ///   passed to the constructor. NOTE: this is not checked
    ///
    /// \pre index is in the range [0, array-size)
    value_type& operator [](size_type index)
    {
        STLSOFT_ASSERT(ss_nullptr_k != get());

        return get()[index];
    }

    /// Obtains a non-mutating reference to the given element
    ///
    /// \param index The 0-based index of the element within the array
    ///   passed to the constructor. NOTE: this is not checked
    ///
    /// \pre index is in the range [0, array-size)
    value_type const& operator [](size_type index) const
    {
        STLSOFT_ASSERT(ss_nullptr_k != get());

        return get()[index];
    }
/// @}

/// \name Members
/// @{
private:
    value_type* m_value;
/// @}
};


// class return_value_destructor
/** This class acts as a return-value scope variable that manages
 *   heap-allocated object instances.
 *
 * \ingroup group__library__Memory
 *
 * \param T The value type
 *
 * \see stlsoft::auto_destructor
 */
template <ss_typename_param_k T>
class return_value_destructor
{
/// \name Types
/// @{
public:
    /// The value type
    typedef T                                               value_type;
    /// The current specialisation of the type
    typedef return_value_destructor<T>                      class_type;
    /// The auto type
    typedef auto_destructor<T>                              auto_type;
private:
    /// The proxy type
    typedef move_proxy<T, class_type>                       proxy_type;
/// @}

/// \name Construction
/// @{
public:
#ifdef STLSOFT_RETURN_VALUE_DESTRUCTOR_ENABLE_DIRECT_CTOR
    /// Constructs from the pointer to an instance whose lifetime will be managedd
    return_value_destructor(value_type* pt)
        : m_value(pt)
    {}
#endif /* STLSOFT_RETURN_VALUE_DESTRUCTOR_ENABLE_DIRECT_CTOR */
    /// Construct from an auto_destructor<T>, transferring the managed instance from it
    return_value_destructor(auto_type& rhs) // NOTE: not explicit
        : m_value(rhs.detach())
    {}
    /// Move constructor
    return_value_destructor(class_type& rhs)
        : m_value(rhs.detach())
    {}
    /// Proxy move constructor
    return_value_destructor(proxy_type rhs)
        : m_value(rhs.m_value)
    {}
    /// Destroys the managed instance
    ~return_value_destructor() STLSOFT_NOEXCEPT
    {
        // This fires a report if value is non-zero, which indicates that
        // the return value had not been used. This is arguably ok since this
        // only ever happens in debug builds (what would be the point in
        // including in a release build?), so its violation of the rules on
        // no-throw destructors can be forgiven.

#ifndef STLSOFT_RETURN_VALUE_DESTRUCTOR_DISABLE_UNUSED_ASSERT
# if defined(STLSOFT_COMPILER_IS_WATCOM)
        STLSOFT_ASSERT(m_value == ss_nullptr_k);
# else /* ? compiler */
        STLSOFT_MESSAGE_ASSERT("This return value was not used", m_value == ss_nullptr_k);
# endif /* compiler */
#endif /* !STLSOFT_RETURN_VALUE_DESTRUCTOR_DISABLE_UNUSED_ASSERT */

        delete m_value;
    }
    /// Proxy conversion operator
    operator proxy_type()
    {
        return proxy_type(detach());
    }
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Operations
/// @{
private:
    friend class auto_destructor<T>;

    /// Detaches the managed instance from the return_value_destructor and returns a pointer to it to the caller
    ///
    /// \note The caller becomes responsible for destroying the instance.
    value_type* detach() STLSOFT_NOEXCEPT
    {
        value_type* t = m_value;

        m_value = ss_nullptr_k;

        return t;
    }
/// @}

/// \name Members
/// @{
private:
    value_type* m_value;
/// @}
};

// class return_value_array_destructor
/** This class acts as a return-value scope variable that manages
 *   heap-allocated object arrays.
 *
 * \ingroup group__library__Memory
 *
 * \param T The value type
 *
 * \see stlsoft::auto_array_destructor
 */
template <ss_typename_param_k T>
class return_value_array_destructor
{
/// \name Types
/// @{
public:
    /// The value type
    typedef T                                           value_type;
    /// The current specialisation of the type
    typedef return_value_array_destructor<T>            class_type;
    /// The auto type
    typedef auto_array_destructor<T>                    auto_type;
private:
    /// The proxy type
    typedef move_proxy<T, class_type>                   proxy_type;
/// @}

/// \name Construction
/// @{
public:
#ifdef STLSOFT_RETURN_VALUE_DESTRUCTOR_ENABLE_DIRECT_CTOR
    /// Constructs from the pointer to the array whose lifetimes will be managedd
    ss_explicit_k return_value_array_destructor(value_type t[])
        : m_value(t)
    {}
#endif /* STLSOFT_RETURN_VALUE_DESTRUCTOR_ENABLE_DIRECT_CTOR */
    /// Constructs from an auto_array_destructor<T> instance, transferring the managed array from it
    return_value_array_destructor(auto_type& rhs) // NOTE: not explicit
        : m_value(rhs.detach())
    {}
#if 1
    /// Move constructor
    return_value_array_destructor(class_type& rhs)
        : m_value(rhs.detach())
    {}
#endif /* 0 */
    /// Proxy move constructor
    return_value_array_destructor(proxy_type rhs)
        : m_value(rhs.m_value)
    {}
    /// Destroys the managed array
    ~return_value_array_destructor() STLSOFT_NOEXCEPT
    {
        // This fires a report if value is non-zero, which indicates that
        // the return value had not been used. This is arguably ok since this
        // only ever happens in debug builds (what would be the point in
        // including in a release build?), so its violation of the rules on
        // no-throw destructors can be forgiven.

#ifndef _STLSOFT_RETURN_VALUE_DESTRUCTOR_DISABLE_UNUSED_ASSERT
# if defined(STLSOFT_COMPILER_IS_WATCOM)
        STLSOFT_ASSERT(m_value == ss_nullptr_k);
# else /* ? compiler */
        STLSOFT_MESSAGE_ASSERT("This return value was not used", m_value == ss_nullptr_k);
# endif /* compiler */
#endif /* !_STLSOFT_RETURN_VALUE_DESTRUCTOR_DISABLE_UNUSED_ASSERT */

        delete [] m_value;
    }
    /// Proxy conversion operator
    operator proxy_type()
    {
        return proxy_type(detach());
    }
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Operations
/// @{
private:
    friend class auto_array_destructor<T>;

    /// Detaches the managed instance from the return_value_array_destructor and returns a pointer to it to the caller
    ///
    /// \note The caller becomes responsible for destroying the instance.
    value_type* detach() STLSOFT_NOEXCEPT
    {
        value_type* t = m_value;

        m_value = ss_nullptr_k;

        return t;
    }
/// @}

/// \name Members
/// @{
private:
    value_type* m_value;
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/**
 * \ingroup group__concept__Shim__Attribute__get_ptr
 */
template <ss_typename_param_k T>
inline
T*
get_ptr(auto_destructor<T> const& ad) STLSOFT_NOEXCEPT
{
    return ad.get();
}

/**
 * \ingroup group__concept__Shim__Attribute__get_ptr
 */
template <ss_typename_param_k T>
inline
T*
get_ptr(return_value_destructor<T> const& ad) STLSOFT_NOEXCEPT
{
    return ad.get();
}

/**
 * \ingroup group__concept__Shim__Attribute__get_ptr
 */
template <ss_typename_param_k T>
inline
T*
get_ptr(auto_array_destructor<T> const& ad) STLSOFT_NOEXCEPT
{
    return ad.get();
}

/**
 * \ingroup group__concept__Shim__Attribute__get_ptr
 */
template <ss_typename_param_k T>
inline
T*
get_ptr(return_value_array_destructor<T> const& ad) STLSOFT_NOEXCEPT
{
    return ad.get();
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * warnings
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1300
# pragma warning(default: 4284)
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_DESTRUCTOR */

/* ///////////////////////////// end of file //////////////////////////// */

