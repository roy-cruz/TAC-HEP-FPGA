# Homework 2

Note: For all of this work, we used `xcvu13p-fsga2577-2-e` with a clock period of `25 ns`.

Part: 
Clock: `25 ns`

## Question 2

Q2. Develop a C/C++ program to sort an array of 16 elements. You may choose any sorting algorithm (e.g., bubble sort, selection sort, insertion sort, or merge sort or write your own sorter). Use Vitis/Vivado HLS to perform `C Simulation (C-Sim)` and `C Synthesis (C-Synth)` and report the results.


### Solution

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

For this implementation, no pragmas were used, allowing the HLT tool to attempt default pilepining. The synthesis results reveal an Initiation Interval of 16, which matches the Iteration Latency of 16. This indicates that iterations are executing sequentially with no overlap, meaning the loop is not effectively pipelined.

The accompanying synthesis warnings indentify the bottleneck as a combination of carried dependencies and limited memory ports on the input array. To seolve this, the array could be partitioned to allow simultaneous access to all elements, and the loop should be unrolled to create dedicated hardware comparators. While the current design meets the 25 ns clock requirement and latency goals, these optimizations could significantly improve throughput.

## Question 3

Q3. Develop multiple versions of a simple computation kernel (e.g., vector addition, multiplication)  between corresponding elements of two arrays of size > 10. Implement using 
  - standard c/c++ data types (int, long, long long)
  - Arbitrary data types: (ap_int<M>, ap_uint<M>, ap_fixed<M>)
  - Compare the resource utilization between standard and arbitrary data types and ap_int and ap_uint, how much it changes and justify the change. 

### Solution

The part and clock speed used are:

Part: `xcvu13p-fsga2577-2-e`
Clock: `25 ns`



