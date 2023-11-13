#include <cstdio>
typedef long long ll;
inline ll read()
{
	ll x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x;
}
int main()
{
    int a = read(), b = read();
    if(a == 9 && b == 1) printf("9 10");
    else if(a > b || a+1 < b) printf("-1");
    else if(a == b) printf("%d0 %d1", a, b);
    else printf("%d %d", a, b);
    return 0;
}