#ifndef AVTTree_hpp
#define AVLTree_hpp
#include "Node.hpp"

#include <string>
#include <algorithm>

class AVL{
    private:
    Node* root;
    int getHeight(Node* node){
        if(node != nullptr){
            return node->height;
        }else{
            return 0;
        }
    };

    void updateHeight(Node* node){
        if(node!= nullptr){
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    };

    int getBalance(Node* node){
        if(node == nullptr){
            return 0;
        };
        return getHeight(node->left)-getHeight(node->right);
    };

    Node* rotateRight(Node* y){
        Node* x = y->left;
        Node* z = x->right;

        x->right = y;
        y->left= z;

        updateHeight(y);
        updateHeight(x);

        return x;
    };

    Node* rotateLeft(Node* y){
        Node* x = y->right;
        Node* z = x->left;

        x->left = y;
        y->right = z;

        updateHeight(y);
        updateHeight(x);

        return x;
    };


    public:
};


#endif