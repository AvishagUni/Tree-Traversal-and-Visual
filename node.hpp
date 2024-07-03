// minnesav@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <iostream>

template <typename T>
class Node {
public:
    T value;
    std::vector<Node<T>*> children;

    /**
     * @brief Constructs a new Node object with the given value.
     *
     * @param val The value to be stored in the node.
     */
    Node(T val) : value(val) {}

    /**
     * @brief Returns a reference to the value.
     * 
     * @tparam T The type of the value.
     * @return T& A reference to the value.
     */
    T& get_value() {  // Returning a reference to the value
        return value;
    }

    /**
     * @brief Retrieves the value stored in the node.
     * 
     * This function returns a constant reference to the value stored in the node.
     * It is marked as const to ensure const correctness.
     * 
     * @return const T& The value stored in the node.
     */
    const T& get_value() const {  // For const correctness
        return value;
    }

    /**
     * @brief Adds a child to the node.
     * 
     * This function adds a child node to the current node. The child node is added to the end of the list of children.
     * 
     * @param child A pointer to the child node to be added.
     */
    void add_child(Node<T>* child) { // Add a child to the node
        children.push_back(child);
    }
};

#endif // NODE_HPP


