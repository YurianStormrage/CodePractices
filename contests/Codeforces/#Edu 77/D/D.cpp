
#include <cstdio>
#include <algorithm>
#include <functional>

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)2e5+2, K = (int)2e5+2;

int m, n, k, t;
int a[M];
struct two{int a,b;}trp[K];
inline bool cmp(two a, two b) {return a.b==b.b? a.a<b.a:a.b>b.b;}
int Mxc[K];

inline ll read()
{
	ll x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x;
}

bool check(int mid)
{
    int hd = 1;
    while(trp[hd].b > a[mid]) ++hd;
    --hd;
    //int tmp = (Mxc[hd]<<1)+n+1;
    return (Mxc[hd]<<1)+n+1 <= t;
}

int main()
{
    m = read(); n = read(); k = read(); t = read();
    for(int i = 1; i <= m; ++i) a[i] = read();
    for(int i = 1; i <= k; ++i) read(), trp[i] = {(int)read(), (int)read()};
    sort(a+1, a+1+m, greater<int>());
    sort(trp+1, trp+1+k, cmp);
    for(int i = 1; i <= k; ++i) Mxc[i] = max(trp[i].a, Mxc[i-1]);
    int l = 0, r = m, mid, ans;
    while(l <= r)
    {
        mid = (l+r)>>1;
        if(check(mid))
        {
            l = mid+1;
            ans = mid;
        }
        else r = mid-1;
    }
    printf("%d\n",ans);
    return 0;
}