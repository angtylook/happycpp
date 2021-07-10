#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int maxAreaIdx(std::vector<int>& height, size_t i) {
            int max_area = 0;
            size_t j = height.size() - 1;
            while (j > i) {
                auto w = j - i;
                auto ge = height[j] >= height[i];
                auto area = ge ? height[i] * w : height[j] * w;
                if (max_area < area) {
                    max_area = area;
                }
                if (ge) {
                    break;
                }
                j--;
            }
            return max_area;
    };

    int maxAreaOne(std::vector<int>& height) {
        int max_area = 0;
        for (size_t i = 0; i < height.size()-1; i++) {
            auto area = maxAreaIdx(height, i);
            if (max_area < area) {
                max_area = area;
            }
        }
        return max_area;
    }

    int maxArea(const std::vector<int>& height) {
        int max_area = 0;
        size_t i = 0;
        size_t j = height.size() - 1;
        while (i < j) {
            auto ge = height[i] >= height[j];
            auto area =  ge ? height[j] * (j - i) : height[i] *(j-i);
            if (area > max_area) {
                max_area = area;
            }
            ge ? j-- : i++;
        }
        return max_area;
    }
};


int main() {
    Solution sol;
    std::cout << sol.maxArea(std::vector<int>{1, 1}) << std::endl;
    std::cout << sol.maxArea(std::vector<int>{4,3,2,1,4}) << std::endl;
    std::cout << sol.maxArea(std::vector<int>{1, 2, 1}) << std::endl;
    std::cout << sol.maxArea(std::vector<int>{1, 8,6,2,5,4,8,3,7}) << std::endl;
    return 0;
}
