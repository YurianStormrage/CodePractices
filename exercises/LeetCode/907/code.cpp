#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        constexpr int mod = 1e9 + 7;
        int n = arr.size();
        pair<int, int> st[n + 1];
        int top = -1, ans = 0, now = 0;
        st[++top] = {0, -1};
        for(int i = 0; i < n; ++i) {
            while (top && arr[i] < st[top].first) { // 若用<=会导致重复计算
                now -= st[top].first * (st[top].second - st[top - 1].second);
                --top;
            }
            now += arr[i] * (i - st[top].second);
            if (now > mod) now -= mod;
            ans += now;
            if (ans > mod) ans -= mod;
            st[++top] = {arr[i], i};
        }
        return ans;
    }
};

int main() {
    struct Test : Solution {
        vector<int> arr;
        void run() {
            auto ans = sumSubarrayMins(arr);
            cout << ans << endl;
            // for_each(ans.begin(), ans.end(),
            //          [](decltype(ans)::value_type const& x) {
            //             cout << x << ' ';
            //          });
            // cout << endl;
        }
    };

    Test t1 {
        .arr = {3,1,2,4},
    };
    Test t2 {
        .arr = {11,81,94,43,3},
    };

    t1.run();
    t2.run();
    
    return 0;
}