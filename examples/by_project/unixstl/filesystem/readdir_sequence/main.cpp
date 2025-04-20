/* /////////////////////////////////////////////////////////////////////////
 * Purpose: Illustrates the use of `unixstl::readdir_sequence` to search for
 *          the files and directories in a given root-directory.
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <unixstl/filesystem/readdir_sequence.hpp>

#include <platformstl/filesystem/path_functions.h>
#include <unixstl/filesystem/filesystem_traits.hpp>

#include <iostream>


using unixstl::readdir_sequence;
typedef unixstl::filesystem_traits<char>    fs_traits_t;


int main(int argc, char* argv[])
{
    char const* const   program_name    =   platformstl::get_executable_name_from_path(argv[0]).ptr;
    char const*         root_dir        =   ss_nullptr_k;

    if (argc > 1 && 0 == strcmp("--help", argv[1]))
    {
        std::cout
            << "USAGE: "
            << program_name
            << " <search-directory>"
            << std::endl;

        return EXIT_SUCCESS;
    }

    switch (argc)
    {
    case 1:

        root_dir = ".";
        break;
    case 2:

        root_dir = argv[1];
        break;

    default:

        std::cerr
            << program_name
            << ": "
            << "too many arguments; use --help for usage"
            << std::endl;

        return EXIT_FAILURE;
    }


    {
        std::cout << "searching for directories in '" << root_dir << "':" << std::endl;

        readdir_sequence directories(root_dir, readdir_sequence::absolutePath | readdir_sequence::fullPath | readdir_sequence::directories);

        for (readdir_sequence::const_iterator i = directories.begin(); directories.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << "/"
                << std::endl;
        }
    }

    {
        std::cout << "searching for files in '" << root_dir << "':" << std::endl;

        readdir_sequence files(root_dir, readdir_sequence::absolutePath | readdir_sequence::fullPath | readdir_sequence::files);

        for (readdir_sequence::const_iterator i = files.begin(); files.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << std::endl;
        }
    }

    {
        std::cout << "searching for sockets in '" << root_dir << "':" << std::endl;

        readdir_sequence sockets(root_dir, readdir_sequence::absolutePath | readdir_sequence::fullPath | readdir_sequence::sockets);

        for (readdir_sequence::const_iterator i = sockets.begin(); sockets.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << std::endl;
        }
    }

    {
        std::cout << "searching for files + sockets in '" << root_dir << "':" << std::endl;

        readdir_sequence entries(root_dir, readdir_sequence::absolutePath | readdir_sequence::fullPath | readdir_sequence::files | readdir_sequence::sockets);

        for (readdir_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << (fs_traits_t::is_directory(*i) ? "/" : "")
                << std::endl;
        }
    }

    {
        std::cout << "searching for directories + files + sockets in '" << root_dir << "':" << std::endl;

        readdir_sequence entries(root_dir, readdir_sequence::absolutePath | readdir_sequence::fullPath | readdir_sequence::directories | readdir_sequence::files | readdir_sequence::sockets);

        for (readdir_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << (fs_traits_t::is_directory(*i) ? "/" : "")
                << std::endl;
        }
    }

    {
        std::cout << "searching for all types in '" << root_dir << "':" << std::endl;

        readdir_sequence entries(root_dir);

        for (readdir_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << (fs_traits_t::is_directory(*i) ? "/" : "")
                << std::endl;
        }
    }


    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

