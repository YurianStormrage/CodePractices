#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int numi[n], numj[m];
        memset(numi, 0, sizeof(numi));
        memset(numj, 0, sizeof(numj));
        unordered_map<int, pair<int, int>> pos;
        for (auto const& row : mat) {
            for (auto const& x : row) {
                pos[x] = {&row - &mat[0], &x - &row[0]};
            }
        }
        for (auto const& x : arr) {
            auto [i, j] = pos[x];
            ++numi[i];
            ++numj[j];
            if (numi[i] == m || numj[j] == n) {
                return &x - &arr[0];
            }
        }
        return -1;
    }
};

int main() {
    struct Test : Solution {
        vector<int> arr;
        vector<vector<int>> mat;
        void run() {
            auto ans = firstCompleteIndex(arr, mat);
            cout << ans << endl;
            // for_each(ans.begin(), ans.end(),
            //          [](decltype(ans)::value_type const& x) {
            //             cout << x << ' ';
            //          });
            // cout << endl;
        }
    };

    Test t1 {
        .arr = {1,3,4,2},
        .mat = {{1,4},{2,3}}
    };
    Test t2 {
        .arr = {2,8,7,4,1,3,5,6,9},
        .mat = {{3,2,5},{1,4,6},{8,7,9}}
    };

    t1.run();
    t2.run();

    return 0;
}