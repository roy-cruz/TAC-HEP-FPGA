# Homework 1

## Resource utilization
Results
| Algorithm | URAM | LUT | FF | DSP48E | BRAM_18K |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Vector add** | 0 | 114 | 20 | 0 | 0 |
| **Matrix add** | 0 | 156 | 35 | 0 | 0 |
| **Matrix mult** | 0 | 274 | 79 | 3 | 0 |

Normalized to vector add where applicable

| Algorithm | URAM | LUT | FF | DSP48E | BRAM_18K |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Vector add** | - | 1.00 | 1.00 | - | - |
| **Matrix add** | - | 1.37 | 1.75 | - | - |
| **Matrix mult** | - | 2.40 | 3.95 | - | - |

## Latency

| Algorithm | Cycles | Cycles (Norm) |
| :--- | :---: | :---: |
| **Vector add** | 102 | 1 |
| **Matrix add** | 221 | 2.17 |
| **Matrix mult** | 2221 | 21.77 |