#include <iostream>
#include <filesystem>
#include <regex>
#include <fstream>
#include <system_error>
#include <limits>
#include <time.h>
#include <iterator>
#include <set>

void process_file(std::filesystem::path file, std::ofstream& out, std::regex& re) {
	std::cout << "file: " << file << std::endl;
	out << "file: " << file << std::endl;
	std::ifstream in(file);
	std::string line;
	while (std::getline(in, line)) {
		auto str_begin = std::sregex_token_iterator(line.begin(), line.end(), re, 1);
		auto str_end = std::sregex_token_iterator();
		for (auto i = str_begin; i != str_end; ++i) {
			out << i->str() << std::endl;
			std::cout << i->str() << std::endl;
		}
	}
	in.close();
}

void findStr() {
	std::regex re{ R"d(fmt.Errorf\("(.+)")d" };
	std::ofstream out("str.txt");
	for (auto entry : std::filesystem::recursive_directory_iterator(std::filesystem::path("G:/devsrc/little_games/server_go/src/ateam/room"))) {
		auto path = entry.path();
		if (std::filesystem::is_regular_file(path) && path.extension() == ".go") {
			process_file(path, out, re);
		}
	}
	out.close();
}

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

int main(int argc, const char* argv[])
{
  std::vector<std::string> emails{"test.email+alex@leetcode.com",
                                  "test.e.mail+bob.cathy@leetcode.com",
                                  "testemail+david@lee.tcode.com"};
  Solution sol;
  std::cout << sol.numUniqueEmails(emails) << std::endl;
    std::cin.get();
    return 0;
}