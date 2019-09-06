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

float ReLU6(float x) {
    return std::min(std::max(0.0f, x), 6.0f);
}

} // namespace op
} // namespace dl
#endif