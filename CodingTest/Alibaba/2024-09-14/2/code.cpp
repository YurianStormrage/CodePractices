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
constexpr int N = 2e5 + 2;
int hd[N], nxt[N << 1], to[N << 1], tot;
void addedge(int u, int v)
{
    nxt[++tot] = hd[u]; to[tot] = v; hd[u] = tot;
    nxt[++tot] = hd[v]; to[tot] = u; hd[v] = tot;
}
int tag[N];
int main()
{
    int n = read(), m = read(), t = read();
    for (int i = 0; i < m; ++i) {
        addedge(read(), read());
    }
    queue<int> q;
    for (int i = 0; i < t; ++i) {
        auto x = read();
        q.emplace(x);
        tag[x] = 1;
    }
    vector<int> ans;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        // cout << "u = " << u << endl;
        auto cnt = 0;
        for (int i = hd[u]; i; i = nxt[i]) {
            auto v = to[i];
            if (!tag[v] || tag[v] > tag[u])
                ++cnt;
            if (!tag[v]) {
                q.emplace(v);
                tag[v] = tag[u] + 1;
            }
        }
        if (cnt == 0) {
            ans.emplace_back(u);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) printf ("%d ", x);
    return 0;
}