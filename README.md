# MAQAO Metrics Analysis

This repository contains various linear algebra algorithms, including dot product and LU decomposition, used to evaluate the relevance of MAQAO's metrics. MAQAO (Modular Assembly Quality Analyzer and Optimizer) is a profiling tool designed to provide detailed performance reports, including time spent in each function, optimization tips, hardware information, and more.

## Prerequisites

Before using this repository, ensure that you have MAQAO installed. You can download and install it from the [official MAQAO website](https://maqao.org/).

## Usage

To analyze the performance of the algorithms with MAQAO, follow these steps for each directory:

1. Run the following command:
    ```sh
    maqao OV -R1 -c=config.json
    ```
2. Open the link provided by MAQAO in your web browser to view the detailed performance report.

## Repository Structure

The repository is structured as follows:

- `dotprod/`: Contains several implementations of the dot product algorithm.
- `lu/`: Contains several implementations of the LU decomposition algorithm.

Each directory includes the necessary source code files and instructions specific to the algorithm as well as a `config.json` file, a configuration file for MAQAO.
