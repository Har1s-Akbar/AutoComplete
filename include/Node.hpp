#ifndef NODE_HPP
#define NODE_HPP

#include <string>

struct Node{
    std::string word;
    Node* left;
    Node* right;
    int height;


    Node(std::string data): word(data), left(nullptr),right(nullptr),height(1){};
};

#endif