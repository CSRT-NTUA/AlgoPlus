#pragma once
#ifndef LAPLACIAN_PYRAMID_H
#define LAPLACIAN_PYRAMID_H


#ifdef __cplusplus
#include <iostream>
#include <vector>
#endif


class GKernel{
private:
  double a;

public:

  GKernel(double a) : a(a) {}

  std::vector<double> return_kernel() {
    std::vector<double> temp = {1/4 - a/2, 1/4, a, 1/4 , 1/4 - a/2};
    return temp * temp
  }

};

#endif
