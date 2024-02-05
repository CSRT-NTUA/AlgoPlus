#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#ifdef __cplusplus
#include <iostream>
#include <vector>
#endif

template<typename T> static void heapify_method(std::vector<T> &arr, int arrayLength, int parent) {
    
    //largest node
    int largest = parent;

    //left child
    int left = 2* parent +1;

    //right child 
    int right = 2* parent +2;

    // Compare left child with parent
    if(left < arrayLength && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < arrayLength && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != parent)
    {
        std::swap(arr[parent], arr[largest]);

        heapify_method(arr, arrayLength, largest);
    }
}

/**
 * @brief heap sort function
 * @param arr input array
 * @param arrayLength input length array
 */
template<typename T> void heap_sort(std::vector<T> &arr, int arrayLength) {
    //heapify the array at first
    for(int i = arrayLength/2 -1; i>=0; i--)
    {
        heapify_method(arr, arrayLength, i);
    }
    for(int i = arrayLength-1; i>=0; i--)
    {
        std::swap(arr[0],arr[i]);

        heapify_method(arr, i, 0);
    }
}

#endif