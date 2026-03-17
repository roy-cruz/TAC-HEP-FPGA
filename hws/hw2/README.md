# Homework 2

## Instructions
- Run [`lex6-ex01.cpp`](./lex6-ex01.cpp) using Vitis and share your conclusion.
- Write a program to sort 16 object and run it with Vitis.

## Results

## Running Code
In order to synthesize `lex6-ex01.cpp`, certain aspects needed to be fixed, included the lack of array initialization and an incorrect type definition. Moreover, the code was refactor in order to construct a testbench file for Vitis to use. The exact nature of all of these changes can be visualized here: [link](https://github.com/roy-cruz/TAC-HEP-FPGA/commit/590bc89e4de2f2028dd65fb7bd5adfd3adb8a3b8).

The reports resulting from the synthesis and co-simulation of the implementation can be foind in [part1/reports](./part1/reports).

## Sorting Algorithm

The sorting algorithm implemented was a simple odd-even sort. The code can be found [here](./part2/src/hw2_sort.cpp), the accompanying test bench [here](./part2/src/hw2_sort_tb.cpp) and the reports [here](./part2/reports/). In the implementation, we used the HLS array pragma to fully partition the input array into seperate registers, removing memory port bottlenecks. Along with this, the pipeline pragma with `II=1` was used on the outer loop to optimize data throughput. Finally, the loops inside the algorithm were unrolled using the `HLS UNROLL` pragma to parallelize the comparisons and swaps.