/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.conversion.try_parse_to/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::try_parse_to`.
 *
 * Created: 18th November 2008
 * Updated: 15th August 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */

#define STLSOFT_MINIMUM_SAS_INCLUDES


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/conversion/string_to_integer.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
// #include <limits>

/* Standard C header files */
// #include <ctype.h>
#include <stdint.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifdef STLSOFT_COMPILER_IS_BORLAND
# undef NULL
# define NULL   0
#endif


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_specialisations_1(void);
    static void test_specialisations_2(void);
    static void test_0(void);
    static void test_positives_implicit(void);
    static void test_positives_explicit(void);
    static void test_negatives(void);
    static void test_bad(void);
    static void test_spaces(void);
    static void test_len_spaces(void);
    static void test_trailing(void);
    static void test_len_trailing(void);
    static void test_len_truncated(void);
    static void test_increasing_length(void);
    static void test_1_10(void);
    static void test_decimal_leading_plus(void);
    static void test_1_12(void);
    static void test_endptr(void);
    static void test_1_14(void);
    static void test_hexadecimal_1(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);

    static void test_try_1_int(void);
    static void test_try_2_int(void);
    static void test_try_3_int(void);
    static void test_try_4_int(void);
    static void test_try_5_int(void);
    static void test_try_6_int(void);
    static void test_try_7_int(void);
    static void test_try_8_int(void);
    static void test_try_9_int(void);
    static void test_try_10_int(void);
    static void test_try_11_int(void);
    static void test_try_12_int(void);

    static void test_try_1_uint64(void);
    static void test_try_2_uint64(void);
    static void test_try_3_uint64(void);
    static void test_try_4_uint64(void);
    static void test_try_5_uint64(void);
    static void test_try_6_uint64(void);
    static void test_try_7_uint64(void);
    static void test_try_8_uint64(void);
    static void test_try_9_uint64(void);
    static void test_try_10_uint64(void);

    static void test_try_hex_1_int(void);
    static void test_try_hex_2_int(void);
    static void test_try_hex_3_int(void);
    static void test_try_hex_4_int(void);
    static void test_try_hex_5_int(void);
    static void test_try_hex_6_int(void);
    static void test_try_hex_7_int(void);
    static void test_try_hex_8_int(void);
    static void test_try_hex_9_int(void);
    static void test_try_hex_10_int(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.conversion.try_parse_to", verbosity))
    {
        XTESTS_RUN_CASE(test_try_1_int);
        XTESTS_RUN_CASE(test_try_2_int);
        XTESTS_RUN_CASE(test_try_3_int);
        XTESTS_RUN_CASE(test_try_4_int);
        XTESTS_RUN_CASE(test_try_5_int);
        XTESTS_RUN_CASE(test_try_6_int);
        XTESTS_RUN_CASE(test_try_7_int);
        XTESTS_RUN_CASE(test_try_8_int);
        XTESTS_RUN_CASE(test_try_9_int);
        XTESTS_RUN_CASE(test_try_10_int);
        XTESTS_RUN_CASE(test_try_11_int);
        XTESTS_RUN_CASE(test_try_12_int);

        XTESTS_RUN_CASE(test_try_1_uint64);
        XTESTS_RUN_CASE(test_try_2_uint64);
        XTESTS_RUN_CASE(test_try_3_uint64);
        XTESTS_RUN_CASE(test_try_4_uint64);
        XTESTS_RUN_CASE(test_try_5_uint64);
        XTESTS_RUN_CASE(test_try_6_uint64);
        XTESTS_RUN_CASE(test_try_7_uint64);
        XTESTS_RUN_CASE(test_try_8_uint64);
        XTESTS_RUN_CASE(test_try_9_uint64);
        XTESTS_RUN_CASE(test_try_10_uint64);

        XTESTS_RUN_CASE(test_try_hex_1_int);
        XTESTS_RUN_CASE(test_try_hex_2_int);
        XTESTS_RUN_CASE(test_try_hex_3_int);
        XTESTS_RUN_CASE(test_try_hex_4_int);
        XTESTS_RUN_CASE(test_try_hex_5_int);
        XTESTS_RUN_CASE(test_try_hex_6_int);
        XTESTS_RUN_CASE(test_try_hex_7_int);
        XTESTS_RUN_CASE(test_try_hex_8_int);
        XTESTS_RUN_CASE(test_try_hex_9_int);
        XTESTS_RUN_CASE(test_try_hex_10_int);

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
    using stlsoft::sint64_t;
    using stlsoft::uint64_t;


static void test_try_1_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10", &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_2_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<int>("10a", &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_3_int()
{
    int         i;
    bool const  b = stlsoft::try_parse_to<int>("10", 2u, &i);

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(b));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_4_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10a", 2u, &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_5_int()
{
    int i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10", 2u, "", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_6_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<int>("10a", 3, "", &i, static_cast<char const**>(NULL))));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_7_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10", 2u, "", &i, static_cast<char const**>(NULL))));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_8_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10a", 2u, "", &i, static_cast<char const**>(NULL))));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_9_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10a", 3, "a", &i, static_cast<char const**>(NULL))));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_10_int()
{
    int i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<int>("10a", 3, "endptr", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_11_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("-10", &i, "endptr")));
    XTESTS_TEST_INTEGER_EQUAL(-10, i);

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("+10", &i, "endptr")));
    XTESTS_TEST_INTEGER_EQUAL(+10, i);

    i = INT_MAX;
    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<int>("+-10", &i, "endptr")));
    XTESTS_TEST_INTEGER_EQUAL(INT_MAX, i);

    i = INT_MIN;
    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<int>("-+10", &i, "endptr")));
    XTESTS_TEST_INTEGER_EQUAL(INT_MIN, i);
}

static void test_try_12_int()
{
    int         i;
    char const* endptr = NULL;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("1", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(1, i);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", endptr);

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<int>("  1  ", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(1, i);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("  ", endptr);

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("+1", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(1, i);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", endptr);

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("-1", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(-1, i);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", endptr);

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("0x0001", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(1, i);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", endptr);
}


static void test_try_1_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10", &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_2_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<uint64_t>("10a", &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_3_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10", 2, &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_4_uint64()
{
    uint64_t i;
    bool const  b   =   stlsoft::try_parse_to<uint64_t>("10a", 2, &i);

    REQUIRE(TEST_BOOLEAN_TRUE(b))
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_5_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10", 2u, "", &i, static_cast<char const**>(NULL))));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_6_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<uint64_t>("10a", 3, "", &i, static_cast<char const**>(NULL))));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_7_uint64()
{
    uint64_t i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10", 2u, "", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_8_uint64()
{
    uint64_t i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<uint64_t>("10a", 3, "", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_CHARACTER_EQUAL('a', *endptr);
}

static void test_try_9_uint64()
{
    uint64_t i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10a", 3, "a", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_10_uint64()
{
    uint64_t i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<uint64_t>("10a", 3, "endptr", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}



static void test_try_hex_1_int()
{
    uint64_t i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("0", 1, "", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(0u, i);
}

static void test_try_hex_2_int()
{
    uint64_t i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("0x0", 3, "", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(0u, i);
}

static void test_try_hex_3_int()
{
    uint64_t i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("+0x0", 4, "", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(0u, i);
}

static void test_try_hex_4_int()
{
    sint64_t i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<sint64_t>("-0x0", 4, "", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(0, i);
}

static void test_try_hex_5_int()
{
    uint64_t i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("0x10", 4, "", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(16u, i);
}

static void test_try_hex_6_int()
{
    sint64_t i;
    char const* endptr;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<sint64_t>("-0x0a", 5, "", &i, &endptr)));
    XTESTS_TEST_INTEGER_EQUAL(-10, i);
}

static void test_try_hex_7_int()
{
}

static void test_try_hex_8_int()
{
}

static void test_try_hex_9_int()
{
}

static void test_try_hex_10_int()
{
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

#if 0

SCENARIO("testing stlsoft/conversion/string_to_integer.hpp - try_parse_to()", "[API]") {

    SECTION("3-parameter form(T_character const*, T_integer*, T_character const**)") {

#if 0 // these are now removed, to disambiguate the overloads()

        int i;
        long l;
        int8_t i8;
        uint8_t u8;
        int16_t i16;
        uint16_t u16;
        int32_t i32;
        uint32_t u32;
        int64_t i64;
        uint64_t u64;

        char const css_m[] = "1234";
        wchar_t const css_w[] = L"5678";

        char const** endptr_m;
        wchar_t const** endptr_w;

        stlsoft::c_str_data("123");

        REQUIRE(stlsoft::try_parse_to("123", &i, &endptr_m));
        CHECK(123 == i);

        REQUIRE(stlsoft::try_parse_to("123", &l, &endptr_m));
        CHECK(123 == l);

        REQUIRE(stlsoft::try_parse_to("123", &i8, &endptr_m));
        CHECK(123 == i8);

        REQUIRE(stlsoft::try_parse_to("123", &u8, &endptr_m));
        CHECK(123 == u8);

        REQUIRE(stlsoft::try_parse_to("123", &i16, &endptr_m));
        CHECK(123 == i16);

        REQUIRE(stlsoft::try_parse_to("123", &u16, &endptr_m));
        CHECK(123 == u16);

        REQUIRE(stlsoft::try_parse_to("123", &i32, &endptr_m));
        CHECK(123 == i32);

        REQUIRE(stlsoft::try_parse_to("123", &u32, &endptr_m));
        CHECK(123 == u32);

        REQUIRE(stlsoft::try_parse_to("123", &i64, &endptr_m));
        CHECK(123 == i64);

        REQUIRE(stlsoft::try_parse_to("123", &u64, &endptr_m));
        CHECK(123 == u64);


        REQUIRE(stlsoft::try_parse_to(L"123", &i, &endptr_w));
        CHECK(123 == i);

        REQUIRE(stlsoft::try_parse_to(L"123", &l, &endptr_w));
        CHECK(123 == l);

        REQUIRE(stlsoft::try_parse_to(L"123", &i8, &endptr_w));
        CHECK(123 == i8);

        REQUIRE(stlsoft::try_parse_to(L"123", &u8, &endptr_w));
        CHECK(123 == u8);

        REQUIRE(stlsoft::try_parse_to(L"123", &i16, &endptr_w));
        CHECK(123 == i16);

        REQUIRE(stlsoft::try_parse_to(L"123", &u16, &endptr_w));
        CHECK(123 == u16);

        REQUIRE(stlsoft::try_parse_to(L"123", &i32, &endptr_w));
        CHECK(123 == i32);

        REQUIRE(stlsoft::try_parse_to(L"123", &u32, &endptr_w));
        CHECK(123 == u32);

        REQUIRE(stlsoft::try_parse_to(L"123", &i64, &endptr_w));
        CHECK(123 == i64);

        REQUIRE(stlsoft::try_parse_to(L"123", &u64, &endptr_w));
        CHECK(123 == u64);
#endif
    }

    SECTION("2-parameter form") {

        int i;
        long l;
        int8_t i8;
        uint8_t u8;
        int16_t i16;
        uint16_t u16;
        int32_t i32;
        uint32_t u32;
        int64_t i64;
        uint64_t u64;

        char const css_m[] = "1234";
        wchar_t const css_w[] = L"5678";

        std::string const ss_m("12345");
        std::wstring const ss_w(L"23456");


        REQUIRE(stlsoft::try_parse_to("123", &i));
        CHECK(123 == i);

        REQUIRE(stlsoft::try_parse_to("123", &l));
        CHECK(123 == l);

        REQUIRE(stlsoft::try_parse_to("123", &i8));
        CHECK(123 == i8);

        REQUIRE(stlsoft::try_parse_to("123", &u8));
        CHECK(123 == u8);

        REQUIRE(stlsoft::try_parse_to("123", &i16));
        CHECK(123 == i16);

        REQUIRE(stlsoft::try_parse_to("123", &u16));
        CHECK(123 == u16);

        REQUIRE(stlsoft::try_parse_to("123", &i32));
        CHECK(123 == i32);

        REQUIRE(stlsoft::try_parse_to("123", &u32));
        CHECK(123 == u32);

        REQUIRE(stlsoft::try_parse_to("123", &i64));
        CHECK(123 == i64);

        REQUIRE(stlsoft::try_parse_to("123", &u64));
        CHECK(123 == u64);


        REQUIRE(stlsoft::try_parse_to(L"123", &i));
        CHECK(123 == i);

        REQUIRE(stlsoft::try_parse_to(L"123", &l));
        CHECK(123 == l);

        REQUIRE(stlsoft::try_parse_to(L"123", &i8));
        CHECK(123 == i8);

        REQUIRE(stlsoft::try_parse_to(L"123", &u8));
        CHECK(123 == u8);

        REQUIRE(stlsoft::try_parse_to(L"123", &i16));
        CHECK(123 == i16);

        REQUIRE(stlsoft::try_parse_to(L"123", &u16));
        CHECK(123 == u16);

        REQUIRE(stlsoft::try_parse_to(L"123", &i32));
        CHECK(123 == i32);

        REQUIRE(stlsoft::try_parse_to(L"123", &u32));
        CHECK(123 == u32);

        REQUIRE(stlsoft::try_parse_to(L"123", &i64));
        CHECK(123 == i64);

        REQUIRE(stlsoft::try_parse_to(L"123", &u64));
        CHECK(123 == u64);


        REQUIRE(stlsoft::try_parse_to(css_m, &i));
        CHECK(1234 == i);

        REQUIRE(stlsoft::try_parse_to(css_m, &l));
        CHECK(1234 == l);

        REQUIRE(stlsoft::try_parse_to("123", &i8));
        CHECK(123 == i8);

        REQUIRE(stlsoft::try_parse_to("234", &u8));
        CHECK(234 == u8);

        REQUIRE(stlsoft::try_parse_to(css_m, &i16));
        CHECK(1234 == i16);

        REQUIRE(stlsoft::try_parse_to(css_m, &u16));
        CHECK(1234 == u16);

        REQUIRE(stlsoft::try_parse_to(css_m, &i32));
        CHECK(1234 == i32);

        REQUIRE(stlsoft::try_parse_to(css_m, &u32));
        CHECK(1234 == u32);

        REQUIRE(stlsoft::try_parse_to(css_m, &i64));
        CHECK(1234 == i64);

        REQUIRE(stlsoft::try_parse_to(css_m, &u64));
        CHECK(1234 == u64);


        REQUIRE(stlsoft::try_parse_to(css_w, &i));
        CHECK(5678 == i);

        REQUIRE(stlsoft::try_parse_to(css_w, &l));
        CHECK(5678 == l);

        REQUIRE(stlsoft::try_parse_to(L"56", &i8));
        CHECK(56 == i8);

        REQUIRE(stlsoft::try_parse_to(L"78", &u8));
        CHECK(78 == u8);

        REQUIRE(stlsoft::try_parse_to(css_w, &i16));
        CHECK(5678 == i16);

        REQUIRE(stlsoft::try_parse_to(css_w, &u16));
        CHECK(5678 == u16);

        REQUIRE(stlsoft::try_parse_to(css_w, &i32));
        CHECK(5678 == i32);

        REQUIRE(stlsoft::try_parse_to(css_w, &u32));
        CHECK(5678 == u32);

        REQUIRE(stlsoft::try_parse_to(css_w, &i64));
        CHECK(5678 == i64);

        REQUIRE(stlsoft::try_parse_to(css_w, &u64));
        CHECK(5678 == u64);


        REQUIRE(stlsoft::try_parse_to(ss_m, &i));
        CHECK(12345 == i);

        REQUIRE(stlsoft::try_parse_to(ss_m, &l));
        CHECK(12345 == l);

        REQUIRE(stlsoft::try_parse_to(std::string("12"), &i8));
        CHECK(12 == i8);

        REQUIRE(stlsoft::try_parse_to(std::string("230"), &u8));
        CHECK(230 == u8);

        REQUIRE(stlsoft::try_parse_to(ss_m, &i16));
        CHECK(12345 == i16);

        REQUIRE(stlsoft::try_parse_to(ss_m, &u16));
        CHECK(12345 == u16);

        REQUIRE(stlsoft::try_parse_to(ss_m, &i32));
        CHECK(12345 == i32);

        REQUIRE(stlsoft::try_parse_to(ss_m, &u32));
        CHECK(12345 == u32);

        REQUIRE(stlsoft::try_parse_to(ss_m, &i64));
        CHECK(12345 == i64);

        REQUIRE(stlsoft::try_parse_to(ss_m, &u64));
        CHECK(12345 == u64);


        REQUIRE(stlsoft::try_parse_to(ss_w, &i));
        CHECK(23456 == i);

        REQUIRE(stlsoft::try_parse_to(ss_w, &l));
        CHECK(23456 == l);

        REQUIRE(stlsoft::try_parse_to(std::wstring(L"45"), &i8));
        CHECK(45 == i8);

        REQUIRE(stlsoft::try_parse_to(std::wstring(L"34"), &u8));
        CHECK(34 == u8);

        REQUIRE(stlsoft::try_parse_to(ss_w, &i16));
        CHECK(23456 == i16);

        REQUIRE(stlsoft::try_parse_to(ss_w, &u16));
        CHECK(23456 == u16);

        REQUIRE(stlsoft::try_parse_to(ss_w, &i32));
        CHECK(23456 == i32);

        REQUIRE(stlsoft::try_parse_to(ss_w, &u32));
        CHECK(23456 == u32);

        REQUIRE(stlsoft::try_parse_to(ss_w, &i64));
        CHECK(23456 == i64);

        REQUIRE(stlsoft::try_parse_to(ss_w, &u64));
        CHECK(23456 == u64);
    }

    SECTION("3-parameter form(T_string const&, size_t, T_integer*)") {

        int i;
        long l;
        int8_t i8;
        uint8_t u8;
        int16_t i16;
        uint16_t u16;
        int32_t i32;
        uint32_t u32;
        int64_t i64;
        uint64_t u64;

        char const css_m[] = "1234";
        wchar_t const css_w[] = L"5678";

        std::string const ss_m("12345");
        std::wstring const ss_w(L"23456");


        REQUIRE(stlsoft::try_parse_to("123", 3, &i));
        CHECK(123 == i);

        REQUIRE(stlsoft::try_parse_to("123", 3, &l));
        CHECK(123 == l);

        REQUIRE(stlsoft::try_parse_to("123", 3, &i8));
        CHECK(123 == i8);

        REQUIRE(stlsoft::try_parse_to("123", 3, &u8));
        CHECK(123 == u8);

        REQUIRE(stlsoft::try_parse_to("123", 3, &i16));
        CHECK(123 == i16);

        REQUIRE(stlsoft::try_parse_to("123", 3, &u16));
        CHECK(123 == u16);

        REQUIRE(stlsoft::try_parse_to("123", 3, &i32));
        CHECK(123 == i32);

        REQUIRE(stlsoft::try_parse_to("123", 3, &u32));
        CHECK(123 == u32);

        REQUIRE(stlsoft::try_parse_to("123", 3, &i64));
        CHECK(123 == i64);

        REQUIRE(stlsoft::try_parse_to("123", 3, &u64));
        CHECK(123 == u64);


        REQUIRE(stlsoft::try_parse_to(L"123", 3, &i));
        CHECK(123 == i);

        REQUIRE(stlsoft::try_parse_to(L"123", 3, &l));
        CHECK(123 == l);

        REQUIRE(stlsoft::try_parse_to(L"123", 3, &i8));
        CHECK(123 == i8);

        REQUIRE(stlsoft::try_parse_to(L"123", 3, &u8));
        CHECK(123 == u8);

        REQUIRE(stlsoft::try_parse_to(L"123", 3, &i16));
        CHECK(123 == i16);

        REQUIRE(stlsoft::try_parse_to(L"123", 3, &u16));
        CHECK(123 == u16);

        REQUIRE(stlsoft::try_parse_to(L"123", 3, &i32));
        CHECK(123 == i32);

        REQUIRE(stlsoft::try_parse_to(L"123", 3, &u32));
        CHECK(123 == u32);

        REQUIRE(stlsoft::try_parse_to(L"123", 3, &i64));
        CHECK(123 == i64);

        REQUIRE(stlsoft::try_parse_to(L"123", 3, &u64));
        CHECK(123 == u64);


        REQUIRE(stlsoft::try_parse_to(css_m, STLSOFT_NUM_ELEMENTS(css_m) - 1, &i));
        CHECK(1234 == i);

        REQUIRE(stlsoft::try_parse_to(css_m, STLSOFT_NUM_ELEMENTS(css_m) - 1, &l));
        CHECK(1234 == l);

#if 0

        REQUIRE(stlsoft::try_parse_to(css_m, STLSOFT_NUM_ELEMENTS(css_m) - 1, &i8));
        CHECK(1234 == i8);

        REQUIRE(stlsoft::try_parse_to(css_m, STLSOFT_NUM_ELEMENTS(css_m) - 1, &u8));
        CHECK(1234 == u8);
#endif

        REQUIRE(stlsoft::try_parse_to(css_m, STLSOFT_NUM_ELEMENTS(css_m) - 1, &i16));
        CHECK(1234 == i16);

        REQUIRE(stlsoft::try_parse_to(css_m, STLSOFT_NUM_ELEMENTS(css_m) - 1, &u16));
        CHECK(1234 == u16);

        REQUIRE(stlsoft::try_parse_to(css_m, STLSOFT_NUM_ELEMENTS(css_m) - 1, &i32));
        CHECK(1234 == i32);

        REQUIRE(stlsoft::try_parse_to(css_m, STLSOFT_NUM_ELEMENTS(css_m) - 1, &u32));
        CHECK(1234 == u32);

        REQUIRE(stlsoft::try_parse_to(css_m, STLSOFT_NUM_ELEMENTS(css_m) - 1, &i64));
        CHECK(1234 == i64);

        REQUIRE(stlsoft::try_parse_to(css_m, STLSOFT_NUM_ELEMENTS(css_m) - 1, &u64));
        CHECK(1234 == u64);


        REQUIRE(stlsoft::try_parse_to(css_w, STLSOFT_NUM_ELEMENTS(css_w) - 1, &i));
        CHECK(5678 == i);

        REQUIRE(stlsoft::try_parse_to(css_w, STLSOFT_NUM_ELEMENTS(css_w) - 1, &l));
        CHECK(5678 == l);

#if 0

        REQUIRE(stlsoft::try_parse_to(css_w, STLSOFT_NUM_ELEMENTS(css_w) - 1, &i8));
        CHECK(5678 == i8);

        REQUIRE(stlsoft::try_parse_to(css_w, STLSOFT_NUM_ELEMENTS(css_w) - 1, &u8));
        CHECK(5678 == u8);
#endif

        REQUIRE(stlsoft::try_parse_to(css_w, STLSOFT_NUM_ELEMENTS(css_w) - 1, &i16));
        CHECK(5678 == i16);

        REQUIRE(stlsoft::try_parse_to(css_w, STLSOFT_NUM_ELEMENTS(css_w) - 1, &u16));
        CHECK(5678 == u16);

        REQUIRE(stlsoft::try_parse_to(css_w, STLSOFT_NUM_ELEMENTS(css_w) - 1, &i32));
        CHECK(5678 == i32);

        REQUIRE(stlsoft::try_parse_to(css_w, STLSOFT_NUM_ELEMENTS(css_w) - 1, &u32));
        CHECK(5678 == u32);

        REQUIRE(stlsoft::try_parse_to(css_w, STLSOFT_NUM_ELEMENTS(css_w) - 1, &i64));
        CHECK(5678 == i64);

        REQUIRE(stlsoft::try_parse_to(css_w, STLSOFT_NUM_ELEMENTS(css_w) - 1, &u64));
        CHECK(5678 == u64);


        REQUIRE(stlsoft::try_parse_to(ss_m, &i));
        CHECK(12345 == i);

        REQUIRE(stlsoft::try_parse_to(ss_m, &l));
        CHECK(12345 == l);

#if 0

        REQUIRE(stlsoft::try_parse_to(ss_m, &i8));
        CHECK(12345 == i8);

        REQUIRE(stlsoft::try_parse_to(ss_m, &u8));
        CHECK(12345 == u8);
#endif

        REQUIRE(stlsoft::try_parse_to(ss_m, &i16));
        CHECK(12345 == i16);

        REQUIRE(stlsoft::try_parse_to(ss_m, &u16));
        CHECK(12345 == u16);

        REQUIRE(stlsoft::try_parse_to(ss_m, &i32));
        CHECK(12345 == i32);

        REQUIRE(stlsoft::try_parse_to(ss_m, &u32));
        CHECK(12345 == u32);

        REQUIRE(stlsoft::try_parse_to(ss_m, &i64));
        CHECK(12345 == i64);

        REQUIRE(stlsoft::try_parse_to(ss_m, &u64));
        CHECK(12345 == u64);


        REQUIRE(stlsoft::try_parse_to(ss_w, &i));
        CHECK(23456 == i);

        REQUIRE(stlsoft::try_parse_to(ss_w, &l));
        CHECK(23456 == l);

#if 0

        REQUIRE(stlsoft::try_parse_to(ss_w, &i8));
        CHECK(23456 == i8);

        REQUIRE(stlsoft::try_parse_to(ss_w, &u8));
        CHECK(23456 == u8);
#endif

        REQUIRE(stlsoft::try_parse_to(ss_w, &i16));
        CHECK(23456 == i16);

        REQUIRE(stlsoft::try_parse_to(ss_w, &u16));
        CHECK(23456 == u16);

        REQUIRE(stlsoft::try_parse_to(ss_w, &i32));
        CHECK(23456 == i32);

        REQUIRE(stlsoft::try_parse_to(ss_w, &u32));
        CHECK(23456 == u32);

        REQUIRE(stlsoft::try_parse_to(ss_w, &i64));
        CHECK(23456 == i64);

        REQUIRE(stlsoft::try_parse_to(ss_w, &u64));
        CHECK(23456 == u64);
    }
}
#endif


/* ///////////////////////////// end of file //////////////////////////// */

