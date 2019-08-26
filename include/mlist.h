#ifndef M_CF_LIST_H_
#define M_CF_LIST_H_
typedef struct cfListNode {
    int value;
    cfListNode* next;
    cfListNode(int v) {
        value = v;
        next = nullptr;
    }
} cfListNode;

void reverse_list(cfListNode* head);

void print_list(cfListNode *phead);
void free_list(cfListNode *phead);

void printReversedList_Iterative(cfListNode *phead);
void printReversedList_Recursive(cfListNode* phead);
#endif