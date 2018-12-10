#include <iostream>
#include <iterator>
#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParityII(std::vector<int>& A) {
        size_t i = 0;
        size_t j = 0;
        size_t r{};
        int temp{};
        size_t n = A.size();
        while (i < n) {
            r = i % 2;
            if (A[i] % 2 == r) {
                i++;
                continue;
            }
            j = i + 1;
            while (j < n && A[j] % 2 != r) {
                j++;
            }
            if (j >= n)
                break;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
            i++;
        }
        return A;
    }
};

int main() {
    Solution sol;
    std::ostream_iterator<int> out(std::cout, " ");
    std::vector<int> vi{4, 2, 5, 7};
    auto res = sol.sortArrayByParityII(vi);
    std::copy(vi.begin(), vi.end(), out);
    std::cout << std::endl;
    return 0;
}
