/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.util.true_typedef/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::true_typedef`.
 *
 * Created: 27th February 2024
 * Updated: 21st March 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/util/true_typedef.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#include <stlsoft/meta/is_integral_type.hpp>

/* Standard C++ header files */
#if __cplusplus >= 201402L
# include <sstream>
#endif

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void test_int_spec();
    static void test_Integer_spec();
    static void test_double_spec();
    static void test_stdstring_spec();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.util.true_typedef", verbosity))
    {
        XTESTS_RUN_CASE(test_int_spec);
        XTESTS_RUN_CASE(test_Integer_spec);
        XTESTS_RUN_CASE(test_double_spec);
        XTESTS_RUN_CASE(test_stdstring_spec);


        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

#if __cplusplus >= 201402L

    struct SimpleStream
    {
        std::string     contents;

        SimpleStream&
        write(
            char const*     s
        ,   std::streamsize n
        )
        {
            contents.append(s, n);

            return *this;
        }

        std::string
        str() const
        {
            return contents;
        }
    };

    SimpleStream&
    operator <<(
        SimpleStream&       stm
    ,   int                 v
    )
    {
        char                buff[21];
        size_t              n;
        char const* const   s   =   stlsoft::integer_to_decimal_string(buff, STLSOFT_NUM_ELEMENTS(buff), v, &n);

        stm.write(s, n);

        return stm;
    }

# if 0

    SimpleStream&
    operator <<(
        SimpleStream&       stm
    ,   std::string const&  s
    )
    {
        stm.write(s.data(), s.size());

        return stm;
    }
# endif
#endif


static void test_int_spec()
{
    STLSOFT_GEN_OPAQUE(h_int_tt)

    typedef stlsoft::true_typedef<int, h_int_tt>            type_t;

    STLSOFT_STATIC_ASSERT(stlsoft::is_integral_type<type_t>::value);

    // v = 0
    {
        type_t          v0(0);
        type_t const    cv0(0);

        TEST_INT_EQ(0, v0);
        TEST_INT_EQ(0, cv0);

        XTESTS_TEST(v0 == v0);
        XTESTS_TEST(v0 == 0);
        XTESTS_TEST(0 == v0);
        XTESTS_TEST(!(v0 != v0));
        XTESTS_TEST(!(v0 != 0));
        XTESTS_TEST(!(0 != v0));

        type_t  v0_2(v0);

        XTESTS_TEST(v0 == v0_2);
        XTESTS_TEST(!(v0 != v0_2));

        type_t  v0_3 = v0;

        XTESTS_TEST(v0 == v0_3);
        XTESTS_TEST(!(v0 != v0_3));

#if __cplusplus >= 201402L

        type_t  v0_4{v0};

        XTESTS_TEST(v0 == v0_4);
        XTESTS_TEST(!(v0 != v0_4));
#endif
    }

    // ++
    {
        type_t  v0(0);
        type_t  v(v0);

        type_t  v_2 = ++v;

        TEST_INT_EQ(1, v);
        TEST_INT_EQ(1, v_2);
    }

    // ++(int)
    {
        type_t  v0(0);
        type_t  v(v0);

        type_t  v_2 = v++;

        TEST_INT_EQ(1, v);
        TEST_INT_EQ(0, v_2);
    }


    // --
    {
        type_t  v0(0);
        type_t  v(v0);

        type_t  v_2 = --v;

        TEST_INT_EQ(-1, v);
        TEST_INT_EQ(-1, v_2);
    }

    // --(int)
    {
        type_t  v0(0);
        type_t  v(v0);

        type_t  v_2 = v--;

        TEST_INT_EQ(-1, v);
        TEST_INT_EQ(0, v_2);
    }


    // <, <=, >, >=
    {
        type_t  v1(1);
        type_t  v2(2);

        XTESTS_TEST(1 < v2);
        XTESTS_TEST(v1 < v2);
        XTESTS_TEST(v1 < 2);

        XTESTS_TEST(v1 <= 1);
        XTESTS_TEST(v1 <= v1);
        XTESTS_TEST(1 <= v2);
        XTESTS_TEST(v1 <= v2);

        XTESTS_TEST(2 > v1);
        XTESTS_TEST(v2 > 1);
        XTESTS_TEST(v2 > v1);

        XTESTS_TEST(v2 >= v2);
        XTESTS_TEST(v2 >= v1);
    }


    // +
    {
        type_t  v1(1);
        type_t  v2(2);
        type_t  v3 = v1 + v2;
        type_t  v4 = 2 + v2;
        type_t  v5 = v1 + 4;

        XTESTS_TEST(1 == v1);
        XTESTS_TEST(2 == v2);
        XTESTS_TEST(3 == v3);
        XTESTS_TEST(4 == v4);
        XTESTS_TEST(5 == v5);
    }

    // +=
    {
        type_t  v(1);

        XTESTS_TEST(1 == v);

        v += v;

        XTESTS_TEST(2 == v);

        v += -3;

        XTESTS_TEST(-1 == v);
    }


    // -
    {
        type_t  v1(1);
        type_t  v2(2);
        type_t  v3 = v2 - v1 + 2;
        type_t  v4 = 5 - v1;
        type_t  v5 = v1 - -4;

        XTESTS_TEST(1 == v1);
        XTESTS_TEST(2 == v2);
        XTESTS_TEST(3 == v3);
        XTESTS_TEST(4 == v4);
        XTESTS_TEST(5 == v5);
    }

    // -=
    {
        type_t  v(1);
        type_t  v2(2);

        XTESTS_TEST(1 == v);

        v -= v2;

        XTESTS_TEST(-1 == v);

        v -= -3;

        XTESTS_TEST(2 == v);
    }


    // *
    {
        type_t  v1(1);
        type_t  v2(2);
        type_t  v3 = 3 * v1;
        type_t  v4 = v2 * v2;
        type_t  v5 = v1 * 5;

        XTESTS_TEST(1 == v1);
        XTESTS_TEST(2 == v2);
        XTESTS_TEST(3 == v3);
        XTESTS_TEST(4 == v4);
        XTESTS_TEST(5 == v5);
    }

    // *=
    {
        type_t  v(1);

        XTESTS_TEST(1 == v);

        v *= 2;

        XTESTS_TEST(2 == v);

        v *= v;

        XTESTS_TEST(4 == v);
    }


    // /
    {
        type_t  v1(1);
        type_t  v2(2);
        type_t  v3 = v1 / v1 + 2;
        type_t  v4 = 8 / v2;
        type_t  v5 = v4 /1 + 1;

        XTESTS_TEST(1 == v1);
        XTESTS_TEST(2 == v2);
        XTESTS_TEST(3 == v3);
        XTESTS_TEST(4 == v4);
        XTESTS_TEST(5 == v5);
    }

    // /=
    {
        type_t  v(12);
        type_t  v2(2);

        XTESTS_TEST(12 == v);

        v /= v2;

        XTESTS_TEST(6 == v);

        v /= 3;

        XTESTS_TEST(2 == v);
    }


    // %
    {
        type_t  v1(1);
        type_t  v2(2);
        type_t  v3 = v1 % v1 + 3;
        type_t  v4 = 5 % v3 * 2;
        type_t  v5 = (v4 % 3) + 4;

        XTESTS_TEST(1 == v1);
        XTESTS_TEST(2 == v2);
        XTESTS_TEST(3 == v3);
        XTESTS_TEST(4 == v4);
        XTESTS_TEST(5 == v5);
    }

    // %=
    {
        type_t  v(15);
        type_t  v4(4);

        XTESTS_TEST(15 == v);

        v %= 8;

        XTESTS_TEST(7 == v);

        v %= v4;

        XTESTS_TEST(3 == v);
    }


    // ^
    {
        type_t  v1(0x1);
        type_t  v2(0x2);
        type_t  v3 = v2 ^ v1;
        type_t  v4 = 6 ^ v2;
        type_t  v5 = v2 ^ 7;

        XTESTS_TEST(1 == v1);
        XTESTS_TEST(2 == v2);
        XTESTS_TEST(3 == v3);
        XTESTS_TEST(4 == v4);
        XTESTS_TEST(5 == v5);
    }

    // ^=
    {
        type_t  v(15);
        type_t  v2(2);

        XTESTS_TEST(15 == v);

        v ^= 8;

        XTESTS_TEST(7 == v);

        v ^= v2;

        XTESTS_TEST(5 == v);
    }


    // ~
    {
        type_t  v1(0x1);
        type_t  v2(0x2);

        XTESTS_TEST(~1 == ~v1);
        XTESTS_TEST(~2 == ~v2);
    }

    // ~=
    {
    }


    // >>
    {
        type_t  v0(0x0);
        type_t  v1(0x1);
        type_t  v2 = 0x4 >> v1;
        type_t  v3 = v2 >> v0 | v1 >> v0;
        type_t  v4 = 4 >> v0;
        type_t  v5 = short(5) >> v0;

        XTESTS_TEST(0 == v0);
        XTESTS_TEST(1 == v1);
        XTESTS_TEST(2 == v2);
        XTESTS_TEST(3 == v3);
        XTESTS_TEST(4 == v4);
        XTESTS_TEST(5 == v5);
    }

    // >>=
    {
        type_t  v(0x0f0f);
        type_t  v8(8);

        XTESTS_TEST(3855 == v);

        v >>= v8;

        XTESTS_TEST(15 == v);

        v >>= 1;

        XTESTS_TEST(7 == v);
    }


    // <<
    {
        type_t const    v0(0x0);
        type_t          v1(0x1);
        type_t const    v2 = (v1 << 1) | (v0 << 0);
        type_t          v3 = (0x1 << v0) | (0x1 << v1);
        type_t          v4 = (v1 << v2) | (v0 << v1);
        type_t          v5 = short(5) << v0;

        XTESTS_TEST(1 == v1);
        XTESTS_TEST(2 == v2);
        XTESTS_TEST(3 == v3);
        XTESTS_TEST(4 == v4);
        XTESTS_TEST(5 == v5);
    }

    // <<=
    {
        type_t  v(0x0f0f);
        type_t  v4(4);

        XTESTS_TEST(3855 == v);

        v <<= v4;

        XTESTS_TEST(61680 == v);

        v <<= 0;

        XTESTS_TEST(61680 == v);
    }

#if __cplusplus >= 201402L

    // << (as insertion operator)
    {
        {
            std::stringstream stm;

            type_t const v(1);

            stm << v;

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1", stm.str());
        }

        {
            std::stringstream stm;

            type_t v(12345678);

            stm << v;

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("12345678", stm.str());
        }
        {
            SimpleStream stm;

            type_t const v(1);

            stm << v;

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1", stm.str());
        }

        {
            SimpleStream stm;

            type_t v(12345678);

            stm << v;

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("12345678", stm.str());
        }
    }
#endif


    // &
    {
        type_t  v0(0x0);
        type_t  v1(0x1);
        type_t  v2 = ~v1 & 0x3;
        type_t  v3 = (v2 | v1) & ~v0;
        type_t  v4 = 6 & ~v2;

        XTESTS_TEST(1 == v1);
        XTESTS_TEST(2 == v2);
        XTESTS_TEST(3 == v3);
        XTESTS_TEST(4 == v4);
    }

    // &=
    {
        type_t  v(0x0f0f);
        type_t  v37(37);

        XTESTS_TEST(3855 == v);

        v &= v37;

        XTESTS_TEST(5 == v);

        v &= 7;

        XTESTS_TEST(5 == v);
    }


    // |
    {
        type_t  v0(0);
        type_t  v1(1);
        type_t  v2(2);
        type_t  v3 = v1 | v2;
        type_t  v4 = v0 | 4;
        type_t  v5 = 1 | v4;

        XTESTS_TEST(0 == v0);
        XTESTS_TEST(1 == v1);
        XTESTS_TEST(2 == v2);
        XTESTS_TEST(3 == v3);
        XTESTS_TEST(4 == v4);
        XTESTS_TEST(5 == v5);
    }

    // |=
    {
        type_t  v(0x0f0f);
        type_t  v37(37);

        XTESTS_TEST(3855 == v);

        v |= v37;

        XTESTS_TEST(3887 == v);

        v |= 0xf080;

        XTESTS_TEST(65455 == v);
    }
}

static void test_Integer_spec()
{

}

static void test_double_spec()
{
    STLSOFT_GEN_OPAQUE(h_double_tt)

    typedef stlsoft::true_typedef<double, h_double_tt>      type_t;

    STLSOFT_STATIC_ASSERT(!stlsoft::is_integral_type<type_t>::value);
}

static void test_stdstring_spec()
{
    STLSOFT_GEN_OPAQUE(h_string_tt)

    typedef stlsoft::true_typedef<std::string, h_string_tt> type_t;

    STLSOFT_STATIC_ASSERT(!stlsoft::is_integral_type<type_t>::value);
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

