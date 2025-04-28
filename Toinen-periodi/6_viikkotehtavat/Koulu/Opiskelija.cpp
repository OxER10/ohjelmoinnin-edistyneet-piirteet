// Oskari Jarvinen 

#include"Opiskelija.h"

Opiskelija::Opiskelija() {
    std::cout << "Opiskelija oletusrakentaja\n";
    opNro = "123321";
    suoritetutKurssit = {"Ohjelmoinnin perusteet", "Insinoorifysiikka", "Matematiikan perusteet"};
    opintopisteet = 15;
}

Opiskelija::Opiskelija(const std::string& tempNimi, const int& tempIka, const Osoite& tempOsoite, const std::string& tempOpNro, const int& tempOpintopisteet)
    : Henkilo(tempNimi, tempIka, tempOsoite), opNro(tempOpNro), opintopisteet(tempOpintopisteet) {
    std::cout << "Opiskelija parametrirakentaja\n";
}

Opiskelija::Opiskelija(const Opiskelija& tempOpiskelija) 
    : Henkilo(tempOpiskelija), opNro(tempOpiskelija.opNro), opintopisteet(tempOpiskelija.opintopisteet), suoritetutKurssit(tempOpiskelija.suoritetutKurssit){
    std::cout << "Opiskelija kopiorakentaja\n";
}

Opiskelija::~Opiskelija() {
    std::cout << "Opiskelija purkaja\n";
}

void Opiskelija::setOpNro(const std::string& uusiOpNRo) {
    opNro = uusiOpNRo;
}

void Opiskelija::setSuoritetutKurssit(const std::vector<std::string>& uusiSuoritetutKurssit) {
    suoritetutKurssit = uusiSuoritetutKurssit;
}

void Opiskelija::setOpintopisteet(const int& uusiOpintopisteet) {
    opintopisteet = uusiOpintopisteet;
}

std::string Opiskelija::getOpNro() const { return opNro; }

std::vector<std::string> Opiskelija::getSuoritetutKurssit() const { return suoritetutKurssit; }

int Opiskelija::getOpintopisteet() const { return opintopisteet; }

void Opiskelija::lisaaKurssi(const std::string& tempKurssi) {
    suoritetutKurssit.push_back(tempKurssi);
}

void Opiskelija::tulostaTiedot () const {
    std::cout << "\nOpiskelijan tiedot:\n";
    Henkilo::tulostaTiedot();
    std::cout << "Opiskelijanumero: " << opNro << "\n";
    std::cout << "Suoritetut kurssit: ";
    for (std::string s : suoritetutKurssit) {
        std::cout << s << ", ";
    }
    std::cout << "\nOpintopisteet: " << opintopisteet << "\n\n";
}

void Opiskelija::lisaaOpintopisteita(const int& tempOpintopisteet) {
    opintopisteet += tempOpintopisteet;
}

void Opiskelija::vaihdaTiedot(const std::string& tempNimi, const int& tempIka) {
    // Private
    // Vs code ilmoittaa, että muuttujaa ei voi käyttää, koska se on yksityinen.

    // Protected
    // Nyt muuttujia voi käyttää ja asettaa opiskelija-luokan sisällä
    nimi = tempNimi;
    ika = tempIka;
}