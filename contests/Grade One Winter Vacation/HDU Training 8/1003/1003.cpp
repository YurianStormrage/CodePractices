#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)102, mod = (int)1e9+7;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

ll x[3], y[3];

int main()
{
    for(int T = read(); T--;)
    {
        for(int i = 0; i < 3; ++i)
        {
            x[i] = read();
            y[i] = read();
        }
        int a = x[1] - x[0], b = y[1] - y[0], d = x[2] - x[0], e = y[2] - y[0];
        if(a * e - b * d < 0) printf("Clockwise\n");
        else printf("Counterclockwise\n");
    }
    return 0;
}