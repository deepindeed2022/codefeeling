#include <dl/extend_op.h>
#include <gtest/gtest.h>
#include "test_api.h"

TEST(DLExtendOp, NMS) {
    BBox a = {{168,127,363,353}, 0.87};
    BBox b = {{169,114,361,369}, 0.546};
    std::vector<BBox> input = {a, b};
    std::vector<BBox> result = nonMaximumSuppression(input, 0.3);
    for(auto& r: result) {
        cf_rect_t rect = r.position;
        fprintf(stderr, "{{%d, %d, %d, %d}, %f}\n", rect.left, rect.top, rect.right, rect.bottom, r.score);
    }
}