# Parallel Graph Coloring Project

## Introduction
This project aims to explore and analyze various graph coloring algorithms with a focus on parallelization. Graph coloring is a well-known problem in discrete mathematics, where each vertex of a graph must be assigned a color such that no two adjacent vertices share the same color. The challenge is to minimize the number of colors used while maintaining this property, a problem known to be NP-complete.

## Objectives
1. **Implement and compare:** Several graph coloring algorithms, including a baseline Greedy algorithm and parallelized versions such as JonesPlassmann and Luby.
2. **Performance analysis:** Measure the speed, efficiency, and memory usage of each algorithm across different graphs and thread counts.
3. **Data consolidation:** Consolidate and analyze performance metrics, producing insights and visualizations.

## Directory Structure

- **`Benchmarks/`:** Contains CSV files with performance metrics for different algorithms and configurations.
- **`Charts_And_Graphs/`:** Holds generated images showing performance metrics and comparisons.
- **`Data_Cleaning_And_Manipulation/`:** Python scripts for processing and analyzing data along with their CSV outputs:
  - **`data_consolidation.py`:** Consolidates individual CSV files into a single dataset.
  - **`comparison_metrics.py`:** Calculates speedup and efficiency metrics.
  - **`visualization.py`:** Generates visualizations based on the consolidated dataset.
- **`src/`:** Source code, divided into the following directories:
  - **`Helpers/`:** Contains libraries for parallelization and benchmarking, including:
    - **`Performance.h`:** Measures performance and outputs results to a CSV.
    - **`TimeLog.h`:** Logs the time taken by an algorithm.
    - **`Split_Range.hpp`:** Splits a range into non-overlapping sub-ranges for parallel processing.
    - **`ParallelProcessing.hpp`:** Allows parallel execution of functions on a vector.
    - **`Graph.h` & `Graph.cpp`:** Manages the graph, including loading from `.gra` and `.graph` files, and providing key methods for graph manipulation.
  - **`Algorithms/`:** Implements graph coloring algorithms, including:
    - **`Greedy`:** Sequential algorithm using a simple greedy strategy.
    - **`JP`:** Implements the Jones & Plassmann algorithm.
    - **`Luby`:** Implements the Luby algorithm.
- **`Tests/`:** Contains test graphs used in benchmarking algorithms.
- **`assets/`:** Additional resources for the project.

### Building the Project:

1. **Compile the code:**
  
   Navigate to the project directory and run the following commands:

   ```bash
   mkdir build && cd build
   cmake ..
   make

## Running the Code
### Prerequisites:
- **C++:** Ensure you have a C++ compiler installed.
- **Python:** Ensure Python is installed, along with packages: `pandas`, `matplotlib`, and `seaborn`.

### Executing Algorithms:
- **Greedy:**

  ```bash
  ./main --algo greedy --graph <graph_file> --out <output_csv>

- **JonesPlassmann:**
  ./main --algo jp --graph <graph_file> --threads <2, 4, 8> --out <output_csv>

- **Luby:**
  ./main --algo luby --graph <graph_file> --threads <2, 4, 8> --out <output_csv>

- **Python scripts:**
  - python3 data_consolidation.py
  - python3 comparison_metrics.py
  - python3 visualization.py






  
