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
void Henkilo::tulostaHenkilonTiedot() const {
    std::cout << "Nimi: " << nimi << "\n";
    std::cout << "Ika: " << ika << "\n";
}

void Henkilo::tervehdi() const {
    std::cout << "Hei! Nimeni on " << nimi << "\n";
    std::cout << "Olen " << ika << " vuotias.\n";
}

void Henkilo::setIka(int uusiIka) {
    if (uusiIka >= 0) {
        ika = uusiIka;
    }
}

int Henkilo::getIka() const {
    return ika;
}

void Henkilo::setNimi(std::string uusiNimi) {
    nimi = uusiNimi;
}

std::string Henkilo::getNimi() const {
    return nimi;
}


Osoite::Osoite() {
    katuosoite = "Kuntokatu 3";
    postinumero = "33520";
    kunta = "Tampere";
}

Osoite::Osoite(std::string tempKatuosoite, std::string tempPostinumero, std::string tempKunta) {
    katuosoite = tempKatuosoite;
    postinumero = tempPostinumero;
    kunta = tempKunta;
}

void Osoite::tulostaOsoiteTiedot() const {
    std::cout << "Koko osoite: " << katuosoite << " , " << postinumero << " " << kunta << "\n";
}

void Osoite::setKatuosioite(std::string uusiKatuosoite) {
    if (uusiKatuosoite != "") {
        katuosoite = uusiKatuosoite;
    }
}

void Osoite::setPostinumero(std::string uusiPostinumero) {
    if (uusiPostinumero != "") {
        postinumero = uusiPostinumero;
    }
}

void Osoite::setKunta(std::string uusiKunta) {
    if (uusiKunta != "") {
        kunta = uusiKunta;
    }
}

std::string Osoite::getKatuosoite() const { return katuosoite; }

std::string Osoite::getPostinumero() const { return postinumero; }

std::string Osoite::getKunta() const { return kunta; }