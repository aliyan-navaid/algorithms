#include "matrix_multiply.h"
#include <algorithm>


int main() {
    int** first = new int*[2];
    for (int i = 0; i < 2; ++i)
        first[i] = new int[3];

    int** second = new int*[3];
    for (int i = 0; i < 3; ++i)
        second[i] = new int[2];

    first[0][0] = 1, first[0][1] = 2, first[0][2] = 3;
    first[1][0] = 4, first[1][1] = 5, first[1][2] = 6;
    
    second[0][0] = 7, second[0][1] = 8;
    second[1][0] = 9, second[1][1] = 10;
    second[2][0] = 11, second[2][1] = 12;

    int** result = matrix::multiply(first, second, 2, 3, 3, 2);

    if (result==nullptr) 
        return 1;

    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << '\n';
    }
}
