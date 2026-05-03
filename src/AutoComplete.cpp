#include "../include/AutoComplete.hpp"

#include <vector>
#include <string>

bool AutoComplete::loadDictionary(const std::string& filename){
    std::fstream file(filename);

    if(!file.is_open()){
        std::cout<<"\nError can not open the file\n";
        return false;
    }

    std::string word;
    while(file>>word){
        tree.insert(word);
        wordCount++;
    };

    file.close();
    return true;
}


std::vector<std::string> AutoComplete::getSuggestions(const std::string& prefix){
    if(prefix.empty()){
        return {};
    }
    return tree.search(prefix);
};