#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto kit = points.begin();
        advance(kit, K);
        vector<vector<int>> ret(points.begin(), kit);

        vector<int> vals;
        for (auto& v : ret) {
            vals.push_back(v[0] * v[0] + v[1] * v[1]);
        }

        int max_val = vals[0];
        size_t max_index = 0;
        auto refresh = [&vals, &max_val, &max_index]() {
            max_val = vals[0];
            max_index = 0;
            for (size_t i = 1; i < vals.size(); i++) {
                if (max_val < vals[i]) {
                    max_val = vals[i];
                    max_index = i;
                }
            }
        };
        refresh();

        for (; kit != points.end(); ++kit) {
            auto& p = *kit;
            auto val = p[0] * p[0] + p[1] * p[1];
            if (val < max_val) {
                vals[max_index] = val;
                ret[max_index] = p;
                refresh();
            }
        }

        return ret;
    }
};

int main() {
    ostream_iterator<int> out(cout, " ");
    vector p1{1, 3};
    vector p2{-2, 2};

    vector p3{3, 3};
    vector p4{5, -1};
    vector p5{-2, 4};

    vector points1{p1, p2};
    vector points2{p3, p4, p5};

    Solution sol;
    auto r1 = sol.kClosest(points1, 1);
    for (auto& v : r1) {
        std::copy(v.begin(), v.end(), out);
        cout << endl;
    }
    auto r2 = sol.kClosest(points2, 2);
    for (auto& v : r2) {
        std::copy(v.begin(), v.end(), out);
        cout << endl;
    }
    return 0;
}
