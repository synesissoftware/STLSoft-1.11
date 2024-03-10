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



/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_empty(void);

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
    }

}


} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

