#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& A) {
        size_t even = 0;
        size_t index = 0;
        size_t sz = A.size();
        while (index < sz) {
            if (A[index] % 2 == 0) {
                auto tmp = A[index];
                A[index] = A[even];
                A[even] = tmp;
                even++;
            }
            index++;
        }
        return A;
    }
};

int main() {
    Solution sol;
    std::vector<int> vi{3, 1, 2, 4};
    vi = sol.sortArrayByParity(vi);
    for (auto e : vi) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    return 0;
}
