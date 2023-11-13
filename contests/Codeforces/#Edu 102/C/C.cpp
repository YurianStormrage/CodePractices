#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar())
        if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x<<1)+(x<<3)+(ch^48);
    return f? x : -x;
}

const int N = 1e5 + 2;

int n, k;
int a[N];

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

int main()
{
    for(int q = read(); q--;) {
        n = read(); k = read();
        int d = 2 * k - n;
        for(int i = 1; i < d; ++ i) a[i] = i;
        for(int i = d; i <= k; ++ i) a[i] = k - i + d;
        //for(int i = k; i <= n; ++ i) a[i] = d + i - k;
        for(int i = 1; i <= k; ++ i) printf("%d ", a[i]); puts("");
    }
    return 0;
}