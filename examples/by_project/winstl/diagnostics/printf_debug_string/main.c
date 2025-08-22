
#include <winstl/diagnostics/printf_debug_string.h>

int main(int argc, char* argv[])
{
    ((void)&argc);
    ((void)&argv);

    {
        winstl_C_printf_debug_string("plain\n");
    }

    {
        winstl_C_printf_debug_string("with values %d and '%s'\n", 10, "ten");
    }

    {
        char ones[5000];

        memset(ones, '1', sizeof(ones));

        winstl_C_printf_debug_string("with values %d and '%s'\n", 10, ones);
    }


    return 0;
}
