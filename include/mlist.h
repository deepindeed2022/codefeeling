#ifndef M_CF_LIST_H_
#define M_CF_LIST_H_
#include <vector>
typedef struct cfListNode {
    int value;
    cfListNode* next;
    cfListNode(int v) {
        value = v;
        next = nullptr;
    }
} cfListNode;

cfListNode* reverse_list(cfListNode* head);
cfListNode *reverseBetween(cfListNode *head, int m, int n);
cfListNode* init_list(std::vector<int>& data, cfListNode** phead);
std::vector<int> resave_list(cfListNode* phead);

void print_list(cfListNode *phead);
void free_list(cfListNode *phead);

void printReversedList_Iterative(cfListNode *phead);
void printReversedList_Recursive(cfListNode* phead);
#endif