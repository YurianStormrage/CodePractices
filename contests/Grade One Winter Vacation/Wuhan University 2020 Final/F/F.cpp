#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch-48);
    if(f) return -x;
    return x;
}

int n;
char a[21], b[21];
int ans[2][200];

int main()
{
    scanf("%s%s", a, b);
    n = read();
    int lenA = strlen(a), lenB = strlen(b);
    for(int i = 0; i < lenA; ++i) ans[0][(int)a[i]]++;
    for(int i = 0; i < lenB; ++i) ans[1][(int)b[i]]++;
    if(n == 1)
    {
        for(int i = 'A'; i <='Z'; ++i) if(ans[0][i])
            printf("%c: %d\n", i, ans[0][i]);
        for(int i = 'a'; i <='z'; ++i) if(ans[0][i])
            printf("%c: %d\n", i, ans[0][i]);
        return 0;
    }
    if(n == 2)
    {
        for(int i = 'A'; i <='Z'; ++i) if(ans[1][i])
            printf("%c: %d\n", i, ans[1][i]);
        for(int i = 'a'; i <='z'; ++i) if(ans[1][i])
            printf("%c: %d\n", i, ans[1][i]);
        return 0;
    }
    int fib[2] = {1, 1}, tmp;
    for(int i = 3; i < n; ++i)
    {
        tmp = fib[1];
        fib[1] += fib[0];
        fib[0] = tmp;
    }
    for(int k = 0; k <= 1; ++k)
    {
        for(int i = 'A'; i <= 'Z'; ++i) ans[k][i] *= fib[k];
        for(int i = 'a'; i <= 'z'; ++i) ans[k][i] *= fib[k];
    }
    for(int i = 'A'; i <='Z'; ++i) if(ans[0][i] || ans[1][i])
        printf("%c: %d\n", i, ans[0][i]+ans[1][i]);
    for(int i = 'a'; i <='z'; ++i) if(ans[0][i] || ans[1][i])
        printf("%c: %d\n", i, ans[0][i]+ans[1][i]);
    return 0;
}