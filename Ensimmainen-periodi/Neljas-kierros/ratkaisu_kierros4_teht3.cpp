// T3 Oskari Järvinen

#include<iostream>
#include<fstream>
#include<string>

int main() {
    std::string name, description;
    std::ofstream site;
    
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Describe yourself: ";
    std::getline(std::cin, description);

    site.open("index.html");
    if (site) {
        // Save text to file. \n is new line.
        site << "<html>\n<head>\n</head>\n<body>\n   <center>\n      <h1>" << name << "</h1>\n   </center>\n   <hr />\n   " << description << "\n   <hr />\n</body>\n</html>\n"; 
    }
    site.close();
    std::cout << "Succesfully created file!";
}

// File creation is success. You can open the file in browser and it displays h1 and hr elements