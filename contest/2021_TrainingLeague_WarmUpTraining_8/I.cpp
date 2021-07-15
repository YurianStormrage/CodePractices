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

int n;
struct Thread {
    int x, l;
    inline bool operator<(const Thread& x) {return this->x < x.x;}
}T[N];

bool check(const int& mid) {
    int pos = -mid;
    for(int i = 1; i <= n; ++i) {
        int next = pos + mid;
        if(next > T[i].x + T[i].l) return false;
        pos = max(next, T[i].x);
    }
    return true;
}

int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) {
        T[i] = {(int)read(), (int)read()};
    }
    sort(T + 1, T + 1 + n);
    if(n == 2) {
        printf("%d\n", (T[2].x + T[2].l) - T[1].x);
        return 0;
    }
    int left = 0, right = 1e9;
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) >> 1;
        if(check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}