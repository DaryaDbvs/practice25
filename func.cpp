#include "func.h"
#include <iostream>

size_t* overwriting(size_t* arr, size_t size) {
    size_t* newArr = new size_t[size];
    for (size_t i = 0; i < size - 1; i++) {
        newArr[i] = arr[i];
    }
    return newArr;
}

size_t* multArrByNumb(size_t* arr, size_t& size, size_t numb) {
    size_t digit = 0;
    for (size_t i = 0; i < size; i++) {
        arr[i] = arr[i] * numb + digit;
        digit = arr[i] / 10;
        arr[i] = arr[i] % 10;
    }
    if (digit) {
        size++;
        size_t* newArr = overwriting(arr, size);
        newArr[size - 1] = digit;
        return newArr;
    }
    return overwriting(arr, size + 1);
}

size_t* powArr(size_t* arr, size_t numb, size_t& size, size_t& power) {
    if (!size || !power) return arr;
    size_t* newArr = multArrByNumb(arr, size, numb);
    delete[] arr;
    power--;
    return powArr(newArr, numb, size, power);
}

void printArr(size_t* arr, size_t size) {
    for (int i = static_cast<int>(size) - 1; i >= 0; i--) {
        std::cout << arr[i];
    }
}
