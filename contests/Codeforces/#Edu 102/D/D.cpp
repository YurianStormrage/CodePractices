#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar())
        if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x<<1)+(x<<3)+(ch^48);
    return f? x : -x;
}

const int N = 2e5 + 2;

int n, m;
char s[N];
struct Query {
    int id;
    int l, r;
    bool operator<(Query x) {
        return l == x.l? r < x.r : l < x.l;
    }
}q[N];
int mp[N], ans[N];

int main()
{
    for(int T = read(); T--;) {
        n = read(); m = read();
        scanf("%s", s);
        for(int i = 1; i <= m; ++i) {
            q[i].id = i;
            q[i].l = read(); q[i].r = read();
        }
        sort(q + 1, q + 1 + m);
        for(int i = 1; i <= m; ++i) mp[q[i].id] = i;
        ans[0] = 1;
        int l = q[1].l, r = q[1].r;
        int mx = 0, mn = 0, now = 0;
        for(int i = 1; i < l; ++i) {
            now += s[i-1] == '+'? 1 : -1;
            if(now > mx) mx = now;
            if(now < mn) mn = now;
        }
        int _mx = 0, _mn = 0, _now = 0;
        for(int i = r + 1; i <= n; ++i) {
            _now += s[i-1] == '+'? 1 : -1;
            if(_now > _mx) _mx = _now;
            if(_now < _mn) _mn = _now;
        }
        int MX = max(mx, _mx + now), MN = min(mn, _mn + now);
        ans[1] = MX - MN + 1;
        for(int i = 2; i <= m; ++i) {
            if(q[i].l > q[i-1].l) {
                for(int j = q[i-1].l; j < q[i].l; ++j) {
                    now += s[j-1] == '+'? 1 : -1;
                    if(now > mx) mx = now;
                    if(now < mn) mn = now;
                }
                for(int j = q[i].r + 1; j <= n; ++j) {
                    _now += s[j-1] == '+'? 1 : -1;
                    if(_now > _mx) _mx = _now;
                    if(_now < _mn) _mn = _now;
                }
            }
            else if(q[i].r > q[i-1].r) {
                for(int j = q[i].r + 1; j <= n; ++j) {
                    _now += s[j-1] == '+'? -1 : 1;
                    if(_now > _mx) _mx = _now;
                    if(_now < _mn) _mn = _now;
                }
            }
            MX = max(mx, _mx + now), MN = min(mn, _mn + now);
            ans[i] = MX - MN + 1;
        }
        for(int i = 1; i <= n; ++i) printf("%d\n", ans[mp[i]]);
    }
    return 0;
}