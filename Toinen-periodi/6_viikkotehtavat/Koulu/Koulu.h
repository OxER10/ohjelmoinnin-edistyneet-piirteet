// Oskari Jarvinen

#include"Opettaja.h"
#include"Opiskelija.h"

class Koulu {
    private: 
        std::vector<Opettaja*> opettajat;
        std::vector<Opiskelija*> opiskelijat;
        std::string koulunNimi;
    public:
        Koulu();
        Koulu(const std::vector<Opettaja>& tempOpettajat, const std::vector<Opiskelija>& opiskelijat, const std::string& tempKoulunNimi);
        Koulu(const Koulu& tempKoulu);
        ~Koulu();
        void setOpettajat(const std::vector<Opettaja*>& tempOpettajat);
        void setOpiskelijat(const std::vector<Opiskelija*>& tempOpiskelijat);
        void setKoulunNimi(const std::string& tempKoulunNimi);
        std::vector<Opettaja*> getOpettajat();
        std::vector<Opiskelija*> getOpiskelijat();
        std::string getKoulunNimi();
        void lisaaOpettaja();
        void lisaaOpiskelija();
        void lisaaOpettajalleKurssi();
        void lisaaOpiskelijalleKurssi();
        void tulostaKaikkiTiedot() const;
        void tulostaOpettajat() const;
        void tulostaOpiskelijat() const;
};