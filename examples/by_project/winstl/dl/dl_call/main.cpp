
#include <winstl/dl/dl_call.hpp>

#include <stdio.h>
#include <stdlib.h>


int main(int /* argc */, char* /* argv */[])
{
#ifdef WINSTL_ARCH_IS_ARM64
# define ARCH "WINSTL_ARCH_IS_ARM64"
#endif /* WINSTL_ARCH_IS_ARM64 */
#ifdef WINSTL_ARCH_IS_IA64
# define ARCH "WINSTL_ARCH_IS_IA64"
#endif /* WINSTL_ARCH_IS_IA64 */
#ifdef WINSTL_ARCH_IS_X64
# define ARCH "WINSTL_ARCH_IS_X64"
#endif /* WINSTL_ARCH_IS_X64 */
#ifdef WINSTL_ARCH_IS_X86
# define ARCH "WINSTL_ARCH_IS_X86"
#endif /* WINSTL_ARCH_IS_X86 */

    fprintf(stdout, "ARCH=%s\n", ARCH);

    try
    {
        DWORD const tc = winstl::dl_call<DWORD>("Kernel32.dll", "S:GetTickCount");

        fprintf(stdout, "Kernel32:GetTickCount: %lu\n", static_cast<unsigned long>(tc));
    }
    catch (winstl::missing_entry_point_exception& x)
    {
        fprintf(stderr, "failed to load dynamic function: %s\n", x.what());
    }
    catch (winstl::invalid_calling_convention_exception& x)
    {
        fprintf(stderr, "failed to load dynamic function: %s\n", x.what());
    }
    catch (std::exception& x)
    {
        fprintf(stderr, "general exception (%s): %s\n", typeid(x).name(), x.what());
    }

    return EXIT_SUCCESS;
}
