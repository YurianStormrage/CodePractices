#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch <'0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? x : -x;
}
const int N = 2e5 + 2, M = 1e7 + 2;
int n;
int a[N];
int pf[M], pr[M];
int main()
{
    for(int i = 2; i < M; ++i) {
        if(!pf[i]) pr[++pr[0]] = pf[i] = i;
        for(int j = 1; j <= pr[0] && i * pr[j] <= M; ++j) {
            pf[i * pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; ++i) {
        
    }
    return 0;
}