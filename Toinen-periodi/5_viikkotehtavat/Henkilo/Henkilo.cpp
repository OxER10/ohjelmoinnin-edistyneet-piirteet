// Oskari Jarvinen 

#include"Henkilo.h"

Henkilo::Henkilo() {
    std::cout << "Henkilo oletusrakentaja\n";
    nimi = "Matti";
    ika = 42;
}

Henkilo::Henkilo(std::string tempNimi, int tempIka) {
    std::cout << "Henkilo parametrirakentaja\n";
    nimi = tempNimi;
    ika = tempIka;
}

Henkilo::Henkilo(const Henkilo& tempHenkilo) {
    std::cout << "Henkilo kopiorakentaja\n";
    nimi = tempHenkilo.nimi;
    ika = tempHenkilo.ika;
    osoite = tempHenkilo.osoite;
}

Henkilo::Henkilo(std::string tempNimi, int tempIka, Osoite tempOsoite) {
    std::cout << "Henkilo osoiteparametrirakentaja\n";
    nimi = tempNimi;
    ika = tempIka;
    osoite = tempOsoite;
}

Henkilo::~Henkilo() {
    std::cout << "Henkilo purkaja\n";
}

void Henkilo::tulostaHenkiloTiedot() const {
    std::cout << "Nimi: " << nimi << "\n";
    std::cout << "Ika: " << ika << "\n";
    std::cout << "Osoite: " << osoite.getKatuosoite() << " , " << osoite.getPostinumero() << " " << osoite.getKunta() << "\n";

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
    std::cout << "Osoite oletusrakentaja\n";
    katuosoite = "Kuntokatu 3";
    postinumero = "33520";
    kunta = "Tampere";
}

Osoite::Osoite(std::string tempKatuosoite, std::string tempPostinumero, std::string tempKunta) {
    std::cout << "Osoite parametrirakentaja\n";
    katuosoite = tempKatuosoite;
    postinumero = tempPostinumero;
    kunta = tempKunta;
}

Osoite::Osoite(const Osoite& tempOsoite) {
    std::cout << "Osoite kopiorakentaja\n";
    katuosoite = tempOsoite.katuosoite;
    postinumero = tempOsoite.postinumero;
    kunta = tempOsoite.kunta;
}

Osoite::~Osoite() {
    std::cout << "Osoite purkaja\n";
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