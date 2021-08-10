#include <vector>
#include "base/util.h"

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        size_t sz = s.size();
        size_t mid = sz / 2;
        for (size_t i = 0; i < mid; i++) {
            char c = s[i];
            s[i] = s[sz - i - 1];
            s[sz - i - 1] = c;
        }
    }
};

int main() {
    Solution sol;
    std::vector s{'h', 'e', 'l', 'l', 'o'};
    std::cout << s << std::endl;
    sol.reverseString(s);
    std::cout << s << std::endl;

    std::vector s1{'h', 'e', 'l', 'l', 'o', 'a'};
    std::cout << s1 << std::endl;
    sol.reverseString(s1);
    std::cout << s1 << std::endl;

    return 0;
}
