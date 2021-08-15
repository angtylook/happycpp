#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Solution {
public:
    bool isSelfDivided(int n) {
        auto number = n;
        while (n != 0) {
            auto r = n % 10;
            if (r == 0 || number % r != 0) {
                return false;
            }
            n = n / 10;
        }
        return true;
    }

    std::vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> vi;
        for (auto i = left; i <= right; i++) {
            if (isSelfDivided(i)) {
                vi.push_back(i);
            }
        }
        return vi;
    }
};

int main() {
    std::ostream_iterator<int> out(std::cout, " ");
    Solution sol;

    auto vi = sol.selfDividingNumbers(1, 22);
    std::copy(vi.begin(), vi.end(), out);
    std::cout << std::endl;
    return 0;
}
