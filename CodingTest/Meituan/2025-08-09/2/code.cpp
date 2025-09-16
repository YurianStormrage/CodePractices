#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> c(11);
    for (int i = 1; i <= n; ++i) {
        long long a;
        cin >> a;
        for (int j = min(10, i); j > 0; --j) {
            auto tmp = j == 10 ? a - i : (j + 1) * a - i;
            c[j] = max(c[j], c[j - 1] + tmp);
        }
        if (i >= 10)
            c[0] = c[10];
        // for (int j = 0; j <= min(10, i); ++j)
        //     cout << "c[" << j << "]: " << c[j] << "\n";
    }
    long long ans = 0;
    for (int i = 0; i <= min(10, n); ++i) {
        ans = max(ans, c[i] + (long long)n * (n + 1) / 2);
    }
    cout << ans << "\n";

    return 0;
}