#include <iostream>
#include <cstdlib>
#include <ap_int.h>
#define N 100

// Function prototype
void vector_mult(ap_int<6> A[N], ap_int<6> B[N], ap_int<16> &C);

int main() {

    ap_int<6> A[N];
    ap_int<6> B[N];
    ap_int<16> C = 0;

    // Initialize inputs
    for (int i = 0; i < N; i++) {
        A[i] = 1;
        B[i] = 1;
    }

    // Call DUT
    vector_mult(A, B, C);

    // Verify results
    int errors = 0;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        temp += A[i] * B[i];
    }
    if (C != temp) {
        errors++;
    }

    if (errors == 0)
        std::cout << "TEST PASSED\n";
    else
        std::cout << "TEST FAILED\n";

    return errors;
}