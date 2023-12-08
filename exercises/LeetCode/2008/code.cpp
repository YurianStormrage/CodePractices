#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // sort(rides.begin(), rides.end(), [](const auto& a, const auto& b) {
        //     return a[1] < b[1];
        // });
        vector<vector<decltype(rides.begin())>> list(n + 1);
        for (auto i = rides.begin(); i != rides.end(); ++i)
            list[(*i)[1]].emplace_back(i);
        long long f[n + 1];
        // memset(f, 0, sizeof(f));
        f[0] = 0;
        // auto it = rides.begin();
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1];
            // while (it != rides.end() && (*it)[1] == i) {
            for (auto& it : list[i])
                f[i] = max(f[i], f[(*it)[0]] + (*it)[1] - (*it)[0] + (*it)[2]);
            //     ++it;
            // }
        }
        return f[n];
    }
};

int main() {
    struct Test : Solution {
        int n;
        vector<vector<int>> rides;
        void run() {
            auto ans = maxTaxiEarnings(n, rides);
            cout << ans << endl;
        }
    };

    Test t1 {
        .n = 5,
        .rides = {{2,5,4},{1,5,1}},
    };
    Test t2 {
        .n = 20,
        .rides = {{1,6,1},{3,10,2},{10,12,3},{11,12,2},{12,15,2},{13,18,1}},
    };

    t1.run();
    t2.run();

    return 0;
}