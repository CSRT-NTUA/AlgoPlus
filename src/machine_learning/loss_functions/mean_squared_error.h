#ifndef MEAN_SQUARED_ERROR_H
#define MEAN_SQUARED_ERROR_H

#ifdef __cplusplus
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#endif


namespace losses {
  float mean_squared_error(std::vector<float> const& y, std::vector<float> const& y_hat) {
    assert(y.size() == y_hat.size());
    size_t n = y.size();
    float mse = 0.0;
    for(size_t i = 0; i<n; i++) {
        mse += std::powf(y[i] - y_hat[i], 2);
    }
    return mse / float(n);
  }

  float root_mean_squared_error(std::vector<float> const& y, std::vector<float> const& y_hat) {
    return std::sqrt(mean_squared_error(y, y_hat));
  }
    
  float mean_absolute_error(std::vector<float> const& y, std::vector<float> const& y_hat) {
    assert(y.size() == y_hat.size());
    size_t n = y.size();
    float mae = 0.0;
    for(size_t i = 0; i<n; i++) {
        mae += std::abs(y[i] - y_hat[i]);
    }
    return mae / float(n);
  }

  float binary_crossentropy_loss(std::vector<float> const& y, std::vector<float> const& y_hat) {
    assert(y.size() == y_hat.size());
    size_t n = y.size();
    float bce = 0.0;
    for(size_t i = 0; i<n; i++) {
        bce += (y[i]*std::log(y_hat[i]) + (1-y[i])*std::log(1 - y_hat[i]));
    }
    return -(1/float(n))*bce;
  }

  float crossentropy_loss(std::vector<float> const& y, std::vector<float> const& y_hat) {
    assert(y.size() == y_hat.size());
    size_t n = y.size();
    float ce = 0.0;
    for(size_t i = 0; i<n; i++) {
        ce += y[i]*std::log(y_hat[i]);
    }
    return -(1/float(n))*ce;
  }
}


#endif

