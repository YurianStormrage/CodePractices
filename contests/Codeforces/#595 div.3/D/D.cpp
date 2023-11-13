#include <cstdio>
#include <set>
using namespace std;
#define Min(a, b) ((a)<(b)? (a):(b))
#define Max(a, b) ((a)>(b)? (a):(b))
typedef long long ll;
const int N = (int)2e5+2;
int n, k;
int r[N];
int hd[N], nxt[N], id[N], tot;
struct Pair
{
    int f,s;
    Pair(int _f=0,int _s=0){f=_f;s=_s;}
    inline bool operator < (Pair a)const
    {
        if(f != a.f) return f > a.f;
        else return s < a.s;
    }
};
set<Pair>seg;
int ans[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline void addseg(int l, int r, int i) {nxt[++tot] = hd[l]; hd[l] = tot; id[tot] = i;}
int main()
{
    n = read(); k = read();
    int L = N, R = 0;
    for(int i = 1; i <= n; ++i)
    {
        int l = read();
        r[i] = read();
        addseg(l, r[i]+1, i);
        L = Min(l, L); R = Max(r[i], R);
    }
    for(int i = L; i <= R; ++i)
    {
        for(int k = hd[i]; k; k = nxt[k]) seg.insert(Pair(r[id[k]], id[k]));
        while(seg.size() > k)
        {
            ans[++ans[0]] = seg.begin()->s;
            seg.erase(seg.begin());
        }
        while(!seg.empty() && (--seg.end())->f <= i) seg.erase(--seg.end());
    }
    printf("%d\n",ans[0]);
    for(int i = 1; i <= ans[0]; ++i) printf("%d ",ans[i]);
    return 0;
}