#include <iostream>
#include <vector>
#include "base/util.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> matrix;
        for (int i = 0; i < m; i++) {
            matrix.emplace_back(n);
        }
        for (int r = 0; r < m; r++) {
            matrix[r][0] = 1;
        }
        for (int c = 0; c < n; c++) {
            matrix[0][c] = 1;
        }
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                matrix[r][c] = matrix[r - 1][c] + matrix[r][c - 1];
            }
        }
        return matrix[m-1][n-1];
    }
};

int main() {
    Solution sol;
    std::cout << sol.uniquePaths(3, 7) << std::endl;
    std::cout << sol.uniquePaths(3, 2) << std::endl;
    std::cout << sol.uniquePaths(7, 3) << std::endl;
    std::cout << sol.uniquePaths(3, 3) << std::endl;
    return 0;
}