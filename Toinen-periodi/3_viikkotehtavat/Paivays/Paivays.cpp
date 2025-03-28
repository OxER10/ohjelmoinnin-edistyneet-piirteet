// Oskari Jarvinen 
// T1 1p
// T3 2p

#include"Paivays.h"
#include<iostream>

Paivays::Paivays() {
    paiva = 6;
    kuukausi = 9;
    vuosi = 2069;
}

Paivays::Paivays(int tempPaiva, int tempKuukausi, int tempVuosi) {
    paiva = tempPaiva;
    kuukausi = tempKuukausi;
    vuosi = tempVuosi;
}

Paivays::~Paivays() {
    std::cout << "Paivays-luokan purkaja\n";
}

void Paivays::destructorTest() {
    Paivays Temp;
}

// Vaaditut jäsenfunktiot (metodit)
void Paivays::setPaiva(int uusiPaiva) {
    if (uusiPaiva > 0 && uusiPaiva <= 31) {
        paiva = uusiPaiva;
    }
}

void Paivays::setKuukausi(int uusiKuukausi) {
    if (uusiKuukausi > 0 && uusiKuukausi <= 12) {
        kuukausi = uusiKuukausi;
    }
}

bool Paivays::isKarkausVuosi(int vuosi) const {
    if (vuosi % 100 != 0 && vuosi % 4 == 0 || vuosi % 100 == 0 && vuosi % 400 == 0) { return true; }
    else { return false; }
}

void Paivays::setVuosi(int uusiVuosi) { 
    vuosi = uusiVuosi; 
    if (isKarkausVuosi(vuosi)) { kuukaudenPaivat[1] = 29; }
}

void Paivays::setKuukaudenPaivat(int uusiKuukaudenPaivat[12]) {
    for (int i = 0; i < 12; i++) {
        kuukaudenPaivat[i] = uusiKuukaudenPaivat[i];
    }
}

int Paivays::getPaiva() const { return paiva; }

int Paivays::getKuukausi() const { return kuukausi; }

int Paivays::getVuosi() const { return vuosi; }

void Paivays::tulostaPaivays() const {
    std::cout << paiva << "." << kuukausi << "." << vuosi << "\n";
}

// Käyttäjältä päivämäärän kysyminen syötteellä metodi 
// Tehty myös syötteentarkistus
void Paivays::kayttajanPaiva() {
    int paiva, kuukausi, vuosi;
    std::cout << "Ilmoita vuosi: ";
    std::cin >> vuosi;
    if (isKarkausVuosi(vuosi)) {
        kuukaudenPaivat[1] = 29;
    }
    std::cout << "Ilmoita kuukausi: ";
    do {
        std::cin >> kuukausi;
        if (kuukausi < 1 || kuukausi > 12) { std::cout << "Ilmoita aito kuukausi: "; }
    }while (kuukausi < 1 || kuukausi > 12);
    std::cout << "Ilmoita paiva: ";
    do {
        std::cin >> paiva;
        if (paiva < 1 || paiva > kuukaudenPaivat[kuukausi - 1]) { std::cout << "Ilmoita aito paiva: "; }
    }while (paiva < 1 || paiva > kuukaudenPaivat[kuukausi - 1]);
    setPaiva(paiva);
    setKuukausi(kuukausi);
    setVuosi(vuosi);
}

// Päivämäärän lisääjä metodi
void Paivays::addPaiva() {
    paiva++;
    if (paiva > kuukaudenPaivat[kuukausi - 1]) {
        paiva = 1;
        kuukausi++;
        if (kuukausi > 12) {
            kuukausi = 1;
            vuosi++;
        }
    }
}

Kalenterimerkinta::Kalenterimerkinta():Paivays() {
    paivays = Paivays();
    asia = "Muista tama asia tai kay huonosti";
    muistutus = true;
}

Kalenterimerkinta::Kalenterimerkinta(Paivays tempPaivays, std::string tempAsia, bool tempMuistutus) {
    paivays = tempPaivays;
    asia = tempAsia;
    muistutus = tempMuistutus;
}

Kalenterimerkinta::~Kalenterimerkinta() {
    std::cout << "Destructor testi\n";
}

void Kalenterimerkinta::setPaivays(Paivays uusiPaivays) {
    paivays = uusiPaivays;
}

void Kalenterimerkinta::setAsia(std::string uusiAsia) {
    asia = uusiAsia;
}

void Kalenterimerkinta::setMuistutus(bool uusiMuistutus) {
    muistutus = uusiMuistutus;
}

Paivays Kalenterimerkinta::getPaivays() const { return paivays; }

std::string Kalenterimerkinta::getAsia() const { return asia; }

bool Kalenterimerkinta::getMuistutus() const { return muistutus; }

void Kalenterimerkinta::tulostaMerkinta() const {
    std::cout << "Paivays: " << paivays.getPaiva() << "." << paivays.getKuukausi() << "." << paivays.getVuosi() << "\n";
    std::cout << "Asia: " << asia << ".\n";
    std::cout << "Muistutus: ";
    if (muistutus) {
        std::cout << "Paalla.\n";
    }
    else {
        std::cout << "Poissa paalta.\n";
    }
}

void Kalenterimerkinta::kysyTiedot() {
    bool tarkistus;
    paivays.kayttajanPaiva();
    std::cout << "Ilmoita merkinnan asia: ";
    std::cin.get();
    std::getline(std::cin, asia);
    std::cout << "Asetetaanko muistutus? (Y/N): ";
    std::cin >> tarkistus;
    if (tarkistus == 'y' || tarkistus == 'Y') {
        muistutus = true;
    }
    else {
        muistutus = false;
    }
}