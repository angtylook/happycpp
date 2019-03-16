#include <iostream>
#include <string>
#include <string_view>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        return isMatchSV(std::string_view(s), std::string_view(p));
    }

    bool isMatchSV(std::string_view s, std::string_view p) {
        if (p.empty())
            return s.empty();

        bool match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (!match) {
            if (p[1] == '*') {
                return isMatchSV(s, p.substr(2));
            }
            return false;
        }

        if (p[1] == '*') {
            // * == 0 || * > 0
            return isMatchSV(s, p.substr(2)) || isMatchSV(s.substr(1), p);
        }
        return isMatchSV(s.substr(1), p.substr(1));
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha << false << ":" << sol.isMatch("aa", "a")
              << std::endl;
    std::cout << std::boolalpha << true << ":" << sol.isMatch("aa", "a*")
              << std::endl;
    std::cout << std::boolalpha << true << ":" << sol.isMatch("ab", ".*")
              << std::endl;
    std::cout << std::boolalpha << true << ":" << sol.isMatch("aab", "c*a*b")
              << std::endl;
    std::cout << std::boolalpha << false << ":"
              << sol.isMatch("mississippi", "mis*is*p*.") << std::endl;
    return 0;
}
