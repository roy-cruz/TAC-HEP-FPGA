# Homework 2

Note: For all of this work, we used `xcvu13p-fsga2577-2-e` with a clock period of `25 ns`.

Part: 
Clock: `25 ns`

## Question 2

Q2. Develop a C/C++ program to sort an array of 16 elements. You may choose any sorting algorithm (e.g., bubble sort, selection sort, insertion sort, or merge sort or write your own sorter). Use Vitis/Vivado HLS to perform `C Simulation (C-Sim)` and `C Synthesis (C-Synth)` and report the results.


### Solution

For this implementation, no pragmas were used, allowing the HLT tool to attempt default pilepining. The synthesis results reveal an Initiation Interval of 16, which matches the Iteration Latency of 16. This indicates that iterations are executing sequentially with no overlap, meaning the loop is not effectively pipelined.

The accompanying synthesis warnings indentify the bottleneck as a combination of carried dependencies and limited memory ports on the input array. To seolve this, the array could be partitioned to allow simultaneous access to all elements, and the loop should be unrolled to create dedicated hardware comparators. While the current design meets the 25 ns clock requirement and latency goals, these optimizations could significantly improve throughput.

```
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+----+-----------+-----------+-----+
|      Modules      | Issue|       | Latency |  Latency  | Iteration|         | Trip |          |      |    |           |           |     |
|      & Loops      | Type | Slack | (cycles)|    (ns)   |  Latency | Interval| Count| Pipelined| BRAM | DSP|     FF    |    LUT    | URAM|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+----+-----------+-----------+-----+
|+ sort             |    II|  16.67|      257|  6.425e+03|         -|      256|     -|    rewind|     -|   -|  489 (~0%)|  493 (~0%)|    -|
| o VITIS_LOOP_4_1  |    II|  18.25|      255|  6.375e+03|        16|       16|    16|       yes|     -|   -|          -|          -|    -|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+----+-----------+-----------+-----+
```

Pipelining warnings:

```bash
INFO: [SCHED 204-61] Pipelining loop 'VITIS_LOOP_4_1'.
WARNING: [HLS 200-880] The II Violation in module 'sort' (loop 'VITIS_LOOP_4_1'): Unable to enforce a carried dependence constraint (II = 1, distance = 1, offset = 1) between 'store' operation 0 bit ('in_r_addr_write_ln11', ../../src/hw2_sort.cpp:11) of variable 'temp', ../../src/hw2_sort.cpp:8 on array 'in_r' and 'load' operation 32 bit ('temp', ../../src/hw2_sort.cpp:8) on array 'in_r'.
Resolution: For help on HLS 200-880 see docs.xilinx.com/access/sources/dita/topic?Doc_Version=2024.1%20English&url=ug1448-hls-guidance&resourceid=200-880.html
WARNING: [HLS 200-885] The II Violation in module 'sort' (loop 'VITIS_LOOP_4_1'): Unable to schedule 'load' operation 32 bit ('temp', ../../src/hw2_sort.cpp:8) on array 'in_r' due to limited memory ports (II = 2). Please consider using a memory core with more ports or partitioning the array 'in_r'.
Resolution: For help on HLS 200-885 see docs.xilinx.com/access/sources/dita/topic?Doc_Version=2024.1%20English&url=ug1448-hls-guidance&resourceid=200-885.html
WARNING: [HLS 200-885] The II Violation in module 'sort' (loop 'VITIS_LOOP_4_1'): Unable to schedule 'load' operation 32 bit ('temp', ../../src/hw2_sort.cpp:8) on array 'in_r' due to limited memory ports (II = 3). Please consider using a memory core with more ports or partitioning the array 'in_r'.
Resolution: For help on HLS 200-885 see docs.xilinx.com/access/sources/dita/topic?Doc_Version=2024.1%20English&url=ug1448-hls-guidance&resourceid=200-885.html
WARNING: [HLS 200-885] The II Violation in module 'sort' (loop 'VITIS_LOOP_4_1'): Unable to schedule 'load' operation 32 bit ('in_r_load_10', ../../src/hw2_sort.cpp:8) on array 'in_r' due to limited memory ports (II = 4). Please consider using a memory core with more ports or partitioning the array 'in_r'.
Resolution: For help on HLS 200-885 see docs.xilinx.com/access/sources/dita/topic?Doc_Version=2024.1%20English&url=ug1448-hls-guidance&resourceid=200-885.html
WARNING: [HLS 200-885] The II Violation in module 'sort' (loop 'VITIS_LOOP_4_1'): Unable to schedule 'store' operation 0 bit ('in_r_addr_5_write_ln11', ../../src/hw2_sort.cpp:11) of variable 'temp', ../../src/hw2_sort.cpp:8 on array 'in_r' due to limited memory ports (II = 11). Please consider using a memory core with more ports or partitioning the array 'in_r'.
Resolution: For help on HLS 200-885 see docs.xilinx.com/access/sources/dita/topic?Doc_Version=2024.1%20English&url=ug1448-hls-guidance&resourceid=200-885.html
WARNING: [HLS 200-885] The II Violation in module 'sort' (loop 'VITIS_LOOP_4_1'): Unable to schedule 'store' operation 0 bit ('in_r_addr_13_write_ln11', ../../src/hw2_sort.cpp:11) of variable 'temp', ../../src/hw2_sort.cpp:8 on array 'in_r' due to limited memory ports (II = 15). Please consider using a memory core with more ports or partitioning the array 'in_r'.
Resolution: For help on HLS 200-885 see docs.xilinx.com/access/sources/dita/topic?Doc_Version=2024.1%20English&url=ug1448-hls-guidance&resourceid=200-885.html
```

