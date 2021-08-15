#include <iostream>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        std::string p1;
        for (auto c : p) {
            if (p1.empty() || c != '*' || p1.back() != '*') {
                p1.push_back(c);
            }
        }
        return isMatchSV(s, p1);
    }

    bool isMatchSV(std::string_view s, std::string_view p) {
        if (s.empty()) {
            return p.empty() || p == "*";
        }
        if (p.empty()) {
            return s.empty();
        }
        // assert(!s.empty() && !p.empty())
        bool first_match = s[0] == p[0] || p[0] == '?' || p[0] == '*';
        if (s[0] == p[0] || p[0] == '?') {
            return isMatchSV(s.substr(1), p.substr(1));
        }
        if (p[0] == '*') {
            return isMatchSV(s.substr(1), p.substr(1)) ||
                   isMatchSV(s, p.substr(1)) || isMatchSV(s.substr(1), p);
        }

        return first_match;
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
