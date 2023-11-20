#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums.front();
        int now = 0;
        for (auto x : nums) {
            now += x;
            ans = max(ans, now);
            if (now < 0) now = 0;
        }
        return ans;
    }
};

int main()
{
    struct Test : Solution {
        vector<int> nums;
        void Solve() {
            auto ans = maxSubArray(nums);
            cout << ans << endl;
        }
    };
    
    Test t1 {
        .nums = {-2,1,-3,4,-1,2,1,-5,4}
        // 6
    };
    Test t2 {
        .nums = {1}
        // 1
    };
    Test t3 {
        .nums = {5,4,-1,7,8}
        // 23
    };

    t1.Solve();
    t2.Solve();
    t3.Solve();
    
    return 0;
}