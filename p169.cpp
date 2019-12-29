#include <vector>
#include <map>
#include <iostream>

class Solution {
public:
    int majorityElement(const std::vector<int>& nums) {
        auto major = nums.size() / 2;
        std::map<int, size_t> counts;
        for (auto n : nums) {
            counts[n]++;
            if (counts[n] > major) {
                return n;
            }
        }
        return 0; 
    }
};

int main() {
    Solution sol;
    std::cout << sol.majorityElement({1}) << std::endl;
    std::cout << sol.majorityElement({3,2,3}) << std::endl;
    std::cout << sol.majorityElement({2,2,1,1,1,2,2}) << std::endl;
    return 0;
}