#ifndef INCLUDE_DL_OP_H_
#define INCLUDE_DL_OP_H_
#include <vector>
#include <algorithm>
namespace dl{
namespace op {
int ArgMax(const std::vector<float>& input) {
    return std::distance(std::begin(input), std::max_element(input.begin(), input.end()));
}

void SoftMax(std::vector<float>& input) {
    float m = *std::max_element(input.begin(), input.end());
    float sum = 0.0;
    for(size_t i = 0; i < input.size(); i++) {
        sum += expf(input[i] - m);
    }
    float offset = m + logf(sum);
    for(size_t i = 0; i < input.size(); i++) {
        input[i] = expf(input[i] - offset);
    }
}

float Sigmod(float v) {
    return 1.0f/(1 + expf(-v));
}

float GradSigmod(float fx) {
    return fx * (1- fx);
}

// RELU层支持in-place计算，这意味着bottom的输出和输入相同以避免内存的消耗。
float ReLU6(float x, float negative_slope = 0.f) {
    return std::min(std::max(0.0f, x) + negative_slope*std::min(0.0f, x), 6.0f);
}

float Power(float x, float power, float shift, float scale) {
    return std::pow((shift + scale*x), power);
}

int GetConvolutionOutputSize(int N, int k, int pad, int stride=1, int dilationrate=1) {
    // 
    // M = (N + 2*pad - (kernal * dilationrate - 1)) / stride  + 1
    //
    if(dilationrate >= 2) {
        return (N + 2*pad - (k*dilationrate - 1)) / stride + 1;
    } else{
        return (N + 2*pad - k) / stride + 1;
    }
}
} // namespace op
} // namespace dl
#endif