#include <iostream>
#include "func.h"

int main() {
	size_t size = 1;
	size_t power;
	std::cout << "enter power: ";
	std::cin >> power;
	size_t* arr = new size_t[size];
	arr[0] = 1;
	size_t* res = powArr(arr, 2, size, power);
	printArr(res, size);
	delete[] res;
	return 0;
}
