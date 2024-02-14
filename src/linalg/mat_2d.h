#pragma once
#ifndef MAT_2D_H
#define MAT_2D_H

#ifdef __cplusplus
#include <iostream>
#include <vector>
#include <climits>
#include "mat_1d.h"
#endif


/**
 *@brief Class for 2-dimensional Matrix 
 *
 */

template <typename T, size_t ROWS, size_t COLS> class Mat2d{
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
  explicit Mat2d(std::vector<std::vector<T> > v = {}) : __cols(COLS), __rows(ROWS), __size(ROWS*COLS){
    arr = new T[ROWS*COLS];
    if(!v.empty()){
      try{
        if(v.size() * v[0].size() != __size || v[0].size() != __cols || v.size() != __rows){
          throw std::logic_error("Initializer array don't have the same dimensions as the constructed array");
        }
        for(size_t i = 0; i<v.size(); i++){
          for(size_t j = 0; j<v[0].size(); j++){
            arr[i*v[0].size() + j] = v[i][j];
          }
        }
      }
      catch(std::logic_error &e){
        std::cerr << e.what() << '\n';
      }
    }
  }

  ~Mat2d(){
    delete [] arr;
  }
  /**
  *@brief constructor for Mat2d class with initializer value
  *@param val the value that we want all the index of the array to have
  */
  explicit Mat2d(const T val) noexcept : __size(ROWS*COLS), __cols(COLS), __rows(ROWS){
    arr = new T[__size];
    for(size_t i = 0; i<__size; i++){
      arr[i] = val;
    }
  }
  
  /**
  *@brief copy constructor for Mat2d class
  *@param mat the 2d matrix we want to copy
  *
  */
  explicit Mat2d(const Mat2d &mat) : __size(ROWS*COLS), __cols(COLS), __rows(ROWS){
    try{
      if(mat.size() != __size || mat.cols() != __cols || mat.rows() != __rows){
        throw std::logic_error("Tried to copy matrixes with different dimensions");
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
  *@brief operator = for Mat2d class
  *@param mat the matrix we want to copy
  *@return Mat2d&
  */
  Mat2d & operator =(Mat2d &mat){
   if(this == &mat){
      return *(this);
    }
   try{
      if(mat.size() != __size || mat.cols() != __cols || mat.rows != __rows){
        throw std::logic_error("Tried to copy matrixes with different dimensions");
      }
      for(size_t i = 0; i<__size; i++){
        this->arr[i] = mat.arr[i];
      } 
      return *(this);
    } 
    catch(std::logic_error &e){
      std::cerr << e.what() << '\n';
    }
  }
  
  /**
   *@brief operator (i, j) for Mat2d class
   *@param i index that's pointing to the row 
   *@param j index that's pointing to the column 
   *@return T the element of arr[i][j]
   */
  T & operator ()(size_t i, size_t j){
    return arr[i*__cols + j];
  }
  
  /**
   *@brief operator () for Mat2d class
   *@param i index that's pointing to the row
   *@return std::vector<T> the array of index i
   */
  Mat1d<T, COLS> & operator()(size_t i){
    for(size_t j = i*__cols; j<i*__cols + __rows; j++){
      mat[j] = arr[j];
    }
    return mat;
  }
  
  /**
  *@brief size function
  *@return size_t the size of the matrix
  */
  size_t size(){
    return __size;
  }

  /**
  *@brief cols function
  *@return size_t the number of elements in each column
  */
  size_t cols(){
    return __cols;
  }

  /**
  *@brief rows function
  *@return size_t the number of elements in each row
  */
  size_t rows(){
    return __rows;
  }

  friend std::ostream & operator <<(std::ostream &out, Mat2d &mat){
    out << '[';
    for(size_t i = 0; i<mat.rows(); i++){
      out << '[';
      for(size_t j = 0; j<mat.cols(); j++){
        out << mat.arr[i*mat.cols() + j];
        if(j != mat.cols() - 1){
          out << " ";
        }
      }
      out << ']';
      if(i != mat.rows() - 1){
        out << '\n';
      }
    }
    out << ']';
    return out;
  }
  
};

#endif
