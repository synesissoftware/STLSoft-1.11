/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.stlsoft.system.environment_block/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::environment_block`.
 *
 * Created: 11th August 2010
 * Updated: 15th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */


// TODO: move stlsoft/containers/environment_block.hpp to stlsoft/system/environment_block.hpp
#include <stlsoft/containers/environment_block.hpp>


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

    static void test_empty(void);
    static void test_1_element(void);
    static void test_2_elements(void);
    static void test_clear(void);


} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.stlsoft.system.environment_block", verbosity))
    {
        XTESTS_RUN_CASE(test_empty);
        XTESTS_RUN_CASE(test_1_element);
        XTESTS_RUN_CASE(test_2_elements);
        XTESTS_RUN_CASE(test_clear);

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

static void test_empty(void)
{
    stlsoft::environment_block_a block;

    XTESTS_TEST_INTEGER_EQUAL(0u, block.size());
}

static void test_1_element(void)
{
    stlsoft::environment_block_a block;

    block.push_back("key-1", "value-1");

    XTESTS_TEST_INTEGER_EQUAL(1u, block.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("key-1=value-1", block.base()[0]);
}

static void test_2_elements(void)
{
    stlsoft::environment_block_a block;

    block.push_back("key-1", "value-1");
    block.push_back("key-0", "value-0");

    XTESTS_TEST_INTEGER_EQUAL(2u, block.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("key-1=value-1", block.base()[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("key-0=value-0", block.base()[1]);
}

static void test_clear(void)
{
    stlsoft::environment_block_a block;

    block.push_back("key-0", "value-0");
    block.push_back("key-1", "value-1");
    block.push_back("key-3", "value-3");

    XTESTS_TEST_INTEGER_EQUAL(3u, block.size());

    block.clear();

    XTESTS_TEST_INTEGER_EQUAL(0u, block.size());
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

