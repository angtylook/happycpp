#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    int numSpecialEquivGroups(std::vector<std::string>& A) {
        using Group = std::pair<std::multiset<char>, std::multiset<char>>;
        using GroupSet = std::set<Group>;
        GroupSet groupSet;
        for (auto& s : A) {
            Group group;
            for (size_t i = 0; i < s.size(); i++) {
                if (i % 2 == 0) {
                    group.first.insert(s[i]);
                } else {
                    group.second.insert(s[i]);
                }
            }
            groupSet.insert(group);
        }
        return static_cast<int>(groupSet.size());
    }
};

int main() {
    std::vector<std::string> t1{"a", "b", "c", "a", "c", "c"};
    std::vector<std::string> t2{"ababaa", "aaabaa"};
    std::vector<std::string> t3{"abc", "acb", "bac", "bca", "cab", "cba"};
    std::vector<std::string> t4{"abcd", "cdab", "adcb", "cbad"};
    Solution sol;
    std::cout << sol.numSpecialEquivGroups(t1) << std::endl;
    std::cout << sol.numSpecialEquivGroups(t2) << std::endl;
    std::cout << sol.numSpecialEquivGroups(t3) << std::endl;
    std::cout << sol.numSpecialEquivGroups(t4) << std::endl;
    return 0;
}
