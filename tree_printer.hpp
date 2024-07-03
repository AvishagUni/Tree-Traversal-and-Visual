// minnesav@gmail.com

#ifndef TREE_PRINTER_HPP
#define TREE_PRINTER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "node.hpp"

// Forward declaration of Tree template class
template <typename T, int K>
class Tree;

template <typename T, int K>
class TreePrinter {
public:
    void print(Tree<T, K> &tree, const std::string &dot_filename, const std::string &png_filename) {
        std::ofstream file(dot_filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file to write DOT representation.");
        }

        file << "digraph G {\n";
        file << "node [shape=circle];\n";

        Node<T>* root = tree.getRoot();
        if (root) {
            printNode(file, root);
        }

        file << "}\n";
        file.close();

        std::string command = "dot -Tpng " + dot_filename + " -o " + png_filename;
        system(command.c_str());
    }

private:
    void printNode(std::ofstream &file, Node<T>* node) {
        for (Node<T>* child : node->children) {
            if (child) {
                file << "\"" << node->get_value() << "\" -> \"" << child->get_value() << "\";\n";
                printNode(file, child);
            }
        }
    }
};

#endif // TREE_PRINTER_HPP


















