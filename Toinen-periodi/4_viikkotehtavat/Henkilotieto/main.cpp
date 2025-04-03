// Oskari Jarvinen
// T3 2p
// T4 1p

#include "Henkilotieto.h"

int main() {
    // Pieni henkilötietoja tallentava sovellus.
    std::vector<Henkilo> henkilot = silmukka();

    // Osoitin ja olio vertailu
    std::cout << "Osoitinkutsut:\n";
    std::vector<Henkilo*> henkilotOsoitin;
    henkilotOsoitin.push_back(new Henkilo("Anne", 20));
    henkilotOsoitin.push_back(new Henkilo("Kalle", 30));
    henkilotOsoitin.push_back(new Henkilo("Oskari", 22));
    henkilotOsoitin.push_back(new Henkilo("Nooa", 20));
    henkilotOsoitin.push_back(new Henkilo("Arttu", 20));

    std::cout << "\nOliokutsut:\n";
    std::vector<Henkilo> henkilotOlio;
    henkilotOlio.push_back(Henkilo("Anne", 20));
    henkilotOlio.push_back(Henkilo("Kalle", 30));
    henkilotOlio.push_back(Henkilo("Oskari", 22));
    henkilotOlio.push_back(Henkilo("Nooa", 20));
    henkilotOlio.push_back(Henkilo("Arttu", 20));


    // Vertaile tilannetta, jossa vektorissa on Henkilö –olioita osoittimien sijaan. Montako kertaa
    // rakentajaa/kopiorakentajaa kutsutaan lisättäessä vektoriin 5 henkilöä. Kumpi on
    // tehokkaampaa ja miksi näin on?

    // Osoittimet ovat tehokkaampia, koska oliotapauksessa vektori hallitsee olioiden elinkaarta
    // ja voi poistaa, sekä lisätä niitä tarpeen mukaan (vektoria suurentaessa) eli se tekee paljon rakentaja ja purkaja kutsuja.
    // Osoittimien tilanteessa ne ovat tallennettu heap muistiin jota vektorilla ei ole oikeutta poistaa, joten se vain luo oliot.
    // Vektori sitten vain poistaa ja lisää osoittimia, eikä itse olioita.

    // Miinuspuoli on, että oliot pitää itse poistaa:
    std::cout << "\nOsoitinpurkajakutsut:\n";
    for (auto object : henkilotOsoitin) {
        delete object;
    }

    std::cout << "\nOliopurkajakutstut kun out of scope:\n";
}

// Tulosteesta näkee kuinka monta kertaa enemmän olio kutsuu, kuin osoitin
// Tuloste parametritakentajalla:

// Osoitinkutsut:
// Rakentajaa kutsuttu!
// Rakentajaa kutsuttu!
// Rakentajaa kutsuttu!
// Rakentajaa kutsuttu!
// Rakentajaa kutsuttu!

// Oliokutsut:
// Rakentajaa kutsuttu!
// Purkajaa kutsuttu!
// Rakentajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Rakentajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Rakentajaa kutsuttu!
// Purkajaa kutsuttu!
// Rakentajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!

// Osoitinpurkajakutsut:
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!

// Oliopurkajakutstut kun out of scope:
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!

// Tuloste kopiorakentajalla:

// Osoitinkutsut:
// Rakentajaa kutsuttu!
// Rakentajaa kutsuttu!
// Rakentajaa kutsuttu!
// Rakentajaa kutsuttu!
// Rakentajaa kutsuttu!

// Oliokutsut:
// Rakentajaa kutsuttu!
// Purkajaa kutsuttu!
// Rakentajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Rakentajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Rakentajaa kutsuttu!
// Purkajaa kutsuttu!
// Rakentajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!

// Osoitinpurkajakutsut:
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!

// Oliopurkajakutstut kun out of scope:
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!
// Purkajaa kutsuttu!