// Oskari Jarvinen 
// T1 2p
// T2 1p

#include <iostream>
#include <string>
#include"Henkilo.h"
#include"Henkilo.cpp"

int main() {
    // Constructor kokeilu
    // Destructor kokeilu luokalla ohjelman alussa
    Henkilo matti;
    Henkilo pekka("Pekka", 20);
    // Purkajaa kutsuttiin ohjelman lopuksi

    // Destructor kokeilu if lauseen sisällä
    int jos = 2;
    if (jos == 2) {
        Henkilo jostesti;
    }
    // Purkajaa kutsuttiin heti if lauseen loputtua

    // Destructor kokeilu for loopin sisällä
    for (int i = 0; i < 3; i++) {
        Henkilo fortesti;
    }
    // Purkajaa kutsuttiin jokaisen silmukan suorituksen jälkeen

    // Destructor kokeilu while loopin sisällä
    while (jos < 5) {
        Henkilo whiletesti;
        jos++;
    }
    // Purkajaa kutsuttiin jokaisen silmukan suorituksen jälkeen

    // Destructor testi funktion sisällä
    matti.destructorTest();
    // Purkajaa kutsuttiin heti kun aliohjelma oli suoritettu
    
    // Henkilo constructor tarkistus
    matti.tulostaHenkilonTiedot();
    pekka.tulostaHenkilonTiedot();

    // Taulukko olion luonti
    Henkilo henkilot[10];
    // Contructor kutsuu tyhjää rakentajaa. Jokainen taulukon arvoista saa parametrittoman rakentajan arvot

    // Dynaaminen olio
    Henkilo* Pekka = new Henkilo("Pekka", 20);
    // Dynaamista oliota ei tuhota

    // Dynaaminen olio pitää itse tuhota
    delete Pekka;
    // Purkaja kutsuttiin

    return 0;  
}