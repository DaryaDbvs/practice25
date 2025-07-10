#include <iostream>
#include <fstream>
#include "matrix.h"

void readMatrix(const char* filename, int**& matrix, int& rows, int& cols) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "can't open the file " << filename << std::endl;
        matrix = nullptr;
        return;
    }

    file >> rows >> cols;
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            file >> matrix[i][j];
        }
    }
    file.close();
}

void swapCols(int** matrix, int rows, int cols) {
    for (int i = 0; i < cols / 2; ++i) {
        for (int j = 0; j < rows; ++j) {
            std::swap(matrix[j][i], matrix[j][cols - i - 1]);
        }
    }
}

void print(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
