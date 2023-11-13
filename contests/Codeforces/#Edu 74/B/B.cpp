#include <cstdio>
#include <algorithm>
using namespace std;
const int N = (int)1e5+1;
int q, n, r, a[N];
inline int read()
{
	int x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
	return x;
}
int main()
{
    q = read();
    while(q--)
    {
        n = read(); r = read();
        for(int i = 1; i <= n; ++i) a[i] = read();
        sort(a+1, a+n+1);
        int last = 0, x = 0, ans = 0;
        for(int i = n; i >= 1; --i)
            if(a[i] != last)
            {
                if(a[i] - x <= 0) break;
                else ans++, x += r, last = a[i];
            }
        printf("%d\n",ans);
            
    }
    return 0;
}