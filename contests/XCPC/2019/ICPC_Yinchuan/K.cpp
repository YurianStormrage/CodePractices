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

const int N = 1002, M = 1002;
int n, m;
int A[N][M], B[N][M];
typedef pair<int, int> pt;
int mp[N * M][2];
#define len first
#define wid second
#define x first
#define y second
pair<int, int> f[N][M];
int main()
{
    n = read(); m = read();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            A[i][j] = read();
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            B[i][j] = read();
            mp[B[i][j]][0] = i;
            mp[B[i][j]][1] = j;
        }
    }

    f[1][1].len = f[1][1].wid = 1;

    for(int j = 2; j <= m; ++j) {
        f[1][j].len = 1;
        if(A[1][j-1] == B[mp[A[1][j]][0]][mp[A[1][j]][1]-1]) {
            f[1][j].wid = f[1][j-1].wid + 1;
        }
        else
            f[1][j].wid = 1;
    }

    mp[0][0] = mp[0][1] = 0;

    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            auto now = make_pair(mp[A[i][j]][0], mp[A[i][j]][1]);

            if(A[i-1][j] != 0 && B[now.x-1][now.y] == A[i-1][j]) {
                f[i][j].len = f[i-1][j].len + 1;
                f[i][j].wid = f[i-1][j].wid + 1;
            }
            else
                f[i][j].len = 1;
            if(A[i][j-1] != 0 && B[now.x][now.y-1] == A[i][j-1]) {
                f[i][j].wid = f[i][j].wid == 0? f[i][j-1].wid + 1 : min(f[i][j].wid, f[i][j-1].wid + 1);
                f[i][j].len = min(f[i][j].len, f[i][j-1].len + 1);
            }
            else
                f[i][j].wid = 1;
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            //printf("f[%d][%d] = (%d, %d)\n", i, j, i - f[i][j].len + 1, j - f[i][j].wid + 1);
            ans = max(ans, f[i][j].len * f[i][j].wid);
        }
    }
    printf("%d", ans);
    return 0;
}