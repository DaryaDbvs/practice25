#include <iostream>
#include "binarny.h"

int main() {
    int N;
    std::cout << "enter lenght: ";
    std::cin >> N;

    int* arr = new int[N];
    int step = 2;
    int start = 10;
    int breakIndex = N / 2;

    generateSequence(arr, N, step, start, breakIndex);
    printArray(arr, N);

    int missing = findMissing(arr, N, step);
    std::cout << "missing element: " << missing << std::endl;

    delete[] arr;
    return 0;
}
