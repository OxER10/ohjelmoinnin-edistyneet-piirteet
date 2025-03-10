// Oskari Jarvinen 
// T2 2p
// T3 1p

#include "Paivays.h"

int main() {
    // Olioiden alustus
    Paivays tanaan, huomenna, kayttajan, laskuri;

    // Tänään olion arvot
    tanaan.setPaiva(11);
    tanaan.setKuukausi(3);
    tanaan.setVuosi(2025);

    // Huomenna olion arvot
    huomenna.setPaiva(12);
    huomenna.setKuukausi(3);
    huomenna.setVuosi(2025);

    // Laskuri olion arvot testausta varten
    laskuri.setPaiva(27);
    laskuri.setKuukausi(2);
    laskuri.setVuosi(2024);

    // Olioiden tulostus
    tanaan.tulostaPaivays();
    huomenna.tulostaPaivays();
    laskuri.tulostaPaivays();

    // addPaiva olion testaus laskuri oliolla
    for (int i = 0; i < 3; i++) {
        laskuri.addPaiva();
        laskuri.tulostaPaivays();
    }

    // Köyttäjän olio
    kayttajan.kayttajanPaiva();
    kayttajan.tulostaPaivays();
    
    // addPaiva olion testaus käyttäjän syötteellä
    for (int i = 0; i < 3; i++) {
        kayttajan.addPaiva();
        kayttajan.tulostaPaivays();
    }
}