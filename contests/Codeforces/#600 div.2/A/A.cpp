#include <cstdio>

typedef long long ll;
const int N = (int)1e5+2;

inline int Min(int a, int b) {return a < b? a : b;}
inline int Max(int a, int b) {return a > b? a : b;}

int q, n;
int a[N], b[N];

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
    q = read();
    while(q--)
    {
        n = read();
        int d = 0, i;
        bool flag = 0;
        for(i = 1; i <= n; ++i) a[i] = read();
        for(i = 1; i <= n; ++i) b[i] = read();
        for(i = 1; i <= n; ++i)
            if(b[i] - a[i] != d)
            {
                if(a[i] == b[i]) d = 0;
                else if(flag || a[i] > b[i]) {printf("NO\n"); break;}
                else d = b[i]-a[i], flag = 1;
            }
        if(i > n) printf("YES\n");
    }
    return 0;
}