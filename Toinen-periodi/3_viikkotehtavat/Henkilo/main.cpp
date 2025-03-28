// Oskari Jarvinen 
// T1 2p
// T2 1p

#include <iostream>
#include <string>
#include"Henkilo.h"

int main() {

    // Constructor kokeilu
    // Destructor kokeilu luokalla ohjelman alussa
    Osoite matti;
    Henkilo pekka("Pekka", 20);




    // Henkilo constructor kokeilu
    matti.matinOsoite.setPostiosoite();
    

    // Henkilo constructor tarkistus
    matti.tulostaHenkilonTiedot();
    pekka.tulostaHenkilonTiedot();
    
    return 0;  
}