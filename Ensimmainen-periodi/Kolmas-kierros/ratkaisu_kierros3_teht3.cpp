// T3 Oskari Järvinen

#include <iostream>

// struct, jossa säilytetään arvot
struct aika_ty {
    int tun, min, sek;
};

// Asetetaan tehty Aika struct typedef komennolla aikaStruct, jotta ei tarvitse kirjoittaa aina uudelleen
typedef struct aika_ty aika_tyStruct;

// Kutsutaan funktioita
int intInputCheck();
void tulostemuoto(int x, int y, int z);
bool vertailu(aika_tyStruct x, aika_tyStruct y);

int main() {
    aika_tyStruct aika1, aika2 = {3, 3, 3}, aika3 = {3, 3, 3};
    aika_tyStruct *aika1_p = &aika1;
    bool sama;
    std::cout << "Anna tunnit: ";
    do {
        aika1.tun = intInputCheck();
        if (aika1.tun >= 24) {
            std::cout << "\nAnna luku 0-23 valilta!: ";
        }
        else if (aika1.tun < 0) {
            std::cout << "\nAnna positiivinen luku!: ";
        }
    } while (aika1.tun >= 24 || aika1.tun < 0);
    std::cout << "Anna minuutit: ";
    do {
        aika1.min = intInputCheck();
        if (aika1.min >= 60) {
            std::cout << "\nAnna luku 0-59 valilta!: ";
        }
        else if (aika1.min < 0) {
            std::cout << "\nAnna positiivinen luku!: ";
        }
    } while (aika1.min >= 60 || aika1.min < 0);
    std::cout << "Anna sekunnit: ";
    do {
        aika1.sek = intInputCheck();
        if (aika1.sek >= 60) {
            std::cout << "\nAnna luku 0-59 valilta!: ";
        }
        else if (aika1.sek < 0) {
            std::cout << "\nAnna positiivinen luku!: ";
        }
    } while (aika1.sek >= 60 || aika1.sek < 0);
    std::cout << "Tulostus aika1 tietueesta ilman osoitinta: " << std::endl;
    tulostemuoto(aika1.tun, aika1.min, aika1.sek);
    // Tulostetaan osoitin perinteisellä tapaa
    std::cout << "Tulostus aika1 tietueesta osoittimella: " << std::endl;
    tulostemuoto((*aika1_p).tun, (*aika1_p).min, (*aika1_p).sek);
    // Tulostetaan osoitin helpommalla tapaa. -> on helpompi tapa kirjoittaa (*) 
    std::cout << "Tulostus aika1 tietueesta osoittimella toisella tapaa: " << std::endl;
    tulostemuoto(aika1_p->tun, aika1_p->min, aika1_p->sek);
    std::cout << "Tulostus aika2 tietueesta: " << std::endl;
    tulostemuoto(aika2.tun, aika2.min, aika2.sek);
    std::cout << "Tulostus aika3 tietueesta: " << std::endl;
    tulostemuoto(aika3.tun, aika3.min, aika3.sek);
    sama = vertailu(aika2, aika3);
    if (sama == true) {
        std::cout << "\nSisallot ovat samat";
    }
    else {
        std::cout << "\nSisallot eivat ole samat";
    }
}

// Funktio, jolla tarkistetaan käyttäjän syöte
int intInputCheck() {
    int input;
    bool error;
    do{
        std::cin >> input;
        if (std::cin.fail()){
            std::cout << "Virhe! Tarkista syote!" << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n'); 
        }
        else {
            error = false;
        }
    }while (error == true);
    return input;
}

// funktio, jolla tehdään monen eri hh:mm:ss tulostus helpommaksi
void tulostemuoto(int x, int y, int z) {
    if (x < 10){
        std::cout << "0" << x;
    }
    else {
        std::cout << x;
    }
    if (y < 10) {
        std::cout << ":0" << y;
    }
    else {
        std::cout << ":" << y;
    }
    if (z < 10) {
        std::cout << ":0" << z;
    }
    else {
        std::cout << ":" << z;
    }
    std::cout << std::endl;
}

bool vertailu(aika_tyStruct x, aika_tyStruct y) {
    if (x.tun == y.tun && x.min == y.min && x.sek == y.sek){
        return true;
    }
    else {
        return false;
    }
};