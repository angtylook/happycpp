#include <cstdio>
#include <iostream>
#include <string>
#include <string_view>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        dp = new int*[s.size() + 1];
        for (size_t i = 0; i <= s.size(); i++) {
            dp[i] = new int[p.size() + 1];
            for (size_t j = 0; j <= p.size(); j++) {
                dp[i][j] = 0;
            }
        }

        bool match = isMatchSV(0, 0, std::string_view(s), std::string_view(p));
        std::cout << "====" << s << "--->" << p << "======" << std::endl;
        for (size_t i = 0; i <= s.size(); i++) {
            for (size_t j = 0; j <= p.size(); j++) {
                std::printf("[%u, %u]=%d\n", i, j, dp[i][j]);
            }
            delete[] dp[i];
        }
        delete[] dp;
        return match;
    }

    bool isMatchSV(int x, int y, std::string_view s, std::string_view p) {
        dp[x][y]++;
        if (p.empty())
            return s.empty();

        bool match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (!match) {
            if (p[1] == '*') {
                return isMatchSV(x, y + 2, s, p.substr(2));
            }
            return false;
        }

        if (p[1] == '*') {
            // * == 0 || * > 0
            return isMatchSV(x, y + 2, s, p.substr(2)) ||
                   isMatchSV(x + 1, y, s.substr(1), p);
        }
        return isMatchSV(x + 1, y + 1, s.substr(1), p.substr(1));
    }

private:
    int** dp;
};

int main() {
    Solution sol;
    std::cout << std::boolalpha << false << ":" << sol.isMatch("aa", "a")
              << std::endl;
    std::cout << std::boolalpha << true << ":"
              << sol.isMatch("aaaaaaaaaaaaaaa", "a*") << std::endl;
    std::cout << std::boolalpha << true << ":"
              << sol.isMatch("abadglakedkealksgfv", ".*") << std::endl;
    std::cout << std::boolalpha << true << ":" << sol.isMatch("aab", "c*a*b")
              << std::endl;
    std::cout << std::boolalpha << false << ":"
              << sol.isMatch("mississippi", "mis*is*p*.") << std::endl;
    return 0;
}
