#include <iostream>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        if (s.empty()) {
            return p.empty() || p == "*";
        }
        if (p.empty()) {
            return s.empty();
        }
        // assert(!s.empty() && !p.empty())
        return true;
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha;
    std::cout << sol.isMatch("aa", "a") << std::endl;         // false
    std::cout << sol.isMatch("aa", "*") << std::endl;         // true
    std::cout << sol.isMatch("cb", "?a") << std::endl;        // false
    std::cout << sol.isMatch("adceb", "*a*b") << std::endl;   // true
    std::cout << sol.isMatch("acdcb", "a*c?b") << std::endl;  // false
    return 0;
}
