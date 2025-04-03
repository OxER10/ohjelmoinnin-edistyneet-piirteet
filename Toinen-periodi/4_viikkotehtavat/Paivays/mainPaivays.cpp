// Oskari Jarvinen 
// T1 1p
// T2 1p

#include "Paivays.h"

int main() {

    // Olion luonti ilman constructor parametreja
    Kalenterimerkinta muistutus;
    muistutus.tulostaMerkinta();

    // Olion luonti constructor parametreilla
    Paivays kalenteripaiva(3, 10, 2002);
    Kalenterimerkinta syntymapaiva(kalenteripaiva, "Tanaan on minun syntymapaiva!!", true);
    syntymapaiva.tulostaMerkinta();

    // Kopiorakentaja
    Kalenterimerkinta kopio(syntymapaiva);
    kopio.tulostaMerkinta();

    // Olioiden välittäminen funktioille/metodeille sekä const –sanan käyttö funktioiden/metodien viittausparametrien yhteydessä
    doSomethingArvoparametri(kopio);
    kopio.tulostaMerkinta();
    doSomethingViittausparametri(kopio);
    kopio.tulostaMerkinta();

    // T2 1p
    // Ensimmäistä versiota ei tulisi käyttää, koska se ei muuta alkuperäistä arvoa. Se vain ns "kopioi" olion ja muutokset säilyy vain funtkion sisällä
    // Jos haluaa muuttaa parametrina saatua arvoa, arvoon pitää osoittaa.

    doSomethingViittausparametriConst(kopio);
    kopio.tulostaMerkinta();
    // Olio pystyy nyt pystyy kutsumaan vain Get-metodeja, koska ne eivät muuta arvoja. Mitään arvoja muutavaa ei voi kustua, eli alkuperäinen arvo pysyy aina samana, vaikka siihen osoitetaan

}