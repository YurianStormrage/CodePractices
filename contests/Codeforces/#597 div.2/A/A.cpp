#include <cstdio>
typedef long long ll;
inline ll read()
{
	ll x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x;
}
inline int gcd(int a, int b) {return b? gcd(b,a%b):a;}
int main()
{
    int q = read();
    while(q--)
    {
        int a = read(), b = read();
        if(gcd(a,b) != 1) puts("Infinite");
        else puts("Finite");
    }
    return 0;
}