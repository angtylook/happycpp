#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "base/util.h"

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& T) {
        constexpr int minT = 30;
        constexpr int maxT = 100;

        std::vector<int> ret(T.size(), 0);
        std::vector<int> bookmarks(maxT - minT + 1, 0);

        for (size_t i = T.size();  i > 0; i--) {
            auto p = i - 1;
            bookmarks[T[p] - minT] = p;
            std::cout << "set " << T[p] << " at " << p << std::endl;

            int idx = T.size();
            for (int t = T[p]+1; t <= maxT; t++) {
                auto bm = bookmarks[t - minT];
                if (bm != 0 && idx > bm) {
                    idx = bm;
                }
            }
            if (idx != T.size()) {
                ret[p] = idx - p;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    std::vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    std::cout << sol.dailyTemperatures(T) << std::endl;
    return 0;
}
