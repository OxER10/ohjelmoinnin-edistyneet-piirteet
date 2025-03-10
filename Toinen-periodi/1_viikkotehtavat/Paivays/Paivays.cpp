// Oskari Jarvinen 
// T2 2p
// T3 1p

#include"Paivays.h"
#include<iostream>

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

bool isKarkausVuosi(int vuosi) {
    if (vuosi % 100 != 0 && vuosi % 4 == 0 || vuosi % 100 == 0 && vuosi % 400 == 0) { return true; }
    else { return false; }
}

void Paivays::setVuosi(int uusiVuosi) { 
    vuosi = uusiVuosi; 
    if (isKarkausVuosi(vuosi)) { kuukaudenPaivat[1] = 29; }
}

int Paivays::getPaiva() { return paiva; }

int Paivays::getKuukausi() { return kuukausi; }

int Paivays::getVuosi() { return vuosi; }

void Paivays::tulostaPaivays() {
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