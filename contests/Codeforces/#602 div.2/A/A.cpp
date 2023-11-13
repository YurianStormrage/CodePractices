#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;

const int inf = (int)1e9;

int q, n;

inline ll read()
{
	ll x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x;
}

int main()
{
    q = read();
    while(q--)
    {
        n = read();
        int minr = inf, maxl = 0;
        for(int i = 1; i <= n; ++i)
        {
            maxl = max((int)read(), maxl);
            minr = min((int)read(), minr);
        }
        printf("%d\n",max(0, maxl-minr));
    }
    return 0;
}