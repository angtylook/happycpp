#include <iostream>
#include <string>

std::string findp(std::string s) {
    std::string p(s.substr(0, 1));
    size_t m = 0;
    for(size_t i = 1; i < s.size(); i++) {
        if(s[i] == s[m]) {
            size_t n = i - m + 1;
            if(n > p.size()) {
                p = s.substr(m, n);
            }
        } else {
            s.empty();
        }
    }
    return p;
}

int main() {
    return 0;
}
