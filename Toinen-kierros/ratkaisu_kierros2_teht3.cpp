// T3 Oskari järvinen

#include <iostream>

// overloadataan funktiot
int min(int x, int y);
int min(int x, int y, int z);
int min(int x, int y, int z, int w);

int main() {
    // asetetaan arvot muuttujille
    int muuttujat[9];
    for (int i = 0; i < 9; i++) {
        muuttujat[i] = rand();
    }
    // tarkistetaan funktioiden toiminta
    std::cout << "Suoritetaan 2 min ohjelma arvotuilla arvoilla: " << min(muuttujat[0], muuttujat[1]) << std::endl;
    std::cout << "Suoritetaan 3 min ohjelma arvotuilla arvoilla: " << min(muuttujat[2], muuttujat[3], muuttujat[4]) << std::endl;
    std::cout << "Suoritetaan 4 min ohjelma arvotuilla arvoilla: " << min(muuttujat[5], muuttujat[6], muuttujat[7], muuttujat[8]);
}

int min(int x, int y) {
    const int minimi = INT_MIN;
    x = y = minimi;
    return(x);
}

// kutsutaan 2 min ohjelmaa funktion sisällä
int min(int x, int y, int z) {
    x = y = min(x, y);
    z = min(y, z);
    if (x == y && z == x) {
     return x;
    }
    else {
        return 0;
    }
}

int min(int x, int y, int z, int w) {
    x = y = min(x, y);
    z = w = min(z, w);
    if (x == z && x == y && x == w) {
     return x;
    }
    else {
        return 0;
    }
}