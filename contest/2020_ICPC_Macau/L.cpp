#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    while(ch > '9' || ch < '0') {if(ch == '-') f = 0; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x<<1)+(x<<3)+(ch^48); ch = getchar();}
    return f ? x : -x;
}
int main()
{
    ll n = read();
    double ans = 1;
    for(int i = 1; i <= n; ++i) {
        ans = ans * i * i / n;
    }
    printf("%.10lf", ans);
    return 0;
}