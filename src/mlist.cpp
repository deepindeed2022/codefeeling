#include "mlist.h"
#include <stack>
#include <iostream>
void printReversedList_Iterative(ListNode* phead)
{
    std::stack<ListNode*> plist;
    ListNode* pNode = phead;
    while(pNode != nullptr) {
        plist.push(pNode);
        pNode = pNode->next;
    }
    while(!plist.empty()) {
        pNode = plist.top();
        std::cout << pNode->value << "\t";
        plist.pop();
    }
}
void printReversedList_Recursive(ListNode* phead){
    if(phead != nullptr) {
        if(phead->next != nullptr) {
            printReversedList_Recursive(phead->next);
        }
        std::cout << phead->value << "\t";
    }
}