#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sumEvenAfterQueries(
        std::vector<int>& A,
        std::vector<std::vector<int>>& queries) {
        std::vector<int> result;
        int sumOfEven = 0;
        for (auto& n : A) {
            if (n % 2 == 0) {
                sumOfEven += n;
            }
        }

        for (auto& query : queries) {
            auto val = query[0];
            auto idx = query[1];
            if (A[idx] % 2 == 0) {
                sumOfEven -= A[idx];
            }
            A[idx] += val;
            if (A[idx] % 2 == 0) {
                sumOfEven += A[idx];
            }
            result.push_back(sumOfEven);
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector A{1, 2, 3, 4};
    std::vector<std::vector<int>> querys{{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
    auto result = sol.sumEvenAfterQueries(A, querys);
    std::ostream_iterator<int> out(std::cout, " ");
    std::copy(result.begin(), result.end(), out);
    return 0;
}
