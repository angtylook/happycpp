#include <iostream>
#include <string>
#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<int> numberOfLines(std::vector<int>& widths, std::string S) {
        int line_count = 0;
        int line_width = 0;
        for (auto c : S) {
            line_width += widths[c - 'a'];
            if (line_width >= 100) {
                line_count++;
                if (line_width == 100) {
                    line_width = 0;
                } else {
                    line_width = widths[c - 'a'];
                }
            }
        }
        if (line_width > 0) {
            line_count++;
        }
        return std::vector{line_count, line_width};
    }
};

int main() {
    std::vector widths1{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                        10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    std::string s1("abcdefghijklmnopqrstuvwxyz");

    std::vector widths2{4,  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                        10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    std::string s2("bbbcccdddaaa");
    Solution sol;
    std::cout << sol.numberOfLines(widths1, s1) << std::endl;
    std::cout << sol.numberOfLines(widths2, s2) << std::endl;
    return 0;
}
