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
constexpr int N = 2e5 + 2;
int a[N];
vector<int> coor[N];
struct Val {
    int val = 0;
    int bit[32]{};
    void update() {
        val = 0;
        for (int i = 31; i >= 0; --i) {
            if (bit[i] > 0) {
                val |= 1 << i;
            }
        }
    }
    void insert(int x) {
        for (int i = 31; i >= 0; --i) {
            if (x >> i & 1) {
                bit[i] += 1;
            }
        }
        update();
    }
    void erase(int x) {
        for (int i = 31; i >= 0; --i) {
            if (x >> i & 1) {
                bit[i] -= 1;
            }
        }
        update();
    }
};
int main()
{
    int n = read();
    for (int i = 1; i <= n; ++i) {
        coor[read()].emplace_back(i);
        coor[read() + 1].emplace_back(-i);
        a[i] = read();
    }
    Val now;
    int ans = 0;
    for (int i = 1; i <= n + 1; ++i) {
        for (auto x : coor[i]) {
            if (x >= 0) {
                now.insert(a[x]);
            } else {
                now.erase(a[-x]);
            }
        }
        ans = max(ans, now.val);
    }
    cout << ans;
    return 0;
}