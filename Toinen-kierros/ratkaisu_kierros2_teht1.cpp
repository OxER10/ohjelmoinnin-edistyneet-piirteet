// T1 Oskari järvinen

#include <iostream>

bool onKolmio(float x, float y, float z);
// float floatInputCheck();

int main(){
    float sivut[3], *sivut_p = sivut;
    for (int i = 0; i < 3; i++) {
        do{
            std::cout << "Anna kolmion " << i + 1 << ". kulma: ";
            std::cin >> *(sivut_p + i);
        } while(*(sivut_p + i) <= 0);
    }
    onKolmio(sivut[1], sivut[2],sivut[3]);
    return 0;
}

bool onKolmio(float x, float y, float z) {
    enum kolmiotyyppi {
        yleinen = 1,
        tasakylkinen = 2,
        tasasivuinen = 3,
        suorakulmainen = 4
    };
}

// float floatInputCheck() {
//     float input;
//     bool error;
//     do{
//         std::cin >> input;
//         if (std::cin.fail()){
//             std::cout << "Virhe! Tarkista syote!: " << std::endl;
//             std::cin.clear();
//             std::cin.ignore(INT_MAX, '\n'); 
//             return 0;
//         }
//         else if (input <= 0) {
//             std::cout << "Anna positiivinen luku!" << std::endl;
//             std::cin.clear();
//             std::cin.ignore(INT_MAX, '\n'); 
//             return 0;
//         }
//         else {
//             error = false;
//         }
//     }while (error == true);
//     return input;
// }