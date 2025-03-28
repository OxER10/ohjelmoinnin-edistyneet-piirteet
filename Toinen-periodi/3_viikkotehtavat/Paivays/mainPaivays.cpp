// Oskari Jarvinen 
// T1 2p
// T2 1p

#include "Paivays.h"

int main() {

    // Constructor
    Paivays testi;
    Paivays testi2(17, 3, 2025);
    // Purkajaa kutsuttiin ohjelman lopuksi

    // Destructor kokeilu if lauseen sisällä
    int jos = 2;
    if (jos == 2) {
        Paivays jostesti;
    }
    // Purkajaa kutsuttiin heti if lauseen loputtua

    // Destructor kokeilu for loopin sisällä
    for (int i = 0; i < 3; i++) {
        Paivays fortesti;
    }
    // Purkajaa kutsuttiin jokaisen silmukan suorituksen jälkeen

    // Destructor kokeilu while loopin sisällä
    while (jos < 5) {
        Paivays whiletesti;
        jos++;
    }
    // Purkajaa kutsuttiin jokaisen silmukan suorituksen jälkeen

    // Destructor testi funktion sisällä
    testi.destructorTest();
    // Purkajaa kutsuttiin heti kun aliohjelma oli suoritettu
    
    // addPaiva olion testaus
    for (int i = 0; i < 3; i++) {
        testi.addPaiva();
        testi.tulostaPaivays();
    }
    
    // addPaiva olion testaus
    for (int i = 0; i < 3; i++) {
        testi2.addPaiva();
        testi2.tulostaPaivays();
    }
}