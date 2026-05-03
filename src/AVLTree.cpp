#include "../include/AVLTree.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

AVL::AVL():root(nullptr){}
    
    
    int AVL::getHeight(Node* node){
    if(node== nullptr) return 0;
    return node->height;
    };

    void AVL::updateHeight(Node* node){

        if(node!= nullptr){
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        };

    };

    int AVL::getBalance(Node* node){
        if(node == nullptr){
            return 0;
        };
        return getHeight(node->left)-getHeight(node->right);
    };

    Node* AVL::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right; // The "Inner" child

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights - ORDER MATTERS (Child first, then new root)
    updateHeight(y);
    updateHeight(x);

    return x;
}

    Node* AVL::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left; // The "Inner" child

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights - ORDER MATTERS
    updateHeight(x);
    updateHeight(y);

    return y;
}

    Node* AVL::insertHandler(Node* node, std::string word){
        // std::cout<<"\nInserting: "<<word<<"\n";
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

    void AVL::searcHandler(Node* root, std::string prefix, int length,std::vector <std::string>& searchList){
        if(root !=nullptr){
            if(root->word.length() >= length && prefix == root->word.substr(0,length)){
                searcHandler(root->left,prefix,length,searchList);
                searchList.push_back(root->word);
                searcHandler(root->right,prefix,length,searchList);
            }
            else if(prefix > root->word.substr(0,length)){
                searcHandler(root->right,prefix,length,searchList);
            }else{
                searcHandler(root->left,prefix,length,searchList);
            }
        }
    };

    void AVL::insert(std::string key){
        root = insertHandler(root, key);
    };

    std::vector <std::string> AVL::search(std::string prefix){
        int length = prefix.length();
        std::vector <std::string> searchList ={};
        if(prefix.empty()){
            return searchList;
        }
        searcHandler(root, prefix, length, searchList);
        return searchList;
    };

