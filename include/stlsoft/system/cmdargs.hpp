/* /////////////////////////////////////////////////////////////////////////
 * File:    stlsoft/system/cmdargs.hpp
 *
 * Purpose: Command-line sequences class.
 *
 * Created: 25th June 2005
 * Updated: 4th May 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/system/cmdargs.hpp
 *
 * \brief [C++] Definition of the stlsoft::cmdargs class
 *   (\ref group__library__System "System" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SYSTEM_HPP_CMDARGS
#define STLSOFT_INCL_STLSOFT_SYSTEM_HPP_CMDARGS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SYSTEM_HPP_CMDARGS_MAJOR       3
# define STLSOFT_VER_STLSOFT_SYSTEM_HPP_CMDARGS_MINOR       2
# define STLSOFT_VER_STLSOFT_SYSTEM_HPP_CMDARGS_REVISION    2
# define STLSOFT_VER_STLSOFT_SYSTEM_HPP_CMDARGS_EDIT        57
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

#ifdef STLSOFT_SYSTEM_CMDARGS_USE_STD_STRING
# include <string>
#else /* ? STLSOFT_SYSTEM_CMDARGS_USE_STD_STRING */
# ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
#  include <stlsoft/string/simple_string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */
#endif /* STLSOFT_SYSTEM_CMDARGS_USE_STD_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS
# include <stlsoft/string/split_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW
# include <stlsoft/string/string_view.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW */

#ifndef STLSOFT_INCL_UTILITY
# define STLSOFT_INCL_UTILITY
# include <utility>
#endif /* !STLSOFT_INCL_UTILITY */
#ifndef STLSOFT_INCL_VECTOR
# define STLSOFT_INCL_VECTOR
# include <vector>
#endif /* !STLSOFT_INCL_VECTOR */


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

/** Facade class that presents argc+argv command line parameters as two
 * separate sequences of options (those arguments with - or -- prefixes and,
 * optionally, separated from an option value by a =) and values (those
 * without any leading hyphens)
 *
 * \ingroup group__library__System
 *
 * \note The cmdargs instance maintains views onto the actual arguments in
 *   the argv array. Therefore, the behaviour is undefined if any code
 *   modifies the strings pointed to by the elements in the argv array, or
 *   repoints any of the <code>argv</code> elements to different strings.
 */
class cmdargs
{
public:
    /// This type
    typedef cmdargs                                         class_type;
    /// The char type
    typedef char                                            char_type;
    /// The string type
#ifdef STLSOFT_SYSTEM_CMDARGS_USE_STD_STRING
    typedef std::string                                     string_type;
#else /* ? STLSOFT_SYSTEM_CMDARGS_USE_STD_STRING */
    typedef simple_string                                   string_type;
#endif /* STLSOFT_SYSTEM_CMDARGS_USE_STD_STRING */
    /// The string view type
    typedef basic_string_view<
        char
    >                                                       string_view_type;

    enum
    {
            singleDash  =   1
        ,   doubleDash  =   2
        ,   tripleDash  =   3
    };

    /// Represents a command-line option
    ///
    /// \warning The value of the <code>original</code> member will be
    ///   undefined if a copy of the instance is kept beyond the lifetime of
    ///   the cmdargs instance from which it was obtained.
    struct option
    {
        string_type         name;
        string_type         value;
        int                 type;
        int                 index;
        string_view_type    original;

        option()
            : name()
            , value()
            , type(-1)
            , index(-1)
            , original()
        {}
        ss_explicit_k
        option(
            int t
        ,   int i
        )
            : name()
            , value()
            , type(t)
            , index(i)
            , original()
        {}
        option(
            string_type const&      n
        ,   string_type const&      v
        ,   int                     t
        ,   int                     i
        ,   string_view_type const& o
        )
            : name(n)
            , value(v)
            , type(t)
            , index(i)
            , original(o)
        {}
    };

