#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, ans = 0;
        for (auto v : nums) {
            if (v == 0) {
                ++cnt;
            } else {
                ans += (cnt * (cnt + 1)) >> 1;
                cnt = 0;
            }
        }
        ans += (cnt * (cnt + 1)) >> 1;
        return ans;
    }
};
