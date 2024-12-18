/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.diagnostics.doomgram/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::doomgram`.
 *
 * Created: 13th May 2013
 * Updated: 17th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* ///////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/diagnostics/doomgram.hpp>

/* ///////////////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <numeric>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector> // for `std::begin()`, `std::end()`

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_doomgram_DEFAULT_CONSTRUCT();
    static void TEST_doomgram_SINGLE_TIMING_EVENT();
    static void TEST_doomgram_ZERO_TIME_EVENTS();
    static void TEST_doomgram_UNIFORM_SPREAD_TIMINGS_1();
    static void TEST_doomgram_UNIFORM_SPREAD_TIMINGS_2();
    static void TEST_doomgram_UNIFORM_SPREAD_TIMINGS_3();
    static void TEST_doomgram_UNIFORM_SPREAD_TIMINGS_4();
    static void TEST_doomgram_SEVERAL_DISTINCT_TIMINGS();
    static void TEST_doomgram_SEVERAL_INTERSECTING_TIMINGS();
    static void TEST_doomgram_MANY_CUMULATIVE_TIMINGS();
    static void TEST_doomgram_OVERFLOW_BY_SECONDS();
    static void TEST_doomgram_OVERFLOW_BY_MICROSECONDS();

    static void TEST_UNSIGNED_OVERFLOW();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.diagnostics.doomgram", verbosity))
    {
        XTESTS_RUN_CASE(TEST_doomgram_DEFAULT_CONSTRUCT);
        XTESTS_RUN_CASE(TEST_doomgram_SINGLE_TIMING_EVENT);
        XTESTS_RUN_CASE(TEST_doomgram_ZERO_TIME_EVENTS);
        XTESTS_RUN_CASE(TEST_doomgram_UNIFORM_SPREAD_TIMINGS_1);
        XTESTS_RUN_CASE(TEST_doomgram_UNIFORM_SPREAD_TIMINGS_2);
        XTESTS_RUN_CASE(TEST_doomgram_UNIFORM_SPREAD_TIMINGS_3);
        XTESTS_RUN_CASE(TEST_doomgram_UNIFORM_SPREAD_TIMINGS_4);
        XTESTS_RUN_CASE(TEST_doomgram_SEVERAL_DISTINCT_TIMINGS);
        XTESTS_RUN_CASE(TEST_doomgram_SEVERAL_INTERSECTING_TIMINGS);
        XTESTS_RUN_CASE(TEST_doomgram_MANY_CUMULATIVE_TIMINGS);
        XTESTS_RUN_CASE(TEST_doomgram_OVERFLOW_BY_SECONDS);
        XTESTS_RUN_CASE(TEST_doomgram_OVERFLOW_BY_MICROSECONDS);

        XTESTS_RUN_CASE(TEST_UNSIGNED_OVERFLOW);

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


static void TEST_doomgram_DEFAULT_CONSTRUCT()
{
    stlsoft::doomgram       dg;
    stlsoft::ss_uint64_t    total_event_time_ns;
    stlsoft::ss_uint64_t    min_event_time_ns;
    stlsoft::ss_uint64_t    max_event_time_ns;

    XTESTS_TEST_BOOLEAN_FALSE(dg.has_overflowed());

    XTESTS_TEST_INTEGER_EQUAL(0, dg.event_count());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(ss_nullptr_k));
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(&total_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(0, total_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(0, dg.total_event_time_ns_raw());
    XTESTS_TEST_BOOLEAN_FALSE(dg.try_get_min_event_time_ns(&min_event_time_ns));
    XTESTS_TEST_BOOLEAN_FALSE(dg.try_get_max_event_time_ns(&max_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1s());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10s());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_ge_100s());
}

static void TEST_doomgram_SINGLE_TIMING_EVENT()
{
    stlsoft::doomgram       dg;
    stlsoft::ss_uint64_t    total_event_time_ns;
    stlsoft::ss_uint64_t    min_event_time_ns;
    stlsoft::ss_uint64_t    max_event_time_ns;

    dg.push_event_time_ms(13);

    XTESTS_TEST_BOOLEAN_FALSE(dg.has_overflowed());

    XTESTS_TEST_INTEGER_EQUAL(1, dg.event_count());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(ss_nullptr_k));
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(&total_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(13000000, total_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(13000000, dg.total_event_time_ns_raw());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_min_event_time_ns(&min_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(13000000, min_event_time_ns);
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_max_event_time_ns(&max_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(13000000, max_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1s());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10s());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_ge_100s());
}

static void TEST_doomgram_ZERO_TIME_EVENTS()
{
    stlsoft::doomgram       dg;
    stlsoft::ss_uint64_t    total_event_time_ns;
    stlsoft::ss_uint64_t    min_event_time_ns;
    stlsoft::ss_uint64_t    max_event_time_ns;

    dg.push_event_time_ns(0);
    dg.push_event_time_us(0);
    dg.push_event_time_ms(0);
    dg.push_event_time_s(0);

    XTESTS_TEST_BOOLEAN_FALSE(dg.has_overflowed());

    XTESTS_TEST_INTEGER_EQUAL(4, dg.event_count());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(ss_nullptr_k));
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(&total_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(0, total_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(0, dg.total_event_time_ns_raw());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_min_event_time_ns(&min_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(0, min_event_time_ns);
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_max_event_time_ns(&max_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(0, max_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1s());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10s());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_ge_100s());
}

static void TEST_doomgram_UNIFORM_SPREAD_TIMINGS_1()
{
    stlsoft::doomgram       dg;
    stlsoft::ss_uint64_t    total_event_time_ns;
    stlsoft::ss_uint64_t    min_event_time_ns;
    stlsoft::ss_uint64_t    max_event_time_ns;

    dg.push_event_time_ns(  9);
    dg.push_event_time_ns( 80);
    dg.push_event_time_ns(700);
    dg.push_event_time_us(  6);
    dg.push_event_time_us( 50);
    dg.push_event_time_us(400);
    dg.push_event_time_ms(  3);
    dg.push_event_time_ms( 20);
    dg.push_event_time_ms(100);
    dg.push_event_time_s(   9);
    dg.push_event_time_s(  80);
    dg.push_event_time_s( 700);

    XTESTS_TEST_BOOLEAN_FALSE(dg.has_overflowed());

    XTESTS_TEST_INTEGER_EQUAL(12, dg.event_count());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(ss_nullptr_k));
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(&total_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(789123456789, total_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(789123456789, dg.total_event_time_ns_raw());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_min_event_time_ns(&min_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(9, min_event_time_ns);
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_max_event_time_ns(&max_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(700000000000, max_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1ns());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10ns());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100ns());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1s());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10s());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_ge_100s());
}

static void TEST_doomgram_UNIFORM_SPREAD_TIMINGS_2()
{
    stlsoft::doomgram       dg;
    stlsoft::ss_uint64_t    total_event_time_ns;
    stlsoft::ss_uint64_t    min_event_time_ns;
    stlsoft::ss_uint64_t    max_event_time_ns;

    dg.push_event_time_ns(     9);
    dg.push_event_time_ns(    80);
    dg.push_event_time_ns(   700);
    dg.push_event_time_ns(  6000);
    dg.push_event_time_ns( 50000);
    dg.push_event_time_ns(400000);
    dg.push_event_time_ms(     3);
    dg.push_event_time_ms(    20);
    dg.push_event_time_ms(   100);
    dg.push_event_time_ms(  9000);
    dg.push_event_time_ms( 80000);
    dg.push_event_time_ms(700000);

    XTESTS_TEST_BOOLEAN_FALSE(dg.has_overflowed());

    XTESTS_TEST_INTEGER_EQUAL(12, dg.event_count());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(ss_nullptr_k));
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(&total_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(789123456789, total_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(789123456789, dg.total_event_time_ns_raw());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_min_event_time_ns(&min_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(9, min_event_time_ns);
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_max_event_time_ns(&max_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(700000000000, max_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1ns());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10ns());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100ns());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1s());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10s());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_ge_100s());
}

static void TEST_doomgram_UNIFORM_SPREAD_TIMINGS_3()
{
    stlsoft::doomgram       dg;
    stlsoft::ss_uint64_t    total_event_time_ns;
    stlsoft::ss_uint64_t    min_event_time_ns;
    stlsoft::ss_uint64_t    max_event_time_ns;

    dg.push_event_time_ns(           9);
    dg.push_event_time_ns(          80);
    dg.push_event_time_ns(         700);
    dg.push_event_time_ns(        6000);
    dg.push_event_time_ns(       50000);
    dg.push_event_time_ns(      400000);
    dg.push_event_time_ns(     3000000);
    dg.push_event_time_ns(    20000000);
    dg.push_event_time_ns(   100000000);
    dg.push_event_time_ns(  9000000000);
    dg.push_event_time_ns( 80000000000);
    dg.push_event_time_ns(700000000000);

    XTESTS_TEST_BOOLEAN_FALSE(dg.has_overflowed());

    XTESTS_TEST_INTEGER_EQUAL(12, dg.event_count());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(ss_nullptr_k));
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(&total_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(789123456789, total_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(789123456789, dg.total_event_time_ns_raw());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_min_event_time_ns(&min_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(9, min_event_time_ns);
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_max_event_time_ns(&max_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(700000000000, max_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1ns());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10ns());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100ns());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1s());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10s());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_ge_100s());
}

static void TEST_doomgram_UNIFORM_SPREAD_TIMINGS_4()
{
    stlsoft::doomgram       dg;
    stlsoft::ss_uint64_t    total_event_time_ns;
    stlsoft::ss_uint64_t    min_event_time_ns;
    stlsoft::ss_uint64_t    max_event_time_ns;

    dg.push_event_time_us(        6);
    dg.push_event_time_us(       50);
    dg.push_event_time_us(      400);
    dg.push_event_time_us(     3000);
    dg.push_event_time_us(    20000);
    dg.push_event_time_us(   100000);
    dg.push_event_time_us(  9000000);
    dg.push_event_time_us( 80000000);
    dg.push_event_time_us(700000000);

    XTESTS_TEST_BOOLEAN_FALSE(dg.has_overflowed());

    XTESTS_TEST_INTEGER_EQUAL(9, dg.event_count());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(ss_nullptr_k));
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(&total_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(789123456000, total_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(789123456000, dg.total_event_time_ns_raw());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_min_event_time_ns(&min_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(6000, min_event_time_ns);
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_max_event_time_ns(&max_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(700000000000, max_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ns());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1s());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10s());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_ge_100s());
}

static void TEST_doomgram_SEVERAL_DISTINCT_TIMINGS()
{
    stlsoft::doomgram       dg;
    stlsoft::ss_uint64_t    total_event_time_ns;
    stlsoft::ss_uint64_t    min_event_time_ns;
    stlsoft::ss_uint64_t    max_event_time_ns;

    dg.push_event_time_ns(23);
    dg.push_event_time_ns(10);
    dg.push_event_time_us(7);
    dg.push_event_time_us(7);
    dg.push_event_time_us(89);
    dg.push_event_time_ms(248);
    dg.push_event_time_s(5);
    dg.push_event_time_s(309);

    XTESTS_TEST_BOOLEAN_FALSE(dg.has_overflowed());

    XTESTS_TEST_INTEGER_EQUAL(8, dg.event_count());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(ss_nullptr_k));
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(&total_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(314248103033, total_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(314248103033, dg.total_event_time_ns_raw());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_min_event_time_ns(&min_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(10, min_event_time_ns);
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_max_event_time_ns(&max_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(309000000000, max_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ns());
    XTESTS_TEST_INTEGER_EQUAL(2, dg.num_events_in_10ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ns());
    XTESTS_TEST_INTEGER_EQUAL(2, dg.num_events_in_1us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_1s());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10s());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_ge_100s());
}

static void TEST_doomgram_SEVERAL_INTERSECTING_TIMINGS()
{
    stlsoft::doomgram       dg;
    stlsoft::ss_uint64_t    total_event_time_ns;
    stlsoft::ss_uint64_t    min_event_time_ns;
    stlsoft::ss_uint64_t    max_event_time_ns;

    dg.push_event_time_ns(11);
    dg.push_event_time_ns(19);
    dg.push_event_time_ns(19);
    dg.push_event_time_us(7);
    dg.push_event_time_us(7);
    dg.push_event_time_us(89);
    dg.push_event_time_ms(248);
    dg.push_event_time_ms(4321);
    dg.push_event_time_s(5);
    dg.push_event_time_s(309);

    XTESTS_TEST_BOOLEAN_FALSE(dg.has_overflowed());

    XTESTS_TEST_INTEGER_EQUAL(10, dg.event_count());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(ss_nullptr_k));
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(&total_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(318569103049, total_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(318569103049, dg.total_event_time_ns_raw());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_min_event_time_ns(&min_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(11, min_event_time_ns);
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_max_event_time_ns(&max_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(309000000000, max_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ns());
    XTESTS_TEST_INTEGER_EQUAL(3, dg.num_events_in_10ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ns());
    XTESTS_TEST_INTEGER_EQUAL(2, dg.num_events_in_1us());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_10us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_1ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10ms());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_in_100ms());
    XTESTS_TEST_INTEGER_EQUAL(2, dg.num_events_in_1s());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10s());
    XTESTS_TEST_INTEGER_EQUAL(1, dg.num_events_ge_100s());
}

static void TEST_doomgram_MANY_CUMULATIVE_TIMINGS()
{
    stlsoft::doomgram       dg;
    stlsoft::ss_uint64_t    total_event_time_ns;
    stlsoft::ss_uint64_t    min_event_time_ns;
    stlsoft::ss_uint64_t    max_event_time_ns;

    { for (int i = 0; 10000 != i; ++i)
    {
        dg.push_event_time_ns(1);
    }}

    { for (int i = 0; 1000 != i; ++i)
    {
        dg.push_event_time_us(1);
    }}

    { for (int i = 0; 100 != i; ++i)
    {
        dg.push_event_time_ms(1);
    }}

    { for (int i = 0; 10 != i; ++i)
    {
        dg.push_event_time_s(1);
    }}

    XTESTS_TEST_BOOLEAN_FALSE(dg.has_overflowed());

    XTESTS_TEST_INTEGER_EQUAL(11110, dg.event_count());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(ss_nullptr_k));
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_total_event_time_ns(&total_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(10101010000, total_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(10101010000, dg.total_event_time_ns_raw());
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_min_event_time_ns(&min_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(1, min_event_time_ns);
    XTESTS_TEST_BOOLEAN_TRUE(dg.try_get_max_event_time_ns(&max_event_time_ns));
    XTESTS_TEST_INTEGER_EQUAL(1000000000, max_event_time_ns);
    XTESTS_TEST_INTEGER_EQUAL(10000, dg.num_events_in_1ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10ns());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ns());
    XTESTS_TEST_INTEGER_EQUAL(1000, dg.num_events_in_1us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10us());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100us());
    XTESTS_TEST_INTEGER_EQUAL(100, dg.num_events_in_1ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10ms());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_100ms());
    XTESTS_TEST_INTEGER_EQUAL(10, dg.num_events_in_1s());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_in_10s());
    XTESTS_TEST_INTEGER_EQUAL(0, dg.num_events_ge_100s());
}

static void TEST_doomgram_OVERFLOW_BY_SECONDS()
{
    stlsoft::doomgram   dg;

    // uint64 max:
    //
    // 18,446,744,073,709,551,615 ns
    //     18,446,744,073,709,551 µs
    //         18,446,744,073,709 ms
    //             18,446,744,073  s

    // 18446744073 max

    // add in max # seconds
    {
        bool r = dg.push_event_time_s(18446744073);

        XTESTS_TEST_BOOLEAN_TRUE(r);
    }

    // add in 0 more
    {
        bool r = dg.push_event_time_s(0);

        XTESTS_TEST_BOOLEAN_TRUE(r);
    }

    // add in 1 more to overflow
    {
        bool r = dg.push_event_time_s(1);

        XTESTS_TEST_BOOLEAN_FALSE(r);
    }
}

static void TEST_doomgram_OVERFLOW_BY_MICROSECONDS()
{
    stlsoft::doomgram   dg;

    // uint64 max:
    //
    // 18,446,744,073,709,551,615 ns
    //     18,446,744,073,709,551 µs
    //         18,446,744,073,709 ms
    //             18,446,744,073  s

    // 18446744073 max

    // add in max-1 # microseconds
    {
        bool r = dg.push_event_time_us(18446744073709550);

        XTESTS_TEST_BOOLEAN_TRUE(r);
    }

    // add in 1 more to max
    {
        bool r = dg.push_event_time_us(1);

        XTESTS_TEST_BOOLEAN_TRUE(r);
    }

    // add in 0 more
    {
        bool r = dg.push_event_time_us(0);

        XTESTS_TEST_BOOLEAN_TRUE(r);
    }

    // add in 1 more to overflow
    {
        bool r = dg.push_event_time_us(1);

        XTESTS_TEST_BOOLEAN_FALSE(r);
    }
}

static void TEST_UNSIGNED_OVERFLOW()
{
    using stlsoft::ss_uint8_t;
    using stlsoft::ss_uint64_t;

    {
        ss_uint64_t  a   =   0x8000000000000000;
        ss_uint64_t  b   =   0x8000000000000001;
        ss_uint64_t  c   =   a + b;

        XTESTS_TEST_INTEGER_EQUAL(1, c);
    }

    {
        for (unsigned i = 0; i != 256; ++i)
        {
            for (unsigned j = 0; j != 256; ++j)
            {
                ss_uint8_t  a   =   static_cast<ss_uint8_t>(i);
                ss_uint8_t  b   =   static_cast<ss_uint8_t>(j);
                ss_uint8_t  c   =   a + b;

                unsigned    s   =   i + j;

                if (s > 255)
                {
                    XTESTS_TEST_INTEGER_LESS(a, c);
                    XTESTS_TEST_INTEGER_LESS(b, c);
                }
            }
        }
    }
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

