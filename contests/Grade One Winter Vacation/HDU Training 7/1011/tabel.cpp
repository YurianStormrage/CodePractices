#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)102, mod = (int)1e9+7;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int n;
int a[N];
int b[N], cnt, tmp[N], num;
int ans;
bool vis[N];

void dfs(int x)
{
    vis[x] = 1;
    b[++cnt] = x;
    if(cnt == n)
    {
        bool flag = 1;
        num = 0;
        for(int i = 1; i <= cnt; ++i)
        {
            while(num && tmp[num] > b[i]) --num;
            tmp[++num] = b[i];
            if(a[i] != -1 && num != a[i]) {flag = 0; break;}
        }
        ans += flag;
        --cnt;
        vis[x] = 0;
        return ;
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    --cnt;
    vis[x] = 0;
}

int main()
{
    for(int T = read(); T--;)
    {
        n = read();
        for(int i = 1; i <= n; ++i)
        {
            a[i] = read();
        }
        ans = 0;
        for(int i = 1; i <= n; ++i) dfs(i);
        printf("%d\n", ans);
    }
    return 0;
}