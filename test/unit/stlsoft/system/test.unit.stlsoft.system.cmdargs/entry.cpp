
/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.stlsoft.cmdargs/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::cmdargs`.
 *
 * Created: 29th December 2024
 * Updated: 29th December 2024
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

namespace
{

    static void TEST_EMPTY();
    static void TEST_PROGRAM_ONLY();
    static void TEST_1_VALUE();
    static void TEST_2_VALUES();
    static void TEST_3_VALUES();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

namespace
{

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

    if (XTESTS_START_RUNNER("test.component.platformstl.diagnostics.stopwatch", verbosity))
    {
        XTESTS_RUN_CASE(TEST_EMPTY);
        XTESTS_RUN_CASE(TEST_PROGRAM_ONLY);
        XTESTS_RUN_CASE(TEST_1_VALUE);
        XTESTS_RUN_CASE(TEST_2_VALUES);
        XTESTS_RUN_CASE(TEST_3_VALUES);

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
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

static void TEST_EMPTY()
{
    char* argv[] =
    {
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_INTEGER_EQUAL(0, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(0, ca.values_size());
}

static void TEST_PROGRAM_ONLY()
{
    char* argv[] =
    {
        "my-program",
        ss_nullptr_k
    };

    cmdargs const ca(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

    XTESTS_TEST_INTEGER_EQUAL(0, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(0, ca.values_size());
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

    XTESTS_TEST_INTEGER_EQUAL(1, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(1, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(1, ca.values().size());
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

    XTESTS_TEST_INTEGER_EQUAL(2, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(2, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(2, ca.values().size());
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

    XTESTS_TEST_INTEGER_EQUAL(3, ca.size());
    XTESTS_TEST_INTEGER_EQUAL(0, ca.options_size());
    XTESTS_TEST_INTEGER_EQUAL(3, ca.values_size());
    XTESTS_TEST_INTEGER_EQUAL(3, ca.values().size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", streamable_to_string(ca.values()[0]));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("d e f", streamable_to_string(ca.values()[1]));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", streamable_to_string(ca.values()[2]));
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

