/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.container.fixed_circular_buffer.cpp
 *
 * Purpose: Unit-tests for `stlsoft::fixed_circular_buffer`.
 *
 * Created: 10th March 2024
 * Updated: 14th March 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* ///////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/containers/fixed_circular_buffer.hpp>

/* ///////////////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <numeric>
#include <string>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_q10_empty(void);
    static void test_q10_single_item_erase(void);
    static void test_q10_erase_1_from_wrapped(void);
    static void test_q10_erase_N_from_wrapped(void);

    static void test_q16_empty(void);
    static void test_q16_try_push_back(void);
    static void test_q16_try_push_front(void);
    static void test_q16_fill(void);
    static void test_q16_initialiser_list(void);
    static void test_q16_initialiser_list_and_erase(void);
    static void test_q16_wrapping(void);
    static void test_q16_wrapping_2(void);
    static void test_q16_wrapping_3(void);
    static void test_q16_offsetted_erase(void);
    static void test_q16_pop_front_and_pop_back(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.container.fixed_circular_buffer", verbosity))
    {
        XTESTS_RUN_CASE(test_q10_empty);
        XTESTS_RUN_CASE(test_q10_single_item_erase);
        XTESTS_RUN_CASE(test_q10_erase_1_from_wrapped);
        XTESTS_RUN_CASE(test_q10_erase_N_from_wrapped);

        XTESTS_RUN_CASE(test_q16_empty);
        XTESTS_RUN_CASE(test_q16_try_push_back);
        XTESTS_RUN_CASE(test_q16_try_push_front);
        XTESTS_RUN_CASE(test_q16_fill);
        XTESTS_RUN_CASE(test_q16_initialiser_list);
        XTESTS_RUN_CASE(test_q16_initialiser_list_and_erase);
        XTESTS_RUN_CASE(test_q16_wrapping);
        XTESTS_RUN_CASE(test_q16_wrapping_2);
        XTESTS_RUN_CASE(test_q16_wrapping_3);
        XTESTS_RUN_CASE(test_q16_offsetted_erase);
        XTESTS_RUN_CASE(test_q16_pop_front_and_pop_back);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_iterator
>
inline
T_value
accumulate_postfix(
    T_iterator  from
,   T_iterator  to
,   T_value     init
)
{
    for (; from != to; from++)
    {
        init = init + *from;
    }

    return init;
}

template <
    ss_typename_param_k T_iterator
,   ss_typename_param_k T_delim
>
std::string
join(
    T_iterator      from
,   T_iterator      to
,   T_delim const&  delim
)
{
    std::string r;

    for (; from != to; ++from)
    {
        if (!r.empty())
        {
            r.append(delim);
        }

        r.append(*from);
    }

    return r;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{


    typedef stlsoft::fixed_circular_buffer<std::string, 10> fcb_str_10_t;

    typedef stlsoft::fixed_circular_buffer<int, 16>         fcb_int_16_t;


    fcb_str_10_t
    helper_build_b_with_xx12345678()
    {
        // |    |    |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |

        fcb_str_10_t b = { "-", "-", "1", "2", "3", "4", "5", "6", "7", "8" };

        b.erase(b.begin() + 1);
        b.erase(b.begin() + 0);

        return b;
    }









static void test_q10_empty(void)
{
    {
        fcb_str_10_t b;

        XTESTS_TEST_INTEGER_EQUAL(0, b.size());
        XTESTS_TEST_INTEGER_EQUAL(10, b.capacity());

        XTESTS_TEST_BOOLEAN_TRUE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());
    }
}

static void test_q10_single_item_erase(void)
{
    {
        fcb_str_10_t b = { "1" };

        XTESTS_TEST_INTEGER_EQUAL(1, b.size());
        XTESTS_TEST_INTEGER_EQUAL(10, b.capacity());

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        b.erase(b.begin());

        XTESTS_TEST_INTEGER_EQUAL(0, b.size());
        XTESTS_TEST_INTEGER_EQUAL(10, b.capacity());

        XTESTS_TEST_BOOLEAN_TRUE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());
    }
}

static void test_q10_erase_1_from_wrapped(void)
{
    // a:  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |    |    |

    {
        fcb_str_10_t b = { "1", "2", "3", "4", "5", "6", "7", "8" };

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // remove "1" - begin() + 0
    {
        fcb_str_10_t b = { "1", "2", "3", "4", "5", "6", "7", "8" };

        b.erase(b.begin() + 0);

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // remove "4" - begin() + 3
    {
        fcb_str_10_t b = { "1", "2", "3", "4", "5", "6", "7", "8" };

        b.erase(b.begin() + 3);

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-5-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // remove "2" - begin() + 1
    {
        fcb_str_10_t b = { "1", "2", "3", "4", "5", "6", "7", "8" };

        b.erase(b.begin() + 1);

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));
    }
}

static void test_q10_erase_N_from_wrapped(void)
{
    // starting contents:  |    |    |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(0, N)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin(), b.end());

        XTESTS_TEST_INTEGER_EQUAL(0, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", join(b.begin(), b.end(), "-"));
    }

    // erase(0, 1)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 0, b.begin() + 1);

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(0, 5)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 0, b.begin() + 5);

        XTESTS_TEST_INTEGER_EQUAL(3, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(end() - 1, end())
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.end() - 1, b.end());

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7", join(b.begin(), b.end(), "-"));
    }

    // erase(end() - 5, end())
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.end() - 5, b.end());

        XTESTS_TEST_INTEGER_EQUAL(3, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3", join(b.begin(), b.end(), "-"));
    }

    // erase(1, 1)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 1, b.begin() + 1);

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(1, 2)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 1, b.begin() + 2);

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(1, 3)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 1, b.begin() + 3);

        XTESTS_TEST_INTEGER_EQUAL(6, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-4-5-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(1, 4)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 1, b.begin() + 4);

        XTESTS_TEST_INTEGER_EQUAL(5, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-5-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(1, 5)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 1, b.begin() + 5);

        XTESTS_TEST_INTEGER_EQUAL(4, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(2, 5)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 2, b.begin() + 5);

        XTESTS_TEST_INTEGER_EQUAL(5, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(2, 5)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 2, b.begin() + 5);

        XTESTS_TEST_INTEGER_EQUAL(5, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(4, 5)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 4, b.begin() + 5);

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-6-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(4, 6)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 4, b.begin() + 6);

        XTESTS_TEST_INTEGER_EQUAL(6, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-7-8", join(b.begin(), b.end(), "-"));
    }

    // erase(4, 7)
    {
        fcb_str_10_t b = helper_build_b_with_xx12345678();

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-5-6-7-8", join(b.begin(), b.end(), "-"));


        b.erase(b.begin() + 4, b.begin() + 7);

        XTESTS_TEST_INTEGER_EQUAL(5, b.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1-2-3-4-8", join(b.begin(), b.end(), "-"));
    }
}


static void test_q16_empty(void)
{
    {
        fcb_int_16_t   b;

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    V:  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
 */

        XTESTS_TEST_BOOLEAN_TRUE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(0, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() == b.begin());

        XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(b.begin(), b.end(), 0));
    }
}

