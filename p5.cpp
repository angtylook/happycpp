#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <utility>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        m.clear();

        cache_.clear();
        std::string_view v(s);
        auto p = longestPalindrome(v, 0, v.size());
        return std::string(p);
    }

    std::string_view longestPalindrome(std::string_view v,
                                       size_t first,
                                       size_t last) {
        std::pair rng{first, last};
        auto iter = cache_.find(rng);
        if (iter != cache_.end()) {
            return iter->second;
        }

        auto test_v = v.substr(first, last);
        m[test_v]++;
        if (isPalindrome(test_v)) {
            cache_[rng] = test_v;
            return test_v;
        }

        std::pair lrng{first, last - 1};
        std::string_view left;
        iter = cache_.find(lrng);
        if (iter == cache_.end()) {
            left = longestPalindrome(v, first, last - 1);
            cache_[lrng] = left;
        } else {
            left = iter->second;
        }

        std::pair rrng{first + 1, last};
        std::string_view right;
        iter = cache_.find(rrng);
        if (iter == cache_.end()) {
            right = longestPalindrome(v, first + 1, last);
            cache_[rrng] = right;
        } else {
            right = iter->second;
        }

        std::string_view ret = left;
        if (left.size() < right.size()) {
            ret = right;
        }

        cache_[rng] = right;
        return ret;
    }

    bool isPalindrome(std::string_view s) {
        size_t n = s.size();
        size_t m = n / 2;
        for (size_t i = 0; i < m; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

    void stat() {
        for (auto [v, n] : m) {
            std::cout << v << ":" << n << std::endl;
        }
    }

private:
    std::map<std::string_view, int> m;
    std::map<std::pair<int, int>, std::string_view> cache_;
};

int main() {
    Solution sol;
    std::cout << sol.longestPalindrome(std::string("babad")) << std::endl;
    std::cout << "=============" << std::endl;
    sol.stat();
    std::cout
        << sol.longestPalindrome(
               // std::string("babaddtattarrattatddetartrateedredividerb"))
               std::string(
                   "kyyrjtdplseovzwjkykrjwhxquwxsfsorjiumvxjhjmgeueafubtonhlerr"
                   "gsgohfosqssmizcuqryqomsipovhhodpfyudtusjhonlqabhxfahfcjqxyc"
                   "kycstcqwxvicwkjeuboerkmjshfgiglceycmycadpnvoeaurqatesivajoq"
                   "dilynbcihnidbizwkuaoegmytopzdmvvoewvhebqzskseeubnretjgnmyjw"
                   "wgcooytfojeuzcuyhsznbcaiqpwcyusyyywqmmvqzvvceylnuwcbxybhqpv"
                   "jumzomnabrjgcfaabqmiotlfojnyuolostmtacbwmwlqdfkbfikusuqtupd"
                   "wdrjwqmuudbcvtpieiwteqbeyfyqejglmxofdjksqmzeugwvuniaxdrunyu"
                   "nnqpbnfbgqemvamaxuhjbyzqmhalrprhnindrkbopwbwsjeqrmyqipnqvjq"
                   "zpjalqyfvaavyhytetllzupxjwozdfpmjhjlrnitnjgapzrakcqahaqetwl"
                   "laaiadalmxgvpawqpgecojxfvcgxsbrldktufdrogkogbltcezflyctklpq"
                   "rjymqzyzmtlssnavzcquytcskcnjzzrytsvawkavzboncxlhqfiofuoheha"
                   "ygxidxsofhmhzygklliovnwqbwwiiyarxtoihvjkdrzqsnmhdtdlpckuayh"
                   "tfyirnhkrhbrwkdymjrjklonyggqnxhfvtkqxoicakzsxmgczpwhpkzcntk"
                   "cwhkdkxvfnjbvjjoumczjyvdgkfukfuldolqnauvoyhoheoqvpwoisniv"))
        << std::endl;
    std::cout << "=============" << std::endl;
    sol.stat();
    return 0;
}
