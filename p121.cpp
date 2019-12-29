#include <vector>
#include <iostream>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        int profit = 0;
        size_t buy = 0;
        size_t sell = 0;
        size_t candidate = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            auto p = prices[i];
            if (p > prices[sell]) {
                sell = i;
                profit = p - prices[buy];
            }

            if (p - prices[candidate] > profit) {
                buy = candidate;
                sell = i;
                profit = p - prices[buy];
            } else if (p < prices[candidate]) {
                candidate = i;
            }
        }
        return profit;
    }
};

int main() {
    Solution sol;
    std::cout << sol.maxProfit({2, 1, 4}) << std::endl;
    std::cout << sol.maxProfit({7, 1, 5, 3, 6, 4}) << std::endl;
    std::cout << sol.maxProfit({1, 2, 3, 4, 5, 6}) << std::endl;
    std::cout << sol.maxProfit({1}) << std::endl;
    std::cout << sol.maxProfit({1, 2}) << std::endl;
    std::cout << sol.maxProfit({2, 1}) << std::endl;
    std::cout << sol.maxProfit({3, 2, 1}) << std::endl;
    return 0;
}