#ifndef AVTTree_hpp
#define AVLTree_hpp
#include "Node.hpp"

#include <iostream>
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

    Node* insertHandler(Node* node, std::string word){
        if(node == nullptr){
            return new Node(word);
        };

        if(word>node->word){
            node->right = insertHandler(node->right, word);
        }else if(word<node->word){
            node->left = insertHandler(node->left,word);
        }else{
            std::cout<<"\nkey already exists\n";
            return node;
        };

        updateHeight(node);
        int balance = getBalance(node);

        if(balance>1 && word<node->left->word){
            return rotateRight(node);
        };
        if(balance <-1 && word> node->right->word){
            return rotateLeft(node);
        };
        if(balance >1 && word>node->left->word){
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        };
        if(balance <-1 && word < node->right->word){
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;

    };

    public:
    void insert(std::string key){
        root = insertHandler(root, key);
    };
};


#endif