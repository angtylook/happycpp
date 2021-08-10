#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "base/util.h"

class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue(
        std::vector<std::vector<int>>& people) {
        std::sort(people.begin(), people.end(),
                  [](const std::vector<int>& l, const std::vector<int>& r) -> bool {
                if (l[0] != r[0]) {
                    return l[0] < r[0];
                }
                return l[1] > r[1];
            });
        std::vector<std::vector<int>> out(people.size());
        for (auto& p : people) {
            auto n = 0;
            for (int i = 0; i < out.size(); i++) {
                if (out[i].empty()) {
                    n++;
                    if (n == p[1]+1) {
                        out[i] = p;
                        break;
                    }
                }
            }
        }
        return out;
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha;
    std::vector<std::vector<int>> people{{7, 0}, {4, 4}, {7, 1},
                                         {5, 0}, {6, 1}, {5, 2}};
    auto result = sol.reconstructQueue(people);
    for (auto& p : result) {
        std::cout << p << std::endl;
    }
    return 0;
}
