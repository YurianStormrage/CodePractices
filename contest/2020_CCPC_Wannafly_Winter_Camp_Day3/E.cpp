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
int n, m;
// int board[502][502];
bitset<502> board[502];
int main()
{
    for(int T = read(); T--; ) {
        n = read(); m = read();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                board[i][j] = getchar() ^ 48;
        
    }
    return 0;
}