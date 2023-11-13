#include <cstdio>

typedef long long ll;
const int N = (int)102;

int q;
int n, m, k;
char map[N][N], ans[N][N];
char chicken[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

inline ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    if(f) return -x;
    return x;
}

int main()
{
    q = read();
    while(q--)
    {
        n = read(); m = read(); k = read();
        int numRice = 0, tmpRice = 0, now = 0;
        int key, rest;
        for(int i = 0; i < n; ++i) scanf("%s", map[i]);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                numRice += map[i][j] == 'R';
        key = numRice/k; rest = numRice%k;
        for(int i = 0; i < n; ++i)
        {
            if(i&1)
            {
                for(int j = m-1; j >= 0; --j)
                {
                    ans[i][j] = chicken[now];
                    tmpRice += map[i][j]=='R';
                    if(tmpRice == key+(now<rest))
                    {
                        tmpRice = 0;
                        now += (now+1)<k;
                    }
                }
            }
            else
            {
                for(int j = 0; j < m; ++j)
                {
                    ans[i][j] = chicken[now];
                    tmpRice += map[i][j]=='R';
                    if(tmpRice == key+(now<rest))
                    {
                        tmpRice = 0;
                        now += (now+1)<k;
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j) putchar(ans[i][j]);
            puts("");
        }
    }
    return 0;
}