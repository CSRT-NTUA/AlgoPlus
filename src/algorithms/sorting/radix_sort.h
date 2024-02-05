#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#ifdef __cplusplus
#include <iostream>
#include <vector>
#include <algorithm>
#endif

template <typename T> void radix_sort(std::vector<T> &arr) {
  T max_el = std::max_element(arr.begin(), arr.end());
  size_t iters = to_string(max_el).size();
}

#endif