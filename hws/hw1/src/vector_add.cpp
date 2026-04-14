#include <iostream>
#define N 100

void vector_add(int A[N], int B[N], int C[N]) {
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }
}

