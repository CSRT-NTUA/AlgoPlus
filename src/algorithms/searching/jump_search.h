#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H

#ifdef __cplusplus
#include <iostream>
#endif

template <typename T> int64_t jump_search(std::vector<T> arr, T key) {
  int64_t n = arr.size(), step = sqrt(arr.size()), prev = 0;
  while (arr[std::min(step, n) - 1] < key) {
    prev = step;
    step += sqrt(n);
    if (prev >= n) {
      return -1; // out of bounds
    }
  }
  while (arr[prev] < key) {
    prev++;
    if (prev == std::min(step, n)) {
      return -1;
    }
  }
  return (arr[prev] == key) ? prev : -1;
}

#endif