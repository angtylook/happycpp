#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int rob(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        // first not rob, second rob
        std::vector<std::pair<int, int>> history(nums.size(), {0,0});
        history[0].second = nums[0];  // rob
        for (size_t i = 1; i < nums.size(); i++) {
            history[i].first = std::max(history[i - 1].second, history[i - 1].first);
            history[i].second = history[i - 1].first + nums[i];
        }
        return std::max(history.back().first, history.back().second);
    }
};

int main() {
    Solution sol;
    std::cout << sol.rob({2, 1, 1, 2}) << std::endl;
    std::cout << sol.rob({1, 2, 3, 1}) << std::endl;
    std::cout << sol.rob({2, 7, 9, 3, 1}) << std::endl;
    return 0;
}