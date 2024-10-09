/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.winstl.util.struct_initialisers/entry.cpp
 *
 * Purpose: Component test for `winstl::struct_initialisers`.
 *
 * Created: 9th October 2024
 * Updated: 9th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <winstl/util/struct_initialisers.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{
    // no_init_member_type
    static void test_FILETIME(void);
    static void test_SYSTEM_INFO(void);
    static void test_SYSTEMTIME(void);

    // cbSize_member_type
    static void test_CONSOLE_SCREEN_BUFFER_INFOEX(void);

    // cb_member_type
    static void test_STARTUPINFOW(void);

    // cBytes_member_type
    static void test_OFSTRUCT(void);

    // dwLength_member_type
    static void test_MEMORYSTATUS(void);

    // dwOSVersionInfoSize_member_type
    static void test_OSVERSIONINFOA(void);
    static void test_OSVERSIONINFOEXA(void);

    // dwSize_member_type
    static void test_COMMCONFIG(void);

    // nLength_member_type
    static void test_SECURITY_ATTRIBUTES(void);

    // uSize_member_type
    static void test_DRAGINFOA(void);

    // DCBlength
    static void test_DCB(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.winstl.dl.struct_initialisers", verbosity))
    {
        // no_init_member_type
        XTESTS_RUN_CASE(test_FILETIME);
        XTESTS_RUN_CASE(test_SYSTEM_INFO);
        XTESTS_RUN_CASE(test_SYSTEMTIME);

        // cbSize_member_type
        XTESTS_RUN_CASE(test_CONSOLE_SCREEN_BUFFER_INFOEX);

        // cb_member_type
        XTESTS_RUN_CASE(test_STARTUPINFOW);

        // cBytes_member_type
        XTESTS_RUN_CASE(test_OFSTRUCT);

        // dwLength_member_type
        XTESTS_RUN_CASE(test_MEMORYSTATUS);

        // dwOSVersionInfoSize_member_type
        XTESTS_RUN_CASE(test_OSVERSIONINFOA);
        XTESTS_RUN_CASE(test_OSVERSIONINFOEXA);

        // dwSize_member_type
        XTESTS_RUN_CASE(test_COMMCONFIG);

        // nLength_member_type
        XTESTS_RUN_CASE(test_SECURITY_ATTRIBUTES);

        // uSize_member_type
        XTESTS_RUN_CASE(test_DRAGINFOA);

        // DCBlength
        XTESTS_RUN_CASE(test_DCB);

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
    using stlsoft::ss_size_t;


// no_init_member_type

static void test_FILETIME(void)
{
    FILETIME ft;

    winstl::init_struct(ft);

    XTESTS_TEST_INTEGER_EQUAL(0, ft.dwLowDateTime);
    XTESTS_TEST_INTEGER_EQUAL(0, ft.dwHighDateTime);
}

static void test_SYSTEMTIME(void)
{
    SYSTEMTIME st;

    winstl::init_struct(st);

    XTESTS_TEST_INTEGER_EQUAL(0, st.wYear);
    XTESTS_TEST_INTEGER_EQUAL(0, st.wMonth);
    XTESTS_TEST_INTEGER_EQUAL(0, st.wDayOfWeek);
    XTESTS_TEST_INTEGER_EQUAL(0, st.wDay);
    XTESTS_TEST_INTEGER_EQUAL(0, st.wHour);
    XTESTS_TEST_INTEGER_EQUAL(0, st.wMinute);
    XTESTS_TEST_INTEGER_EQUAL(0, st.wSecond);
    XTESTS_TEST_INTEGER_EQUAL(0, st.wMilliseconds);
}

static void test_SYSTEM_INFO(void)
{
    SYSTEM_INFO si;

    winstl::init_struct(si);

    XTESTS_TEST_INTEGER_EQUAL(0, si.dwOemId);
    XTESTS_TEST_INTEGER_EQUAL(0, si.wProcessorArchitecture);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwPageSize);
    XTESTS_TEST_POINTER_EQUAL(0, si.lpMinimumApplicationAddress);
    XTESTS_TEST_POINTER_EQUAL(0, si.lpMaximumApplicationAddress);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwActiveProcessorMask);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwNumberOfProcessors);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwProcessorType);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwAllocationGranularity);
    XTESTS_TEST_INTEGER_EQUAL(0, si.wProcessorLevel);
    XTESTS_TEST_INTEGER_EQUAL(0, si.wProcessorRevision);
}


