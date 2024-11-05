/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.winstl.memory.shell_allocator/entry.cpp
 *
 * Purpose: Unit-tests for `winstl::shell_allocator`.
 *
 * Created: 18th October 2024
 * Updated: 5th November 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <winstl/memory/shell_allocator.hpp>

/* /////////////////////////////////////
 * general includes
 */


/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */

/* Standard C header files */
#include <assert.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_alloc_0(void);
    static void test_alloc_small(void);
    static void test_alloc_medium(void);
    static void test_alloc_large(void);
    static void test_alloc_toolarge(void);

    static void test_specialise_list(void);
    static void test_specialise_vector(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.winstl.memory.shell_allocator", verbosity))
    {
        XTESTS_RUN_CASE(test_alloc_0);
        XTESTS_RUN_CASE(test_alloc_small);
        XTESTS_RUN_CASE(test_alloc_medium);
        XTESTS_RUN_CASE(test_alloc_large);
        XTESTS_RUN_CASE(test_alloc_toolarge);

        XTESTS_RUN_CASE(test_specialise_list);
        XTESTS_RUN_CASE(test_specialise_vector);

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

static void test_alloc_0(void)
{

}

static void test_alloc_small(void)
{

}

static void test_alloc_medium(void)
{

}

static void test_alloc_large(void)
{

}

static void test_alloc_toolarge(void)
{

}

static void test_specialise_list(void)
{

}

static void test_specialise_vector(void)
{

}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

