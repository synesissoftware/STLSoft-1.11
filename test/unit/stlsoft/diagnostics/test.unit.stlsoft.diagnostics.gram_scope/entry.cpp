/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.container.gram_scope/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::gram_scope`.
 *
 * Created: 15th December 2024
 * Updated: 17th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* ///////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/diagnostics/gram_scope.hpp>

/* ///////////////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <platformstl/diagnostics/stopwatch.hpp>
#include <platformstl/synch/sleep_functions.h>
#include <stlsoft/diagnostics/doomgram.hpp>

/* Standard C++ header files */
#include <numeric>
#include <stdexcept>
#include <string>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_gram_scope_CONSTRUCT_FROM_INSTANCES();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.container.doomgram", verbosity))
    {
        XTESTS_RUN_CASE(TEST_gram_scope_CONSTRUCT_FROM_INSTANCES);

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

static void TEST_gram_scope_CONSTRUCT_FROM_INSTANCES()
{
    platformstl::stopwatch  sw;
    stlsoft::doomgram       gram;

    {
        stlsoft::gram_scope scope(gram, sw);

        platformstl::micro_sleep(10000);
    }

    auto const total_time_ns = gram.total_event_time_ns_raw();

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10000000, total_time_ns);
    XTESTS_TEST_INTEGER_LESS_OR_EQUAL(20000000, total_time_ns);
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

