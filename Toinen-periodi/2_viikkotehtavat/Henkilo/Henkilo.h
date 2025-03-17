// Oskari Jarvinen 
// T1 2p
// T2 1p

#include<string>
#pragma once

class Henkilo {
    private:
        std::string nimi;
        int ika;

    public:
        Henkilo();
        Henkilo(std::string tempNimi, int tempIka);
        ~Henkilo();
        void destructorTest();
        void tulostaHenkilonTiedot();
        void tervehdi();
        void setIka(int uusiIka);
        int getIka();
        void setNimi(std::string uusiNimi);
        std::string getNimi();
};