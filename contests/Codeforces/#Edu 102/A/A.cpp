#include <bits/stdc++.h>
#include <cstdio>
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

const int N = 102;

int n, a[N];
int d;

int main()
{
    for(int T = read(); T--;) {
        n = read(); d = read();
        for(int i = 1; i <= n; ++i)
            a[i] = read();
        bool flag = 1;
        for(int i = 1; i <= n; ++i)
            if(a[i] > d)
                flag = 0;
        if(flag) {
            puts("YES");
            continue;
        }
        int mn[2] = {min(a[1], a[2]), max(a[1], a[2])};

        for(int i = 3; i <= n; ++i) {
            if(a[i] < mn[0]) {
                mn[1] = mn[0];
                mn[0] = a[i];
            }
            else if(a[i] < mn[1]) mn[1] = a[i];
        }
        if(mn[0] + mn[1] <= d) puts("YES");
        else puts("NO");
    }
    return 0;
}