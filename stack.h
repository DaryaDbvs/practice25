#pragma once
#ifndef BRACKET_STACK_H
#define BRACKET_STACK_H

class Stack {
private:
    char* arr;
    int size;
    int topIndex;
public:
    Stack(int size);
    ~Stack();
    bool isEmpty() const;
    int getSize() const;
    bool isFull() const;
    void push(int value);
    int pop();
    int top() const;
};

bool isMatching(char open, char close);
bool isBalanced(const char* str, int length);
void generateRandomBrackets(char* arr, int length);

#endif 

