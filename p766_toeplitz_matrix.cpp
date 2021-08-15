#include <iostream>
#include <vector>

class Solution {
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();
        for (size_t i = 0; i < cols; i++) {
            int v = matrix[0][i];
            size_t c = i + 1;
            size_t r = 1;
            while (c < cols && r < rows) {
                if (matrix[r][c] != v) {
                    return false;
                }
                c++;
                r++;
            }
        }

        for (size_t i = 1; i < rows; i++) {
            int v = matrix[i][0];
            size_t r = i + 1;
            size_t c = 1;
            while (c < cols && r < rows) {
                if (matrix[r][c] != v) {
                    return false;
                }
                c++;
                r++;
            }
        }
        return true;
    }
};

int main() {
    std::vector r1{1, 2, 3, 4};
    std::vector r2{5, 1, 2, 3};
    std::vector r3{9, 5, 1, 2};
    std::vector m1{r1, r2, r3};

    std::vector r4{1, 2};
    std::vector r5{2, 2};
    std::vector m2{r4, r5};

    Solution sol;
    std::cout << sol.isToeplitzMatrix(m1) << std::endl;
    std::cout << sol.isToeplitzMatrix(m2) << std::endl;
    return 0;
}
