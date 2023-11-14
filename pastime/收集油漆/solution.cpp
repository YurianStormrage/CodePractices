#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
    ll x = 0; bool f = 0; char ch = getchar();
    for (; ch < '0' || '9' < ch; ch = getchar()) if (ch == '-') f = 1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? -x : x;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

constexpr int N = 102, M = 10002, inf = 0x7f7f7f7f;
int n;
int r[N], v[N];
int tmp[N], tot, vol, used;
int f[N][M], ans = inf;

int main()
{
    n = read();
    for (int i = 1; i <= n; ++i) {
        tot += r[i] = read();
    }
    for (int i = 1; i <= n; ++i)
        tmp[i] = v[i] = read();

    sort(tmp + 1, tmp + 1 + n, greater<decltype(*tmp)>());
    for (; used <= n && vol < tot; ++used, vol += tmp[used]);
    if (!used) {
        puts("0 0");
        return 0;
    }

    memset(f, 0x7f, sizeof(f));
    f[0][0] = 0; // (0,0,0) -> 0
    for (int k = 1, sum = v[1]; k <= n; ++k, sum += v[k]) {
        for (int i = min(k, used); i; --i)
            for (int j = min(sum, vol); j >= v[k]; --j) {
                f[i][j] = min((ll)f[i][j] + r[k], f[i - 1][j - v[k]]);
                printf("f[%d][%d] = %d\n", i, j, f[i][j]);
            }
        f[0][0] += r[k];
    }

    for (int i = tot; i <= vol; ++i)
        ans = min(ans, f[used][i]);
    printf("%d %d", used, ans);
    return 0;
}