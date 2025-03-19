/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.container.frequency_map/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::frequency_map`.
 *
 * Created: 19th March 2025
 * Updated: 19th March 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* ///////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/containers/frequency_map.hpp>


/* ///////////////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/meta/is_integral_type.hpp>

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
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.container.frequency_map", verbosity))
    {
        XTESTS_RUN_CASE(TEST_generate_binary_1);

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
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

