#include <cstdio>
#include <cstring>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))
typedef long long ll;
const int N = 102;
int q, n, a, b, c;
char s[N], ans[N];
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
        n = read(); a = read(); b = read(); c = read();
        scanf("%s",s);
        int num1 = 0, num2 = 0, num3 = 0, A, B, C;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == 'R') num1++;
            else if(s[i] == 'P') num2++;
            else num3++;
        }
        A = Min(num3, a); B = Min(num1, b); C = Min(num2, c);
        if((A+B+C)<<1 < n) {puts("NO"); continue;}
        for(int i = 0; i <= n; ++i) ans[i] = '\0';
        for(int i = 0; i < n; ++i)
            if(s[i] == 'R')
            {
                if(!B) break;
                ans[i] = 'P';
                --B;
            }
        for(int i = 0; i < n; ++i)
            if(s[i] == 'P')
            {
                if(!C) break;
                ans[i] = 'S';
                --C;
            }
        for(int i = 0; i < n; ++i)
            if(s[i] == 'S')
            {
                if(!A) break;
                ans[i] = 'R';
                --A;
            }
        a = a - Min(num3, a); b = b - Min(num1, b); c = c - Min(num2, c);
        for(int i = 0; i < n; ++i)
        {
            if(ans[i] != '\0') continue;
            if(a-- > 0) ans[i] = 'R';
            else if(b-- > 0) ans[i] = 'P';
            else ans[i] = 'S', --c;
        }
        printf("YES\n%s\n",ans);
    }
    return 0;
}