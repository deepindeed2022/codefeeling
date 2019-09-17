#include <dl/extend_op.h>
#include <gtest/gtest.h>
#include "test_api.h"

TEST(DLExtendOp, NMS) {
    BBox a = {{1, 1, 9, 9}, 0.9};
    BBox b = {{0, 0, 4, 4}, 0.8};
    BBox c = {{7, 7, 8, 8}, 0.9};
    BBox d = {{1, 1, 2, 2}, 0.76};
    std::vector<BBox> input = {a, b, c, d};
    std::vector<BBox> result = nonMaximumSuppression(input, 0.5);
    for(auto& r: result) {
        cf_rect_t rect = r.position;
        fprintf(stderr, "{{%d, %d, %d, %d}, %f}\n", rect.left, rect.top, rect.right, rect.bottom, r.score);
    }
}