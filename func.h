#pragma once
#pragma once
#ifndef LIST_H
#define LIST__H

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val = 0, ListNode* next = nullptr);
};

bool hasCycle(ListNode* head);
ListNode* generateListWithCycle(int size);

#endif 
