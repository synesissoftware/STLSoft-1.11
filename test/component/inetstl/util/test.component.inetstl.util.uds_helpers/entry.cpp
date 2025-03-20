/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.inetstl.util.uds_helpers/entry.cpp
 *
 * Purpose: Unit-tests for `inetstl::environment_variable`.
 *
 * Created: 21st February 2025
 * Updated: 20th March 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */


#include <inetstl/util/uds_helpers.h>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <limits>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void TEST_INSUFFICIENT_SPACE();
    static void TEST_EMPTY_path();
    static void TEST_VALID_paths();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.inetstl.util.uds_helpers", verbosity))
    {
        XTESTS_RUN_CASE(TEST_INSUFFICIENT_SPACE);
        XTESTS_RUN_CASE(TEST_EMPTY_path);
        XTESTS_RUN_CASE(TEST_VALID_paths);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

static void TEST_INSUFFICIENT_SPACE()
{

    {
        char buff[1] =  { '~' };

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        reinterpret_cast<struct sockaddr_un*>(&buff)
                                    ,   sizeof(buff)
                                    ,   NULL
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(-1, r);
        TEST_INT_EQ(EINVAL, errno);
        TEST_INT_EQ(0, cb_actual);
        XTESTS_TEST_CHARACTER_EQUAL('~', buff[0]);
    }

    {
        char buff[2] =  { '~' };

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        reinterpret_cast<struct sockaddr_un*>(&buff)
                                    ,   sizeof(buff)
                                    ,   NULL
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(-1, r);
        TEST_INT_EQ(EINVAL, errno);
        TEST_INT_EQ(0, cb_actual);
        XTESTS_TEST_CHARACTER_EQUAL('~', buff[0]);
    }
}

static void TEST_EMPTY_path()
{
    {
        char buff[3] =  { '1', '2', '3' };

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        reinterpret_cast<struct sockaddr_un*>(&buff)
                                    ,   sizeof(buff)
                                    ,   NULL
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(0, r);
        TEST_INT_EQ(0, errno);
        TEST_INT_EQ(3, cb_actual);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('1', buff[0]);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('2', buff[1]);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('3', buff[2]);
    }

    {
        char buff[3] =  { '1', '2', '3' };

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        reinterpret_cast<struct sockaddr_un*>(&buff)
                                    ,   sizeof(buff)
                                    ,   ""
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(0, r);
        TEST_INT_EQ(0, errno);
        TEST_INT_EQ(3, cb_actual);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('1', buff[0]);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('2', buff[1]);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('3', buff[2]);
    }

    {
        char buff[4] =  { '1', '2', '3', '4' };

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        reinterpret_cast<struct sockaddr_un*>(&buff)
                                    ,   3
                                    ,   NULL
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(0, r);
        TEST_INT_EQ(0, errno);
        TEST_INT_EQ(3, cb_actual);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('1', buff[0]);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('2', buff[1]);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('3', buff[2]);
        XTESTS_TEST_CHARACTER_EQUAL('4', buff[3]);
    }

    {
        char buff[4] =  { '1', '2', '3', '4' };

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        reinterpret_cast<struct sockaddr_un*>(&buff)
                                    ,   3
                                    ,   ""
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(0, r);
        TEST_INT_EQ(0, errno);
        TEST_INT_EQ(3, cb_actual);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('1', buff[0]);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('2', buff[1]);
        XTESTS_TEST_CHARACTER_NOT_EQUAL('3', buff[2]);
        XTESTS_TEST_CHARACTER_EQUAL('4', buff[3]);
    }
}

static void TEST_VALID_paths()
{
    {
        struct sockaddr_un  sa_un;

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        &sa_un
                                    ,   sizeof(sa_un)
                                    ,   "p"
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(0, r);
        TEST_INT_EQ(0, errno);
        TEST_INT_EQ(4, cb_actual);

#if defined(INETSTL_OS_IS_MACOSX)

        TEST_INT_EQ(4, sa_un.sun_len);
#endif
        TEST_INT_EQ(AF_UNIX, sa_un.sun_family);
        TEST_MS_EQ("p", sa_un.sun_path);
    }

    {
        struct sockaddr_un  sa_un;

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        &sa_un
                                    ,   sizeof(sa_un)
                                    ,   "/tmp/sock/my_socket"
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(0, r);
        TEST_INT_EQ(0, errno);
        TEST_INT_EQ(22, cb_actual);

#if defined(INETSTL_OS_IS_MACOSX)

        TEST_INT_EQ(22, sa_un.sun_len);
#endif
        TEST_INT_EQ(AF_UNIX, sa_un.sun_family);
        TEST_MS_EQ("/tmp/sock/my_socket", sa_un.sun_path);
    }

    {
        struct sockaddr_un  sa_un;

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        &sa_un
                                    ,   sizeof(sa_un)
                                    ,   "/tmp/sock/012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(0, r);
        TEST_INT_EQ(0, errno);
        TEST_INT_EQ(103, cb_actual);

#if defined(INETSTL_OS_IS_MACOSX)

        TEST_INT_EQ(103, sa_un.sun_len);
#endif
        TEST_INT_EQ(AF_UNIX, sa_un.sun_family);
        TEST_MS_EQ("/tmp/sock/012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789", sa_un.sun_path);
    }

    {
        struct sockaddr_un  sa_un;

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        &sa_un
                                    ,   sizeof(sa_un)
                                    ,   "/tmp/sock/012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012"
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(0, r);
        TEST_INT_EQ(0, errno);
        TEST_INT_EQ(106, cb_actual);

#if defined(INETSTL_OS_IS_MACOSX)

        TEST_INT_EQ(106, sa_un.sun_len);
#endif
        TEST_INT_EQ(AF_UNIX, sa_un.sun_family);
        TEST_MS_EQ("/tmp/sock/012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012", sa_un.sun_path);
    }

    {
        struct sockaddr_un  sa_un;

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        &sa_un
                                    ,   sizeof(sa_un)
                                    ,   "/tmp/sock/0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123"
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(0, r);
        TEST_INT_EQ(0, errno);
        TEST_INT_EQ(106, cb_actual);

#if defined(INETSTL_OS_IS_MACOSX)

        TEST_INT_EQ(106, sa_un.sun_len);
#endif
        TEST_INT_EQ(AF_UNIX, sa_un.sun_family);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("/tmp/sock/0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123", sa_un.sun_path, 104);
    }

    {
        struct sockaddr_un  sa_un;

        memset(&sa_un, 0, sizeof(sa_un));

        errno = 0;

        size_t      cb_actual   =   std::numeric_limits<size_t>::max();
        int const   r           =   inetstl_c_sockaddr_un_init_from_path(
                                        &sa_un
                                    ,   sizeof(sa_un)
                                    ,   "/tmp/sock/01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234"
                                    ,   &cb_actual
                                    );

        TEST_INT_EQ(-1, r);
        TEST_INT_EQ(EINVAL, errno);
        TEST_INT_EQ(0, cb_actual);

#if defined(INETSTL_OS_IS_MACOSX)

        TEST_INT_EQ(0, sa_un.sun_len);
#endif
        TEST_INT_EQ(0, sa_un.sun_family);
        TEST_MS_EQ("", sa_un.sun_path);
    }
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

