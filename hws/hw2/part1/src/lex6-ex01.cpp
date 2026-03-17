#define  totalNumWords 512
typedef unsigned char data_t;

void compute (data_t in[totalNumWords], data_t Out[totalNumWords]) {
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
     Out[i] = tmp1[i] + tmp2[i] * 2;
   }
}