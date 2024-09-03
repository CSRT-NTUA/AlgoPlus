#define CATCH_CONFIG_MAIN
#include "../../../src/machine_learning/loss_functions/losses.h"
#include "../../../third_party/catch.hpp"

using namespace losses;

TEST_CASE("Testing mean squared error") {

  std::vector<double> v1 { 1.23, 4.25, 4.4, 1.231, 5.567 };
  std::vector<double> v2 { 4.56, 4.123, 1.234, 6.432, 5.555 };
  
  REQUIRE(mean_squared_error(v1, v2) == Approx(9.6358263926).epsilon(1e-6));
}

TEST_CASE("Testing mean absolute error") {
  std::vector<double> v1 { 1.23, 4.25, 4.4, 1.231, 5.567 };
  std::vector<double> v2 { 4.56, 4.123, 1.234, 6.432, 5.555 };
  
  REQUIRE(mean_absolute_error(v1, v2) == Approx(2.36720).epsilon(1e-6));
}

TEST_CASE("Testing binary crossentropy loss") {
  std::vector<double> v1 { 0., 0., 0., 0., 1., 0., 0., 0., 0., 1. };
  std::vector<double> v2 { 1.8055,  0.9193, -0.2527,  1.0489,  0.5396, -1.2046, -0.9479,  0.8274,
        -0.0548, -0.1902 };

  REQUIRE(binary_crossentropy_loss(v1, v2) == Approx(0.8834657559).epsilon(1e-6));
}

