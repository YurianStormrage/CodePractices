#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans = 0;
        // int a = -1;
        // for (auto x : nums) {
        //     if (~a) [[likely]] {
        //         if (a != x) [[unlikely]]
        //             a = -1;
        //         else ++ans;
        //     }
        //     else a = x;
        // }
        // return ans + (a != -1);

        /* This version is slightly faster */
        for (int i = 0, lim = nums.size() - 1; i < lim;) {
            if (nums[i] != nums[i + 1])
                i += 2;
            else {
                ++i;
                ++ans;
            }
        }
        return ans + ((nums.size() - ans) & 1);
    }
};

int main()
{
    struct Test : Solution {
        vector<int> nums;
        void run() {
            auto ans = minDeletion(nums);
            cout << ans << endl;
        }
    };
    
    Test t1 {
        .nums = {1,1,2,3,5}
        // 1
    };
    Test t2 {
        .nums = {1,1,2,2,3,3}
        // 2
    };

    t1.run();
    t2.run();
    
    return 0;
}