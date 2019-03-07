#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) {
        auto k = logs.rbegin();
        for (auto it = logs.rbegin(); it != logs.rend(); ++it) {
            std::string_view sv(*it);
            auto index = sv.find_first_of(' ');
            if (std::isdigit(sv[index + 1])) {
                std::swap(*it, *k);
                ++k;
            }
        }
        std::sort(k, logs.rend(),
                  [](const std::string& l, const std::string& r) -> bool {
                      std::string_view lv(l);
                      lv = lv.substr(lv.find_first_of(' ') + 1);

                      std::string_view rv(r);
                      rv = rv.substr(rv.find_first_of(' ') + 1);

                      return lv > rv;
                  });
        return logs;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> t1{"a1 9 2 3 1", "g1 act car", "zo4 4 7",
                                "ab1 off key dog", "a8 act zoo"};
    std::cout << sol.reorderLogFiles(t1) << std::endl;
    return 0;
}
