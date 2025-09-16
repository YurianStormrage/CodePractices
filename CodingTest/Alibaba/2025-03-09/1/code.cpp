#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 2e5 + 2, mod = 1e9 + 7;
// int cnt[N];
int num_seq[N];
int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        // memset(cnt, 0, sizeof(cnt));
        ll ans = 0;
        memset(num_seq, 0, sizeof(num_seq));
        num_seq[0] = 1;
        for (int i = 0; i < n; ++i) {
            ll x; cin >> x;
            (ans += x * num_seq[x - 1] % mod) %= mod;
            (num_seq[x] += num_seq[x - 1]) %= mod;
        }
        // for (int i = 1; i <= n; ++i) {
        //     int x; cin >> x;
        //     cnt[x] += 1;
        // }
        // ll ans = 0, all_cnt = 1;
        // for (int i = 1; i <= n; ++i) {
        //     if (!cnt[i]) break;
        //     (all_cnt *= cnt[i]) %= mod;
        //     (ans += i * all_cnt % mod) %= mod;
        // }
        cout << ans << endl;
    }
    return 0;
}