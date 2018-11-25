#include <cassert>
#include <string>

class Solution {
public:
    bool judgeCircle(std::string moves) {
        int x = 0;
        int y = 0;
        for (auto m : moves) {
            switch (m) {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
            }
        }
        return x == 0 && y == 0;
    }
};

int main() {
    Solution sol;
    assert(sol.judgeCircle("UD"));
    assert(!sol.judgeCircle("LL"));
}
