#include <iostream>
#include <cstdlib>
#define N 10

// Function prototype
void vector_mult(int A[N], int B[N], int &C);

int main() {

    int A[N];
    int B[N];
    int C = 0;

    // Initialize inputs
    for (int i = 0; i < N; i++) {
        A[i] = i;
        B[i] = 2*i;
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