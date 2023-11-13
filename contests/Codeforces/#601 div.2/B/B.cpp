#include <cstdio>

typedef long long ll;
const int N = (int)3002;

int q, n, m;
int a[N];
int sum;

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
        n = read(); m = read();
        for(int i = 1; i <= n; ++i)
        {
            a[i] = read();
            sum += a[i];
        }
        if(m < n || n == 2) printf("-1\n");
        else
        {
            printf("%d\n", sum<<1);
            for(int i = 1; i < m; ++i) printf("%d %d\n", i, i+1);
            printf("%d %d\n",1, m);
        }
        sum = 0;
    }
    return 0;
}