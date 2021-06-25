#include <iostream>
#include <vector>
#include <algorithm>

#include "base/util.h"

class Solution {
public:
    int numTrees(int n) {
        if (n < nums_.size()) {
            return nums_[n];
        }
        int total = 0;
        for (int i = 1; i <= n; i++) {
            total += std::max(1, numTrees(i-1)) * std::max(1, numTrees(n - i));
        }
        nums_.push_back(total);
        return total;
    }
private:
    std::vector<int> nums_ = {0, 1, 2, 5};
};

int main() {
    Solution sol;
    for (int i = 1; i < 20; i++) {
        std::cout << i << " -> " << sol.numTrees(i) << std::endl;
    }
    return 0;
}
