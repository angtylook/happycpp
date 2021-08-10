#include <vector>
#include <iostream>

#include "base/util.h"

/*
* Given a non negative integer number num.
* For every numbers i in the range 0 ¡Ü i ¡Ü num
* calculate the number of 1's in their binary representation
* and return them as an array.
*/
class Solution {
public:
    std::vector<int> countBits(int num) {
        std::vector<int> result;
        result.reserve(size_t(num) + 1);
        result.push_back(0);
        int next2power = 2;
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 1) {
                result.push_back(result.back() + 1);
            } else {
                if (i == next2power) {
                    result.push_back(1);
                    next2power *= 2;
                } else {
                    int remain = i - next2power / 2;
                    result.push_back(result[remain]+1);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    for (int i = 0; i <= 16; i++) {
        std::cout << sol.countBits(i) << std::endl;
    }
    std::cout << sol.countBits(64) << std::endl;
    return 0;
}

