#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

class Solution {
public:
    // nums an non empty array with size >= end
    // start the range begin index
    // end the range end index
    // !nums.empty() and [start, end)
    // return k if index < k then number <= num else number > num
    size_t findIndexBinary(std::vector<int>& nums,
                           size_t start,
                           size_t end,
                           float num) {
        size_t mid = 0;
        while (end - start > 1) {
            mid = (start + end) / 2;
            if (num < nums[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (num < nums[start])
            return start;
        else
            return end;
    }

    void printResult(std::vector<int>& arr, size_t k, float number) {
        std::cout << "partion with number: " << number << " k = " << k
                  << std::endl;
        std::cout << "{ ";
        for (size_t i = 0; i < k && i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "| ";
        for (size_t i = k; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "}" << std::endl;
    }

    double findMedianSortedArrays(std::vector<int>& nums1,
                                  std::vector<int>& nums2) {
        if (nums1.front() == nums1.back() && nums2.front() == nums2.back()) {
            if (nums1.front() == nums2.front()) {
                return nums1.front();
            } else {
                if (nums1.size() == nums2.size()) {
                    return (nums1.front() + nums2.front()) / 2.0;
                } else if (nums1.size() > nums2.size()) {
                    return nums1.front();
                } else {
                    return nums2.front();
                }
            }
        }
     
        size_t n = nums1.size() + nums2.size();
        size_t k = n / 2;
        std::cout << "to find k = " << k << std::endl;

        size_t start1 = 0;
        size_t start2 = 0;
        size_t end1 = nums1.size();
        size_t end2 = nums2.size();
        // init
        float p =
            (nums1[(start1 + end1) / 2] + nums2[(start2 + end2) / 2]) / 2.0;
        size_t k1 = findIndexBinary(nums1, start1, end1, p);
        printResult(nums1, k1, p);
        size_t k2 = findIndexBinary(nums2, start2, end2, p);
        printResult(nums2, k2, p);
        size_t left = k1 + k2;
        // size_t right = (nums1.size() - k1) + (nums2.size() - k2);
        std::cout << "k1 = " << k1 << ", k2 = " << k2 << ", p = " << p
                  << std::endl;
        while (k != left - 1 && (end1 - start1 > 1 || end2 - start2 > 1)) {
            if (k < left) {
                end1 = k1;
                end2 = k2;
            } else {
                start1 = k1;
                start2 = k2;
            }
            p = (nums1[(start1 + end1) / 2] + nums2[(start2 + end2) / 2]) / 2.0;
            k1 = findIndexBinary(nums1, start1, end1, p);
            printResult(nums1, k1, p);
            k2 = findIndexBinary(nums2, start2, end2, p);
            printResult(nums2, k2, p);
            left = k1 + k2;
            std::cout << "k1 = " << k1 << ", k2 = " << k2 << ", p = " << p
                      << std::endl;
        }
        if (n % 2 == 1) {
            return std::max(nums1[k1 - 1], nums2[k2 - 1]);
        }
        return (nums1[k1 - 1] + nums2[k2 - 1]) / 2.0;
    }

    void test0() {
        std::vector<int> nums1 = {1, 3};
        // before start
        size_t index = findIndexBinary(nums1, 0, nums1.size(), 0);
        std::cout << "part {1, 3} with 0 => " << index << std::endl;
        // start
        index = findIndexBinary(nums1, 0, nums1.size(), 1);
        std::cout << "part {1, 3} with 1 => " << index << std::endl;
        // mid
        index = findIndexBinary(nums1, 0, nums1.size(), 2);
        std::cout << "part {1, 3} with 2 => " << index << std::endl;
        // end
        index = findIndexBinary(nums1, 0, nums1.size(), 3);
        std::cout << "part {1, 3} with 3 => " << index << std::endl;
        // after end
        index = findIndexBinary(nums1, 0, nums1.size(), 4);
        std::cout << "part {1, 3} with 4 => " << index << std::endl;
        // only one element
        std::vector<int> nums2 = {2};
        index = findIndexBinary(nums2, 0, nums2.size(), 1);
        std::cout << "part {2} with 1 => " << index << std::endl;
        index = findIndexBinary(nums2, 0, nums2.size(), 2);
        std::cout << "part {2} with 2 => " << index << std::endl;
        index = findIndexBinary(nums2, 0, nums2.size(), 3);
        std::cout << "part {2} with 3 => " << index << std::endl;
    }

    void test() {
        std::vector<int> nums1 = {2, 2, 2};
        std::vector<int> nums2 = {1, 3};
        auto p = findMedianSortedArrays(nums1, nums2);
        std::cout << "{0, 0}, {1, 2} ==> " << p << std::endl;
        /*
        std::vector<int> nums1 = { 1, 3 };
        std::vector<int> nums2 = { 2 };
        std::cout << "{1, 3}, {2} ==> " << findMedianSortedArrays(nums1, nums2)
        << std::endl;

        std::vector<int> nums3 = { 1, 2 };
        std::vector<int> nums4 = { 3, 4 };
        std::cout << "{1, 2}, {3, 4} ==> " << findMedianSortedArrays(nums3,
        nums4) << std::endl;

        std::vector<int> nums5 = {1, 2, 3, 4};
        std::vector<int> nums6 = {3, 4, 5};
        std::cout << "{1, 2, 3, 4}, {3, 4, 5} ==> "
                  << findMedianSortedArrays(nums5, nums6) << std::endl;

        std::vector<int> nums7 = { 1, 2, 3 };
        std::vector<int> nums8 = { 3, 4, 6 };
        std::cout << "{1, 2, 3}, {3, 4, 6} ==> " <<
        findMedianSortedArrays(nums7, nums8) << std::endl;

        std::vector<int> nums9 = { 3, 9, 16, 30, 40, 200 };
        std::vector<int> nums10 = { 34, 89, 100 };
        std::cout << "{ 3, 9, 16, 30, 40, 200 },{ 34, 89, 100 } ==> " <<
        findMedianSortedArrays(nums9, nums10) << std::endl;
        */
    }
};

int main(int argc, const char* argv[]) {
    Solution solution;
    // solution.test0();
    solution.test();
    return 0;
}
