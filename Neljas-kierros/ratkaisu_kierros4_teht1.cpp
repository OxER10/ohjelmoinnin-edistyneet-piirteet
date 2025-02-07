// T1 Oskari Järvinen

#include <iostream>

const int SIZE = 500000000000;

// char gtable[SIZE];

int main() {
    // char ltable[SIZE];
    char *utable_p = new char [SIZE];

    // gtable[SIZE - 1] = 'L';
    // ltable[SIZE - 1] = 'L';
    utable_p[SIZE - 1] = 'L';

    // std::cout << gtable[SIZE - 1] << std::endl;
    // std::cout << ltable[SIZE - 1] << std::endl;
    std::cout << utable_p[SIZE - 1] << std::endl;
}

// Seuraavan kokoisia paikallisia taulukoita onnistui varata: 500, 1000 kilotavulla, 
// Tilavaraus epäonnistui ensimmäisen kerran seuraavaan kokoon: 1500 kilotavua

// Dynaamisen muistin alueelta onnistui seuraavat tilavaraukset: 100 000, 1 000 000, 10 000 000, 100 000 000, 500 000 000 kilotavua
// Tilavaraus dyn.muistin alueelta epäonnistui 1. kerran seuraavalla koolla: 1 000 000 000 kilotavua
