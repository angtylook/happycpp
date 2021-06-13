#include <vector>
#include "base/util.h"

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        auto slow = nums[0];
        auto fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = nums[0];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};

int main() {
    Solution sol;
    std::vector<int> v1{1, 3, 4, 2, 2};
    std::cout << sol.findDuplicate(v1) << std::endl;
    std::vector<int> v2{3, 1, 3, 4, 2};
    std::cout << sol.findDuplicate(v2) << std::endl;
    std::vector<int> v3{1, 1};
    std::cout << sol.findDuplicate(v3) << std::endl;
    return 0;
}