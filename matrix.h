#pragma once
#ifndef MATRIX_H
#define MATRIX_H

void readMatrix(const char* filename, int**& matrix, int& rows, int& cols);
void swapCols(int** matrix, int rows, int cols);
void print(int** matrix, int rows, int cols);
void deleteMatrix(int** matrix, int rows);

#endif 

