
#include <stlsoft/view/transforming/member_selector_view.hpp>

#include <iostream>
#include <list>

#include <time.h>

int main()
{
    {
        struct tm elements[] =
        {
            { .tm_mon = 1 },
            { .tm_mon = 2 },
            { .tm_mon = 3 },
        };

        auto const months = stlsoft::make_member_selector_view(elements, &tm::tm_mon);

        std::cout
            << "months (from array):"
            << std::endl
            ;

        for (auto const& month : months)
        {
            std::cout << month << std::endl;
        }
    }

    {
        struct tm elements[] =
        {
            { .tm_mon = 1 },
            { .tm_mon = 2 },
            { .tm_mon = 3 },
        };

        auto const months = stlsoft::make_member_selector_view(std::begin(elements), std::end(elements), &tm::tm_mon);

        std::cout
            << "months (from array pointers):"
            << std::endl
            ;

        for (auto const& month : months)
        {
            std::cout << month << std::endl;
        }
    }

    {
        struct tm elements[] =
        {
            { .tm_mon = 1 },
            { .tm_mon = 2 },
            { .tm_mon = 3 },
        };

        std::list<struct tm> list_of_elements(std::begin(elements), std::end(elements));

        auto const months = stlsoft::make_member_selector_view(std::begin(list_of_elements), std::end(list_of_elements), &tm::tm_mon);

        std::cout
            << "months (from list):"
            << std::endl
            ;

        for (auto const& month : months)
        {
            std::cout << month << std::endl;
        }
    }



    return 0;
}
