#include <iostream>
#include <string>
#include <thread>
#include <tuple>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        size_t l = 0;
        size_t r = nums.size();
        while (l < r) {
            size_t m = (r - l) / 2 + l;
            if (target > nums[m]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[r] == target ? static_cast<int>(r) : -1;
    }
};

size_t binary_search(std::vector<int> arr, int v) {
    size_t l = 0;
    size_t r = arr.size();
    while (l < r) {
        size_t m = (r - l) / 2 + l;
        if (v > arr[m]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return r;
}

int main() {
    // std::vector<int> v1{1, 2, 3, 4, 5, 6};
    // std::vector<int> v2{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> v3{-1,0,3,5,9,121};
    // std::cout << binary_search(v1, 2) << std::endl;
    // std::cout << binary_search(v1, 6) << std::endl;
    // std::cout << binary_search(v1, 8) << std::endl;

    // std::cout << binary_search(v2, 1) << std::endl;
    // std::cout << binary_search(v2, 3) << std::endl;
    // std::cout << binary_search(v2, 8) << std::endl;

    std::cout << binary_search(v3, 2) << std::endl;
    // std::cout << binary_search(v3, 3) << std::endl;
    // std::cout << binary_search(v3, 8) << std::endl;

    return 0;
}
