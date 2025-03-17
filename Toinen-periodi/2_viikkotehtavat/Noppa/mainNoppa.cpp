// Oskari Jarvinen 
// T3 1p
// T4 1p

#include"Noppa.h"
#include<iostream>

int main() {
    // Testataan oletusrakentajalla
    std::cout << "Noppayksilo:\n";
    Noppa kimble;
    kimble.heitaNoppaa();
    kimble.kerroViimeisenHeitonLukema();

    // Testataan kahdella nopalla
    std::cout << "Noppapari:\n";
    Noppa monopoli(2);
    monopoli.heitaNoppaa();
    monopoli.kerroViimeisenHeitonLukema();

    // Testataan kolmella nopalla
    std::cout << "Triplanopat:\n";
    Noppa ceeLo(3);
    ceeLo.heitaNoppaa();
    ceeLo.kerroViimeisenHeitonLukema();

    // Testataan neljällä nopalla
    std::cout << "Nelionopat:\n";
    Noppa fourKeeps(4);
    fourKeeps.heitaNoppaa();
    fourKeeps.kerroViimeisenHeitonLukema();

    // Testataan neljällä nopalla
    std::cout << "Vitosnopat:\n";
    Noppa yazty(5);
    yazty.heitaNoppaa();
    yazty.kerroViimeisenHeitonLukema();

    // Testataan loput metodit
    std::cout << yazty.getNoppienLkm() << " " << yazty.getViimeisinlukema();
}