#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stack.h"

Stack::Stack(int size) {
    this->size = size;
    arr = new char[size];
    topIndex = -1;
}

Stack::~Stack() {
    delete[] arr;
}

bool Stack::isEmpty() const {
    return topIndex == -1;
}

int Stack::getSize() const {
    return size;
}

bool Stack::isFull() const {
    return topIndex == size - 1;
}

void Stack::push(int value) {
    if (isFull()) {
        std::cout << "Stack overflow!" << std::endl;
        return;
    }
    arr[++topIndex] = value;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack underflow!" << std::endl;
        return -1;
    }
    return arr[topIndex--];
}

int Stack::top() const {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return -1;
    }
    return arr[topIndex];
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '[' && close == ']') ||
        (open == '{' && close == '}');
}

bool isBalanced(const char* str, int length) {
    Stack stack(length);
    for (int i = 0; i < length; ++i) {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.isEmpty() || !isMatching(stack.pop(), ch)) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

void generateRandomBrackets(char* arr, int length) {
    const char brackets[] = { '(', ')', '[', ']', '{', '}' };
    for (int i = 0; i < length; ++i) {
        arr[i] = brackets[std::rand() % 6];
    }
    arr[length] = '\0';
}
