#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> diStringMatch(std::string S) {
        std::vector<int> vi;
        int v{0};
        int j{0};
        size_t i = 0;
        while (i < S.size()) {
            if (S[i] == 'I') {
                if (j != -1) {
                    vi.push_back(v - j);
                    j = -1;
                } else {
                    vi.push_back(v);
                }
                v++;
                i++;
                if (i == S.size()) {
                    vi.push_back(v);
                }
                continue;
            }

            int count{0};
            while (S[i] == 'D') {
                count++;
                v++;
                i++;
            }
            j = 0;
            while (count > 0) {
                vi.push_back(v - j);
                j++;
                count--;
            }
            if (i == S.size()) {
                vi.push_back(v - j);
            }
        }
        return vi;
    }
};

int main() {
    std::ostream_iterator<int> out(std::cout, " ");
    Solution sol;
    auto vi = sol.diStringMatch("IDID");
    std::copy(vi.begin(), vi.end(), out);
    std::cout << std::endl;

    vi = sol.diStringMatch("III");
    std::copy(vi.begin(), vi.end(), out);
    std::cout << std::endl;

    vi = sol.diStringMatch("DDI");
    std::copy(vi.begin(), vi.end(), out);
    std::cout << std::endl;

    vi = sol.diStringMatch("DDD");
    std::copy(vi.begin(), vi.end(), out);
    std::cout << std::endl;
    return 0;
}
