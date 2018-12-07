#include <algorithm>
#include <cassert>
#include <vector>

class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        size_t n = nums.size();
        int min_num = nums[0];
        int max_num = nums[1];
        if (min_num > max_num) {
            min_num = nums[1];
            max_num = nums[0];
        }
        int sum = min_num;

        for (size_t i = 2; i < n; i += 2) {
            auto small = nums[i];
            auto big = nums[i + 1];
            if (big < small) {
                small = nums[i + 1];
                big = nums[i];
            }

            if (small >= max_num) {
                sum += small;
                max_num = big;
                continue;
            }

            if (big <= min_num) {
                sum += small;
                min_num = small;
                continue;
            }

            if (max_num < big) {
                sum += max_num;
                max_num = big;
            } else {
                sum += big;
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    std::vector<int> vi{1, 4, 3, 2};
    assert(sol.arrayPairSum(vi) == 4);

    std::vector<int> vi1{7, 3, 1, 0, 0, 6};
    assert(sol.arrayPairSum(vi) == 7);
    return 0;
}
