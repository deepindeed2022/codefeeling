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

TEST(DLOp, GetConvolutionOutputSize) {
    ASSERT_EQ(4, dl::op::GetConvolutionOutputSize(4, 3, 1));
    ASSERT_EQ(2, dl::op::GetConvolutionOutputSize(4, 3, 0));
    ASSERT_EQ(2, dl::op::GetConvolutionOutputSize(4, 3, 1, 1, 2));
    ASSERT_EQ(4, dl::op::GetConvolutionOutputSize(4, 3, 2, 1, 2));
}

TEST(DLOp, ReLU6) {
    ASSERT_EQ(4, dl::op::ReLU6(4));
    ASSERT_EQ(0, dl::op::ReLU6(-4));
    ASSERT_FLOAT_EQ(-0.8f, dl::op::ReLU6(-4, 0.2));
    ASSERT_FLOAT_EQ(4, dl::op::ReLU6(4, 0.2));
}

TEST(DLOp, Sigmod) {
    ASSERT_FLOAT_EQ(dl::op::Sigmod(0), 0.5f); 
    ASSERT_FLOAT_EQ(dl::op::Sigmod(1), 0.7310586); 
    ASSERT_FLOAT_EQ(dl::op::Sigmod(-1), 0.26894143); 
}