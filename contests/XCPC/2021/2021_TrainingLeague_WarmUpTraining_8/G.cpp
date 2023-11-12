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
const int N = 1e5 + 2;
int n, m;
struct Segment {
    static int num;
    int l, r;
    vector <int> pt;
} s[N];

int x[N];
int ans;
int main()
{
    m = read(); n = read();
    for(int i = 1; i <= n; ++i) x[i] = read();
    int last = -1;
    Segment::num = 0;
    for(int i = 1; i <= n; ++i) {
        int now = read();
        if(last != now) {
            
            ++ ans;
            last = now;
        }
    }
    printf("%d", ans);
    return 0;
}