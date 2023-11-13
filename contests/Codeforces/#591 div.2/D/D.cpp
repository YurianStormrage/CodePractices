#include <cstdio>
#define Max(a, b) (a > b ? a : b)
const int N = (int)3e5+10, inf = (int)1e8;

int q;
int n, a;
int l[N], r[N];

inline int read()
{
    int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int main()
{
    q = read();
    while(q--)
    {
        n = read();
        for(int i = 1; i <= n; ++i) l[i] = inf;
        for(int i = 1; i <= n; ++i)
        {
            a = read();
            if(l[a] == inf) l[a] = i;
            r[a] = i;
        }

        int M = 0, cnt = 0, las = 0, tmp = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(l[i] != inf)
            {
                ++cnt;
                if(r[las] <= l[i]) ++tmp;
                else
                {
                    if(tmp > M) M = tmp;
                    tmp = 1;
                }
                las = i;
            }
        }

        printf("%d\n",cnt - Max(M, tmp));
    }
    return 0;
}