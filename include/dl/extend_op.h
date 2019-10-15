#ifndef INCLUDE_DL_EXTEND_OP_H_
#define INCLUDE_DL_EXTEND_OP_H_
#include <cf_util.h>
#include <vector>
#include <algorithm>
#include <iostream>
static int InterSectionArea(cf_rect_t& aa, cf_rect_t& bb) {
	int l = std::max(aa.left, bb.left);
	int t = std::max(aa.top, bb.top);
	int r = std::min(aa.right, bb.right);
	int b = std::min(aa.bottom, bb.bottom);
	return (r - l + 1) * (b - t + 1);
}
typedef struct BBox {
	cf_rect_t position;
	float score;
} BBox;

// nms
std::vector<BBox> nonMaximumSuppression(std::vector<BBox>& bbox, float overlapThreshold) {
	const int bbox_size = bbox.size();
	std::sort(bbox.begin(), bbox.end(), [](BBox& a, BBox& b) {return a.score > b.score;});
	std::vector<bool> is_suppressed(bbox_size, false);
	std::vector<float> bbox_area(bbox_size, 0);
	for(int i = 0; i < bbox_size; i++) {
		cf_rect_t rect = bbox[i].position;
		bbox_area[i] = (rect.right - rect.left + 1)*(rect.bottom - rect.top + 1);
	}
	for (int i = 0; i < bbox_size; i++) {  
		if (is_suppressed[i]) continue;
		for (int j = i + 1; j < bbox_size; j++) {
			if (is_suppressed[j]) continue;
			int overlap = InterSectionArea(bbox[i].position, bbox[j].position);
			if (overlap > 0) {
				float overlapRatio = overlap / (bbox_area[i] + bbox_area[j] - overlap);	// 计算重叠的比率
				if (overlapRatio > overlapThreshold) {
					is_suppressed[j] = true; 		// 将窗口j标记为抑制
				}
			}
		}
		
	}
	std::vector<BBox> res;
	for(int i = 0; i < bbox_size; ++i) {
		if(!is_suppressed[i]) res.push_back(bbox[i]);
	}
	return res;
}

// roialign
// roipooling

#endif