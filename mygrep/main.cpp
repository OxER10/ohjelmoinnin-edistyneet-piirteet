// Oskari Järvinen
// 4 Increments, so 5 points

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
    bool reverseSearch = false;
    bool caseIgnore = false;
};

// Call Functions first to get main on top of the stack
int stringSearch(const std::string &sour, const std::string &sear);

// Overloading functions for different increments
void searchFile(const std::string &file, const std::string sear);
int searchFile(const std::string &sour, const std::string &sear, const options opt, indexingStruct *index);

int main(int argc, char *argv[]) {
    try {
        std::string source, search;
        int amount;
        // If there is no additional arguments. For increment 1
        if (argc == 1) {
            std::cout << "Give a string from which to search for: ";
            if (!std::getline(std::cin, source) || source.empty()) {
                // Error if cin is empty
                throw std::runtime_error("Empty input!");
            }
            std::cout << "Give search string: ";
            if (!std::getline(std::cin, search) || search.empty()) {
                // Error if cin is empty
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
        // If there is one additional argument. For help
        else if (argc == 2) {
            std::string arg = argv[1];
            if (arg == "help" || "Help") {
                std::cout << "Run mygrep.exe like: mygrep.exe options string filename" << std::endl;
                std::cout << "Options argument starts with -o. additional arguments include:" << std::endl;
                std::cout << "l - Shows line numbers before searched line" << std::endl;
                std::cout << "o - Shows total number of lines where searched string was found" << std::endl;
                std::cout << "r - Shows only lines that doesn't contain searched string" << std::endl;
                std::cout << "i - Disables case sensitive search" << std::endl;
                std::cout << "For example: mygrep.exe -olori hello myFile.txt" << std::endl;
            }
            else {
                throw std::runtime_error("Invalid argument! Try help");
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
                // Error if first additional argument was something else than "-o"
                throw std::runtime_error("Invalid option. Please use \"-o\" for options. ");
            }
            for (char c : opt.substr(2)) {
				if (c == 'l')  option.lineNo = true;
				else if (c == 'o') option.occurences = true;
                else if (c == 'r') option.reverseSearch = true;
                else if (c == 'i') option.caseIgnore = true;
				else {
                    // Error if options afte "-o" are invalid
					throw std::runtime_error("Invalid options after \"-o\"!\n");
				}
			}
            amount = searchFile(source, search, option, indexing_p);
            if (amount > 0) {
                for (int i = 0; i < indexing.index.size(); i++) {
                    if (option.lineNo) {
                        std::cout << indexing.index[i] << ":   ";
                    }
                    std::cout << indexing.line[i] << std::endl;
                }
                if (option.occurences) {
                    if (option.reverseSearch) {
                        std::cout << "Occurences of lines NOT containing \"" << search << "\" in file: " << amount << std::endl;
                    }
                    else {
                        std::cout << "Occurences of lines containing \"" << search << "\" in file: " << amount << std::endl;
                    }
                }
            }
            else {
                std::cout << "\"" << search << "\" NOT found in \"" << source << "\"";
            }
        }
        else {
            throw std::runtime_error("Invalid arguments!");
        }
    // If program encounters known error, outputs error message
    } catch (const std::exception& exc) {
        std::cerr << "Encountered error: " << exc.what() << "\n";
        return 1;
    }
    // If program encounters unknown error, HOW DID YOU EVEN DO THAT?!
    catch (...) {
        std::cerr << "Unknown error! Congrats!\n";
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
            position = stringSearch(line, sear);
            // If string is found, prints it
            if (position != 0) {
                std::cout << line << std::endl;
            }
        }
    }
    else {
        // Error if there is no file with requested name, or you don't have access
        throw std::runtime_error("Couldn't open the file");
    }
    txtFile.close();
}

// Second, more complicated iteration of searchFile function. Returns all needed values instead of printing them for further developement.
int searchFile(const std::string &sour, const std::string &sear, const options opt, indexingStruct *index) {
    std::ifstream txtFile(sour);
    std::string line, tempLine, tempSear = sear;
    int tot {0}, amount {0}, position{0};
    // If case ignore is enabled, change all characters on search to lowercase
    if (opt.caseIgnore) {
        std::transform(tempSear.begin(), tempSear.end(), tempSear.begin(), ::tolower);
    }
    if (txtFile.is_open()){
        while (std::getline(txtFile, line)) {
            position++;
            tempLine = line;
            // If case ignore is enabled, change all characters on line to lowercase
            if (opt.caseIgnore) {
                std::transform(tempLine.begin(), tempLine.end(), tempLine.begin(), ::tolower);
            }
            amount = stringSearch(tempLine, tempSear);
            // If reverse search is enabled, saves only lines with no search found
            if (opt.reverseSearch) {
                if (amount == 0) {
                    (*index).index.emplace_back(position);
                    (*index).line.emplace_back(line);
                    tot++;
                }
            }
            else {
                // If string is found, save it to vector via pointer
                if (amount != 0) {
                    (*index).index.emplace_back(position);
                    (*index).line.emplace_back(line);
                    tot++;
                }
            }
        }
    }
    else {
        // Error if there is no file with requested name, or you don't have access
        throw std::runtime_error("Couldn't open the file");
    }
    txtFile.close();
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