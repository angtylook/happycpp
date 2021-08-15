#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int projectionArea(std::vector<std::vector<int>>& grid) {
        int sum{0};
        size_t max_sz{0};
        for (auto& v : grid) {
            if (max_sz < v.size()) {
                max_sz = v.size();
            }
            int max = 0;
            for (auto i : v) {
                if (i > 0)
                    sum++;  // bottom
                if (max < i) {
                    max = i;
                }
            }
            sum += max;  // left
        }

        for (size_t i = 0; i < max_sz; i++) {
            int max = 0;
            for (auto& v : grid) {
                if (i < v.size()) {
                    if (max < v[i]) {
                        max = v[i];
                    }
                }
            }
            sum += max;  // right
        }
        return sum;
    }
};

int main() {
    std::vector v1{2};
    std::vector v2{1, 2};
    std::vector v3{3, 4};
    std::vector v4{1, 0};
    std::vector v5{0, 2};

    std::vector tv1{{v1}};
    std::vector tv2{v2, v3};
    std::vector tv3{v4, v5};

    Solution sol;
    std::cout << sol.projectionArea(tv1) << std::endl;  // 5
    std::cout << sol.projectionArea(tv2) << std::endl;  // 17
    std::cout << sol.projectionArea(tv3) << std::endl;  // 8
    return 0;
}
