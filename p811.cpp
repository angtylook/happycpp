#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include "base/util.h"

class Solution {
public:
    std::vector<std::string> subdomainVisits(
        std::vector<std::string>& cpdomains) {
        std::unordered_map<std::string_view, int> counts;
        for (auto& domain : cpdomains) {
            std::string_view domain_sv(domain);
            auto space_iter = domain_sv.find_first_of(' ');
            auto number = domain_sv.substr(0, space_iter);
            auto count = std::stoi(std::string(number));
            while (space_iter < domain_sv.length()) {
                space_iter++;
                domain_sv = domain_sv.substr(space_iter);
                counts[domain_sv] += count;
                space_iter = domain_sv.find_first_of('.');
            }
        }
        std::vector<std::string> out;
        for (auto [v, c] : counts) {
            out.push_back(std::to_string(c) + " " + std::string(v));
        }
        return out;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> v1{"9001 discuss.leetcode.com"};
    std::vector<std::string> v2{"900 google.mail.com", "50 yahoo.com",
                                "1 intel.mail.com", "5 wiki.org"};
    std::cout << v1 << std::endl;
    std::cout << sol.subdomainVisits(v1) << std::endl;

    std::cout << v2 << std::endl;
    std::cout << sol.subdomainVisits(v2) << std::endl;
    return 0;
}
