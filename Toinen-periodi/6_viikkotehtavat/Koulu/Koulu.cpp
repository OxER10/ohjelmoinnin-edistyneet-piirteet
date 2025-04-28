// Oskari Jarvinen 

#include"Koulu.h"

Koulu::Koulu() {
    koulunNimi = "tamk";
}

Koulu::Koulu(const std::vector<Opettaja>& tempOpettajat, const std::vector<Opiskelija>& tempOpiskelijat, const std::string& tempKoulunNimi) {
    koulunNimi = tempKoulunNimi;
    for (const auto& opettaja : tempOpettajat) {
        opettajat.push_back(new Opettaja(opettaja));
    }
    for (const auto& opiskelija : tempOpiskelijat) {
        opiskelijat.push_back(new Opiskelija(opiskelija));
    }
}

Koulu::Koulu(const Koulu& tempKoulu) {
    koulunNimi = tempKoulu.koulunNimi;
    for (const auto& opettaja : tempKoulu.opettajat) {
        opettajat.push_back(new Opettaja(*opettaja));
    }
    for (const auto& opiskelija : tempKoulu.opiskelijat) {
        opiskelijat.push_back(new Opiskelija(*opiskelija));
    }
}

Koulu::~Koulu() {
    for (auto opettaja : opettajat) {
        delete opettaja;
    }
    
    for (auto opiskelija : opiskelijat) {
        delete opiskelija;
    }
}

void Koulu::setOpettajat(const std::vector<Opettaja*>& tempOpettajat) {
    // Poista edelliset, koska dynaamisessa muistissa
    for (auto opettaja : opettajat) {
        delete opettaja;
    }
    for (const auto& opettaja : tempOpettajat) {
        opettajat.push_back(new Opettaja(*opettaja));
    }
}

void Koulu::setOpiskelijat(const std::vector<Opiskelija*>& tempOpiskelijat) {
    // Poista edelliset, koska dynaamisessa muistissa
    for (auto opiskelija : opiskelijat) {
        delete opiskelija;
    }
    for (const auto& opiskelija : tempOpiskelijat) {
        opiskelijat.push_back(new Opiskelija(*opiskelija));
    }
}

void Koulu::setKoulunNimi(const std::string& tempKoulunNimi) {
    koulunNimi = tempKoulunNimi;
}

std::vector<Opettaja*> Koulu::getOpettajat() { return opettajat; }

std::vector<Opiskelija*> Koulu::getOpiskelijat() { return opiskelijat; }

std::string Koulu::getKoulunNimi() { return koulunNimi; }

void Koulu::lisaaOpettaja() {
    std::string tempNimi, tempKoulutusala, tempKatuosoite, tempPostinumero, tempKunta;
    int tempIka;
    std::cout << "\nLisää opettaja\n";
    std::cout << "Anna nimi: ";
    std::cin.ignore();
    std::getline(std::cin, tempNimi);
    std::cout << "Anna ika: ";
    std::cin >> tempIka;
    std::cout << "Anna katuosoite: ";
    std::cin.ignore();
    std::getline(std::cin, tempKatuosoite);
    std::cout << "Anna postinumero: ";
    std::getline(std::cin, tempPostinumero);
    std::cout << "Anna kunta: ";
    std::getline(std::cin, tempKunta);
    std::cout << "Anna koulutusala: ";
    std::getline(std::cin, tempKoulutusala);
    Osoite tempOsoite(tempKatuosoite, tempPostinumero, tempKunta);

    Opettaja* uusiOpettaja = new Opettaja(tempNimi, tempIka, tempOsoite, tempKoulutusala);
    opettajat.push_back(uusiOpettaja);
}

