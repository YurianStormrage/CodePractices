#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        const int n = nums.size();
        // 2nums[i] <= nums[j]
        // binary search
        multiset<int> val;
        for (auto& v : nums) {
            val.emplace(v);
        }
        int ans = 0;
        auto it = prev(val.end());
        while (true) {
            auto x = *it;
            // cout << "x = " << x << endl;
            auto y = ranges::lower_bound(val, x << 1);
            if (y != val.end()) {
                ans += 2;
                val.erase(y);
                if (it != val.begin()) {
                    auto pre = prev(it);
                    val.erase(it);
                    it = pre;
                } else {
                    break;
                }
            } else if (it != val.begin()) {
                it = prev(it);
            } else {
                break;
            }
        }
        return ans;
    }
};
