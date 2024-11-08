// minnesav@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include <queue>
#include <stack>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "tree_printer.hpp"

// Template class for k-ary tree
template <typename T, int K = 2>
class Tree {
private:
    Node<T>* root;  // Root node of the tree

public:
    // Constructor
    Tree() : root(nullptr) {}

    // Destructor
    ~Tree() {
        clear();
    }

    // Add root node
    void add_root(Node<T>& node) {
        if (!root) {
            root = new Node<T>(node.value);
        } else {
            root->value = node.value;
        }
    }

    // Add a child node to a parent node
    void add_sub_node(Node<T>& parent_node, Node<T>& child_node) {
        Node<T>* parent = find(root, parent_node.value);
        if (parent == nullptr || parent->children.size() >= K) {
            throw std::runtime_error("Parent node not found or maximum children exceeded.");
        }
        Node<T>* new_child = new Node<T>(child_node.value);
        parent->add_child(new_child);
    }

    // Find a node with the given value
    Node<T>* find(Node<T>* node, T value) {
        if (!node) return nullptr;
        if (node->value == value) return node;
        for (Node<T>* child : node->children) {
            Node<T>* result = find(child, value);
            if (result) return result;
        }
        return nullptr;
    }

    // Clear the tree
    void clear() {
        clear(root);
        root = nullptr;
    }

    // Clear a node and its children
    void clear(Node<T>* node) {
        if (!node) return;
        for (Node<T>* child : node->children) {
            clear(child);
        }
        delete node;
    }

    // Get the root node
    Node<T>* getRoot() const {
        return root;
    }

    // Print the tree using TreePrinter
    void print() {
        TreePrinter<T, K> printer;
        printer.print(*this);
    }

    // Pre-Order Iterator
    class PreOrderIterator {
    private:
        std::stack<Node<T>*> stack;  // Stack to manage the nodes

    public:
        PreOrderIterator(Node<T>* root) {
            if (root) stack.push(root);
        }

        bool operator!=(const PreOrderIterator&) const {
            return !stack.empty();
        }

        PreOrderIterator& operator++() {
            Node<T>* node = stack.top();
            stack.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                stack.push(*it);
            }
            return *this;
        }

        Node<T>* operator*() const {
            return stack.top();
        }

