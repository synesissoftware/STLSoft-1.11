/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.unixstl.system.environment_variable/entry.cpp
 *
 * Purpose: Unit-tests for `unixstl::environment_variable`.
 *
 * Created: 11th August 2010
 * Updated: 27th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */


#include <unixstl/system/environment_variable.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_1_00(void);


} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.unixstl.system.environment_variable", verbosity))
    {
        XTESTS_RUN_CASE(test_1_00);

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

static void test_1_00(void)
{
    char const* const PATH = ::getenv("PATH");

    if (NULL != PATH)
    {
        unixstl::environment_variable ev_PATH("PATH");

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(PATH, ev_PATH);
    }
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

