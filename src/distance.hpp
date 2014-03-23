#pragma once

#include "array.hpp"

class distance {
	int** table;
	const int MaxN, MaxM;
  
 public:
  distance(int max);
  ~distance();
  
	template <class T> 
  int operator()(const array<T> &ar1, const array<T> &ar2) {
    const int n1 = ar1.size, n2 = ar2.size;
    if (n1 >= MaxN || n2 >= MaxM)
      throw "not enough memory - too big words";
    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        if (ar1[i - 1] == ar2[j - 1])
          table[i][j] = table[i - 1][j - 1];
        else {
          table[i][j] = table[i - 1][j - 1] + 1;
          if (table[i][j] > table[i - 1][j] + 1)
            table[i][j] = table[i - 1][j] + 1;
          if (table[i][j] > table[i][j - 1] + 1)
            table[i][j] = table[i][j - 1] + 1;
        }
      }
    }
    return table[n1][n2];
  }
};