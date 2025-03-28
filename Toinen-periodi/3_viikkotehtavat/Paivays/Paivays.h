// Oskari Jarvinen 
// T1 1p
// T3 2p

#include<string>


class Paivays {
    private: 
        int paiva;
        int kuukausi;
        int vuosi;
        int kuukaudenPaivat[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public:
        Paivays();
        Paivays(int tempPaiva, int tempKuukausi, int tempVuosi);
        ~Paivays();
        void destructorTest();
        void setPaiva(int uusiPaiva);
        void setKuukausi(int uusiKuukausi);
        void setVuosi(int uusiVuosi);
        void setKuukaudenPaivat(int kuukaudenPaivat[12]);
        bool isKarkausVuosi(int vuosi) const;
        int getPaiva() const;
        int getKuukausi() const;
        int getVuosi() const;
        void tulostaPaivays() const;
        void kayttajanPaiva();
        void addPaiva();
};

class Kalenterimerkinta : Paivays {
    private:
        Paivays paivays;
        std::string asia;
        bool muistutus;
    public:
        Kalenterimerkinta();
        Kalenterimerkinta(Paivays tempPaivays, std::string tempAsia, bool tempMuistutus);
        ~Kalenterimerkinta();
        void setPaivays(Paivays uusiPaivays);
        void setAsia(std::string uusiAsia);
        void setMuistutus(bool uusiMuistutus);
        Paivays getPaivays() const ;
        std::string getAsia() const ;
        bool getMuistutus() const ;
        void tulostaMerkinta() const ;
        void kysyTiedot();
};