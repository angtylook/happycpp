#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::vector<int>>
    matrixReshape(std::vector<std::vector<int>>& nums, int r, int c) {
        int total = (nums.size() * nums[0].size());
        if (total != r * c) {
            return nums;
        }
        std::vector<std::vector<int>> m;
        std::vector<int> row;
        row.reserve(c);
        for (auto& v : nums) {
            for (auto e : v) {
                row.push_back(e);
                if (row.size() == c) {
                    // m.push_back(std::move(row));
                    m.push_back(row);
                    m.clear();
                }
            }
        }
        return m;
    }
};

int main() {
    Solution sol;

    std::vector r1{1, 2};
    std::vector r2{3, 4};
    std::vector m1{r1, r2};

    auto m3 = sol.matrixReshape(m1, 1, 4);
    for (auto& v : m3) {
        std::cout << v << std::endl;
    }
    auto m4 = sol.matrixReshape(m1, 2, 4);
    for (auto& v : m4) {
        std::cout << v << std::endl;
    }
    return 0;
}
