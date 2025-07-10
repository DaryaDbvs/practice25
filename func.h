#pragma once
#ifndef NIRS_H
#define NIRS_H

#include <string>

const int MAX = 100;

struct StudentInfo {
    char recordBook[15];
    char surname[30];
    char nirsCode[10];
};

struct NIRSInfo {
    char code[10];
    std::string title;
};

bool codesMatch(const char* a, const char* b);
int readStudentFile(const char* filename, StudentInfo students[], int maxCount);
int readNIRSFile(const char* filename, NIRSInfo nirsData[], int maxCount);
int findNIRSIndex(const char* code, NIRSInfo nirsData[], int count);
void writeCombinedFile(const char* filename, StudentInfo students[], int studentCount,
    NIRSInfo nirsData[], int nirsCount);

#endif 

