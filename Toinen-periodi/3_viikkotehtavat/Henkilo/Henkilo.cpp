// Oskari Jarvinen 
// T1 1p
// T2 2p

#include"Henkilo.h"
#include<iostream>
#include<string>


Henkilo::Henkilo() {
    nimi = "matti";
    ika = 76;
}

Henkilo::Henkilo(std::string tempNimi, int tempIka) {
    nimi = tempNimi;
    ika = tempIka;
}

Henkilo::Henkilo(std::string tempNimi, int tempIka, Osoite tempOsoite) {
    nimi = tempNimi;
    ika = tempIka;
    osoite = tempOsoite;
}

void Henkilo::tulostaTiedot() const {
    std::cout << "Nimi: " << nimi << "\n";
    std::cout << "Ika: " << ika << "\n";
    std::cout << "Osoie: " << osoite.getKatuosoite() << " , " << osoite.getPostinumero() << " " << osoite.getKunta() << "\n";

}

void Henkilo::setIka(int uusiIka) {
    if (uusiIka >= 0) {
        ika = uusiIka;
    }
}

void Henkilo::setNimi(std::string uusiNimi) {
    nimi = uusiNimi;
}

void Henkilo::setOsoite(Osoite uusiOsoite) {
    osoite = uusiOsoite;
}

std::string Henkilo::getNimi() const { return nimi; }

int Henkilo::getIka() const { return ika; }

Osoite Henkilo::getOsoite() const { return osoite; }

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