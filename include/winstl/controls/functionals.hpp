/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/controls/functionals.hpp
 *
 * Purpose: Functionals for application to controls.
 *
 * Created: 8th October 2002
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/controls/functionals.hpp
 *
 * \brief [C++] Functionals for application to controls
 *   (\ref group__library__Windows_Control "Windows Control" Library).
 */

#ifndef WINSTL_INCL_WINSTL_CONTROL_HPP_FUNCTIONALS
#define WINSTL_INCL_WINSTL_CONTROL_HPP_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CONTROL_HPP_FUNCTIONALS_MAJOR    4
# define WINSTL_VER_WINSTL_CONTROL_HPP_FUNCTIONALS_MINOR    2
# define WINSTL_VER_WINSTL_CONTROL_HPP_FUNCTIONALS_REVISION 15
# define WINSTL_VER_WINSTL_CONTROL_HPP_FUNCTIONALS_EDIT     102
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(STLSOFT_COMPILER_IS_GCC) && \
    __GNUC__ < 3
# error winstl/controls/functionals.hpp is not compatible with GNU C++ prior to 3.0
#endif /* compiler */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1100
# error winstl/controls/functionals.hpp is not compatible with Visual C++ 4.2 or earlier
#endif /* compiler */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_UNARY_FUNCTION_OUTPUT_ITERATOR_ADAPTOR
# include <stlsoft/iterators/unary_function_output_iterator_adaptor.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_UNARY_FUNCTION_OUTPUT_ITERATOR_ADAPTOR */
#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING
# include <winstl/shims/access/string.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING */
#ifndef WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND
# include <winstl/shims/attribute/get_HWND.hpp>
#endif /* !WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND */
#ifndef WINSTL_INCL_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS
# include <winstl/conversion/char_conversions.hpp>  // for winstl::a2w, w2a
#endif /* !WINSTL_INCL_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS */
#ifndef WINSTL_INCL_WINSTL_CONTROLS_H_FUNCTIONS
# include <winstl/controls/functions.h>     // for winstl::listbox_add_string, ...
#endif /* !WINSTL_INCL_WINSTL_CONTROLS_H_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <winstl/system/system_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */

#ifndef _WINSTL_CONTROL_FUNCTIONALS_NO_STD
# include <functional>
#else /* ? _WINSTL_CONTROL_FUNCTIONALS_NO_STD */
# error Now need to write that std_binary_function stuff!!
#endif /* _WINSTL_CONTROL_FUNCTIONALS_NO_STD */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_memfns
# include <stlsoft/api/external/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_memfns */
#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

#ifndef WINSTL_INCL_WINSTL_API_external_h_WindowsAndMessages
# include <winstl/api/external/WindowsAndMessages.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_WindowsAndMessages */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * workarounds
 */

#if defined(STLSOFT_COMPILER_IS_DMC)

#endif /* STLSOFT_COMPILER_IS_DMC */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Functor used to (un)check buttons
 *
 * \ingroup group__library__Windows_Control
 */
// [[synesis:class:unary-functor: button_check]]
class button_check
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<HWND, void>
#endif
{
public:
    typedef HWND                                            argument_type;
    typedef void                                            result_type;
    /// This type
    typedef button_check                                    class_type;

public:
    ss_explicit_k
    button_check(int nCheck = BST_CHECKED)
        : m_nCheck(nCheck)
    {}
    button_check(button_check const& rhs)
        : m_nCheck(rhs.m_nCheck)
    {}

public:
    void operator ()(HWND hwnd) const
    {
        check_(hwnd, m_nCheck);
    }
    template <ss_typename_param_k W>
    void operator ()(W &wnd) const
    {
        check_(WINSTL_NS_QUAL(get_HWND)(wnd), m_nCheck);
    }
private:
    static void check_(HWND hwnd, int nCheck)
    {
        WINSTL_API_EXTERNAL_WindowsAndMessages_SendMessage(hwnd, BM_SETCHECK, static_cast<WPARAM>(nCheck), 0L);
    }

private:
    const int   m_nCheck;

private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
};


/** Predicate used to indicate the check-state of buttons
 *
 * \ingroup group__library__Windows_Control
 */