    /// Represents a command-line value
    ///
    /// \warning The value of the <code>name</code> member will be undefined
    ///   if a copy of the instance is kept beyond the lifetime of the
    ///   cmdargs instance from which it was obtained.
    struct value
    {
        string_view_type    name;
        int                 index;

        value()
            : name()
            , index(-1)
        {}
        value(
            string_view_type const& v
        ,   int                     i
        )
            : name(v)
            , index(i)
        {}
    };

    typedef option                                          options_value_type;
    typedef value                                           values_value_type;

    typedef STLSOFT_NS_QUAL_STD(vector)<options_value_type> options_type;
    typedef STLSOFT_NS_QUAL_STD(vector)<values_value_type>  values_type;

    typedef options_type::const_iterator                    const_options_iterator;
    typedef values_type::const_iterator                     const_values_iterator;

    typedef ss_size_t                                       size_type;
    typedef ss_bool_t                                       bool_type;

public: // construction
    /// Constructs from argc/argv
    cmdargs(int argc, char* argv[]);
    /// Releases any resources
    ~cmdargs() STLSOFT_NOEXCEPT;
private:
    cmdargs(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

public: // attributes
    /// The program name
    string_type const&      program_name() const;

    /// (Non-mutating) reference to the options collection
    options_type const&     options() const;
    /// (Non-mutating) reference to the values collection
    values_type const&      values() const;

    const_options_iterator  options_begin() const;
    const_options_iterator  options_end() const;

    const_values_iterator   values_begin() const;
    const_values_iterator   values_end() const;

    /// The number of options
    size_type   options_size() const;
    /// The number of values
    size_type   values_size() const;
    /// The numbers options and values
    size_type   size() const;
    /// Indicates whether there are any options and/or values
    bool_type   empty() const;

    /// Determines whether the options collection contains an option of
    ///  the given name
    ///
    /// \param optionName The name of the option to search for
    /// \param type The type of the option (i.e the number of hyphens). It
    ///    defaults to -1, which indicates that the caller does not care.
    template <ss_typename_param_k S>
    bool_type
    has_option(
        S const&    optionName
    ,   int         type = -1
    ) const
    {
        return m_options.end() != has_option_(c_str_ptr(optionName), type);
    }
    /// Determines whether the options collection contains an option of
    ///  the given name, and copies the found option's details into a
    ///  caller-supplied instance
    ///
    /// \param optionName The name of the option to search for
    /// \param type The type of the option (i.e the number of hyphens). The
    ///    caller can specify -1 to indicate that it does not care.
    /// \param opt The instance into which the
    template <ss_typename_param_k S>
    bool_type
    has_option(
        S const&    optionName
    ,   int         type
    ,   option&     opt
    ) const
    {
        options_type::const_iterator it = has_option_(c_str_ptr(optionName), type);

        if (m_options.end() != it)
        {
            opt = *it;

            return true;
        }

        return false;
    }

    template <ss_typename_param_k S>
    bool_type
    has_value(S const& valueName) const
    {
        return m_values.end() != has_value_(c_str_ptr(valueName));
    }
    template <ss_typename_param_k S>
    bool_type
    has_value(
        S const&    valueName
    ,   value&      val
    ) const
    {
        values_type::const_iterator it = has_value_(c_str_ptr(valueName));

        if (m_values.end() != it)
        {
            val = *it;

            return true;
        }

        return false;
    }

private: // implementation
    static
    size_type
    count_dashes_(char_type const* arg);

    values_type::const_iterator
    has_value_(char const* valueName) const;

    options_type::const_iterator
    has_option_(
        char const* optionName
    ,   int         type
    ) const;

private: // fields
    string_type     m_program_name;
    options_type    m_options;
    values_type     m_values;
};


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
/* static */
cmdargs::size_type
cmdargs::count_dashes_(char_type const* arg)
{
    if ('-' != arg[0])
    {
        return 0;
    }

    if ('-' != arg[1])
    {
        return 1;
    }

    if ('-' != arg[2])
    {
        return 2;
    }

    if ('-' != arg[2])
    {
        return 3;
    }

    return 0;
}


inline
cmdargs::cmdargs(
    int     argc
,   char*   argv[]
)
    : m_program_name((argc > 0) ? argv[0] : "")
    , m_options()
    , m_values()
{

    if (argc >= 2)
    {
        bool treat_as_values = false;

        for (int i = 1; i != argc; ++i)
        {
            char const*     arg         =   argv[i];
            size_type const num_dashes  =   count_dashes_(arg);

            if (!treat_as_values &&
                0 != num_dashes)
            {

                if ('\0' == arg[1])
                {
                    m_options.push_back(option(singleDash, i));
                }
                else
                if (2 == num_dashes &&
                    '\0' == arg[2])
                {
                    treat_as_values = true;
                }
                else
                {
                    int const type = int(num_dashes);

                    string_type s0;
                    string_type s1;

                    split(arg + num_dashes, '=', s0, s1);

                    m_options.push_back(option(s0, s1, type, i, argv[i]));
                }
            }
            else
            {
                m_values.push_back(value(arg, i));
            }
        }
    }
}

inline
cmdargs::~cmdargs() STLSOFT_NOEXCEPT
{
}

inline
cmdargs::string_type const&
cmdargs::program_name() const
{
    return m_program_name;
}

inline
cmdargs::options_type const&
cmdargs::options() const
{
    return m_options;
}

inline
cmdargs::values_type const&
cmdargs::values() const
{
    return m_values;
}

inline
cmdargs::const_options_iterator
cmdargs::options_begin() const
{
    return m_options.begin();
}

inline
cmdargs::const_options_iterator
cmdargs::options_end() const
{
    return m_options.end();
}

inline
cmdargs::const_values_iterator
cmdargs::values_begin() const
{
    return m_values.begin();
}

inline
cmdargs::const_values_iterator
cmdargs::values_end() const
{
    return m_values.end();
}

inline
cmdargs::size_type
cmdargs::options_size() const
{
    return m_options.size();
}

inline
cmdargs::size_type
cmdargs::values_size() const
{
    return m_values.size();
}

inline
cmdargs::size_type
cmdargs::size() const
{
    return options_size() + values_size();
}

inline
cmdargs::bool_type
cmdargs::empty() const
{
    return 0 == size();
}

inline
cmdargs::values_type::const_iterator
cmdargs::has_value_(char const* valueName) const
{
    STLSOFT_ASSERT(NULL != valueName);

    values_type::const_iterator b;

    for (b = m_values.begin(); b != m_values.end(); ++b)
    {
        if ((*b).name == valueName)
        {
            break;
        }
    }

    return b;
}

inline
cmdargs::options_type::const_iterator
cmdargs::has_option_(
    char const* optionName
,   int         type
) const
{
    STLSOFT_ASSERT(NULL != optionName);

    options_type::const_iterator b;

    for (b = m_options.begin(); b != m_options.end(); ++b)
    {
        if ((*b).name == optionName &&
            (   -1 == type ||
                type == (*b).type))
        {
            break;
        }
    }

    return b;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template <ss_typename_param_k T_stream>
inline
T_stream&
operator <<(
    T_stream&               stm
,   cmdargs::option const&  option
)
{
    static const char s_dashes[] =
    {
            '-'
        ,   '-'
        ,   '\0'
    };
    char const* const dashes = &s_dashes[(option.type == cmdargs::singleDash)];

    if (option.value.empty())
    {
        stm << dashes << option.name;
    }
    else
    {
        stm << dashes << option.name << '=' << option.value;
    }

    return stm;
}

template <ss_typename_param_k T_stream>
inline
T_stream&
operator <<(
    T_stream&               stm
,   cmdargs::value const&   value
)
{
    stm << value.name;

    return stm;
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_SYSTEM_HPP_CMDARGS */

/* ///////////////////////////// end of file //////////////////////////// */

