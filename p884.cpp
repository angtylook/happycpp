#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <string_view>
#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::string> uncommonFromSentences(std::string A,
                                                   std::string B) {
        auto split = [](const std::string& s) -> std::set<std::string_view> {
            std::set<std::string_view> words;
            std::string_view view(s);
            std::string_view::size_type first = 0;
            std::string_view::size_type last = view.find_first_of(' ', first);
            while (first != last) {
                auto word = view.substr(first, last - first);
                if (words.find(word) != words.end()) {
                    words.insert(word);
                } else {
                    words.erase(word);
                }
                first = last + 1;
                last = view.find_first_of(' ', first);
            }

            return words;
        };
        auto s1 = split(A);
        auto s2 = split(B);
        std::vector<std::string_view> vr;
        std::vector<std::string> r;
        std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(),
                                      s2.end(), std::back_inserter(vr));
        std::copy(vr.begin(), vr.end(), std::back_inserter(r));
        return r;
    }
};

int main() {
    Solution sol;
    std::cout << sol.uncommonFromSentences("this apple is sweet",
                                           "this apple is sour")
              << std::endl;
    std::cout << sol.uncommonFromSentences("apple apple", "banana")
              << std::endl;
    return 0;
}