// cbSize_member_type

static void test_CONSOLE_SCREEN_BUFFER_INFOEX(void)
{
    CONSOLE_SCREEN_BUFFER_INFOEX csbix;

    winstl::init_struct(csbix);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(csbix), csbix.cbSize);

#if 0
    XTESTS_TEST((COORD { 0, 0 } == csbix.dwSize));
    XTESTS_TEST((COORD { 0, 0 } == csbix.dwCursorPosition));
#endif
    XTESTS_TEST_INTEGER_EQUAL(0, csbix.wAttributes);
#if 0
    XTESTS_TEST_INTEGER_EQUAL(0, csbix.srWindow);
    XTESTS_TEST_INTEGER_EQUAL(0, csbix.dwMaximumWindowSize);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0, csbix.wPopupAttributes);
    XTESTS_TEST_BOOLEAN_FALSE(csbix.bFullscreenSupported);
    // COLORREF csbix.ColorTable[16];
}


// cb_member_type

static void test_STARTUPINFOW(void)
{
    STARTUPINFOW si;

    winstl::init_struct(si);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(si), si.cb);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.lpReserved);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.lpDesktop);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.lpTitle);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwX);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwY);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwXSize);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwYSize);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwXCountChars);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwYCountChars);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwFillAttribute);
    XTESTS_TEST_INTEGER_EQUAL(0, si.dwFlags);
    XTESTS_TEST_INTEGER_EQUAL(0, si.wShowWindow);
    XTESTS_TEST_INTEGER_EQUAL(0, si.cbReserved2);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.lpReserved2);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.hStdInput);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.hStdOutput);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.hStdError);
}


// cBytes_member_type

static void test_OFSTRUCT(void)
{
    OFSTRUCT ofs;

    winstl::init_struct(ofs);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(ofs), static_cast<ss_size_t>(ofs.cBytes));
    XTESTS_TEST_INTEGER_EQUAL(0, ofs.fFixedDisk);
    XTESTS_TEST_INTEGER_EQUAL(0, ofs.nErrCode);
    XTESTS_TEST_INTEGER_EQUAL(0, ofs.Reserved1);
    XTESTS_TEST_INTEGER_EQUAL(0, ofs.Reserved2);
#if 0
    CHAR szPathName[OFS_MAXPATHNAME];
#endif
}


// dwLength_member_type

static void test_MEMORYSTATUS(void)
{
    MEMORYSTATUS ms;

    winstl::init_struct(ms);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(ms), ms.dwLength);
    XTESTS_TEST_INTEGER_EQUAL(0, ms.dwMemoryLoad);
    XTESTS_TEST_INTEGER_EQUAL(0, ms.dwTotalPhys);
    XTESTS_TEST_INTEGER_EQUAL(0, ms.dwAvailPhys);
    XTESTS_TEST_INTEGER_EQUAL(0, ms.dwTotalPageFile);
    XTESTS_TEST_INTEGER_EQUAL(0, ms.dwAvailPageFile);
    XTESTS_TEST_INTEGER_EQUAL(0, ms.dwTotalVirtual);
    XTESTS_TEST_INTEGER_EQUAL(0, ms.dwAvailVirtual);
}


// dwOSVersionInfoSize_member_type

static void test_OSVERSIONINFOA(void)
{
    OSVERSIONINFOA osvi;

    winstl::init_struct(osvi);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(osvi), osvi.dwOSVersionInfoSize);
    XTESTS_TEST_INTEGER_EQUAL(0, osvi.dwMajorVersion);
    XTESTS_TEST_INTEGER_EQUAL(0, osvi.dwMinorVersion);
    XTESTS_TEST_INTEGER_EQUAL(0, osvi.dwBuildNumber);
    XTESTS_TEST_INTEGER_EQUAL(0, osvi.dwPlatformId);
