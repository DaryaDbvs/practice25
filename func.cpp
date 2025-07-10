#include <iostream>
#include <fstream>
#include <cstring>
#include "func.h"

bool codesMatch(const char* a, const char* b) {
    return std::strcmp(a, b) == 0;
}

int readStudentFile(const char* filename, StudentInfo students[], int maxCount) {
    std::ifstream file(filename);
    if (!file) return 0;

    int count = 0;
    while (count < maxCount &&
        file >> students[count].recordBook >> students[count].surname >> students[count].nirsCode) {
        count++;
    }
    file.close();
    return count;
}

int readNIRSFile(const char* filename, NIRSInfo nirsData[], int maxCount) {
    std::ifstream file(filename);
    if (!file) return 0;

    int count = 0;
    while (count < maxCount &&
        file >> nirsData[count].code >> std::ws &&
        std::getline(file, nirsData[count].title)) {
        count++;
    }
    file.close();
    return count;
}

int findNIRSIndex(const char* code, NIRSInfo nirsData[], int count) {
    for (int i = 0; i < count; ++i) {
        if (codesMatch(code, nirsData[i].code)) {
            return i;
        }
    }
    return -1;
}

void writeCombinedFile(const char* filename, StudentInfo students[], int studentCount,
    NIRSInfo nirsData[], int nirsCount) {
    std::ofstream file(filename);
    if (!file) return;

    for (int i = 0; i < studentCount; ++i) {
        int index = findNIRSIndex(students[i].nirsCode, nirsData, nirsCount);
        if (index != -1) {
            file << students[i].recordBook << " "
                << students[i].surname << " "
                << students[i].nirsCode << " "
                << nirsData[index].title << std::endl;
        }
    }
    file.close();
}
