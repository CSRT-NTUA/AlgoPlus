#pragma once
#ifndef MAT_1D_H
#define MAT_1D_H

#ifdef __cplusplus
#include <iostream>
#include <cstdint>
#include <climits>
#include <optional>
#include "../algorithms/sorting/quick_sort.h"
#endif


/**
*@brief Class for 1-dimensional Matrix
*
*/
template <typename T, size_t SIZE> class Mat1d{
private:
  T *arr;
  size_t __size;

public:

  /**
  *@brief constructor for Mat1d class
  *
  */
  explicit Mat1d(std::vector<T> v = {}) : __size(SIZE) {
    arr = new T[__size];
    if(!v.empty()){
      try{
        if(v.size() != __size){
          throw std::logic_error("Initializer array don't have the same size as the constructed array");
        }
        else{
          for(size_t i = 0; i<__size; i++){
            arr[i] = v[i];
          }
        }
      }
      catch(std::logic_error &e){
        std::cerr << e.what() << '\n';
      }
    }
  }


  /**
  *@brief constructor for Mat1d class with input value
  *@param val the value that we want all the elements of the array to have
  *@return Mat1d&
  */
  explicit Mat1d(const T val) noexcept {
    for(size_t i = 0; i<__size; ++i){
      arr[i] = val;
    }
    return *(this);
  }

  /**
   *@brief copy constructor for Mat1d class
   *@param mat the matrix we want to copy
   *@return Mat1d
   */
  explicit Mat1d(Mat1d &mat) : __size(SIZE) {
    try{
      if(mat.size() != __size){
        throw std::logic_error("Tried to copy matrixes with different sizes");
      }
      this -> arr = new T[__size];
      for(size_t i = 0; i<__size; i++){
        this->arr[i] = mat.arr[i];
      }
    }
    catch(std::logic_error &e){
      std::cerr << e.what() << '\n';
    }
  }

  /**
  *@brief copy constructor for Mat1d class
  *@param mat the matrix we want to copy
  *@return Mat1d&
  */
  Mat1d & operator =(Mat1d &mat){
    try{
      if(mat.size() != this -> __size){
        throw std::logic_error("Tried to copy matrixes with different sizes");
      }
      this -> __size = mat.size();
      for(size_t i = 0; i<__size; i++){
        this -> arr[i] = mat.arr[i]; 
      }
      return *(this);
    }
    catch(std::logic_error &e){
      std::cerr << e.what() << '\n';
    }
  }

  /**
  *@brief destructor of Mat1d class
  *
  */
  ~Mat1d(){ 
    delete [] arr;
  }

  /**
  *@brief size function
  *@return size_t the size of the array 
  *
  */
  size_t size(){
    return this->__size;
  }

  class Iterator;

  /**
   *@brief Iterator begin for Mat1d class
   *
   */
  Iterator begin(){
    return Iterator(0, __size, arr);
  }

  /**
   *@brief Iterator end for Mat1d class
   *
   */
  Iterator end(){
    return Iterator(__size , __size, arr);
  }

  /**
   *@brief operator[] for Mat1d class
   *@return T the value of the array to that index
   */
  T & operator [](const size_t index){
    try{
      if(index >= __size){
        throw std::invalid_argument("index out of bounds");
      }
      return arr[index];
    }
    catch(std::invalid_argument &e){
      std::cerr << e.what() << '\n';
    }
  } 

  /**
   *@brief sorting function
   *
   */
  void sort();

  /**
  *@brief operator << for Mat1d class
  *@param mat the matrix
  *
  */
  friend std::ostream & operator <<(std::ostream &out, const Mat1d &mat){
    out << '[';
    for(size_t i = 0; i<mat.size; i++){
      out << mat[i];
      if(i != mat.size() - 1){
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
  size_t __size;
  size_t index;
  T *arr;

public:
  /**
   * @brief Construct a new Iterator object
   *
   * @param __size size of the array
   * @param mat the matrix we have
   */
  explicit Iterator(size_t __index, size_t __size, T *__arr) noexcept : index(__index), __size(__size){
    arr = new T[__size];
    for(size_t i = 0; i<__size; i++){
      arr[i] = __arr[i];
    }
  }

  /**
   * @brief = operator for Iterator type
   *
   * @param curr the current array
   * @return Iterator&
   */
  Iterator &operator=(T *curr) {
    for(size_t i = 0; i<__size; i++){
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
    if (index < __size) {
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
   * @return true if the 2 arrays contains the same elements in the current index 
   * @return false otherwise
   */
  bool operator!=(const Iterator &it) { 
    return it.arr[it.index] != arr[index];
  }

  /**
   * @brief operator * for type Iterator
   *
   * @return T the value of the array to that index 
   */
  T operator*() { return arr[index]; }
};


#endif
