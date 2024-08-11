### Mini tutorial for the helper folder
  1. debugger
  2. analyzer(timer)

The analyzer contains:
  - complexity analyzer with graphs
  - execution time analyzer
  - comparator for 2 functions

The debugger contains:
  - a debugger to print passed arguments

### **exec_time**:
```cpp

// be careful for member functions, they have to be transformed into
// static ones using lambda functions or std::bind()
auto shortest_path = [&](int a, int b) -> double {
    return g.shortest_path(a, b);
};

TIMER::exec_time(shortest_path, 0, 4); // will print the execution time of the function
```

### **check_faster**:
```cpp
auto shortest_path = [&](int a, int b) -> double {
    return g.shortest_path(a, b);
};

auto dfs = [&](int a) -> std::vector<int> {
    return g.dfs(a);
};

// This will return which function is faster
std::cout << TIMER::check_faster(shortest_path, std::make_tuple(0, 1), dfs, std::make_tuple(0)) << '\n';
```

### **time_complexity**:
```cpp
#include "eratosthenes_sieve.h"

// This will analyze the complexity with a graph
TIMER::time_complexity(soe, std::make_tuple(4), std::make_tuple(5), std::make_tuple(10), std::make_tuple(15), std::make_tuple(50), std::make_tuple(100), std::make_tuple(500), std::make_tuple(10000), std::make_tuple(99999));
```


### **get_args**:
```cpp
auto shortest_path = [&](int a, int b) -> double {
    return g.shortest_path(a, b);
};

// This will print 0, 5
DEBUG::get_args(shortest_path, 0, 5);
```
