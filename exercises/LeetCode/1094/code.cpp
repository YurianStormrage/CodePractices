#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        constexpr int N = 1001;
        int num[N];
        memset(num, 0, sizeof(num));
        for (auto const& trip : trips) {
            auto [n, i, j] = tuple{trip[0], trip[1], trip[2]};
            num[i] += n;
            num[j] -= n;
        }
        for (int i = 0; i < N; ++i) {
            if (i > 0) {
                num[i] += num[i - 1];
            }
            if (num[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    struct Test : Solution {
        vector<vector<int>> trips;
        int capacity;
        void run() {
            auto ans = carPooling(trips, capacity);
            cout << ans << endl;
        }
    };

    Test t1 {
        .trips = {{2,1,5},{3,3,7}},
        .capacity = 4
    };
    Test t2 {
        .trips = {{2,1,5},{3,3,7}},
        .capacity = 5
    };

    t1.run();
    t2.run();

    return 0;
}