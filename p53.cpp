#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if(nums.empty())
            return 0;

        std::vector<int> record;
        record.push_back(nums[0]);
        int max = nums[0];
        for(size_t i = 1; i < nums.size(); ++i) {
            if(record.back() + nums[i] > nums[i])
                record.push_back(record.back() + nums[i]);
            else
                record.push_back(nums[i]);
            if(max < record.back()) {
                max = record.back();
            }
        }
        return max;
    }
};

int main() {
    return 0;
}
