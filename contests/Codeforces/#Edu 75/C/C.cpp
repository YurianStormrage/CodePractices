#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)3e5+2;
int q, n;
int num[2][N], t[2];
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
        int tmp;
        char ch = getchar();
        while(ch >= '0' && ch <= '9')
        {
            tmp = ch^48;
            num[tmp&1][t[tmp&1]++] = tmp;
            ch = getchar();
        }
        int l = 0, r = 0;
        while(l != t[0] && r != t[1])
        {
            if(num[0][l] < num[1][r]) printf("%d",num[0][l++]);
            else printf("%d",num[1][r++]);
        }
        while(l != t[0]) printf("%d",num[0][l++]);
        while(r != t[1]) printf("%d",num[1][r++]);
        printf("\n");
        t[0] = t[1] = 0;
    }
    return 0;
}