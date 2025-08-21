
/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.platformstl.system.pid_sequence/entry.cpp
 *
 * Purpose: Unit-tests for `platformstl::pid_sequence`.
 *
 * Created: 22nd August 2025
 * Updated: 22nd August 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <platformstl/system/pid_sequence.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <algorithm>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void TEST_CONTAINS_SYSTEM_PIDS();
    static void TEST_NOT_CONTAINS_SYSTEM_PIDS();
    static void TEST_CONTAINS_THIS_PROCESS_PID();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.platformstl.system.pid_sequence", verbosity))
    {
        XTESTS_RUN_CASE(TEST_CONTAINS_SYSTEM_PIDS);
        XTESTS_RUN_CASE(TEST_NOT_CONTAINS_SYSTEM_PIDS);
        XTESTS_RUN_CASE(TEST_CONTAINS_THIS_PROCESS_PID);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * names
 */

namespace {

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

static void TEST_CONTAINS_SYSTEM_PIDS()
{
    platformstl::pid_sequence pids(0);

    TEST(pids.end() != std::find(pids.cbegin(), pids.cend(), 0));
    TEST(pids.end() != std::find(pids.cbegin(), pids.cend(), 1));

    TEST(pids.end() == std::find(pids.cbegin(), pids.cend(), std::numeric_limits<platformstl::pid_sequence::value_type>::max()));
}

static void TEST_NOT_CONTAINS_SYSTEM_PIDS()
{
    platformstl::pid_sequence pids;

    TEST(pids.end() == std::find(pids.cbegin(), pids.cend(), 0));
    TEST(pids.end() == std::find(pids.cbegin(), pids.cend(), 1));

    TEST(pids.end() == std::find(pids.cbegin(), pids.cend(), std::numeric_limits<platformstl::pid_sequence::value_type>::max()));
}

static void TEST_CONTAINS_THIS_PROCESS_PID()
{
    platformstl::pid_sequence pids;

#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)

    pid_t const pid = ::getpid();

    TEST(pids.end() != std::find(pids.cbegin(), pids.cend(), pid));
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    DWORD const pid = ::GetCurrentProcessId();

    TEST(pids.end() != std::find(pids.cbegin(), pids.cend(), pid));
#else

#endif
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

