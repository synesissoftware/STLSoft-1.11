
#include <stlsoft/view/transforming/member_selector_view.hpp>

#include <iostream>
#include <list>

#include <time.h>


int main()
{


#if __cplusplus >= 202002L

    struct tm elements[] =
    {
        { .tm_mon = 1 },
        { .tm_mon = 2 },
        { .tm_mon = 3 },
    };
#else

    struct tm elements[3] =
    {
        {},
        {},
        {},
    };
    elements[0].tm_mon = 1;
    elements[0].tm_mon = 2;
    elements[0].tm_mon = 3;
#endif



    {
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

