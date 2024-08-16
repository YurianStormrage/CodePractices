#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        const int n = nums.size(), m = andValues.size();
        constexpr int inf = 0x3f3f3f3f;
        vector<vector<int>> f(n, vector<int>(m, inf));
        for (int i = 0; i < n; ++i) {
            int tmp = -1;
            for (int k = i; ~k; --k) {
                tmp &= nums[k];
                for (int j = 0; j < min(m, k + 1); ++j) {
                    if (tmp != andValues[j])
                        continue;
                    if (!j && !k) {
                        f[i][0] = nums[i];
                    } else if (j && k) {
                        f[i][j] = min(f[i][j], f[k - 1][j - 1] + nums[i]);
                    }
                    // printf("f[%d][%d] = %d\n", i, j, f[i][j]);
                }
            }
        }
        return f[n - 1][m - 1] >= inf ? -1 : f[n - 1][m - 1];
    }
};
