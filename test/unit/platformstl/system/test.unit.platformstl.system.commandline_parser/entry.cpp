
/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.platformstl.system.commandline_parser/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::commandline_parser` / `winstl::commandline_parser`.
 *
 * Created: 29th December 2024
 * Updated: 22nd August 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <platformstl/platformstl.h>
#if 0
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <winstl/system/commandline_parser.hpp>
#else
# include <stlsoft/system/commandline_parser.hpp>
#endif

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

namespace {

    static void TEST_EMPTY_STRING();
    static void TEST_WHITESPACE_ONLY_STRING();
    static void TEST_ONE_VALUE();
    static void TEST_TWO_VALUES();
    static void TEST_ONE_FLAG();
    static void TEST_TWO_FLAGS();
    static void TEST_ONE_OPTION();
    static void TEST_DOC_EXAMPLE();
    static void TEST_ONE_OPTION_WITH_SPACES_1();
    static void TEST_ONE_OPTION_WITH_SPACES_2();
    static void TEST_ONE_OPTION_WITH_MANY_STRING_SECTIONS();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.platformstl.system.commandline_parser", verbosity))
    {
        XTESTS_RUN_CASE(TEST_EMPTY_STRING);
        XTESTS_RUN_CASE(TEST_WHITESPACE_ONLY_STRING);
        XTESTS_RUN_CASE(TEST_ONE_VALUE);
        XTESTS_RUN_CASE(TEST_TWO_VALUES);
        XTESTS_RUN_CASE(TEST_ONE_FLAG);
        XTESTS_RUN_CASE(TEST_TWO_FLAGS);
        XTESTS_RUN_CASE(TEST_ONE_OPTION);
        XTESTS_RUN_CASE(TEST_DOC_EXAMPLE);
        XTESTS_RUN_CASE(TEST_ONE_OPTION_WITH_SPACES_1);
        XTESTS_RUN_CASE(TEST_ONE_OPTION_WITH_SPACES_2);
        XTESTS_RUN_CASE(TEST_ONE_OPTION_WITH_MANY_STRING_SECTIONS);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * names
 */

namespace {

#if 0
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
    using winstl::commandline_parser_a;
#else
    using stlsoft::commandline_parser_a;
#endif
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

static void TEST_EMPTY_STRING()
{
    commandline_parser_a const clp("");

    XTESTS_TEST_INTEGER_EQUAL(0u, clp.size());
    XTESTS_TEST_INTEGER_EQUAL(0, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_POINTER_EQUAL(NULL, clp[0]);
}

static void TEST_WHITESPACE_ONLY_STRING()
{
    commandline_parser_a const clp("  \t\n");

    XTESTS_TEST_INTEGER_EQUAL(0u, clp.size());
    XTESTS_TEST_INTEGER_EQUAL(0, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_POINTER_EQUAL(NULL, clp[0]);
}

static void TEST_ONE_VALUE()
{
    commandline_parser_a const clp(" abc ");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, clp.size()));
    XTESTS_TEST_INTEGER_EQUAL(1, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", clp[0]);
    XTESTS_TEST_POINTER_EQUAL(NULL, clp[1]);
}

static void TEST_TWO_VALUES()
{
    commandline_parser_a const clp(" abc def");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, clp.size()));
    XTESTS_TEST_INTEGER_EQUAL(2, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", clp[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", clp[1]);
    XTESTS_TEST_POINTER_EQUAL(NULL, clp[2]);
}

static void TEST_ONE_FLAG()
{
    commandline_parser_a const clp("--flag1");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, clp.size()));
    XTESTS_TEST_INTEGER_EQUAL(1, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("--flag1", clp[0]);
    XTESTS_TEST_POINTER_EQUAL(NULL, clp[1]);
}

static void TEST_TWO_FLAGS()
{
    commandline_parser_a const clp("--flag1 \t -f2\t");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, clp.size()));
    XTESTS_TEST_INTEGER_EQUAL(2, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("--flag1", clp[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-f2", clp[1]);
    XTESTS_TEST_POINTER_EQUAL(NULL, clp[2]);
}

static void TEST_ONE_OPTION()
{
    commandline_parser_a const clp("--option1=abc");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, clp.size()));
    XTESTS_TEST_INTEGER_EQUAL(1, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("--option1=abc", clp[0]);
    XTESTS_TEST_POINTER_EQUAL(NULL, clp[1]);
}

static void TEST_DOC_EXAMPLE()
{
    commandline_parser_a const clp("abc \"d e f\" ghi");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, clp.size()));
    XTESTS_TEST_INTEGER_EQUAL(3, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", clp[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("d e f", clp[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", clp[2]);
    XTESTS_TEST_POINTER_EQUAL(NULL, clp[3]);
}

static void TEST_ONE_OPTION_WITH_SPACES_1()
{
    commandline_parser_a const clp("--option1=\"a b c\"");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, clp.size()));
    XTESTS_TEST_INTEGER_EQUAL(1, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("--option1=a b c", clp[0]);
    XTESTS_TEST_POINTER_EQUAL(NULL, clp[1]);
}

static void TEST_ONE_OPTION_WITH_SPACES_2()
{
    commandline_parser_a const clp("--option1=\"a b \"c");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, clp.size()));
    XTESTS_TEST_INTEGER_EQUAL(1, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("--option1=a b c", clp[0]);
    XTESTS_TEST_POINTER_EQUAL(NULL, clp[1]);
}

static void TEST_ONE_OPTION_WITH_MANY_STRING_SECTIONS()
{
    commandline_parser_a const clp("--option1=\"\"\"a \"\"b \"c");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, clp.size()));
    XTESTS_TEST_INTEGER_EQUAL(1, std::distance(clp.begin(), clp.end()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("--option1=a b c", clp[0]);
    XTESTS_TEST_POINTER_EQUAL(NULL, clp[1]);
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

