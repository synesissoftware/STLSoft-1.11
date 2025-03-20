/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.algorithm.generate_bbst_order/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::generate_bbst_order`.
 *
 * Created: 19th March 2025
 * Updated: 20th March 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* ///////////////////////////////////////////////
 * test component header file include(s)
 */

/*
#include <stlsoft/algorithm/generate_bbst_order.hpp>
 */


/* ///////////////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/meta/is_integral_type.hpp>
#include <stlsoft/util/true_typedef.hpp>

/* Standard C++ header files */
#include <vector>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * STLSoft
 */

namespace stlsoft
{

} // stlsoft


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_generate_binary_1();
    static void TEST_generate_binary_2();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.algorithm.generate_bbst_order", verbosity))
    {
        XTESTS_RUN_CASE(TEST_generate_binary_1);
        XTESTS_RUN_CASE(TEST_generate_binary_2);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * utility functions
 */

namespace
{

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void TEST_generate_binary_1()
{
}
static void TEST_generate_binary_2()
{
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

