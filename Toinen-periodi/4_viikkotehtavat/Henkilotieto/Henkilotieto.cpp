// Oskari Jarvinen
// T3 2p
// T4 1p

#include "Henkilotieto.h"

// Parametrirakentaja:
// Henkilo::Henkilo(std::string tempNimi, int tempIka) {
//     std::cout << "Rakentajaa kutsuttu!\n";
//     nimi = tempNimi;
//     ika = tempIka;
// }

// Kopiorakentaja:
Henkilo::Henkilo(const std::string &tempNimi, const int &tempIka) {
    std::cout << "Rakentajaa kutsuttu!\n";
    nimi = tempNimi;
    ika = tempIka;
}

Henkilo::~Henkilo() {
    std::cout << "Purkajaa kutsuttu!\n";
}

void Henkilo::setNimi(std::string uusiNimi) {
    nimi = uusiNimi;
}

void Henkilo::setIka(int uusiIka) {
    ika = uusiIka;
}

std::string Henkilo::getNimi() const { return nimi; }

int Henkilo::getIka() const { return ika; }

void Henkilo::tulostaTiedot(int i) const {
    std::cout << i + 1 << ". Henkilon:\n";
    std::cout << "Nimi: " << nimi << "\n";
    std::cout << "Ika: " << ika << "\n\n";
}

// Tehtävän 1 silmukka
std::vector<Henkilo> silmukka() {
    bool lopeta = false;
    std::vector<Henkilo> henkilot;
    do {
        std::string nimi;
        int ika, numero{0};
        char komento;
        bool loydetty = false;
        std::cout << "Anna komento: L (Lisaa uusi henkilo), T (Tulosta henkilot), P (Poista henkilo) tai Q (Lopeta):";
        std::cin >> komento;
        switch (komento){
            case 'L':
            case 'l':
                std::cout << "Ilmoita henkilon nimi: ";
                std::cin.get();
                std::getline(std::cin, nimi);
                std::cout << "Ilmoita henkilon ika: ";
                std::cin >> ika;
                henkilot.push_back(Henkilo(nimi, ika));
                break;
            case 'T':
            case 't':
                for (int i = 0; i < henkilot.size(); i++) {
                    henkilot[i].tulostaTiedot(i);
                }
                break;
            case 'p':
            case 'P':
                std::cout << "Ilmoita poistettavan henkilon nimi: ";
                std::cin.get();
                std::getline(std::cin, nimi);
                for (numero; numero < henkilot.size(); numero++) {
                    if (henkilot[numero].getNimi() == nimi) {
                        loydetty = true;
                        break;
                    }
                }
                if (loydetty) {
                    henkilot.erase(henkilot.begin()+numero);
                }
                else {
                    std::cout << "Henkiloa ei loydetty\n";
                }
                break;
            case 'Q':
            case 'q':
                lopeta = true;
                break;
            default:
                std::cout << "Ilmoita oikea komento!\n";
                break;
        }
    } while (!lopeta);
    return henkilot;
}
