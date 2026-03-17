#include <vector>
#include <iostream>
#include <ap_int.h>
#include "hls_vector.h"
 
#define  totalNumWords 512
// unsigned char data_t;
typedef unsigned char data_t;

// Prototype of functions
void compute (data_t in[totalNumWords], data_t Out[totalNumWords]);
void check_results(data_t in[totalNumWords], data_t Out[totalNumWords]);
 
int main(int, char**) {
    // initialize input vector arrays on CPU
    data_t in[totalNumWords], Out[totalNumWords];
    // initialize the input data
    for (int i = 0; i < totalNumWords; i++) {
      in[i] = i;
      Out[i] = 0;
    }
    compute(in, Out);
    check_results(in, Out);
}

void check_results(data_t in[totalNumWords], data_t Out[totalNumWords]) {
  for (int i = 0; i < totalNumWords; i++) {
    data_t expected = (in[i] * 3 + 25) + (in[i] * 3 * 2) * 2;
    if (Out[i] != expected) {
      std::cout << "Error at index " << i << ": Expected " << expected << ", but got " << Out[i] << std::endl;
      return;
    }
  }
  std::cout << "All results are correct!" << std::endl;
}
