#pragma once
#ifndef MATHARRAY_H
#define MATHARRAY_H

#include <cstddef>

size_t* overwriting(size_t* arr, size_t size);
size_t* multArrByNumb(size_t* arr, size_t& size, size_t numb);
size_t* powArr(size_t* arr, size_t numb, size_t& size, size_t& power);
void printArr(size_t* arr, size_t size);

#endif 
