#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        constexpr int min__ = -50, max__ = 50;
        constexpr int bias = -min__, max_ = max__ + bias/*, min_ = 0*/;
        typedef int arr[max_ + 1];
        arr bucket = {0}, sum = {0};
        for (const auto& x : nums) ++bucket[x + bias];
        sum[0] = bucket[0];
        for (int i = 1; i <= max_; ++i) sum[i] = bucket[i] + sum[i - 1];
        // for (int i = 0; i <= max_; ++i) cout << "i="<<i<<',' << sum[i] << endl;
        int ans = 0;
        for (const auto& x : nums)
            if (target - x - 1 + bias >= 0) [[likely]]
                ans += sum[min(max_, target - x - 1 + bias)];
        return (ans - sum[(target + (bias << 1) - 1) >> 1]) >> 1;
    }
};