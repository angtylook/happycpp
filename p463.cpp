#include <iostream>
#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        size_t Y = grid.size();
        size_t X = grid[0].size();
        int count = 0;
        for (size_t y = 0; y < Y; ++y) {
            for (size_t x = 0; x < X; ++x) {
                if (grid[y][x] == 0) {
                    continue;
                }
                if (y == 0 || grid[y - 1][x] == 0) {
                    count++;
                }
                if (y == Y - 1 || grid[y + 1][x] == 0) {
                    count++;
                }
                if (x == 0 || grid[y][x - 1] == 0) {
                    count++;
                }
                if (x == X - 1 || grid[y][x + 1] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    std::vector r1{0, 1, 0, 0};
    std::vector r2{1, 1, 1, 0};
    std::vector r3{0, 1, 0, 0};
    std::vector r4{1, 1, 0, 0};
    std::vector grid{r1, r2, r3, r4};
    Solution sol;
    std::cout << sol.islandPerimeter(grid) << std::endl;
    return 0;
}
