#ifndef DEBUG_H
#define DEBUG_H

#ifdef __cplusplus
#include <iostream>
#endif

namespace DEBUG {
    template <typename T>
    void print_arguments(T &&t) { // single argument
        std::cout << t << ' ';
    }

    template <typename T, typename ...Args>
    void print_arguments(T &&t, Args&& ...args) { // multiple arguments
        std::cout << t << ' ';
        print_arguments(std::forward<Args>(args)...);
    }

    template <typename Func, typename ...Args>
    void get_args(Func &&callback, Args&& ...args) {
        std::cout << "\033[33m" << "Arguments: ";
        print_arguments(args...);
        std::cout << '\n';
    }
}

#endif
