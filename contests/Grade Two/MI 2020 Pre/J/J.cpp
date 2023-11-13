#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch <'0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? x : -x;
}
const int N = 1e3 + 2;
int n, m, a, b;
int m[N][N];
int c[N][N];
int main()
{
    for(int T = read(); T--;) {
        n = read(); m = read(); a = read(); b = read();
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                m[i][j] = read();
        
    }
    return 0;
}