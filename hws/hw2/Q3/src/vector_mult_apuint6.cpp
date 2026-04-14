#include <iostream>
#include <ap_int.h>
#define N 100

void vector_mult(ap_uint<6> A[N], ap_uint<6> B[N], ap_uint<16> &C) {
    for (int i = 0; i < N; i++) {
        C += A[i] * B[i];
    }
}