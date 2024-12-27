/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.traits.integral_printf_format_traits/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::integral_printf_format_traits`.
 *
 * Created: 20th October 2024
 * Updated: 28th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/traits/integral_printf_format_traits.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/util/string/snprintf.h>

/* Standard C++ header files */

/* Standard C header files */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_char();
    static void test_char_signed();
    static void test_char_unsigned();
    static void test_short_signed();
    static void test_short_unsigned();
    static void test_int_signed();
    static void test_int_unsigned();
    static void test_long_signed();
    static void test_long_unsigned();
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
    static void test_long_long_signed();
    static void test_long_long_unsigned();
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.traits.integral_printf_format_traits", verbosity))
    {
        XTESTS_RUN_CASE(test_char);
        XTESTS_RUN_CASE(test_char_signed);
        XTESTS_RUN_CASE(test_char_unsigned);
        XTESTS_RUN_CASE(test_short_signed);
        XTESTS_RUN_CASE(test_short_unsigned);
        XTESTS_RUN_CASE(test_int_signed);
        XTESTS_RUN_CASE(test_int_unsigned);
        XTESTS_RUN_CASE(test_long_signed);
        XTESTS_RUN_CASE(test_long_unsigned);
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
        XTESTS_RUN_CASE(test_long_long_signed);
        XTESTS_RUN_CASE(test_long_long_unsigned);
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */

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

static void test_char()
{
    typedef char                                            int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

#ifdef STLSOFT_CF_char_IS_UNSIGNED
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", ipft_t::decimal_format_a());
#else /* ? STLSOFT_CF_char_IS_UNSIGNED */
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", ipft_t::decimal_format_a());
#endif /* STLSOFT_CF_char_IS_UNSIGNED */
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", ipft_t::octal_format_a());

#ifdef STLSOFT_CF_char_IS_UNSIGNED
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", ipft_t::decimal_format_w());
#else /* ? STLSOFT_CF_char_IS_UNSIGNED */
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", ipft_t::decimal_format_w());
#endif /* STLSOFT_CF_char_IS_UNSIGNED */
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", ipft_t::octal_format_w());

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
#ifdef STLSOFT_CF_char_IS_UNSIGNED
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", ipft_t::format_a());
#else /* ? STLSOFT_CF_char_IS_UNSIGNED */
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", ipft_t::format_a());
#endif /* STLSOFT_CF_char_IS_UNSIGNED */
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hex_format_a());

#ifdef STLSOFT_CF_char_IS_UNSIGNED
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", ipft_t::format_w());
#else /* ? STLSOFT_CF_char_IS_UNSIGNED */
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", ipft_t::format_w());
#endif /* STLSOFT_CF_char_IS_UNSIGNED */
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hex_format_w());
# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>

    {
        char    buff[21];

        {
            int_t const v   =   123;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::decimal_format_a(), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", buff);
        }

        {
            int_t const v   =   123;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::hexadecimal_format_a(false), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("7b", buff);
        }

        {
            int_t const v   =   123;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::octal_format_a(), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("173", buff);
        }
    }
}

static void test_char_signed()
{
    typedef char signed                                     int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", ipft_t::octal_format_w());

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hex_format_w());
# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
}

static void test_char_unsigned()
{
    typedef char unsigned                                   int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", ipft_t::octal_format_w());

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hex_format_w());
# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
}

static void test_short_signed()
{
    typedef short signed                                    int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", ipft_t::octal_format_w());

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hex_format_w());
# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>

    {
        char    buff[21];

        {
            int_t const v   =   -12345;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::decimal_format_a(), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-12345", buff);
        }

        {
            int_t const v   =   12345;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::hexadecimal_format_a(false), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("3039", buff);
        }

        {
            int_t const v   =   12345;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::octal_format_a(), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(5, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("30071", buff);
        }
    }
}

static void test_short_unsigned()
{
    typedef short unsigned                                  int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", ipft_t::octal_format_w());

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hex_format_w());
# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
}

static void test_int_signed()
{
    typedef int signed                                      int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", ipft_t::octal_format_w());

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hex_format_w());
# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
}

static void test_int_unsigned()
{
    typedef int unsigned                                    int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", ipft_t::octal_format_w());

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", ipft_t::hex_format_w());
# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>

    {
        char    buff[21];

        {
            int_t const v   =   9090909;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::decimal_format_a(), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(7, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("9090909", buff);
        }

        {
            int_t const v   =   9090909;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::hexadecimal_format_a(true), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("8AB75D", buff);
        }

        {
            int_t const v   =   9090909;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::octal_format_a(), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(8, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("42533535", buff);
        }
    }
}

static void test_long_signed()
{
    typedef long signed                                     int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%ld", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lx", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lX", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lo", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%ld", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lx", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lX", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lo", ipft_t::octal_format_w());

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%ld", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lx", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%ld", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lx", ipft_t::hex_format_w());
# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
}

static void test_long_unsigned()
{
    typedef long unsigned                                   int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lu", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lx", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lX", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lo", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lu", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lx", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lX", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lo", ipft_t::octal_format_w());

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lu", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lx", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lu", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lx", ipft_t::hex_format_w());
# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
}
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT

static void test_long_long_signed()
{
    typedef long long signed                                int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

# if 0
# elif defined(STLSOFT_CF_64_BIT_PRINTF_USES_I64)
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64d", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64X", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64o", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64d", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64X", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64o", ipft_t::octal_format_w());

#  include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64d", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64d", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", ipft_t::hex_format_w());
#  include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
# elif defined(STLSOFT_CF_64_BIT_PRINTF_USES_LL)

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lld", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llX", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llo", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lld", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%llX", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%llo", ipft_t::octal_format_w());

#  include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lld", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%lld", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", ipft_t::hex_format_w());
#  include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
# else

#  error Further compiler discrimination is required
# endif /* printf-64 */

    {
        char    buff[21];

        {
            int_t const v   =   123456789123456789;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::decimal_format_a(), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(18, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123456789123456789", buff);
        }

        {
            int_t const v   =   123456789123456789;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::hexadecimal_format_a(true), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(15, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1B69B4BACD05F15", buff);
        }

        {
            int_t const v   =   123456789123456789;
            int const   r   =   stlsoft::snprintf(buff, STLSOFT_NUM_ELEMENTS(buff), ipft_t::octal_format_a(), v);

            XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(19, r));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("6664664565464057425", buff);
        }
    }
}

static void test_long_long_unsigned()
{
    typedef long long unsigned                              int_t;
    typedef stlsoft::integral_printf_format_traits<
        int_t
    >                                                       ipft_t;

# if 0
# elif defined(STLSOFT_CF_64_BIT_PRINTF_USES_I64)

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64u", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64X", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64o", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64u", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64X", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64o", ipft_t::octal_format_w());

#  include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64u", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64u", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", ipft_t::hex_format_w());
#  include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
# elif defined(STLSOFT_CF_64_BIT_PRINTF_USES_LL)

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llu", ipft_t::decimal_format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", ipft_t::hexadecimal_format_a(false));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llX", ipft_t::hexadecimal_format_a(true));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llo", ipft_t::octal_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%llu", ipft_t::decimal_format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", ipft_t::hexadecimal_format_w(false));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%llX", ipft_t::hexadecimal_format_w(true));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%llo", ipft_t::octal_format_w());

#  include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llu", ipft_t::format_a());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", ipft_t::hex_format_a());

    XTESTS_TEST_WIDE_STRING_EQUAL(L"%llu", ipft_t::format_w());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", ipft_t::hex_format_w());
#  include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
# else

#  error Further compiler discrimination is required
# endif /* printf-64 */
}
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

