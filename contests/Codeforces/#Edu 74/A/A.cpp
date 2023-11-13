#include <cstdio>
typedef long long ll;
int q;
ll x, y;
inline ll read()
{
	ll x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
	return x;
}
int main()
{
    q = read();
    while(q--)
    {
        x = read(); y = read();
        if(x - y != 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}