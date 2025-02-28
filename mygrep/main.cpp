// Oskari Järvinen

#include <iostream>
#include <string>

int grepSearch(std::string &sour, std::string &sear);

int main() {
    std::string source, search;
    int position;
    std::cout << "Give a string from which to search for: ";
    std::getline(std::cin, source);
    std::cout << "Give search string: ";
    std::getline(std::cin, search);
    position = grepSearch(source, search);
    if (position == 0) {
        std::cout << "\"" << search << "\" NOT found in \"" << source << "\"";
    }
    else {
        std::cout << "\"" << search << "\" Was found in " << position << " number of positions";
    }
}

int grepSearch(std::string &sour, std::string &sear) {
    int position = 0, sourl = sour.length(), searl = sear.length();
    // Search through the text to find matches
    for (int i = 0; i <= sourl - searl; i++) {
        // Check source for search matches
        int o;
        for (o = 0; o < searl; o++) {
            // If source doesn't match search, break
            if (sour[i + o] != sear[o]) {
                break;
            }
        }
        // If loop completed, match is found.
        if (o == searl) {
            position++;
        }
    }
    return position;
}