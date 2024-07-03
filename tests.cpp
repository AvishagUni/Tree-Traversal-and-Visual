#include <iostream>
#include <cassert>
#include "tree.hpp"
#include "complex.hpp"

// Function to test adding a root to the tree
void test_add_root() {
    std::cout << "Running test_add_root..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    tree.add_root(*root_node);
    assert(tree.getRoot() != nullptr);
    assert(tree.getRoot()->get_value() == root_complex);
    std::cout << "test_add_root passed!" << std::endl;
    delete root_node; // Clean up
}

// Function to test adding child nodes to the tree
void test_add_sub_node() {
    std::cout << "Running test_add_sub_node..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex child_complex(2.0, 3.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* child_node = new Node<Complex>(child_complex);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *child_node);
    assert(tree.getRoot()->children.size() == 1);
    assert(tree.getRoot()->children[0]->get_value() == child_complex);
    std::cout << "test_add_sub_node passed!" << std::endl;
    delete root_node; // Clean up
    delete child_node; // Clean up
}

// Function to test pre-order traversal
void test_pre_order_traversal() {
    std::cout << "Running test_pre_order_traversal..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Complex c2(3.0, 4.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    Node<Complex>* n2 = new Node<Complex>(c2);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);
    tree.add_sub_node(*root_node, *n2);

    std::vector<Complex> result;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "Pre-order traversal result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex.toString() << std::endl;
    }

    assert(result[0] == root_complex);
    assert(result[1] == c1);
    assert(result[2] == c2);
    std::cout << "test_pre_order_traversal passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
    delete n2; // Clean up
}

// Function to test post-order traversal
void test_post_order_traversal() {
    std::cout << "Running test_post_order_traversal..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Complex c2(3.0, 4.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    Node<Complex>* n2 = new Node<Complex>(c2);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);
    tree.add_sub_node(*root_node, *n2);

    std::vector<Complex> result;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "Post-order traversal result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex.toString() << std::endl;
    }

    assert(result[0] == c1);
    assert(result[1] == c2);
    assert(result[2] == root_complex);
    std::cout << "test_post_order_traversal passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
    delete n2; // Clean up
}

// Function to test in-order traversal (binary tree specific)
void test_in_order_traversal() {
    std::cout << "Running test_in_order_traversal..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Complex c2(3.0, 4.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    Node<Complex>* n2 = new Node<Complex>(c2);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);
    tree.add_sub_node(*root_node, *n2);

    std::vector<Complex> result;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "In-order traversal result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex.toString() << std::endl;
    }

    assert(result[0] == c1);
    assert(result[1] == root_complex);
    assert(result[2] == c2);
    std::cout << "test_in_order_traversal passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
    delete n2; // Clean up
}

// Function to test BFS traversal
void test_bfs_traversal() {
    std::cout << "Running test_bfs_traversal..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Complex c2(3.0, 4.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    Node<Complex>* n2 = new Node<Complex>(c2);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);
    tree.add_sub_node(*root_node, *n2);

    std::vector<Complex> result;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "BFS traversal result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex.toString() << std::endl;
    }

    assert(result[0] == root_complex);
    assert(result[1] == c1);
    assert(result[2] == c2);
    std::cout << "test_bfs_traversal passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
    delete n2; // Clean up
}

// Function to test DFS traversal
void test_dfs_traversal() {
    std::cout << "Running test_dfs_traversal..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Complex c2(3.0, 4.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    Node<Complex>* n2 = new Node<Complex>(c2);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);
    tree.add_sub_node(*root_node, *n2);

    std::vector<Complex> result;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "DFS traversal result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex.toString() << std::endl;
    }

    assert(result[0] == root_complex);
    assert(result[1] == c1);
    assert(result[2] == c2);
    std::cout << "test_dfs_traversal passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
    delete n2; // Clean up
}

void test_heap_traversal() {
    std::cout << "Running test_heap_traversal..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(3.0, 4.0);
    Complex c1(1.0, 2.0);
    Complex c2(2.0, 3.0);
    Node<Complex> root_node(root_complex);
    Node<Complex> n1(c1);
    Node<Complex> n2(c2);
    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);

    std::vector<Complex> result;
    for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it) {
        std::cout << "Heap traversal: Current node value: " << *it << std::endl;
        result.push_back(*it);
    }

    // Debug print
    std::cout << "Heap traversal result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex << std::endl;
    }

    assert(result[0] == c1);
    assert(result[1] == c2);
    assert(result[2] == root_complex);
    std::cout << "test_heap_traversal passed!" << std::endl;
}

// Function to test finding a node
void test_find_node() {
    std::cout << "Running test_find_node..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Complex c2(3.0, 4.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    Node<Complex>* n2 = new Node<Complex>(c2);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);
    tree.add_sub_node(*root_node, *n2);

    Node<Complex>* found = tree.find(tree.getRoot(), c2);
    assert(found != nullptr);
    assert(found->get_value() == c2);
    std::cout << "test_find_node passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
    delete n2; // Clean up
}

// Function to test clearing the tree
void test_clear_tree() {
    std::cout << "Running test_clear_tree..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Complex c2(3.0, 4.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    Node<Complex>* n2 = new Node<Complex>(c2);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);
    tree.add_sub_node(*root_node, *n2);

    tree.clear();
    assert(tree.getRoot() == nullptr);
    std::cout << "test_clear_tree passed!" << std::endl;
}

