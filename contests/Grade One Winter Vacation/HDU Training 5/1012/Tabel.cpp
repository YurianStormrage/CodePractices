#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)5e6+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int n;

int main()
{
    freopen("tabel.out", "w", stdout);
    n = 9;
    ll a[50] = {0, 1, 1}, b[50] = {0};
    printf("1 1\n");
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= i+1; ++j) b[j] = (i-2+j)*a[j-1] + (i-j+1)*a[j];
        for(int j = 1; j <= i+1; ++j) a[j] = b[j];
        for(int j = 1; j <= i+1; ++j) printf("%lld ", a[j]);
        puts("");
    }
    return 0;
}