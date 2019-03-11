#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::vector<int>>
    matrixReshape(std::vector<std::vector<int>>& nums, int r, int c) {
        return nums;
    }
};

int main() {
    Solution sol;

    std::vector r1{1, 2};
    std::vector r2{3, 4};
    std::vector m1{r1, r2};

    std::cout << sol.matrixReshape(m1, 1, 4) << std::endl;
    std::cout << sol.matrixReshape(m1, 2, 4) << std::endl;
    return 0;
}
