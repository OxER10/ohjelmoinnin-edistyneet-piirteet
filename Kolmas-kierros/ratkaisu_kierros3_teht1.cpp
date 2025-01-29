// T1 OSkari Järvinen

#include <iostream>

// Kutsutaan funktiota
void sekunnit_ajaksi(int x, int* y);

int main(){
    int sekunnit, aika[3] = {0};
    int* aika_p = aika;
    std::cout << "Ilmoita kuinka monta sekuntia: ";
    std::cin >> sekunnit;
    sekunnit_ajaksi(sekunnit, aika_p);
    std::cout << sekunnit << " sekuntia on " << aika[0] << " tuntia " << aika[1] << " minuuttia " << aika[2] << " sekuntia.";
    return 0;
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