// Oskari Jarvinen 
// T3 1p
// T4 1p

class Noppa {
    private:
        int lukema;
        int noppienLkm;
        int nopat [5];
    public:
        Noppa();
        Noppa(int lkm);
        ~Noppa();
        void setNoppienLkm(int lkm);
        int getNoppienLkm();
        int getViimeisinlukema();
        void heitaNoppaa();
        void kerroViimeisenHeitonLukema();
};