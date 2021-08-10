#include <iostream>

class Solution {
public:
    int findComplement(int num) {
        unsigned ones = 0xffffffff;
        unsigned mask = 0x80000000;
        int r = num ^ ones;
        int i = 0;
        for (; i < 32; i++) {
            if (mask & (num << i)) {
                break;
            }
        }
        r = r & (ones >> i);
        return r;
    }
};

int main() {
    Solution sol;
    std::cout << sol.findComplement(5) << std::endl;
    std::cout << sol.findComplement(1) << std::endl;
    return 0;
}
