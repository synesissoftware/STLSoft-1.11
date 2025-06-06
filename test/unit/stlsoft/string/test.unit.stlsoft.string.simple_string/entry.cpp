/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.string.simple_string/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::basic_simple_string`.
 *
 * Created: 4th November 2008
 * Updated: 20th March 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */

// #define USE_std_string


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#ifdef _DEBUG
# define _CRT_SECURE_NO_DEPRECATE
# define _SCL_SECURE_NO_WARNINGS
#endif

#ifndef USE_std_string
# include <stlsoft/string/simple_string.hpp>
#endif /* !USE_std_string */
#include <stlsoft/string/char_traits.hpp>
#include <stlsoft/string/string_traits.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <iomanip>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    // construction

    static void test_ctor_default();
    static void test_ctor_copy();
    static void test_ctor_s_pos();
    static void test_ctor_s_pos_n();
    static void test_ctor_ccs();
    static void test_ctor_ccs_n();
    static void test_ctor_n_ch();
    static void test_ctor_range();
#ifndef USE_std_string
    static void test_ctor_range_2();
#endif /* !USE_std_string */


    // `assign()`

    static void test_assign_1();
    static void test_assign_2();
    static void test_assign_3();
#ifndef USE_std_string
    static void test_assign_4();
#endif /* !USE_std_string */


    // `append()`

    static void test_append_1();
    static void test_append_2();
    static void test_append_3();
#ifndef USE_std_string
    static void test_push_back();
#endif /* !USE_std_string */
    static void test_pop_back();


    // modifiers

    static void test_reserve();
    static void test_swap_1();
    static void test_swap_2();
    static void test_swap_3();
    static void test_resize();
#ifndef USE_std_string
    static void test_clear();
#endif /* !USE_std_string */
#ifdef USE_std_string
    static void test_erase_0_param();
    static void test_erase_1_pos();
    static void test_erase_pos_and_cch();
#endif

    // attributes

    static void test_size();
    static void test_max_size();
    static void test_length();
    static void test_capacity();
    static void test_empty();


    // comparison

    static void test_compare_1();
    static void test_compare_2();
    static void test_compare_3();
    static void test_compare_4();
    static void test_equality_operators_1();
#ifndef USE_std_string
    static void test_equal_p_n_ccs_n();
    static void test_equal_p_n_ccs();
    static void test_equal_ccs();
    static void test_equal_p_n_scr_p_n();
    static void test_equal_p_n_scr();
    static void test_equal_scr();
#endif /* !USE_std_string */
#if !defined(USE_std_string) || \
    __cplusplus >= 202002L
    static void test_starts_with_1();
    static void test_starts_with_2();
    static void test_contains_1();
    static void test_contains_2();
    static void test_contains_3();
    static void test_ends_with_1();
    static void test_ends_with_2();
#endif


    // accessors

    static void test_at_1();
    static void test_at_2();
    static void test_at_3();
    static void test_at_4();
    static void test_index_1();
    static void test_index_2();
    static void test_copy();
    static void test_substr();
    static void test_substr_throw();


    // search

#ifdef USE_std_string
    static void test_find_char();
    static void test_find_c_string();
    static void test_find_string();
    static void test_rfind_char();
    static void test_rfind_c_string();
    static void test_rfind_string();
    static void test_find_first_of_char();
    static void test_find_first_of_c_string();
    static void test_find_first_of_string();
    static void test_find_last_of_char();
    static void test_find_last_of_c_string();
    static void test_find_last_of_string();
    static void test_find_first_not_of_char();
    static void test_find_first_not_of_c_string();
    static void test_find_first_not_of_string();
    static void test_find_last_not_of_char();
    static void test_find_last_not_of_c_string();
    static void test_find_last_not_of_string();
#endif


    // traits

    static void test_stlsoft_char_traits();

    static void test_string_traits();


    // operators : concatenation

    static void test_concatenation_1();
    static void test_concatenation_2();
#ifdef USE_std_string
    static void test_concatenation_3();
    static void test_concatenation_4();
    static void test_concatenation_5();
#endif
    static void test_concatenation_6();


    // operators : insertion

    static void test_insertion_1();
    static void test_insertion_2();
    static void test_insertion_3();
    static void test_insertion_4();


    // shims : sas

    static void test_string_access_shims();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.string.simple_string", verbosity))
    {
        // construction

        XTESTS_RUN_CASE(test_ctor_default);
        XTESTS_RUN_CASE(test_ctor_copy);
        XTESTS_RUN_CASE(test_ctor_s_pos);
        XTESTS_RUN_CASE(test_ctor_s_pos_n);
        XTESTS_RUN_CASE(test_ctor_ccs);
        XTESTS_RUN_CASE(test_ctor_ccs_n);
        XTESTS_RUN_CASE(test_ctor_n_ch);
        XTESTS_RUN_CASE(test_ctor_range);
#ifndef USE_std_string
        XTESTS_RUN_CASE(test_ctor_range_2);
#endif /* !USE_std_string */


        // `assign()`

        XTESTS_RUN_CASE(test_assign_1);
        XTESTS_RUN_CASE(test_assign_2);
        XTESTS_RUN_CASE(test_assign_3);
#ifndef USE_std_string
        XTESTS_RUN_CASE(test_assign_4);
#endif /* !USE_std_string */


        // `append()`

        XTESTS_RUN_CASE(test_append_1);
        XTESTS_RUN_CASE(test_append_2);
        XTESTS_RUN_CASE_THAT_THROWS(test_append_3, std::out_of_range);
#ifndef USE_std_string
        XTESTS_RUN_CASE(test_push_back);
#endif /* !USE_std_string */
        XTESTS_RUN_CASE(test_pop_back);


        // modifiers

        XTESTS_RUN_CASE(test_reserve);
        XTESTS_RUN_CASE(test_swap_1);
        XTESTS_RUN_CASE(test_swap_2);
        XTESTS_RUN_CASE(test_swap_3);
        XTESTS_RUN_CASE(test_resize);
#ifndef USE_std_string
        XTESTS_RUN_CASE(test_clear);
#endif /* !USE_std_string */
#ifdef USE_std_string
        XTESTS_RUN_CASE(test_erase_0_param);
        XTESTS_RUN_CASE(test_erase_1_pos);
        XTESTS_RUN_CASE(test_erase_pos_and_cch);
#endif

        // attributes

        XTESTS_RUN_CASE(test_size);
        XTESTS_RUN_CASE(test_max_size);
        XTESTS_RUN_CASE(test_length);
        XTESTS_RUN_CASE(test_capacity);
        XTESTS_RUN_CASE(test_empty);


        // comparison

        XTESTS_RUN_CASE(test_compare_1);
        XTESTS_RUN_CASE(test_compare_2);
        XTESTS_RUN_CASE(test_compare_3);
        XTESTS_RUN_CASE(test_compare_4);
        XTESTS_RUN_CASE(test_equality_operators_1);
#ifndef USE_std_string
        XTESTS_RUN_CASE(test_equal_p_n_ccs_n);
        XTESTS_RUN_CASE(test_equal_p_n_ccs);
        XTESTS_RUN_CASE(test_equal_ccs);
        XTESTS_RUN_CASE(test_equal_p_n_scr_p_n);
        XTESTS_RUN_CASE(test_equal_p_n_scr);
        XTESTS_RUN_CASE(test_equal_scr);
#endif /* !USE_std_string */

#if !defined(USE_std_string) || \
    __cplusplus >= 202002L
        XTESTS_RUN_CASE(test_starts_with_1);
        XTESTS_RUN_CASE(test_starts_with_2);
        XTESTS_RUN_CASE(test_contains_1);
        XTESTS_RUN_CASE(test_contains_2);
        XTESTS_RUN_CASE(test_contains_3);
        XTESTS_RUN_CASE(test_ends_with_1);
        XTESTS_RUN_CASE(test_ends_with_2);
#endif


        // accessors

        XTESTS_RUN_CASE(test_at_1);
        XTESTS_RUN_CASE(test_at_2);
        XTESTS_RUN_CASE_THAT_THROWS(test_at_3, std::out_of_range);
        XTESTS_RUN_CASE_THAT_THROWS(test_at_4, std::out_of_range);
        XTESTS_RUN_CASE(test_index_1);
        XTESTS_RUN_CASE(test_index_2);
        XTESTS_RUN_CASE(test_copy);
        XTESTS_RUN_CASE(test_substr);
        XTESTS_RUN_CASE_THAT_THROWS(test_substr_throw, std::out_of_range);


        // search

#ifdef USE_std_string
        XTESTS_RUN_CASE(test_find_char);
        XTESTS_RUN_CASE(test_find_c_string);
        XTESTS_RUN_CASE(test_find_string);
        XTESTS_RUN_CASE(test_rfind_char);
        XTESTS_RUN_CASE(test_rfind_c_string);
        XTESTS_RUN_CASE(test_rfind_string);
        XTESTS_RUN_CASE(test_find_first_of_char);
        XTESTS_RUN_CASE(test_find_first_of_c_string);
        XTESTS_RUN_CASE(test_find_first_of_string);
        XTESTS_RUN_CASE(test_find_last_of_char);
        XTESTS_RUN_CASE(test_find_last_of_c_string);
        XTESTS_RUN_CASE(test_find_last_of_string);
        XTESTS_RUN_CASE(test_find_first_not_of_char);
        XTESTS_RUN_CASE(test_find_first_not_of_c_string);
        XTESTS_RUN_CASE(test_find_first_not_of_string);
        XTESTS_RUN_CASE(test_find_last_not_of_char);
        XTESTS_RUN_CASE(test_find_last_not_of_c_string);
        XTESTS_RUN_CASE(test_find_last_not_of_string);
#endif

        // traits

        XTESTS_RUN_CASE(test_stlsoft_char_traits);

        XTESTS_RUN_CASE(test_string_traits);


        // operators : concatenation

        XTESTS_RUN_CASE(test_concatenation_1);
        XTESTS_RUN_CASE(test_concatenation_2);
#ifdef USE_std_string
        XTESTS_RUN_CASE(test_concatenation_3);
        XTESTS_RUN_CASE(test_concatenation_4);
        XTESTS_RUN_CASE(test_concatenation_5);
#endif
        XTESTS_RUN_CASE(test_concatenation_6);


        // operators : insertion

        XTESTS_RUN_CASE(test_insertion_1);
        XTESTS_RUN_CASE(test_insertion_2);
        XTESTS_RUN_CASE(test_insertion_3);
        XTESTS_RUN_CASE(test_insertion_4);


        // shims : sas

        XTESTS_RUN_CASE(test_string_access_shims);


        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

#ifndef USE_std_string
    typedef stlsoft::simple_string                          string_t;
    typedef stlsoft::simple_wstring                         wstring_t;
#else /* ? !USE_std_string */
    typedef std::string                                     string_t;
    typedef std::wstring                                    wstring_t;
#endif /* !USE_std_string */
    using stlsoft::ss_size_t;


    struct SimpleStream
    {
        std::string     contents;

        SimpleStream&
        write(
            char const*     s
        ,   std::streamsize n
        )
        {
            contents.append(s, static_cast<std::size_t>(n));

            return *this;
        }

        std::string
        str() const
        {
            return contents;
        }
    };

#if 0

    SimpleStream&
    operator <<(
        SimpleStream&       stm
    ,   char const*         s
    )
    {
        std::size_t const   len = ::strlen(s);

        stm.write(s, len);

        return stm;
    }
#endif
#ifdef USE_std_string

    SimpleStream&
    operator <<(
        SimpleStream&       stm
    ,   std::string const&  s
    )
    {
        stm.write(s.data(), s.size());

        return stm;
    }
#endif


    static char const       alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    static wchar_t const    alphabet_w[] = L"abcdefghijklmnopqrstuvwxyz";


// construction

static void test_ctor_default()
{
    {
        ss_constexpr_2020_k
        string_t s;

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }
}

static void test_ctor_copy()
{
    {
        string_t    s1;
        string_t    s2(s1);

        XTESTS_TEST_INTEGER_EQUAL(s1.size(), s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }

    {
        string_t    s1("abc");
        string_t    s2(s1);

        XTESTS_TEST_INTEGER_EQUAL(s1.size(), s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }
}

static void test_ctor_s_pos()
{
    {
        string_t    s1;
        string_t    s2(s1, 0);

        XTESTS_TEST_INTEGER_EQUAL(s1.size(), s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }

    {
        string_t    s1("abc");
        string_t    s2(s1, 1);

        XTESTS_TEST_INTEGER_EQUAL(2u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bc", s2);
    }
}

static void test_ctor_s_pos_n()
{
    {
        string_t    s1("abc");
        string_t    s2(s1, 0u, s1.size());

        XTESTS_TEST_INTEGER_EQUAL(s1.size(), s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }

    {
        string_t    s1("abc");
        string_t    s2(s1, 1u, s1.size() - 1u);

        XTESTS_TEST_INTEGER_EQUAL(2u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bc", s2);
    }

    // deliberately over-specify n
    {
        string_t    s1("abc");
        string_t    s2(s1, 1u, 500);

        XTESTS_TEST_INTEGER_EQUAL(2u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bc", s2);
    }
}

static void test_ctor_ccs()
{
    {
        string_t    s("abc");

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);
    }

#ifndef USE_std_string
    {
        string_t    s(static_cast<char const*>(NULL));

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }
#endif /* !USE_std_string */
}

static void test_ctor_ccs_n()
{
    {
        string_t    s(alphabet, 3);

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }

#ifndef USE_std_string
    {
        string_t    s(static_cast<char const*>(NULL), size_t(0));

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }
#endif /* !USE_std_string */
}

static void test_ctor_n_ch()
{
    {
        string_t    s(0, '~');

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
    }

    {
        string_t    s(8, '~');

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(8u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(8u, s.capacity());
#ifndef USE_std_string
        XTESTS_TEST_CHARACTER_EQUAL('~', s.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', s.back());

        string_t const& cs = s;

        XTESTS_TEST_CHARACTER_EQUAL('~', cs.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', cs.back());
#endif // !USE_std_string
    }

    {
        string_t    s(9, '~');

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(9u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(9u, s.capacity());
        XTESTS_TEST_CHARACTER_EQUAL('~', s.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', s.back());

        string_t const& cs = s;

        XTESTS_TEST_CHARACTER_EQUAL('~', cs.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', cs.back());
    }

    {
        string_t    s(10, '~');

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(10u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, s.capacity());
        XTESTS_TEST_CHARACTER_EQUAL('~', s.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', s.back());

        string_t const& cs = s;

        XTESTS_TEST_CHARACTER_EQUAL('~', cs.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', cs.back());
    }
}

static void test_ctor_range()
{
    string_t        s1(alphabet);
    string_t        s2(&alphabet[0], &alphabet[0] + STLSOFT_NUM_ELEMENTS(alphabet) -1);
    string_t const  s3(s1.begin(), s1.end());
    string_t        s4(s3.begin(), s3.end());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s1);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s2);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s3);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s4);
}

#ifndef USE_std_string

static void test_ctor_range_2()
{
    string_t        s1(alphabet);
    string_t        s2(&alphabet[0], &alphabet[0] + STLSOFT_NUM_ELEMENTS(alphabet) -1);
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_RANGE_METHOD_SUPPORT
    string_t const  s3(s1.rbegin(), s1.rend());
    string_t        s4(s3.rbegin(), s3.rend());
# endif

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s1);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s2);
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_RANGE_METHOD_SUPPORT
//  XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s3);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s4);
# endif
}
#endif /* !USE_std_string */


// `assign()`

static void test_assign_1()
{
    {
        string_t    s;

        s.assign("");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s = "";

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s = 'a';

        XTESTS_TEST_INTEGER_EQUAL(1u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", s);

        s = string_t();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.assign("abc");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.assign(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);

        s.assign("");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);
    }

    {
        string_t s;

        s.assign("");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.assign(s.c_str(), 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);
    }

    {
        string_t s;

        s.assign(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);

        s.assign(s.c_str(), 26);

        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);

        s.assign(s.c_str() + 13, 13);

        XTESTS_TEST_INTEGER_EQUAL(13u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("nopqrstuvwxyz", s);
    }
}

static void test_assign_2()
{
    {
        string_t    s;

        s.assign("", size_t(0));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.assign("abc", 3);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.assign(alphabet, 26);

        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);

        s.assign(alphabet, 3);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.assign("", size_t(0));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);
    }
}

static void test_assign_3()
{
    string_t const s_alphabet(alphabet);

    {
        string_t    s;

        s.assign(s_alphabet, 0, 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.assign(s_alphabet, 0, 3);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.assign(s_alphabet, 0, 26);

        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);

        s.assign(s_alphabet.begin(), s_alphabet.end());

        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);

        s.assign(s_alphabet, 25, 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);
    }
}

#ifndef USE_std_string

static void test_assign_4()
{
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_RANGE_METHOD_SUPPORT
    std::stringstream   ss("abc");

    string_t    s1 = string_t(std::istream_iterator<char>(ss), std::istream_iterator<char>());

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
# endif
}
#endif /* !USE_std_string */


// `append()`

static void test_append_1()
{
    string_t        s1;
    string_t const  s2("abc");

    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

    s1.append(s1, 0, 0);

    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

    s1.append(s2, 3u, 0u);

    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

    s1.append(s2, 0, 3);

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);

#ifndef USE_std_string
    s1.clear();
#else /* ? !USE_std_string */
    s1.erase(s1.begin(), s1.end());
#endif /* !USE_std_string */
    s1.append(s2, 2, 3);

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("c", s1);

#ifndef USE_std_string
    s1.clear();
#else /* ? !USE_std_string */
    s1.erase(s1.begin(), s1.end());
#endif /* !USE_std_string */
    s1.append(s2.begin(), s2.end());

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);

    std::stringstream   ss("abc");

#ifndef USE_std_string
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_RANGE_METHOD_SUPPORT
    s1.clear();
    s1.append(std::istream_iterator<char>(ss), std::istream_iterator<char>());

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
# endif
#endif /* !USE_std_string */
}

static void test_append_2()
{
    string_t    s1;
    char const  s2[] = "abc";

    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

    s1.append(s1, 0u, 0);

    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

    s1.append(s2, 3);

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);

    s1.append(s2, size_t(0));

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
}

static void test_append_3()
{
    string_t    s1;

    s1.append(s1, 1u, 0);

    XTESTS_TEST_FAIL("should not get here!");
}

#ifndef USE_std_string

static void test_push_back()
{
    string_t    s;

    XTESTS_TEST_BOOLEAN_TRUE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

    s.push_back('a');

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", s);

    s.push_back('b');

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab", s);

    s.push_back('c');

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);
}
#endif /* !USE_std_string */

static void test_pop_back()
{
    string_t s(alphabet, 10);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghij", s);

    s.pop_back();

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghi", s);

    s.pop_back();
    s.pop_back();
    s.pop_back();

    XTESTS_TEST_INTEGER_EQUAL(6u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", s);

    s.pop_back();
    s.pop_back();
    s.pop_back();
    s.pop_back();

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab", s);

    s.pop_back();

    XTESTS_TEST_INTEGER_EQUAL(1u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", s);

    s.pop_back();

    XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

    s.pop_back();

    XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);
}


// modifiers

static void test_reserve()
{
    {
        string_t    s;

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());

        s.reserve(10u);

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, s.capacity());
    }

    {
        string_t    s("abc");

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.reserve(10u);

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.reserve(1000u);

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1000u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);
    }
}

static void test_swap_1()
{
    {
        string_t    s1;
        string_t    s2;

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        s1.swap(s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
    }

    {
        string_t    s1("abc");
        string_t    s2;

        XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);

        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);

        s1.swap(s2);

        XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

        XTESTS_TEST_INTEGER_EQUAL(3u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s2);
    }
}

static void test_swap_2()
{
    {
        string_t    s1;
        string_t    s2;

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        swap(s1, s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
    }

    {
        string_t    s1("abc");
        string_t    s2;

        XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);

        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);

        swap(s1, s2);

        XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

        XTESTS_TEST_INTEGER_EQUAL(3u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s2);
    }
}

static void test_swap_3()
{
    {
        string_t    s1;
        string_t    s2;

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        std::swap(s1, s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
    }

    {
        string_t    s1("abc");
        string_t    s2;

        XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);

        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);

        std::swap(s1, s2);

        XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

        XTESTS_TEST_INTEGER_EQUAL(3u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s2);
    }
}

static void test_resize()
{
    {
        string_t    s;

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());

        s.resize(0u);

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t    s;

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());

        s.resize(3u, '~');

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~~~", s);
    }

    {
        string_t    s("abcdef");

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(6u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", s);

        s.resize(3u, '~');

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);
    }
}

#ifndef USE_std_string

static void test_clear()
{
    {
        string_t    s;

        s.clear();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t    s("abc");

        s.clear();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}
#endif /* !USE_std_string */

#ifdef USE_std_string

static void test_erase_0_param()
{
    {
        string_t    s;

        s.erase();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t    s("abc");

        s.erase();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}

static void test_erase_1_pos()
{
    {
        string_t    s;

        s.erase(size_t(0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t    s("abc");

        s.erase(size_t(0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}

static void test_erase_pos_and_cch()
{
    {
        string_t    s;

        s.erase(0u, 10u);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t    s("abc");

        s.erase(0u, 10u);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}
#endif


// attributes

static void test_size()
{
    {

    }
}

static void test_max_size()
{
    string_t s;

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1000000u, s.max_size());
}

static void test_length()
{

}

static void test_capacity()
{
    string_t s;

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());

    s.resize(10u);

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, s.capacity());

    s.resize(1000u);

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1000u, s.capacity());
}

static void test_empty()
{

}


// comparison

static void test_compare_1()
{
    string_t    s1("abc");
    string_t    s2("def");

    XTESTS_TEST_BOOLEAN_TRUE(s1 != s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 != s2.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s1.c_str() != s2);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(s1, s2);

    XTESTS_TEST_BOOLEAN_TRUE(s1 < s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 < s2.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s1.c_str() < s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 <= s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 <= s2.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s1.c_str() <= s2);
    XTESTS_TEST_BOOLEAN_TRUE(s2 > s1);
    XTESTS_TEST_BOOLEAN_TRUE(s2 > s1.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s2.c_str() > s1);
    XTESTS_TEST_BOOLEAN_TRUE(s2 >= s1);
    XTESTS_TEST_BOOLEAN_TRUE(s2 >= s1.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s2.c_str() >= s1);

    XTESTS_TEST_BOOLEAN_TRUE(s1 == s1);
    XTESTS_TEST_BOOLEAN_TRUE(s1 == s1.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s1 == "abc");
    XTESTS_TEST_BOOLEAN_TRUE(s1.c_str() == s1);
    XTESTS_TEST_BOOLEAN_TRUE("abc" == s1);

    XTESTS_TEST_BOOLEAN_TRUE(s1 != s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 != s2.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s1 != "def");
    XTESTS_TEST_BOOLEAN_TRUE(s1.c_str() != s2);
    XTESTS_TEST_BOOLEAN_TRUE("abc" != s2);
}

static void test_compare_2()
{
    string_t    s1("abc");
    string_t    s2("def");

    XTESTS_TEST_INTEGER_LESS(0, s1.compare(s2));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, s2));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, s2.c_str()));
//  XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 4u, s2.c_str()));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, s2.c_str(), s2.size()));
}

static void test_compare_3()
{
    string_t    s1("def");

    XTESTS_TEST_INTEGER_LESS(0, s1.compare("ghi"));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, "ghi"));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(3u, 0u, "ghi"));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 2u, "ghi"));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 2u, "ghi", 2u));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(3u, 2u, "ghi", 2u));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(3u, 2u, "ghi", 0u, 2u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(0u, 2u, "abc", 0u, 2u));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(3u, 2u, "abc", 0u, 2u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 2u, "ghi", 3u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 2u, "ghi", 3u, 2u));


    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(0u, 0u, "def", 0u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 0u, "def", 1u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 0u, "def", 2u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 0u, "def", 3u, 0u));

    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(0u, 1u, "def", 0u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 1u, "def", 1u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 1u, "def", 2u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 1u, "def", 3u, 1u));

    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(0u, 2u, "def", 0u, 2u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 2u, "def", 1u, 2u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 2u, "def", 2u, 2u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 2u, "def", 3u, 2u));

    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(0u, 3u, "def", 0u, 3u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 3u, "def", 1u, 3u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 3u, "def", 2u, 3u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 3u, "def", 3u, 3u));


    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(0u, 0u, "fed", 0u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 0u, "fed", 1u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 0u, "fed", 2u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 0u, "fed", 3u, 0u));

    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 1u, "fed", 0u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 1u, "fed", 1u, 1u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(2u, 1u, "fed", 2u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 1u, "fed", 3u, 1u));

    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 2u, "fed", 0u, 2u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(1u, 2u, "fed", 1u, 2u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(2u, 2u, "fed", 2u, 2u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 2u, "fed", 3u, 2u));

    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, "fed", 0u, 3u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(1u, 3u, "fed", 1u, 3u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(2u, 3u, "fed", 2u, 3u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 3u, "fed", 3u, 3u));
}

static void test_compare_4()
{
    {
        string_t    s1("mno");
        string_t    s2("mnopqr");

        XTESTS_TEST_INTEGER_LESS(0, s1.compare(s2));
        XTESTS_TEST_INTEGER_LESS(0, s1.compare(s2.c_str()));
        XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, s1.size(), s2));
    }
}

static void test_equality_operators_1()
{
    string_t    s1("abc");
    string_t    s2("def");
    string_t    s3("abc");
    string_t    s4("def");

    XTESTS_TEST_BOOLEAN_TRUE(s1 == s1);
    XTESTS_TEST_BOOLEAN_FALSE(s1 != s1);
    XTESTS_TEST_BOOLEAN_TRUE(s1 != s2);
    XTESTS_TEST_BOOLEAN_FALSE(s1 == s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 == s3);
    XTESTS_TEST_BOOLEAN_FALSE(s1 != s3);
    XTESTS_TEST_BOOLEAN_TRUE(s1 != s4);
    XTESTS_TEST_BOOLEAN_FALSE(s1 == s4);
}

#ifndef USE_std_string

static void test_equal_p_n_ccs_n()
{
    string_t    s1("abc");
    string_t    s2("def");
    string_t    s3("abc");
    string_t    s4("def");

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 3, s1.c_str(), 3));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(0, 3, s2.c_str(), 3));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 3, s3.c_str(), 3));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(0, 3, s4.c_str(), 3));
}

static void test_equal_p_n_ccs()
{
    string_t    s1("abc");
    string_t    s2("def");
    string_t    s3("abc");
    string_t    s4("def");

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 3, s1.c_str()));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(0, 3, s2.c_str()));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 3, s3.c_str()));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(0, 3, s4.c_str()));

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 3, "abc"));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(1, 2, "bc"));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(2, 1, "c"));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(3, 0, ""));

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 4, "abc"));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 444, "abc"));

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(1, 3, "bc"));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(1, 333, "bc"));

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(2, 2, "c"));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(2, 222, "c"));
}

static void test_equal_ccs()
{
    string_t    s1("abc");
    string_t    s2("def");
    string_t    s3("abc");
    string_t    s4("def");

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(s1.c_str()));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(s2.c_str()));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(s3.c_str()));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(s4.c_str()));
}

static void test_equal_p_n_scr_p_n()
{
    string_t    s0;
    string_t    s1("abc");
    string_t    s2("def");
    string_t    s3("abcd");
    string_t    s4("defg");

    XTESTS_TEST_BOOLEAN_TRUE(s0.equal(0, 0, s0, 0, 0));
    XTESTS_TEST_BOOLEAN_TRUE(s0.equal(0, 1, s0, 0, 0));
    XTESTS_TEST_BOOLEAN_FALSE(s0.equal(0, 0, s0, 0, 1));

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 0, s0, 0, 0));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 1, s0, 0, 0));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 2, s0, 0, 0));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(1, 0, s0, 0, 0));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(1, 1, s0, 0, 0));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(1, 2, s0, 0, 0));

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 3, s1, 0, s1.size()));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(0, 3, s2, 0, s2.size()));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 3, s1, 0, s1.size()));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(0, 3, s3, 0, s3.size()));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(0, 3, s4, 0, s4.size()));

    XTESTS_TEST_BOOLEAN_FALSE(s3.equal(0, 1, s1));
    XTESTS_TEST_BOOLEAN_FALSE(s3.equal(0, 2, s1));
    XTESTS_TEST_BOOLEAN_TRUE(s3.equal(0, 3, s1));
    XTESTS_TEST_BOOLEAN_FALSE(s3.equal(0, 4, s1));
}

static void test_equal_p_n_scr()
{
    string_t    s0;
    string_t    s1("abc");
    string_t    s2("def");
    string_t    s3("abcd");
    string_t    s4("defg");

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 0, s0));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 1, s0));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 2, s0));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(1, 0, s0));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(1, 1, s0));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(1, 2, s0));

    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 3, s1));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(0, 3, s2));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(0, 3, s1));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(0, 3, s3));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(0, 3, s4));

    XTESTS_TEST_BOOLEAN_FALSE(s3.equal(0, 1, s1));
    XTESTS_TEST_BOOLEAN_FALSE(s3.equal(0, 2, s1));
    XTESTS_TEST_BOOLEAN_TRUE(s3.equal(0, 3, s1));
    XTESTS_TEST_BOOLEAN_FALSE(s3.equal(0, 4, s1));
}

static void test_equal_scr()
{
    string_t    s0;
    string_t    s1("abc");
    string_t    s2("def");
    string_t    s3("abc");
    string_t    s4("def");

    XTESTS_TEST_BOOLEAN_TRUE(s0.equal(s0));
    XTESTS_TEST_BOOLEAN_FALSE(s0.equal(s1));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(s1));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(s2));
    XTESTS_TEST_BOOLEAN_TRUE(s1.equal(s3));
    XTESTS_TEST_BOOLEAN_FALSE(s1.equal(s4));
}
#endif /* !USE_std_string */

#if !defined(USE_std_string) || \
    __cplusplus >= 202002L

static void test_starts_with_1()
{
    string_t const s;

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with(""));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("a"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("b"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("c"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("d"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("e"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("i"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("o"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("u"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("x"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("y"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("z"));

        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("ab"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("abc"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("abcd"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("abcde"));

        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("aa"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("bcde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("acde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("abde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("abce"));
    }

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with(string_t("")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("a")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("b")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("c")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("d")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("e")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("i")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("o")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("u")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("x")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("y")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("z")));

        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("ab")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("abc")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("abcd")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("abcde")));

        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("aa")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("bcde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("acde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("abde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("abce")));
    }

    {
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('a'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('b'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('c'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('d'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('e'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('i'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('o'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('u'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('x'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('y'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('z'));
    }
}

static void test_starts_with_2()
{
    string_t const s(alphabet);

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with(""));
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with("a"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("b"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("c"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("d"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("e"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("i"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("o"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("u"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("x"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("y"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("z"));

        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with("ab"));
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with("abc"));
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with("abcd"));
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with("abcde"));

        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("aa"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("bcde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("acde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("abde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with("abce"));
    }

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with(string_t("")));
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with(string_t("a")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("b")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("c")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("d")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("e")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("i")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("o")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("u")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("x")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("y")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("z")));

        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with(string_t("ab")));
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with(string_t("abc")));
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with(string_t("abcd")));
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with(string_t("abcde")));

        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("aa")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("bcde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("acde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("abde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with(string_t("abce")));
    }

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.starts_with('a'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('b'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('c'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('d'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('e'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('i'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('o'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('u'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('x'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('y'));
        XTESTS_TEST_BOOLEAN_FALSE(s.starts_with('z'));
    }
}

static void test_contains_1()
{
    string_t const s;

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(""));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("a"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("b"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("c"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("d"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("e"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("i"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("o"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("u"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("x"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("y"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("z"));

        XTESTS_TEST_BOOLEAN_FALSE(s.contains("ab"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("abc"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("abcd"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("abcde"));

        XTESTS_TEST_BOOLEAN_FALSE(s.contains("aa"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("bcde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("acde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("abde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("abce"));
    }

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("a")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("b")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("c")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("d")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("e")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("i")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("o")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("u")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("x")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("y")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("z")));

        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("ab")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("abc")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("abcd")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("abcde")));

        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("aa")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("bcde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("acde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("abde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("abce")));
    }

    {
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('a'));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('b'));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('c'));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('d'));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('e'));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('i'));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('o'));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('u'));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('x'));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('y'));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('z'));
    }
}

static void test_contains_2()
{
    string_t const s(alphabet);

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(""));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("a"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("b"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("c"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("d"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("e"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("i"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("o"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("u"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("x"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("y"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("z"));

        XTESTS_TEST_BOOLEAN_TRUE(s.contains("ab"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("abc"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("abcd"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("abcde"));

        XTESTS_TEST_BOOLEAN_FALSE(s.contains("aa"));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains("bcde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("acde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("abde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains("abce"));
    }

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("a")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("b")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("c")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("d")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("e")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("i")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("o")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("u")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("x")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("y")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("z")));

        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("ab")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("abc")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("abcd")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("abcde")));

        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("aa")));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains(string_t("bcde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("acde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("abde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains(string_t("abce")));
    }

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('a'));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('b'));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('c'));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('d'));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('e'));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('i'));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('o'));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('u'));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('x'));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('y'));
        XTESTS_TEST_BOOLEAN_TRUE(s.contains('z'));

        XTESTS_TEST_BOOLEAN_FALSE(s.contains(' '));
        XTESTS_TEST_BOOLEAN_FALSE(s.contains('*'));
    }
}

static void test_contains_3()
{
    {
        string_t const s("abdabeabcab");

        {
            XTESTS_TEST_BOOLEAN_TRUE(s.contains("abc"));
        }
    }

    {
        string_t const s("abdabeabfab");

        {
            XTESTS_TEST_BOOLEAN_FALSE(s.contains("abc"));
        }
    }

    {
        string_t const s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");

        {
            XTESTS_TEST_BOOLEAN_TRUE(s.contains("ab"));
            XTESTS_TEST_BOOLEAN_FALSE(s.contains("ac"));
        }
    }
}

static void test_ends_with_1()
{
    string_t const s;

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with(""));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("a"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("b"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("c"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("d"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("e"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("i"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("o"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("u"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("x"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("y"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("z"));

        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("yz"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("xyz"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("wxyz"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("vwxyz"));

        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("aa"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("bcde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("acde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("abde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("abce"));
    }

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with(string_t("")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("a")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("b")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("c")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("d")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("e")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("i")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("o")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("u")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("x")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("y")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("z")));

        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("yz")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("xyz")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("wxyz")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("vwxyz")));

        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("aa")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("bcde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("acde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("abde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("abce")));
    }


    {
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('a'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('b'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('c'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('d'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('e'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('i'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('o'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('u'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('x'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('y'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('z'));
    }
}

static void test_ends_with_2()
{
    string_t const s(alphabet);

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with(""));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("a"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("b"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("c"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("d"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("e"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("i"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("o"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("u"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("x"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("y"));
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with("z"));

        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with("yz"));
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with("xyz"));
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with("wxyz"));
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with("vwxyz"));

        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("aa"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("bcde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("acde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("abde"));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with("abce"));
    }

    {
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with(string_t("")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("a")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("b")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("c")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("d")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("e")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("i")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("o")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("u")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("x")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("y")));
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with(string_t("z")));

        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with(string_t("yz")));
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with(string_t("xyz")));
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with(string_t("wxyz")));
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with(string_t("vwxyz")));

        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("aa")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("bcde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("acde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("abde")));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with(string_t("abce")));
    }


    {
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('a'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('b'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('c'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('d'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('e'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('i'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('o'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('u'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('x'));
        XTESTS_TEST_BOOLEAN_FALSE(s.ends_with('y'));
        XTESTS_TEST_BOOLEAN_TRUE(s.ends_with('z'));
    }
}
#endif


// accessors

static void test_at_1()
{
    string_t    s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s.at(0u));
    XTESTS_TEST_CHARACTER_EQUAL('b', s.at(1u));
    XTESTS_TEST_CHARACTER_EQUAL('c', s.at(2u));
}

static void test_at_2()
{
    string_t const s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s.at(0u));
    XTESTS_TEST_CHARACTER_EQUAL('b', s.at(1u));
    XTESTS_TEST_CHARACTER_EQUAL('c', s.at(2u));
}

static void test_at_3()
{
    string_t    s;

    s.at(0u);
}

static void test_at_4()
{
    string_t const s("abc");

    s.at(3u);
}

static void test_index_1()
{
    string_t    s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s[0u]);
    XTESTS_TEST_CHARACTER_EQUAL('b', s[1u]);
    XTESTS_TEST_CHARACTER_EQUAL('c', s[2u]);
}

static void test_index_2()
{
    string_t const s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s[0u]);
    XTESTS_TEST_CHARACTER_EQUAL('b', s[1u]);
    XTESTS_TEST_CHARACTER_EQUAL('c', s[2u]);
    XTESTS_TEST_CHARACTER_EQUAL('\0', s[3u]);
}

static void test_copy()
{
    string_t const s_alphabet(alphabet);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s_alphabet);

    {
        string_t    s;
        char        dest[101];
        size_t      cch = s.copy(&dest[0], STLSOFT_NUM_ELEMENTS(dest), 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

#ifndef USE_std_string

    {
        string_t    s;
        char        dest[101];
        size_t      cch = s.copy(&dest[0], STLSOFT_NUM_ELEMENTS(dest), 10);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }
#endif

    {
        string_t    s("abc");
        char        dest[101];
        size_t      cch = s.copy(&dest[0], STLSOFT_NUM_ELEMENTS(dest), 0);

        XTESTS_TEST_INTEGER_EQUAL(3u, cch);
    }

    {
        string_t    s("abc");
        char        dest[101];
        size_t      cch = s.copy(&dest[0], STLSOFT_NUM_ELEMENTS(dest), 2);

        XTESTS_TEST_INTEGER_EQUAL(1u, cch);
    }

    {
        string_t    s("abc");
        char        dest[101];
        size_t      cch = s.copy(&dest[0], STLSOFT_NUM_ELEMENTS(dest), 3);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

    {
        char dest[26 + 1] = { 0 };

        size_t n = s_alphabet.copy(&dest[0], 26);
        dest[26] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(26u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", dest);
    }

    {
        char dest[20 + 1] = { 0 };

        size_t n = s_alphabet.copy(&dest[0], 20);
        dest[20] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(20u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrst", dest);
    }

    {
        char dest[20 + 1] = { 0 };

        size_t n = s_alphabet.copy(&dest[0], 20, 6);
        dest[20] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(20u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghijklmnopqrstuvwxyz", dest);
    }

    {
        char dest[10 + 1] = { 0 };

        size_t n = s_alphabet.copy(&dest[0], 20, 16);
        dest[10] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(10u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("qrstuvwxyz", dest);
    }
}

static void test_substr()
{
    string_t const  s1("abcdefghi");
    string_t        s2 = s1.substr(0);
    string_t        s3 = s1.substr(0, s1.size());
    string_t        s4 = s1.substr(0, s1.size() * 2);
    string_t        s5 = s1.substr();

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s3);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s4);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

static void test_substr_throw()
{
    string_t const  s1("abcdefghi");
    string_t        s2 = s1.substr(s1.size() + 1);

    XTESTS_TEST_FAIL("should not get here");
}


// search

#ifdef USE_std_string

static void test_find_char()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('\0'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('\0'));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find('a'));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find('z'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('A'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('\0'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('\0', 1u));
    }
}

static void test_find_c_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find("", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 2u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 3u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 4u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 5u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 6u));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find("", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 2u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 3u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 4u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 5u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 6u));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("abc", 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find("", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find("", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find("", 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find("", 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find("", 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find("", 5u));
        XTESTS_TEST_INTEGER_EQUAL(6u, s.find("", 6u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 7u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 8u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find("abc"));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find("bcd", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find("bcd", 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("bdc", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("bdc", 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find("z"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("A"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("a", 1u));
    }
}

static void test_find_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("abc", 4u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find(string_t("bcd"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find(string_t("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("bdc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("bdc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("A")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("a"), 1u));
    }
}

static void test_rfind_char()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('\0'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('\0'));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind('a', 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a', 5u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a', 6u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a', 100u));

        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind('b'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind('b', 5u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind('b', 6u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind('b', 100u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.rfind('z'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('A'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('\0'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('\0', 1u));
    }
}

static void test_rfind_c_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("", 0u));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("", 0u));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc"));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 7u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 6u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 5u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 3u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 0u));
        XTESTS_TEST_INTEGER_EQUAL(6u, s.rfind(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.rfind("", 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("", 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind("", 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.rfind("", 5u));
        XTESTS_TEST_INTEGER_EQUAL(6u, s.rfind("", 6u));
        XTESTS_TEST_INTEGER_EQUAL(6u, s.rfind("", 7u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("bcd", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 4u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 5u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 6u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 7u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 100u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("bdc", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("bdc", 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.rfind("z"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("A"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("a", 1u));
    }
}

static void test_rfind_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 3u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 5u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 6u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 100u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("bcd"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 5u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 10u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 20u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 100u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("bdc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("bdc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.rfind(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("A")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(string_t("a")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(string_t("a"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(string_t("a"), 1u));
    }
}

static void test_find_first_of_char()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('\0'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('\0'));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_first_of('z'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('A'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('\0'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('\0', 1u));
    }
}

static void test_find_first_of_c_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("abc"));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("abc"));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("defghijklmnopqrstuvwxyz", 4u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_of("abc"));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of("bcd", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of("dcb", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of("bcd", 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("BDC", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("aBDC", 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_first_of("z"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("A"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("a", 1u));
    }
}

static void test_find_first_of_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("defghijklmnopqrstuvwxyz"), 4u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_of(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of(string_t("bcd"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of(string_t("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of(string_t("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("BDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_first_of(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("A")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("a"), 1u));
    }
}

static void test_find_last_of_char()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('\0'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('\0'));
    }

    {
        string_t    s("a");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('\0'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('\0', 1u));
    }

    {
        string_t    s("ab");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('b', 0u));
    }

    {
        string_t    s("abab");

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('b', 0u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_of('a', 51u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_of('a', 27u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_of('a', 26u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 25u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_of('b', 51u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_of('b', 50u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_of('b', 28u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_of('b', 27u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 26u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 10u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('b', 0u));

        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_of('z'));
        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_of('z', 51u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of('z', 50u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of('z', 26u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of('z', 25u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('z', 24u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('z', 10u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('z', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('z', 0u));
    }
}

static void test_find_last_of_c_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("abc"));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("abc"));
    }

    {
        string_t    s("abc");

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc"));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("defghijklmnopqrstuvwxyz", 4u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("abc", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("abc", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc", 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc", 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc", 20u));

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("bca"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("bca", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("bca", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("bca", 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("bca", 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("bca", 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("bca", 20u));

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("cab"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("cab", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("cab", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("cab", 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("cab", 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("cab", 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("cab", 20u));

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of("dcb"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("dcb", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("dcb", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("dcb", 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of("dcb", 3u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of("dcb", 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of("dcb", 20u));

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("BDC"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("BDC", 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("aBDC"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("aBDC", 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("aBDC", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("aBDC", 20u));

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("AbDC"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("AbDC", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("AbDC", 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("AbDC", 20u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("a"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("a", 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("a", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("a", 20u));

        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of("z"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("z", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("z", 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("z", 20u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("z", 24u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of("z", 25u));

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("A"));
    }
}

static void test_find_last_of_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("defghijklmnopqrstuvwxyz"), 4u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("abc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("abc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("abc"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("abc"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("abc"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("abc"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("bca")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("bca"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("bca"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("bca"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("bca"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("bca"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("bca"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("cab")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("cab"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("cab"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("cab"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("cab"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("cab"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("cab"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of(string_t("dcb")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("dcb"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("dcb"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of(string_t("dcb"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of(string_t("dcb"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of(string_t("dcb"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("BDC")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("BDC"), 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("aBDC")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("aBDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("aBDC"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("AbDC")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("AbDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("AbDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("AbDC"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("a")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("a"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("a"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("a"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("z"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("z"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("z"), 20u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("z"), 24u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of(string_t("z"), 25u));

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("A")));
    }
}

static void test_find_first_not_of_char()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a'));
    }

    {
        string_t    s("a");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 2u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 2u));
    }

    {
        string_t    s("ab");

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b', 0u));
    }

    {
        string_t    s("abab");

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b', 0u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_first_not_of('a', 51u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_first_not_of('a', 27u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_first_not_of('a', 26u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_first_not_of('a', 25u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_first_not_of('b', 51u));
        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_first_not_of('b', 50u));
        XTESTS_TEST_INTEGER_EQUAL(28u, s.find_first_not_of('b', 28u));
        XTESTS_TEST_INTEGER_EQUAL(28u, s.find_first_not_of('b', 27u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_first_not_of('b', 26u));
        XTESTS_TEST_INTEGER_EQUAL(10u, s.find_first_not_of('b', 10u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b', 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('z'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('z', 51u));
        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_first_not_of('z', 50u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_first_not_of('z', 26u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_first_not_of('z', 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_first_not_of('z', 24u));
        XTESTS_TEST_INTEGER_EQUAL(10u, s.find_first_not_of('z', 10u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('z', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('z', 0u));
    }
}

static void test_find_first_not_of_c_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(("abc")));
    }

    {
        string_t    s("xyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 5u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 6u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 7u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("abc")));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("abc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("abc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("abc"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("abc"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(("abc"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("BDC")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("BDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(("z"), 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_first_not_of(("z"), 24u));
        XTESTS_TEST_INTEGER_EQUAL(23u, s.find_first_not_of(("z"), 23u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("A")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(("a"), 1u));
    }
}

static void test_find_first_not_of_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(string_t("abc")));
    }

    {
        string_t    s("xyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 5u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 6u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 7u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("abc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("abc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("abc"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("abc"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(string_t("abc"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(string_t("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("BDC")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("BDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(string_t("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(string_t("z"), 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_first_not_of(string_t("z"), 24u));
        XTESTS_TEST_INTEGER_EQUAL(23u, s.find_first_not_of(string_t("z"), 23u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("A")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(string_t("a"), 1u));
    }
}

static void test_find_last_not_of_char()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a'));
    }

    {
        string_t    s("a");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 2u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 2u));
    }

    {
        string_t    s("ab");

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 0u));
    }

    {
        string_t    s("abab");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 0u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_not_of('a', 51u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_not_of('a', 27u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of('a', 26u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of('a', 25u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_not_of('b', 51u));
        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_last_not_of('b', 50u));
        XTESTS_TEST_INTEGER_EQUAL(28u, s.find_last_not_of('b', 28u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_not_of('b', 27u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_not_of('b', 26u));
        XTESTS_TEST_INTEGER_EQUAL(10u, s.find_last_not_of('b', 10u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 0u));

        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_last_not_of('z'));
        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_last_not_of('z', 51u));
        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_last_not_of('z', 50u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_not_of('z', 26u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of('z', 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of('z', 24u));
        XTESTS_TEST_INTEGER_EQUAL(10u, s.find_last_not_of('z', 10u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('z', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('z', 0u));
    }
}

static void test_find_last_not_of_c_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(("abc")));
    }

    {
        string_t    s("xyz");

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of(("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 5u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 6u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 7u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(("abc")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(("abc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(("abc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(("abc"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of(("abc"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_last_not_of(("abc"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(("BDC")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(("BDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(("z")));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(("z"), 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(("z"), 24u));
        XTESTS_TEST_INTEGER_EQUAL(23u, s.find_last_not_of(("z"), 23u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(("A")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(("a"), 1u));
    }
}

static void test_find_last_not_of_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(string_t("abc")));
    }

    {
        string_t    s("xyz");

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 5u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 6u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 7u));
    }

    {
        string_t    s(alphabet);

        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(string_t("abc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(string_t("abc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(string_t("abc"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of(string_t("abc"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_last_not_of(string_t("abc"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(string_t("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(string_t("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(string_t("BDC")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(string_t("BDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(string_t("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(string_t("z"), 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(string_t("z"), 24u));
        XTESTS_TEST_INTEGER_EQUAL(23u, s.find_last_not_of(string_t("z"), 23u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(string_t("A")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(string_t("a"), 1u));
    }
}
#endif


// traits

static void test_stlsoft_char_traits()
{
    {
        typedef stlsoft::char_traits<char> traits_t;

        // assign
        {
            char        buff4[4] = { '1', '2', '3', '4' };

            traits_t::assign(buff4, 3, 'a');

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("aaa4", buff4, 4);
        }

        // compare
        {
            {
                int const r = traits_t::compare("abc", "abc", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare("abcd", "abce", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare("a\0cd", "a\0ce", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare("a\0d", "a\0e", 3);

                XTESTS_TEST_INTEGER_NOT_EQUAL(0, r);
            }
        }

        // compare_max
        {
            {
                int const r = traits_t::compare_max("abc", "abc", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare_max("abcd", "abce", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare_max("a\0cd", "a\0ce", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare_max("a\0d", "a\0e", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }
        }

        // find
        {
            {
                char buff4[4] = { '1', '2', '3', '4' };

                char const* i = traits_t::find(buff4, 4, '3');

                XTESTS_TEST_INTEGER_EQUAL(2, i - buff4);
            }

            {
                char const* i = traits_t::find(alphabet, 26, 'm');

                XTESTS_TEST_INTEGER_EQUAL(12, i - alphabet);
            }

            {
                char const* i = traits_t::find(alphabet, 11, 'm');

                XTESTS_TEST_POINTER_EQUAL(ss_nullptr_k, i);
            }
        }

        // length
        {
            {
                ss_size_t const r = traits_t::length("");

                XTESTS_TEST_INTEGER_EQUAL(0u, r);
            }

            {
                ss_size_t const r = traits_t::length("abc");

                XTESTS_TEST_INTEGER_EQUAL(3u, r);
            }

            {
                ss_size_t const r = traits_t::length(alphabet);

                XTESTS_TEST_INTEGER_EQUAL(26u, r);
            }
        }

        // length_max
        {
            {
                ss_size_t const r = traits_t::length_max("", 0);

                XTESTS_TEST_INTEGER_EQUAL(0u, r);
            }

            {
                ss_size_t const r = traits_t::length_max("", 10);

                XTESTS_TEST_INTEGER_EQUAL(0u, r);
            }

            {
                ss_size_t const r = traits_t::length_max("abc", 3);

                XTESTS_TEST_INTEGER_EQUAL(3u, r);
            }

            {
                ss_size_t const r = traits_t::length_max("abc", 2);

                XTESTS_TEST_INTEGER_EQUAL(2u, r);
            }

            {
                ss_size_t const r = traits_t::length_max("abc", 22);

                XTESTS_TEST_INTEGER_EQUAL(3u, r);
            }

            {
                ss_size_t const r = traits_t::length_max(alphabet, 1000);

                XTESTS_TEST_INTEGER_EQUAL(26u, r);
            }
        }
    }

    {
        typedef stlsoft::char_traits<wchar_t> traits_t;

        // assign
        {
            wchar_t buff4[4] = { '1', '2', '3', '4' };

            traits_t::assign(buff4, 3, L'a');

            XTESTS_TEST_WIDE_STRING_EQUAL_N(L"aaa4", buff4, 4);
        }

        // compare
        {
            {
                int const r = traits_t::compare(L"abc", L"abc", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare(L"abcd", L"abce", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare(L"a\0cd", L"a\0ce", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare(L"a\0d", L"a\0e", 3);

                XTESTS_TEST_INTEGER_NOT_EQUAL(0, r);
            }
        }

        // compare_max
        {
            {
                int const r = traits_t::compare_max(L"abc", L"abc", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare_max(L"abcd", L"abce", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare_max(L"a\0cd", L"a\0ce", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }

            {
                int const r = traits_t::compare_max(L"a\0d", L"a\0e", 3);

                XTESTS_TEST_INTEGER_EQUAL(0, r);
            }
        }

        // find
        {
            {
                wchar_t buff4[4] = { '1', '2', '3', '4' };

                wchar_t const* i = traits_t::find(buff4, 4, '3');

                XTESTS_TEST_INTEGER_EQUAL(2, i - buff4);
            }

            {
                wchar_t const* i = traits_t::find(alphabet_w, 26, 'm');

                XTESTS_TEST_INTEGER_EQUAL(12, i - alphabet_w);
            }

            {
                wchar_t const* i = traits_t::find(alphabet_w, 11, 'm');

                XTESTS_TEST_POINTER_EQUAL(ss_nullptr_k, i);
            }
        }

        // length
        {
            {
                ss_size_t const r = traits_t::length(L"");

                XTESTS_TEST_INTEGER_EQUAL(0u, r);
            }

            {
                ss_size_t const r = traits_t::length(L"abc");

                XTESTS_TEST_INTEGER_EQUAL(3u, r);
            }

            {
                ss_size_t const r = traits_t::length(alphabet_w);

                XTESTS_TEST_INTEGER_EQUAL(26u, r);
            }
        }

        // length_max
        {
            {
                ss_size_t const r = traits_t::length_max(L"", 0);

                XTESTS_TEST_INTEGER_EQUAL(0u, r);
            }

            {
                ss_size_t const r = traits_t::length_max(L"", 10);

                XTESTS_TEST_INTEGER_EQUAL(0u, r);
            }

            {
                ss_size_t const r = traits_t::length_max(L"abc", 3);

                XTESTS_TEST_INTEGER_EQUAL(3u, r);
            }

            {
                ss_size_t const r = traits_t::length_max(L"abc", 2);

                XTESTS_TEST_INTEGER_EQUAL(2u, r);
            }

            {
                ss_size_t const r = traits_t::length_max(L"abc", 22);

                XTESTS_TEST_INTEGER_EQUAL(3u, r);
            }

            {
                ss_size_t const r = traits_t::length_max(alphabet_w, 1000);

                XTESTS_TEST_INTEGER_EQUAL(26u, r);
            }
        }
    }
}

static void test_string_traits()
{
    {
        string_t    s = stlsoft::string_traits<string_t>::empty_string();

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }

    {
        string_t    s1;
        string_t    s2("abc");
        string_t    s3("def");

        string_t    s4 = stlsoft::string_traits<string_t>::construct(s1, 0u, s1.size());
        string_t    s5 = stlsoft::string_traits<string_t>::construct(s2, 0u, s2.size());
        string_t    s6 = stlsoft::string_traits<string_t>::construct(s3, 0u, s3.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s4);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s2, s5);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s3, s6);
    }

    {
        string_t    s1;
        string_t    s2("abc");

        stlsoft::string_traits<string_t>::assign_inplace(s1, s2.begin(), s2.end());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }
}


// operators : concatenation

static void test_concatenation_1()
{
    string_t    s1(alphabet);
    string_t    s2(s1, 0, 10);
    string_t    s3(s1, 10, 10);
    string_t    s4(s1, 20, 6);
    string_t    s5 = s2 + s3 + s4;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

static void test_concatenation_2()
{
    string_t    s1(alphabet);
    string_t    s2 = s1.substr(0, 10);
    string_t    s3 = s1.substr(10, 10);
    string_t    s4 = s1.substr(20, 6);
    string_t    s5 = s2 + s3 + s4;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

#ifdef USE_std_string

static void test_concatenation_3()
{
    string_t    s1(alphabet);
    string_t    s2 = s1.substr(0, 10);
    string_t    s3 = s1;
                s3.erase(0, 10);
                s3.erase(10);
    string_t    s4 = s1.substr(20, 6);
    string_t    s5 = s2 + s3 + s4;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

static void test_concatenation_4()
{
    string_t    s1(alphabet);
    string_t    s2 = s1.substr(0, 10);
    string_t    s3 = s1;
                s3.erase(s3.begin(), s3.begin() + 10);
                s3.erase(s3.begin() + 10, s3.end() - 1);
                s3.erase(s3.end() - 1);
    string_t    s4 = s1.substr(20, 6);
    string_t    s5 = s2 + s3 + s4;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

static void test_concatenation_5()
{
    string_t    s1(alphabet);
    string_t    s2 = s1.substr(0, 10);
    string_t    s3 = s1;
                s3.erase(s3.begin(), s3.begin() + 10);
                s3.erase(s3.begin() + 10, s3.end() - 1);
                s3.erase(s3.end() - 1);
    string_t    s4 = s1.substr(20, 6);
    string_t    s5 = s2 + s3.c_str() + s4;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}
#endif

static void test_concatenation_6()
{
    string_t    s;

    XTESTS_TEST_BOOLEAN_TRUE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

    s += 'a';

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", s);

    s = s + 'b';

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab", s);

    s = 'c' + s;

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("cab", s);

    s = "" + s;

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("cab", s);
}


// operators : insertion

static void test_insertion_1()
{
    string_t const  s1;
    string_t const  s2("abc");
    string_t const  s3("def");

    {
        std::stringstream   ss;

        ss
            << std::left
            << s1
            << s2
            << std::right
            << s3
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", ss.str());
    }

    {
        SimpleStream    ss;

        ss
            << s1
            << s2
            << s3
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", ss.str());
    }
}

static void test_insertion_2()
{
    string_t const  s2("abc");
    string_t const  s3("def");

    {
        std::stringstream ss;

        ss
            << std::setw(2)
            << std::left
            << s2
            << std::right
            << s3
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", ss.str());
    }
}

static void test_insertion_3()
{
    string_t const  s1;
    string_t const  s2("abc");
    string_t const  s3("def");

    {
        std::stringstream ss;

        ss
            << std::setfill('_')
            << std::setw(4)
            << s1
            << std::setw(4) << std::left
            << s2
            << std::setw(4) << std::right
            << s3
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("____abc__def", ss.str());
    }
}

static void test_insertion_4()
{
    const std::size_t FIELD_WIDTH = 2000;
#if defined(_MSC_VER) &&\
    _MSC_VER == 1700

    STLSOFT_SUPPRESS_UNUSED(&FIELD_WIDTH);
# define FIELD_WIDTH (2000)
#endif

    string_t const  s1;
    string_t const  s2("abc");
    string_t const  s3("defg");

    std::stringstream   ss;

    ss
        << std::setfill('_')
        << std::setw(FIELD_WIDTH)
        << s1
        << std::setw(FIELD_WIDTH) << std::left
        << s2
        << std::setw(FIELD_WIDTH) << std::right
        << s3
        ;


#if __cplusplus >= 201402L
    std::string expected = ([&s2, &s3, FIELD_WIDTH]() {
#else
    struct Expected
    {
        static
        std::string
        fn(
            string_t const& s2
        ,   string_t const& s3
        )
#endif

        {
            std::string r;

            r.append(FIELD_WIDTH, '_');

            r.append(s2.data(), s2.size());
            r.append(FIELD_WIDTH - s2.size(), '_');

            r.append(FIELD_WIDTH - s3.size(), '_');
            r.append(s3.data(), s3.size());

            return r;
        }
#if __cplusplus >= 201402L
    })();
#else
    };

    std::string const expected = Expected::fn(s2, s3);
#endif

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        expected
        , ss.str());

#ifdef FIELD_WIDTH
# undef FIELD_WIDTH
#endif
} // anonymous namespace


// shims : sas

static void test_string_access_shims()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len_a(s));
        XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_data_a(s));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_data_a(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_data(s));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_data(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_ptr_a(s));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_ptr_a(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_ptr(s));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_ptr(s));

        XTESTS_TEST_POINTER_EQUAL(NULL, stlsoft::c_str_ptr_null_a(s));

        XTESTS_TEST_POINTER_EQUAL(NULL, stlsoft::c_str_ptr_null(s));
    }

    {
        wstring_t   s;

        XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len_w(s));
//      XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_data_w(s));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_data_w(s));

//      XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_data(s));
//      XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_data(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_ptr_w(s));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_ptr_w(s));

//      XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_ptr(s));
//      XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_ptr(s));

        XTESTS_TEST_POINTER_EQUAL(NULL, stlsoft::c_str_ptr_null_w(s));

//      XTESTS_TEST_POINTER_EQUAL(NULL, stlsoft::c_str_ptr_null(s));
    }

}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

