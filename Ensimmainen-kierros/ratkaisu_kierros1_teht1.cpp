// T1 Oskari järvinen

#include <iostream>

int main(){
    int muuttuja = 7; 
    int *muuttuja_p = &muuttuja;
    std::cout << "muuttuja_p = " << muuttuja_p << std::endl;
    std::cout << "muuttuja = "<< muuttuja << std::endl;
    std::cout << "&muuttuja_p = " << &muuttuja_p << std::endl;
    std::cout << "&muuttuja_p = " << &muuttuja << std::endl;
    std::cout << "*&muuttuja_p = " << *&muuttuja_p << std::endl;
    std::cout << "&*muuttuja_p = " << &*muuttuja_p << std::endl;
    std::cout << "sizeof(muuttuja) = " << sizeof(muuttuja) << std::endl;
    std::cout << "sizeof(muuttuja_p) = " << sizeof(muuttuja_p) << std::endl;

    // T1 G,H
    // int *muuttuja_q;
    // int muuttuja2 = muuttuja_q;
    // Ei toimi

    int *muuttuja_q = nullptr;
    int muuttuja2 = *muuttuja_q;

    // VSCode suorittaa ohjelman, mutta debuggerissa jää jumiin, koska Exception has occurred: W32/0xC0000005 Unhandled exception thrown: read access violation. muuttuja_q was nullptr.

    return 0;
}
