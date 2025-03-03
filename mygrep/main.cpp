// Oskari Järvinen

#include <iostream>
#include <fstream>
#include <string>

// Call Functions first
void searchFile(const std::string &file, const std::string sear);
int stringSearch(const std::string &sour, const std::string &sear);

int main(int argc, char *argv[]) {
    try {
        std::string source, search;
        // If there is no additional arguments
        if (argc == 1) {
            int position;
            std::cout << "Give a string from which to search for: ";
            if (!std::getline(std::cin, source) || source.empty()) {
                throw std::runtime_error("Empty input!");
            }
            std::cout << "Give search string: ";
            if (!std::getline(std::cin, search) || search.empty()) {
                throw std::runtime_error("Empty input!");
            }
            position = stringSearch(source, search);
            if (position == 0) {
                std::cout << "\"" << search << "\" NOT found in \"" << source << "\"";
            }
            else {
                std::cout << "\"" << search << "\" Was found in " << position << " number of positions";
            }
        }
        // If there is two additional arguments
        else if (argc == 3) {
            source = argv[2];
            search = argv[1];
            searchFile(source, search);
        }
        else {
            throw std::runtime_error("Invalid arguments!");
        }
    } catch (const std::exception& exc) {
        std::cerr << "Encountered error: " << exc.what() << "\n";
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown error! Congrats\n";
        return 1;
    }
    return 0;
}

// Searches the file for requested search and prints every line with desired search.
void searchFile(const std::string &sour, const std::string sear) {
    std::ifstream txtFile(sour);
    std::string line;
    int position{0};
    if (txtFile.is_open()){
        while (std::getline(txtFile, line)) {
            position = stringSearch(line, sear);
            if (position != 0) {
                std::cout << line << std::endl;
            }
        }
        txtFile.close();
    }
    else {
        throw std::runtime_error("Couldn't open the file");
    }
}


// Funtion that searches trough a string looking for another string. Works with nested for loops
int stringSearch(const std::string &sour, const std::string &sear) {
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
    // Returns how many times search was found
    return position;
}