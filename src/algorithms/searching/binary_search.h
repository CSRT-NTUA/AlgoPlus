#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#ifdef __cplusplus
#include <iostream>
#endif

/**
 * @brief binary search function
 *
 * @param arr the vector
 * @param left the left pointer
 * @param right the right pointer
 * @param x the element we want to search
 * @return int64_t the index of the element in the vector, if it doesn't exist
 * then it returns -1
 */
template <typename T>
int64_t bin_search(std::vector<T> arr, int64_t left, int64_t right, T x) {
  while (left <= right) {
    int64_t mid = left + (right - left) / 2;
    if (arr[mid] == x) {
      return mid;
    }
    if (arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1; // element not found
}

#endif