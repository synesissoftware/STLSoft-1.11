/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.smartptr.shared_ptr/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::shared_ptr`.
 *
 * Created: 7th October 2024
 * Updated: 20th March 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/smartptr/shared_ptr.hpp>


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

namespace {

    static void test_types_exist();

    static void test_ctor_default();
    static void test_ctor_nullptr();
    static void test_ctor_conversion();
    static void test_ctor_copy();
#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

    static void test_ctor_move();
#endif
    static void test_swap();
    static void test_std_swap();
    static void test_1_1();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.smartptr.shared_ptr", verbosity))
    {
        XTESTS_RUN_CASE(test_types_exist);

        XTESTS_RUN_CASE(test_ctor_default);
        XTESTS_RUN_CASE(test_ctor_nullptr);
        XTESTS_RUN_CASE(test_ctor_conversion);
        XTESTS_RUN_CASE(test_ctor_copy);
#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

        XTESTS_RUN_CASE(test_ctor_move);
#endif
        XTESTS_RUN_CASE(test_swap);
        XTESTS_RUN_CASE(test_std_swap);
        XTESTS_RUN_CASE(test_1_1);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

    struct CountHolder
    {
    public: // construction
        CountHolder(int& i)
            : m_i(i)
        {
            ++m_i;
        }
        ~CountHolder() STLSOFT_NOEXCEPT
        {
            --m_i;
        }
    private:
        void operator =(CountHolder const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

    public: // accessors
        int i() const STLSOFT_NOEXCEPT
        {
            return m_i;
        }

    public: // fields
        int& m_i;
    };
} // anonymous namespace

namespace {

static void test_types_exist()
{
    STLSOFT_SUPPRESS_UNUSED(typeid(stlsoft::shared_ptr<char*>));
#if 0

    STLSOFT_SUPPRESS_UNUSED(typeid(stlsoft::shared_ptr<void>));
#endif

    XTESTS_TEST_PASSED();
}

static void test_ctor_default()
{
    {
        stlsoft::shared_ptr<int> ptr;

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());
    }

    {
        stlsoft::shared_ptr<std::string> ptr;

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());
    }

    {
        stlsoft::shared_ptr<CountHolder> ptr;

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());
    }
}

static void test_ctor_nullptr()
{
    {
        stlsoft::shared_ptr<int> ptr(ss_nullptr_k);

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());
    }

    {
        stlsoft::shared_ptr<std::string> ptr(ss_nullptr_k);

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());
    }

    {
        stlsoft::shared_ptr<CountHolder> ptr(ss_nullptr_k);

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());
    }
}

static void test_ctor_conversion()
{
    {
        stlsoft::shared_ptr<int> ptr(new int(123));

        XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(123, *ptr);
    }

    {
        stlsoft::shared_ptr<std::string> ptr(new std::string("123"));

        XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", *ptr);
        XTESTS_TEST_INTEGER_EQUAL(3u, ptr->size());
    }

    {
        int i = 123;

        {
            stlsoft::shared_ptr<CountHolder> ptr(new CountHolder(i));

            XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
            XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
            XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

            XTESTS_TEST_INTEGER_EQUAL(124, ptr->i());
        }

        XTESTS_TEST_INTEGER_EQUAL(123, i);
    }
}

static void test_ctor_copy()
{
    {
        stlsoft::shared_ptr<int> ptr(new int(123));

        XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(123, *ptr);

        stlsoft::shared_ptr<int> ptr2(ptr);

        XTESTS_TEST_INTEGER_EQUAL(2, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(2, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(123, *ptr);

        XTESTS_TEST_INTEGER_EQUAL(2, ptr2.count());
        XTESTS_TEST_INTEGER_EQUAL(2, ptr2.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

        XTESTS_TEST_INTEGER_EQUAL(123, *ptr2);
    }

    {
        stlsoft::shared_ptr<std::string> ptr(new std::string("123"));

        XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", *ptr);

        stlsoft::shared_ptr<std::string> ptr2(ptr);

        XTESTS_TEST_INTEGER_EQUAL(2, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(2, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", *ptr);
        XTESTS_TEST_INTEGER_EQUAL(3u, ptr->size());

        XTESTS_TEST_INTEGER_EQUAL(2, ptr2.count());
        XTESTS_TEST_INTEGER_EQUAL(2, ptr2.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", *ptr2);
        XTESTS_TEST_INTEGER_EQUAL(3u, ptr2->size());
    }

    {
        int i = 123;

        {
            stlsoft::shared_ptr<CountHolder> ptr(new CountHolder(i));

            XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
            XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
            XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

            XTESTS_TEST_INTEGER_EQUAL(124, ptr->i());

            {
                stlsoft::shared_ptr<CountHolder> ptr2(ptr);

                XTESTS_TEST_INTEGER_EQUAL(2, ptr.count());
                XTESTS_TEST_INTEGER_EQUAL(2, ptr.use_count());
                XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

                XTESTS_TEST_INTEGER_EQUAL(124, ptr->i());

                XTESTS_TEST_INTEGER_EQUAL(2, ptr2.count());
                XTESTS_TEST_INTEGER_EQUAL(2, ptr2.use_count());
                XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

                XTESTS_TEST_INTEGER_EQUAL(124, ptr2->i());
            }

            XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
            XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
            XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

            XTESTS_TEST_INTEGER_EQUAL(124, ptr->i());
        }

        XTESTS_TEST_INTEGER_EQUAL(123, i);
    }
}

#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

static void test_ctor_move()
{
    {
        stlsoft::shared_ptr<int> ptr(new int(123));

        XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(123, *ptr);

        stlsoft::shared_ptr<int> ptr2(std::move(ptr));

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

        XTESTS_TEST_INTEGER_EQUAL(123, *ptr2);
    }

    {
        stlsoft::shared_ptr<std::string> ptr(new std::string("123"));

        XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", *ptr);

        stlsoft::shared_ptr<std::string> ptr2(std::move(ptr));

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", *ptr2);
        XTESTS_TEST_INTEGER_EQUAL(3u, ptr2->size());
    }

    {
        int i = 123;

        {
            stlsoft::shared_ptr<CountHolder> ptr(new CountHolder(i));

            XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
            XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
            XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

            XTESTS_TEST_INTEGER_EQUAL(124, ptr->i());

            {
                stlsoft::shared_ptr<CountHolder> ptr2(std::move(ptr));

                XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
                XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
                XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());

                XTESTS_TEST_INTEGER_EQUAL(1, ptr2.count());
                XTESTS_TEST_INTEGER_EQUAL(1, ptr2.use_count());
                XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

                XTESTS_TEST_INTEGER_EQUAL(124, ptr2->i());
            }

            XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
            XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
            XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());
        }

        XTESTS_TEST_INTEGER_EQUAL(123, i);
    }
}
#endif

static void test_swap()
{
    {
        stlsoft::shared_ptr<int> ptr(new int(123));

        XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(123, *ptr);

        stlsoft::shared_ptr<int> ptr2;

        ptr2.swap(ptr);

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

        XTESTS_TEST_INTEGER_EQUAL(123, *ptr2);
    }

    {
        stlsoft::shared_ptr<std::string> ptr(new std::string("123"));

        XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", *ptr);

        stlsoft::shared_ptr<std::string> ptr2;

        ptr2.swap(ptr);

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", *ptr2);
        XTESTS_TEST_INTEGER_EQUAL(3u, ptr2->size());
    }

    {
        int i = 123;

        {
            stlsoft::shared_ptr<CountHolder> ptr(new CountHolder(i));

            XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
            XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
            XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

            XTESTS_TEST_INTEGER_EQUAL(124, ptr->i());

            {
                stlsoft::shared_ptr<CountHolder> ptr2;

                ptr2.swap(ptr);

                XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
                XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
                XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());

                XTESTS_TEST_INTEGER_EQUAL(1, ptr2.count());
                XTESTS_TEST_INTEGER_EQUAL(1, ptr2.use_count());
                XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

                XTESTS_TEST_INTEGER_EQUAL(124, ptr2->i());
            }

            XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
            XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
            XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());
        }

        XTESTS_TEST_INTEGER_EQUAL(123, i);
    }
}

static void test_std_swap()
{
    {
        stlsoft::shared_ptr<int> ptr(new int(123));

        XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(123, *ptr);

        stlsoft::shared_ptr<int> ptr2;

        std::swap(ptr, ptr2);

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

        XTESTS_TEST_INTEGER_EQUAL(123, *ptr2);
    }

    {
        stlsoft::shared_ptr<std::string> ptr(new std::string("123"));

        XTESTS_TEST_INTEGER_EQUAL(1, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr.get());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", *ptr);

        stlsoft::shared_ptr<std::string> ptr2;

        std::swap(ptr, ptr2);

        XTESTS_TEST_INTEGER_EQUAL(0, ptr.count());
        XTESTS_TEST_INTEGER_EQUAL(0, ptr.use_count());
        XTESTS_TEST_POINTER_EQUAL(NULL, ptr.get());

        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.count());
        XTESTS_TEST_INTEGER_EQUAL(1, ptr2.use_count());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr2.get());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("123", *ptr2);
        XTESTS_TEST_INTEGER_EQUAL(3u, ptr2->size());
    }
}

static void test_1_1()
{
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

