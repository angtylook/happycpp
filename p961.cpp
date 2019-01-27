#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& A) {
        std::set<int> s;
        for (auto x : A) {
            if (s.find(x) == s.end()) {
                s.insert(x);
            } else {
                return x;
            }
        }
        return 0;
    }
};

int main() {
    std::vector<int> A{1, 2, 3, 3};
    std::vector<int> B{2, 1, 2, 5, 3, 2};
    Solution sol;
    std::cout << sol.repeatedNTimes(A) << std::endl;
    std::cout << sol.repeatedNTimes(B) << std::endl;
    return 0;
}
