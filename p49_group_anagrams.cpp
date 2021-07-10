#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <unordered_map>
#include "base/util.h"

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> sets;
        for (auto& str : strs) {
            auto key = str;
            std::sort(key.begin(), key.end());
            sets[key].push_back(str);
        }
        std::vector<std::vector<std::string>> retv;
        for (auto& [k, v] : sets) {
            retv.push_back(v);
        }
        return retv;
    }
};

int main(int argc, const char* argv[]) {
    Solution solution;
    std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto groups = solution.groupAnagrams(strs);
    for (auto& g : groups) {
        std::cout << g << std::endl;
    }
    return 0;
}