static void test_q16_try_push_back(void)
{
    {
        fcb_int_16_t   b;

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    V:  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
 */

        XTESTS_TEST_BOOLEAN_TRUE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(0, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() == b.begin());

        XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(b.begin(), b.end(), 0));


        bool r = b.try_push_back(1);

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    V:  |     1 |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_BOOLEAN_TRUE(r);

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(1, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() != b.begin());

        XTESTS_TEST_INTEGER_EQUAL(1, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(1, accumulate_postfix(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(1, b.at(0));
        XTESTS_TEST_INTEGER_EQUAL(1, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(1, b.back());
        XTESTS_TEST_INTEGER_EQUAL(1, b.front());


        bool r2 = b.try_push_back(2);

        XTESTS_TEST_BOOLEAN_TRUE(r2);

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(2, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() != b.begin());

        XTESTS_TEST_INTEGER_EQUAL(3, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(3, accumulate_postfix(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(1, b.at(0));
        XTESTS_TEST_INTEGER_EQUAL(1, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(2, b.back());
        XTESTS_TEST_INTEGER_EQUAL(1, b.front());
    }
}

static void test_q16_try_push_front(void)
{
    {
        fcb_int_16_t   b;

        XTESTS_TEST_BOOLEAN_TRUE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(0, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() == b.begin());

        XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(b.begin(), b.end(), 0));


        bool r = b.try_push_front(1);

        XTESTS_TEST_BOOLEAN_TRUE(r);

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(1, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() != b.begin());

        XTESTS_TEST_INTEGER_EQUAL(1, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(1, accumulate_postfix(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(1, b.at(0));
        XTESTS_TEST_INTEGER_EQUAL(1, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(1, b.back());
        XTESTS_TEST_INTEGER_EQUAL(1, b.front());


        bool r2 = b.try_push_front(2);

        XTESTS_TEST_BOOLEAN_TRUE(r2);

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(2, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() != b.begin());

        XTESTS_TEST_INTEGER_EQUAL(3, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(3, accumulate_postfix(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(2, b.at(0));
        XTESTS_TEST_INTEGER_EQUAL(2, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(1, b.back());
        XTESTS_TEST_INTEGER_EQUAL(2, b.front());
    }

    {
        fcb_int_16_t   b;

        for (int i = 0; i != 16; ++i)
        {
            bool r = b.try_push_front(1 + i);

            XTESTS_TEST_BOOLEAN_TRUE(r);
        }

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_TRUE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() != b.begin());

        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(136, accumulate_postfix(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(1, b.back());
        XTESTS_TEST_INTEGER_EQUAL(16, b.front());

        XTESTS_TEST_INTEGER_EQUAL(16, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[6]);
        XTESTS_TEST_INTEGER_EQUAL( 9, b[7]);
        XTESTS_TEST_INTEGER_EQUAL( 8, b[8]);
        XTESTS_TEST_INTEGER_EQUAL( 7, b[9]);
        XTESTS_TEST_INTEGER_EQUAL( 6, b[10]);
        XTESTS_TEST_INTEGER_EQUAL( 5, b[11]);
        XTESTS_TEST_INTEGER_EQUAL( 4, b[12]);
        XTESTS_TEST_INTEGER_EQUAL( 3, b[13]);
        XTESTS_TEST_INTEGER_EQUAL( 2, b[14]);
        XTESTS_TEST_INTEGER_EQUAL( 1, b[15]);

        b.pop_back();

        b.try_push_front(17);

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_TRUE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() != b.begin());

        XTESTS_TEST_INTEGER_EQUAL(152, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(152, accumulate_postfix(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(2, b.back());
        XTESTS_TEST_INTEGER_EQUAL(17, b.front());

        XTESTS_TEST_INTEGER_EQUAL(17, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[7]);
        XTESTS_TEST_INTEGER_EQUAL( 9, b[8]);
        XTESTS_TEST_INTEGER_EQUAL( 8, b[9]);
        XTESTS_TEST_INTEGER_EQUAL( 7, b[10]);
        XTESTS_TEST_INTEGER_EQUAL( 6, b[11]);
        XTESTS_TEST_INTEGER_EQUAL( 5, b[12]);
        XTESTS_TEST_INTEGER_EQUAL( 4, b[13]);
        XTESTS_TEST_INTEGER_EQUAL( 3, b[14]);
        XTESTS_TEST_INTEGER_EQUAL( 2, b[15]);
    }
}

static void test_q16_fill(void)
{
    {
        fcb_int_16_t   b;

        XTESTS_TEST_BOOLEAN_TRUE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(0, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() == b.begin());

        XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(b.begin(), b.end(), 0));


        for (int i = 1; i <= 16; ++i)
        {
            XTESTS_TEST_BOOLEAN_FALSE(b.full());

            bool r = b.try_push_back(i);

            XTESTS_TEST_BOOLEAN_TRUE(r);

            XTESTS_TEST_BOOLEAN_FALSE(b.empty());

            XTESTS_TEST_INTEGER_EQUAL(i, b.size());
            XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

            XTESTS_TEST(b.end() != b.begin());

            int const sum_expected = (i * (b.back() + b.front())) / 2;      // n * (l - f) / 2
            int const sum_after = std::accumulate(b.begin(), b.end(), 0);

            XTESTS_TEST_INTEGER_EQUAL(sum_expected, sum_after);

            XTESTS_TEST_INTEGER_EQUAL(i, b.at(i - 1));
            XTESTS_TEST_INTEGER_EQUAL(i, b[i - 1]);
            XTESTS_TEST_INTEGER_EQUAL(i, b.back());
            XTESTS_TEST_INTEGER_EQUAL(1, b.front());
        }

        XTESTS_TEST_BOOLEAN_TRUE(b.full());

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    V:  |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |    16 |
    B:  |     ⬆️                                                                                                                        |
 */
    }
}

static void test_q16_initialiser_list(void)
{
    // 8 initialisers
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8 };

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() != b.begin());

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |       |       |       |       |       |       |       |       |
    V:  |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |       |       |       |       |       |       |       |       |
    B:  |     ⬆️                                                                                                                        |
 */
    }

    // 16 initialisers
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_TRUE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() != b.begin());

        bool r = b.try_push_back(17);

        XTESTS_TEST_BOOLEAN_FALSE(r);

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    V:  |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |    16 |
    B:  |     ⬆️                                                                                                                        |
 */
    }

    // 17 initialisers - 1 too many
    try
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };

        XTESTS_TEST_FAIL("should not get here");
    }
    catch (std::runtime_error& /* x */)
    {
        // expected
    }
    catch (std::exception& x)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("should not get here", x.what());
    }
}

static void test_q16_initialiser_list_and_erase(void)
{
    // at index 0
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8 };

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |       |       |       |       |       |       |       |       |
    V:  |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |       |       |       |       |       |       |       |       |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        int const sum_expected = (8 * (b.back() + b.front())) / 2;      // n * (l - f) / 2
        int const sum = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(sum_expected, sum);

        fcb_int_16_t::iterator i = b.begin() + 0;

        b.erase(i);

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |       |     0 |     1 |     2 |     3 |     4 |     5 |     6 |       |       |       |       |       |       |       |       |
    V:  |       |     2 |     3 |     4 |     5 |     6 |     7 |     8 |       |       |       |       |       |       |       |       |
    B:  |            ⬆️                                                                                                                  |
 */

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        int const sum_expected_after = sum_expected - 1;
        int const sum_after = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(sum_expected_after, sum_after);
    }

    // at index 7
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8 };

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |       |       |       |       |       |       |       |       |
    V:  |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |       |       |       |       |       |       |       |       |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        int const sum_expected = (8 * (b.back() + b.front())) / 2;      // n * (l - f) / 2
        int const sum = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(sum_expected, sum);

        fcb_int_16_t::iterator i = b.begin() + 7;

        b.erase(i);

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |       |       |       |       |       |       |       |       |       |
    V:  |     1 |     2 |     3 |     4 |     5 |     6 |     7 |       |       |       |       |       |       |       |       |       |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        int const sum_expected_after = sum_expected - 8;
        int const sum_after = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(sum_expected_after, sum_after);
    }

    // at index 4
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8 };

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |       |       |       |       |       |       |       |       |
    V:  |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |       |       |       |       |       |       |       |       |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        int const sum_expected = (8 * (b.back() + b.front())) / 2;      // n * (l - f) / 2
        int const sum = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(sum_expected, sum);

        fcb_int_16_t::iterator i = b.begin() + 4;

        b.erase(i);

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |       |       |       |       |       |       |       |       |       |
    V:  |     1 |     2 |     3 |     4 |     6 |     7 |     8 |       |       |       |       |       |       |       |       |       |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        int const sum_expected_after = sum_expected - 5;
        int const sum_after = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(sum_expected_after, sum_after);

        XTESTS_TEST_INTEGER_EQUAL(1, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(2, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(3, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[6]);
    }

    // at index 2
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8 };

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |       |       |       |       |       |       |       |       |
    V:  |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |       |       |       |       |       |       |       |       |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        int const sum_expected = (8 * (b.back() + b.front())) / 2;      // n * (l - f) / 2
        int const sum = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(sum_expected, sum);

        fcb_int_16_t::iterator i = b.begin() + 2;

        b.erase(i);

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |       |     0 |     1 |     2 |     3 |     4 |     5 |     6 |       |       |       |       |       |       |       |       |
    V:  |       |     1 |     2 |     4 |     5 |     6 |     7 |     8 |       |       |       |       |       |       |       |
    B:  |       |     ⬆️
 */

        XTESTS_TEST_INTEGER_EQUAL(7, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        int const sum_expected_after = sum_expected - 3;
        int const sum_after = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(sum_expected_after, sum_after);

        XTESTS_TEST_INTEGER_EQUAL(1, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(2, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[6]);
    }
}

static void test_q16_wrapping(void)
{
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8 };

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST_INTEGER_EQUAL(36, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(36, std::accumulate(b.cbegin(), b.cend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(36, std::accumulate(b.rbegin(), b.rend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(36, std::accumulate(b.crbegin(), b.crend(), 0));

        XTESTS_TEST_INTEGER_EQUAL(1, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(2, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(3, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[7]);

        auto r = b.try_push_back_range( { 9, 10, 11, 12, 13, 14, 15, 16 } );

        XTESTS_TEST_INTEGER_EQUAL(8, r);

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_TRUE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.cbegin(), b.cend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.rbegin(), b.rend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.crbegin(), b.crend(), 0));

        XTESTS_TEST_INTEGER_EQUAL(1, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(2, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(3, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[11]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[13]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[14]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[15]);

        b.erase(b.begin());

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(15, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST_INTEGER_EQUAL(135, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(135, std::accumulate(b.cbegin(), b.cend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(135, std::accumulate(b.rbegin(), b.rend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(135, std::accumulate(b.crbegin(), b.crend(), 0));

        XTESTS_TEST_INTEGER_EQUAL(2, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(3, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[11]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[13]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[14]);

        auto r2 = b.try_push_back(17);

        XTESTS_TEST_BOOLEAN_TRUE(r2);

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_TRUE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST_INTEGER_EQUAL(152, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(152, std::accumulate(b.cbegin(), b.cend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(152, std::accumulate(b.rbegin(), b.rend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(152, std::accumulate(b.crbegin(), b.crend(), 0));

        XTESTS_TEST_INTEGER_EQUAL(2, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(3, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[11]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[13]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[14]);
        XTESTS_TEST_INTEGER_EQUAL(17, b[15]);
    }
}

static void test_q16_wrapping_2(void)
{
    // full (16); pop-front 15 times; push-back 2 twice; pop-front once
    {
        fcb_int_16_t b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    V:  |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |    16 |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());
        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.begin(), b.end(), 0));

        for (int i = 0; i != 15; ++i)
        {
            b.pop_front();
        }

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |     0 |
    V:  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |    16 |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(1, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, *b.begin());
        XTESTS_TEST_INTEGER_EQUAL(16, std::accumulate(b.begin(), b.end(), 0));

        b.try_push_back_range({ 17, 18, 19, 20 });

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     1 |     2 |     3 |     4 |       |       |       |       |       |       |       |       |       |       |       |     0 |
    V:  |    17 |    18 |    19 |    20 |       |       |       |       |       |       |       |       |       |       |       |    16 |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(5, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, *b.begin());
        XTESTS_TEST_INTEGER_EQUAL(90, std::accumulate(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(16, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(17, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(18, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(19, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(20, b[4]);

        // ///////////////////////////////////////

        // Now at this point we do two more `pop_front()`s, and measure each
        // one at a time

        b.pop_front();

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |       |       |       |       |       |       |       |       |       |       |       |       |
    V:  |    17 |    18 |    19 |    20 |       |       |       |       |       |       |       |       |       |       |       |       |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(4, b.size());
        XTESTS_TEST_INTEGER_EQUAL(17, *b.begin());
        XTESTS_TEST_INTEGER_EQUAL(74, std::accumulate(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(17, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(18, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(19, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(20, b[3]);

        b.pop_front();

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |       |     0 |     1 |     2 |       |       |       |       |       |       |       |       |       |       |       |       |
    V:  |       |    18 |    19 |    20 |       |       |       |       |       |       |       |       |       |       |       |       |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(3, b.size());
        XTESTS_TEST_INTEGER_EQUAL(18, *b.begin());
        XTESTS_TEST_INTEGER_EQUAL(57, std::accumulate(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(18, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(19, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(20, b[2]);
    }
}

static void test_q16_wrapping_3(void)
{
    // full (16); pop-front 15 times; push-back 2 twice; pop-front once
    {
        fcb_int_16_t b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    V:  |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |    16 |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());
        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.begin(), b.end(), 0));

        for (int i = 0; i != 15; ++i)
        {
            b.pop_front();
        }

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |     0 |
    V:  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |    16 |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(1, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, *b.begin());
        XTESTS_TEST_INTEGER_EQUAL(16, std::accumulate(b.begin(), b.end(), 0));

        b.try_push_back_range({ 17, 18, 19, 20 });

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     1 |     2 |     3 |     4 |       |       |       |       |       |       |       |       |       |       |       |     0 |
    V:  |    17 |    18 |    19 |    20 |       |       |       |       |       |       |       |       |       |       |       |    16 |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(5, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, *b.begin());
        XTESTS_TEST_INTEGER_EQUAL(90, std::accumulate(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(16, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(17, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(18, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(19, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(20, b[4]);

        // ///////////////////////////////////////

        // Now at this point we do two `erase()`s, and measure each
        // one at a time

        b.erase(b.begin() + 2);

/*
    I:  |     0 |     1 |     2 |     3 |     4 |     5 |     6 |     7 |     8 |     9 |    10 |    11 |    12 |    13 |    14 |    15 |
    E:  |     1 |     2 |     3 |       |       |       |       |       |       |       |       |       |       |       |       |     0 |
    V:  |    17 |    19 |    20 |       |       |       |       |       |       |       |       |       |       |       |       |    16 |
    B:  |     ⬆️                                                                                                                        |
 */

        XTESTS_TEST_INTEGER_EQUAL(4, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, *b.begin());
        XTESTS_TEST_INTEGER_EQUAL(72, std::accumulate(b.begin(), b.end(), 0));

        XTESTS_TEST_INTEGER_EQUAL(16, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(17, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(19, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(20, b[3]);
    }
}

static void test_q16_offsetted_erase(void)
{
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());

        XTESTS_TEST_INTEGER_EQUAL(1, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(2, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(3, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[11]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[13]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[14]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[15]);

        b.erase(b.begin(), b.begin() + 4);

        XTESTS_TEST_INTEGER_EQUAL(12, b.size());

        XTESTS_TEST_INTEGER_EQUAL(5, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[11]);

        b.try_push_back_range( { 17, 18, 19, 20 });

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());

        XTESTS_TEST_INTEGER_EQUAL(5, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[11]);
        /* ------------------------------  */
        XTESTS_TEST_INTEGER_EQUAL(17, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(18, b[13]);
        XTESTS_TEST_INTEGER_EQUAL(19, b[14]);
        XTESTS_TEST_INTEGER_EQUAL(20, b[15]);

        b.erase(b.begin() + 4, b.begin() + 6);

        XTESTS_TEST_INTEGER_EQUAL(14, b.size());

        XTESTS_TEST_INTEGER_EQUAL(5, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[3]);
        /* - - - - - - - - - - - - - - - - */
        XTESTS_TEST_INTEGER_EQUAL(11, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[9]);
        /* ------------------------------  */
        XTESTS_TEST_INTEGER_EQUAL(17, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(18, b[11]);
        XTESTS_TEST_INTEGER_EQUAL(19, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(20, b[13]);
    }
}

static void test_q16_pop_front_and_pop_back(void)
{
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_TRUE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.cbegin(), b.cend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.rbegin(), b.rend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(136, std::accumulate(b.crbegin(), b.crend(), 0));

        XTESTS_TEST_INTEGER_EQUAL(1, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(2, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(3, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[11]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[13]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[14]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[15]);

        b.pop_front();

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(15, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST_INTEGER_EQUAL(135, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(135, std::accumulate(b.cbegin(), b.cend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(135, std::accumulate(b.rbegin(), b.rend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(135, std::accumulate(b.crbegin(), b.crend(), 0));

        XTESTS_TEST_INTEGER_EQUAL(2, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(3, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[11]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[13]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[14]);

        b.pop_front();

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(14, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST_INTEGER_EQUAL(133, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(133, std::accumulate(b.cbegin(), b.cend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(133, std::accumulate(b.rbegin(), b.rend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(133, std::accumulate(b.crbegin(), b.crend(), 0));

        XTESTS_TEST_INTEGER_EQUAL(3, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[11]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[13]);

        b.try_push_back(17);

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(15, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST_INTEGER_EQUAL(150, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(150, std::accumulate(b.cbegin(), b.cend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(150, std::accumulate(b.rbegin(), b.rend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(150, std::accumulate(b.crbegin(), b.crend(), 0));

        XTESTS_TEST_INTEGER_EQUAL(3, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[11]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[13]);
        XTESTS_TEST_INTEGER_EQUAL(17, b[14]);

        b.try_push_back(18);

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_TRUE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(16, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST_INTEGER_EQUAL(168, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(168, std::accumulate(b.cbegin(), b.cend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(168, std::accumulate(b.rbegin(), b.rend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(168, std::accumulate(b.crbegin(), b.crend(), 0));

        XTESTS_TEST_INTEGER_EQUAL(3, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(4, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(5, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(6, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(7, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[11]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[12]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[13]);
        XTESTS_TEST_INTEGER_EQUAL(17, b[14]);
        XTESTS_TEST_INTEGER_EQUAL(18, b[15]);

        b.pop_front();
        b.pop_front();
        b.pop_front();
        b.pop_front();

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(12, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST_INTEGER_EQUAL(150, std::accumulate(b.begin(), b.end(), 0));
        XTESTS_TEST_INTEGER_EQUAL(150, std::accumulate(b.cbegin(), b.cend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(150, std::accumulate(b.rbegin(), b.rend(), 0));
        XTESTS_TEST_INTEGER_EQUAL(150, std::accumulate(b.crbegin(), b.crend(), 0));

        XTESTS_TEST_INTEGER_EQUAL(7, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(8, b[1]);
        XTESTS_TEST_INTEGER_EQUAL(9, b[2]);
        XTESTS_TEST_INTEGER_EQUAL(10, b[3]);
        XTESTS_TEST_INTEGER_EQUAL(11, b[4]);
        XTESTS_TEST_INTEGER_EQUAL(12, b[5]);
        XTESTS_TEST_INTEGER_EQUAL(13, b[6]);
        XTESTS_TEST_INTEGER_EQUAL(14, b[7]);
        XTESTS_TEST_INTEGER_EQUAL(15, b[8]);
        XTESTS_TEST_INTEGER_EQUAL(16, b[9]);
        XTESTS_TEST_INTEGER_EQUAL(17, b[10]);
        XTESTS_TEST_INTEGER_EQUAL(18, b[11]);
    }
}



} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

