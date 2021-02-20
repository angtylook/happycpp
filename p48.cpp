#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include "base/util.h"

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        for (size_t r = 0; r < matrix.size()/2; r++) {
            size_t len = matrix.size() - r-1;
            for (size_t c = r; c < matrix.size() - r-1; c++) {
                int temp = matrix[c][len];
                matrix[c][len] = matrix[r][c];
                std::swap(temp, matrix[len][len-(c-r)]);
                std::swap(temp, matrix[len-(c-r)][r]);
                std::swap(temp, matrix[r][c]);
            }
        }
    }
};

int main(int argc, const char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> matrix;
    const int n = 2;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        int c = n;
        std::vector<int> row;
        while (c > 0) {
            row.push_back(cnt++);
            c--;
        }
        matrix.push_back(row);
    }
    solution.rotate(matrix);
    for (auto& v : matrix) {
        std::cout << v << std::endl;
    }
    return 0;
}