        Node<T>* operator->() const {
            return stack.top();
        }
    };

    // Post-Order Iterator
    class PostOrderIterator {
    private:
        std::stack<Node<T>*> stack;
        std::stack<Node<T>*> output;

    public:
        PostOrderIterator(Node<T>* root) {
            if (root) {
                stack.push(root);
                while (!stack.empty()) {
                    Node<T>* node = stack.top();
                    stack.pop();
                    output.push(node);
                    for (Node<T>* child : node->children) {
                        stack.push(child);
                    }
                }
            }
        }

        bool operator!=(const PostOrderIterator&) const {
            return !output.empty();
        }

        PostOrderIterator& operator++() {
            output.pop();
            return *this;
        }

        Node<T>* operator*() const {
            return output.top();
        }

        Node<T>* operator->() const {
            return output.top();
        }
    };

    // In-Order Iterator (Binary tree specific)
    class InOrderIterator {
    private:
        std::stack<Node<T>*> stack;
        Node<T>* current;

    public:
        InOrderIterator(Node<T>* root) {
            stack.push(nullptr);
            while(root != nullptr) {
                stack.push(root);
                if(root->children.size()>0 && root->children[0] != nullptr) {
                    root = root->children[0];
                }
                else {
                    root = nullptr;
                }
            }
        }

        bool operator==(const InOrderIterator& other) const { return stack.top() == other.stack.top(); }

        bool operator!=(const InOrderIterator& other) const {
            return !(*this == other);
        }

        InOrderIterator& operator++() {
            Node<T>* node = stack.top();
            stack.pop();
            if(node->children.size()>1 && node->children[1] != nullptr) {
                Node<T>* right_child = node->children[1];
                stack.push(right_child);
                Node<T>* right_child_left_child = right_child;
                while (right_child_left_child->children.size() > 0 && right_child_left_child->children[0] != nullptr) {
                    right_child_left_child = right_child_left_child->children[0];
                    stack.push(right_child_left_child);
                }
            }
            return *this;
        }

        Node<T>* operator*() const {
            return stack.top();
        }

        Node<T>* operator->() const {
            return stack.top();
        }
    };

    // BFS Iterator
    class BFSIterator {
    private:
        std::queue<Node<T>*> queue;

    public:
        BFSIterator(Node<T>* root) {
            if (root) queue.push(root);
        }

        bool operator!=(const BFSIterator&) const {
            return !queue.empty();
        }

        BFSIterator& operator++() {
            Node<T>* node = queue.front();
            queue.pop();
            for (Node<T>* child : node->children) {
                queue.push(child);
            }
            return *this;
        }

        Node<T>* operator*() const {
            return queue.front();
        }

        Node<T>* operator->() const {
            return queue.front();
        }
    };

    // DFS Iterator
    class DFSIterator {
    private:
        std::stack<Node<T>*> stack;

    public:
        DFSIterator(Node<T>* root) {
            if (root) stack.push(root);
        }

        bool operator!=(const DFSIterator&) const {
            return !stack.empty();
        }

        DFSIterator& operator++() {
            Node<T>* node = stack.top();
            stack.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                stack.push(*it);
            }
            return *this;
        }

        Node<T>* operator*() const {
            return stack.top();
        }

        Node<T>* operator->() const {
            return stack.top();
        }
    };

    // Heap Iterator (for min-heap conversion)
    class HeapIterator {
    private:
        std::vector<Node<T>*> heap;  // Vector to store heap nodes
        size_t index;  // Index for current node in the heap

    public:
        HeapIterator(Node<T>* root) {
            index = 0;
            if (root == nullptr) {
                return;
            }

            // Collect all nodes in the tree using BFS
            std::queue<Node<T>*> node_queue;
            node_queue.push(root);

            while (!node_queue.empty()) {
                Node<T>* current_node = node_queue.front();
                node_queue.pop();
                heap.push_back(current_node);
                for (Node<T>* child : current_node->children) {
                    node_queue.push(child);
                }
            }

            // Convert the vector to a min-heap
            std::make_heap(heap.begin(), heap.end(), [](Node<T>* a, Node<T>* b) { return a->get_value() > b->get_value(); });
        }

        T& operator*() { return heap.front()->get_value(); }

        Node<T>* operator->() { return heap.front(); }

        HeapIterator& operator++() {
            if (heap.empty()) {
                return *this;
            }
            std::pop_heap(heap.begin(), heap.end(), [](Node<T>* a, Node<T>* b) { return a->get_value() > b->get_value(); });
            heap.pop_back();
            return *this;
        }

        bool operator==(const HeapIterator& other) const { return heap.size() == other.heap.size(); }
        bool operator!=(const HeapIterator& other) const { return !(*this == other); }
    };

    // Iterator functions
    PreOrderIterator begin_pre_order() { return PreOrderIterator(root); }
    PreOrderIterator end_pre_order() { return PreOrderIterator(nullptr); }

    PostOrderIterator begin_post_order() { return PostOrderIterator(root); }
    PostOrderIterator end_post_order() { return PostOrderIterator(nullptr); }

    InOrderIterator begin_in_order() { return InOrderIterator(root); }
    InOrderIterator end_in_order() { return InOrderIterator(nullptr); }

    BFSIterator begin_bfs_scan() { return BFSIterator(root); }
    BFSIterator end_bfs_scan() { return BFSIterator(nullptr); }

    DFSIterator begin_dfs_scan() { return DFSIterator(root); }
    DFSIterator end_dfs_scan() { return DFSIterator(nullptr); }

    HeapIterator begin_heap() { return HeapIterator(root); }
    HeapIterator end_heap() { return HeapIterator(nullptr); }

    // Transform the tree into a minimum heap
    void myHeap() {
        std::vector<Node<T>*> nodes;
        collectNodes(root, nodes);
        std::make_heap(nodes.begin(), nodes.end(), [](Node<T>* a, Node<T>* b) { return a->value > b->value; });
        buildHeap(nodes);
    }

private:
    // Collect nodes for heap transformation
    void collectNodes(Node<T>* node, std::vector<Node<T>*>& nodes) {
        if (!node) return;
        nodes.push_back(node);
        for (Node<T>* child : node->children) {
            collectNodes(child, nodes);
        }
    }

    // Build the heap from collected nodes
    void buildHeap(const std::vector<Node<T>*>& nodes) {
        if (nodes.empty()) return;
        root = nodes[0];
        std::queue<Node<T>*> queue;
        queue.push(root);
        size_t index = 1;
        while (!queue.empty() && index < nodes.size()) {
            Node<T>* node = queue.front();
            queue.pop();
            node->children.clear();
            for (int i = 0; i < K && index < nodes.size(); ++i) {
                node->add_child(nodes[index++]);
                queue.push(node->children.back());
            }
        }
    }
};

#endif // TREE_HPP







