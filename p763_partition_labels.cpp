#include <iostream>
#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>

class Solution {
public:
    std::vector<int> partitionLabels(std::string S) {
        std::unordered_map<char, std::pair<int, int>> positions;
        int sz = static_cast<int>(S.size());
        for (int i = 0; i < sz; i++) {
            auto c = S[i];
            if (auto it = positions.find(c); it != positions.end()) {
                it->second.second = i;
            } else {
                positions.emplace(std::piecewise_construct,
                                  std::forward_as_tuple(c),
                                  std::forward_as_tuple(i, i));
            }
        }
        /*
        for (auto& [c, pos] : positions) {
            std::cout << "char " << c << " range [" << pos.first << ","
                      << pos.second << "]"
                      << std::endl;
        }*/
        std::vector<int> result;
        for (int i = 0; i < sz; i++) {
            auto first = i;
            auto last = i;
            const auto& pos = positions[S[i]];
            if (pos.second > last) {
                last = pos.second;
            }
            while (i != last) {
                i++;
                const auto& pos = positions[S[i]];
                if (pos.second > last) {
                    last = pos.second;
                }
            }
            result.push_back(last - first + 1);
        }
        return result; 
    }
};

int main() {
    Solution sol;
    auto res = sol.partitionLabels("ababcbacadefegdehijhklij");
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, ","));
    return 0;
}