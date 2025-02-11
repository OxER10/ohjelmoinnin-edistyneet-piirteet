// Oskari Järvinen

#include <iostream>
#include <string>

int grepSearch(std::string x, std::string y);

int main() {
    std::string source, search;
    int position;
    std::cout << "Give a string from which to search for: ";
    std::getline(std::cin, source);
    std::cout << "Give search string: ";
    std::getline(std::cin, search);
    position = grepSearch(search, source);
    if (position == 0) {
        std::cout << "\"" << search << "\" NOT found in \"" << source << "\"";
    }
}

int grepSearch(std::string x, std::string y) {
    int position = 0;
    return position;
}