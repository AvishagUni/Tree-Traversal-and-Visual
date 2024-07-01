#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include <queue>
#include <stack>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <QWidget>
#include "tree_printer.hpp"

template <typename T, int K = 2>
class Tree {
private:
    Node<T>* root;

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        clear();
    }

    void add_root(Node<T>& node) {
        if (!root) {
            root = new Node<T>(node.value);
        } else {
            root->value = node.value;
        }
    }

    void add_sub_node(Node<T>& parent_node, Node<T>& child_node) {
        Node<T>* parent = find(root, parent_node.value);
        if (parent == nullptr || parent->children.size() >= K) {
            throw std::runtime_error("Parent node not found or maximum children exceeded.");
        }
        Node<T>* new_child = new Node<T>(child_node.value);
        parent->add_child(new_child);
    }

    Node<T>* find(Node<T>* node, T value) {
        if (!node) return nullptr;
        if (node->value == value) return node;
        for (Node<T>* child : node->children) {
            Node<T>* result = find(child, value);
            if (result) return result;
        }
        return nullptr;
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

    void clear(Node<T>* node) {
        if (!node) return;
        for (Node<T>* child : node->children) {
            clear(child);
        }
        delete node;
    }

    Node<T>* getRoot() const {
        return root;
    }

    void print() {
        TreePrinter<T, K> printer;
        printer.print(*this);
    }

    // Pre-Order Iterator
    class PreOrderIterator {
    private:
        std::stack<Node<T>*> stack;
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
            // return stack.top()->get_value();
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

    // Heap Iterator (Min-Heap conversion)
    class HeapIterator {
    private:
        std::vector<Node<T>*> heap;
        size_t index;

        // void heapify(Node<T>* node) {
        //     index = 0;
        //     if (node == nullptr) {
        //         return;
        //     }
        //     std::cout << "Heapify: Starting BFS traversal for heap construction." << std::endl;
        //     for (auto it = BFSIterator(node); it != BFSIterator(nullptr); ++it) {
        //         heap.push_back(*it);
        //         std::cout << "Heapify: Adding node with value: " << (*it)->get_value().toString() << std::endl;
        //     }
        //     std::cout << "Heapify: Finished BFS traversal. Building heap." << std::endl;
        //     std::make_heap(heap.begin(), heap.end(), [](Node<T>* a, Node<T>* b) { return a->value > b->value; });
        //     std::cout << "Heapify: Heap construction completed." << std::endl;
        // }

        void heapify(Node<T>* node) {
            index = 0;
            if (node == nullptr) {
                return;
            }

            std::queue<Node<T>*> node_queue;
            node_queue.push(node);

            // Perform BFS to collect all nodes in the heap
            while (!node_queue.empty()) {
                Node<T>* current_node = node_queue.front();
                node_queue.pop();
                heap.push_back(current_node);
                for (Node<T>* child : current_node->children) {
                    node_queue.push(child);
                }
            }

            std::make_heap(heap.begin(), heap.end(), [](Node<T>* a, Node<T>* b) { return a->value > b->value; });
        }

    public:
        HeapIterator(Node<T>* root) : index(0) {
            if (root) {
                heapify(root);
            }
        }

        bool operator==(const HeapIterator& other) const { return index == other.index && heap.size() == other.heap.size(); }
        bool operator!=(const HeapIterator& other) const { return !(*this == other); }

        HeapIterator& operator++() {
            std::cout << "HeapIterator: Incrementing iterator." << std::endl;
            std::pop_heap(heap.begin(), heap.end() - index, [](Node<T>* a, Node<T>* b) { return a->value > b->value; });
            index++;
            return *this;
        }

        Node<T>* operator*() const {
            return heap[index];
        }

        Node<T>* operator->() const {
            return heap[0];
        }
    };

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

    // myHeap method to transform the tree into a minimum heap
    void myHeap() {
        std::vector<Node<T>*> nodes;
        collectNodes(root, nodes);
        std::make_heap(nodes.begin(), nodes.end(), [](Node<T>* a, Node<T>* b) { return a->value > b->value; });
        buildHeap(nodes);
    }

private:
    void collectNodes(Node<T>* node, std::vector<Node<T>*>& nodes) {
        if (!node) return;
        nodes.push_back(node);
        for (Node<T>* child : node->children) {
            collectNodes(child, nodes);
        }
    }

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







