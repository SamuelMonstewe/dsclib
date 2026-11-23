## Benchmarks

### Scope & Status

This benchmark suite currently evaluates **only the `MAP` structure** (backed by a Red-Black Tree implementation in `dsclib.h`).

#### Implemented
- Generic `PAIR` definition and `MAP` generation macros (`NEW_MAP`, `MAP_INSERT`, `MAP_SEARCH`)
- Red-Black Tree insertion, rotations, and fix-up balancing with a `nil` sentinel node
- Benchmark harness measuring sequential insertion and search (`CLOCK_MONOTONIC`)

#### Roadmap / Pending
- **Deletion (`MAP_DELETE` / RB-Delete):** removal of keys while preserving Red-Black Tree invariants
- **Memory cleanup (`FREE_MAP` / `DESTROY_MAP`):** freeing all allocated tree nodes, `nil`, and the map struct
- **Duplicate keys policy:** define whether inserting an existing key updates `.second`, is ignored, or is allowed
- **Additional benchmarks:** separate insertion, search, and deletion across both sequential and random workloads, plus other `dsclib` structures (`SET`, etc.)

### Test Environment
- **CPU:** 11th Gen Intel(R) Core(TM) i5-11300H (3.10 GHz base / up to 4.40 GHz boost)
- **Cache:** L1d 192 KiB | L2 5 MiB | L3 8 MiB
- **Memory:** 8 GB DDR4 @ 1600 MHz (3200 MT/s)
- **OS:** Ubuntu 24.04.5 LTS
- **Compiler:** GCC 13.3.0 (`-O2 -march=native -Wall -g`)
- **Methodology:** 10 independent runs per input size ($n$), measured with `CLOCK_MONOTONIC`.

### Case 1: Sequential Insertion & Search (Worst-Case)

| $n$ | Average (s) | Median (s) | Max (s) | Min (s) | Std. Dev. (s) |
| :--- | :---: | :---: | :---: | :---: | :---: |
| $10^2$ | *pending* | *pending* | *pending* | *pending* | *pending* |
| $10^3$ | *pending* | *pending* | *pending* | *pending* | *pending* |
| $10^4$ | *pending* | *pending* | *pending* | *pending* | *pending* |
| $10^5$ | *pending* | *pending* | *pending* | *pending* | *pending* |
| $10^6$ | 0.254050 | 0.254079 | 0.257079 | 0.252074 | 0.001536 |
| $10^7$ | 3.293463 | 3.288591 | 3.325073 | 3.269255 | 0.019374 |
