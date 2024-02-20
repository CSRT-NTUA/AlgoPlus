#include "../../../src/linalg/mat_1d.h"
#include "../../catch2/catch.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <random>


TEST_CASE("testing destructor for Mat1d"){
  Mat1d<int, 5> mat;
  mat[4] = 5;
  REQUIRE(mat[4] == 5);
}

TEST_CASE("testing default constructor of mat_1d"){
  Mat1d<int, 5> mat;
  for(int i = 0; i<mat.size(); i++){
    mat[i] = 10;
  }

  std::vector<int> v(5, 10);
  std::vector<int> check;
  for(int i = 0; i<mat.size(); i++){
    check.push_back(mat[i]);
  }
  REQUIRE(v == check);

  Mat1d<char, 10> mat2({'a','b','c','d','e','f','g','h','i','j'});
  std::vector<char> v2 = {'a','b','c','d','e','f','g','h','i','j'};
  std::vector<char> check2;
  for(int i = 0; i<mat2.size(); i++){
    check2.push_back(mat2[i]);
  }
  REQUIRE(v2 == check2);
}

TEST_CASE("testing copy constructor of mat_1d"){
  Mat1d<int, 5> mat1;
  for(int i = 0; i<mat1.size(); ++i){
    mat1[i] = i + 1;
  }

  Mat1d<int, 5> mat2(mat1);
  std::vector<int> v1 ,v2;
  for(int i = 0; i<mat1.size(); i++){
    v1.push_back(mat1[i]);
    v2.push_back(mat2[i]);
  }
  REQUIRE(v1 == v2);

  Mat1d<char, 5> mat3;
  for(int i = 0; i<mat3.size(); i++){
    mat3[i] = 'a';
  }

  Mat1d<char, 5> mat4;
  mat4 = mat3;

  std::vector<int> v3, v4;
  for(int i = 0; i<mat3.size(); i++){
    v3.push_back(mat3[i]);
    v4.push_back(mat4[i]);
  }
  REQUIRE(v3 == v4);
}

TEST_CASE("testing iterators for Mat1d class"){
  Mat1d<char, 5> mat({'a','b','c','d','e'});
  std::vector<char> v = {'a','b','c','d','e'};
  std::vector<char> check;
  for(auto it = mat.begin(); it != mat.end(); it++){
    check.push_back(*(it));
  }
  REQUIRE(v == check);

  Mat1d<std::string, 5> mat2({"hello", "world", "we", "are", "csrt"});
  std::vector<std::string> v2 = {"hello", "world", "we", "are", "csrt"};
  std::vector<std::string> check2;
  for(auto it = mat2.begin(); it != mat2.end(); it++){
    check2.push_back(*(it));
  }
  REQUIRE(v2 == check2);
}