## Question 3

Q3. Develop multiple versions of a simple computation kernel (e.g., vector addition, multiplication)  between corresponding elements of two arrays of size > 10. Implement using 
  - standard c/c++ data types (int, long, long long)
  - Arbitrary data types: (ap_int<M>, ap_uint<M>, ap_fixed<M>)
  - Compare the resource utilization between standard and arbitrary data types and ap_int and ap_uint, how much it changes and justify the change. 

### Solution

For this problem, a multiplication-accumulation kernel was made which iterates through two vectors of size 100, multiplying corresponding elements and adding the results to a global accumulator.

From the results obtained, the shift from the standard C++ types (`int`, `long`) to arbitrary precision types (`ap_int<6>` and `ap_uint<6>`) resulted in a significant reduction in resources. Specifically, the 6-bit `ap_int` version utilized only 33% of the DSPs and 63% of the LUTs compared to the 32-bit `int` type.

Moreover, comparing `ap_int<6>` and `ap_uint<6>` shows identical resources utilization. Because both types use the same number of bits, the hardware required for the multiplcation and addition remains the same regardless of whether the last bit is used a sign or a value bit.

We included an extreme case of `ap_int<1024>`. This version used 1889 DSPs, which is comparatively large, but expected for such a large bit-width. Looking at the performance metrics, we can see this had some impact since this large data type adds additional overhead. However, the kernel sill met the 25 ns latency requirements, but with a reduced slack.

**apint6**

```
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+----------+-----+
|      Modules      | Issue|       | Latency |  Latency  | Iteration|         | Trip |          |      |         |          |          |     |
|      & Loops      | Type | Slack | (cycles)|    (ns)   |  Latency | Interval| Count| Pipelined| BRAM |   DSP   |    FF    |    LUT   | URAM|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+----------+-----+
|+ vector_mult      |     -|  16.68|      105|  2.625e+03|         -|      106|     -|        no|     -|  1 (~0%)|  47 (~0%)|  86 (~0%)|    -|
| o VITIS_LOOP_6_1  |     -|  18.25|      103|  2.575e+03|         5|        1|   100|       yes|     -|        -|         -|         -|    -|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+----------+-----+
```

**apuint6**

```
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+----------+-----+
|      Modules      | Issue|       | Latency |  Latency  | Iteration|         | Trip |          |      |         |          |          |     |
|      & Loops      | Type | Slack | (cycles)|    (ns)   |  Latency | Interval| Count| Pipelined| BRAM |   DSP   |    FF    |    LUT   | URAM|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+----------+-----+
|+ vector_mult      |     -|  16.68|      105|  2.625e+03|         -|      106|     -|        no|     -|  1 (~0%)|  47 (~0%)|  86 (~0%)|    -|
| o VITIS_LOOP_6_1  |     -|  18.25|      103|  2.575e+03|         5|        1|   100|       yes|     -|        -|         -|         -|    -|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+----------+-----+
```

**int**

```
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+-----------+-----+
|      Modules      | Issue|       | Latency |  Latency  | Iteration|         | Trip |          |      |         |          |           |     |
|      & Loops      | Type | Slack | (cycles)|    (ns)   |  Latency | Interval| Count| Pipelined| BRAM |   DSP   |    FF    |    LUT    | URAM|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+-----------+-----+
|+ vector_mult      |     -|  13.21|      102|  2.550e+03|         -|      103|     -|        no|     -|  3 (~0%)|  76 (~0%)|  136 (~0%)|    -|
| o VITIS_LOOP_5_1  |     -|  18.25|      100|  2.500e+03|         2|        1|   100|       yes|     -|        -|         -|          -|    -|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+-----------+-----+
```

**long**

```
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+----------+-----------+-----------+-----+
|      Modules      | Issue|       | Latency |  Latency  | Iteration|         | Trip |          |      |          |           |           |     |
|      & Loops      | Type | Slack | (cycles)|    (ns)   |  Latency | Interval| Count| Pipelined| BRAM |    DSP   |     FF    |    LUT    | URAM|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+----------+-----------+-----------+-----+
|+ vector_mult      |     -|  11.09|      102|  2.550e+03|         -|      103|     -|        no|     -|  10 (~0%)|  140 (~0%)|  193 (~0%)|    -|
| o VITIS_LOOP_5_1  |     -|  18.25|      100|  2.500e+03|         2|        1|   100|       yes|     -|         -|          -|          -|    -|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+----------+-----------+-----------+-----+
```

**apint1024**

```
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+------------+------------+------------+-----+
|      Modules      | Issue|       | Latency |  Latency  | Iteration|         | Trip |          |      |            |            |            |     |
|      & Loops      | Type | Slack | (cycles)|    (ns)   |  Latency | Interval| Count| Pipelined| BRAM |     DSP    |     FF     |     LUT    | URAM|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+------------+------------+------------+-----+
|+ vector_mult      |     -|   8.20|      103|  2.575e+03|         -|      104|     -|        no|     -|  1889 (15%)|  2422 (~0%)|  1279 (~0%)|    -|
| o VITIS_LOOP_6_1  |     -|  18.25|      101|  2.525e+03|         3|        1|   100|       yes|     -|           -|           -|           -|    -|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+------------+------------+------------+-----+
```