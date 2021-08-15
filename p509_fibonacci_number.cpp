#include <iostream>

class Solution {
public:
    int fib(int N) {
        if (N == 0)
            return 0;
        if (N == 1) {
            return 1;
        }
        int f1 = 0;
        int f2 = 1;
        for (int i = 2; i <= N; i++) {
            auto f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }
};

int main() {
    Solution sol;
    for (int n = 0; n <= 30; n++) {
        std::cout << sol.fib(n) << " ";
    }
    return 0;
}