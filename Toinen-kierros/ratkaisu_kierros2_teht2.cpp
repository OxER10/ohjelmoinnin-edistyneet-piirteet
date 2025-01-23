// T2 Oskari järvinen

#include <iostream>

//Ohjelma tarvitsee cmath kirjaston
#include <cmath>

int main() {
    float input;
    int floor, ceil;
    std::cout << "Anna desimaaliluku: ";
    std::cin >> input;
    // Käyttämällä floor voidaan pyöristää numero alas ja käyttämällä ceil voidaan pyöristää numero ylös
    std::cout << "Luku " << input << " sisaltyy valille [ " << std::floor(input) << ", " << std::ceil(input) << " ].";
    return 0;
}