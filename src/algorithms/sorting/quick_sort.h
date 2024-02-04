#ifndef ALGOPLUS_QUICK_SORT_H
#define ALGOPLUS_QUICK_SORT_H

#include <iterator> // For std::iterator_traits
#include <algorithm> // For std::partition
/**
 * @brief Sorts a range of elements using the Quick Sort algorithm
 * @param begin An iterator to the beginning of the range to be sorted.
 * @param end An iterator to the end of the range to be sorted.
 * @details The implementation requires that the iterator type `Iter` supports Random Access to enable
 * efficient partitioning and element swapping. The elements in the range must be move-assignable
 * and should support comparison with the '<' operator. If these requirements are not met,
 * the behavior of the function is undefined.
 * This function sorts the elements in the range [begin, end) into ascending order.
 * The sort is performed in-place.
 * Its performance is generally O(n log n) on average, though worst-case performance is O(n^2)
*/
template<typename Iter>
void quick_sort(Iter begin, Iter end) {
    auto distance = std::distance(begin, end);
    if (distance <= 1) return; // Base case: 0 or 1 element

    auto pivot = *begin;

    Iter middle1 = std::partition(begin, end, [pivot](const auto& elem) {
        return elem < pivot;
    });

    Iter middle2 = std::partition(middle1, end, [pivot](const auto& elem) {
        return !(pivot < elem);
    });

    // Recursively apply quick_sort to the partitions
    quick_sort(begin, middle1);
    quick_sort(middle2, end);
}

#endif //QUICK_SORT_H
