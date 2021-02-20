#include <iostream>
#include <vector>
#include "base/util.h"

/**
 * Given an array nums of n integers where n > 1,  return an array output such that
 * output[i] is equal to the product of all the elements of nums except nums[i]
 */
class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        std::vector<int> out(nums.size(), 1);
        auto p = 1;
        for (size_t i = 0; i < nums.size() - 1; i++) {
            p *= nums[i];
            out[i + 1] *= p;
        }
        p = 1;
        for (size_t i = nums.size(); i > 1; i--) {
            p *= nums[i - 1];
            out[i - 2] *= p;
        }
        return out;
    }
};

int main() {
    Solution sol;
    std::cout << sol.productExceptSelf({1, 2, 3, 4}) << std::endl;
    std::cout << sol.productExceptSelf({1, 3, 2, 4}) << std::endl;
    return 0;
}
