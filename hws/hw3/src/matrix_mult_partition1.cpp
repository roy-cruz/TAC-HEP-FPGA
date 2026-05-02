#include <iostream>
#define N 6

void matrix_mult(int A[N][N], int B[N][N], int C[N][N]) {
  #pragma HLS interface m_axi port=A depth=36
  #pragma HLS interface m_axi port=B depth=36
  #pragma HLS interface m_axi port=C depth=36
  #pragma HLS interface s_axilite port=return

  #pragma HLS array_partition variable=A complete dim=2
  #pragma HLS array_partition variable=B complete dim=1
  #pragma HLS array_partition variable=C complete dim=2

  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j) {
      C[i][j]=0;
      for (size_t k = 0; k < N; ++k) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
