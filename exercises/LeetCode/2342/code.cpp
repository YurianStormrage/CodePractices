#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        if (nums.size() < 2) [[unlikely]] {
            return -1;
        }
        using pii = pair<int, int>;
        vector<pii> arr(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            arr[i].second = nums[i];
            auto& x = nums[i];
            auto& y = arr[i].first;
            while(x) {
                y += x % 10;
                x /= 10;
            }
        }
        sort(arr.begin(), arr.end());
        int ans = -1;
        bool flag = 0;
        for (int i = arr.size() - 2; i >= 0; --i) {
            // printf("arr[%d] = (%d, %d)\n", i, arr[i].first, arr[i].second);
            if (arr[i].first != arr[i + 1].first) [[unlikely]] {
                flag = 0;
                continue;
            }
            if (flag) [[likely]] continue;
            if (ans < arr[i].second + arr[i + 1].second) {
                ans = arr[i].second + arr[i + 1].second;
                // printf("update ans = %d\n", ans);
                flag = 1;
            }
        }
        return ans;
    }
};

int main()
{
    struct Test : Solution {
        vector<int> nums;
        Test(decltype(nums) _nums) : nums(_nums) { }
        void Solve() { cout << maximumSum(nums) << endl; }
    };
    Test t1 = Test(vector<int>{18, 43, 36, 13, 7});
    Test t2 = Test(vector<int>{10, 12, 19, 14});
    Test error1 = Test{vector<int>{368,369,307,304,384,138,90,279,35,396,114,328,251,364,300,191,438,467,183}};
    // t1.Solve();
    // t2.Solve();
    error1.Solve(); // 数位和最大 != 和最大
    return 0;
}