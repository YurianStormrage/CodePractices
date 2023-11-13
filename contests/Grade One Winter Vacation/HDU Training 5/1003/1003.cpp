#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)41e4, mod = 998244353;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int n;
int model[N];


int main()
{
    for(int T = read(); T--;)
    {
        n = read();
        for(int i = 1; i <= n; ++i);
    }
    return 0;
}