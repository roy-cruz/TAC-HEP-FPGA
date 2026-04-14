#include <vector>
#include <iostream>
#include <ap_int.h>
#include "hls_vector.h"
 
#define N 16

void sort (int in[N]);
void print_arr(int in[N]);
void check_results(int in[N]);
 
int main() {
    // initialize input vector arrays on CPU with random data
    int in[N];
    for (int i = 0; i < N; i++) {
        in[i] = rand() % 100; // Random data between 0 and 99
    }

    print_arr(in);
    sort(in);
    print_arr(in);
    check_results(in);
}

void print_arr(int in[N]) {
    for (int i = 0; i < N; i++) {
        std::cout << in[i] << " ";
    }
    std::cout << std::endl;
}

void check_results(int in[N]) {
    for (int i = 0; i < N - 1; i++) {
        if (in[i] > in[i + 1]) {
            std::cerr << "Error: Array is not sorted at index " << i << std::endl;
            return;
        }
    }
    std::cout << "All results are correct!" << std::endl;
}
