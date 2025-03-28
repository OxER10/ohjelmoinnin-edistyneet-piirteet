// Oskari Jarvinen 
// T1 1p
// T2 2p

#include <iostream>
#include <string>
#include"Henkilo.h"

int main() {

    // Constructor olion luonti
    Osoite pekanOsoite("Kotikatu 2", "12345", "Kotikunta");
    Henkilo pekka("Pekka", 20, pekanOsoite);

    // Tulostetaan pekka-olion tiedot osoitteen kanssa
    pekka.tulostaTiedot();
    
    // Olioiden luoni settereitä varten
    Osoite anninOsoite;
    Henkilo anni;

    // Asetetaan tiedot settereillä
    anninOsoite.setKatuosioite("Aurinkokuja 5");
    anninOsoite.setPostinumero("55243");
    anninOsoite.setKunta("Iloinen");
    anni.setNimi("Anni");
    anni.setIka(26);
    anni.setOsoite(anninOsoite);

    // Tulostetaan anni-olion tiedot osoitteen kanssa
    anni.tulostaTiedot();

    return 0;  
}