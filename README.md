README
Project Title: Tree Visualization with Qt

This project implements a tree data structure in C++ with various traversal methods and a GUI-based visualization using Qt. The tree can store elements of different types, including user-defined types like complex numbers. The project includes the necessary classes to create, manipulate, and visualize k-ary trees (where each node can have up to k children).

Classes and Methods
Tree Class

The Tree class represents a generic k-ary tree.
Methods:

    void add_root(Node<T>& node): Adds the root node to the tree.
    void add_sub_node(Node<T>& parent_node, Node<T>& child_node): Adds a child node to a specified parent node.
    void print(): Displays the tree structure using a GUI.

Iterators:

    Pre-Order Iterator: Traverses the tree in pre-order.
    Post-Order Iterator: Traverses the tree in post-order.
    In-Order Iterator: Traverses the tree in in-order (binary trees only).
    BFS Iterator: Traverses the tree using breadth-first search.
    DFS Iterator: Traverses the tree using depth-first search.
    Heap Iterator: Converts the tree into a min-heap and traverses it.

Node Class

The Node class represents a node in the tree.
Methods:

    T get_value(): Returns the value stored in the node.
    void add_child(Node<T>* child): Adds a child node.

TreePrinter Class

The TreePrinter class visualizes the tree structure using Qt.
Methods:

    void print(Tree<T, K>& tree): Prints the tree using Qt's graphics view.

Complex Class

The Complex class represents complex numbers for demonstration purposes.
Methods:

    Complex(double real, double imag): Constructor to initialize a complex number.
    std::string toString(): Returns a string representation of the complex number.
