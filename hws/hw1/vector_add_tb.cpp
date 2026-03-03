#include <iostream>
#include <cstdlib>
#define SIZE 100

// Function prototype
void vector_add(int A[SIZE], int B[SIZE], int C[SIZE]);

int main() {

    int A[SIZE];
    int B[SIZE];
    int C[SIZE];

    // Initialize inputs
    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = 2*i;
    }

    // Call DUT
    vector_add(A, B, C);

    // Verify results
    int errors = 0;
    for (int i = 0; i < SIZE; i++) {
        if (C[i] != A[i] + B[i]) {
            errors++;
        }
    }

    if (errors == 0)
        std::cout << "TEST PASSED\n";
    else
        std::cout << "TEST FAILED\n";

    return errors;
}

