#include <vector>

class Solution {
public:
    int numRookCaptures(std::vector<std::vector<char>>& board) {
        auto sz = board.size();
        int rx, ry;
        // find rock
        for (size_t y = 0; y < sz; y++) {
            for (size_t x = 0; x < sz; x++) {
                if (board[y][x] == 'R') {
                    rx = x;
                    ry = y;
                }
            }
        }
        int counts = 0;
        // left
        for (int x = rx - 1; x >= 0; x--) {
            auto c = board[ry][x];
            if (c == '.') {
                continue;
            }
            if (c == 'B') {
                break;
            }
            if (c == 'p') {
                counts++;
                break;
            }
        }
        // right
        for (int x = rx + 1; x < sz; x++) {
            auto c = board[ry][x];
            if (c == '.') {
                continue;
            }
            if (c == 'B') {
                break;
            }
            if (c == 'p') {
                counts++;
                break;
            }
        }
        // up
        for (int y = ry - 1; y >= 0; y--) {
            auto c = board[y][rx];
            if (c == '.') {
                continue;
            }
            if (c == 'B') {
                break;
            }
            if (c == 'p') {
                counts++;
                break;
            }
        }
        // down
        for (int y = ry + 1; y < sz; y++) {
            auto c = board[y][rx];
            if (c == '.') {
                continue;
            }
            if (c == 'B') {
                break;
            }
            if (c == 'p') {
                counts++;
                break;
            }
        }
        return counts;
    }
};

int main() {
    return 0;
}
