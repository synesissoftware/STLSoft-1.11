/* /////////////////////////////////////////////////////////////////////////
 * File:    comstl/smartptr/interface_ptr.hpp (originally MLRelItf.h; ::SynesisCom)
 *
 * Purpose: Interface management helper classes.
 *
 * Created: 2nd November 1994
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


/** \file comstl/smartptr/interface_ptr.hpp
 *
 * \brief [C++] Definition of the comstl::interface_ptr smart
 *   pointer class template
 *   (\ref group__library__SmartPointer "Smart Pointer" Library).
 */

#ifndef COMSTL_INCL_COMSTL_SMARTPTR_HPP_INTERFACE_PTR
#define COMSTL_INCL_COMSTL_SMARTPTR_HPP_INTERFACE_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_SMARTPTR_HPP_INTERFACE_PTR_MAJOR     7
# define COMSTL_VER_COMSTL_SMARTPTR_HPP_INTERFACE_PTR_MINOR     4
# define COMSTL_VER_COMSTL_SMARTPTR_HPP_INTERFACE_PTR_REVISION  1
# define COMSTL_VER_COMSTL_SMARTPTR_HPP_INTERFACE_PTR_EDIT      517
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

#ifdef STLSOFT_PPF_pragma_message_SUPPORT
# pragma message("This file (comstl/smartptr/interface_ptr.hpp) is now obsolete. Include stlsoft/smartptr/ref_ptr.hpp and use stlsoft::ref_ptr<>")
#endif /* STLSOFT_PPF_pragma_message_SUPPORT */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_OPERATOR_BOOL
# include <stlsoft/util/operator_bool.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_OPERATOR_BOOL */
#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR
# include <stlsoft/smartptr/ref_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR */


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

/** [DEPRECATED] Manages a COM interface pointer, ensuring that it is released
 *
 * \deprecated Instead use stlsoft::ref_ptr
 *
 * \ingroup group__library__SmartPointer
 */