void Koulu::lisaaOpiskelija() {
    std::string tempNimi, opNro, tempKatuosoite, tempPostinumero, tempKunta;
    int tempIka, opintopisteet;
    std::cout << "\nLisaa opiskelija\n";
    std::cout << "Anna nimi: ";
    std::cin.ignore();
    std::getline(std::cin, tempNimi);
    std::cout << "Anna ika: ";
    std::cin >> tempIka;
    std::cout << "Anna Katuosoite: ";
    std::cin.ignore();
    std::getline(std::cin, tempKatuosoite);
    std::cout << "Anna postinumero: ";
    std::getline(std::cin, tempPostinumero);
    std::cout << "Anna kunta: ";
    std::getline(std::cin, tempKunta);
    std::cout << "Anna opiskelijanumero: ";
    std::getline(std::cin, opNro);
    std::cout << "Anna opintopisteet: ";
    std::cin >> opintopisteet;
    Osoite tempOsoite(tempKatuosoite, tempPostinumero, tempKunta);

    Opiskelija* uusiOpiskelija = new Opiskelija(tempNimi, tempIka, tempOsoite, opNro, opintopisteet);
    opiskelijat.push_back(uusiOpiskelija);
}

void Koulu::lisaaOpettajalleKurssi() {
    
    int valinta;
    std::string kurssi;
    if (opettajat.empty()) {
        std::cout << "Ei opettajia listalla. Lisää ensin opettaja!\n";
        return;
    }
    std::cout << "\nValitse opettaja (1-" << opettajat.size() << "):\n";
    for (size_t i = 0; i < opettajat.size(); i++) {
        std::cout << (i+1) << ". " << opettajat[i]->getNimi() << "\n";
    }
    std::cout << "Valinta: ";
    std::cin >> valinta;
    if (valinta < 1 || valinta > opettajat.size()) {
        std::cout << "Virheellinen valinta!\n";
        return;
    }
    std::cout << "Anna kurssin nimi: ";
    std::cin.ignore();
    std::getline(std::cin, kurssi);
    opettajat[valinta-1]->lisaaKurssi(kurssi);
    std::cout << "Kurssi lisatty opettajalle: " << opettajat[valinta-1]->getNimi() << "\n";
}

void Koulu::lisaaOpiskelijalleKurssi() {
    int valinta;
    std::string kurssi;
    if (opiskelijat.empty()) {
        std::cout << "Ei opiskelijoita listalla. Lisaa ensin opiskelija.\n";
        return;
    }
    std::cout << "\nValitse opiskelija (1-" << opiskelijat.size() << "):\n";
    for (size_t i = 0; i < opiskelijat.size(); i++) {
        std::cout << (i+1) << ". " << opiskelijat[i]->getNimi() << "\n";
    }
    std::cout << "Valinta: ";
    std::cin >> valinta;
    if (valinta < 1 || valinta > opiskelijat.size()) {
        std::cout << "Virheellinen valinta!\n";
        return;
    }
    std::cout << "Anna kurssin nimi: ";
    std::cin.ignore();
    std::getline(std::cin, kurssi);
    opiskelijat[valinta-1]->lisaaKurssi(kurssi);
    std::cout << "Kurssi lisätty opiskelijalle " << opiskelijat[valinta-1]->getNimi() << "\n";
}

void Koulu::tulostaKaikkiTiedot() const {
    std::cout << "Koulun nimi: " << koulunNimi << "\n";
    std::cout << "Opettajien lukumaara: " << opettajat.size() << "\n";
    std::cout << "Opiskelijoiden lukumaara: " << opiskelijat.size() << "\n";
    tulostaOpettajat();
    tulostaOpiskelijat();
}

void Koulu::tulostaOpettajat() const {
    std::cout << "Opettajat: \n";
    if (opettajat.empty()) {
        std::cout << "Ei opettajia listalla.\n";
        return;
    }
    for (auto opettaja : opettajat ) {
        opettaja->tulostaTiedot();
    }
}

void Koulu::tulostaOpiskelijat() const {
    if (opiskelijat.empty()) {
        std::cout << "Ei opiskelijoita listalla.\n";
        return;
    }
    std::cout << "Opiskelijat: \n";
    for (auto opiskelija : opiskelijat ) {
        opiskelija->tulostaTiedot();
    }
}