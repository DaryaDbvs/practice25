#include <iostream>
#include <ctime>
#include "stack.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    int length = 0;
    char input[1001];

    std::cout << "random braces:1\nyour string: 2\nYour choice: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter length: ";
        std::cin >> length;
        generateRandomBrackets(input, length);
        std::cout << "Random braces: " << input << std::endl;
    }
    else {
        std::cout << "Enter braces (less than 1000): ";
        std::cin >> input;
        length = std::strlen(input);
    }

    if (isBalanced(input, length)) {
        std::cout << "Right" << std::endl;
    }
    else {
        std::cout << "Wrong" << std::endl;
    }

    return 0;
}
