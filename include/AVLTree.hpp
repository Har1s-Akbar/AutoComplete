#ifndef AVTTree_hpp
#define AVLTree_hpp
#include "Node.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class AVL{
    private:
    Node* root = nullptr;
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

    void searcHandler(Node* root, std::string prefix, int length,std::vector <std::string>& searchList){
        if(root !=nullptr){
            if(prefix == root->word.substr(0,length)){
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

    public:
    void insert(std::string key){
        root = insertHandler(root, key);
    };

    std::vector <std::string> search(std::string prefix){
        int length = prefix.length();
        std::vector <std::string> searchList ={};
        searcHandler(root, prefix, length, searchList);
        return searchList;
    };

};


#endif