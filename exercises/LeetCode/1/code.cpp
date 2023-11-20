#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, int> exists;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        exists.reserve(nums.size());
        int i = 0;
        for (auto x : nums) exists.insert_or_assign(x, i++);
        i = 0;
        for (auto x : nums) {
            if (exists.contains(target - x) &&
                i != exists[target - x]) [[unlikely]]
                return {i, exists[target - x]};
            ++i;
        }
        return {-1, -1};
    }
};

int main()
{
    struct Test : Solution {
        vector<int> nums;
        int target;
        void run() {
            auto ans = twoSum(nums, target);
            // cout << ans << endl;
            for_each(ans.begin(), ans.end(),
                     [](decltype(ans)::value_type const& x) {
                        cout << x << ' ';
                     });
            cout << endl;
        }
    };

    Test t1 {
        .nums = {2,7,11,15},
        .target = 9
        // 0 1
    };
    Test t2 {
        .nums = {3,2,4},
        .target = 6
        // 1 2
    };
    Test t3 {
        .nums = {3,3},
        .target = 6
        // 0 1
    };

    t1.run();
    t2.run();
    t3.run();
    
    return 0;
}