// Oskari Jarvinen 
// T1 1p
// T3 2p

#include "Paivays.h"

int main() {

    // Olion luonti ilman constructor parametreja
    Kalenterimerkinta muistutus;
    muistutus.tulostaMerkinta();

    // Olion luonti constructor parametreilla
    Paivays kalenteripaiva(3, 10, 2002);
    Kalenterimerkinta syntymapaiva(kalenteripaiva, "Tanaan on minun syntymapaiva!!", true);
    syntymapaiva.tulostaMerkinta();

    // Kayttajan luoma kalenterimerkinta-olio
    Kalenterimerkinta kayttaja;
    kayttaja.kysyTiedot();
    kayttaja.tulostaMerkinta();
}