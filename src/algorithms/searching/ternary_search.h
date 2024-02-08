#pragma once
#ifndef ALGOPLUS_TERNARY_SEARCH_H
#define ALGOPLUS_TERNARY_SEARCH_H

#ifdef __cplusplus
#include <vector>
#include <cstdint>
#include <algorithm>
#endif

/**
 * @brief Performs an interpolation search on a sorted container.
 *
 * @details
 * This function performs a ternary_search algorithm,
 * which is a divide-and-conquer search algorithm and works by
 * dividing the search space into three equal parts and determining
 * in which part the key lies. This algorithm as a time complexity of O(log3 N)
 *
 * @tparam RandomAccessIterator A type of random-access iterator.
 * @tparam T The type of elements in the sequence to be searched.
 * @param start The starting iterator of the sequence.
 * @param end The ending iterator of the sequence
 * @param key The key value to search for in the sequence.
 * @return If the key is found, returns the index. If the key is not found, returns -1.
 */
template <typename RandomAccessIterator, typename T>
int64_t ternary_search(RandomAccessIterator start, RandomAccessIterator end, T key) {
    int64_t baseIndex = std::distance(start, end);

    while (end >= start) {
        int64_t range = std::distance(start, end) / 3;
        auto mid1 = start + range;
        auto mid2 = mid1 + range;

        if (*mid1 == key) {
            return std::distance(start, mid1) + baseIndex;
        }
        if (*mid2 == key) {
            return std::distance(start, mid2) + baseIndex;
        }

        if (key < *mid1) {
            end = mid1 - 1;
        } else if (key > *mid2) {
            start = mid2 + 1;
        } else {
            start = mid1 + 1;
            end = mid2 - 1;
        }
    }
    return -1;
}

#endif //ALGOPLUS_TERNARY_SEARCH_H
