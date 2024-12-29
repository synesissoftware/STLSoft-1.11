/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.util.bit_functions/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::bit_functions`.
 *
 * Created: 19th March 2010
 * Updated: 29th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/util/bit_functions.h>

/* /////////////////////////////////////
 * general includes
 */


/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <platformstl/diagnostics/stopwatch.hpp>

/* Standard C++ header files */

/* Standard C header files */
#include <assert.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_count_bits_Kernighan();
    static void test_count_bits_8bit_table();
    static void test_find_high_bit_32();
    static void test_find_high_bit_64();
    static void test_calculate_xor_over_range_8_bit();
} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.util.bit_functions", verbosity))
    {
        XTESTS_RUN_CASE(test_count_bits_Kernighan);
        XTESTS_RUN_CASE(test_count_bits_8bit_table);
        XTESTS_RUN_CASE(test_find_high_bit_32);
        XTESTS_RUN_CASE(test_find_high_bit_64);
        XTESTS_RUN_CASE(test_calculate_xor_over_range_8_bit);

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
    using stlsoft::sint8_t;
    using stlsoft::uint8_t;
    using stlsoft::sint16_t;
    using stlsoft::uint16_t;
    using stlsoft::sint32_t;
    using stlsoft::uint32_t;
    using stlsoft::sint64_t;
    using stlsoft::uint64_t;

    using platformstl::stopwatch;

static void test_count_bits_Kernighan()
{
    stopwatch counter;

    counter.start();

    XTESTS_TEST_INTEGER_EQUAL(0u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0)));
    XTESTS_TEST_INTEGER_EQUAL(0u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00000000)));

    XTESTS_TEST_INTEGER_EQUAL(32u, stlsoft::count_bits_by_Kernighan_method(uint32_t(0xffffffff)));

    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_Kernighan_method(uint32_t(0x33333333)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_Kernighan_method(uint32_t(0x55555555)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_Kernighan_method(uint32_t(0x66666666)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_Kernighan_method(uint32_t(0x99999999)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_Kernighan_method(uint32_t(0xaaaaaaaa)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_Kernighan_method(uint32_t(0xcccccccc)));

    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x000000ff)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x0000ff00)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00ff0000)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0xff000000)));

    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00000001)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00000010)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00000100)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00001000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00010000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00100000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x01000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x10000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00000002)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00000020)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00000200)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00002000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00020000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00200000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x02000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x20000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00000002)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00000020)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00000200)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00002000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00020000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00200000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x02000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x20000000)));

    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00001001)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00001010)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00001100)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x01001000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00011000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x00101000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x01001000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_Kernighan_method(uint32_t(0x10001000)));

    counter.stop();

    fprintf(stdout, "t: %luns\n", static_cast<unsigned long>(counter.get_nanoseconds()));
}

static void test_count_bits_8bit_table()
{
    stopwatch counter;

    counter.start();

    XTESTS_TEST_INTEGER_EQUAL(0u,  stlsoft::count_bits_by_8bit_table(uint32_t(0)));
    XTESTS_TEST_INTEGER_EQUAL(0u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00000000)));

    XTESTS_TEST_INTEGER_EQUAL(32u, stlsoft::count_bits_by_8bit_table(uint32_t(0xffffffff)));

    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_8bit_table(uint32_t(0x33333333)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_8bit_table(uint32_t(0x55555555)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_8bit_table(uint32_t(0x66666666)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_8bit_table(uint32_t(0x99999999)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_8bit_table(uint32_t(0xaaaaaaaa)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_by_8bit_table(uint32_t(0xcccccccc)));

    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x000000ff)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x0000ff00)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00ff0000)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_by_8bit_table(uint32_t(0xff000000)));

    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00000001)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00000010)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00000100)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00001000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00010000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00100000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x01000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x10000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00000002)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00000020)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00000200)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00002000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00020000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00200000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x02000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x20000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00000002)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00000020)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00000200)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00002000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00020000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00200000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x02000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x20000000)));

    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00001001)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00001010)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00001100)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x01001000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00011000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x00101000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x01001000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_by_8bit_table(uint32_t(0x10001000)));

    counter.stop();

    fprintf(stdout, "t: %luns\n", static_cast<unsigned long>(counter.get_nanoseconds()));
}

static void test_find_high_bit_32()
{
    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::find_highest_bit(uint32_t(0)));

    XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::find_highest_bit(uint32_t(1)));

    XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::find_highest_bit(uint32_t(2)));
    XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::find_highest_bit(uint32_t(3)));

    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::find_highest_bit(uint32_t(4)));
    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::find_highest_bit(uint32_t(5)));
    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::find_highest_bit(uint32_t(6)));
    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::find_highest_bit(uint32_t(7)));

    XTESTS_TEST_INTEGER_EQUAL(25u, stlsoft::find_highest_bit(uint32_t(0x01000000)));
    XTESTS_TEST_INTEGER_EQUAL(25u, stlsoft::find_highest_bit(uint32_t(0x01f00000)));
    XTESTS_TEST_INTEGER_EQUAL(25u, stlsoft::find_highest_bit(uint32_t(0x010f0000)));
    XTESTS_TEST_INTEGER_EQUAL(25u, stlsoft::find_highest_bit(uint32_t(0x0100ffff)));

    XTESTS_TEST_INTEGER_EQUAL(32u, stlsoft::find_highest_bit(uint32_t(0x80000000)));
}

static void test_find_high_bit_64()
{
    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::find_highest_bit(uint64_t(0)));

    XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::find_highest_bit(uint64_t(1)));

    XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::find_highest_bit(uint64_t(2)));
    XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::find_highest_bit(uint64_t(3)));

    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::find_highest_bit(uint64_t(4)));
    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::find_highest_bit(uint64_t(5)));
    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::find_highest_bit(uint64_t(6)));
    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::find_highest_bit(uint64_t(7)));

    XTESTS_TEST_INTEGER_EQUAL(25u, stlsoft::find_highest_bit(uint64_t(0x01000000)));
    XTESTS_TEST_INTEGER_EQUAL(25u, stlsoft::find_highest_bit(uint64_t(0x01f00000)));
    XTESTS_TEST_INTEGER_EQUAL(25u, stlsoft::find_highest_bit(uint64_t(0x010f0000)));
    XTESTS_TEST_INTEGER_EQUAL(25u, stlsoft::find_highest_bit(uint64_t(0x0100ffff)));

    XTESTS_TEST_INTEGER_EQUAL(32u, stlsoft::find_highest_bit(uint64_t(0x80000000)));

    XTESTS_TEST_INTEGER_EQUAL(33u, stlsoft::find_highest_bit(uint64_t(STLSOFT_GEN_UINT64_SUFFIX(0x100000000))));
    XTESTS_TEST_INTEGER_EQUAL(33u, stlsoft::find_highest_bit(uint64_t(STLSOFT_GEN_UINT64_SUFFIX(0x13c3c3c3c))));

    XTESTS_TEST_INTEGER_EQUAL(41u, stlsoft::find_highest_bit(uint64_t(STLSOFT_GEN_UINT64_SUFFIX(0x10000000000))));
    XTESTS_TEST_INTEGER_EQUAL(41u, stlsoft::find_highest_bit(uint64_t(STLSOFT_GEN_UINT64_SUFFIX(0x13c3c3c3c3c))));

    XTESTS_TEST_INTEGER_EQUAL(45u, stlsoft::find_highest_bit(uint64_t(STLSOFT_GEN_UINT64_SUFFIX(0x100000000000))));
    XTESTS_TEST_INTEGER_EQUAL(45u, stlsoft::find_highest_bit(uint64_t(STLSOFT_GEN_UINT64_SUFFIX(0x1c3c3c3c3c3c))));
}

static void test_calculate_xor_over_range_8_bit()
{
    uint8_t const elements[] =
    {
            0x00

        ,   0x01
        ,   0x02
        ,   0x04
        ,   0x08

        ,   0x01
        ,   0x02
        ,   0x04
        ,   0x08

        ,   0x40
        ,   0x80
        ,   0x10
        ,   0x20
    };

    XTESTS_TEST_INTEGER_EQUAL(0x00, stlsoft::calculate_xor_over_range(elements,  0u));

    XTESTS_TEST_INTEGER_EQUAL(0x00, stlsoft::calculate_xor_over_range(elements,  1u));

    XTESTS_TEST_INTEGER_EQUAL(0x01, stlsoft::calculate_xor_over_range(elements,  2u));
    XTESTS_TEST_INTEGER_EQUAL(0x03, stlsoft::calculate_xor_over_range(elements,  3u));
    XTESTS_TEST_INTEGER_EQUAL(0x07, stlsoft::calculate_xor_over_range(elements,  4u));
    XTESTS_TEST_INTEGER_EQUAL(0x0f, stlsoft::calculate_xor_over_range(elements,  5u));

    XTESTS_TEST_INTEGER_EQUAL(0x0e, stlsoft::calculate_xor_over_range(elements,  6u));
    XTESTS_TEST_INTEGER_EQUAL(0x0c, stlsoft::calculate_xor_over_range(elements,  7u));
    XTESTS_TEST_INTEGER_EQUAL(0x08, stlsoft::calculate_xor_over_range(elements,  8u));
    XTESTS_TEST_INTEGER_EQUAL(0x00, stlsoft::calculate_xor_over_range(elements,  9u));

    XTESTS_TEST_INTEGER_EQUAL(0x40, stlsoft::calculate_xor_over_range(elements, 10u));
    XTESTS_TEST_INTEGER_EQUAL(0xc0, stlsoft::calculate_xor_over_range(elements, 11u));
    XTESTS_TEST_INTEGER_EQUAL(0xd0, stlsoft::calculate_xor_over_range(elements, 12u));
    XTESTS_TEST_INTEGER_EQUAL(0xf0, stlsoft::calculate_xor_over_range(elements, 13u));
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */
