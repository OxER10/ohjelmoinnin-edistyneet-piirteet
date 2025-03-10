#pragma once
#include<string>
#include<iostream>

class Henkilo {
    private:
        std::string nimi;
        int ika;

    public:
        void tervehdi();
        void setIka(int uusiIka);
        int getIka();
        void setNimi(std::string uusiNimi);
        std::string getNimi();
};