#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <array>
#include <algorithm>

class Solution {
public:
    int minDeletionSize(std::vector<std::string>& A) {
        auto num_col = A[0].size();
        auto num_ele = A.size();
        std::fill(del_.begin(), del_.end(), 0);
        for(size_t e = 1; e < num_ele; e++) {
            for(size_t c = 0; c < num_col; c++) {
                // already in deleted set
                if(del_[c] == 1) {
                    continue;
                }
                if(A[e][c] < A[e-1][c]) {
                    del_[c] = 1;
                }
            }
        }
        debug_out();
        auto n = std::count(del_.begin(), del_.end(), 1);
        return static_cast<int>(n);
    }

    void debug_out() {
        std::cout << "[";
        for(decltype(del_.size()) i = 0; i < del_.size(); i++) {
            if(del_[i] == 1) {
                std::cout << "\"" << i << "\",";
            }
        }
        std::cout << "]" << std::endl;
    }
private:
    std::array<int, 1000> del_;
};

int main() {
    Solution sol;
    std::vector<std::string> case1 {"cba", "daf", "ghi"};
    assert(sol.minDeletionSize(case1) == 1);

    std::vector<std::string> case2 {"a", "b"};
    assert(sol.minDeletionSize(case2) == 0);

    std::vector<std::string> case3 {"zyx", "wvu", "tsr"};
    assert(sol.minDeletionSize(case3) == 3);
}
