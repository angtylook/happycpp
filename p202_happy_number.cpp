#include <array>
#include <cassert>
#include <iostream>
#include <set>

class Solution {
public:
    int sumOfDigitSquared(int n) {
        int sum{0};
        while (n != 0) {
            auto r = n % 10;
            sum += sqrt_[r];
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        while (n > 99) {
            n = sumOfDigitSquared(n);
        }
        return flags_[n];
    }

private:
    std::array<int, 10> sqrt_{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    std::array<bool, 100> flags_{
        false, true,  false, false, false, false, false, true,  false, false,
        true,  false, false, true,  false, false, false, false, false, true,
        false, false, false, true,  false, false, false, false, true,  false,
        false, true,  true,  false, false, false, false, false, false, false,
        false, false, false, false, true,  false, false, false, false, true,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, true,  false,
        true,  false, false, false, false, false, false, false, false, true,
        false, false, true,  false, false, false, true,  false, false, false,
        false, true,  false, false, true,  false, false, true,  false, false};
};

void generate() {
    Solution sol;
    auto check = [&sol](int n) -> bool {
        std::set<int> repeated;
        while (true) {
            auto squared = sol.sumOfDigitSquared(n);
            if (squared == 1) {
                break;
            }
            if (repeated.count(squared) == 1) {
                return false;
            }
            repeated.insert(squared);
            n = squared;
        }
        return true;
    };
    std::cout << std::boolalpha;
    for (int i = 0; i < 100; i++) {
        std::cout << check(i) << ", ";
    }
}

int main() {
    // generate();
    Solution sol;
    assert(sol.isHappy(19) == true);
    return 0;
}
