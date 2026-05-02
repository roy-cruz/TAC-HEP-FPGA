#include <iostream>
#define N 10

void vector_mult(int A[N], int B[N], int &C) {
    #pragma HLS interface s_axilite port=C
    #pragma HLS interface m_axi port=A depth=N
    #pragma HLS interface m_axi port=B depth=N
    #pragma HLS interface s_axilite port=return

    #pragma HLS ARRAY_PARTITION variable=A block factor=2
    #pragma HLS ARRAY_PARTITION variable=B block factor=2

    for (int i = 0; i < N; i++) {
        C += A[i] * B[i];
    }
}