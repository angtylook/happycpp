#include <bitset>
#include <cassert>
#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        std::bitset<sizeof(int) * 8> bitx(x);
        std::bitset<sizeof(int) * 8> bity(y);
        return static_cast<int>((bitx ^ bity).count());
    }
};

int main() {
    Solution sol;
    assert(sol.hammingDistance(1, 4) == 2);
    // assert(__builtin_popcount(93 ^ 73) == 2);
    assert(sol.hammingDistance(93, 73) == 2);
    return 0;
}
