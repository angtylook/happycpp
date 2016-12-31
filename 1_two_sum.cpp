#include <vector>
#include <iostream>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target){
    std::vector<int> result;
    for(int i = 0; i < nums.size(); ++i) {
      for(int j = i + 1; j < nums.size(); ++j) {
        if(nums[i] + nums[j] == target) {
          result.push_back(i);
          result.push_back(j);
          return result;
        }
      }
    }
    return result;
  }
};

int main(int argc, const char* argv[]) {
  std::vector<int> nums = {3, 2, 4};
  int target = 6;
  Solution solution;
  auto result = solution.twoSum(nums, target);
  for(auto& x: result) {
    std::cout << x << ' ';
  }
  std::cout << std::endl;
  return 0;
}


