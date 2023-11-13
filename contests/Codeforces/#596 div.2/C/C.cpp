#include <cstdio>
typedef long long ll;

ll n;
int p;

inline ll read()
{
	ll x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch = getchar()) if(ch == '-') f = 1;
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    if(f) return -x;
	return x;
}

inline bool check(int mid)
{
    ll tmp = n - mid*p;
    int pow = 1<<29, cnt = 0;
    while(tmp > 0)
    {
        while(tmp >= pow)
        {
            tmp -= pow;
            --mid;
            cnt += pow-1;
        }
        pow >>= 1;
    }
    return mid >= 0 && mid - cnt <= 0;
}

int main()
{
    n = read(); p = read();
    for(int i = 1; i <= 31; ++i) if(check(i)) {printf("%d",i); return 0;}
    printf("-1");
    return 0;
}