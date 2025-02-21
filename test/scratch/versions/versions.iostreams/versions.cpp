
#include <stlsoft/stlsoft.h>
#include <platformstl/platformstl.h>

#include <iomanip>
#include <iostream>


int main(int /* argc */, char* /* argv */[])
{
    // __cplusplus

    {
        std::cout
            << "__cplusplus = "
            << __cplusplus
            << std::endl
            ;

        std::cout << std::endl;
    }


    // _STLSOFT_VER

    {
        std::cout
            << "STLSoft = "
            << ((_STLSOFT_VER >> 24) & 0xff)
            << "."
            << ((_STLSOFT_VER >> 16) & 0xff)
            << "."
            << ((_STLSOFT_VER >> 8) & 0xff)
            << "."
            << ((_STLSOFT_VER >> 0) & 0xff)
            << std::endl
            ;
        std::cout
            << "_STLSOFT_VER = 0x"
            << std::hex << std::setfill('0') << std::setw(8) << _STLSOFT_VER
            << std::dec
            << std::endl
            ;
        std::cout
            << "STLSOFT_COMPILER_VERSION_STRING = "
            << STLSOFT_COMPILER_VERSION_STRING
            << std::endl
            ;

        std::cout << std::endl;
    }


    // _PLATFORMSTL_VER

    {
        std::cout
            << "PlatformSTL = "
            << ((_PLATFORMSTL_VER >> 24) & 0xff)
            << "."
            << ((_PLATFORMSTL_VER >> 16) & 0xff)
            << "."
            << ((_PLATFORMSTL_VER >> 8) & 0xff)
            << "."
            << ((_PLATFORMSTL_VER >> 0) & 0xff)
            << std::endl
            ;
        std::cout
            << "_PLATFORMSTL_VER = 0x"
            << std::hex << std::setfill('0') << std::setw(8) << _PLATFORMSTL_VER
            << std::dec
            << std::endl
            ;

        std::cout << std::endl;
    }


#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)

    // _UNIXSTL_VER

    {
        std::cout
            << "UNIXSTL = "
            << ((_UNIXSTL_VER >> 24) & 0xff)
            << "."
            << ((_UNIXSTL_VER >> 16) & 0xff)
            << "."
            << ((_UNIXSTL_VER >> 8) & 0xff)
            << "."
            << ((_UNIXSTL_VER >> 0) & 0xff)
            << std::endl
            ;
        std::cout
            << "_UNIXSTL_VER = 0x"
            << std::hex << std::setfill('0') << std::setw(8) << _UNIXSTL_VER
            << std::dec
            << std::endl
            ;

        std::cout << std::endl;
    }
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    // _WINSTL_VER

    {
        std::cout
            << "WinSTL = "
            << ((_WINSTL_VER >> 24) & 0xff)
            << "."
            << ((_WINSTL_VER >> 16) & 0xff)
            << "."
            << ((_WINSTL_VER >> 8) & 0xff)
            << "."
            << ((_WINSTL_VER >> 0) & 0xff)
            << std::endl
            ;
        std::cout
            << "_WINSTL_VER = 0x"
            << std::hex << std::setfill('0') << std::setw(8) << _WINSTL_VER
            << std::dec
            << std::endl
            ;

        std::cout << std::endl;
    }
#endif


    return 0;
}

