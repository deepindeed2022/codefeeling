#include <gtest/gtest.h>
#include "test_api.h"
#include <mlist.h>
#include <cassert>
static void generate_random_list(ListNode* pHead, int size){
    assert(pHead == NULL && size > 0);
    pHead = new ListNode;
    pHead->value = get_int_rand();
    for(int i = 1; i < size; i++) {
        pHead->next = new ListNode;
        pHead = pHead->next;
        pHead->value = get_int_rand();
    }
}

void free_list(ListNode* pHead) {
    ListNode* pN;
    while(pHead != NULL) {
        pN = pHead;
        pHead = pHead->next;
        delete pN;
        pN = NULL;
    }
}
TEST(List, reversedPrint)
{
   ListNode* phead = NULL;
   generate_random_list(phead, 10);
   printReversedList_Iterative(phead);
   printReversedList_Recursive(phead);
}
