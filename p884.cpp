#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <string_view>
#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::string> uncommonFromSentences(std::string A,
                                                   std::string B) {
        using Set = std::set<std::string_view>;
        auto split = [](const std::string& s, Set& all, Set& duplites) {
            std::string_view view(s);
            std::string_view::size_type first = 0;
            std::string_view::size_type last = view.find_first_of(' ', first);
            while (last != std::string_view::npos) {
                auto word = view.substr(first, last - first);
                if (all.find(word) != all.end()) {
                    duplites.insert(word);
                }
                all.insert(word);
                first = last + 1;
                last = view.find_first_of(' ', first);
            }
            if (last == std::string_view::npos) {
                auto word = view.substr(first);
                if (all.find(word) != all.end()) {
                    duplites.insert(word);
                }
                all.insert(word);
            }
        };

        Set all1, dup1;
        split(A, all1, dup1);
        Set all2, dup2;
        split(B, all2, dup2);

        Set t1, t2;
        std::set_union(dup1.begin(), dup1.end(), all2.begin(), all2.end(),
                       std::inserter(t1, t1.end()));
        std::set_union(dup2.begin(), dup2.end(), all1.begin(), all1.end(),
                       std::inserter(t2, t2.end()));

        Set r1, r2;
        std::set_difference(all1.begin(), all1.end(), t1.begin(), t1.end(),
                            std::inserter(r1, r1.end()));
        std::set_difference(all2.begin(), all2.end(), t2.begin(), t2.end(),
                            std::inserter(r2, r2.end()));

        Set all;
        std::set_union(r1.begin(), r1.end(), r2.begin(), r2.end(),
                       std::inserter(all, all.end()));
        std::vector<std::string> r;
        for (auto v : all) {
            r.emplace_back(v);
        }
        return r;
    }
};

int main() {
    Solution sol;
    std::cout << sol.uncommonFromSentences("this apple is sweet",
                                           "this apple is sour")
              << std::endl;
    std::cout << sol.uncommonFromSentences("s z z z s", "s z ejt") << std::endl;
    return 0;
}
