#include <cstdio>
typedef long long ll;
const int N = (int)3e5+2;
int n;
bool a[N<<1];
int ans, ansl, ansr;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    n = read();
    int cnt = 0, mn = 0, pos = -1;
    for(int i = 0; i < n; ++i)
    {
        char ch = getchar();
        if(ch == '(') ++cnt;
        else a[i] = a[i+n] = 1, --cnt;
        if(mn > cnt) mn = cnt, pos = i, ans = 1;
        else if(mn == cnt) ++ans;
    }
    if(cnt) {printf("0\n1 1"); return 0;}
    int I = n + ++pos, num[2] = {0, 0}, l[2], tmp = ans;
    for(int i = pos; i < I; ++i)
    {
        if(!a[i])
        {
            ++cnt;
            if(cnt == 1) ++num[0], l[0] = i;
            else if(cnt == 2) ++num[1], l[1] = i;
        }
        else
        {
            --cnt;
            if(!cnt)
            {
                if(num[0] > ans) {ans = num[0]; ansl = l[0]; ansr = i;}
                num[0] = 0;
            }
            else if(cnt == 1)
            {
                if(tmp + num[1] > ans) {ans = tmp+num[1]; ansl = l[1]; ansr = i;}
                ++num[0]; num[1] = 0;
            }
            else if (cnt == 2) ++num[1];
        }
    }
    printf("%d\n%d %d",ans, ansl%n+1, ansr%n+1);
    return 0;
}