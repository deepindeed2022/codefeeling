#ifndef M_LIST_H_
#define M_LIST_H_
typedef struct ListNode {
    int value;
    ListNode* next;
} ListNode;

void printReversedList_Iterative(ListNode* phead);
void printReversedList_Recursive(ListNode* phead);
#endif