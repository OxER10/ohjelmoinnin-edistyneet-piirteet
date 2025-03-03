// Oskari Järvinen

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Struct for indexing lines
struct indexing {
    std::vector<int> index;
    std::vector<std::string> line;
};

typedef struct indexing indexingStruct;

// Struct for options
struct options {
    bool lineNo = false;
    bool occurences = false;
};

// Call Functions first
void searchFile(const std::string &file, const std::string sear);
// Overloading functions
int searchFile(const std::string &sour, const std::string &sear, const options opt, indexingStruct *index);
int stringSearch(const std::string &sour, const std::string &sear);

int main(int argc, char *argv[]) {
    try {
        std::string source, search;
        int amount;
        // If there is no additional arguments. For increment 1
        if (argc == 1) {
            std::cout << "Give a string from which to search for: ";
            if (!std::getline(std::cin, source) || source.empty()) {
                throw std::runtime_error("Empty input!");
            }
            std::cout << "Give search string: ";
            if (!std::getline(std::cin, search) || search.empty()) {
                throw std::runtime_error("Empty input!");
            }
            amount = stringSearch(source, search);
            if (amount == 0) {
                std::cout << "\"" << search << "\" NOT found in \"" << source << "\"";
            }
            else {
                std::cout << "\"" << search << "\" Was found in " << amount << " number of positions";
            }
        }
        // If there is two additional arguments. For increment 2
        else if (argc == 3) {
            source = argv[2];
            search = argv[1];
            searchFile(source, search);
        }
        // If there is three additional arguments. For increment 3 and 4
        else if (argc == 4) {
            indexingStruct indexing, *indexing_p = &indexing;
            options option;
            source = argv[3];
            search = argv[2];
            std::string opt = argv[1];
            if (opt.substr(0, 2) != "-o") {
                throw std::runtime_error("Invalid option. Please use \"-o\" for options. ");
            }
            for (char c : opt.substr(2)) {
				if (c == 'l')  option.lineNo = true;
				else if (c == 'o') option.occurences = true;
				else {
					throw std::runtime_error("Invalid options after \"-o\"!\n");
				}
			}
            amount = searchFile(source, search, option, indexing_p);
            for (int i = 0; i < indexing.index.size(); i++) {
                if (option.lineNo) {
                    std::cout << indexing.index[i] << ":   ";
                }
                std::cout << indexing.line[i] << std::endl;
            }
            if (option.occurences) {
                std::cout << "Number of strings in file: " << amount << std::endl;
            }
            
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

// First iteration of searchFile Function for increment 2. Searches the file for requested search and prints every line with desired search.
void searchFile(const std::string &sour, const std::string sear) {
    std::ifstream txtFile(sour);
    std::string line;
    int position{0};
    if (txtFile.is_open()){
        while (std::getline(txtFile, line)) {
            // If string is found, prints it
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

// Second, more complicated iteration of searchFile function. Returns all needed values instead of printing them.
int searchFile(const std::string &sour, const std::string &sear, const options opt, indexingStruct *index) {
    std::ifstream txtFile(sour);
    std::string line;
    int tot {0}, amount {0}, position{0};
    if (txtFile.is_open()){
        while (std::getline(txtFile, line)) {
            position++;
            amount = stringSearch(line, sear);
            // If string is found, save it to vector via pointer
            if (amount != 0) {
                (*index).index.emplace_back(position);
                (*index).line.emplace_back(line);
                // Adds string occurences to total values
                tot += amount;
            }
        }
        txtFile.close();
    }
    else {
        throw std::runtime_error("Couldn't open the file");
    }
    return tot;
}

// Function that searches trough a string looking for another string. Works with nested for loops
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