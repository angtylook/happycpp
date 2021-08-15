#include <vector>
#include <string>
#include <set>
#include <utility>
#include <iostream>

/**
 * Given a string, your task is to count how many palindromic substrings in this string.
 * The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 */

class Solution {
public:
    int countSubstrings(std::string s) {
        std::set<std::pair<int, int>> strs;
        for (size_t n = 0; n < s.size(); n++) {
            for (size_t i = 0; i < s.size() - n; i++) {
                std::pair<int, int> rng(i,i+n);
                if (rng.second - rng.first == 0) {
                    strs.insert(rng);
                    continue;
                }
                auto inner = std::make_pair(rng.first + 1, rng.second - 1);
                if (s[rng.first] == s[rng.second] && (inner.second < inner.first || strs.find(inner)!=strs.end())) {
                    strs.insert(rng);
                }
            }
        }
        for (auto [first, last] : strs) {
            std::cout << s.substr(first, last - first + 1) << std::endl;
        }
        return static_cast<int>(strs.size());
    }
};

int main() {
    Solution sol;
    std::cout << sol.countSubstrings("abc") << std::endl;
    std::cout << sol.countSubstrings("aaa") << std::endl;
    std::cout << sol.countSubstrings("abaca") << std::endl;
    return 0;
}
