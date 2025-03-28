// Oskari Jarvinen 
// T1 1p
// T2 2p

#include<string>

// Luotu osoite olio
class Osoite {
    private:
        std::string katuosoite;
        std::string postinumero;
        std::string kunta;
    public:
        Osoite();
        Osoite(std::string tempKatuosoite, std::string tempPostinumero, std::string tempKunta);
        void setKatuosioite(std::string uusiKatuosoite);
        void setPostinumero(std::string uusiPostinumero);
        void setKunta(std::string uusiKunta);
        std::string getKatuosoite() const;
        std::string getPostinumero() const;
        std::string getKunta() const;
};

class Henkilo {
    private:
        std::string nimi;
        int ika;
        Osoite osoite;
    public:
        Henkilo();
        Henkilo(std::string tempNimi, int tempIka);
        Henkilo(std::string tempNimi, int tempIka, Osoite tempOsoite);
        void tulostaTiedot() const;
        void setIka(int uusiIka);
        void setNimi(std::string uusiNimi);
        void setOsoite(Osoite tempOsoite);
        int getIka() const;
        std::string getNimi() const;
        Osoite getOsoite() const;
};