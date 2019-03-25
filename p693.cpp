#include <iostream>

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned kMask = 0x80000000;
        bool first = false;
        while (kMask != 0) {
            if ((kMask & unsigned(n)) > 0) {
                if (!first)
                    first = true;
                else
                    return false;
            } else {
                first = false;
            }
            kMask = kMask >> 1;
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha;
    std::cout << sol.hasAlternatingBits(4) << std::endl;
    std::cout << sol.hasAlternatingBits(5) << std::endl;
    std::cout << sol.hasAlternatingBits(7) << std::endl;
    std::cout << sol.hasAlternatingBits(11) << std::endl;
    std::cout << sol.hasAlternatingBits(10) << std::endl;
    return 0;
}
