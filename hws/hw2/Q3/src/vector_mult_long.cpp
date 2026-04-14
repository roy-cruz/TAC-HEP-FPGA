#include <iostream>
#define N 100

void vector_mult(long A[N], long B[N], long &C) {
    for (int i = 0; i < N; i++) {
        C += A[i] * B[i];
    }
}