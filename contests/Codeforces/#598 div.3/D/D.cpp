#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)1e6+2;
int q, n;
ll k;
char s[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    q = read();
    while(q--)
    {
        n = read(); k = read();
        scanf("%s",s);
        int cnt = 0;
        for(int i = 0; i < n; ++i)
            if(s[i] == '0')
            {
                if(k >= i-cnt)
                {
                    k -= i-cnt;
                    swap(s[cnt], s[i]);
                }
                else {swap(s[i], s[i-k]); break;}
                ++cnt;
            }
        printf("%s\n",s);
    }
    return 0;
}