# AA

## Project Overview
This repository contains C++ lab assignments organized by lab number. Each lab folder includes source code and compiled binaries for different algorithms and programming exercises.

## Folder Structure

- `Lab2/` — Prime checking algorithm
- `Lab3/` — Minimum cut algorithm
- `Lab4/` — Ford-Fulkerson algorithm
- `Lab5/` — String matching algorithms
- `Lab6/` — String matching (alternate)
- `Lab7/` — Closest pair and intersection algorithms
- `Lab8/` — Graham scan algorithm
- `Lab9/` — Euler check algorithm
- `Lab10/` — (empty or new lab)

## Build Instructions

You can build individual C++ files using the provided VS Code tasks:

- **g++ build active file**: Compiles the currently open C++ file using g++.
- **g++-13 build active file**: Compiles the currently open C++ file using g++-13.

To build manually, run:

```bash
g++ -g <source_file.cpp> -o <output_binary>
```

Replace `<source_file.cpp>` with your file and `<output_binary>` with the desired output name.

## Notes
- Each lab folder may contain multiple source files and binaries.
- No central build system (like CMake or Makefile) is used; builds are per-file.