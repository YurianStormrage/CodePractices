#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int q, n;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    q = read();
    while(q--)
    {
        n = read();
        bool flag = 0;
        int cnt = 0;
        int num, num0, num1;
        for(int i = 0; i < n; ++i)
        {
            num = num0 = num1 = 0;
            char ch = getchar();
            while(ch == '0' || ch == '1')
            {
                ++num;
                if(ch=='0') ++num0;
                else ++num1;
                ch = getchar();
            }
            if(num&1) flag = 1;
            else if(num0&1 || num1&1) ++cnt;
        }
        if(flag || !(cnt&1)) printf("%d\n",n);
        else printf("%d\n",n-1);
    }
    return 0;
}