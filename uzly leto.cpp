#include <iostream>
#include "func.h"

int main() {
    int size = 10;
    ListNode* head = generateListWithCycle(size);
    std::cout << "Has cycle: " << (hasCycle(head) ? "yes" : "no") << std::endl;
    return 0;
}
