// Oskari Jarvinen 

#include"Opettaja.h"
#include "Henkilo.h"

Opettaja::Opettaja(){
    std::cout << "Opettaja oletusrakentaja\n";
    koulutusala = "Tietotekniikka";
    kurssit = {"Ohjelmoinnin perusteet", "Olio-ohjelmointi", "Pelikehitys"};
}

Opettaja::Opettaja(const std::string& tempNimi, int tempIka, const Osoite& tempOsoite, const std::string& tempKoulutusala) 
    : Henkilo(tempNimi, tempIka, tempOsoite), koulutusala(tempKoulutusala) {
    std::cout << "Opettaja parametrirakentaja\n";
}

Opettaja::Opettaja(const Opettaja& tempOpettaja)
    : Henkilo(tempOpettaja), koulutusala(tempOpettaja.koulutusala), kurssit(tempOpettaja.kurssit) {
    std::cout << "Opettaja kopiorakentaja\n";
}

Opettaja::~Opettaja() {
    std::cout << "Opettaja purkaja\n";
}

void Opettaja::setKoulutusala(const std::string& uusiKoulutusala) {
    koulutusala = uusiKoulutusala;
}

void Opettaja::setKurssit(const std::vector<std::string>& uusiKurssit) {
    kurssit = uusiKurssit;
}

std::string Opettaja::getKoulutusala() const { return koulutusala; }

std::vector<std::string> Opettaja::getKurssit() const { return kurssit; }

void Opettaja::tulostaTiedot () const {
    std::cout << "\nOpettajan tiedot:\n";
    Henkilo::tulostaTiedot();
    std::cout << "Koulutusala: " << koulutusala << "\n";
    std::cout << "Vastuukurssit: ";
    for (std::string s : kurssit) {
        std::cout << s << ", ";
    }
    std::cout << "\n\n";
}

void Opettaja::poistaKurssi(const std::string& tempKurssi) {
    for (int i = 0; i < kurssit.size(); i++) {
        if (kurssit[i] == tempKurssi) {
            kurssit.erase(kurssit.begin() + i);
            return;
        }
    }
}

void Opettaja::lisaaKurssi(const std::string& tempKurssi) {
    kurssit.push_back(tempKurssi);
}