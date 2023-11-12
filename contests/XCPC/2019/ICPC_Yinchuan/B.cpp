#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    while(ch > '9' || ch < '0') {if(ch == '-') f = 0; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x<<1)+(x<<3)+(ch^48); ch = getchar();}
    return f ? x : -x;
}
const int N = 1002;
int n;
int a[N][N];
int x, y;
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            a[i][j] = read();
            if(a[i][j] == -1) x = i, y = j;
        }
    
    for(int i = 1; i <= n; ++ i) {
        if(i == x) continue;
        int mn = 1e6;
        for(int j = 1; j <= n; ++j)
            mn = min(mn, a[i][j]);
        for(int j = 1; j <= n; ++j)
            a[i][j] -= mn;
    }
    for(int j = 1; j <= n; ++j) {
        if(j == y) continue;
        int mn = 1e6;
        for(int i = 1; i <= n; ++i) 
            mn = min(mn, a[i][j]);
        for(int i = 1; i <= n; ++i)
            a[i][j] -= mn;
    }

    // for(int i = 1; i <= n; ++i) {
    //     for(int j = 1; j <= n; ++j)
    //         printf("%3d", a[i][j]);
    //     puts("");
    // }

    printf("%d", a[x][1] + a[1][y]);
    return 0;
}