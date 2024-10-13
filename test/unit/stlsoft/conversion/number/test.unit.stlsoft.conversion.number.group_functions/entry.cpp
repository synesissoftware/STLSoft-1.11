/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.conversion.byte_format_functions.cpp
 *
 * Purpose: Unit-tests for `stlsoft::basic_simple_string`.
 *
 * Created: 28th March 2024
 * Updated: 11th October 2024
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

    static void test_number_0(void);
    static void test_number_987654321_with_default_separators(void);
    static void test_number_987654321_with_custom_separators(void);
#if 0
    static void test_1_23(void);
    static void test_1_24(void);
    static void test_1_25(void);
    static void test_1_26(void);
    static void test_1_27(void);
    static void test_1_28(void);
    static void test_1_29(void);
    static void test_1_30(void);
#endif
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
        XTESTS_RUN_CASE(test_number_0);
        XTESTS_RUN_CASE(test_number_987654321_with_default_separators);
        XTESTS_RUN_CASE(test_number_987654321_with_custom_separators);
#if 0
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_1_24);
        XTESTS_RUN_CASE(test_1_25);
        XTESTS_RUN_CASE(test_1_26);
        XTESTS_RUN_CASE(test_1_27);
        XTESTS_RUN_CASE(test_1_28);
        XTESTS_RUN_CASE(test_1_29);
        XTESTS_RUN_CASE(test_1_30);
#endif

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
  typedef std::string       string_a_t;

static void test_number_0()
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

        XTESTS_TEST_INTEGER_EQUAL(2, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", string_a_t(dest, n - 1));
    }
}

static void test_number_987654321_with_default_separators()
{
    char      dest[101];
    const int v  =  987654321;
    size_t    n;

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "9", v);

    XTESTS_TEST_INTEGER_EQUAL(10, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987654321", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "1", v);

    XTESTS_TEST_INTEGER_EQUAL(11, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("98765432,1", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "2;1", v);

    XTESTS_TEST_INTEGER_EQUAL(12, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987654,3,21", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";3;1", v);

    XTESTS_TEST_INTEGER_EQUAL(12, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("98765,4,321", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";3;3", v);

    XTESTS_TEST_INTEGER_EQUAL(12, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987,654,321", string_a_t(dest, n - 1));
}

static void test_number_987654321_with_custom_separators()
{
    char      dest[101];
    const int v  =  987654321;
    size_t    n;

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "9", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(10, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987654321", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "1", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(11, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("98765432.1", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "2|1", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(12, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987654.3.21", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "|3|1", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(12, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("98765.4.321", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "|3|3", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(12, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987.654.321", string_a_t(dest, n - 1));

    n = stlsoft::format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "|3|1|2", v, '|', '.');

    XTESTS_TEST_INTEGER_EQUAL(13, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("987.65.4.321", string_a_t(dest, n - 1));
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

