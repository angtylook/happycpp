#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    int distributeCandies(std::vector<int>& candies) {
        std::set<int> s;
        for (auto c : candies) {
            s.insert(c);
        }
        auto half = candies.size() / 2;
        if (s.size() < half) {
            return int(s.size());
        }
        return int(half);
    }
};

int main() {
    Solution sol;
    std::vector t1{1, 1, 2, 2, 3, 3};
    std::vector t2{1, 1, 2, 3};
    std::cout << sol.distributeCandies(t1) << std::endl;
    std::cout << sol.distributeCandies(t2) << std::endl;
    return 0;
}
