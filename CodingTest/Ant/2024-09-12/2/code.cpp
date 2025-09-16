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
int main()
{
    int n = read(), m = read();
    vector<int> a;
    a.reserve(n + 1);
    a.emplace_back(0);
    for (int i = 1; i <= n; ++i) a.push_back(read());
    using pii = pair<int, int>;
    unordered_map<int, pii> mp;
    for (int i = 1; i <= n; ++i) {
        auto x = a[i];
        if (mp.find(x) == mp.end()) mp[x] = {i, i};
        else mp[x].second = i;
    }
    for (int i = 1, j = 1; i <= m; ++i) {
        while (j <= m && mp.find(j) == mp.end()) ++j;
        printf ("%d %d\n", mp[j].first, mp[j].second);
        if (i == j) ++j;
    }
    return 0;
}