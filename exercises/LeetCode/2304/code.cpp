#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int N = 50, M = 50;
    typedef array<array<int, N>, M> matrix;
    matrix f;
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < n; ++i) f[0][i] = grid[0][i];
        for (int i = 1; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int tmp = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    tmp = min(tmp, f[i - 1][k] +
                                   moveCost[grid[i - 1][k]][j]);
                }
                f[i][j] = grid[i][j] + tmp;
            }
        int ans = f[m - 1][0];
        for (int j = 1; j < n; ++j)
            ans = min(ans, f[m - 1][j]);
        return ans;
    }
};

int main()
{
    struct Test : Solution {
        vector<vector<int>> grid, moveCost;
        void run() {
            auto ans = minPathCost(grid, moveCost);
            cout << ans << endl;
            // for_each(ans.begin(), ans.end(),
            //          [](decltype(ans)::value_type const& x) {
            //             cout << x << ' ';
            //          });
            // cout << endl;
        }
    };

    Test t1 {
        .grid = {{5,3},{4,0},{2,1}},
        .moveCost = {{9,8},{1,5},{10,12},{18,6},{2,4},{14,3}}
        // 17
    };
    Test t2 {
        .grid = {{5,1,2},{4,0,3}},
        .moveCost = {{12,10,15},{20,23,8},{21,7,1},{8,1,13},{9,10,25},{5,3,2}}
        // 6
    };

    t1.run();
    t2.run();
    
    return 0;
}