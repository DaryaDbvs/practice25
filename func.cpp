#include <iostream>
#include <cstdlib>
#include <ctime>
#include "func.h"

ListNode::ListNode(int val, ListNode* next) : val(val), next(next) {}

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }

    return false;
}

ListNode* generateListWithCycle(int size) {
    if (size <= 0) return nullptr;
    std::srand(std::time(nullptr));

    ListNode* head = new ListNode(1);
    ListNode* current = head;
    ListNode** nodeArray = new ListNode * [size];
    nodeArray[0] = head;

    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(i + 1);
        current = current->next;
        nodeArray[i] = current;
    }

    int randomIndex = std::rand() % (size + 1);
    if (randomIndex < size) {
        current->next = nodeArray[randomIndex];
        std::cout << "Last node goes to " << randomIndex + 1 << std::endl;
    }
    else {
        std::cout << "No cycle" << std::endl;
    }

    delete[] nodeArray;
    return head;
}
