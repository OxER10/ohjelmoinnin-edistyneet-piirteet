// Oskari Jarvinen 
// T3 1p
// T4 1p

#include"Noppa.h"
#include<iostream>

const int MIN_LKM = 1;
const int MAX_LKM = 5;

Noppa::Noppa() {
    lukema = rand() % 5 + 1;
    noppienLkm = 1;
}

Noppa::Noppa(int lkm) {
    lukema = rand() % 5 + 1;
    if (lkm > MIN_LKM && lkm <= MAX_LKM) {
        noppienLkm = lkm;
    }
    else {
        std::cout << "Vaara noppien lkm!" << "\n";
    }
}

Noppa::~Noppa() {}

void Noppa::setNoppienLkm(int lkm) {
    if (lkm > MIN_LKM && lkm <= MAX_LKM) {
        noppienLkm = lkm;
    }
    else {
        std::cout << "Vaara maara noppia!" << "\n";
    }
}

void Noppa::heitaNoppaa() {
    for (int i = 0; i < noppienLkm; i++) {
        lukema = rand() % 5 + 1; 
        std::cout << "Noppa " << i + 1 << ": " << lukema << "\n";
        nopat[i] = lukema;
    }
}

void Noppa::kerroViimeisenHeitonLukema() {
    std::cout << "Viimeisin heitto on " << getViimeisinlukema() << ". Heitetty " << noppienLkm << " nopalla.\n";
}

int Noppa::getNoppienLkm() { return noppienLkm; }

int Noppa::getViimeisinlukema() { 
    int summa{0};
    for (int i = 0; i < noppienLkm; i++) {
        summa += nopat[i];
    }
    return summa;
 }