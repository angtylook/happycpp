#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& findNums,
                                        std::vector<int>& nums) {
        std::vector<int> vi;
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
