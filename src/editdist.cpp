#include "editdist.h"
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

int editDistance(const char* src, const char*dst) {
    if(strlen(src) == 0 || strlen(dst) == 0) {
        return abs((int)strlen(src) - (int)strlen(dst));
    }
    if(src[0] == dst[0]) {
        return editDistance(src+1, dst+1);
    }
    int edIns = editDistance(src, dst+1) + 1;
    int edDel = editDistance(src+1, dst) + 1;
    int edRep = editDistance(src+1, dst+1) + 1;
    return std::min(std::min(edIns, edDel), edRep);
}

int minEditDistance(std::string src, std::string dst) {
    int m = src.size(), n = dst.size();
    std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) dp[0][i] = i;
    for (int i = 0; i <= m; ++i) dp[i][0] = i;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (src[i - 1] == dst[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    return dp[m][n];
}
