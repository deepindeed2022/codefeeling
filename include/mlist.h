#ifndef M_LIST_H_
#define M_LIST_H_
typedef struct ListNode {
    int value;
    ListNode* next;
    ListNode(int v) {
        value = v;
        next = nullptr;
    }
} ListNode;

void print_list(ListNode *phead);
void free_list(ListNode *phead);

void printReversedList_Iterative(ListNode *phead);
void printReversedList_Recursive(ListNode* phead);
#endif