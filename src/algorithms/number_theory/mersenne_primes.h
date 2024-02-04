#ifndef MERSENNE_PRIMES_H
#define MERSENNE_PRIMES_H

#ifdef __cplusplus
#include "eratosthenes_sieve.h"
#include <iostream>
#endif

/**
 * @brief mersenne prime function
 *
 * @param n the upper bound
 * @return std::vector<int> the total mersenne primes till the upper bound n
 */
std::vector<int> mersenne(int64_t n) {
  std::vector<bool> prime = soe(n);
  std::vector<int> elements;
  int64_t k = 2;
  while ((1 << k) - 1 <= n) {
    if (prime[(1 << k) - 1]) {
      elements.push_back(k);
    }
    k++;
  }
  return elements;
}
#endif