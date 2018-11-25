#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <array>
#include <set>

class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        std::set<std::string> sets;
        for(const auto& w : words) {
            sets.insert(convto(w));
        }
        return static_cast<int>(sets.size());
    }

    std::string convto(const std::string& from) {
        std::string s;
        for(auto c : from) {
            s.append(morses_[c-'a']);
        }
        return s;
    }
private:
    std::array<std::string, 26> morses_ {
        ".-","-...","-.-.","-..",".","..-.","--.",  // abcdefg
        "....","..",".---","-.-",".-..","--","-.",  // hijklmn
        "---",".--.","--.-",".-.","...","-",        // opqrst
        "..-","...-",".--","-..-","-.--","--.."     // uvwxyz
    };
};

int main() {
    Solution sol;
    std::vector<std::string> words {"gin", "zen", "gig", "msg"};
    assert(sol.uniqueMorseRepresentations(words) == 2);
}
