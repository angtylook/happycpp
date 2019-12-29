#include "base/util.h"

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        if (nums.empty()) {
            return nums;
        }
        size_t n = nums.size();
        std::vector<int> counts(n, 0);
        for (size_t i = 0; i < n; i++) {
            counts[nums[i] - 1] = 1;
        }
        std::vector<int> ret;
        for (int i = 0; i < int(n); i++) {
            if (counts[i] == 0) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    std::vector<int> input = {4, 3, 2, 7, 8, 2, 3, 1};
    auto output = sol.findDisappearedNumbers(input);
    std::cout << output << std::endl;
    return 0;
} 