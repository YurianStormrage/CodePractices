#include <cstdio>
#include <set>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
const int N = (int)2e5+2;
int n, k;
vector<pair<int, int>>e[N];
set<pair<int, int>>seg;
int ans[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    n = read(); k = read();
    for(int i = 1; i <= n; ++i) e[read()].push_back(make_pair(read(), i));
    for(int i = 1; i <= 2e5; ++i)
    {
        int lim = e[i].size();
        for(int j = 0; j < lim; ++j) seg.insert(e[i][j]);
        while(seg.size() > k)
        {
            ans[++ans[0]] = (--seg.end())->second;
            seg.erase(--seg.end());
        }
        while(!seg.empty() && seg.begin()->first <= i) seg.erase(seg.begin());
    }
    printf("%d\n",ans[0]);
    for(int i = 1; i <= ans[0]; ++i) printf("%d ",ans[i]);
    return 0;
}