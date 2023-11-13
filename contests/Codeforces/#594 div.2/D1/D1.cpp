#include <cstdio>
typedef long long ll;
const int N = 501;
int n;
bool a[N];
int stk[N], top;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline void Swap(bool &a, bool &b) {bool c = a; a = b; b = c;}
inline int calc()
{
    int num = 0, mn = N, pre = 0;
   for(int k = 0; k < n; ++k)
    {
        if(!a[k]) ++pre;
        else --pre;
        if(mn > pre)
        {
            mn = pre;
            num = 1;
        }
        else if(mn == pre) ++num;
    }
    if(!pre) return num;
    else return 0;
}
int main()
{
    n = read();
    for(int i = 0; i < n; ++i)
    {
        char ch = getchar();
        if(ch == '(') a[i] = 0;
        else a[i] = 1;
    }
    int ans = calc(), l = 0, r = 0;
    if(!ans) {printf("0\n1 1"); return 0;}
    for(int i = 0; i < n; ++i)
        for(int j = i+1; j < n; ++j)
        {
            if(a[i] == a[j]) continue;
            Swap(a[i], a[j]);
            int tmp = calc();
            if(tmp > ans)
            {
                ans = tmp;
                l = i;
                r = j;
            }
            Swap(a[i], a[j]);
        }
    
    printf("%d\n%d %d",ans, l+1, r+1);
    return 0;
}