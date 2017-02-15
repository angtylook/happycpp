#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>

class Solution {
public:
	// nums an non empty array with size >= end
	// start the range begin index
	// end the range end index
	// !nums.empty() and [start, end)
	// return k if index < k then number <= num else number > num
	size_t findIndexBinary(std::vector<int>& nums, size_t start, size_t end, float num) {
		size_t mid = 0;
		while (end - start > 1) {
			mid = (start + end) / 2;
			if (num < nums[mid]) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		if (num < nums[start])
			return start;
		else
			return end;
	}

	void printResult(std::vector<int>& arr, size_t k, float number) {
		std::cout << "partion with number: " << number << " k = " << k << std::endl;
		std::cout << "{ ";
		for (size_t i = 0; i < k && i < arr.size(); ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << "}" << std::endl;
		std::cout << "{ ";
		for (size_t i = k; i < arr.size(); ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << "}" << std::endl;
	}

	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		// to find
		size_t k = (nums1.size() + nums2.size()) / 2;
		std::cout << "k = " << k << std::endl;
		size_t start1 = 0;
		size_t start2 = 0;
		size_t end1 = nums1.size();
		size_t end2 = nums2.size();
		// init
		float p = (nums1[(start1 + end1) / 2] + nums2[(start2 + end2) / 2]) / 2.0;
		size_t k1 = findIndexBinary(nums1, start1, end1, p);
		printResult(nums1, k1, p);
		size_t k2 = findIndexBinary(nums2, start2, end2, p);
		printResult(nums2, k2, p);
		size_t left = k1 + k2;
		//size_t right = (nums1.size() - k1) + (nums2.size() - k2);
		std::cout << "k1 = " << k1 << ", k2 = " << k2 << ", p = " << p << std::endl;
		while (k != left && (end1 - start1 > 1 || end2 - start2 > 1)) {
			if (k < left) {
				end1 = k1;
				end2 = k2;
			}
			else {
				start1 = k1;
				start2 = k2;
			}
			p = (nums1[(start1 + end1) / 2] + nums2[(start2 + end2) / 2]) / 2.0;
			k1 = findIndexBinary(nums1, start1, end1, p);
			printResult(nums1, k1, p);
			k2 = findIndexBinary(nums2, start2, end2, p);
			printResult(nums2, k2, p);
			left = k1 + k2;
			std::cout << "k1 = " << k1 << ", k2 = " << k2 << ", p = " << p << std::endl;
		}
		return 0;
		/*
		bool isEven = (nums1.size() + nums2.size()) % 2 == 0;

		if (k1 == 0 || k1 == nums1.size()) {
			if (k1 == 0) {
				if (isEven) {
					return (nums2[k] + nums2[k - 1]) / 2.0;
				}
				else {
					return nums2[k];
				}
			}
			if (k1 == nums1.size()) {
				if (isEven) {
					return (nums2[k - nums1.size()] + nums2[k - nums1.size() - 1]) / 2.0;
				}
				else {
					return nums2[k - nums1.size()];
				}
			}
		}
		if (k2 == 0 || k2 == nums2.size()) {
			if (k2 == 0) {
				if (isEven) {
					return (nums1[k] + nums1[k - 1]) / 2.0;
				}
				else {
					return nums1[k];
				}
			}
			if (k2 == nums2.size()) {
				if (isEven) {
					return (nums1[k - nums2.size()] + nums1[k - nums2.size() - 1]) / 2.0;
				}
				else {
					return nums1[k - nums2.size()];
				}
			}
		}

		if (isEven) {
			return (nums1[k1] + nums2[k2]) / 2.0;
		}
		else {
			return nums1[k1] > nums2[k2] ? nums1[k1] : nums2[k2];
		}*/
	}

	void test0() {
		std::vector<int> nums1 = { 1, 3 };
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
		std::vector<int> nums2 = { 2 };
		index = findIndexBinary(nums2, 0, nums2.size(), 1);
		std::cout << "part {2} with 1 => " << index << std::endl;
		index = findIndexBinary(nums2, 0, nums2.size(), 2);
		std::cout << "part {2} with 2 => " << index << std::endl;
		index = findIndexBinary(nums2, 0, nums2.size(), 3);
		std::cout << "part {2} with 3 => " << index << std::endl;
	}

	void test() {
		/*
		std::vector<int> nums1 = { 1, 3 };
		std::vector<int> nums2 = { 2 };
		std::cout << "{1, 3}, {2} ==> " << findMedianSortedArrays(nums1, nums2) << std::endl;
		
		
		std::vector<int> nums3 = { 1, 2 };
		std::vector<int> nums4 = { 3, 4 };
		std::cout << "{1, 2}, {3, 4} ==> " << findMedianSortedArrays(nums3, nums4) << std::endl;
		*/
		std::vector<int> nums5 = { 1, 2, 3, 4 };
		std::vector<int> nums6 = { 3, 4, 5 };
		std::cout << "{1, 2, 3, 4}, {3, 4, 5} ==> " << findMedianSortedArrays(nums5, nums6) << std::endl;
		
		/*
		std::vector<int> nums7 = { 1, 2, 3 };
		std::vector<int> nums8 = { 3, 4, 6 };
		std::cout << "{1, 2, 3}, {3, 4, 6} ==> " << findMedianSortedArrays(nums7, nums8) << std::endl;
		*/
	}

};

int main(int argc, const char* argv[]) {
	Solution solution;
	//solution.test0();
	solution.test();
	return 0;
}
