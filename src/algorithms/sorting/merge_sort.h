#ifndef ALGOPLUS_MERGE_SORT_H
#define ALGOPLUS_MERGE_SORT_H

#include <iostream>
#include <vector>
#include <algorithm> // Required for std::inplace_merge

/**
 * @brief Performs a merge sort on a range of elements.
 * @param begin An iterator to the beginning of the range to be sorted.
 * @param end An iterator to the end of the range to be sorted.
 *
 * @details
 * This function sorts the elements in the range [begin, end) into ascending order.
 * The sort is performed in-place. The function requires that the range of elements
 * is sortable by the criteria used in std::inplace_merge.
 *
 * merge sort has an average and worst-case performance of O(n log n) comparisons
 */
template <typename Iter>
void merge_sort(Iter begin, Iter end) {
    if (end - begin > 1) {
        Iter mid = begin + (end - begin) / 2; // Assumes Random Access Iterator
        merge_sort(begin, mid);
        merge_sort(mid, end);
        std::inplace_merge(begin, mid, end); // Elements must be comparable and move-assignable
    }
}

#endif //ALGOPLUS_MERGE_SORT_H
