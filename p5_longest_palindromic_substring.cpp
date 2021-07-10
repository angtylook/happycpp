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
        auto p = longestPalindrome(v);
        return std::string(p);
    }

    std::string longestPalindrome2(std::string s) {
        std::string_view v(s);
        std::string_view ret(v.substr(0, 1));
        auto vz = v.size();
        for (size_t i = 1; i < vz; i++) {
            auto sz = ret.size();
            auto test_v = v.substr(i - sz, sz + 1);
            if (isPalindrome(test_v)) {
                ret = test_v;
            }

            if (i - sz >= 1) {
                auto test_v = v.substr(i - sz - 1, sz + 2);
                if (isPalindrome(test_v)) {
                    ret = test_v;
                }
            }
        }
        return std::string(ret);
    }

    std::string_view longestPalindrome(std::string_view v) {
        auto iter = cache_.find(v);
        if (iter != cache_.end()) {
            return iter->second;
        }

        m[v]++;
        if (isPalindrome(v)) {
            cache_[v] = v;
            return v;
        }

        std::string_view left;
        auto lv = v.substr(0, v.size() - 1);
        iter = cache_.find(lv);
        if (iter == cache_.end()) {
            left = longestPalindrome(lv);
            cache_[lv] = left;
        } else {
            left = iter->second;
        }

        std::string_view right;
        auto rv = v.substr(1, v.size());
        iter = cache_.find(rv);
        if (iter == cache_.end()) {
            right = longestPalindrome(rv);
            cache_[rv] = right;
        } else {
            right = iter->second;
        }

        std::string_view ret = left;
        if (left.size() < right.size()) {
            ret = right;
        }

        cache_[v] = ret;
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
            if (n > 1) {
                std::cout << v << ":" << n << std::endl;
            }
        }
    }

private:
    std::map<std::string_view, int> m;
    std::map<std::string_view, std::string_view> cache_;
};

int main() {
    Solution sol;
    std::cout << sol.longestPalindrome2(std::string("babad")) << std::endl;
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
    std::cout << "===qahaq==========" << std::endl;
    sol.stat();
    std::cout
        << sol.longestPalindrome2(
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

    return 0;
}
