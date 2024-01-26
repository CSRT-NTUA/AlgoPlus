#ifndef LCS_H
#define LCS_H

#ifdef __cplusplus
#include <iostream>
#include <string>
#endif

int lcs(std::string a, std::string b) {
  int m = a.length(), n = b.length();
  int res[m + 1][n + 1];
  int trace[20][20];

  for (int i = 0; i < m + 1; i++) {
    for (int j = 0; j < n + 1; j++) {
      res[i][j] = 0;
      trace[i][j] = 0;
    }
  }

  for (int i = 0; i < m + 1; ++i) {
    for (int j = 0; j < n + 1; ++j) {
      if (i == 0 || j == 0) {
        res[i][j] = 0;
        trace[i][j] = 0;
      }

      else if (a[i - 1] == b[j - 1]) {
        res[i][j] = 1 + res[i - 1][j - 1];
        trace[i][j] = 1;

      } else {
        if (res[i - 1][j] > res[i][j - 1]) {
          res[i][j] = res[i - 1][j];
          trace[i][j] = 2;
        } else {
          res[i][j] = res[i][j - 1];
          trace[i][j] = 3;
        }
      }
    }
  }
  return res[m][n];
}

#endif