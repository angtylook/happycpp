#include <string>
#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> vs;
        for (int i = 1; i <= n; ++i) {
            bool multi3 = i % 3 == 0;
            bool multi5 = i % 5 == 0;
            if (multi3 && multi5) {
                vs.push_back("FizzBuzz");
                continue;
            }
            if (multi3) {
                vs.push_back("Fizz");
                continue;
            }
            if (multi5) {
                vs.push_back("Buzz");
                continue;
            }
            vs.push_back(std::to_string(i));
        }
        return vs;
    }
};

int main() {
    Solution sol;
    std::cout << sol.fizzBuzz(15) << std::endl;
    return 0;
}
