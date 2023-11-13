#include <cstdio>
typedef long long ll;
const int N = (int)2e5+2, K = (int)1e6+2;

int q, n, k, d;
int a[N], used[K];
int tmp, ans;

inline ll read()
{
	ll x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x;
}

int main()
{
    q = read();
    while(q--)
    {
        n = read(); k = read(); d = read();
        for(int i = 1; i <= n; ++i) {a[i] = read(); used[a[i]] = 0;}
        tmp = 0;
        for(int i = 1; i <= d; ++i) if(used[a[i]]++ == 0) ++tmp;
        ans = tmp;
        for(int i = d+1; i <= n; ++i)
        {
            if(--used[a[i-d]] == 0) --tmp;
            if(used[a[i]]++ == 0) ++tmp;
            if(tmp < ans) ans = tmp;
        }
        printf("%d\n",ans);
    }
    return 0;
}