
#include <winstl/diagnostics/output_debug_line.hpp>

int main(int argc, char* argv[])
{
    ((void)&argc);
    ((void)&argv);

    winstl::diagnostics::output_debug_line("single string");

    winstl::diagnostics::output_debug_line("two-", "strings");

    winstl::diagnostics::output_debug_line("this", " ", "is", " ", "message", " ", "comprising", " ", "eleven", " ", "elements");

    return 0;
}
