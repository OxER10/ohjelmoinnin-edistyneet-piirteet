// Oskari Jarvinen 

#include"Henkilo.h"

class Opiskelija : public Henkilo {
    private:
        std::string opNro;
        std::vector<std::string> suoritetutKurssit;
        int opintopisteet;
    public:
        Opiskelija();
        Opiskelija(const std::string& tempNimi, int ika, const Osoite& tempOsoite, const std::string& tempOpNro, int tempOpintopisteet);
        Opiskelija(const Opiskelija& tempOpiskelija);
        ~Opiskelija();
        void setOpNro(const std::string& uusiOpNRo);
        void setSuoritetutKurssit(const std::vector<std::string>& uusiSuoritetutKurssit);
        void setOpintopisteet(const int& uusiOpintopisteet);
        std::string getOpNro() const;
        std::vector<std::string> getSuoritetutKurssit() const;
        int getOpintopisteet() const;
        void lisaaKurssi(const std::string& tempKurssi);
        void tulostaTiedot() const;
        void lisaaOpintopisteita(const int& tempOpintopisteet);
};