#include <iostream>
#include <string>
#include"Henkilo.h"

int main() {
    std::string hello("Hello.");
    int pituus = hello.length();
    hello.append(" Lisaa jotain");
    std::cout << hello << std::endl;
    system("pause");

    // Henkilon kalle luonti
    Henkilo kalle;

    kalle.setNimi("Kalle");
    kalle.setIka(20);

    Henkilo ville;

    ville.setNimi("Ville");
    ville.setIka(23);

    kalle.tervehdi();
    ville.tervehdi();

    int x1 = kalle.getIka();
    int x2 = ville.getIka();

    system("pause");

    return 0;  
}