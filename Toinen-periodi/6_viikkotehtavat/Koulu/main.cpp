// Oskari Jarvinen 

#include"Henkilo.h"
#include"Koulu.h"

int main() {
    // Tehtävä 1: Protected testi
    // Private
    // Vs code ilmoittaa, että muuttujaa ei voi käyttää, koska se on yksityinen.
    Opiskelija testi("Oskari Opiskelija", 22, Osoite("Alapeusonkatu 69", "33540", "Tampere"), "12345", 38);
    std::cout << "Opiskelijan tiedot ennen vaihtoa:\n";
    testi.tulostaTiedot();

    // Protected
    // Nyt muuttujia voi käyttää ja asettaa opiskelija-luokan sisällä
    testi.vaihdaTiedot("Veeti Opiskelija", 26);
    std::cout << "Opiskelijan tiedot vaihdon jälkeen:\n";
    testi.tulostaTiedot();

    // Tehtävä 5: Virtual metodi
    std::cout << "Virtuaalimetodien testaus: \n";
    std::vector<Henkilo*> henkilot;

    // Luodaan monta eri henkilötyyppiä
    henkilot.push_back(new Henkilo("Anne", 20, Osoite("Koulukatu 37", "54332", "Janakkala")));
    henkilot.push_back(new Opiskelija("Oskari Opiskelija", 22, Osoite("Teiskontie 22", "33540", "Tampere"), "432622", 39));
    henkilot.push_back(new Opettaja("Teuvo Opettaja", 42, Osoite("Sammonkatu 69", "33540", "Tampere"), "Tietotekniikka"));

    // Kutsutaan tulostaTiedot metodia, jokaisella tyypillä.
    for (auto henkilo : henkilot) {
        henkilo->tulostaTiedot();
    }
    // Metodit kutsutaan oikein. Opettajan tulostaTiedot on eri kuin opiskelijan tulostaTiedot.

    // Kun tulostaTiedot() on merkitty virtual-avainsanalla, ohjelma kutsuu kunkin olion oman luokan toteutusta eikä kantaluokan metodia, vaikka käytetään Henkilo-osoitinta. 
    // Dynaaminen sidonta tarkoittaa, että ohjelman suorituksen aikana määritetään, mitä metodia oikeasti kutsutaan. 
    // Tämä on keskeistä polymorfismissa, sillä se mahdollistaa eri aliluokkien olioiden käsittelyn samalla tavalla kantaluokan kautta.

    // Tehtävät 2-4: Koulu luokka
    Koulu koulu;
    int valinta = 0;
    std::cout << "\nKoululoop:\n";
    koulu.setKoulunNimi("Tampereen ammattikorkeakoulu");
    do {
        std::cout << "Koulu: " << koulu.getKoulunNimi() << "\n";
        std::cout << "1. Lisää opettaja\n";
        std::cout << "2. Lisää opettajalle kurssi\n";
        std::cout << "3. Lisää opiskelija\n";
        std::cout << "4. Lisää opiskelijalle kurssi\n";
        std::cout << "5. Tulosta opettajat\n";
        std::cout << "6. Tulosta opiskelijat\n";
        std::cout << "7. Tulosta koulun tiedot\n";
        std::cout << "0. Lopeta\n";
        std::cout << "Valinta: ";
        std::cin >> valinta;
        switch (valinta) {
            case 1:
                koulu.lisaaOpettaja();
                break;
            case 2:
                koulu.lisaaOpettajalleKurssi();
                break;
            case 3:
                koulu.lisaaOpiskelija();
                break;
            case 4:
                koulu.lisaaOpiskelijalleKurssi();
                break;
            case 5:
                koulu.tulostaOpettajat();
                break;
            case 6:
                koulu.tulostaOpiskelijat();
                break;
            case 7:
                koulu.tulostaKaikkiTiedot();
                break;
            case 0:
                std::cout << "Ohjelma lopetetaan...\n";
                break;
            default:
                std::cout << "Virheellinen valinta!\n";
        }
    } while (valinta != 0);

    return 0;  
}