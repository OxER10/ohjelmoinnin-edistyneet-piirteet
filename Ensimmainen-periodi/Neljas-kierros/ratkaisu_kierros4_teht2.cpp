// T2 Oskari Järvinen

#include<iostream>
#include<fstream>
#include<string>

int main() {
    int number, sum = 0, average, count = 0;
    std::ifstream file;
    file.open("Random.txt");
    if (file) {
        std::cout << "Every number: ";
        // Reads every line that is in the file
        while (file >> number) {
            count++;
            sum += number;
            std::cout << number << ", ";
        }
        average = sum / count;
        std::cout << "\nNumber count: " << count;
        std::cout << "\nSum of numbers: " << sum;
        std::cout << "\nAverage of numbers: " << average;

    }
    else {
        std::cout << "Error. Couldn't open the file";
        return 0;
    }

    // Output:
    // Every number: 42, 468, 335, 501, 170, 725, 479, 359, 963, 465, 706, 146, 282, 828, 962, 492, 996, 943, 828, 437, 392, 605, 903, 154, 293, 383, 422, 717, 719, 896, 448, 727, 772, 539, 870, 913, 668, 300, 36, 895, 704, 812, 323, 334, 674, 665, 142, 712, 254, 869, 548, 645, 663, 758, 38, 860, 724, 742, 530, 779, 317, 36, 191, 843, 289, 107, 41, 943, 265, 649, 447, 806, 891, 730, 371, 351, 7, 102, 394, 549, 630, 624, 85, 955, 757, 841, 967, 377, 932, 309, 945, 440, 627, 324, 538, 539, 119, 83, 930, 542, 834, 116, 640, 659, 705, 931, 978, 307, 674, 387, 22, 746, 925, 73, 271, 830, 778, 574, 98, 513, 987, 291, 162, 637, 356, 768, 656, 575, 32, 53, 351, 151, 942, 725, 967, 431, 108, 192, 8, 338, 458, 288, 754, 384, 946, 910, 210, 759, 222, 589, 423, 947, 507, 31, 414, 169, 901, 592, 763, 656, 411, 360, 625, 538, 549, 484, 596, 42, 603, 351, 292, 837, 375, 21, 597, 22, 349, 200, 669, 485, 282, 735, 54, 1000, 419, 939, 901, 789, 128, 468, 729, 894, 649, 484, 808, 422, 311, 618, 814, 515, 
    // Number count: 200
    // Sum of numbers: 105527
    // Average of numbers: 527
}
