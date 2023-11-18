#include <bits/stdc++.h>
using namespace std;

class Solution {
    constexpr static int N = 2e4 + 2, MAX = 1 << 16;
    struct pii {
        int x, y;
        bool operator<(pii const& b) const noexcept {
            return x < b.x ? : x == b.x ? y > b.y : false;
        }
    };
    array<pii, N> f, g;
    array<int, N> sums;
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        sums[0] = nums[0];
        for (int i = 1, lim = n; i < lim; ++i)
            sums[i] = nums[i] + sums[i - 1];

        auto sum = [&](int a, int b) {
            if (!a) [[unlikely]] return sums[b];
            return sums[b] - sums[a - 1];
        };

        f[k - 1] = {sum(0, k - 1), 0};
        for (int i = k, lim = n; i < lim; ++i)
            f[i] = max(f[i - 1], {sum(i - k + 1, i), i - k + 1});

        g[n - k] = {sum(n - k, n - 1), n - k};
        for (int i = n - k - 1; i >= 0; --i)
            g[i] = max(g[i + 1], {sum(i, i + k - 1), i});

        int ans = 0, ret;
        // auto ret = tuple{0, 0, 0};
        for (int i = k, lim = n - (k << 1); i <= lim; ++i) {
            int tmp = f[i - 1].x + sum(i, i + k - 1) + g[i + k].x;
            if (ans < tmp) [[unlikely]] {
                ans = tmp;
                // ret = {f[i - 1].y, i, g[i + k].y};
                ret = i;
            }
        }

        return {f[ret - 1].y, ret, g[ret + k].y};
    }
};

int main()
{
    struct Test : Solution {
        vector<int> nums;
        int k;
        void Solve() {
            auto ans = maxSumOfThreeSubarrays(nums, k);
            for_each(ans.begin(), ans.end(), [](decltype(ans)::value_type& x){cout << x << endl;});
        }
    };
    
    Test t1 {
        .nums = vector<int>{1, 2, 1, 2, 6, 7, 5, 1},
        .k = 2
        //output = 0 3 5
    };
    Test t2 {
        .nums = vector<int>{1,2,1,2,1,2,1,2,1},
        .k = 2
        //output = 0 2 4
    };

    t1.Solve();
    t2.Solve();

    Test error1 {
        .nums = {4, 3, 2, 1},
        .k = 1
    };

    error1.Solve(); // 使用了f[-1]和g[nums.size()]越界
    
    return 0;
}