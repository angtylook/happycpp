#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto n = nums.size();
        int sum{0};
        for (size_t i = 0; i < n; i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {
    Solution sol;
    std::vector<int> vi{1, 4, 3, 2};
    assert(sol.arrayPairSum(vi) == 4);

    std::vector<int> vi1{7, 3, 1, 0, 0, 6};
    assert(sol.arrayPairSum(vi1) == 7);
    return 0;
}
