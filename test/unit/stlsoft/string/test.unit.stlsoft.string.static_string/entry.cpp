/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.string.static_string/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::basic_static_string`.
 *
 * Created: 4th November 2008
 * Updated: 30th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/string/static_string.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/limits/integral_limits.hpp>

/* Standard C++ header files */
#include <iomanip>
#include <iterator>
#include <sstream>
#include <stdexcept>

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
    static void test_ctor_ccs_too_large();
    static void test_ctor_ccs_n();
    static void test_ctor_ccs_n_too_large();
    static void test_ctor_n_ch();
    static void test_ctor_n_ch_too_large();
    static void test_ctor_range();
    static void test_ctor_range_too_large();

    // `assign()`

    static void test_assign_ccs();
    static void test_assign_ccs_too_large();
    static void test_assign_ccs_n();
    static void test_assign_ccs_n_too_large();
    static void test_assign_s();
    static void test_assign_s_pos_n();
    static void test_assign_s_pos_n_outofrange();
    static void test_assign_n_ch();
    static void test_assign_n_ch_too_large();
    static void test_assign_range();
    static void test_assign_range_too_large();
    static void test_opassign_ccs();
    static void test_opassign_ccs_too_large();
    static void test_opassign_s();
    static void test_opassign_ch();

    // `append()`

    static void test_append_ccs();
    static void test_append_ccs_too_large();
    static void test_append_ccs_n();
    static void test_append_ccs_n_too_large();
    static void test_append_s();
    static void test_append_s_too_large();
    static void test_append_s_pos_n();
    static void test_append_s_pos_n_too_large();
    static void test_append_n_ch();
    static void test_append_n_ch_too_large();
    static void test_append_range();
    static void test_append_range_too_large();
    static void test_opaddassign_ccs();
    static void test_opaddassign_ccs_too_large();
    static void test_opaddassign_s();
    static void test_opaddassign_s_too_large();
    static void test_opaddassign_ch();
    static void test_opaddassign_ch_too_large();
    static void test_push_back();
    static void test_push_back_too_large();
    static void test_pop_back();

    // modifiers

    static void test_reserve();
    static void test_reserve_too_large();
    static void test_swap_1();
    static void test_swap_2();
    static void test_swap_3();
    static void test_resize();
    static void test_resize_too_large();
    static void test_clear();

    // attributes

    static void test_size();
    static void test_max_size();
    static void test_length();
    static void test_capacity();
    static void test_empty();


    // comparison

    static void test_contains_1();
    static void test_contains_2();
    static void test_contains_3();
    static void test_starts_with_1();
    static void test_starts_with_2();
    static void test_ends_with_1();
    static void test_ends_with_2();


    // accessors

    static void test_at();
    static void test_at_out_of_range_1();
    static void test_at_out_of_range_2();
    static void test_copy();
    static void test_substr();
    static void test_substr_throw();


    // length-error attempts
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    static void TEST_overlong_ctor();
    static void TEST_overlong_append();
    static void TEST_overlong_assign();
    static void TEST_overlong_reserve();
    static void TEST_overlong_resize();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


    // search


    // traits


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

    if (XTESTS_START_RUNNER("test.unit.stlsoft.string.static_string", verbosity))
    {
        // construction

        XTESTS_RUN_CASE(test_ctor_default);
        XTESTS_RUN_CASE(test_ctor_copy);
        XTESTS_RUN_CASE(test_ctor_s_pos);
        XTESTS_RUN_CASE(test_ctor_s_pos_n);
        XTESTS_RUN_CASE(test_ctor_ccs);
        XTESTS_RUN_CASE_THAT_THROWS(test_ctor_ccs_too_large, std::length_error);
        XTESTS_RUN_CASE(test_ctor_ccs_n);
        XTESTS_RUN_CASE_THAT_THROWS(test_ctor_ccs_n_too_large, std::length_error);
        XTESTS_RUN_CASE(test_ctor_n_ch);
        XTESTS_RUN_CASE_THAT_THROWS(test_ctor_n_ch_too_large, std::length_error);
        XTESTS_RUN_CASE(test_ctor_range);
        XTESTS_RUN_CASE_THAT_THROWS(test_ctor_range_too_large, std::length_error);

        // `assign()`

        XTESTS_RUN_CASE(test_assign_ccs);
        XTESTS_RUN_CASE_THAT_THROWS(test_assign_ccs_too_large, std::length_error);
        XTESTS_RUN_CASE(test_assign_ccs_n);
        XTESTS_RUN_CASE_THAT_THROWS(test_assign_ccs_n_too_large, std::length_error);
        XTESTS_RUN_CASE(test_assign_s);
        XTESTS_RUN_CASE(test_assign_s_pos_n);
        XTESTS_RUN_CASE_THAT_THROWS(test_assign_s_pos_n_outofrange, std::out_of_range);
        XTESTS_RUN_CASE(test_assign_n_ch);
        XTESTS_RUN_CASE_THAT_THROWS(test_assign_n_ch_too_large, std::length_error);
        XTESTS_RUN_CASE(test_assign_range);
        XTESTS_RUN_CASE_THAT_THROWS(test_assign_range_too_large, std::length_error);
        XTESTS_RUN_CASE(test_opassign_ccs);
        XTESTS_RUN_CASE_THAT_THROWS(test_opassign_ccs_too_large, std::length_error);
        XTESTS_RUN_CASE(test_opassign_s);
        XTESTS_RUN_CASE(test_opassign_ch);

        // `append()`

        XTESTS_RUN_CASE(test_append_ccs);
        XTESTS_RUN_CASE_THAT_THROWS(test_append_ccs_too_large, std::length_error);
        XTESTS_RUN_CASE(test_append_ccs_n);
        XTESTS_RUN_CASE_THAT_THROWS(test_append_ccs_n_too_large, std::length_error);
        XTESTS_RUN_CASE(test_append_s);
        XTESTS_RUN_CASE_THAT_THROWS(test_append_s_too_large, std::length_error);
        XTESTS_RUN_CASE(test_append_s_pos_n);
        XTESTS_RUN_CASE_THAT_THROWS(test_append_s_pos_n_too_large, std::length_error);
        XTESTS_RUN_CASE(test_append_n_ch);
        XTESTS_RUN_CASE_THAT_THROWS(test_append_n_ch_too_large, std::length_error);
        XTESTS_RUN_CASE(test_append_range);
        XTESTS_RUN_CASE_THAT_THROWS(test_append_range_too_large, std::length_error);
        XTESTS_RUN_CASE(test_opaddassign_ccs);
        XTESTS_RUN_CASE_THAT_THROWS(test_opaddassign_ccs_too_large, std::length_error);
        XTESTS_RUN_CASE(test_opaddassign_s);
        XTESTS_RUN_CASE_THAT_THROWS(test_opaddassign_s_too_large, std::length_error);
        XTESTS_RUN_CASE(test_opaddassign_ch);
        XTESTS_RUN_CASE_THAT_THROWS(test_opaddassign_ch_too_large, std::length_error);
        XTESTS_RUN_CASE(test_push_back);
        XTESTS_RUN_CASE_THAT_THROWS(test_push_back_too_large, std::length_error);
        XTESTS_RUN_CASE(test_pop_back);

        // modifiers

        XTESTS_RUN_CASE(test_reserve);
        XTESTS_RUN_CASE_THAT_THROWS(test_reserve_too_large, std::length_error);
        XTESTS_RUN_CASE(test_swap_1);
        XTESTS_RUN_CASE(test_swap_2);
        XTESTS_RUN_CASE(test_swap_3);
        XTESTS_RUN_CASE(test_resize);
        XTESTS_RUN_CASE_THAT_THROWS(test_resize_too_large, std::length_error);
        XTESTS_RUN_CASE(test_clear);

        // attributes

        XTESTS_RUN_CASE(test_size);
        XTESTS_RUN_CASE(test_max_size);
        XTESTS_RUN_CASE(test_length);
        XTESTS_RUN_CASE(test_capacity);
        XTESTS_RUN_CASE(test_empty);

        // comparison

        XTESTS_RUN_CASE(test_contains_1);
        XTESTS_RUN_CASE(test_contains_2);
        XTESTS_RUN_CASE(test_contains_3);
        XTESTS_RUN_CASE(test_starts_with_1);
        XTESTS_RUN_CASE(test_starts_with_2);
        XTESTS_RUN_CASE(test_ends_with_1);
        XTESTS_RUN_CASE(test_ends_with_2);

        // accessors

        XTESTS_RUN_CASE(test_at);
        XTESTS_RUN_CASE_THAT_THROWS(test_at_out_of_range_1, std::out_of_range);
        XTESTS_RUN_CASE_THAT_THROWS(test_at_out_of_range_2, std::out_of_range);
        XTESTS_RUN_CASE(test_copy);
        XTESTS_RUN_CASE(test_substr);
        XTESTS_RUN_CASE_THAT_THROWS(test_substr_throw, std::out_of_range);


        // length-error attempts

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        XTESTS_RUN_CASE(TEST_overlong_ctor);
        XTESTS_RUN_CASE(TEST_overlong_append);
        XTESTS_RUN_CASE(TEST_overlong_assign);
        XTESTS_RUN_CASE(TEST_overlong_reserve);
        XTESTS_RUN_CASE(TEST_overlong_resize);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // search


        // traits


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

    typedef stlsoft::basic_static_string<char, 10>          string_10_t;
    typedef stlsoft::basic_static_string<char, 30>          string_30_t;
    typedef stlsoft::basic_static_string<wchar_t, 10>       wstring_10_t;


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


    static char const alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    static char const alphabet2[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


// construction

static void test_ctor_default()
{
    typedef string_10_t string_t;

    string_t    s;

    XTESTS_TEST_BOOLEAN_TRUE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
    XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
}

static void test_ctor_copy()
{
    typedef string_10_t string_t;

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
    typedef string_10_t string_t;

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
    typedef string_10_t string_t;

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
    typedef string_10_t string_t;

    {
        string_t    s("abc");

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);
    }

    {
        string_t    s(static_cast<char const*>(NULL));

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }
}

static void test_ctor_ccs_too_large()
{
    typedef string_10_t string_t;

    string_t s(alphabet);
}

static void test_ctor_ccs_n()
{
    typedef string_30_t string_t;

    {
        string_t    s(alphabet, 3);

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }

    {
        string_t    s(static_cast<char const*>(NULL), size_t(0));

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }
}

static void test_ctor_ccs_n_too_large()
{
    typedef string_10_t string_t;

    string_t s(alphabet, 11);
}

static void test_ctor_n_ch()
{
    typedef string_10_t string_t;

    {
        string_t    s(0, '~');

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }

    {
        string_t    s(8, '~');

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(8u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(8u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
#if 0
        XTESTS_TEST_CHARACTER_EQUAL('~', s.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', s.back());

        string_t const& cs = s;

        XTESTS_TEST_CHARACTER_EQUAL('~', cs.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', cs.back());
#endif
    }

    {
        string_t    s(9, '~');

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(9u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(9u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
#if 0
        XTESTS_TEST_CHARACTER_EQUAL('~', s.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', s.back());

        string_t const& cs = s;

        XTESTS_TEST_CHARACTER_EQUAL('~', cs.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', cs.back());
#endif
    }

    {
        string_t    s(10, '~');

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(10u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
#if 0
        XTESTS_TEST_CHARACTER_EQUAL('~', s.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', s.back());

        string_t const& cs = s;

        XTESTS_TEST_CHARACTER_EQUAL('~', cs.front());
        XTESTS_TEST_CHARACTER_EQUAL('~', cs.back());
#endif
    }
}

static void test_ctor_n_ch_too_large()
{
    typedef string_10_t string_t;

    string_t s(11, '~');
}

static void test_ctor_range()
{
}

static void test_ctor_range_too_large()
{
    typedef string_30_t  string_t;

    string_t s2(&alphabet2[0], &alphabet2[0] + STLSOFT_NUM_ELEMENTS(alphabet2) -1);
}


// `assign()`

static void test_assign_ccs()
{
    typedef string_10_t string_t;

    {
        char const* const   s1 = "";
        string_t            s2;

        s2.assign(s1);

        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
    }

    {
        char const* const   s1 = NULL;
        string_t            s2;

        s2.assign(s1);

        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
    }

    {
        char const* const   s1 = "abc";
        string_t            s2;

        s2.assign(s1);

        XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s2);
    }
}

static void test_assign_ccs_too_large()
{
    typedef string_10_t string_t;

    string_t s;

    s.assign(alphabet);
}

static void test_assign_ccs_n()
{
    typedef string_10_t string_t;

    {
        char const* const   s1 = "";
        string_t            s2;

        s2.assign(s1, size_t(0));

        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
    }

    {
        char const* const   s1 = NULL;
        string_t            s2;

        s2.assign(s1, size_t(0));

        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
    }

    {
        char const* const   s1 = "abc";
        string_t            s2;

        s2.assign(s1, 2);

        XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab", s2);
    }
}

static void test_assign_ccs_n_too_large()
{
    typedef string_10_t string_t;

    string_t s;

    s.assign(alphabet, 11);
}

static void test_assign_s()
{
    typedef string_10_t string_t;

    {
        string_t const  s1;
        string_t        s2;

        s2.assign(s1);

        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
    }

    {
        string_t const  s1("abc");
        string_t        s2;

        s2.assign(s1);

        XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s2);
    }

    {
        string_t const  s1("abc");
        string_t        s2;

        s2.assign(s1);
        s2.assign(s2);

        XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s2);
    }

}

static void test_assign_s_pos_n()
{
    typedef string_10_t string_t;

    {
        string_t const  s1;
        string_t        s2;

        s2.assign(s1, size_t(0), size_t(0));

        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
    }

    {
        string_t const  s1("abc");
        string_t        s2;

        s2.assign(s1, 1, 2);

        XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bc", s2);
    }

    {
        string_t const  s1("abc");
        string_t        s2;

        s2.assign(s1, 1, 200);

        XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bc", s2);
    }
}

static void test_assign_s_pos_n_outofrange()
{
    typedef string_10_t string_t;

    string_t const  s1("abc");
    string_t        s2;

    s2.assign(s1, 4, 0);
}

static void test_assign_n_ch()
{
    typedef string_10_t string_t;

    {
        char const      ch1 =   '\0';
        string_t        s2;

        s2.assign(0, ch1);

        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
    }

    {
        char const      ch1 =   'x';
        string_t        s2;

        s2.assign(0, ch1);

        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
    }

    {
        char const      ch1 =   'x';
        string_t        s2;

        s2.assign(3, ch1);

        XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("xxx", s2);
    }
}

static void test_assign_n_ch_too_large()
{
    typedef string_10_t string_t;

    string_t s;

    s.assign(11, 'x');
}

static void test_assign_range()
{
    typedef string_30_t string_t;

    {
        string_t s;

        s.assign(&alphabet[0], &alphabet[0] + 0);

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);
    }

    {
        string_t s;

        s.assign(&alphabet[0], &alphabet[0] + STLSOFT_NUM_ELEMENTS(alphabet) -1);

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);
    }
}

static void test_assign_range_too_large()
{
    typedef string_10_t string_t;

    string_t s;

    s.assign(&alphabet2[0], &alphabet2[0] + STLSOFT_NUM_ELEMENTS(alphabet2) -1);
}

static void test_opassign_ccs()
{

}

static void test_opassign_ccs_too_large()
{
    typedef string_10_t string_t;

    string_t s;

    s = alphabet;
}

static void test_opassign_s()
{

}

static void test_opassign_ch()
{

}


// `append()`

static void test_append_ccs()
{
    typedef string_10_t string_t;

    string_t s("abc");

    XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

    s.append(alphabet + 19);

    XTESTS_TEST_INTEGER_EQUAL(10u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abctuvwxyz", s);
}

static void test_append_ccs_too_large()
{
    typedef string_10_t string_t;

    string_t s("abc");

    s.append(alphabet + 3);
}

static void test_append_ccs_n()
{
    typedef string_10_t string_t;

    string_t s("abc");

    XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

    s.append(alphabet + 3, 7);

    XTESTS_TEST_INTEGER_EQUAL(10u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghij", s);
}

static void test_append_ccs_n_too_large()
{
    typedef string_10_t string_t;

    string_t s("abc");

    s.append(alphabet + 3, 8);
}

static void test_append_s()
{
    typedef string_10_t string_t;

    string_t        s1(alphabet, 8);
    string_t const  s2(alphabet + 8, 2);

    XTESTS_TEST_INTEGER_EQUAL(8u, s1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefgh", s1);

    s1.append(s2);

    XTESTS_TEST_INTEGER_EQUAL(10u, s1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghij", s1);
}

static void test_append_s_too_large()
{
    typedef string_10_t string_t;

    string_t        s1(alphabet, 8);
    string_t const  s2(alphabet + 8, 8);

    s1.append(s2);
}

static void test_append_s_pos_n()
{
    typedef string_10_t string_t;

    string_t        s1(alphabet, 8);
    string_t const  s2(alphabet + 8, 8);

    XTESTS_TEST_INTEGER_EQUAL(8u, s1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefgh", s1);

    s1.append(s2, 0, 2);

    XTESTS_TEST_INTEGER_EQUAL(10u, s1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghij", s1);
}

static void test_append_s_pos_n_too_large()
{
    typedef string_10_t string_t;

    string_t        s1(alphabet, 8);
    string_t const  s2(alphabet + 8, 8);

    s1.append(s2, 0, 3);
}

static void test_append_n_ch()
{
    typedef string_10_t string_t;

    string_t s(alphabet, 9);

    XTESTS_TEST_INTEGER_EQUAL(9u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghi", s);

    s.append(1, 'j');

    XTESTS_TEST_INTEGER_EQUAL(10u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghij", s);
}

static void test_append_n_ch_too_large()
{
    typedef string_10_t string_t;

    string_t s(alphabet, 10);

    s.append(1, 'k');
}

static void test_append_range()
{
    typedef string_10_t string_t;

    string_t s(alphabet, 8);

    XTESTS_TEST_INTEGER_EQUAL(8u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefgh", s);

    s.append(alphabet + 8, alphabet + 10);

    XTESTS_TEST_INTEGER_EQUAL(10u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghij", s);
}

static void test_append_range_too_large()
{
    typedef string_10_t string_t;

    string_t s(alphabet, 8);

    s.append(alphabet + 8, alphabet + 11);
}

static void test_opaddassign_ccs()
{
    typedef string_10_t string_t;

    string_t s("abc");

    XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

    s += alphabet + 19;

    XTESTS_TEST_INTEGER_EQUAL(10u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abctuvwxyz", s);
}

static void test_opaddassign_ccs_too_large()
{
    typedef string_10_t string_t;

    string_t s("abc");

    s += alphabet + 3;
}

static void test_opaddassign_s()
{
    typedef string_10_t string_t;

    string_t        s1(alphabet, 8);
    string_t const  s2(alphabet + 8, 2);

    XTESTS_TEST_INTEGER_EQUAL(8u, s1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefgh", s1);

    s1 += s2;

    XTESTS_TEST_INTEGER_EQUAL(10u, s1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghij", s1);
}

static void test_opaddassign_s_too_large()
{
    typedef string_10_t string_t;

    string_t        s1(alphabet, 8);
    string_t const  s2(alphabet + 8, 3);

    s1 += s2;
}

static void test_opaddassign_ch()
{
    typedef string_10_t string_t;

    string_t s(9, '~');

    XTESTS_TEST_INTEGER_EQUAL(9u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~~~~~~~~~", s);

    s += '+';

    XTESTS_TEST_INTEGER_EQUAL(10u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~~~~~~~~~+", s);
}

static void test_opaddassign_ch_too_large()
{
    typedef string_10_t string_t;

    string_t s(10, '~');

    s += '+';
}

static void test_push_back()
{
    typedef string_10_t string_t;

    string_t s(8, '~');

    s.push_back('+');
    s.push_back('+');

    XTESTS_TEST_INTEGER_EQUAL(10u, s.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~~~~~~~~++", s);
}

static void test_push_back_too_large()
{
    typedef string_10_t string_t;

    string_t s(10, '~');

    s.push_back('+');
}

static void test_pop_back()
{
    typedef string_10_t string_t;

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
    typedef string_10_t string_t;

    {
        string_t s;

        s.reserve(0);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.reserve(1);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.reserve(2);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.reserve(8);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(8u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.reserve(10);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);
    }

    {
        string_t s("abc");

        s.reserve(0);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.reserve(1);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.reserve(2);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.reserve(8);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(8u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.reserve(10);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);
    }
}

static void test_reserve_too_large()
{
    typedef string_10_t string_t;

    string_t s;

    s.reserve(11);
}

static void test_swap_1()
{
    typedef string_10_t string_t;

    {
        string_t s1;
        string_t s2;

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
    typedef string_10_t string_t;

    {
        string_t s1;
        string_t s2;

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
    typedef string_10_t string_t;

    {
        string_t s1;
        string_t s2;

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        std::swap(s1, s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
    }

    {
        string_t s1("abc");
        string_t s2;

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
    typedef string_10_t string_t;

    {
        string_t s;

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());

        s.resize(1, '~');

        XTESTS_TEST_INTEGER_EQUAL(1u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~", s);

        s.resize(1, '~');

        XTESTS_TEST_INTEGER_EQUAL(1u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~", s);

        s.resize(8, '~');

        XTESTS_TEST_INTEGER_EQUAL(8u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~~~~~~~~", s);
    }

    {
        string_t s("abc");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());

        s.clear();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t s("abcdefghij");

        XTESTS_TEST_INTEGER_EQUAL(10u, s.size());

        s.clear();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}

static void test_resize_too_large()
{
    typedef string_10_t string_t;

    string_t s("abcdefghij");

    s.resize(11);
}

static void test_clear()
{
    typedef string_10_t string_t;

    {
        string_t s;

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());

        s.clear();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t s("abc");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());

        s.clear();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}


// attributes

static void test_size()
{
    {

    }
}

static void test_max_size()
{
    {
        typedef string_10_t string_t;

        XTESTS_TEST_INTEGER_EQUAL(10u, string_t::max_size());
    }

    {
        typedef string_30_t string_t;

        XTESTS_TEST_INTEGER_EQUAL(30u, string_t::max_size());
    }
}

static void test_length()
{

}

static void test_capacity()
{
    {
        typedef string_10_t string_t;

        string_t s;

        XTESTS_TEST_INTEGER_EQUAL(10u, s.capacity());
    }

    {
        typedef string_30_t string_t;

        string_t s;

        XTESTS_TEST_INTEGER_EQUAL(30u, s.capacity());
    }
}

static void test_empty()
{

}



// comparison

static void test_contains_1()
{
    typedef string_30_t string_t;

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
    typedef string_30_t string_t;

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
    typedef string_30_t string_t;

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
        string_t const s("aaaaaaaaaaaaaaaaaaaaaaaaaaab");

        {
            XTESTS_TEST_BOOLEAN_TRUE(s.contains("ab"));
            XTESTS_TEST_BOOLEAN_FALSE(s.contains("ac"));
        }
    }
}

static void test_starts_with_1()
{
    typedef string_30_t string_t;

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
    typedef string_30_t string_t;

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

static void test_ends_with_1()
{
    typedef string_30_t string_t;

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
    typedef string_30_t string_t;

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


// accessors

static void test_at()
{
    typedef string_10_t string_t;

    {
        string_t s("abc");

        XTESTS_TEST_CHARACTER_EQUAL('a', s.at(0u));
        XTESTS_TEST_CHARACTER_EQUAL('b', s.at(1u));
        XTESTS_TEST_CHARACTER_EQUAL('c', s.at(2u));
    }

    {
        string_t const s("abc");

        XTESTS_TEST_CHARACTER_EQUAL('a', s.at(0u));
        XTESTS_TEST_CHARACTER_EQUAL('b', s.at(1u));
        XTESTS_TEST_CHARACTER_EQUAL('c', s.at(2u));
    }

    {
        string_t const s;

        s.at(0u);
    }

    {
        string_t const s("abc");

        s.at(3u);
    }
}

static void test_at_out_of_range_1()
{
    typedef string_10_t string_t;

    string_t s;

    s.at(0u);
}

static void test_at_out_of_range_2()
{
    typedef string_10_t string_t;

    string_t const s("abc");

    s.at(4u);
}

static void test_copy()
{
    typedef stlsoft::basic_static_string<char, 26> string_t;

    string_t const s_alphabet(alphabet);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s_alphabet);

    {
        string_t    s;
        char        dest[101];
        size_t      cch = s.copy(&dest[0], STLSOFT_NUM_ELEMENTS(dest), 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

    {
        string_t    s;
        char        dest[101];
        size_t      cch = s.copy(&dest[0], STLSOFT_NUM_ELEMENTS(dest), 10);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

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
    typedef string_10_t string_t;

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
    typedef string_10_t string_t;

    string_t const  s1("abcdefghi");
    string_t        s2 = s1.substr(s1.size() + 1);

    XTESTS_TEST_FAIL("should not get here");
}


// length-error attempts
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

static void TEST_overlong_ctor()
{
    typedef string_10_t                                     string_t;

    try
    {
        string_t s("abcdefghijk");

        TEST_FAIL("should not get here");
    }
    catch (std::length_error& x)
    {
#ifdef XTESTS_USE_SHWILD

        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("operation would result in static_string (of 11 element(s)) that is too large for static limit (of 10 element(s))", x.what());
#else

        STLSOFT_SUPPRESS_UNUSED(x);
#endif // XTESTS_USE_SHWILD
    }
}

static void TEST_overlong_append()
{

}

static void TEST_overlong_assign()
{

}

static void TEST_overlong_reserve()
{

}

static void TEST_overlong_resize()
{
    typedef string_10_t                                     string_t;

    try
    {
        string_t s("abc");

        TEST_PASSED();

        s.resize(stlsoft::integral_limits<std::size_t>::maximum());

        TEST_FAIL("should not get here");
    }
    catch (std::length_error& x)
    {
#ifdef XTESTS_USE_SHWILD

        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("operation would result in static_string (of ?* element(s)) that is too large for static limit (of 10 element(s))", x.what());
#else

        STLSOFT_SUPPRESS_UNUSED(x);
#endif // XTESTS_USE_SHWILD
    }
}
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


// operators : insertion

static void test_insertion_1()
{
    typedef string_10_t string_t;

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
    typedef string_10_t string_t;

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
    typedef string_10_t string_t;

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
    typedef string_10_t string_t;

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
    typedef string_10_t string_t;
    typedef wstring_10_t wstring_t;

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

