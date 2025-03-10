#include"Henkilo.h"
#include<iostream>
#include<string>

void Henkilo::tervehdi() {
    std::cout << "Hei! Nimeni on " << nimi << "\n";
    std::cout << "Olen " << ika << " vuotias.\n";
}

void Henkilo::setIka(int uusiIka) {
    if (uusiIka >= 0) {
        ika = uusiIka;
    }
}

int Henkilo::getIka() {
    return ika;
}

void Henkilo::setNimi(std::string uusiNimi) {
    nimi = uusiNimi;
}

std::string Henkilo::getNimi() {
    return nimi;
}