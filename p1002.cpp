#include <array>
#include <limits>
#include <string>
#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& A) {
        std::vector<std::string> result;
        std::array<std::vector<int>, 26> counts;
        auto sz = A.size();
        for (size_t i = 0; i < sz; i++) {
            for (auto c : A[i]) {
                auto& v = counts[c - 'a'];
                if (v.empty()) {
                    v.resize(sz);
                }
                v[i]++;
            }
        }
        for (size_t i = 0; i < 26; i++) {
            if (counts[i].empty()) {
                continue;
            }

            int min = std::numeric_limits<int>::max();
            for (auto c : counts[i]) {
                if (c < min) {
                    min = c;
                }
            }
            for (int n = 0; n < min; n++) {
                result.push_back(std::string(1, 'a' + i));
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> t1{"bella", "label", "roller"};
    std::vector<std::string> t2{"cool", "lock", "cook"};
    std::cout << sol.commonChars(t1) << std::endl;
    std::cout << sol.commonChars(t2) << std::endl;
    return 0;
}
