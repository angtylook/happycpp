#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<int> shortestToChar(std::string S, char C) {
        std::vector<int> result(S.size(), 0);
        size_t p = 0;
        for (size_t i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                result[i] = 0;
                for (size_t j = i; j > p; j--) {
                    int d = static_cast<int>(i - j + 1);
                    if (d < result[j - 1]) {
                        result[j - 1] = d;
                    } else {
                        break;
                    }
                }
                p = i;
            } else {
                if (i == 0) {
                    result[i] = int(S.size());
                } else {
                    result[i] = result[i - 1] + 1;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::cout << sol.shortestToChar("loveleetcode", 'e') << std::endl;
    return 0;
}
