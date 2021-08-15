#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& A) {
        std::for_each(A.begin(), A.end(), [](int& a) { a = a * a; });
        std::sort(A.begin(), A.end());
        return A;
    }
};

int main() {
    std::ostream_iterator<int> os(std::cout, " ");
    std::vector<int> A{-4, -1, 0, 3, 10};
    Solution sol;
    A = sol.sortedSquares(A);
    std::copy(A.begin(), A.end(), os);
    return 0;
}
