#ifndef INCLUDE_DL_EXTEND_OP_H_
#define INCLUDE_DL_EXTEND_OP_H_
#include <cf_util.h>
#include <vector>
typedef struct cf_point_t {
    int x;
    int y;
} cf_point_t;

static cf_rect_t combine_box(cf_point_t& lt, cf_point_t& rb) {
    return cf_rect_t{lt.x, lt.y, rb.x, rb.y};
}
static float InterSectionArea(cf_rect_t& a, cf_rect_t& b) {
    int l = std::max(a.left, b.left);
    int t = std::max(a.top, b.top);
    int r = std::min(a.right, b.right);
    int b = std::min(a.bottom, b.bottom);
}
typedef struct BBox {
    cf_rect_t position;
    float score;
} BBox;

std::vector<BBox> nonMaximumSuppression(std::vector<BBox>& bbox, float overlapThreshold) {

}
#endif