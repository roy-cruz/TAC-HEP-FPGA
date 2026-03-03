#include <iostream>
#define N 10

void matrix_mult(int A[N][N], int B[N][N], int C[N][N]) {
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j) {


      C[i][j]=0;
      for (size_t k = 0; k < N; ++k) {
	C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

}
