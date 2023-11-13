#include <cstdio>
const int N = (int)4e5+1;
int n, k;
bool a[N];
int c[N];
inline int read()
{
    int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    n = read(); k = read();
    for(int i = 1; i <= n; ++i)
    {
        char ch = getchar();
        a[i] = a[i+n] = ch == 'B';
        c[i] = c[i+n] = a[i];
    }

    int lim;
    lim = a[1] == a[n]? n : n<<1;
    if(a[1] == a[n] || a[1] == a[2]) c[1] += 2;
    for(int i = 2; i < lim; ++i) if(a[i] == a[i-1] || a[i] == a[i+1]) c[i] += 2;
    if(a[lim] == a[1] || a[lim] == a[lim-1]) c[lim] += 2;

    int l = 0; bool flag = 0;
    for(int i = 1; i <= lim; ++i)
    {
        if(c[i]>>1)
        {
            if(!flag)
            {
                l = i;
                continue;
            }
            int tmp;
            if(c[l] == c[i])
            {
                if(k >= (i-l)>>1) for(int j = l+1; j < i; ++j) c[(j-1)%n+1] = c[l];
                else
                {
                    tmp = k;
                    for(int j = l+1;tmp; ++j,--tmp) c[(j-1)%n+1] = c[l];
                    tmp = k;
                    for(int j = i-1;tmp; --j,--tmp) c[(j-1)%n+1] = c[l];
                    if(k&1) for(int j = l+k+1; j < i-k; ++j) c[(j-1)%n+1] ^= 1;
                }
            }
            else
            {
                if(k >= (i-l)>>1)
                {
                    tmp = (i-l)>>1;
                    for(int j = l+1;tmp; ++j,--tmp) c[(j-1)%n+1] = c[l];
                    tmp = (i-l)>>1;
                    for(int j = i-1;tmp; --j,--tmp) c[(j-1)%n+1] = c[i];
                }
                else
                {
                    tmp = k;
                    for(int j = l+1;tmp; ++j,--tmp) c[(j-1)%n+1] = c[l];
                    tmp = k;
                    for(int j = i-1;tmp; --j,--tmp) c[(j-1)%n+1] = c[i];
                    if(k&1) for(int j = l+k+1; j < i-k; ++j) c[(j-1)%n+1] ^= 1;
                }
            }
            if(i >= n) break;
            flag = 0;
        }
        else if(l) flag = 1;
    }

    for(int i = 1; i <= n; ++i)
    {
        if(c[i] == 0 || c[i] == 2) putchar('W');
        else putchar('B');
    }
    return 0;
}