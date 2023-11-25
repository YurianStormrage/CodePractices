#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        constexpr int N = 50;
        unordered_map<int, int> bucket, sum;
        bucket.reserve(N * 3);
        sum.reserve(N * 3);
        int min_ = nums.front();
        for (auto x : nums) {
            ++bucket[x];
            min_ = min(min_, x);
        }
        int max_ = target - min_;
        for (int i = min_; i <= max_; ++i) sum[i] = bucket[i] + sum[i - 1];
        // for (int i = min_; i <= max_; ++i) cout << "i="<<i<<',' << sum[i] << endl;
        int ans = 0;
        for (auto x : nums) ans += sum[target - x - 1];
        return (ans - sum[(target - 1) >> 1]) >> 1;
    }
};

int main() {
    struct Test : Solution {
        vector<int> nums;
        int target;
        void run() {
            auto ans = countPairs(nums, target);
            cout << ans << endl;
        }
    };

    Test t1{
        .nums = {-1,1,2,3,1},
        .target = 2
        // 3
    };
    Test t2{
        .nums = {-6,2,5,-2,-7,-1,3},
        .target = -2
        // 10
    };

    t1.run();
    t2.run();

    Test e1 {
        .nums = {9,-5,-5,5,-5,-4,-6,6,-6},
        .target = 3
        // error: 23
        // right: 27
        // 减去自重复的数量时不能减backet[x]，直接减 1 即可
    };
    Test e2 {
        .nums = {6,-1,7,4,2,3},
        .target = 8
        // error: 5
        // right: 8
        // 前缀和应该统计到 target-min，而不是 max
    };

    e1.run();
    e2.run();

    return 0;
}