#include <iostream>

namespace matrix {
    int** multiply( int** first, int** second, int rows1, int cols1, int rows2, int cols2 ) {
        if (cols1 != rows2)
            return nullptr;

        int** result = new int*[rows1];
        for (int i = 0; i < rows1; ++i)
            result[i] = new int[cols2];

        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                int sum = 0;
                for (int k = 0; k < cols1; k++) {  // cols1 should match rows2
                    sum += first[i][k] * second[k][j];
                }
                result[i][j] = sum;
            }
        }
        return result;
    }

}