#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int calPoints(std::vector<std::string>& ops) {
        int sum = 0;
        std::vector<int> roundPoints;
        for (auto& op : ops) {
            if (op == "C") {
                if (!roundPoints.empty()) {
                    sum -= roundPoints.back();
                    roundPoints.pop_back();
                }
                continue;
            }
            if (op == "D") {
                if (!roundPoints.empty()) {
                    roundPoints.push_back(roundPoints.back() * 2);
                    sum += roundPoints.back();
                }
                continue;
            }
            if (op == "+") {
                auto sz = roundPoints.size();
                if (sz == 1) {
                    roundPoints.push_back(roundPoints.back());
                    sum += roundPoints.back();
                } else if (sz >= 2) {
                    auto p = roundPoints[sz - 1] + roundPoints[sz - 2];
                    roundPoints.push_back(p);
                    sum += p;
                }
                continue;
            }
            roundPoints.push_back(std::stoi(op));
            sum += roundPoints.back();
        }

        return sum;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> t1{"5", "2", "C", "D", "+"};
    std::vector<std::string> t2{"5", "-2", "4", "C", "D", "9", "+", "+"};
    std::cout << sol.calPoints(t1) << std::endl;
    std::cout << sol.calPoints(t2) << std::endl;
    return 0;
}
