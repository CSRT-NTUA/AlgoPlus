#ifndef EXPONENTIAL_SEARCH_H
#define EXPONENTIAL_SEARCH_H

#ifdef __cplusplus
#include "binary_search.h"
#include <iostream>
#endif

template <typename T> int64_t exponential_search(std::vector<T> arr, T key) {
  if (arr[0] == key) {
    return true;
  }
  int64_t i = 1, n = arr.size();
  while (i < n && arr[i] < key) {
    i *= 2;
  }
  int64_t lo = i / 2, hi = std::min(i, n - 1);
  while (lo <= hi) {
    int64_t mid = (lo + hi) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return -1;
}

#endif