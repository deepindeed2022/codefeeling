#ifndef INCLUDE_DL_OP_H_
#define INCLUDE_DL_OP_H_
#include <vector>

namespace dl {
namespace op {
int ArgMax(const std::vector<float>& input);

void SoftMax(std::vector<float>& input);

float Sigmod(float v);

float GradSigmod(float fx);

// RELU层支持in-place计算，这意味着bottom的输出和输入相同以避免内存的消耗。
float ReLU6(float x, float negative_slope = 0.f);

float Power(float x, float power, float shift, float scale);

int GetConvolutionOutputSize(int N, int k, int pad, int stride=1, int dilationrate=1);

} // namespace op
} // namespace dl
#endif