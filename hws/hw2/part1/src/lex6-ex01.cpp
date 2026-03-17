#include <vector>
#include <iostream>
#include <ap_int.h>
#include "hls_vector.h"
 
#define  totalNumWords 512
unsigned char data_t;
 
int main(int, char**) {
    // initialize input vector arrays on CPU
    for (int i = 0; i < totalNumWords; i++) {
      in[i] = i;
    }
    compute(data_t in[totalNumWords], data_t Out[totalNumWords]);
    check_results();
}
 
void compute (data_t in[totalNumWords ], data_t Out[totalNumWords ]) {
  data_t tmp1[totalNumWords], tmp2[totalNumWords];
  A: for (int i = 0; i < totalNumWords ; ++i) {    
    tmp1[i] = in[i] * 3;
    tmp2[i] = in[i] * 3;
  }
  B: for (int i = 0; i < totalNumWords ; ++i) {    
    tmp1[i] = tmp1[i] + 25;
  }
  C: for (int i = 0; i < totalNumWords ; ++i) {  
    tmp2[i] = tmp2[i] * 2;
 }
  D: for (int i = 0; i <  totalNumWords ; ++i) {    
     out[i] = tmp1[i] + tmp2[i] * 2;
   }
}
