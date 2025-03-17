// Oskari Jarvinen 
// T1 2p
// T2 1p

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
        int getPaiva();
        int getKuukausi();
        int getVuosi();
        void tulostaPaivays();
        void kayttajanPaiva();
        void addPaiva();
};