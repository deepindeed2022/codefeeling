#include "test_api.h"
#include <random>
int get_int_rand()
{
    std::random_device rd;
    std::mt19937 e(rd());
    std::uniform_int_distribution<int> dist;
    return dist(e);
}
std::vector<int> generate_int_array(const size_t size) {
    std::vector<int> result;
    for(size_t i = 0; i < size; ++i) result.push_back(get_int_rand());
    return result;
}