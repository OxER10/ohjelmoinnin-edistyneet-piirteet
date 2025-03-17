// Oskari Jarvinen 
// T1 2p
// T2 1p

#include"Henkilo.h"
#include<iostream>
#include<string>


// Lisatty constructor ilman parametreja
Henkilo::Henkilo() {
    std::cout << "Henkilo-luokan parametriton rakentaja\n";
    nimi = "matti";
    ika = 76;
}

// Lisatty constructor 2 parametrilla
Henkilo::Henkilo(std::string tempNimi, int tempIka) {
    std::cout << "Henkilo-luokan 2 parametrinen rakentaja\n";
    nimi = tempNimi;
    ika = tempIka;
}

// Lisätty destructor
Henkilo::~Henkilo() {
    std::cout << "Henkilo-luokan purkaja\n";
}

void Henkilo::destructorTest() {
    Henkilo Temp;
}

// Lisatty tulostaHenkilonTiedot jäsenfunktio
void Henkilo::tulostaHenkilonTiedot() {
    std::cout << "Nimi: " << nimi << "\n";
    std::cout << "Ika: " << ika << "\n";
}

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