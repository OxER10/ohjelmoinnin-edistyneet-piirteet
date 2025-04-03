// Oskari Jarvinen
// T3 2p
// T4 1p

#include <iostream>
#include <string>
#include <vector>

class Henkilo {
    private:
        std::string nimi;
        int ika;
    public:
        // Parametrirakentaja:
        // Henkilo(std::string tempNimi, int tempIka);
        // Kopiorakentaja:
        Henkilo(const std::string &tempNimi, const int &tempIka);
        ~Henkilo();
        void setNimi(std::string uusiNimi);
        void setIka(int uusiNimi);
        std::string getNimi() const;
        int getIka() const;
        void tulostaTiedot(int i) const;
};

std::vector<Henkilo> silmukka();