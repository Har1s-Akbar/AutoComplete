#include "../include/AutoComplete.hpp"

int main() {
    AutoComplete ac;
    
    std::cout << "Loading dictionary..." << std::endl;
    if (!ac.loadDictionary("data/words.txt")) {
        return 1;
    }
    std::cout << ac.getWordCount() << " words loaded!" << std::endl;

    std::string input;
    while (true) {
        std::cout << "\nEnter prefix (type 'exit' to quit): ";
        std::cin >> input;

        if (input == "exit") break;

        std::vector<std::string> results = ac.getSuggestions(input);

        if (results.empty()) {
            std::cout << "No suggestions found." << std::endl;
        } else {
            for (const std::string& s : results) {
                std::cout << " - " << s << "\n";
            }
        }
    }
    return 0;
}