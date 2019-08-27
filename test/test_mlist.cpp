#include <gtest/gtest.h>
#include "test_api.h"
#include <mlist.h>
#include <cassert>

#define TEST_MAX_VALUE 10000

inline cfListNode* generate_random_list(cfListNode** phead, int size){
    assert(*phead == NULL && size > 0);
    cfListNode** p = phead;
    (*p) = new cfListNode(get_int_rand() % TEST_MAX_VALUE);
    cfListNode* pp = *p; //注意: 一定是创建cfListNode之后再赋值,否则会丢失内存
    for(int i = 1; i < size; i++) {
        (*p)->next = new cfListNode(get_int_rand() % TEST_MAX_VALUE);
        *p = (*p)->next;
    }
    return pp;
}

TEST(List, reversedPrint)
{
    cfListNode* phead = NULL;
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

TEST(List, reverse_list) {
    cfListNode* phead = NULL;
    std::vector<int> test_data = {1,2,3,4,5,6,7,8,9};
    init_list(test_data, &phead);
    phead = reverse_list(phead);
    // print_list(phead);
    std::vector<int> result = resave_list(phead);
    const int size = test_data.size();
    for(int i =0; i < size; i++) {
        ASSERT_EQ(test_data[size - 1 - i],  result[i]);
    }
}
TEST(List, reverse_between) {
    cfListNode* phead = NULL;
    std::vector<int> test_data = {1,2,3,4,5,6,7,8,9};
    init_list(test_data, &phead);
    int m = 4, n = 8;
    phead = reverseBetween(phead, m, n);
    std::vector<int> result = resave_list(phead);
    const int size = test_data.size();
    for(int i = 0; i < size; i++) {
        if(i < n && i >= m - 1) {
            ASSERT_EQ(test_data[n-m+1-(i-m) + 1],  result[i]);
        } else {
            ASSERT_EQ(test_data[i],  result[i]);
        }
    }
}