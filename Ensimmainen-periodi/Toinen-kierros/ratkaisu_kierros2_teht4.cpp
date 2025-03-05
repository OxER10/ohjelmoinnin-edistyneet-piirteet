// T4 Oskari järvinen

// c) Mielestäni prime_square_root on tehokkain, koska sen tarvitsee tarkistaa vähiten numeroita. Ohjelmaa suorittaessa huomaa myös, että prime_square_root on tehokkain
// c) 2 viimeistä strategiaa ovat toimivia, koska kaikki mahdolliset jakajat on jo testattu neljöjuureen mennessä

#include <iostream>
#include <cmath>

bool isPrime(int x);
bool prime_all(int x);
bool prime_half(int x);
bool prime_square_root(int x);

// maksimiluku, jonka väliltä tarkastellaan
const int tarkasteltavat = 10000;

int main() {
    int annettu = 2693;
    int primecount = 0;
    std::cout << "a) kohta: " << isPrime(annettu);
    std::cout << "\n\nb) kohta: ";
    for (int i = 1; i <= tarkasteltavat; i++){
        bool prime = false;
        prime = isPrime(i);
        if (prime == true) {
            std::cout << i << ", ";
            primecount++;
        }
    }
    std::cout << "yhteensa alkulukuja: " << primecount;
    primecount = 0;
    std::cout << "\n\nc) kohta, prime_all: ";
    for (int i = 1; i <= tarkasteltavat; i++){
        bool prime = false;
        prime = prime_all(i);
        if (prime == true) {
            std::cout << i << ", ";
            primecount++;
        }
    }
    std::cout << "yhteensa alkulukuja: " << primecount;
    primecount = 0;
    std::cout << "\n\nc) kohta, prime_half: ";
    for (int i = 1; i <= tarkasteltavat; i++){
        bool prime = false;
        prime = prime_half(i);
        if (prime == true) {
            std::cout << i << ", ";
            primecount++;
        }
    }
    std::cout << "yhteensa alkulukuja: " << primecount;
    primecount = 0;
    std::cout << "\n\nc) kohta, prime_square_root: ";
    for (int i = 1; i <= tarkasteltavat; i++){
        bool prime = false;
        prime = prime_square_root(i);
        if (prime == true) {
            std::cout << i << ", ";
            primecount++;
        }
    }
    std::cout << "yhteensa alkulukuja: " << primecount;
    primecount = 0;
}

// funktio, jolla testataan kaikki mahdolliset numerot
bool isPrime(int x) {
    int jako = 0;
    if (x <= 1) {
        return false;
    }
    else {
        for (int i = 1; i <= x; i++) {
            if (x % i == 0) {
                jako++;
            }
        }
        if (jako > 2) {
            return false;
        }
        else {
            return true;
        }
    }
}

// funktio, joka testaa kaikki arvot 1 ja x välillä
bool prime_all(int x) {
    int jako = 0;
    if (x <= 1) {
        return false;
    }
    else {
        for (int i = 2; i < (x - 1); i++) {
            if (x % i == 0) {
                jako++;
            }
        }
        if (jako == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

// funktio, joka testaa kaikki arvot 1 ja x/2 välillä
bool prime_half(int x) {
    int jako = 0;
    if (x <= 1) {
        return false;
    }
    else {
        for (int i = 2; i <= (x / 2); i++) {
            if (x % i == 0) {
                jako++;
            }
        }
        if (jako == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

// funktio, joka testaa kaikki arvot 1 ja x/2 välillä
bool prime_square_root(int x) {
    int jako = 0;
    if (x <= 1) {
        return false;
    }
    else {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                jako++;
            }
        }
        if (jako == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}