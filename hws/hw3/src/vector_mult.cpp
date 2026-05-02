#include <iostream>
#define N 10

void vector_mult(int A[N], int B[N], int &C) {
    #pragma HLS interface s_axilite port=C
    #pragma HLS interface m_axi port=A depth=N
    #pragma HLS interface m_axi port=B depth=N
    #pragma HLS interface s_axilite port=return

    for (int i = 0; i < N; i++) {
        C += A[i] * B[i];
    }
}