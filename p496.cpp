#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& findNums,
                                        std::vector<int>& nums) {
        std::vector<int> vi;
        for (auto n : findNums) {
            auto iter = std::find_if(std::find(nums.begin(), nums.end(), n),
                                     nums.end(), [n](int v) { return v > n; });
            if (iter != nums.end()) {
                vi.push_back(*iter);
            } else {
                vi.push_back(-1);
            }
        }
        return vi;
    }
};

int main() {
    Solution sol;
    std::vector sub1{4, 1, 2};
    std::vector all1{1, 3, 4, 2};
    std::cout << sol.nextGreaterElement(sub1, all1) << std::endl;
    std::vector sub2{2, 4};
    std::vector all2{1, 2, 3, 4};
    std::cout << sol.nextGreaterElement(sub2, all2) << std::endl;
    return 0;
}
