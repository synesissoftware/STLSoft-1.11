/* /////////////////////////////////////////////////////////////////////////
 * File:    test.performance.stlsoft.simple_string.op_eq.cpp
 *
 * Purpose: Perf-test for `stlsoft::basic_simple_string#operator ==()`.
 *
 * Created: 15th March 2024
 * Updated: 17th March 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if !defined(__cplusplus) || \
    __cplusplus < 201103L
# error Requires C++11 or later
#endif


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <platformstl/diagnostics/stopwatch.hpp>
#include <platformstl/diagnostics/processtimes_stopwatch.hpp>
#include <stlsoft/diagnostics/std_chrono_hrc_stopwatch.hpp>

#include <iomanip>
#include <iostream>


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

using stlsoft::ss_size_t;
typedef platformstl::stopwatch::interval_type   interval_t;


/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

template<
    ss_typename_param_k T_sw
>
std::pair<
    interval_t  // total_time_ns
,   ss_size_t   // anchoring_value - this to incline the optimiser to not elide the whole thing
>
test_(
    ss_size_t   num_iterations
)
{
    platformstl::stopwatch  sw;
    interval_t              interval        =   0;
    ss_size_t               anchoring_value =   0;

    for (int W = 2; W != 0; --W)
    {
        sw.start();

        {
            T_sw t;

            t.start();

            for (ss_size_t i = 0; i != num_iterations; ++i)
            {
                t.stop();
            }

            anchoring_value += t.get_microseconds();
        }

        sw.stop();

        interval = sw.get_nanoseconds();
    }

    return std::make_pair(interval, anchoring_value);
}

void
display_results(
    std::ostream&       stm
,   ss_size_t           num_iterations
,   char const*         type_name
,   std::pair<
        interval_t  // total_time_ns
    ,   ss_size_t   // anchoring_value
    > const&            r
)
{
    stm
        << '\t'
        << type_name
        << '\t'
        << num_iterations
        << '\t'
        << std::setw(12) << std::right << r.first
        << '\t'
        << std::setw(12) << std::setfill(' ') << std::right << std::fixed << std::setprecision(3) << (static_cast<double>(r.first) / num_iterations)
        << '\t'
        << r.second
        << std::endl;
}


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    ss_size_t const NUM_ITERATIONS  =   1000000;

#define DEFINE_TYPE_AND_NAME(t)             char const* const type_name = #t; typedef t sw_t

    {
        DEFINE_TYPE_AND_NAME(platformstl::stopwatch);

        std::pair<
            interval_t  // total_time_ns
        ,   ss_size_t   // anchoring_value
        > const r = test_<sw_t>(NUM_ITERATIONS);

        display_results(std::cout, NUM_ITERATIONS, type_name, r);
    }


    {
        DEFINE_TYPE_AND_NAME(platformstl::processtimes_stopwatch);

        std::pair<
            interval_t  // total_time_ns
        ,   ss_size_t   // anchoring_value
        > const r = test_<sw_t>(NUM_ITERATIONS);

        display_results(std::cout, NUM_ITERATIONS, type_name, r);
    }


    {
        DEFINE_TYPE_AND_NAME(stlsoft::std_chrono_hrc_stopwatch);

        std::pair<
            interval_t  // total_time_ns
        ,   ss_size_t   // anchoring_value
        > const r = test_<sw_t>(NUM_ITERATIONS);

        display_results(std::cout, NUM_ITERATIONS, type_name, r);
    }


    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

