#include <iostream>
#include "binarny.h"

int findMissing(const int* arr, int size, int step) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int expected = arr[0] + mid * step;

        if (arr[mid] == expected) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return arr[0] + left * step;
}

void generateSequence(int* arr, int size, int step, int start, int breakIndex) {
    int current = start;
    for (int i = 0; i < size; ++i) {
        arr[i] = current;
        if (i == breakIndex) {
            current += step * 2;
        }
        else {
            current += step;
        }
    }
}

void printArray(const int* arr, int size) {
    std::cout << "\narr:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
