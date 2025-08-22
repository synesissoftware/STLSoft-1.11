
#include <unixstl/system/home_directory.hpp>

#include <platformstl/filesystem/path_functions.h>

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

int main(int /* argc */, char* argv[])
{
    stlsoft::string_slice_m_t const program_name = platformstl::get_executable_name_from_path(argv[0]);

    try
    {
        std::cout
            << "home directory is '"
            << unixstl::home_directory()
            << "'"
            << std::endl;

        return EXIT_SUCCESS;
    }
    catch (std::bad_alloc&)
    {
        fprintf(stderr, "%.*s: out of memory\n", static_cast<int>(program_name.len), program_name.ptr);
    }
    catch (std::exception& x)
    {
        std::cerr
            << program_name
            << ": "
            << x.what()
            << std::endl;
    }

    return EXIT_FAILURE;
}
