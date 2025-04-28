// Oskari Jarvinen 

#include"Henkilo.h"

class Opettaja : public Henkilo {
    private:
        std::string koulutusala;
        std::vector<std::string> kurssit;
    public:
        Opettaja();
        Opettaja(const std::string& tempNimi, int tempika, const Osoite& tempOsoite, const std::string& tempKoulutusala);
        Opettaja(const Opettaja& tempOpettaja);
        ~Opettaja();
        void setKoulutusala(const std::string& uusiKoulutusala);
        void setKurssit(const std::vector<std::string>& uusiKurssit);
        std::string getKoulutusala() const;
        std::vector<std::string> getKurssit() const;
        void tulostaTiedot() const;
        void poistaKurssi(const std::string& tempKurssi);
        void lisaaKurssi(const std::string& tempKurssi);
};