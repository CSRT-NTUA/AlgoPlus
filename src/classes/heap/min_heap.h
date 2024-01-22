#ifdef __cplusplus
#include <functional>
#include <iostream>
#include <vector>
#endif
 
 
template <typename T> class min_heap {
private:
  T *arr;
  size_t max_size;
  size_t heap_size;

public:
  explicit min_heap(size_t max_size) noexcept {
    heap_size = 0;
    this->max_size = max_size;
    arr = new T[max_size];
  }

  ~min_heap() noexcept { delete[] arr; }
  T parent(T i) { return (i - 1) / 2; }

  T __left(T i) { return (2 * i + 1); }

  T __right(T i) { return (2 * i + 2); }

  T __min() {
    if (heap_size <= 0) {
      return INT_MAX;
    }
    if (heap_size == 1) {
      heap_size--;
      return arr[0];
    }
    T root = arr[0];
    arr[0] = arr[heap_size - 1];
    heap_size--;
    heapify(0);
    return root;
  }

  T min() { return arr[0]; }

  void decrease_key(T i, T key) {
    arr[i] = key;
    while (i != 0 && arr[parent(i)] > arr[i]) {
      std::swap(arr[i], arr[parent(i)]);
      i = parent(i);
    }
  }

  void insert(T key) {
    try {
      if (heap_size == max_size) {
        throw std::invalid_argument("Heap reached maximum size");
      } else {
        heap_size++;
        size_t i = heap_size - 1;
        arr[i] = key;
        while (i != 0 && arr[parent(i)] > arr[i]) {
          std::swap(arr[i], arr[parent(i)]);
          i = parent(i);
        }
      }
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << '\n';
      return;
    }
  }

  void remove(T key) {
    decrease_key(key, INT_MIN);
    __min();
  }

  void heapify(T i) {
    T left = __left(i);
    T right = __right(i);
    T minim = i;
    if (left < heap_size && arr[left] < arr[i]) {
      minim = left;
    }
    if (right < heap_size && arr[right] < arr[i]) {
      minim = right;
    }
    if (minim != i) {
      std::swap(arr[i], arr[minim]);
      heapify(minim);
    }
  }
};