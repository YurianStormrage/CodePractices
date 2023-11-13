#include <cstdio>
#include <utility>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
const int N = (int)1e5+2;

int n;
int cnt[N];
set<int> list[N];
vector<int> p[N];
int ans[N];

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
    n = read();
    int x;
    for(int i = 1; i <= n-2; ++i)
        for(int j = 1; j <= 3; ++j)
        {
            x = read();
            p[x].push_back(i);
            list[i].insert(x);
        }
    int key, key2;
    for(int i = 1; i <= n; ++i) if(p[i].size() == 1) {key = p[i][0]; ans[1] = i; break;}
    for(int i = 1; i <= n; ++i)
        if(p[i].size() == 2 && (p[i][0] == key || p[i][1] == key))
        {
            key2 = p[i][p[i][0]==key];
            ans[2] = i;
            list[key2].erase(i);
            break;
        }
    list[key].erase(ans[1]); list[key].erase(ans[2]);
    for(int i = 3; i <= n; ++i)
    {
        ans[i] = *list[key].begin();
        for(auto it : p[ans[i]])
        {
            list[it].erase(ans[i]);
            if(list[it].size() == 1) key = it;
        }
    }
    for(int i = 1; i <= n; ++i) printf("%d ",ans[i]);
    return 0;
}