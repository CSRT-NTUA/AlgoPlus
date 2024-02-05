#ifdef __cplusplus
#include "../../src/algorithms/sorting/heap_sort.h"
#endif

int main()
{
    int arr[] = {59, 84, 62, 35, 32, 89, 16, 44};
    int N = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr, N);
    for (int i = 0; i<N;i++)
    {
        std::cout << arr[i] << " ";
    }
}