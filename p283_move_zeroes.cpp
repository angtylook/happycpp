#include <vector>
#include "base/util.h"

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        auto sz = nums.size();
        size_t i = 0;
        size_t p = 0;
        while (i < sz) {
            if (nums[i] != 0) {
                nums[p] = nums[i];
                p++;
            }
            i++;
        }
        while (p < sz) {
            nums[p] = 0;
            p++;
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> empty;
    sol.moveZeroes(empty);
    std::cout << empty << std::endl;

    std::vector<int> zero = {0};
    sol.moveZeroes(zero);
    std::cout << zero << std::endl;

    std::vector<int> zeros = {0, 0};
    sol.moveZeroes(zeros);
    std::cout << zeros << std::endl;

    std::vector<int> one = {1};
    sol.moveZeroes(one);
    std::cout << one << std::endl;

    std::vector<int> ones = {1, 1};
    sol.moveZeroes(ones);
    std::cout << ones << std::endl;

    std::vector<int> leading_zeros = {0, 0, 1, 1};
    sol.moveZeroes(leading_zeros);
    std::cout << leading_zeros << std::endl;

    std::vector<int> tail_zeros = {1, 1, 0, 0};
    sol.moveZeroes(tail_zeros);
    std::cout << tail_zeros << std::endl;
    
    std::vector<int> mix_zeros = {0,1,0,3,12};
    sol.moveZeroes(mix_zeros);
    std::cout << mix_zeros << std::endl;
    return 0;
}