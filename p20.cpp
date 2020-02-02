#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (auto c : s) {
            if (!stack.empty() && isMatch(stack.top(), c)) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }

    bool isMatch(char l, char r) {
        switch (l) {
            case '(':
                return r == ')';
            case '{':
                return r == '}';
            case '[':
                return r == ']';
            default:
                return false;
        }
    }
};

int main() {
    Solution sol;
    std::cout << sol.isValid("()") << std::endl;
    std::cout << sol.isValid("()[]{}") << std::endl;
    std::cout << sol.isValid("(]") << std::endl;
    std::cout << sol.isValid("(])]") << std::endl;
    return 0;
}
