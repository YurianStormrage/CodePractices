#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int n = nums.size();
        if (k >= n) k = n - 1;
        vector<int> f(n);
        multiset<int> s;
        f[0] = nums[0];
        s.emplace(f[0]);
        for (int i = 1; i <= k; ++i) {
            // printf("nums[%d] = %d\n", i, nums[i]);
            f[i] = nums[i] + *s.rbegin();
            // printf("f[%d] = %d\n", i, f[i]);
            s.emplace(f[i]);
            // cout << "end = " << *s.rbegin() << endl;
        }
        for (int i = k + 1; i < n; ++i) {
            s.erase(s.find(f[i - k - 1]));
            f[i] = nums[i] + *s.rbegin();
            s.emplace(f[i]);
            // cout << "end = " << *s.rbegin() << endl;
        }
        // for (auto const& val : f) {
        //     printf("%d ", val);
        // }
        return f[n - 1];
    }
};

int main() {
    struct Test : Solution {
        vector<int> nums;
        int k;
        void run() {
            auto ans = maxResult(nums, k);
            cout << ans << endl;
        }
    };

    Test t1 {
        .nums = {1,-1,-2,4,-7,3},
        .k = 2
    };
    Test t2 {
        .nums = {10,-5,-2,4,0,3},
        .k = 3
    };
    Test t3 {
        .nums = {1,-5,-20,4,-1,3,-6,-3},
        .k = 2
    };

    t1.run();
    t2.run();
    t3.run();

    return 0;
}