/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.conversion.number.group_functions/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::basic_simple_string`.
 *
 * Created: 28th March 2024
 * Updated: 29th November 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/conversion/number/grouping_functions.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <string>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_format_thousands_SIMPLE(void);
    static void TEST_format_thousands_987654321_WITH_DEFAULT_SEPARATORS(void);
    static void TEST_format_thousands_987654321_WITH_CUSTOM_SEPARATORS(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.conversion.number.grouping_functions", verbosity))
    {
        XTESTS_RUN_CASE(TEST_format_thousands_SIMPLE);
        XTESTS_RUN_CASE(TEST_format_thousands_987654321_WITH_DEFAULT_SEPARATORS);
        XTESTS_RUN_CASE(TEST_format_thousands_987654321_WITH_CUSTOM_SEPARATORS);

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
    typedef std::string                                     string_a_t;


static void TEST_format_thousands_SIMPLE()
{
    char const* const pictures[] =
    {
        "1"
        , "2"
        , ";2"
        , "2;"
        , "4"
        , ";4"
        , "4;"
        , "8"
        , ";8"
        , "8;"
    };

    char      dest[101];
    const int v  =  0;
    size_t    n;

    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(pictures) != i; ++i)
    {
        n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), pictures[i], v);

        XTESTS_TEST_INTEGER_EQUAL(2u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", string_a_t(dest, n - 1));
    }
}

static void TEST_format_thousands_987654321_WITH_DEFAULT_SEPARATORS()
{
    char      dest[101];
    const int v  =  987654321;
    size_t    n;

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "9", v);

    XTESTS_TEST_INTEGER_EQUAL(10u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987654321", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "1", v);

    XTESTS_TEST_INTEGER_EQUAL(11u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("98765432,1", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "2;1", v);

    XTESTS_TEST_INTEGER_EQUAL(12u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987654,3,21", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";3;1", v);

    XTESTS_TEST_INTEGER_EQUAL(12u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("98765,4,321", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";3;3", v);

    XTESTS_TEST_INTEGER_EQUAL(12u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987,654,321", string_a_t(dest, n - 1));
}

static void TEST_format_thousands_987654321_WITH_CUSTOM_SEPARATORS()
{
    char      dest[101];
    const int v  =  987654321;
    size_t    n;

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "9", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(10u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987654321", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "1", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(11u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("98765432.1", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "2|1", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(12u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987654.3.21", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "|3|1", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(12u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("98765.4.321", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "|3|3", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(12u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987.654.321", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "|3|1|2", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(13u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987.65.4.321", string_a_t(dest, n - 1));
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

