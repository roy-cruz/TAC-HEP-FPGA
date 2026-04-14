#define  N 16

void sort (int in[N]) {
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            // Even
            for (int j = 0; j < N - 1; j += 2) {
                if (in[j] > in[j+1]) {
                    int temp = in[j];
                    in[j] = in[j+1];
                    in[j+1] = temp;
                }
            }
        } else {
            // Odd
            for (int j = 1; j < N - 1; j += 2) {
                if (in[j] > in[j+1]) {
                    int temp = in[j];
                    in[j] = in[j+1];
                    in[j+1] = temp;
                }
            }
        }
    }
}