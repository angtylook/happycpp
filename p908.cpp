#include <iostream>
#include <vector>

class Solution {
public:
    int smallestRangeI(std::vector<int>& A, int K) {
        int smallest = A.front();
        int biggest = A.front();
        for (auto a : A) {
            if (smallest > a) {
                smallest = a;
            }
            if (biggest < a) {
                biggest = a;
            }
        }
        smallest += K;
        biggest -= K;
        if (biggest > smallest) {
            return biggest - smallest;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    std::vector t1{1};
    std::vector t2{0, 10};
    std::vector t3{1, 3, 6};

    std::cout << sol.smallestRangeI(t1, 0) << std::endl;
    std::cout << sol.smallestRangeI(t2, 2) << std::endl;
    std::cout << sol.smallestRangeI(t3, 3) << std::endl;
    return 0;
}
