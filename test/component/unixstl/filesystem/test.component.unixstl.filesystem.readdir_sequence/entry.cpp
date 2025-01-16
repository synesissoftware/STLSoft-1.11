/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.unixstl.filesystem.readdir_sequence/entry.cpp
 *
 * Purpose: Component test for `unixstl::readdir_sequence`.
 *
 * Created: sometime in 2010s
 * Updated: 28th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <unixstl/filesystem/readdir_sequence.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>
#include <xtests/util/temp_directory.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_empty_directory();
    static void test_non_empty_directory();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.unixstl.filesystem.readdir_sequence", verbosity))
    {
        XTESTS_RUN_CASE(test_empty_directory);
        XTESTS_RUN_CASE(test_non_empty_directory);

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

    typedef unixstl::readdir_sequence                       readdir_sequence_t;

    using ::xtests::cpp::util::temp_directory;


static void test_empty_directory()
{
    temp_directory dir(temp_directory::EmptyOnClose | temp_directory::EmptyOnOpen | temp_directory::RemoveOnClose);

    readdir_sequence_t rds(dir);
    // readdir_sequence_t rds(dir.c_str());

    XTESTS_TEST_BOOLEAN_TRUE(rds.empty());
}

static void test_non_empty_directory()
{
    readdir_sequence_t rds(".");

    XTESTS_TEST_BOOLEAN_FALSE(rds.empty());
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

