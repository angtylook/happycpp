#include <iostream>
#include <string>

class Solution {
public:
    void reverseString(std::string& s,
                       std::string::size_type begin,
                       std::string::size_type end) {
        if (end == s.npos) {
            end = s.size();
        }
        size_t sz = end - begin;
        size_t mid = begin + (sz / 2);
        for (size_t i = begin; i < mid; i++) {
            char c = s[i];
            s[i] = s[end - i - 1 + begin];
            s[end - i - 1 + begin] = c;
        }
    }

    std::string reverseWords(std::string s) {
        auto begin = s.find_first_not_of(" ");
        auto end = s.find_first_of(" ");
        while (begin != end) {
            reverseString(s, begin, end);
            begin = s.find_first_not_of(" ", end);
            end = s.find_first_of(" ", begin);
        }
        return s;
    }
};

int main() {
    Solution sol;
    std::cout << sol.reverseWords("Let's take LeetCode contest") << std::endl;
    return 0;
}
