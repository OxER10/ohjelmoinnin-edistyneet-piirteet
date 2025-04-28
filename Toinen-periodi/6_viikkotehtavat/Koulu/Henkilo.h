// Oskari Jarvinen 

#pragma once

#include<iostream>
#include<string>
#include<vector>

// Luotu osoite olio
class Osoite {
    private:
        std::string katuosoite;
        std::string postinumero;
        std::string kunta;
    public:
        Osoite();
        Osoite(std::string tempKatuosoite, std::string tempPostinumero, std::string tempKunta);
        Osoite(const Osoite& tempOsoite);
        ~Osoite();
        void setKatuosioite(std::string uusiKatuosoite);
        void setPostinumero(std::string uusiPostinumero);
        void setKunta(std::string uusiKunta);
        std::string getKatuosoite() const;
        std::string getPostinumero() const;
        std::string getKunta() const;
};

class Henkilo {
    private:
        Osoite osoite;
    protected:
        std::string nimi;
        int ika;
    public:
        Henkilo();
        Henkilo(std::string tempNimi, int tempIka);
        Henkilo(std::string tempNimi, int tempIka, Osoite tempOsoite);
        Henkilo(const Henkilo& tempHenkilo);
        ~Henkilo();
        virtual void tulostaTiedot() const;
        void setIka(int uusiIka);
        void setNimi(std::string uusiNimi);
        void setOsoite(Osoite tempOsoite);
        int getIka() const;
        std::string getNimi() const;
        Osoite getOsoite() const;
};