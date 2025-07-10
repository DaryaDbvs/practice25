#include <iostream>
#include "func.h"

int main() {
    StudentInfo students[MAX];
    NIRSInfo nirsData[MAX];

    int studentCount = readStudentFile("F.txt", students, MAX);
    int nirsCount = readNIRSFile("G.txt", nirsData, MAX);

    writeCombinedFile("H.txt", students, studentCount, nirsData, nirsCount);
    std::cout << "H.txt successfully written." << std::endl;

    return 0;
}
