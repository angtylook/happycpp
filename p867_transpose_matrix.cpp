#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& A) {
        std::vector<std::vector<int>> result;
        size_t cols = A.begin()->size();
        for (size_t col = 0; col < cols; col++) {
            std::vector<int> column;
            for (auto& row : A) {
                column.push_back(row[col]);
            }
            result.push_back(column);
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector line1{1, 2, 3};
    std::vector line2{4, 5, 6};
    std::vector line3{7, 8, 9};

    std::vector t1{line1, line2, line3};
    std::vector t2{line1, line2};

    auto m1 = sol.transpose(t1);
    for (auto& r : m1) {
        std::cout << r << std::endl;
    }

    auto m2 = sol.transpose(t2);
    for (auto& r : m2) {
        std::cout << r << std::endl;
    }
    return 0;
}
