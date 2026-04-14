#include <iostream>
#define N 100

void matrix_add(int A[N][N], int B[N][N], int C[N][N]);

int main() {

    int A[N][N];
    int B[N][N];
    int C[N][N];

    // Initialize matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0;
        }
    }

    // Call DUT
    matrix_add(A, B, C);

    // Verify
    int errors = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (C[i][j] != A[i][j] + B[i][j]) {
                errors++;
            }
        }
    }

    if (errors == 0)
        std::cout << "TEST PASSED\n";
    else
        std::cout << "TEST FAILED\n";

    return errors;
}

