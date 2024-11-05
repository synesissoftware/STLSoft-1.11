/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.unixstl.filesystem.memory_mapped_file/entry.cpp
 *
 * Purpose: Component test for `unixstl::memory_mapped_file`.
 *
 * Created: sometime in 2010s
 * Updated: 11th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <unixstl/filesystem/memory_mapped_file.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>
#include <xtests/util/temp_file.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_nonexisting_file(void);
    static void test_existing_file_with_known_contents(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.unixstl.filesystem.memory_mapped_file", verbosity))
    {
        XTESTS_RUN_CASE_THAT_THROWS(test_nonexisting_file, unixstl::filesystem_exception);
        XTESTS_RUN_CASE(test_existing_file_with_known_contents);

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

    using ::xtests::cpp::util::temp_file;


static void test_nonexisting_file(void)
{
    temp_file f(temp_file::DeleteOnOpen | temp_file::DeleteOnClose);

    unixstl::memory_mapped_file mmf(f.c_str());

    XTESTS_TEST_FAIL("should not get here");

    STLSOFT_SUPPRESS_UNUSED(mmf);
}

static void test_existing_file_with_known_contents(void)
{
    stlsoft::byte_t bytes[4 * 1024];

    std::fill_n(&bytes[0], STLSOFT_NUM_ELEMENTS(bytes), stlsoft::byte_t(123));

    temp_file f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen, &bytes[0], STLSOFT_NUM_ELEMENTS(bytes));

    unixstl::memory_mapped_file mmf(f.c_str());

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(sizeof(bytes), mmf.size());
    XTESTS_TEST_BOOLEAN_TRUE((0 == ::memcmp(bytes, mmf.memory(), sizeof(bytes))));
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */
