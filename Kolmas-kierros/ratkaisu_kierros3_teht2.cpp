// T2 OSkari Järvinen

#include <iostream>

// Kutsutaan funktiota
int aika_sekunneiksi(int x, int y, int z);
void sekunnit_ajaksi(int x, int* y);

int main() {
    int sekunnit, aika[3];
    int* aika_p = aika;
    std::cout << "Ilmoita kuinka monta tuntia: ";
    std::cin >> aika [0];
    std::cout << "Minuuttia: ";
    std::cin >> aika [1];
    std::cout << "Sekuntia: ";
    std::cin >> aika [2];
    sekunnit = aika_sekunneiksi(aika[0], aika[1], aika[2]);
    std::cout << aika[0] << " tuntia " << aika[1] << " minuuttia " << aika[2] << " sekuntia on " << sekunnit << " sekuntia, joka on puolestaan " ;
    sekunnit_ajaksi(sekunnit, aika_p);
    std::cout << aika[0] << " tuntia " << aika[1] << " minuuttia " << aika[2] << " sekuntia.";
}

// Funktio, joka muuttaa tunnit, minuutit ja sekuntit sekunneiksi. Palauttaa sekunnit
int aika_sekunneiksi(int x, int y, int z) {
    int sek = 0;
    sek += x * 3600;
    sek += y * 60;
    sek += z;
    return sek;
}

// Funktio, joka muuttaa sekuntit tunneiksi, minuuteiksi ja sekunteiksi. Ei palauta arvoa, koska kaikki arvot tallennetaan/palautetaan pointerin avulla
void sekunnit_ajaksi(int x, int* y) {
    float tun, min, sek;
    tun = x / 3600.0;
    *y = std::floor(tun);
    min = (tun - std::floor(tun)) * 60.0;
    *(y + 1) = std::floor(min);
    sek = (min - std::floor(min)) * 60.0;
    *(y + 2) = std::ceil(sek);
}