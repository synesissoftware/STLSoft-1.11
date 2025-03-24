/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.iterator.FILE_iterator/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::FILE_iterator`.
 *
 * Created: 24th March 2025
 * Updated: 24th March 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

 #include <stlsoft/iterator/FILE_iterator.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/terse-api.h>
#include <xtests/util/temp_file.hpp>

/* STLSoft header files */
#include <platformstl/filesystem/FILE_stream.hpp>
#include <platformstl/filesystem/file_lines.hpp>

/* Standard C++ header files */
#include <algorithm>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void test_1();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.iterator.FILE_iterator", verbosity))
    {
        XTESTS_RUN_CASE(test_1);


        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace stlsoft {

} // namespace stlsoft


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

    using stlsoft::FILE_iterator;

    using ::xtests::cpp::util::temp_file;


static void test_1()
{
    temp_file f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);

    char const* const strings[] =
    {
        "abc"
    ,   ""
    ,   "jklmnopqrstuvwxyz"
    };


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        std::copy(
            std::begin(strings)
        ,   std::end(strings)
        ,   FILE_iterator<char const*>(stlsoft::get_FILE_ptr(stm), "%s\n")
        );
    }

    {
        platformstl::file_lines     lines(f.c_str());

        REQUIRE(TEST_INT_EQ(3u, lines.size()));
        TEST_MS_EQ("abc", lines[0]);
        TEST_MS_EQ("", lines[1]);
        TEST_MS_EQ("jklmnopqrstuvwxyz", lines[2]);
    }
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

