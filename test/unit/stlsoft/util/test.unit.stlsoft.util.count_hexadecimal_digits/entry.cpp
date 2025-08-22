/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.util.count_hexadecimal_digits/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::count_hexadecimal_digits`.
 *
 * Created: 18th October 2024
 * Updated: 20th March 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/util/count_digits/count_hexadecimal_digits.h>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void TEST_count_hexadecimal_digits_WITH_uint16();
    static void TEST_count_hexadecimal_digits_WITH_uint32();
    static void TEST_count_hexadecimal_digits_WITH_uint64();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.util.count_hexadecimal_digits", verbosity))
    {
        XTESTS_RUN_CASE(TEST_count_hexadecimal_digits_WITH_uint16);
        XTESTS_RUN_CASE(TEST_count_hexadecimal_digits_WITH_uint32);
        XTESTS_RUN_CASE(TEST_count_hexadecimal_digits_WITH_uint64);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

static void TEST_count_hexadecimal_digits_WITH_uint16()
{
    typedef stlsoft::ss_uint16_t                            uint_t;

    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::count_hexadecimal_digits(uint_t(0)));

    for (uint_t i = 0x1; 0x10 != i; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::count_hexadecimal_digits(i));
    }

    for (uint_t i = 0x10; 0x100 != i; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(2, stlsoft::count_hexadecimal_digits(i));
    }

    for (uint_t i = 0x100; 0x1000 != i; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(3, stlsoft::count_hexadecimal_digits(i));
    }

    for (uint_t i = 0x1000; 0xffff != i; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(4, stlsoft::count_hexadecimal_digits(i));
    }
}

static void TEST_count_hexadecimal_digits_WITH_uint32()
{
    typedef stlsoft::ss_uint32_t                            uint_t;

    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::count_hexadecimal_digits(uint_t(0)));

    for (uint_t i = 0x1; 0x10 != i; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::count_hexadecimal_digits(i));
    }

    for (uint_t i = 0x10; 0x100 != i; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(2, stlsoft::count_hexadecimal_digits(i));
    }

    for (uint_t i = 0x100; 0x1000 != i; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(3, stlsoft::count_hexadecimal_digits(i));
    }

    for (uint_t i = 0x1000; 0x10000 != i; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(4, stlsoft::count_hexadecimal_digits(i));
    }

    for (uint_t i = 0x10000; 0x100000 != i; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(5, stlsoft::count_hexadecimal_digits(i));
    }

    for (uint_t i = 0x100000; 0x1000000 != i; i += 10)
    {
        XTESTS_TEST_INTEGER_EQUAL(6, stlsoft::count_hexadecimal_digits(i));
    }

    for (uint_t i = 0x1000000; 0x10000000 != i; i += 10)
    {
        XTESTS_TEST_INTEGER_EQUAL(7, stlsoft::count_hexadecimal_digits(i));
    }

    XTESTS_TEST_INTEGER_EQUAL(8, stlsoft::count_hexadecimal_digits(uint_t(0x10000000)));
    XTESTS_TEST_INTEGER_EQUAL(8, stlsoft::count_hexadecimal_digits(uint_t(0xffffffff)));
}

static void TEST_count_hexadecimal_digits_WITH_uint64()
{
    typedef stlsoft::ss_uint64_t                            uint_t;

    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::count_hexadecimal_digits(uint_t(0)));

    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::count_hexadecimal_digits(uint_t(0x1)));
    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::count_hexadecimal_digits(uint_t(0xf)));

    XTESTS_TEST_INTEGER_EQUAL(2, stlsoft::count_hexadecimal_digits(uint_t(0x10)));
    XTESTS_TEST_INTEGER_EQUAL(2, stlsoft::count_hexadecimal_digits(uint_t(0xff)));

    XTESTS_TEST_INTEGER_EQUAL(3, stlsoft::count_hexadecimal_digits(uint_t(0x100)));
    XTESTS_TEST_INTEGER_EQUAL(3, stlsoft::count_hexadecimal_digits(uint_t(0xfff)));

    XTESTS_TEST_INTEGER_EQUAL(4, stlsoft::count_hexadecimal_digits(uint_t(0x1000)));
    XTESTS_TEST_INTEGER_EQUAL(4, stlsoft::count_hexadecimal_digits(uint_t(0xffff)));

    XTESTS_TEST_INTEGER_EQUAL(5, stlsoft::count_hexadecimal_digits(uint_t(0x10000)));
    XTESTS_TEST_INTEGER_EQUAL(5, stlsoft::count_hexadecimal_digits(uint_t(0xfffff)));

    XTESTS_TEST_INTEGER_EQUAL(6, stlsoft::count_hexadecimal_digits(uint_t(0x100000)));
    XTESTS_TEST_INTEGER_EQUAL(6, stlsoft::count_hexadecimal_digits(uint_t(0xffffff)));

    XTESTS_TEST_INTEGER_EQUAL(7, stlsoft::count_hexadecimal_digits(uint_t(0x1000000)));
    XTESTS_TEST_INTEGER_EQUAL(7, stlsoft::count_hexadecimal_digits(uint_t(0xfffffff)));

    XTESTS_TEST_INTEGER_EQUAL(8, stlsoft::count_hexadecimal_digits(uint_t(0x10000000)));
    XTESTS_TEST_INTEGER_EQUAL(8, stlsoft::count_hexadecimal_digits(uint_t(0xffffffff)));

    XTESTS_TEST_INTEGER_EQUAL(9, stlsoft::count_hexadecimal_digits(uint_t(0x100000000)));
    XTESTS_TEST_INTEGER_EQUAL(9, stlsoft::count_hexadecimal_digits(uint_t(0xfffffffff)));

    XTESTS_TEST_INTEGER_EQUAL(10, stlsoft::count_hexadecimal_digits(uint_t(0x1000000000)));
    XTESTS_TEST_INTEGER_EQUAL(10, stlsoft::count_hexadecimal_digits(uint_t(0xffffffffff)));

    XTESTS_TEST_INTEGER_EQUAL(11, stlsoft::count_hexadecimal_digits(uint_t(0x10000000000)));
    XTESTS_TEST_INTEGER_EQUAL(11, stlsoft::count_hexadecimal_digits(uint_t(0xfffffffffff)));

    XTESTS_TEST_INTEGER_EQUAL(12, stlsoft::count_hexadecimal_digits(uint_t(0x100000000000)));
    XTESTS_TEST_INTEGER_EQUAL(12, stlsoft::count_hexadecimal_digits(uint_t(0xffffffffffff)));
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