// [[synesis:class:unary-predicate: is_checked]]
class is_checked
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<HWND, BOOL>
#endif
{
public:
    typedef HWND                                            argument_type;
    typedef BOOL                                            result_type;
    /// This type
    typedef is_checked                                      class_type;

public:
    is_checked(int nCheckType = -1)
        : m_nCheckType(nCheckType)
    {
        WINSTL_ASSERT((-1 == nCheckType) || (BST_UNCHECKED == nCheckType) || (BST_CHECKED == nCheckType) || (BST_INDETERMINATE == nCheckType));
    }
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

public:
    BOOL operator ()(HWND hwnd) const
    {
        return is_checked_(hwnd);
    }
    template <ss_typename_param_k W>
    BOOL operator ()(W &wnd) const
    {
        return is_checked_(WINSTL_NS_QUAL(get_HWND)(wnd));
    }
private:
    BOOL is_checked_(HWND hwnd) const
    {
        int nCheck  =   static_cast<int>(WINSTL_API_EXTERNAL_WindowsAndMessages_SendMessage(hwnd, BM_GETCHECK, 0, 0L));

        if (-1 == m_nCheckType)
        {
            return nCheck;
        }
        else
        {
            return m_nCheckType == nCheck;
        }
    }

private:
    int const   m_nCheckType;
};


/** Predicate used to detect whether the window is of a given class
 *
 * \ingroup group__library__Windows_Control
 */
// [[synesis:class:unary-predicate: is_class]]
class is_class
#if __cplusplus < 201103L
    : public STLSOFT_NS_QUAL_STD(unary_function)<HWND, BOOL>
#endif
{
public:
    typedef HWND                                            argument_type;
    typedef BOOL                                            result_type;
    /// This type
    typedef is_class                                        class_type;

public:
    ss_explicit_k
    is_class(ws_char_a_t const* windowClass)
        : m_bUnicode(false)
    {
        typedef system_traits<ws_char_a_t>  traits_t;

        WINSTL_ASSERT(NULL != windowClass);

        const traits_t::size_type cchClass = traits_t::str_len(windowClass);

        WINSTL_ASSERT(cchClass < STLSOFT_NUM_ELEMENTS(m_name.sza));

        STLSOFT_API_EXTERNAL_memfns_memcpy(&m_name.sza[0], windowClass, cchClass);
        m_name.sza[cchClass] = '\0';
    }
    ss_explicit_k
    is_class(ws_char_w_t const* windowClass)
        : m_bUnicode(true)
    {
        typedef system_traits<ws_char_w_t>  traits_t;

        WINSTL_ASSERT(NULL != windowClass);

        const traits_t::size_type cchClass = traits_t::str_len(windowClass);

        WINSTL_ASSERT(cchClass < STLSOFT_NUM_ELEMENTS(m_name.szw));

        STLSOFT_API_EXTERNAL_memfns_memcpy(&m_name.szw[0], windowClass, cchClass);
        m_name.szw[cchClass] = '\0';
    }
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

public:
    BOOL operator ()(HWND hwnd) const
    {
        return is_class_(hwnd);
    }
    template <ss_typename_param_k W>
    BOOL operator ()(W &wnd) const
    {
        return is_class_(WINSTL_NS_QUAL(get_HWND)(wnd));
    }
private:
    BOOL is_class_(HWND hwnd) const
    {
        return m_bUnicode ? is_class_w_(hwnd) : is_class_a_(hwnd);
    }
    BOOL is_class_w_(HWND hwnd) const
    {
        ws_char_w_t szw[256];

        return  ::GetClassNameW(hwnd, &szw[0], STLSOFT_NUM_ELEMENTS(szw)) &&
                0 == STLSOFT_API_EXTERNAL_string_wcsicmp(&szw[0], &m_name.szw[0]);
    }
    BOOL is_class_a_(HWND hwnd) const
    {
        ws_char_a_t sza[256];

        return  ::GetClassNameA(hwnd, &sza[0], STLSOFT_NUM_ELEMENTS(sza)) &&
                0 == STLSOFT_API_EXTERNAL_string_stricmp(&sza[0], &m_name.sza[0]);
    }

private:
    union
    {
        ws_char_a_t sza[256];
        ws_char_w_t szw[256];
    }           m_name;
    const int   m_bUnicode;
};

