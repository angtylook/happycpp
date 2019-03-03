#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::string>& words) {
        std::vector<std::set<char>> keys{
            {'Q', 'q', 'W', 'w', 'E', 'e', 'R', 'r', 'T', 't',
             'Y', 'y', 'U', 'u', 'I', 'i', 'O', 'o', 'P', 'p'},
            {'A', 'a', 'S', 's', 'D', 'd', 'F', 'f', 'G', 'g', 'H', 'h', 'J',
             'j', 'K', 'k', 'L', 'l'},
            {'Z', 'z', 'X', 'x', 'C', 'c', 'V', 'v', 'B', 'b', 'N', 'n', 'M',
             'm'}};
        auto fit = [](const std::set<char>& key,
                      const std::string& word) -> bool {
            return std::all_of(word.begin(), word.end(), [&key](char c) {
                return key.find(c) != key.end();
            });
        };
        std::vector<std::string> results;
        for (auto& word : words) {
            if (std::any_of(keys.begin(), keys.end(),
                            [&word, &fit](const std::set<char>& key) {
                                return fit(key, word);
                            })) {
                results.push_back(word);
            }
        }
        return results;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> t1{"Hello", "Alaska", "Dad", "Peace"};
    std::cout << sol.findWords(t1) << std::endl;
    return 0;
}
