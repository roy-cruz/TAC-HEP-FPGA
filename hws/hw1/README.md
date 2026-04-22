# Homework 1

## Question 1
Q1. Develop C/C++ programs to implement the following operations:

  a. Vector addition 
  b. Vector multiplication
  c. Matrix addition 
  d. Matrix multiplication

You may use the templates provided in the lecture04 directory as a starting point. Use Vitis/Vivado HLS to perform `C Simulation (C-Sim)` and `C Synthesis (C-Synth)`. Use at least 10 elements for each of above case. 

For each of the four implementations:
- Finally, compare the results across all four categories and discuss your observations.

### Solution

The part and clock used are:

Part: `xcvu13p-fsga2577-2-e`
Clock: `25 ns`

The following are the performance and resource estimates reports provided by Vitis for each of the implementations:

#### Matrix addition

```
+----------------------------------+------+-------+---------+-----------+----------+---------+-------+----------+------+---------+----------+-----------+-----+
|              Modules             | Issue|       | Latency |  Latency  | Iteration|         |  Trip |          |      |         |          |           |     |
|              & Loops             | Type | Slack | (cycles)|    (ns)   |  Latency | Interval| Count | Pipelined| BRAM |   DSP   |    FF    |    LUT    | URAM|
+----------------------------------+------+-------+---------+-----------+----------+---------+-------+----------+------+---------+----------+-----------+-----+
|+ matrix_add                      |    II|  14.87|    10005|  2.501e+05|         -|    10000|      -|    rewind|     -|  1 (~0%)|  68 (~0%)|  224 (~0%)|    -|
| o VITIS_LOOP_5_1_VITIS_LOOP_6_2  |     -|  18.25|    10003|  2.501e+05|         5|        1|  10000|       yes|     -|        -|         -|          -|    -|
+----------------------------------+------+-------+---------+-----------+----------+---------+-------+----------+------+---------+----------+-----------+-----+
```

#### Matrix multiplication

```
+-------------------------------------------------+------+-------+---------+-----------+----------+---------+---------+----------+------+---------+-----------+-----------+-----+
|                     Modules                     | Issue|       | Latency |  Latency  | Iteration|         |   Trip  |          |      |         |           |           |     |
|                     & Loops                     | Type | Slack | (cycles)|    (ns)   |  Latency | Interval|  Count  | Pipelined| BRAM |   DSP   |     FF    |    LUT    | URAM|
+-------------------------------------------------+------+-------+---------+-----------+----------+---------+---------+----------+------+---------+-----------+-----------+-----+
|+ matrix_mult                                    |    II|  11.70|  1000005|  2.500e+07|         -|  1000000|        -|    rewind|     -|  4 (~0%)|  289 (~0%)|  573 (~0%)|    -|
| o VITIS_LOOP_5_1_VITIS_LOOP_6_2_VITIS_LOOP_8_3  |     -|  18.25|  1000003|  2.500e+07|         5|        1|  1000000|       yes|     -|        -|          -|          -|    -|
+-------------------------------------------------+------+-------+---------+-----------+----------+---------+---------+----------+------+---------+-----------+-----------+-----+
```

#### Vector addition

```
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+----+----------+-----------+-----+
|      Modules      | Issue|       | Latency |  Latency  | Iteration|         | Trip |          |      |    |          |           |     |
|      & Loops      | Type | Slack | (cycles)|    (ns)   |  Latency | Interval| Count| Pipelined| BRAM | DSP|    FF    |    LUT    | URAM|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+----+----------+-----------+-----+
|+ vector_add       |    II|  16.17|      102|  2.550e+03|         -|      100|     -|    rewind|     -|   -|  18 (~0%)|  107 (~0%)|    -|
| o VITIS_LOOP_5_1  |     -|  18.25|      100|  2.500e+03|         2|        1|   100|       yes|     -|   -|         -|          -|    -|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+----+----------+-----------+-----+
```

#### Vector multiplication

```
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+-----------+-----+
|      Modules      | Issue|       | Latency |  Latency  | Iteration|         | Trip |          |      |         |          |           |     |
|      & Loops      | Type | Slack | (cycles)|    (ns)   |  Latency | Interval| Count| Pipelined| BRAM |   DSP   |    FF    |    LUT    | URAM|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+-----------+-----+
|+ vector_mult      |     -|  13.21|      102|  2.550e+03|         -|      103|     -|        no|     -|  3 (~0%)|  76 (~0%)|  136 (~0%)|    -|
| o VITIS_LOOP_5_1  |     -|  18.25|      100|  2.500e+03|         2|        1|   100|       yes|     -|        -|         -|          -|    -|
+-------------------+------+-------+---------+-----------+----------+---------+------+----------+------+---------+----------+-----------+-----+
```