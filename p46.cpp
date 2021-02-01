#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<int> prefix;
        permute(prefix, nums);
        return out_;
    }

    void permute(std::vector<int>& prefix, std::vector<int>& subfix) {
        switch (subfix.size()) {
            case 0:
                out_.push_back(prefix);
                return;
            case 1:
                out_.push_back(concat(prefix, subfix));
                return;
        }
        auto n = subfix.size();
        for (int i = 0; i < n; i++) {
            std::swap(subfix[i], subfix[n - 1]);
            prefix.push_back(subfix[n - 1]);
            subfix.pop_back();

            permute(prefix, subfix);

            subfix.push_back(prefix.back());
            prefix.pop_back();
            std::swap(subfix[i], subfix[n - 1]);
        }
    }

    std::vector<int> concat(const std::vector<int>& v1,
                            const std::vector<int>& v2) {
        std::vector<int> result;
        std::copy(v1.begin(), v1.end(), std::back_inserter(result));
        std::copy(v2.begin(), v2.end(), std::back_inserter(result));
        return result;
    }

private:
    std::vector<std::vector<int>> out_;
};

int main() {
    Solution sol;
    std::cout << std::boolalpha;
    auto result = sol.permute(std::vector<int>{1,2,3,4});
    for (auto& p : result) {
        std::cout << p << std::endl;
    }
    return 0;
}
