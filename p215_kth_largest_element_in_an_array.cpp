#include <vector>
#include <random>

#include "base/util.h"

class Solution {
public:
    size_t partition(std::vector<int>& nums, size_t begin, size_t end) {
        auto last = end - 1;
        auto p = nums[last];
        size_t i = begin;
        size_t j = begin;
        while (j < last) {
            if (nums[j] <= p) {
                auto t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                i++;
            }
            j++;
        }
        nums[last] = nums[i];
        nums[i] = p;
        return i;
    }

    size_t randomPartition(std::vector<int>& nums, size_t begin, size_t end) {
        std::default_random_engine e;
        std::uniform_int_distribution<size_t> dist(begin, end-1);
        auto r = dist(e);
        std::cout << "before swap " << nums << std::endl;
        std::cout << "swap " << r << " -> " << nums[r] << std::endl;
        std::swap(nums[r], nums[end - 1]);
        std::cout << "after swap " << nums << std::endl;
        return partition(nums, begin, end);
    }

    int findKthLargest(std::vector<int>& nums, int k) {
        k = nums.size() - k;
        size_t begin = 0;
        size_t end = nums.size();
        while (true) {
            auto i = partition(nums, begin, end);
            if (i == k) {
                return nums[i];
            }
            if (i < k) {
                begin = i;
            } else {
                end = i;
            }
        }
        return nums[0];
    }
};


int main() {
    Solution sol;
    std::vector<int> v1{3, 2, 1, 5, 6, 4};
    std::vector<int> v2{3, 2, 3, 1, 2, 4, 5, 5, 6};
    std::cout << sol.findKthLargest(v1, 2) << std::endl;
    std::cout << sol.findKthLargest(v2, 4) << std::endl;
    /*
    std::cout << sol.randomPartition(v1, 0, v1.size()) << "->" << v1
              << std::endl;
    std::cout << sol.randomPartition(v2, 0, v2.size()) << "->" << v2
              << std::endl;
    std::vector<int> v3{2};
    std::cout << sol.partition(v3, 0, v3.size()) << "->" << v3 << std::endl;
    */
    return 0;
}
