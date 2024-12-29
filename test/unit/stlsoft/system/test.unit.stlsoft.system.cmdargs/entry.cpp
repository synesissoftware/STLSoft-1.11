
/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.stlsoft.cmdargs/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::cmdargs`.
 *
 * Created: 29th December 2024
 * Updated: 29th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/system/cmdargs.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <algorithm>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_EMPTY();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.platformstl.diagnostics.stopwatch", verbosity))
    {
        XTESTS_RUN_CASE(TEST_EMPTY);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * names
 */

namespace {

    using stlsoft::cmdargs;
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

static void TEST_EMPTY()
{
    char* argv[] =
    {
        ss_nullptr_k
    };

    cmdargs const ca(0, argv);

    XTESTS_TEST_INTEGER_EQUAL(0, ca.size());
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

