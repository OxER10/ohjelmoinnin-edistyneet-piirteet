// T3 Oskari järvinen
#include <iostream>

// Kutsutaan aliojhelmat ennen main
void lisaaja1(int x[]);
void lisaaja2(int x[]);

// Globaali muuttuja helppoa muokkausta varten
const int taulukkoKoko = 10;

int main() {
    int taulukko1[taulukkoKoko], taulukko2[taulukkoKoko], *taulukko_p = taulukko2;
    //For loopit, jotka alustaa taulukot
    for (int i = 0; i < taulukkoKoko; i++) {
        taulukko1[i] = 0;
    }
    for (int i = 0; i < taulukkoKoko; i++) {
        taulukko2[i] = 0;
    }
    std::cout << "Taulukko1 ennen lisaaja1 kutsua: ";
    for (int i = 0; i < taulukkoKoko; i++) {
        std::cout << taulukko1[i] << " ";
    }
    std::cout << std::endl;
    lisaaja1(taulukko1);
    std::cout << "\nTaulukko2 ennen lisaaja2 kutsua: ";
    for (int i = 0; i < taulukkoKoko; i++) {
        std::cout << taulukko2[i] << " ";
    }
    std::cout << std::endl;
    lisaaja2(taulukko2);
    return 0;
}

// Aliohjelma lisää jokaiseen taulukon lokeron arvoon +1
// Aliohjelmassa käytetään perustaulukkokäsittelyä
void lisaaja1(int x[taulukkoKoko]) {
    std::cout << "Taulukko1 lisaaja1 kutsun jalkeen: ";
    for (int i = 0; i < taulukkoKoko; i++) {
        x[i]++;
        std::cout << x[i] << " ";
    }  
}

// Aliohjelma lisää jokaiseen taulukon lokeron arvoon +1
// Aliohjelmassa käytetään osoitinartimetriikkaa
void lisaaja2(int *x) {
    std::cout << "Taulukko2 lisaaja2 kutsun jalkeen: ";
    for (int i = 0; i < taulukkoKoko; i++) {
        *(x + i) = *(x + i) + 1;
        std::cout << x[i] << " ";
    }  
}