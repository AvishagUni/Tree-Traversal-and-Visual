# Tree Visualization and Traversal

This project implements a **k-ary tree data structure** with support for multiple data types, various tree traversal methods, and visualization using **Graphviz**. It demonstrates how to build and traverse trees, visualize their structure, and work with diverse node values, including integers, strings, and complex numbers.

---

## 📋 Features

### 1. Tree Structure
- Implements a **k-ary tree** where each node can have up to `k` children.
- Nodes support different types of values, including integers, strings, and custom complex numbers.

### 2. Tree Traversals
- **In-order**, **Pre-order**, **Post-order** (for binary trees)
- **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** for k-ary trees

### 3. Tree Visualization
- Visualizes the tree structure as PNG images using Graphviz, providing a graphical view of the tree.

### 4. Complex Number Support
- Includes a custom `Complex` class, demonstrating the tree’s flexibility in handling various data types.

---

## 📂 Project Structure

- **main.cpp**: Contains the main function and demonstrations of tree functionalities.
- **tests.cpp**: Includes test cases to verify the correctness of tree operations.
- **tree.hpp**: Header file for the tree data structure implementation.
- **tree_printer.hpp**: Header file for tree visualization using Graphviz.
- **node.hpp**: Header file defining the tree node structure.
- **complex.hpp**: Header file for the custom `Complex` class used in tree nodes.

---

## 🛠 Dependencies

- **Graphviz**: Required for converting DOT files to PNG images for tree visualization.

---

## 🔍 Demonstrations

### Binary Tree (Doubles)
- **In-order Scan**: `1.4, 1.2, 1.5, 3.1, 3.6, 4.3`
- **Pre-order Scan**: `3.1, 2.2, 1.4, 2.5, 4.3, 3.6`
- **Post-order Scan**: `1.4, 2.5, 2.2, 3.6, 4.3, 3.1`
- **BFS Scan**: `3.1, 2.2, 4.3, 1.4, 2.5, 3.6`
- **DFS Scan**: `3.1, 2.2, 1.4, 2.5, 4.3, 3.6`

### 3-ary Tree (Doubles)
- **DFS Scan**: `3.1, 2.2, 1.4, 2.5, 4.3, 3.6`
- **BFS Scan**: `3.1, 2.2, 4.3, 1.4, 2.5, 3.6`

### Binary Tree (Integers)
- **BFS Scan**: `10, 20, 30, 40, 50, 60, 70, 80, 90, 100`
- **In-order Scan**: `40, 20, 50, 10, 60, 30, 70, 80, 90, 100`

### String Tree
- **Root**: `"alpha"`
- **Children**: `"beta"`, `"gamma"`
- **Subchildren**: `"delta"`, `"epsilon"` (under `"beta"`)

### Complex Tree
- **DFS Scan**: `(1.0, 1.1), (-2.2, -2.2), (-5.5, 1.5), (6.6, 0), (0.3, -1.3), (7.7, 1), (8.8, 1.8), (4.4, 4.4)`

---

## 🚀 Getting Started

### Requirements
- **C++ Compiler**: Ensure C++11 or higher.
- **Graphviz**: Install Graphviz to enable PNG generation from DOT files.

### Compilation
To compile the project, run:
```bash
g++ -std=c++11 -o tree_demo main.cpp tests.cpp tree.cpp node.cpp complex.cpp

