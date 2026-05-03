#ifndef AutoComplete_hpp
#define AutoComplete_hpp

#include "AVLTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class AutoComplete{
    private:
        AVL tree;
        int wordCount =0;
    public:
    bool loadDictionary(const std::string & filename);

    std::vector<std::string> getSuggestions(const std::string& prefix);

    int getWordCount() const {return wordCount;};
};

#endif