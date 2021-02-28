#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <unordered_map>
#include "base/util.h"

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        combinationSum(candidates, target, 0);
        return result_;
    }

    void combinationSum(std::vector<int>& candidates, int target, int index) {
        if (index >= candidates.size())
            return;

        int candidate = candidates[index];
        current_sum_ += candidate;

        if (current_sum_ > target) {
            current_sum_ -= candidate;
            combinationSum(candidates, target, index + 1);
            return;
        }

        if (current_sum_ == target) {
            current_.push_back(candidate);
            result_.push_back(current_);
            current_.pop_back();
            current_sum_ -= candidate;
            combinationSum(candidates, target, index + 1);
            return;
        }

        current_.push_back(candidate);
        combinationSum(candidates, target, index);
        current_.pop_back();
        current_sum_ -= candidate;
        combinationSum(candidates, target, index + 1);
    }

private:
    std::vector<std::vector<int>> result_;
    std::vector<int> current_;
    int current_sum_{0};
};

int main(int argc, const char* argv[]) {
    Solution solution;
    std::vector<int> candidates{2, 3, 6, 7};
    auto results = solution.combinationSum(candidates, 7);
    for (auto& r : results) {
        std::cout << r << std::endl;
    }
    return 0;
}
