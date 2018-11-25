#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

class Solution {
public:
    std::string toLowerCase(std::string str) {
        for(auto& c : str) {
            c = static_cast<char>(std::tolower(c));
        }
        return str;
    }
};

int main() {
    Solution sol;
    if (sol.toLowerCase("Hello") != "hello") {
        assert(false);
    }
    if (sol.toLowerCase("here") != "here") {
        assert(false);
    }
    if (sol.toLowerCase("LOVE") != "love") {
        assert(false);
    }
    return 0;
}
