#include <string>
#include <cassert>

class Solution {
public:
    bool backspaceCompare(std::string S, std::string T) {
        int s_bs_count {0};
        int t_bs_count {0};
        char s_last {'#'};
        char t_last {'#'};
        auto s_iter = S.rbegin();
        auto s_end = S.rend();
        auto t_iter = T.rbegin();
        auto t_end = T.rend();
        while(s_iter != s_end || t_iter != t_end) {
            while(s_iter != s_end) {
                if (*s_iter == '#') {
                    s_bs_count++;
                    ++s_iter;
                    continue;
                }
                if (*s_iter != '#' && s_bs_count > 0) {
                    s_bs_count--;
                    ++s_iter;
                    continue;
                }
                s_last = *s_iter;
                ++s_iter;
                break;
            }

            while(t_iter != t_end) {
                if (*t_iter == '#') {
                    t_bs_count++;
                    ++t_iter;
                    continue;
                }
                if (*t_iter != '#' && t_bs_count > 0) {
                    t_bs_count--;
                    ++t_iter;
                    continue;
                }
                t_last = *t_iter;
                ++t_iter;
                break;
            }
            if(s_last != t_last) {
                return false;
            }
            s_last = '#';
            t_last = '#';
        }
        return s_last == t_last;
    }
};

int main() {
    Solution sol;
    assert(sol.backspaceCompare("ab#c", "ad#c") == true);
    assert(sol.backspaceCompare("ab##", "c#d#") == true);
    assert(sol.backspaceCompare("a##c", "#a#c") == true);
    assert(sol.backspaceCompare("a#c", "b") == false);
    return 0;
}
