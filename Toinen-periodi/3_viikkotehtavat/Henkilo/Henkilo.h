// Oskari Jarvinen 
// T1 2p
// T2 1p

#include<string>
#pragma once

class Henkilo {
    private:
        std::string nimi;
        int ika;
        Osoite osoite;
    public:
        Henkilo();
        Henkilo(std::string tempNimi, int tempIka);
        ~Henkilo();
        void destructorTest();
        void tulostaHenkilonTiedot() const;
        void tervehdi() const;
        void setIka(int uusiIka);
        int getIka() const;
        void setNimi(std::string uusiNimi);
        std::string getNimi() const;
};

class Osoite : public Henkilo {
    private:
        std::string katuosoite;
        std::string postinumero;
        std::string kunta;

    public:
        Osoite();
        Osoite(std::string tempKatuosoite, std::string tempPostinumero, std::string tempKunta);
        void tulostaOsoiteTiedot() const;
        void setKatuosioite(std::string uusiKatuosoite);
        void setPostinumero(std::string uusiPostinumero);
        void setKunta(std::string uusiKunta);
        std::string getKatuosoite() const;
        std::string getPostinumero() const;
        std::string getKunta() const;
};