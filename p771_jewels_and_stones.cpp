#include <string>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int numJewelsInStones(std::string J, std::string S) {
        int total = 0;
        for(auto c : J) {
            total += std::count(S.begin(), S.end(), c);
        }
        return total;
    }
};

int main() {
    Solution solution;
    assert(solution.numJewelsInStones("aA", "aAAbbbb") == 3);
    assert(solution.numJewelsInStones("z", "ZZ") == 0);
    return 0;
}