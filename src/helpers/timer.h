#ifndef TIMER_H
#define TIMER_H

#include <utility>
#ifdef __cplusplus
#include <iostream>
#include <functional>
#include <ctime>
#include <tuple>
#endif

namespace TIMER {
    // Helper function to invoke a function with arguments from a tuple
    template <typename Func, typename Tuple, std::size_t... I>
    void invoke_tuple(Func &&func, Tuple &&tup, std::index_sequence<I...>) {
        std::invoke(std::forward<Func>(func), std::get<I>(std::forward<Tuple>(tup))...);
    }

    // Function to measure execution time
    template <typename Func, typename ...Args>
    double exec_time(Func &&callback, Args&& ...args) {
        auto start = clock();
        std::invoke(std::forward<Func>(callback), std::forward<Args>(args)...);
        auto end = clock();
        double total = (end - start) / double(CLOCKS_PER_SEC) * 1000;
        if (total > 1.0) {
            std::cout << "\033[33m" << "Total execution time: " << total << " ms\n";
        } else {
            std::cout << "\033[32m" << "Total execution time: " << total << " ms\n";
        }
        return total;
    }

    // Function to compare execution times of two functions
    template <typename Func1, typename Tuple1, typename Func2, typename Tuple2>
    int check_faster(Func1 &&callback1, const Tuple1 &args1, Func2 &&callback2, const Tuple2 &args2, int verbose = 0) {
        // Run first function
        auto start = clock();
        invoke_tuple(std::forward<Func1>(callback1), args1, std::make_index_sequence<std::tuple_size_v<Tuple1>>{});
        auto end = clock();
        auto total1 = (end - start) / double(CLOCKS_PER_SEC) * 1000;

        // Run second function
        start = clock();
        invoke_tuple(std::forward<Func2>(callback2), args2, std::make_index_sequence<std::tuple_size_v<Tuple2>>{});
        end = clock();
        auto total2 = (end - start) / double(CLOCKS_PER_SEC) * 1000;

        if(verbose == 1){
            std::cout << "Function 1 execution time: " << total1 << " ms\n";
            std::cout << "Function 2 execution time: " << total2 << " ms\n";
        }

        return (total1 > total2) ? 1 : 0;
    }
}

#endif
