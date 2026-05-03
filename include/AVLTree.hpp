#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "Node.hpp"
#include <vector>
#include <string>

class AVL {
private:
    Node* root;

    // Private helper prototypes
    int getHeight(Node* node);
    void updateHeight(Node* node);
    int getBalance(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* y);
    Node* insertHandler(Node* node, std::string word);
    void searcHandler(Node* node, std::string prefix, int length, std::vector<std::string>& searchList);

public:
    AVL();
    void insert(std::string key);
    std::vector<std::string> search(std::string prefix);
};

#endif