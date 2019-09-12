#include "mlist.h"
#include <stack>
#include <cstdio>
cfListNode* reverse_list_v0(cfListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    cfListNode* prev = nullptr;
    cfListNode* cur = head;
    while(cur->next != nullptr) {
        cfListNode*next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    return cur;
}
cfListNode* reverse_list(cfListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    cfListNode* prev = head;
    cfListNode* cur = head->next;
    cfListNode* next;
    prev->next = nullptr;

    while(cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

cfListNode *reverseBetween(cfListNode *head, int m, int n) {
    cfListNode dummy(-1);
    dummy.next = head;
    cfListNode* prev = &dummy;
    for(int i = 0; i < m - 1; i++) {
        prev = prev->next;
    }
    cfListNode* const head2 = prev;
    prev = head2->next;
    cfListNode* cur = prev->next;
    for(int i = m; i < n; i++) {
        prev->next = cur->next;
        cur->next = head2->next;
        head2->next = cur;
        cur = prev->next;
    }
    return dummy.next;
}

void print_list(cfListNode *phead)
{
    fprintf(stderr, "List: ");
    while (phead != NULL)
    {
        fprintf(stderr, "%d->", phead->value);
        phead = phead->next;
    }
    fprintf(stderr, "null\n");
}
void free_list(cfListNode *phead)
{
    cfListNode *pN;
    while (phead != NULL)
    {
        pN = phead;
        phead = phead->next;
        delete pN;
        pN = NULL;
    }
}

void printReversedList_Iterative(cfListNode* phead)
{
    std::stack<cfListNode*> plist;
    while (phead != nullptr) {
        plist.push(phead);
        phead = phead->next;
    }
    while(!plist.empty()) {
        phead = plist.top();
        fprintf(stderr, "%d<-", phead->value);
        plist.pop();
    }
}

void printReversedList_Recursive(cfListNode* phead){
    if(phead != nullptr) {
        if(phead->next != nullptr) {
            printReversedList_Recursive(phead->next);
        }
        fprintf(stderr, "%d<-", phead->value);
    }
}

cfListNode* init_list(std::vector<int>& data, cfListNode** phead) {
    cfListNode dummy(-1); //注意: 一定是创建cfListNode之后再赋值,否则会丢失内存
    cfListNode* pp = &dummy;
    for(uint32_t i = 0; i < data.size(); i++) {
        pp->next = new cfListNode(data[i]);
        pp = pp->next;
    }
    *phead = dummy.next;
    return dummy.next;
}

std::vector<int> resave_list(cfListNode* phead) {
    std::vector<int> result;
    while(phead != nullptr) {
        result.push_back(phead->value);
        phead = phead->next;
    }
    return result;
}