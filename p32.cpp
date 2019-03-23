#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <string_view>
#include <vector>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::cout << "====" << s << "======" << std::endl;
        size_t sz = s.size();
        std::string_view sv(s);

        std::vector<std::vector<size_t>> dp;
        for (size_t i = 0; i < sz; i++) {
            dp.push_back(std::vector<size_t>(sz + 1, 0));
        }

        // std::string_view max;
        size_t max = 0;
        for (size_t i = 0; i <= sz - 2; i++) {
            auto v = sv.substr(i, 2);
            if (v == "()") {
                dp[i][i + 2] = 1;
                // max = v;
                max = 2;
                // std::cout << "[" << i << "," << i + 2 << "," << 1 << "]";
            }
        }
        // std::cout << std::endl;

        for (size_t d = 4; d <= sz; d += 2) {
            for (size_t i = 0; i <= sz - d; i++) {
                bool check = false;
                for (size_t k = 2; k < d; k += 2) {
                    /*
                    std::printf("[%d, %d] ==> [%d,%d] = %d, [%d,%d] = %d\n", i,
                                i + d, i, i + k, dp[i][i + k], i + k, i + d,
                                dp[i + k][i + d]);
*/
                    if (dp[i][i + k] == 1 && dp[i + k][i + d] == 1) {
                        dp[i][i + d] = 1;
                        max = d;
                        check = true;
                        break;
                    }
                }
                if (!check) {
                    // std::printf("check [%d,%d] = %d\n", i + 1, i + d - 1,
                    //            dp[i + 1][i + d - 1]);
                    if (dp[i + 1][i + d - 1] == 1 && i + d - 1 < sz &&
                        sv[i] == '(' && sv[i + d - 1] == ')') {
                        dp[i][i + d] = 1;
                        max = d;
                    }
                    /*
                    auto v = sv.substr(i, d);
                    if (isValid(v)) {
                        dp[i][i + d] = v.size();
                        // std::cout << v << " = " << v.size() << std::endl;
                        max = v.size();
                    }*/
                }
            }
        }

        // return int(max.size());
        return int(max);
    }

    int lvp(std::string s) {
        std::string_view sv(s);
        size_t max = 0;
        size_t sz = sv.size();
        for (size_t i = 1; i < sz; i++) {
            std::string_view v;
            if (i >= (max + 1)) {
                v = sv.substr(i - max - 1, max + 2);
            } else {
                v = sv.substr(0, max + 2);
            }

            if (isValid(v)) {
                max = v.size();
            }

            if (i >= (2 * max + 1)) {
                v = sv.substr(i - 2 * max - 1, 2 * max + 2);
            } else {
                v = sv.substr(0, 2 * max + 2);
            }

            if (isValid(v)) {
                max = v.size();
            }
        }
        return int(max);
    }

    bool isValid(std::string_view v) {
        if (v.size() % 2 != 0) {
            return false;
        }
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
    Solution sol;
    // 2
    std::cout << sol.longestValidParentheses("(()") << std::endl;
    // 4
    std::cout << sol.longestValidParentheses(")()())") << std::endl;
    // 2
    std::cout << sol.longestValidParentheses("())") << std::endl;
    // 6
    std::cout << sol.longestValidParentheses("()(())") << std::endl;
    // 22
    std::cout << sol.longestValidParentheses(")(((((()())()()))()(()))(")
              << std::endl;
    std::cout << sol.longestValidParentheses(
        "((())())(()))(()()(()(()))(()((((()))))))((()())()))()()(()(((((()()()"
        "())))()())(()()))((((((())))((()))()()))))(()))())))()))()())((()())))"
        ")(()(((((())))))()((()(()(())((((())(())((()()(()())))())(()(())()()))"
        "())(()()()))()(((()())(((()()())))(((()()()))(()()))()))()))))))())()("
        ")((()(())(()))()((()()()((())))()(((()())(()))())())))(((()))))())))()"
        "(())))()())))())()((()))((()))()))(((())((()()()(()((()((())))((()()))"
        "())(()()(()))))())((())))(()))()))))))()(()))())(()())))))(()))((())(("
        ")((())(((((()()()(()()())))(()())()((()(()()))(()(())((()((()))))))))("
        "()(())()())()(()(()(()))()()()(()()())))(())(()((((()()))())))(())((()"
        "(())())))))())()()))(((())))())((()(()))(()()))((())(())))))(()(()((()"
        "((()()))))))(()()()(()()()(()(())()))()))(((()(())()())(()))())))(((()"
        "))())(()((()))(()((()()()(())()(()())()(())(()(()((((())()))(((()()((("
        "()())(()()()(())()())())(()(()()((()))))()(()))))(((())))()()))(()))(("
        "()))))()()))))((((()(())()()()((()))((()))())())(()((()()())))))))()))"
        "(((()))))))(()())))(((()))((()))())))(((()(((())))())(()))))(((()((((("
        "((((((((())(((()))((((())())()))())((((())(((())))())(((()))))()())()("
        "())())(()))))()))()()()))(((((())()()((()))())(()))()()(()()))(())(()("
        ")))()))))(((())))))((()()(()()()()((())((((())())))))((((((()((()((())"
        "())(()((()))(()())())())(()(())(())(()((())((())))(())())))(()()())((("
        "(()))))((()(())(()(()())))))))))((()())()()))((()(((()((()))(((((()()("
        ")()()(()(()((()(()))(()(()((()()))))()(()()((((((()((()())()))((())()("
        ")(((((()(()))))()()((()())((()())()(())((()))()()(()))");
    // std::cout << sol.lvp(")(((((()())()()))()(()))(") <<
    // std::endl; std::cout << sol.lvp(")()())") << std::endl;
    // std::cout << sol.lvp("())") << std::endl;
    // std::cout << sol.lvp("()(())") << std::endl;
    return 0;
}
