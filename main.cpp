#include <iostream>
#include "matrix.h"

int main() {
    int** matrix = nullptr;
    int rows = 0, cols = 0;

    readMatrix("matrix.txt", matrix, rows, cols);

    if (!matrix) return 1;

    std::cout << "Base matrix:" << std::endl;
    print(matrix, rows, cols);

    swapCols(matrix, rows, cols);

    std::cout << "Remade matrix:" << std::endl;
    print(matrix, rows, cols);

    deleteMatrix(matrix, rows);
    return 0;
}
