#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "base/util.h"

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& T) {
        std::vector<int> ret;
        for (size_t i = 0; i < T.size(); i++) {
            ret.push_back(0);
            for (size_t j = i + 1; j < T.size(); j++) {
                if (T[j] > T[i]) {
                    ret.back() = j - i;
                    break;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    std::vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    std::cout << sol.dailyTemperatures(T) << std::endl;
    return 0;
}
