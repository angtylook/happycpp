#include <vector>
#include <iostream>
#include <string>

class Solution {
public:
  int lengthOfLongestSubString(std::string s) {
    if(s.size() <= 1) {
      return static_cast<int>(s.size());
    }
    
    std::string longest = s.substr(0, 1);
    std::string temp = s.substr(0, 1);
    for(int i = 1; i < s.size(); ++i) {
      size_t index = temp.find(s[i]);
      if(index == std::string::npos) {
        temp.push_back(s[i]);
      } else {
        temp = temp.substr(index + 1);
        temp.push_back(s[i]);
      }
      if(temp.size() > longest.size()) {
        longest = temp;
      }
    }
    //std::cout << "longest sub string: " << longest << std::endl;
    return static_cast<int>(longest.size());
  }
  
  void test() {
    std::cout << "abcabcbb =>" << lengthOfLongestSubString("abcabcbb") << std::endl;
    std::cout << "bbbbb =>" << lengthOfLongestSubString("bbbbb") << std::endl;
    std::cout << "pwwkew =>" << lengthOfLongestSubString("pwwkew") << std::endl;
  }
  
};

int main(int argc, const char* argv[]) {
  Solution solution;
  solution.test();
  return 0;
}


