#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <deque>

using namespace std;
using longs = long long;
using uint = unsigned;

inline int nextInt()
{
    int x = 0, f = 0, ch = getchar();
    while (!isdigit(ch)) ch == '-' && (f = 1), ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;
int a[N], b[N], c[N];
longs sum[N];

int main()
{
    freopen("K.in", "r", stdin);
    ios::sync_with_stdio(false);

    int t = nextInt();
    deque<pair<longs, longs>> contrib;
    for (int cases = 1; cases <= t; ++ cases)
    {
        int n = nextInt(), selected = 0; contrib.clear();
        for (int i = 1; i <= n; ++ i) sum[i] = a[i] = nextInt();
        for (int i = 1; i <= n; ++ i) c[i] = b[i] = nextInt();
        for (int i = 2; i <= n; ++ i)
            sum[i] += sum[i - 1], c[i] = min(c[i - 1], c[i]);
        for (int i = n; i; -- i)
        {
            if (sum[i] < sum[1]) continue;
            auto chance = c[i] - selected;
            while (!contrib.empty() && contrib.front().first <= sum[i])
                chance += contrib.front().second,
                selected -= contrib.front().second,
                contrib.pop_front();
            contrib.emplace_front(sum[i], chance);
            selected += chance;
        }
        assert(selected == b[1]);
        longs ans = 0;
        while (!contrib.empty())
            ans += contrib.front().first * contrib.front().second,
            contrib.pop_front();
        printf("Case #%d: %d %lld\n", cases, b[1], ans);
    }

    return 0;
}