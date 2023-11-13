#include <cstdio>
typedef long long ll;
const int N = (int)2e6+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int n;
char stage[N];
int cnt[N];
int main()
{
    int T = read();
    while(T--)
    {
        n = read();
        int fb = 0, f = 0;
        scanf("%s", stage);
        for(int i = 0; i <= n; ++i) cnt[i] = 0;
        for(int i = n - 1; i >= 0; --i) cnt[i] = cnt[i+1] + (stage[i]=='0');
        for(int i = 0; i < n; ++i)
        {
            if(stage[i] == '0')
            {
                if(fb >= 1) fb--, f++;
            }
            else if(stage[i] == '1')
            {
                if(fb > cnt[i]) fb--, f++;
                else fb++;
            }
            else ++f;
        }
        printf("%d\n", f);
    }
    return 0;
}