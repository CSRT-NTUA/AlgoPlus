#include "../../../src/linalg/mat_2d.h"
#include "../../catch2/catch.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <random>

TEST_CASE("testing default constructor for Mat2d class"){
  Mat2d<int, 5, 5> mat;
  for(int i = 0; i<5; i++){
    for(int j = 0; j<5; j++){
      mat(i, j) = i + j;
    }
  }

  REQUIRE(mat(0,0) == 0);
  REQUIRE(mat(1,1) == 2);
  REQUIRE(mat(4,3) == 7);
  REQUIRE(mat(4,4) == 8);

  Mat2d<char, 5, 5> mat2({{'a','b','c','d','e'}, {'a','b','c','d','e'}, {'a','b','c','d','e'},{'a','b','c','d','e'}, {'a','b','c','d','e'}});
  Mat1d<char, 5> check({'a','b','c','d','e'});
  bool ww = mat2(0) == check;
  REQUIRE(ww == true);
  
}


