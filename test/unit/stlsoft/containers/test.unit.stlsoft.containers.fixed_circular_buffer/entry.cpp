/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.container.fixed_circular_buffer.cpp
 *
 * Purpose: Unit-tests for `stlsoft::fixed_circular_buffer`.
 *
 * Created: 10th March 2024
 * Updated: 11th March 2024
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

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_empty(void);
    static void test_try_push_back(void);
    static void test_fill(void);
    static void test_initialiser_list(void);

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
        XTESTS_RUN_CASE(test_empty);
        XTESTS_RUN_CASE(test_try_push_back);
        XTESTS_RUN_CASE(test_fill);
        XTESTS_RUN_CASE(test_initialiser_list);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{


    typedef stlsoft::fixed_circular_buffer<int, 16>         fcb_int_16_t;


static void test_empty(void)
{
    {
        fcb_int_16_t   b;

        XTESTS_TEST_BOOLEAN_TRUE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(0, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() == b.begin());

        int const sum = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(0, sum);
    }
}

static void test_try_push_back(void)
{
    {
        fcb_int_16_t   b;

        XTESTS_TEST_BOOLEAN_TRUE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(0, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() == b.begin());

        int const sum = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(0, sum);


        bool r = b.try_push_back(1);

        XTESTS_TEST_BOOLEAN_TRUE(r);

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(1, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() != b.begin());

        int const sum_after = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(1, sum_after);

        XTESTS_TEST_INTEGER_EQUAL(1, b.at(0));
        XTESTS_TEST_INTEGER_EQUAL(1, b[0]);
        XTESTS_TEST_INTEGER_EQUAL(1, b.back());
        XTESTS_TEST_INTEGER_EQUAL(1, b.front());
    }
}

static void test_fill(void)
{
    {
        fcb_int_16_t   b;

        XTESTS_TEST_BOOLEAN_TRUE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(0, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() == b.begin());

        int const sum = std::accumulate(b.begin(), b.end(), 0);

        XTESTS_TEST_INTEGER_EQUAL(0, sum);


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
    }
}

static void test_initialiser_list(void)
{
    {
        fcb_int_16_t   b = { 1, 2, 3, 4, 5, 6, 7, 8 };

        XTESTS_TEST_BOOLEAN_FALSE(b.empty());
        XTESTS_TEST_BOOLEAN_FALSE(b.full());

        XTESTS_TEST_INTEGER_EQUAL(8, b.size());
        XTESTS_TEST_INTEGER_EQUAL(16, b.capacity());

        XTESTS_TEST(b.end() != b.begin());
    }

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
    }

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


} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

