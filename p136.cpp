#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int sum = 0;
        std::for_each(nums.begin(), nums.end(), [&sum](int v) { sum ^= v; });
        return sum;
    }
};

int main() {
    Solution sol;
    std::vector t1{2, 2, 1};
    std::cout << sol.singleNumber(t1) << std::endl;
    std::vector t2{4, 1, 2, 1, 2};
    std::cout << sol.singleNumber(t2) << std::endl;
    return 0;
}
