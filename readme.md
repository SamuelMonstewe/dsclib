## Benchmarks

### Test Environment
* **CPU:** 11th Gen Intel(R) Core(TM) i5-11300H (3.10 GHz base / up to 4.40 GHz boost)
* **Cache:** L1d 192 KiB | L2 5 MiB | L3 8 MiB
* **Memory:** 8 GB DDR4 @ 3200 MHz (Dual-Channel)
* **OS:** Ubuntu 24.04.5 LTS
* **Compiler:** GCC 13.3.0 (`-O3 -march=native -Wall -g`)
* **Methodology:** 10 independent runs per input size ($n$), measured with `CLOCK_MONOTONIC`.

### Case 1: Sequential Insertion & Search (Worst-Case)

| $n$ | Average (s) | Median (s) | Max (s) | Min (s) | Std. Dev. (s) |
| :--- | :---: | :---: | :---: | :---: | :---: |
| $10^2$ | *pending* | *pending* | *pending* | *pending* | *pending* |
| $10^3$ | *pending* | *pending* | *pending* | *pending* | *pending* |
| $10^4$ | *pending* | *pending* | *pending* | *pending* | *pending* |
| $10^5$ | *pending* | *pending* | *pending* | *pending* | *pending* |
| $10^6$ | 0.254050 | 0.254079 | 0.257079 | 0.252074 | 0.001536 |
| $10^7$ | 3.293463 | 3.288591 | 3.325073 | 3.269255 | 0.019374 |
