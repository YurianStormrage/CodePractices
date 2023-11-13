#include <cstdio>
const int N = (int)2e5+1;
int q, h, n, p[N];
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
        h = read(); n = read();
        for(int i = 1; i <= n; ++i) p[i] = read();

        int pos = p[2]+1, ans = 0; p[n+1] = 0;
        for(int i = 2; i <= n; ++i)
        {
            if(pos == p[i+1]+2) pos = p[(++i)+1]+1;
            else ++ans, pos = p[i+1]+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}