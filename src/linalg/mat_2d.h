#pragma once
#ifndef MAT_2D_H
#define MAT_2D_H

#ifdef __cplusplus
#include "mat_1d.h"
#include <climits>
#include <iostream>
#include <vector>
#endif

/**
 *@brief Class for 2-dimensional Matrix
 *
 */

template <typename T, size_t ROWS, size_t COLS> class Mat2d {
private:
  T *arr;
  size_t __size;
  size_t __cols;
  size_t __rows;
  Mat1d<T, COLS> mat;

public:
  /**
   *@brief constructor for Mat2d class
   *
   */
  explicit Mat2d(std::vector<std::vector<T>> v = {})
      : __cols(COLS), __rows(ROWS), __size(ROWS * COLS) {
    arr = new T[ROWS * COLS];
    if (!v.empty()) {
      try {
        if (v.size() * v[0].size() != __size || v[0].size() != __cols ||
            v.size() != __rows) {
          throw std::logic_error("Initializer array don't have the same "
                                 "dimensions as the constructed array");
        }
        for (size_t i = 0; i < v.size(); i++) {
          for (size_t j = 0; j < v[0].size(); j++) {
            arr[i * v[0].size() + j] = v[i][j];
          }
        }
      } catch (std::logic_error &e) {
        std::cerr << e.what() << '\n';
      }
    }
  }

  ~Mat2d() { delete[] arr; }
  /**
   *@brief constructor for Mat2d class with initializer value
   *@param val the value that we want all the index of the array to have
   */
  explicit Mat2d(const T val) noexcept
      : __size(ROWS * COLS), __cols(COLS), __rows(ROWS) {
    arr = new T[__size];
    for (size_t i = 0; i < __size; i++) {
      arr[i] = val;
    }
  }

  /**
   *@brief copy constructor for Mat2d class
   *@param mat the 2d matrix we want to copy
   *
   */
  explicit Mat2d(const Mat2d &mat)
      : __size(ROWS * COLS), __cols(COLS), __rows(ROWS) {
    try {
      if (mat.size() != __size || mat.cols() != __cols ||
          mat.rows() != __rows) {
        throw std::logic_error(
            "Tried to copy matrixes with different dimensions");
      }
      this->arr = new T[__size];
      for (size_t i = 0; i < __size; i++) {
        this->arr[i] = mat.arr[i];
      }
    } catch (std::logic_error &e) {
      std::cerr << e.what() << '\n';
    }
  }

  /**
   *@brief operator = for Mat2d class
   *@param mat the matrix we want to copy
   *@return Mat2d&
   */
  Mat2d &operator=(Mat2d &mat) {
    if (this == &mat) {
      return *(this);
    }
    try {
      if (mat.size() != __size || mat.cols() != __cols || mat.rows != __rows) {
        throw std::logic_error(
            "Tried to copy matrixes with different dimensions");
      }
      for (size_t i = 0; i < __size; i++) {
        this->arr[i] = mat.arr[i];
      }
      return *(this);
    } catch (std::logic_error &e) {
      std::cerr << e.what() << '\n';
    }
  }

  /**
   *@brief operator (i, j) for Mat2d class
   *@param i index that's pointing to the row
   *@param j index that's pointing to the column
   *@return T the element of arr[i][j]
   */
  T &operator()(size_t i, size_t j) const { return arr[i * __cols + j]; }

  /**
   *@brief operator () for Mat2d class
   *@param i index that's pointing to the row
   *@return std::vector<T> the array of index i
   */
  Mat1d<T, COLS> &operator()(size_t i) {
    size_t index = 0;
    for (size_t j = i * __cols; j < i * __cols + __rows; j++) {
      mat[index++] = arr[j];
    }
    return mat;
  }

  /**
   *@brief size function
   *@return size_t the size of the matrix
   */
  size_t size() const { return __size; }

  /**
   *@brief cols function
   *@return size_t the number of elements in each column
   */
  size_t cols() const { return __cols; }

  /**
   *@brief rows function
   *@return size_t the number of elements in each row
   */
  size_t rows() const { return __rows; }

  class Iterator;

  /**
   *@brief begin() Iterator for Mat2d class
   *@return Iterator
   */
  Iterator begin() { return Iterator(arr, __rows, __cols, 0); }

  /**
   *@brief end() Iterator for Mat2d class
   *@return Iterator
   */
  Iterator end() { return Iterator(arr, __rows, __cols, __size); }

  /**
   *@brief operator << for Mat2d class
   */
  friend std::ostream &operator<<(std::ostream &out, Mat2d &mat) {
    out << '[';
    for (size_t i = 0; i < mat.rows(); i++) {
      out << '[';
      for (size_t j = 0; j < mat.cols(); j++) {
        out << mat.arr[i * mat.cols() + j];
        if (j != mat.cols() - 1) {
          out << " ";
        }
      }
      out << ']';
      if (i != mat.rows() - 1) {
        out << '\n';
      }
    }
    out << ']';
    return out;
  }
};

/**
 *@brief Iterator for Mat2d class
 */
template <typename T, size_t ROWS, size_t COLS>
class Mat2d<T, ROWS, COLS>::Iterator {
private:
  T *arr;
  size_t __rows;
  size_t __cols;
  size_t __index;
  size_t __size;
  Mat1d<T, COLS> mat;

public:
  /**
   *@brief constructor for Iterator class
   *@param __arr the input array
   *@param rows the number of rows of the matrix
   *@param cols the number of columns of the matrix
   *@param index the current index, if it's begin() then 0, if it's end() then
   *__size
   */
  explicit Iterator(T *__arr, size_t rows, size_t cols, size_t index) noexcept
      : __rows(rows), __cols(cols), __index(index) {
    __size = rows * cols;
    arr = new T[__size];
    for (size_t i = 0; i < __size; i++) {
      arr[i] = __arr[i];
    }
  }

  /**
   *@brief operator = for Iterator class
   *@param curr the current array
   *@return Iterator&
   */
  Iterator &operator=(T *curr) {
    for (size_t i = 0; i < __size; i++) {
      arr[i] = curr[i];
    }
    return *(this);
  }

  /**
   *@brief operator ++ for Iterator class
   *@return Iterator&
   */
  Iterator &operator++() {
    if (this->__index < __size) {
      this->__index++;
    }
    return *(this);
  }

  /**
   *@param operator ++ for Iterator class
   *@return Iterator&
   */
  Iterator &operator++(int) {
    Iterator it = *(this);
    ++*(this);
    return it;
  }

  /**
   *@brief operator -- for Iterator class
   *@return Iterator&
   */
  Iterator &operator--() {
    if (this->__index > 0) {
      this->__index--;
    }
    return *(this);
  }

  /**
   *@brief operator -- for Iterator class
   *@return Iterator&
   */
  Iterator &operator--(int) {
    Iterator it = *(this);
    --*(this);
    return it;
  }

  /**
   *@brief operator != for Iterator class
   *@return true if the elements of the array in the current index is not equal
   *@return false otherwise
   */
  bool operator!=(const Iterator &it) {
    return it.arr[it.index] != arr[this->index];
  }

  /**
   *@brief operator * for Iterator class
   *@return Mat1d<T, COLS> the 1-Dimensional Matrix in the current row
   */
  Mat1d<T, COLS> operator*() {
    size_t index = 0;
    for (size_t j = this->__index * __cols; j < this->__index * __cols + __rows;
         ++j) {
      mat[index++] = arr[j];
    }
    return mat;
  }
};
#endif
