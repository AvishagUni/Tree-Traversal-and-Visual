README
Tree Visualization and Traversal

This project demonstrates the implementation of a k-ary tree data structure, various tree traversal methods, and visualization using Graphviz. The tree can contain nodes with different types of values, such as integers, strings, and complex numbers.
Features

    Tree Structure: Implementation of a k-ary tree where each node can have up to k children.
    Tree Traversals: Includes in-order, pre-order, post-order, BFS, and DFS traversals.
    Tree Visualization: Uses Graphviz to visualize the tree structure as PNG images.
    Complex Number Support: Demonstrates the use of a custom Complex class within the tree.

Files

    main.cpp: Contains the main function and demonstration of the tree functionalities.
    tests.cpp: Contains various test functions to ensure the correctness of the tree operations.
    tree.hpp: Header file for the tree implementation.
    tree_printer.hpp: Header file for the tree visualization using Graphviz.
    node.hpp: Header file for the tree node implementation.
    complex.hpp: Header file for the custom Complex class.

Dependencies

    Graphviz: Required for generating PNG images from DOT files.
    
Demonstrations
Binary Tree (Doubles)

    In-order Scan: 1.4, 1.2, 1.5, 3.1, 3.6, 4.3
    Pre-order Scan: 3.1, 2.2, 1.4, 2.5, 4.3, 3.6
    Post-order Scan: 1.4, 2.5, 2.2, 3.6, 4.3, 3.1
    BFS Scan: 3.1, 2.2, 4.3, 1.4, 2.5, 3.6
    DFS Scan: 3.1, 2.2, 1.4, 2.5, 4.3, 3.6

3-ary Tree (Doubles)

    DFS Scan: 3.1, 2.2, 1.4, 2.5, 4.3, 3.6
    BFS Scan: 3.1, 2.2, 4.3, 1.4, 2.5, 3.6

Binary Tree (Integers)

    BFS Scan: 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    In-order Scan: 40, 20, 50, 10, 60, 30, 70, 80, 90, 100

String Tree

    Root: "alpha"
    Children: "beta", "gamma"
    Subchildren: "delta", "epsilon" (under "beta")

Complex Tree

    DFS Scan: (1.0, 1.1), (-2.2, -2.2), (-5.5, 1.5), (6.6, 0), (0.3, -1.3), (7.7, 1), (8.8, 1.8), (4.4, 4.4)

Conclusion

This project demonstrates the implementation and visualization of a k-ary tree data structure with various traversal methods. The project includes a comprehensive set of tests to ensure the correctness of the tree operations and showcases the versatility of the tree with different data types.
