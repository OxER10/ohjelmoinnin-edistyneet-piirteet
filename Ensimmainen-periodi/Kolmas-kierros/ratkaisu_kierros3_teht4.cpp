// T4 Oskari Järvinen

#include <iostream>

// struct, jossa säilytetään arvot
struct aika_ty {
    int tun = 0, min = 0, sek = 0;
};

// Asetetaan tehty Aika struct typedef komennolla aikaStruct, jotta ei tarvitse kirjoittaa aina uudelleen
typedef struct aika_ty aika_tyStruct;

// Kutsutaan funktioita
int intInputCheck();
void inputKysely(aika_tyStruct *x);
void tulostemuoto(aika_tyStruct x);
int aika_sekunneiksi(aika_tyStruct y);
void sekunnit_ajaksi(int x, aika_tyStruct *y);
aika_tyStruct aikojen_erotus(aika_tyStruct x, aika_tyStruct y);

int main() {
    aika_tyStruct aika1, aika2, aikaerotus;
    aika_tyStruct *aika1_p = &aika1, *aika2_p = &aika2;
    inputKysely(aika1_p);
    inputKysely(aika2_p);
    aikaerotus = aikojen_erotus(aika1, aika2);
    std::cout << "\nAjan 1. : ";
    tulostemuoto(aika1);
    std::cout << "\nAjan 2. : ";
    tulostemuoto(aika2);
    std::cout << "\nErotus on : ";
    tulostemuoto(aikaerotus);
    std::cout << "\nEli " << aikaerotus.tun << " tuntia " << aikaerotus.min << " minuuttia " << aikaerotus.sek << " sekuntia.";
}

// Funktio, joka tarkistaa käyttäjän syötteen virheiden varalta
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

// Funktio, joka kysyy arvot käyttäjältä pointerin avulla
void inputKysely(aika_tyStruct *x) {
    static int suoritettu = 1;
    std::cout << "Anna ajan " << suoritettu << ". tunnit: ";
    do {
        (*x).tun = intInputCheck();
        if ((*x).tun >= 24) {
            std::cout << "\nAnna luku 0-23 valilta!: ";
        }
        else if ((*x).tun < 0) {
            std::cout << "\nAnna positiivinen luku!: ";
        }
    } while ((*x).tun >= 24 || (*x).tun < 0);
    std::cout << "Anna ajan " << suoritettu << ". minuutit: ";
    do {
        (*x).min = intInputCheck();
        if ((*x).min >= 60) {
            std::cout << "\nAnna luku 0-59 valilta!: ";
        }
        else if ((*x).min < 0) {
            std::cout << "\nAnna positiivinen luku!: ";
        }
    } while ((*x).min >= 60 || (*x).min < 0);
    std::cout << "Anna ajan " << suoritettu << ". sekuntit: ";
    do {
        (*x).sek = intInputCheck();
        if ((*x).sek >= 60) {
            std::cout << "\nAnna luku 0-59 valilta!: ";
        }
        else if ((*x).sek < 0) {
            std::cout << "\nAnna positiivinen luku!: ";
        }
    } while ((*x).sek >= 60 || (*x).sek < 0);
    suoritettu++;
    return ;
}

//funktio, joka tulostaa arvot structista oikeaan muotoon
void tulostemuoto(aika_tyStruct x) {
    if (x.tun < 10){
        std::cout << "0" << x.tun;
    }
    else {
        std::cout << x.tun;
    }
    if (x.min < 10) {
        std::cout << ":0" << x.min;
    }
    else {
        std::cout << ":" << x.min;
    }
    if (x.sek < 10) {
        std::cout << ":0" << x.sek;
    }
    else {
        std::cout << ":" << x.sek;
    }
    std::cout << std::endl;
}

// Funktio, joka muuttaa tunnit, minuutit ja sekuntit sekunneiksi. Palauttaa sekunnit
int aika_sekunneiksi(aika_tyStruct y) {
    int sek = 0;
    sek += y.tun * 3600;
    sek += y.min * 60;
    sek += y.sek;
    return sek;
}

// Funktio, joka muuttaa sekuntit tunneiksi, minuuteiksi ja sekunteiksi. Ei palauta arvoa, koska kaikki arvot tallennetaan/palautetaan pointerin avulla
void sekunnit_ajaksi(int x, aika_tyStruct *y) {
    float tun, min, sek;
    tun = x / 3600.0;
    (*y).tun = std::floor(tun);
    min = (tun - std::floor(tun)) * 60.0;
    (*y).min = std::floor(min);
    sek = (min - std::floor(min)) * 60.0;
    (*y).sek = std::ceil(sek);
}

//Funktio, joka erottaa kaksi aikaa keskenään ja palauttaa erotetun arvon
aika_tyStruct aikojen_erotus(aika_tyStruct x, aika_tyStruct y) {
    int sekunnit1, sekunnit2, erotus;
    aika_tyStruct erotettu, *erotettu_p = &erotettu;
    sekunnit1 = aika_sekunneiksi(x);
    sekunnit2 = aika_sekunneiksi(y);
    if (sekunnit1 == sekunnit2) {
        erotettu = {0, 0, 0};
        return erotettu;
    }
    else if (sekunnit1 > sekunnit2) {
        erotus = sekunnit1 - sekunnit2;
    }
    else {
        erotus = sekunnit2 - sekunnit1;
    }
    sekunnit_ajaksi(erotus, erotettu_p);
    return erotettu;
}