#if 0
    CHAR   szCSDVersion[ 128 ];     // Maintenance string for PSS usage
#endif
}

static void test_OSVERSIONINFOEXA(void)
{
    OSVERSIONINFOEXA osvix;

    winstl::init_struct(osvix);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(osvix), osvix.dwOSVersionInfoSize);
    XTESTS_TEST_INTEGER_EQUAL(0, osvix.dwMajorVersion);
    XTESTS_TEST_INTEGER_EQUAL(0, osvix.dwMinorVersion);
    XTESTS_TEST_INTEGER_EQUAL(0, osvix.dwBuildNumber);
    XTESTS_TEST_INTEGER_EQUAL(0, osvix.dwPlatformId);
#if 0
    CHAR   szCSDVersion[ 128 ];     // Maintenance string for PSS usage
#endif
    XTESTS_TEST_INTEGER_EQUAL(0, osvix.wServicePackMajor);
    XTESTS_TEST_INTEGER_EQUAL(0, osvix.wServicePackMinor);
    XTESTS_TEST_INTEGER_EQUAL(0, osvix.wSuiteMask);
    XTESTS_TEST_INTEGER_EQUAL(0, osvix.wProductType);
    XTESTS_TEST_INTEGER_EQUAL(0, osvix.wReserved);
}


// dwSize_member_type

static void test_COMMCONFIG(void)
{
    // NOTE: this specialisation is questionnable, since COMMCONFIG is a
    // variable-length structure

    COMMCONFIG cc;

    winstl::init_struct(cc);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(cc), cc.dwSize);
    XTESTS_TEST_INTEGER_EQUAL(0, cc.wVersion);
    XTESTS_TEST_INTEGER_EQUAL(0, cc.wReserved);
#if 0
    XTESTS_TEST_INTEGER_EQUAL(0, cc.dcb);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0, cc.dwProviderSubType);
    XTESTS_TEST_INTEGER_EQUAL(0, cc.dwProviderOffset);
    XTESTS_TEST_INTEGER_EQUAL(0, cc.dwProviderSize);
#if 0
    XTESTS_TEST_INTEGER_EQUAL(0, cc.wcProviderData);
#endif
}


// nLength_member_type

static void test_SECURITY_ATTRIBUTES(void)
{
    SECURITY_ATTRIBUTES sa;

    winstl::init_struct(sa);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(sa), sa.nLength);
    XTESTS_TEST_POINTER_EQUAL(NULL, sa.lpSecurityDescriptor);
    XTESTS_TEST_BOOLEAN_FALSE(sa.bInheritHandle);
}


// uSize_member_type

static void test_DRAGINFOA(void)
{
    DRAGINFOA da;

    winstl::init_struct(da);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(da), da.uSize);
#if 0
    POINT pt;
#endif
    XTESTS_TEST_BOOLEAN_FALSE(da.fNC);
    XTESTS_TEST_POINTER_EQUAL(NULL, da.lpFileList);
    XTESTS_TEST_INTEGER_EQUAL(0, da.grfKeyState);
}


// DCBlength

static void test_DCB(void)
{
    DCB dcb;

    winstl::init_struct(dcb);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(dcb), dcb.DCBlength);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.BaudRate);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fBinary);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fParity);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fOutxCtsFlow);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fOutxDsrFlow);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fDtrControl);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fDsrSensitivity);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fTXContinueOnXoff);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fOutX);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fInX);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fErrorChar);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fNull);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fRtsControl);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fAbortOnError);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.fDummy2);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.wReserved);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.XonLim);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.XoffLim);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.ByteSize);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.Parity);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.StopBits);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dcb.XonChar);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dcb.XoffChar);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dcb.ErrorChar);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dcb.EofChar);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dcb.EvtChar);
    XTESTS_TEST_INTEGER_EQUAL(0, dcb.wReserved1);
}


} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