// Function to test adding multiple children
void test_add_multiple_children() {
    std::cout << "Running test_add_multiple_children..." << std::endl;
    Tree<Complex, 3> tree; // Specify a 3-ary tree
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Complex c2(3.0, 4.0);
    Complex c3(4.0, 5.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    Node<Complex>* n2 = new Node<Complex>(c2);
    Node<Complex>* n3 = new Node<Complex>(c3);
    tree.add_root(*root_node);
    std::cout << "Adding first child..." << std::endl;
    tree.add_sub_node(*root_node, *n1);
    std::cout << "Adding second child..." << std::endl;
    tree.add_sub_node(*root_node, *n2);
    std::cout << "Adding third child..." << std::endl;
    tree.add_sub_node(*root_node, *n3);

    assert(tree.getRoot()->children.size() == 3);
    assert(tree.getRoot()->children[0]->get_value() == c1);
    assert(tree.getRoot()->children[1]->get_value() == c2);
    assert(tree.getRoot()->children[2]->get_value() == c3);
    std::cout << "test_add_multiple_children passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
    delete n2; // Clean up
    delete n3; // Clean up
}

// Function to test tree with custom node values
void test_tree_with_custom_values() {
    std::cout << "Running test_tree_with_custom_values..." << std::endl;
    Tree<int> tree;
    Node<int>* root_node = new Node<int>(1);
    Node<int>* n1 = new Node<int>(2);
    Node<int>* n2 = new Node<int>(3);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);
    tree.add_sub_node(*root_node, *n2);

    std::vector<int> result;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "BFS traversal with custom values result:" << std::endl;
    for (const auto& value : result) {
        std::cout << value << std::endl;
    }

    assert(result[0] == 1);
    assert(result[1] == 2);
    assert(result[2] == 3);
    std::cout << "test_tree_with_custom_values passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
    delete n2; // Clean up
}

// Function to test in-order traversal with one child
void test_in_order_one_child() {
    std::cout << "Running test_in_order_one_child..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);

    std::vector<Complex> result;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "In-order traversal with one child result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex.toString() << std::endl;
    }

    assert(result[0] == c1);
    assert(result[1] == root_complex);
    std::cout << "test_in_order_one_child passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
}

// Function to test post-order traversal with one child
void test_post_order_one_child() {
    std::cout << "Running test_post_order_one_child..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);

    std::vector<Complex> result;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "Post-order traversal with one child result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex.toString() << std::endl;
    }

    assert(result[0] == c1);
    assert(result[1] == root_complex);
    std::cout << "test_post_order_one_child passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
}

// Function to test BFS traversal with one child
void test_bfs_one_child() {
    std::cout << "Running test_bfs_one_child..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);

    std::vector<Complex> result;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "BFS traversal with one child result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex.toString() << std::endl;
    }

    assert(result[0] == root_complex);
    assert(result[1] == c1);
    std::cout << "test_bfs_one_child passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
}

// Function to test DFS traversal with one child
void test_dfs_one_child() {
    std::cout << "Running test_dfs_one_child..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);

    std::vector<Complex> result;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "DFS traversal with one child result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex.toString() << std::endl;
    }

    assert(result[0] == root_complex);
    assert(result[1] == c1);
    std::cout << "test_dfs_one_child passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
}

// Function to test pre-order traversal with one child
void test_pre_order_one_child() {
    std::cout << "Running test_pre_order_one_child..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(1.0, 2.0);
    Complex c1(2.0, 3.0);
    Node<Complex>* root_node = new Node<Complex>(root_complex);
    Node<Complex>* n1 = new Node<Complex>(c1);
    tree.add_root(*root_node);
    tree.add_sub_node(*root_node, *n1);

    std::vector<Complex> result;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        result.push_back((*it)->get_value());
    }

    // Debug print
    std::cout << "Pre-order traversal with one child result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex.toString() << std::endl;
    }

    assert(result[0] == root_complex);
    assert(result[1] == c1);
    std::cout << "test_pre_order_one_child passed!" << std::endl;
    delete root_node; // Clean up
    delete n1; // Clean up
}

void test_heap_one_child() {
    std::cout << "Running test_heap_one_child..." << std::endl;
    Tree<Complex> tree;
    Complex root_complex(2.0, 3.0);
    Complex c1(1.0, 2.0);
    Node<Complex> root_node(root_complex);
    Node<Complex> n1(c1);
    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);

    std::vector<Complex> result;
    for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it) {
        result.push_back(*it);
    }

    // Debug print
    std::cout << "Heap traversal with one child result:" << std::endl;
    for (const auto& complex : result) {
        std::cout << complex << std::endl;
    }

    assert(result[0] == c1);
    assert(result[1] == root_complex);
    std::cout << "test_heap_one_child passed!" << std::endl;
}

// Function to test complex number equality
void test_complex_equality() {
    std::cout << "Running test_complex_equality..." << std::endl;
    Complex c1(1.0, 2.0);
    Complex c2(1.0, 2.0);
    Complex c3(2.0, 3.0);
    assert(c1 == c2);
    assert(!(c1 == c3));
    std::cout << "test_complex_equality passed!" << std::endl;
}

// Function to test complex number string representation
void test_complex_to_string() {
    std::cout << "Running test_complex_to_string..." << std::endl;
    Complex c1(1.0, 2.0);
    assert(c1.toString() == "(1.000000, 2.000000)");
    std::cout << "test_complex_to_string passed!" << std::endl;
}

#ifdef RUN_TESTS
// Main function to run all tests
int main() {
    test_add_root();
    test_add_sub_node();
    test_pre_order_traversal();
    test_post_order_traversal();
    test_in_order_traversal();
    test_bfs_traversal();
    test_dfs_traversal();
    test_heap_traversal();
    test_find_node();
    test_clear_tree();
    test_add_multiple_children();
    test_tree_with_custom_values();
    test_in_order_one_child();
    test_post_order_one_child();
    test_bfs_one_child();
    test_dfs_one_child();
    test_pre_order_one_child();
    test_heap_one_child();
    test_complex_equality();
    test_complex_to_string();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
#endif





