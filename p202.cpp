#include <array>
#include <cassert>

class Solution {
public:
    int sumOfDigitSquared(int n) {
        int sum {0};
        while(n != 0) {
            auto r = n % 10;
            sum += sqrt_[r];
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        return false;
    }
private:
    std::array<int, 10> sqrt_ {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
};

int main() {
    Solution sol;
    assert(sol.isHappy(19) == true);
    return 0;
}
