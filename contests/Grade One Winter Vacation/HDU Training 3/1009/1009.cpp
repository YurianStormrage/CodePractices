#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)1e5+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int n;
int x[N], hd, tl;
char s[N];
int main()
{
    for(int T = read(); T--;)
    {
        scanf("%s", s);
        n = strlen(s);
        int flag = 0;
        hd = 1; tl = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '*') x[++tl] = i;
            else if(s[i] == '(') ++flag;
            else --flag;
            if(flag < 0)
            {
                if(hd > tl) break;
                s[x[hd++]] = '(';
                flag++;
            }
        }
        if(flag < 0) {printf("No solution!\n"); continue;}
        if(flag == 0)
        {
            for(int i = 0; i < n; ++i) if(s[i] != '*') putchar(s[i]); puts("");
            continue;
        }
        flag = 0;
        hd = 1; tl = 0;
        for(int i = n-1; i >= 0; --i)
        {
            if(s[i] == '*') x[++tl] = i;
            else if(s[i] == ')') --flag;
            else ++flag;
            if(flag > 0)
            {
                if(hd > tl) break;
                s[x[hd++]] = ')';
                flag--;
            }
        }
        if(flag) {printf("No solution!\n"); continue;}
        for(int i = 0; i < n; ++i) if(s[i] != '*') putchar(s[i]); puts("");
    }
    return 0;
}