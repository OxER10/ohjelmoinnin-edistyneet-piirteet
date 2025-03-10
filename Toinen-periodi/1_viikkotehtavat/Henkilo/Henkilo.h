// Oskari Jarvinen 
// T1 2p

#include<string>

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