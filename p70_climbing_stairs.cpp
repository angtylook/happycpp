#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n < 1) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        std::vector<int> ways(n + 1, 0);
        ways[1] = 1;
        ways[2] = 2;
        for (int i = 3; i <= n; i++) {
            ways[i] = ways[i - 1] + ways[i - 2];
        }
        return ways[n];
    }
};

int main() {
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(1) << std::endl;
    Solution sol;
    for (int i = 0; i < 10; i++) {
        std::cout << sol.climbStairs(i) << std::endl;
    }
    return 0;
}