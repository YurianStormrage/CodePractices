#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)2e5 + 2;
int F[N];
int val[N];
inline ll rea()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int find(int x)
{
    if(F[x] == -1) return x;
    int tmp = find(F[x]);
    val[x] += val[F[x]];
    return F[x] = tmp;
}
int main()
{
    int n,m;
    int u,v,w;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(F, -1, sizeof(F));
        memset(val, 0, sizeof(val));
        int ans = 0;
        while(m--)
        {
            u = rea(); v = rea(); w = rea();
            u--;
            int t1 = find(u);
            int t2 = find(v);
            if(t1 != t2)
            {
                F[t2] = t1;
                val[t2] = val[u]-val[v]+w;
            }
            else if(val[v]-val[u] != w)  ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}