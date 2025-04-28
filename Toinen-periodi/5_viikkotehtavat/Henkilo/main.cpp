// Oskari Jarvinen 

#include"Henkilo.h"
#include"Opettaja.h"
#include"Opiskelija.h"

int main() {
    // Opettaja oletusrakentaja
    Opettaja opettajaMatti;
    opettajaMatti.tulostaTiedot();

    // Opetaja parametrirakentaja
    Opettaja teuvo("Teuvo Opettaja", 42, Osoite("Sammonkatu 69", "33540", "Tampere"), "Tietotekniikka");
    teuvo.lisaaKurssi("Ohjelmoinnin perusteet");
    teuvo.lisaaKurssi("Edistynyt ohjelmointi");
    teuvo.lisaaKurssi("Pelikehityksen perusteet");
    teuvo.tulostaTiedot();
    teuvo.poistaKurssi("Pelikehityksen perusteet");

    // Opettaja kopiorakentaja
    Opettaja teuvo2(teuvo);
    teuvo2.poistaKurssi("Pelikehityksen perusteet");
    teuvo2.tulostaTiedot();

    // Opiskelija oletusrakentaja
    Opiskelija opiskelijaMatti;
    opiskelijaMatti.tulostaTiedot();

    // Opiskelija parametrirakentaja
    Opiskelija oskari("Oskari Opiskelija", 22, Osoite("Teiskontie 22", "33540", "Tampere"), "432622", 39);
    oskari.lisaaKurssi("Alykkaat jarjestelmat jatko");
    oskari.lisaaOpintopisteita(12);
    oskari.tulostaTiedot();

    // Opiskelija kopiorakentaja
    Opiskelija matkija(opiskelijaMatti);
    matkija.lisaaKurssi("Alykkaat jarjestelmat");
    matkija.lisaaOpintopisteita(10);
    matkija.tulostaTiedot();

    // Henkilo-osoittimet
    std::cout << "\nOsoittimet: \n";
    std::vector<Henkilo*> henkilot;
    henkilot.push_back(new Henkilo("Anne", 20));
    henkilot.push_back(new Henkilo("Kalle", 30));
    henkilot.push_back(new Opettaja(teuvo));
    henkilot.push_back(new Opettaja("Kalle Opettaja", 67, Osoite("Katajapolku", "63540", "Kuopio"), "Biologia"));
    henkilot.push_back(new Opiskelija(oskari));
    henkilot.push_back(new Opiskelija());

    // Kaikki henkiloluokan metodit voi kutsua. Ei muuta
    henkilot[4]->getIka();
    henkilot[3]->setIka(12);

    for (auto h : henkilot) {
        h->tulostaHenkiloTiedot();
    }

    std::cout << "\nOsoitinpurkajakutsut:\n";
    for (auto object : henkilot) {
        delete object;
    }

    std::cout << "\nOliopurkajakutstut kun out of scope:\n";

    return 0;  
}