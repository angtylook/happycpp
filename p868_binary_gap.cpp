#include <iostream>

class Solution {
public:
    int binaryGap(int N) {
        const size_t sz = sizeof(int) * 8;
        size_t last = sz + 1;
        size_t max = 0;
        for (size_t i = 0; i < sz; i++) {
            unsigned b = 0x00000001 & (N >> i);
            // std::cout << b;
            if (b == 1) {
                if (last != sz + 1) {
                    size_t distance = i - last;
                    if (distance > max) {
                        max = distance;
                    }
                }
                last = i;
            }
        }
        // std::cout << std::endl;
        return int(max);
    }
};

int main() {
    Solution sol;
    std::cout << sol.binaryGap(22) << std::endl;
    std::cout << sol.binaryGap(5) << std::endl;
    std::cout << sol.binaryGap(6) << std::endl;
    std::cout << sol.binaryGap(8) << std::endl;
    return 0;
}
