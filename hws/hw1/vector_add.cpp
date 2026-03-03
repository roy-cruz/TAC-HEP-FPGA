#include <iostream>
#define SIZE 100

void vector_add(int A[SIZE], int B[SIZE], int C[SIZE]) {

    for (int i = 0; i < SIZE; i++) {
#pragma HLS PIPELINE II=1
        C[i] = A[i] + B[i];
    }
}

