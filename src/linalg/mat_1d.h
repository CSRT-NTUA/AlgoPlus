#ifndef MAT_1D_H
#define MAT_1D_H

#ifdef __cplusplus
#include "../algorithms/sorting/quick_sort.h"
#include <cassert>
#include <climits>
#include <cstdint>
#include <iostream>
#include <optional>
#include <vector>
#endif

/**
 *@brief Class for 1-dimensional Matrix
 *
 */
template <typename T, size_t SIZE> class Mat1d {
private:
  T *arr;
  size_t _size;

public:
  /**
   *@brief constructor for Mat1d class
   *
   */
  explicit Mat1d(std::vector<T> v = {}) : _size(SIZE) {
    arr = new T[_size];
    if (!v.empty()) {
      try {
        if (v.size() != _size) {
          throw std::logic_error("Initializer array don't have the same size "
                                 "as the constructed array");
        } else {
          for (size_t i = 0; i < _size; i++) {
            arr[i] = v[i];
          }
        }
      } catch (std::logic_error &e) {
        std::cerr << e.what() << '\n';
      }
    }
  }

  /**
   *@brief constructor for Mat1d class with input value
   *@param val the value that we want all the elements of the array to have
   */
  explicit Mat1d(const T val) noexcept : _size(SIZE) {
    arr = new T[_size];
    for (size_t i = 0; i < _size; ++i) {
      arr[i] = val;
    }
  }

  /**
   *@brief copy constructor for Mat1d class
   *@param mat the matrix we want to copy
   *@return Mat1d
   */
  explicit Mat1d(Mat1d &mat) : _size(SIZE) {
    try {
      if (mat.size() != _size) {
        throw std::logic_error("Tried to copy matrixes with different sizes");
      }
      this->arr = new T[_size];
      for (size_t i = 0; i < _size; i++) {
        this->arr[i] = mat.arr[i];
      }
    } catch (std::logic_error &e) {
      std::cerr << e.what() << '\n';
    }
  }

  /**
   *@brief copy constructor for Mat1d class
   *@param mat the matrix we want to copy
   *@return Mat1d&
   */
  Mat1d &operator=(Mat1d &mat) {
    if (this == &mat) {
      return *(this);
    }
    assert(mat.size() == this->_size);
    for (size_t i = 0; i < _size; i++) {
      this->arr[i] = mat.arr[i];
    }
    return *(this);
  }

  /**
   *@brief destructor of Mat1d class
   *
   */
  ~Mat1d() { delete[] arr; }

  /**
   *@brief size function
   *@return size_t the size of the array
   *
   */
  size_t size() { return this->_size; }

  class Iterator;

  /**
   *@brief Iterator begin for Mat1d class
   *
   */
  Iterator begin() { return Iterator(0, _size, arr); }

  /**
   *@brief Iterator end for Mat1d class
   *
   */
  Iterator end() { return Iterator(_size, _size, arr); }

  /**
   *@brief operator[] for Mat1d class
   *@return T the value of the array to that index
   */
  T &operator[](const size_t index) {
    assert(index < _size);
    return arr[index];
  }

  /**
   *@brief operator == for Mat1d class
   *@param mat the matrix to compare
   *@return true if &this is equal to mat
   *@return false otherwise
   */
  bool operator==(Mat1d &mat) const {
    if (mat.size() != _size) {
      return false;
    }

    for (size_t i = 0; i < _size; i++) {
      if (mat.arr[i] != this->arr[i]) {
        return false;
      }
    }
    return true;
  }

  /**
   *@brief operator << for Mat1d class
   *@param mat the matrix
   *
   */
  friend std::ostream &operator<<(std::ostream &out, Mat1d &mat) {
    out << '[';
    for (size_t i = 0; i < mat.size(); i++) {
      out << mat[i];
      if (i != mat.size() - 1) {
        out << " ";
      }
    }
    out << ']' << '\n';
    return out;
  }
};

/**
 * @brief Iterator class
 */
template <typename T, size_t SIZE> class Mat1d<T, SIZE>::Iterator {
private:
  size_t _size;
  size_t index;
  T *arr;

public:
  /**
   * @brief Construct a new Iterator object
   *
   * @param __size size of the array
   * @param mat the matrix we have
   */
  explicit Iterator(size_t _index, size_t _size, T *_arr) noexcept
      : index(_index), _size(_size), arr(new T[_size]) {
    
    for (size_t i = 0; i < _size; i++) {
      arr[i] = _arr[i];
    }
  }

  /**
   * @brief = operator for Iterator type
   *
   * @param curr the current array
   * @return Iterator&
   */
  Iterator &operator=(T *curr) {
    for (size_t i = 0; i < _size; i++) {
      arr[i] = curr[i];
    }
    return *(this);
  }

  /**
   * @brief operator ++ for type Iterator
   *
   * @return Iterator&
   */
  Iterator &operator++() {
    if (index < _size) {
      index++;
    }
    return *(this);
  }

  /**
   * @brief operator ++ for type Iterator
   *
   * @return Iterator
   */
  Iterator operator++(int) {
    Iterator it = *this;
    ++*(this);
    return it;
  }

  /**
   * @brief operator ++ for type Iterator
   *
   * @return Iterator&
   */
  Iterator &operator--() {
    if (index > 0) {
      index--;
    }
    return *(this);
  }

  /**
   * @brief operator -- for type Iterator
   *
   * @return Iterator
   */
  Iterator operator--(int) {
    Iterator it = *this;
    --*(this);
    return it;
  }

  /**
   * @brief operator != for type Iterator
   *
   * @param it const Iterator
   * @return true if the 2 arrays contains the same elements in the current
   * index
   * @return false otherwise
   */
  bool operator!=(const Iterator &it) { return it.arr[it.index] != arr[index]; }

  /**
   * @brief operator * for type Iterator
   *
   * @return T the value of the array to that index
   */
  T operator*() { return arr[index]; }
};

#endif
