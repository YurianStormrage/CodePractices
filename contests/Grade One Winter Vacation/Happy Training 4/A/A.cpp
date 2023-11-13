#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

const int N = (int)1e5 + 2, mod = (int)1e9 + 7;

int n, m, p[N];

struct edge
{
    int u, v;
    ll w;
} e[N];

bool cmp(edge a, edge b)
{
    if(a.w != b.w) return a.w < b.w;
    if(a.u != b.u) return a.u < b.u;
    return a.v < b.v; 
}

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

ll k1,k2;
ll xorShift128Plus()
{
    ll k3=k1,k4=k2;
    k1=k4;
    k3^=k3<<23;
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}
void gen()
{
    scanf("%d%d%llu%llu",&n,&m,&k1,&k2);
    for(int i=1;i<=m;i++)
    {
        e[i].u=xorShift128Plus()%n+1;
        e[i].v=xorShift128Plus()%n+1;
        e[i].w=xorShift128Plus();
        if(e[i].u > e[i].v)
            swap(e[i].u, e[i].v);
    }
}

void kurskal()
{
    gen();
    for(int i = 1; i <= n; ++i) p[i]=i; 
    sort(e+1, e+m+1, cmp);
    int cnt = 0;
    ll val = 0, num = 1, tmp;
    for(int i = 1; i <= m; ++i)
    {
        int fu = find(e[i].u), fv = find(e[i].v);
        if(fu != fv)
        {
            p[fu] = fv;
            ++cnt;
            tmp = 1;
            val = (val + e[i].w) % mod;
            while(i+1 <= m && e[i].u == e[i+1].u && e[i].v == e[i+1].v && e[i].w == e[i+1].w)
            {
                ++i;
                ++tmp;
            }
            num = num * tmp % mod;
        }
        if(cnt == n-1) break;
    }
    if(cnt == n-1) printf("%llu\n", val % mod * num % mod);
    else printf("0\n");
}

int main()
{
    int q; 
    scanf("%d", &q);
    while(q--)
        kurskal();
    return 0;
}