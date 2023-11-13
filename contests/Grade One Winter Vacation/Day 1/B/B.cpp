#include <cstdio>
typedef long long ll;
int q, n;
int a[7];
ll rea()
{
    ll x = 0; char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int main()
{
    q = rea();
    while(q--)
    {
        n = rea();
        int mx = 0;
        for(int j = 1; j <= n; ++j)
        {
            bool flag = true;
            for(int i = 0; i < 7; ++i) a[i] = rea();
            for(int i = 3; i <= 5; ++i) a[i] -= a[6];
            int sum = 0;
            for(int i = 3; i <= 6; ++i) sum += a[i];
            for(int i = 0; i <= 2; ++i) a[i] -= sum-a[(i+1)%3+3];
            for(int i = 0; i < 7; ++i) if(a[i] < 0) {flag = false; break;}
            if(!flag) continue;
            else if(sum+a[0]+a[1]+a[2] > mx) mx = sum+a[0]+a[1]+a[2];
        }
        printf("%d\n", mx);
    }
    return 0;
}