#include <gtest/gtest.h>
#include "test_api.h"
#include <mlist.h>
#include <cassert>

#define TEST_MAX_VALUE 10000
inline ListNode* generate_random_list(ListNode** phead, int size){
    assert(*phead == NULL && size > 0);
    ListNode** p = phead;
    (*p) = new ListNode(get_int_rand() % TEST_MAX_VALUE);
    ListNode* pp = *p; //注意: 一定是创建ListNode之后再赋值,否则会丢失内存
    for(int i = 1; i < size; i++) {
        (*p)->next = new ListNode(get_int_rand() % TEST_MAX_VALUE);
        *p = (*p)->next;
    }
    return pp;
}

TEST(List, reversedPrint)
{
    ListNode* phead = NULL;
    printReversedList_Iterative(phead);
    printReversedList_Recursive(phead);
    phead = generate_random_list(&phead, 10);
    print_list(phead);
    printReversedList_Iterative(phead);
    fprintf(stderr, "\n");
    print_list(phead);
    printReversedList_Recursive(phead);
    fprintf(stderr,"\n");
    free_list(phead);
}
