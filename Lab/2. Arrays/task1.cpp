#include <iostream>
#include <algorithm>

const int rows {5};

int main() {
    /* Defining Size */
    int** jagged = new int*[rows];

    int sizes[rows];
    for (int i=0; i<rows; i++) {
        std::cout << "Size of row " << i+1 << ": ";
        std::cin >> sizes[i];

        jagged[i] = new int[sizes[i]];
    }

    /* Inputting Contents */
    for (int i = 0; i<rows; i++) {
        for (int j=0; j<sizes[i]; j++){ 
            std::cout << "Value for Row " << i+1 
                << " and Column: " << j+1 << ": ";
            std::cin >> jagged[i][j];
        }
    }

    /* Printing Contents */  
    for (int i = 0; i<rows; i++) {
        for (int j=0; j<sizes[i]; j++) {
            std::cout << jagged[i][j] << " ";
        }
        std::cout << '\n';    
    }

    /* Deleting DAM */
    for (int i=0; i<rows; i++) {
        delete [] jagged[i];
    }

    delete [] jagged;
}