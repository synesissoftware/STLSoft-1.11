
/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.system.cmdargs/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::cmdargs`.
 *
 * Created: 29th December 2024
 * Updated: 20th March 2025
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
#include <sstream>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void TEST_EMPTY();
    static void TEST_PROGRAM_ONLY();
    static void TEST_1_VALUE();
    static void TEST_2_VALUES();
    static void TEST_3_VALUES();
    static void TEST_1_OPTION();
    static void TEST_1_OPTION_WITH_VALUE();
    static void TEST_1_OPTION_WITH_VALUE_AND_1_VALUE();
    static void TEST_SINGLE_DASH();
    static void TEST_DOUBLE_DASH();
    static void TEST_DOUBLE_DASH_WITH_VALUES_AND_OPTIONS();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

namespace {

    template <ss_typename_param_k T>
    std::string
    streamable_to_string(
        T const&    t
    )
    {
        std::stringstream stm;

        stm << t;

        return stm.str();
    }
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.system.cmdargs", verbosity))
    {
        XTESTS_RUN_CASE(TEST_EMPTY);
        XTESTS_RUN_CASE(TEST_PROGRAM_ONLY);
        XTESTS_RUN_CASE(TEST_1_VALUE);
        XTESTS_RUN_CASE(TEST_2_VALUES);
        XTESTS_RUN_CASE(TEST_3_VALUES);
        XTESTS_RUN_CASE(TEST_1_OPTION);
        XTESTS_RUN_CASE(TEST_1_OPTION_WITH_VALUE);
        XTESTS_RUN_CASE(TEST_1_OPTION_WITH_VALUE_AND_1_VALUE);
        XTESTS_RUN_CASE(TEST_SINGLE_DASH);
        XTESTS_RUN_CASE(TEST_DOUBLE_DASH);
        XTESTS_RUN_CASE(TEST_DOUBLE_DASH_WITH_VALUES_AND_OPTIONS);

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
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

static void TEST_EMPTY()
{
    char* argv[] =
    {
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values().size());
}

static void TEST_PROGRAM_ONLY()
{
    char* argv[] =
    {
        "my-program",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("my-program", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values().size());
}

static void TEST_1_VALUE()
{
    char* argv[] =
    {
        "my-program",
        "abc",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("my-program", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.values().size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", streamable_to_string(ca.values()[0]));
}

static void TEST_2_VALUES()
{
    char* argv[] =
    {
        "my-program",
        "abc",
        "d e f",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("my-program", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(2u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(2u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(2u, ca.values().size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", streamable_to_string(ca.values()[0]));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("d e f", streamable_to_string(ca.values()[1]));
}

static void TEST_3_VALUES()
{
    char* argv[] =
    {
        "my-program",
        "abc",
        "d e f",
        "ghi",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("my-program", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(3u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(3u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(3u, ca.values().size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", streamable_to_string(ca.values()[0]));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("d e f", streamable_to_string(ca.values()[1]));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", streamable_to_string(ca.values()[2]));
}

static void TEST_1_OPTION()
{
    char* argv[] =
    {
        "my-program",
        "-abc",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("my-program", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values().size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-abc", streamable_to_string(ca.options()[0]));
}

static void TEST_1_OPTION_WITH_VALUE()
{
    char* argv[] =
    {
        "my-program",
        "--abc=d e f",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("my-program", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values().size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("--abc=d e f", streamable_to_string(ca.options()[0]));
}

static void TEST_1_OPTION_WITH_VALUE_AND_1_VALUE()
{
    char* argv[] =
    {
        "my-program",
        "--abc=d e f",
        "v",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("my-program", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(2u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.values().size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("--abc=d e f", streamable_to_string(ca.options()[0]));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("v", streamable_to_string(ca.values()[0]));
}

static void TEST_SINGLE_DASH()
{
    char* argv[] =
    {
        "my-program",
        "-",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("my-program", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values().size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-", streamable_to_string(ca.options()[0]));
}

static void TEST_DOUBLE_DASH()
{
    char* argv[] =
    {
        "my-program",
        "--",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("my-program", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(0u, ca.values().size());
}

static void TEST_DOUBLE_DASH_WITH_VALUES_AND_OPTIONS()
{
    char* argv[] =
    {
        "my-program",
        "--abc=d e f",
        "v1",
        "--",
        "--ghi=m n o",
        "v2",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("my-program", ca.program_name());
    XTESTS_TEST_INTEGER_EQUAL(4u, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(3u, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(1u, ca.options().size());
    XTESTS_TEST_INTEGER_EQUAL(3u, ca.values().size());
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

