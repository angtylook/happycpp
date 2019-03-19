#include <stack>
#include <string>
#include <string_view>
#include <vector>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::vector<std::vector<int>> dp;
        size_t sz = s.size();
        for (size_t i = 0; i < sz; i++) {
            dp.push_back(std::vector<int>(sz, 0));
        }
        std::string_view sv(s);
        for (size_t i = 0; i < sz - 2; i++) {
            if (sv.substr(i, 2) == "()") {
                dp[i][i + 2] = 1;
            }
        }

        for (size_t d = 3; d < sz; d++) {
            for (size_t i = 0; i < sz; i++) {
                // dp[i][d] =
            }
        }

        return 0;
    }

    int lvp(std::string s) {
        std::string_view sv(s);
        int max = 0;
        size_t sz = sv.size();
        for (size_t i = 2; i < sz; i++) {
        }
    }

    bool isValid(std::string_view v) {
        std::stack<char> s;
        for (auto c : v) {
            if (!s.empty() && s.top() == '(' && c == ')') {
                s.pop();
            } else {
                s.push(c);
            }
        }
        return s.empty();
    }
};

int main() {
    return 0;
}
