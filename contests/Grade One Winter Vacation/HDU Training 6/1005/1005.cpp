#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5002;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}
string str="11451419191145141919";
int ans[N];
bool vis[20][20];
set<int> s[20][20];
ll num(const int& l, const int& r)
{
    ll res = 0;
    for(int i = l; i <= r; ++i) res = (res<<1)+(res<<3)+(str[i]^48);
    return res;
}
void dfs(const int& l, const int& r)
{
    if(vis[l][r]) return;
    vis[l][r] = 1;
    for(int i = l; i < r; ++i)
    {
        dfs(l, i); dfs(i+1, r);
        for(auto x : s[l][i]) for(auto y : s[i+1][r])
        {
            if(x + y <= 5000) s[l][r].insert(x + y);
            if(x * y <= 5000) s[l][r].insert(x * y);
        }
    }
    if(num(l, r) <= 5000) s[l][r].insert(num(l, r));
}
int main()
{
    freopen("1005.out", "w", stdout);
    int n = 15;
    dfs(0, n);
    memset(ans, -1, sizeof(ans));
    for(int i = 0; i <= n; ++i) for(auto x : s[0][i]) if(!~ans[x]) ans[x] = i + 1;
    for(int i = 1; i < 5000; ++i) printf("%d,", ans[i]);
    printf("%d", ans[5000]);
    return 0;
}