#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(
        std::vector<std::vector<int>>& A) {
        for (auto& v : A) {
            std::reverse(v.begin(), v.end());
            std::for_each(v.begin(), v.end(), [](int& e) { e ^= 1; });
        }
        return A;
    }
};

int main() {
    std::vector<int> v{1, 0};
    std::for_each(v.begin(), v.end(), [](int& e) { e ^= 1; });
    std::for_each(v.begin(), v.end(), [](int e) { std::cout << e << " "; });
    return 0;
}
