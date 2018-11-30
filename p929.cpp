#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

class Solution {
 public:
  std::string transform(std::string& email) {
    auto at = email.find_first_of('@');
    auto host = email.substr(at);
    auto name = email.substr(0, at);
    name = name.substr(0, name.find_first_of('+'));
    auto it = std::remove(name.begin(), name.end(), '.');
    name.erase(it, name.end());
    name.append(host);
    return name;
  }

  int numUniqueEmails(std::vector<std::string>& emails) {
      std::set<std::string> s;
    for (auto& email : emails) {
        s.insert(transform(email));
    }
    return int(s.size());
  }
};

int main()
{
  std::vector<std::string> emails{"test.email+alex@leetcode.com",
                                  "test.e.mail+bob.cathy@leetcode.com",
                                  "testemail+david@lee.tcode.com"};
  Solution sol;
  std::cout << sol.numUniqueEmails(emails) << std::endl;
    std::cin.get();
    return 0;
}