template <ss_typename_param_k T>
class interface_ptr
    : public STLSOFT_NS_QUAL(ref_ptr)<T>
{
/// \name Types
/// @{
private:
    typedef STLSOFT_NS_QUAL(ref_ptr)<T>                     parent_class_type;
public:
    typedef interface_ptr<T>                                class_type;

    typedef T                                               value_type;
    typedef value_type*                                     pointer;
    typedef value_type const*                               const_pointer;
    typedef value_type&                                     reference;
    typedef value_type const&                               const_reference;
/// @}

/// \name Construction
/// @{
public:
     interface_ptr();
     interface_ptr(pointer p, cs_bool_t bAddRef);
     interface_ptr(reference r, cs_bool_t bAddRef);
     interface_ptr(class_type const& rhs);
    ~interface_ptr() STLSOFT_NOEXCEPT;

    class_type& operator =(class_type const& rhs);
/// @}

/// \name Operations
/// @{
public:
    void    set(pointer p, cs_bool_t bAddRef);
    void    set(reference r, cs_bool_t bAddRef);
    void    release();
    void    release(cs_bool_t bDecRef /* = true */);
    pointer detach();
    void    swap(class_type& rhs);
/// @}

/// \name Comparison
/// @{
public:
    cs_bool_t operator ==(class_type const& rhs) const;
    cs_bool_t operator !=(class_type const& rhs) const;
/// @}

/// \name State
/// @{
private:
    STLSOFT_DEFINE_OPERATOR_BOOL_TYPES_T(class_type, operator_bool_generator_type, operator_bool_type);
public:
    operator operator_bool_type() const;

//    cs_bool_t operator !() const;
/// @}

/// \name Accessors
/// @{
public:
    pointer get_interface_ptr() const;
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template <ss_typename_param_k T>
inline void swap(interface_ptr<T>& lhs, interface_ptr<T>& rhs)
{
    lhs.swap(rhs);
}


/* /////////////////////////////////////////////////////////////////////////
 * deprecated shims
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
inline
cs_bool_t
is_empty(interface_ptr<T> const& p) STLSOFT_NOEXCEPT
{
    return NULL == p.get_interface_ptr();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/**
 * \ingroup group__concept__Shim__Attribute__get_ptr
 */
template <ss_typename_param_k T>
inline
T*
get_ptr(interface_ptr<T> const& p) STLSOFT_NOEXCEPT
{
    return p.get_interface_ptr();
}


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

// interface_ptr

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
inline void interface_ptr<T>::swap(interface_ptr<T>& rhs)
{
    parent_class_type::swap(rhs);
}

template <ss_typename_param_k T>
inline interface_ptr<T>::interface_ptr()
    : parent_class_type()
{}

template <ss_typename_param_k T>
inline interface_ptr<T>::interface_ptr(ss_typename_type_k interface_ptr<T>::pointer p, cs_bool_t bAddRef)
    : parent_class_type(p, bAddRef)
{}

template <ss_typename_param_k T>
inline interface_ptr<T>::interface_ptr(ss_typename_type_k interface_ptr<T>::reference r, cs_bool_t bAddRef)
    : parent_class_type(&r, bAddRef)
{}

template <ss_typename_param_k T>
inline interface_ptr<T>::interface_ptr(ss_typename_type_k interface_ptr<T>::class_type const& rhs)
    : parent_class_type(rhs)
{}

template <ss_typename_param_k T>
inline void interface_ptr<T>::release()
{
    parent_class_type::close();
}

template <ss_typename_param_k T>
inline void interface_ptr<T>::release(cs_bool_t bDecRef /* = true */)
{
    bDecRef ? parent_class_type::close() : static_cast<void>(parent_class_type::detach());
}

template <ss_typename_param_k T>
inline interface_ptr<T>::~interface_ptr() STLSOFT_NOEXCEPT
{
    release();
}

template <ss_typename_param_k T>
inline ss_typename_type_ret_k interface_ptr<T>::class_type& interface_ptr<T>::operator =(ss_typename_type_k interface_ptr<T>::class_type const& rhs)
{
    class_type   t(rhs);

    swap(t);

    return *this;
}

template <ss_typename_param_k T>
inline void interface_ptr<T>::set(ss_typename_type_k interface_ptr<T>::pointer p, cs_bool_t bAddRef)
{
    class_type   t(p, bAddRef);

    swap(t);
}

template <ss_typename_param_k T>
inline void interface_ptr<T>::set(ss_typename_type_k interface_ptr<T>::reference r, cs_bool_t bAddRef)
{
    COMSTL_MESSAGE_ASSERT("Attempting to dereference a null pointer", &r != NULL);

    class_type   t(&r, bAddRef);

    swap(t);
}

template <ss_typename_param_k T>
inline ss_typename_type_ret_k interface_ptr<T>::pointer interface_ptr<T>::detach()
{
    return parent_class_type::detach();
}

template <ss_typename_param_k T>
inline cs_bool_t interface_ptr<T>::operator ==(ss_typename_type_k interface_ptr<T>::class_type const& rhs) const
{
    return parent_class_type::equal(rhs);
}

template <ss_typename_param_k T>
inline cs_bool_t interface_ptr<T>::operator !=(ss_typename_type_k interface_ptr<T>::class_type const& rhs) const
{
    return !parent_class_type::equal(rhs);
}

template <ss_typename_param_k T>
inline interface_ptr<T>::operator ss_typename_type_k interface_ptr<T>::operator_bool_type() const
{
    return operator_bool_generator_type::translate(parent_class_type::empty());
}

template <ss_typename_param_k T>
inline ss_typename_type_ret_k interface_ptr<T>::pointer interface_ptr<T>::get_interface_ptr() const
{
    return parent_class_type::get();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


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
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef COMSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::comstl::get_ptr;

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

using ::comstl::is_empty;

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* In the special case of Intel behaving as VC++ 7.0 or earlier on Win32, we
 * illegally insert into the std namespace.
 */
#if defined(STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template <ss_typename_param_k T>
    inline
    void
    swap(
        COMSTL_NS_QUAL(interface_ptr)<T>&   lhs
    ,   COMSTL_NS_QUAL(interface_ptr)<T>&   rhs
    )
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_SMARTPTR_HPP_INTERFACE_PTR */

/* ///////////////////////////// end of file //////////////////////////// */

