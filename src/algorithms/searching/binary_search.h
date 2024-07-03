#pragma once
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#ifdef __cplusplus
#include <cstdint>
#include <iostream>
#include <vector>
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

/**
 * @brief lower bound search function
 *
 * @param arr the vector
 * @param left the left pointer
 * @param right the right pointer
 * @param x the element we want to search
 * @return int64_t the first index of the element in the vector, if it doesn't exist
 * then it returns -1
 */
template <typename T>
int64_t lower_bound(std::vector<T> arr, int64_t left, int64_t right, T x) {
  int64_t mid = 0;
  int64_t result =-1;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (arr[mid] == x) {
      result = mid;             // element found, make compression on left
      right = mid-1;
    }
    else if (arr[mid] > x) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return result; // element not found
}

/**
 * @brief upper bound search function
 *
 * @param arr the vector
 * @param left the left pointer
 * @param right the right pointer
 * @param x the element we want to search
 * @return int64_t the first last of the element in the vector, if it doesn't exist
 * then it returns -1
 */
template <typename T>
int64_t upper_bound(std::vector<T> arr, int64_t left, int64_t right, T x) {
  int64_t mid = 0;
  int64_t result =-1;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (arr[mid] == x) {
      result = mid;             // element found, make compression on left
      left = mid+1;
    }
    else if (arr[mid] < x) {
      left = mid+1;
    } else {
      right = mid-1;
    }
  }
  return result; // element not found
}

#endif