#include <iostream>
#include <vector>
#include <algorithm>
#include "base/util.h"

class Solution {
public:
    std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
        size_t sz = nums.size();
        out_.push_back({}); // empty set
        if (sz == 0) {
            return out_;
        }
        for (size_t n = 1; n < sz; n++) {
            std::vector<int> current;
            std::vector<int> flag(nums.size(), 0);
            select(nums, current, flag, n, 0);
        }
        out_.push_back(nums); // full set
        return out_;
    }

    void select(const std::vector<int>& nums, std::vector<int>& current, std::vector<int>& flag, size_t n, size_t start) {
        if (n == 1) {
            for (size_t i = start; i < flag.size(); i++) {
                if (flag[i] == 0) {
                    current.push_back(nums[i]);
                    out_.push_back(current);
                    current.pop_back();
                }
            }
            return;
        }

        for (size_t i = start; i < flag.size(); i++) {
            if (flag[i] == 0) {
                flag[i] = 1;
                current.push_back(nums[i]);
                select(nums, current, flag, n - 1, i);
                flag[i] = 0;
                current.pop_back();
            }
        }
    }

    void clear() { out_.clear();
    }

private:
    std::vector<std::vector<int>> out_;
};

int main() {
    Solution sol;
    auto result = sol.subsets({});
    for (auto r : result) {
        std::cout << r << std::endl;
    }
    sol.clear();
    std::cout << "=======" << result.size() << std::endl;

    result = sol.subsets({1});
    for (auto r : result) {
        std::cout << r << std::endl;
    }
    sol.clear();
    std::cout << "=======" << result.size() << std::endl;

    result = sol.subsets({1,2});
    for (auto r : result) {
        std::cout << r << std::endl;
    }
    sol.clear();
    std::cout << "=======" << result.size() << std::endl;

    result = sol.subsets({1,2,3});
    for (auto r : result) {
        std::cout << r << std::endl;
    }
    sol.clear();
    std::cout << "=======" << result.size() << std::endl;

    result = sol.subsets({1,2,3,4});
    for (auto r : result) {
        std::cout << r << std::endl;
    }
    sol.clear();
    std::cout << "=======" << result.size() << std::endl;

    result = sol.subsets({1,2,3,4,5});
    for (auto r : result) {
        std::cout << r << std::endl;
    }
    std::cout << "=======" << result.size() << std::endl;
    return 0;
}