#include <iostream>
#include <cstdio>
#include <cctype>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cassert>

#define CODE 2
#define READ 1
#define ALL 3

using namespace std;
using longs = long long;
using uint = unsigned;

inline int nextInt()
{
    int x = 0, f = 1, ch = getchar();
    while (!isdigit(ch)) if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

const int N = 1e5 + 5;
const longs mod = 1e9 + 7;
int ch[N], tp[4];
struct {longs r, c, contrib;} hook[N];

namespace FastC
{
    const longs mod = 1e9 + 7;
    longs fact[N], inv[N];

    longs fastPow(longs a, longs b)
    {
        longs ans = 1;
        while (b)
        {
            if (b & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans % mod;
    }

    void init(int p)
    {
        fact[0] = 1;
        for (int i = 1; i <= p; i++)
            fact[i] = fact[i - 1] * i % mod;
        inv[p] = fastPow(fact[p], mod - 2);
        for (int i = p - 1; i >= 0; i--)
            inv[i] = inv[i + 1] * (i + 1) % mod;
    }

    longs C(longs n, longs m)
    {
        if (m > n) return 0;
        return fact[n] * inv[m] % mod * inv[n - m] % mod;
    }
}

namespace UFS
{
    using number = int;
    number p[N];

    void init(int n = N)
    {
        for (int i = 0; i < n; ++ i)
            p[i] = i;
    }

    number father(int x)
    {
        return p[x] == x ? x : p[x] = father(p[x]);
    }

    number join(int x, int y)
    {
        return p[father(x)] = p[father(y)];
    }
}

longs calculate(int cc, int rr, int xc, int xr)
{
    using FastC::C;
    auto _3 = C(cc, 3) + C(cc, 2) * rr % mod;
    auto _2 = C(cc, 2) * (xc + xr) % mod + (longs)cc * rr % mod * xc % mod;
    return (_3 + _2) % mod;
}

longs calculate(int cc, int rr)
{return calculate(cc, rr, tp[CODE] - cc, tp[READ] - rr);}

longs connect(longs old, int u, int v)
{
    auto ufa = UFS::father(u), vfa = UFS::father(v);
    if (ufa == vfa) return old;
    auto tmp = (old + hook[ufa].contrib + hook[vfa].contrib) % mod;
    auto nr = hook[ufa].r + hook[vfa].r, nc = hook[ufa].c + hook[vfa].c;
    auto fa = UFS::join(u, v);
    hook[fa] = {nr, nc, calculate(nc, nr)};
    return (tmp - hook[fa].contrib + mod) % mod;
}

int main()
{
    FastC::init(1e5 + 1);
    int t, n;
    cin >> t;
    while (t --)
    {
        cin >> t;
        memset(ch, 0, sizeof(int) * (n + 1));
        UFS::init(n + 1);
        tp[CODE] = tp[READ] = tp[ALL] = 0;
        for (int i = 1; i <= n; ++ i)
        {
            cin >> ch[i], ++ tp[ch[i]];
            if (ch[i] == CODE) hook[i] = {0, 1, 0};
            else hook[i] = {1, 0, 0};
        }
        longs all = calculate(tp[CODE], tp[READ]);
        cout << all << endl;
        auto tmp = all;
        for (int i = 1; i < n; ++ i)
        {
            int u, v;
            cin >> u >> v;
            tmp = connect(tmp, u, v);
            cout << tmp << endl;
            assert(tmp >= 0 && tmp < mod);
        }
    }

    return 0;
}