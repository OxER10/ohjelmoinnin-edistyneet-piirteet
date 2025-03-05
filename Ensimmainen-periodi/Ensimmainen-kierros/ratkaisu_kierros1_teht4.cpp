//T4 Oskari järvinen
#include <iostream>

// Kutsutaan aliojhelmat ennen main
void swap(int *x, int *y);

// Globaali muuttuja helppoa muokkausta varten
// Tätä muokkaamalla voi vaihtaa kuinka monta numeroa käännetään
const int taulukkoKoko = 10;

int main() {
    int taulukko[taulukkoKoko], *taulukko_p = taulukko;
    for (int i = 0; i < taulukkoKoko; i++) {
        taulukko[i] = i + 1;
    }
    std::cout << "Taulukko ennen kaantoa: ";
    for (int i = 0; i < taulukkoKoko; i++) {
        std::cout << taulukko[i] << " ";
    }
    std::cout << std::endl;
    // For loop, joka kääntää numerot. Loopissa käytetty osoitinartimetriikkaa.
    for (int i = 0; i < taulukkoKoko / 2; i++) {
        int x = *(taulukko + i), y = *(taulukko + taulukkoKoko - i - 1);
        swap(&x, &y);
        *(taulukko + i) = x;
        *(taulukko + taulukkoKoko - i - 1) = y;
    }
    std::cout << "Taulukko kaannettyna: ";
    for (int i = 0; i < taulukkoKoko; i++) {
        std::cout << taulukko[i] << " ";
    }
    return 0;
}

// Swap funktio
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}