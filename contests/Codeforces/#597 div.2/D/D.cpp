#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))
#define Abs(x) ((x)>=0? (x):(-(x)))
typedef long long ll;
const int N = 2002, inf = (int)1e9+1;
int n, x[N], y[N], c[N], k[N];
int fa[N];
ll Ans;
vector<int> ans;
vector<pair<int, int>> ans2;
bool used[N];
inline ll read()
{
	ll x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x;
}
inline int getDis(int i, int j) {return Abs(x[i]-x[j])+Abs(y[i]-y[j]);}
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) x[i] = read(), y[i] = read();
    for(int i = 1; i <= n; ++i) c[i] = read();
    for(int i = 1; i <= n; ++i) k[i] = read();
    int mn = inf, id;
    for(int lim = n; lim--;)
    {
        mn = inf;
        for(int i = 1; i <= n; ++i)
        {
            if(used[i]) continue;
            if(c[i] < mn)
            {
                mn = c[i];
                id = i;
            }
        }
        Ans += mn;
        used[id] = 1;
        if(!fa[id]) ans.push_back(id);
        else ans2.push_back({id, fa[id]});
        for(int i = 1; i <= n; ++i)
        {
            if(used[i]) continue;
            ll tmp = (ll)getDis(id, i)*(k[id]+k[i]);
            if(c[i] > tmp)
            {
                fa[i] = id;
                c[i] = tmp;
            }
        }
    }
    printf("%lld\n",Ans);
    printf("%d\n",ans.size()); for(auto it : ans) printf("%d ",it); puts("");
    printf("%d\n",ans2.size()); for(auto it : ans2) printf("%d %d\n",it.first, it.second);
    return 0;
}