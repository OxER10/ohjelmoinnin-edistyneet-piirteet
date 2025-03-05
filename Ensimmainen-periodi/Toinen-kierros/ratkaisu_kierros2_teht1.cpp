// T1 Oskari järvinen

#include <iostream>
#include <cmath>

bool onKolmiollinen(float x, float y, float z, int* w);
float floatInputCheck();

// enum varmistamaan kolmiotyyppi
enum kolmiotyyppi {
        tasakylkinen = 1,
        suorakulmainen,
        epasaannollinen,
        tasasivuinen
};

int main() {
    bool onkoKolmio;
    int kolmiotyyppi_numero;
    float sivu[3];
    for (int i : sivu) {
        do{
            std::cout << "Anna kolmion " << i + 1 << ". sivun pituus: ";
            sivu[i] = floatInputCheck();
        } while(sivu[i] < 1);
    }
    // Kutsutaan funktiota, joka palauttaa bool arvon ja asettaa int arvon oikeaa tulostusta varten
    onkoKolmio = onKolmiollinen(sivu[0], sivu[1],sivu[2], &kolmiotyyppi_numero);
    if (onkoKolmio == true) {
        // switch, joka lukee asetetun arvon ja tulostaa sen mukaan
        switch (kolmiotyyppi_numero) {
            case 1:
                std::cout << "Annetuista sivuista voidaan muodostaa tasakylkinen kolmio.";
                break;
            case 2:
                std::cout << "Annetuista sivuista voidaan muodostaa suorakulmainen kolmio.";
                break;
            case 3:
                std::cout << "Annetuista sivuista voidaan muodostaa epasaannollinen kolmio.";
                break;
            case 4:
                std::cout << "Annetuista sivuista voidaan muodostaa tasasivuinen kolmio.";
                break;
        }
    }
    else {
        std::cout << "Annetuista sivuista ei voida muodostaa kolmiota.";
    }
    return 0;
}


// sivujen tarkistusfunktio, joka palauttaa bool arvon ja asettaa pointerille oikean arvon kolmiotyypin valintaa varten
bool onKolmiollinen(float x, float y, float z, int* w) {
    enum kolmiotyyppi valinta;
    if (x + y > z && x + z > y && y + z > x) {
        if (x == y && y == z) {
        valinta = tasakylkinen;
        }
        else if (pow(x, 2) + pow(y, 2)== pow(z, 2) || pow(x, 2) + pow(z, 2) == pow(y, 2) || pow(y, 2) + pow(z, 2) == pow(x, 2)) {
        valinta = suorakulmainen;
        }
        else if (x == y || y == z || x == z) {
        valinta = tasasivuinen;
        }
        else {
        valinta = epasaannollinen;
        }
    }
    else {
        return false;
    }
    // Switch joka palauttaa halutut arvot
    switch (valinta) {
        case 1:
            *w = 1;
            return true;
            break;
        case 2:
            *w = 2;
            return true;
            break;
        case 3:
            *w = 3;
            return true;
            break;
        case 4:
            *w = 4;
            return true;
            break;
        default:
            std::cout << "Onnistuit jollain ihmeella rikkoon mun koodin >:(";
            return 0;
    }

}

// Käyttäjän syötteen tarkistus. Onnea tämän rikkomiseen
float floatInputCheck() {
    float input;
    bool error;
    do{
        std::cin >> input;
        if (std::cin.fail()){
            std::cout << "Virhe! Tarkista syote!" << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n'); 
        }
        else if (input <= 0) {
            std::cout << "Anna positiivinen luku!" << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n'); 
        }
        else {
            error = false;
        }
    }while (error == true);
    return input;
}