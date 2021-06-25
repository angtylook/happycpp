#include <iostream>
#include <vector>
#include <algorithm>

#include "base/util.h"

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int row = grid.size();
        int col = grid.back().size();

        std::vector<std::vector<int>> matrix;
        for (int i = 0; i < row; i++) {
            matrix.emplace_back(col);
        }
        matrix[0][0] = grid[0][0];
        for (int r = 1; r < row; r++) {
            matrix[r][0] = grid[r][0] + matrix[r-1][0];
        }
        for (int c = 1; c < col; c++) {
            matrix[0][c] = grid[0][c] + matrix[0][c-1];
        }
        for (int r = 1; r < row; r++) {
            for (int c = 1; c < col; c++) {
                matrix[r][c] = grid[r][c] + std::min(matrix[r - 1][c], matrix[r][c - 1]);
            }
        }
        return matrix[row - 1][col - 1];
    }
};

int main() {
    Solution sol;
    auto grid1 = std::vector<std::vector<int>> {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    std::cout << sol.minPathSum(grid1) << std::endl;
    auto grid2 = std::vector<std::vector<int>>{{1, 2, 3}, {4, 5, 6}};
    std::cout << sol.minPathSum(grid2) << std::endl;
    return 0;
}