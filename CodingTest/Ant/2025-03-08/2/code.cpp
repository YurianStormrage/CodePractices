#include <bits/stdc++.h>
#include <functional>
using namespace std;
using ll = long long;
int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    cin >> T;
    vector<int> cnt(26);
    while (T--) {
        for (auto& x : cnt) {
            cin >> x;
        }
        // sort(cnt.begin(), cnt.end(), greater<>());
        // ll ans = 0;
        // int mx = cnt[0];
        // for (int i = 1; i <= 25; ++i) {
        //     ans += min(mx - 1, cnt[i]);
        // }
        ll ans = 0, sum = 0;
        int mx = 0;
        for (auto x : cnt) {
            mx = max(mx, x);
            sum += x;
        }
        if (mx <= sum - mx + 1) {
            ans = sum;
        } else {
            ans = (sum - mx) * 2 + 1;
        }
        cout << ans << endl;
    }
    return 0;
}