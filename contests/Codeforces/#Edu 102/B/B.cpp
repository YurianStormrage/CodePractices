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

const int N = 402;

int S, T;
char s[N], t[N];

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

int main()
{
    for(int q = read(); q--;) {
        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
        scanf("%s%s", s, t);
        S = strlen(s); T = strlen(t);
        int len = S * T / gcd(S, T);
        for(int i = S; i < len; ++ i) {
            s[i] = s[i - S];
        }
        for(int i = T; i < len; ++ i) {
            t[i] = t[i - T];
        }
        if(strcmp(s, t)) printf("-1\n");
        else puts(s);
    }
    return 0;
}