#include <cstdio>
typedef long long ll;
inline ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return x;
    return -x;
}
int main()
{
    int n = read();
    for(int i = 1; i <= n; ++i)
    {
        char s[7];
        scanf("%s", s);
        if(s[0] != 'm')
        {
            int j = 0, tmp = 0;
            while(s[j])
            {
                tmp = tmp*10 + (s[j]^48);
                ++j;
            }
            if(tmp != i) {printf("something is fishy"); return 0;}
        }
    }
    printf("makes sense");
    return 0;
}