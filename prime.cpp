#include "prime.h"
#include <cmath>
bool isPrimeNumber(int num)
{
	if (num == 1 || num == 0) {
		return false;
	}
	if (num == 2) {
		return true;
	}
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
bool isCallen(int num) {
	int n = num - 1;
	int counter = 0;
	while (n % 2 == 0) {
		n = n / 2;
		counter++;
	}
	if (counter == n)return true;
	return false;
}
