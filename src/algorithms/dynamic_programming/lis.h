#ifndef LIS_H
#define LIS_H

#ifdef __cplusplus
#include <iostream>
#include <vector>
#endif

/*
 *lis function.
 *@param arr: the input array.
 *Returns the longest increasing subsequence of the array.
 */
template <typename T> int64_t lis(std::vector<T> arr) {
  std::vector<T> ans;
  int64_t n = arr.size();
  for (int64_t i = 0; i < n; i++) {
    auto it = std::lower_bound(ans.begin(), ans.end(), arr[i]);
    if (it == ans.end()) {
      ans.push_back(arr[i]);
    } else {
      *it = arr[i];
    }
  }
  return ans.size();
}

#endif