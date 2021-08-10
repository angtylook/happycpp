#include <vector>
#include <unordered_map>

#include "base/util.h"

/*
 * Given a non-empty array of integers, return the k most frequent elements.
 * You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the
 * array's size. 
 * It's guaranteed that the answer is unique, in other words the set
 * of the top k frequent elements is unique. You can return the answer in any order.
*/

class Solution {
public:
    std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> frequents;
        for (auto n : nums) {
            frequents[n]++;
        }
        std::vector<std::pair<int, int>> kheap;
        kheap.reserve(k);
        std::greater<std::pair<int, int>> cmp;
        int n = 0;
        for (auto& [num, fre] : frequents) {
            if (n < k) {
                n++;
                kheap.emplace_back(fre, num);
                if (n == k) {
                    std::make_heap(kheap.begin(), kheap.end(), cmp);
                }
                continue;
            }
            kheap.emplace_back(fre, num);
            std::push_heap(kheap.begin(), kheap.end(), cmp);
            std::pop_heap(kheap.begin(), kheap.end(), cmp);
            kheap.pop_back();
        }
        std::vector<int> ret;
        ret.reserve(k);
        std::transform(
            kheap.begin(), kheap.end(), std::back_inserter(ret),
            [](const std::pair<int, int>& p) -> int { return p.second; });
        return ret;
    }
};

int main() {
    Solution sol;
    std::cout << sol.topKFrequent({1, 1, 1, 2, 2, 3}, 2) << std::endl;
    std::cout << sol.topKFrequent({1}, 1) << std::endl;
    return 0;
}
