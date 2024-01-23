#ifdef __cplusplus
#include <iostream>
#endif

#ifndef GCD_H
#define GCD_H

namespace gcd {

/*
 *binary_gcd function.
 *@param a: first element.
 *@param b: second element.
 *Returns the gcd(a,b).
 */
int64_t binary_gcd(const int64_t a, const int64_t b) {
  if (a == b) {
    return a;
  }
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }

  if (~a & 1) {
    if (~b & 1) {
      return binary_gcd(a >> 1, b >> 1) << 1;
    } else {
      return binary_gcd(a >> 1, b);
    }
  }
  if (~b & 1) {
    return binary_gcd(a, b >> 1);
  }

  if (a > b) {
    return binary_gcd((a - b) >> 1, b);
  }
  return binary_gcd((b - a) >> 1, a);
}

/*
 *euclidean_gcd function.
 *@param a: first element.
 *@param b: second element.
 *Returns the gcd(a,b).
 */
int64_t euclidean_gcd(int64_t a, int64_t b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
  return (a + b);
}

}; // namespace gcd

#endif