#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#ifdef __cplusplus
#include <iostream>
#endif

template <typename T> bool linear_search(std::vector<T> arr, T key) {
  for (T &x : arr) {
    if (x == key) {
      return true;
    }
  }
  return false;
}

#endif