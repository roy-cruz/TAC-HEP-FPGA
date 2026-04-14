#include <iostream>
#define N 100

void vector_mult(int A[N], int B[N], int &C) {
    for (int i = 0; i < N; i++) {
        C += A[i] * B[i];
    }
}