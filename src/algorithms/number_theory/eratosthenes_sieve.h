#pragma once
#ifndef ERATOSTHENES_SIEVE_H
#define ERATOSTHENES_SIEVE_H

#ifdef __cplusplus
#include <assert.h>
#include <iostream>
#include <vector>

#include <cinttypes>
#endif

/**
 * @brief eratosthenes sieve function(sieve of eratosthenes)
 *
 * @param n upper bound
 * @return std::vector<std::uint8_t> if arr[i] = 1 then i is prime
 */
std::vector<std::uint8_t> soe(std::size_t n) {
  assert(n != 0);
  std::vector<std::uint8_t> prime(n + 1, 1);
  for (std::size_t p = 2; p * p <= n; ++p) {
    if (prime[p]) {
      for (std::size_t i = p * p; i <= n; i += p) {
        prime[i] = 0;
      }
    }
  }
  return prime;
}

#endif
