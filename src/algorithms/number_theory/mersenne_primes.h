#ifndef MERSENNE_PRIMES_H
#define MERSENNE_PRIMES_H

#ifdef __cplusplus
#include "eratosthenes_sieve.h"
#include <iostream>
#endif

/*
 *mersenne function.
 *@param n: the upper bound
 *Returns vector<int>: the vector includes the elements "p" from m = 2^p - 1 for
 *which p gives us a mersenne prime number.
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