/** A function class used to insert items at the front of list-box
 *
 * \ingroup group__library__Windows_Control
 */
// [[synesis:class:unary-functor: listbox_front_inserter]]
struct listbox_front_inserter
#if !defined(STLSOFT_COMPILER_IS_DMC) || \
        __DMC__ > 0x0850
    : public STLSOFT_NS_QUAL(unary_function_output_iterator_adaptor)<listbox_front_inserter>
#endif /* compiler */
{
public:
    /// This type
    typedef listbox_front_inserter  class_type;

public:
    /// Construct with the target list-box window
    ss_explicit_k
    listbox_front_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    listbox_front_inserter(class_type const& rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const& s)
    {
        insert(STLSOFT_NS_QUAL(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const* s)
    {
        insert(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const* s)
    {
        insert(s);
    }

// Implementation
private:
    void insert(ws_char_a_t const* s)
    {
        if (m_bUnicode)
        {
            listbox_insertstring_w(m_hwndListbox, a2w(s), 0);
        }
        else
        {
            listbox_insertstring_a(m_hwndListbox, s, 0);
        }
    }
    void insert(ws_char_w_t const* s)
    {
        if (m_bUnicode)
        {
            listbox_insertstring_w(m_hwndListbox, s, 0);
        }
        else
        {
            listbox_insertstring_a(m_hwndListbox, w2a(s), 0);
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};

/** A function class used to add items to a list-box
 *
 * \ingroup group__library__Windows_Control
 */
// [[synesis:class:unary-functor: listbox_add_inserter]]
struct listbox_add_inserter
#if !defined(STLSOFT_COMPILER_IS_DMC) || \
        __DMC__ > 0x0850
    : public STLSOFT_NS_QUAL(unary_function_output_iterator_adaptor)<listbox_add_inserter>
#endif /* compiler */
{
public:
    /// This type
    typedef listbox_add_inserter    class_type;

public:
    /// Construct with the target list-box window
    ss_explicit_k
    listbox_add_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    listbox_add_inserter(class_type const& rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const& s)
    {
        add(STLSOFT_NS_QUAL(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const* s)
    {
        add(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const* s)
    {
        add(s);
    }

// Implementation
private:
    void add(ws_char_a_t const* s)
    {
        if (m_bUnicode)
        {
            listbox_addstring_w(m_hwndListbox, a2w(s));
        }
        else
        {
            listbox_addstring_a(m_hwndListbox, s);
        }
    }
    void add(ws_char_w_t const* s)
    {
        if (m_bUnicode)
        {
            listbox_addstring_w(m_hwndListbox, s);
        }
        else
        {
            listbox_addstring_a(m_hwndListbox, w2a(s));
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};

/** A function class used to insert items to the back of a list-box
 *
 * \ingroup group__library__Windows_Control
 */
// [[synesis:class:unary-functor: listbox_back_inserter]]
struct listbox_back_inserter
#if !defined(STLSOFT_COMPILER_IS_DMC) || \
        __DMC__ > 0x0850
    : public STLSOFT_NS_QUAL(unary_function_output_iterator_adaptor)<listbox_back_inserter>
#endif /* compiler */
{
public:
    /// This type
    typedef listbox_back_inserter   class_type;

public:
    /// Construct with the target list-box window
    ss_explicit_k
    listbox_back_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    listbox_back_inserter(class_type const& rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const& s)
    {
        insert(STLSOFT_NS_QUAL(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const* s)
    {
        insert(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const* s)
    {
        insert(s);
    }

// Implementation
private:
    void insert(ws_char_a_t const* s)
    {
        if (m_bUnicode)
        {
            listbox_insertstring_w(m_hwndListbox, a2w(s), -1);
        }
        else
        {
            listbox_insertstring_a(m_hwndListbox, s, -1);
        }
    }
    void insert(ws_char_w_t const* s)
    {
        if (m_bUnicode)
        {
            listbox_insertstring_w(m_hwndListbox, s, -1);
        }
        else
        {
            listbox_insertstring_a(m_hwndListbox, w2a(s), -1);
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};



/** A function class used to insert items at the front of combo-box
 *
 * \ingroup group__library__Windows_Control
 */
// [[synesis:class:unary-functor: combobox_front_inserter]]
struct combobox_front_inserter
#if !defined(STLSOFT_COMPILER_IS_DMC) || \
        __DMC__ > 0x0850
    : public STLSOFT_NS_QUAL(unary_function_output_iterator_adaptor)<combobox_front_inserter>
#endif /* compiler */
{
public:
    /// This type
    typedef combobox_front_inserter class_type;

public:
    /// Construct with the target combo-box window
    ss_explicit_k
    combobox_front_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    combobox_front_inserter(class_type const& rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const& s)
    {
        insert(STLSOFT_NS_QUAL(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const* s)
    {
        insert(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const* s)
    {
        insert(s);
    }

// Implementation
private:
    void insert(ws_char_a_t const* s)
    {
        if (m_bUnicode)
        {
            combobox_insertstring_w(m_hwndListbox, a2w(s), 0);
        }
        else
        {
            combobox_insertstring_a(m_hwndListbox, s, 0);
        }
    }
    void insert(ws_char_w_t const* s)
    {
        if (m_bUnicode)
        {
            combobox_insertstring_w(m_hwndListbox, s, 0);
        }
        else
        {
            combobox_insertstring_a(m_hwndListbox, w2a(s), 0);
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};

/** A function class used to add items to a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
// [[synesis:class:unary-functor: combobox_add_inserter]]
struct combobox_add_inserter
#if !defined(STLSOFT_COMPILER_IS_DMC) || \
        __DMC__ > 0x0850
    : public STLSOFT_NS_QUAL(unary_function_output_iterator_adaptor)<combobox_add_inserter>
#endif /* compiler */
{
public:
    /// This type
    typedef combobox_add_inserter   class_type;

public:
    /// Construct with the target combo-box window
    ss_explicit_k
    combobox_add_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    combobox_add_inserter(class_type const& rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const& s)
    {
        add(STLSOFT_NS_QUAL(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const* s)
    {
        add(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const* s)
    {
        add(s);
    }

// Implementation
private:
    void add(ws_char_a_t const* s)
    {
        if (m_bUnicode)
        {
            combobox_addstring_w(m_hwndListbox, a2w(s));
        }
        else
        {
            combobox_addstring_a(m_hwndListbox, s);
        }
    }
    void add(ws_char_w_t const* s)
    {
        if (m_bUnicode)
        {
            combobox_addstring_w(m_hwndListbox, s);
        }
        else
        {
            combobox_addstring_a(m_hwndListbox, w2a(s));
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};

/** A function class used to insert items to the back of a combo-box
 *
 * \ingroup group__library__Windows_Control
 */
// [[synesis:class:unary-functor: combobox_back_inserter]]
struct combobox_back_inserter
#if !defined(STLSOFT_COMPILER_IS_DMC) || \
        __DMC__ > 0x0850
    : public STLSOFT_NS_QUAL(unary_function_output_iterator_adaptor)<combobox_back_inserter>
#endif /* compiler */
{
public:
    /// This type
    typedef combobox_back_inserter  class_type;

public:
    /// Construct with the target combo-box window
    ss_explicit_k
    combobox_back_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    combobox_back_inserter(class_type const& rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const& s)
    {
        insert(STLSOFT_NS_QUAL(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const* s)
    {
        insert(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const* s)
    {
        insert(s);
    }

// Implementation
private:
    void insert(ws_char_a_t const* s)
    {
        if (m_bUnicode)
        {
            combobox_insertstring_w(m_hwndListbox, a2w(s), -1);
        }
        else
        {
            combobox_insertstring_a(m_hwndListbox, s, -1);
        }
    }
    void insert(ws_char_w_t const* s)
    {
        if (m_bUnicode)
        {
            combobox_insertstring_w(m_hwndListbox, s, -1);
        }
        else
        {
            combobox_insertstring_a(m_hwndListbox, w2a(s), -1);
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_CONTROL_HPP_FUNCTIONALS */

/* ///////////////////////////// end of file //////////////////////////// */

