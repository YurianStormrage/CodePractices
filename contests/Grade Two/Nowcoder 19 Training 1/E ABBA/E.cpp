#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 2, mod = 1e9 + 7;

int n, m;
int f[N][N];

int main()
{
    while(scanf("%d%d", &n, &m) == 2)
    {
        int len = n + m;
        
        for(int i = 0; i <= len; ++i)
            for(int j = 0; j <= len; ++j)
                f[i][j] = 0;
        f[0][0] = 1;

        for(int i = 0; i <= len; ++i)
            for(int j = 0; j <= len; ++j) {
                if((i < n || j > i - n) && ((f[i+1][j] += f[i][j]) >= mod)) f[i+1][j] -= mod;
                if((j < m || i > j - m) && ((f[i][j+1] += f[i][j]) >= mod)) f[i][j+1] -= mod;
            }
        
        printf("%d\n", f[len][len]);
    }
    return 0;
}