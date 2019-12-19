#include <gtest/gtest.h>
#include <dl/op.h>
#include "test_api.h"

TEST(DLOp, SoftMax) {
    std::vector<float> input = {1, 1, 2};
    dl::op::SoftMax(input);
    ASSERT_EQ(2, dl::op::ArgMax(input));
    ASSERT_FLOAT_EQ(input[0], input[1]);
    ASSERT_GE(input[2], input[1]);
}

TEST(DLOp, GetConvolutionOutputSize) {
    ASSERT_EQ(4, dl::op::GetConvolutionOutputSize(4, 3, 1));
    ASSERT_EQ(2, dl::op::GetConvolutionOutputSize(4, 3, 0));
    ASSERT_EQ(2, dl::op::GetConvolutionOutputSize(4, 3, 1, 1, 2));
    ASSERT_EQ(4, dl::op::GetConvolutionOutputSize(4, 3, 2, 1, 2));
}

TEST(DLOp, Sigmod) {
    ASSERT_FLOAT_EQ(dl::op::Sigmod(0), 0.5f); 
    ASSERT_FLOAT_EQ(dl::op::Sigmod(1), 0.7310586f); 
    ASSERT_FLOAT_EQ(dl::op::Sigmod(-1), 0.26894143f); 
}