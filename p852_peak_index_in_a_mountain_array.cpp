#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& A) {
        size_t low = 0;
        size_t high = A.size();
        while (low < high) {
            auto mid = low + (high - low) / 2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                return static_cast<int>(mid);
            }
            if (A[mid] > A[mid - 1] && A[mid] < A[mid + 1]) {
                low = mid + 1;
            }
            if (A[mid] > A[mid + 1] && A[mid] < A[mid - 1]) {
                high = mid;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> vi{0, 1, 0};
    assert(sol.peakIndexInMountainArray(vi) == 1);
    std::vector<int> vi2{0, 2, 1, 0};
    assert(sol.peakIndexInMountainArray(vi2) == 1);
    return 0;
}
