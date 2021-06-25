#include <iostream>
#include <vector>
#include <algorithm>

#include "base/util.h"

class Solution {
public:
    int numTrees(int n) {
        switch (n) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 5;
        }
        int total = 0;
        for (int i = 1; i <= n; i++) {
            total += std::max(1, numTrees(i-1)) * std::max(1, numTrees(n - i));
        }
        return total;
    }
};

int main() {
    Solution sol;
    for (int i = 1; i < 20; i++) {
        std::cout << i << " -> " << sol.numTrees(i) << std::endl;
    }
    return 0;
}
