#include <dl/op.h>
#include <gtest/gtest.h>
#include "../test_api.h"

TEST(DLOp, SoftMax) {
    std::vector<float> input = {1, 1, 2};
    dl::op::SoftMax(input);
    ASSERT_EQ(2, dl::op::ArgMax(input));
    for(auto i: input){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
