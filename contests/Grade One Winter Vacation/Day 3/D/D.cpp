#include <cstdio>
#include <cstring>
typedef long long ll;
const int mod = 37500001;
int a[6];
char hash[mod];
int ans;
inline ll rea()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    for(int i = 1; i <= 5; ++i) a[i] = rea();
    for(int i = -50; i <= 50; ++i)
    {
        if(!i) continue;
        for(int j = -50; j <= 50; ++j)
        {
            if(!j) continue;
            for(int k = -50; k <= 50; ++k)
            {
                if(!k) continue;
                int tmp = a[1]*i*i*i+a[2]*j*j*j+a[3]*k*k*k;
                hash[(tmp+mod)%mod]++;
            }
        }
    }
    for(int i = -50; i <= 50; ++i)
    {
        if(!i) continue;
        for(int j = -50; j <= 50; ++j)
        {
            if(!j) continue;
            int tmp = a[4]*i*i*i+a[5]*j*j*j;
            ans += hash[(-tmp+mod)%mod];
        }
    }
    printf("%d", ans);
    return 0;
}