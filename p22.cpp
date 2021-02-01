#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

#include "base/util.h"

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> out;
        std::string current;
        generateParenthesis(out, current, n, 0, 0);
        // std::sort(out.begin(), out.end());
        return out;
    }
    
    void generateParenthesis(std::vector<std::string>& out, std::string current, int n, int open, int close) {
        if (open == n && close == n) {
            out.push_back(current);
            return;
        }
        if (open < n) {
            generateParenthesis(out, current + "(", n, open+1, close);
        }
        if (close < open) {
            generateParenthesis(out, current + ")", n, open, close+1);
        }
    }
};

int main() {
    Solution sol;
    std::cout << sol.generateParenthesis(3) << std::endl;
    std::cout << sol.generateParenthesis(4) << std::endl;
    std::cout << sol.generateParenthesis(5) << std::endl;
    return 0;
}
