// [WC2009]最短路问题

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
const int N = 1e5 + 2, Q = 1e5 + 2;

int n, q;
int mp[7][N];

struct Node {
    int lr[7][7], ll[7][7], rr[7][7];
    void clear() {
        memset(lr, 0x3f, sizeof(lr));
        memset(ll, 0x3f, sizeof(ll));
        memset(rr, 0x3f, sizeof(rr));
    }
};

Node seg[N << 2];

#define lc ((p) << 1)
#define rc ((p) << 1 | 1)

Node operator+ (const Node& L, const Node& R)
{
    static Node res;
    memset(res.lr, 0x3f, sizeof(res.lr));
    static int lm[7][7], mr[7][7];
    memset(lm, 0x3f, sizeof(lm));
    memset(mr, 0x3f, sizeof(mr));
    for(int i = 1; i <= 6; ++i)
        for(int j = 1; j <= 6; ++j)
            for(int k = 1; k <= 6; ++k) {
                lm[i][j] = min(lm[i][j], L.lr[i][k]+R.ll[k][j]+L.rr[j][j]);
                mr[i][j] = min(mr[i][j], R.ll[i][i]+L.rr[i][k]+R.lr[k][j]);
            }
    for(int i = 1; i <= 6; ++i) {
        for(int j = 1; j <= 6; ++j) {
            res.ll[i][j] = L.ll[i][j];
            res.rr[i][j] = R.rr[i][j];
            for(int k = 1; k <= 6; ++k) {
                res.ll[i][j] = min(res.ll[i][j], lm[i][k]+L.lr[j][k]-L.rr[k][k]);
                res.rr[i][j] = min(res.rr[i][j], mr[k][i]+R.lr[k][j]-R.ll[k][k]);
                res.lr[i][j] = min(res.lr[i][j],
                                min(lm[i][k] - L.rr[k][k] + mr[k][j] - R.ll[k][k], 
                                    L.lr[i][k] + R.lr[k][j]));
            }
        }
    }
    return res;
}

void build(const int& p = 1, const int& l = 1, const int& r = n)
{
    if(l == r) {
        static int sum[7] = {0}; // 赋初值
        for(int i = 1; i <= 6; ++i) sum[i] = sum[i-1] + mp[i][l];
        for(int i = 1; i <= 6; ++i)
            for(int j = i; j <= 6; ++j)
                seg[p].ll[i][j] = seg[p].rr[i][j] = seg[p].lr[i][j]
                = seg[p].ll[j][i] = seg[p].rr[j][i] = seg[p].lr[j][i] = sum[j] - sum[i-1];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    seg[p] = seg[lc] + seg[rc];
}

void modify(const int& y, const int& p = 1, const int& l = 1, const int& r = n)
{
    if(l == r) {
        static int sum[7] = {0}; // 赋初值
        for(int i = 1; i <= 6; ++i) sum[i] = sum[i-1] + mp[i][y];
        for(int i = 1; i <= 6; ++i)
            for(int j = i; j <= 6; ++j)
                seg[p].ll[i][j] = seg[p].rr[i][j] = seg[p].lr[i][j]
                = seg[p].ll[j][i] = seg[p].rr[j][i] = seg[p].lr[j][i] = sum[j] - sum[i-1];
        return ;
    }
    int mid = (l + r) >> 1;
    if(y <= mid) modify(y, lc, l, mid);
    else modify(y, rc, mid+1, r);
    seg[p] = seg[lc] + seg[rc];
}

Node query(int y1, int y2, int p = 1, int l = 1, int r = n)
{
    if(y1 <= l && r <= y2) // 不是 ** l <= y1 && y2 <= r ** , l r表示当前区间
        return seg[p];
    int mid = (l + r) >> 1;
    // 漏掉了分段
    if(y2 <= mid) return query(y1, y2, lc, l, mid);
    if(y1 > mid) return query(y1, y2, rc, mid+1, r);
    return query(y1, y2, lc, l, mid) + query(y1, y2, rc, mid+1, r);
}

#undef lc
#undef rc

int main()
{
    n = read();
    for(int i = 1; i <= 6; ++i)
        for(int j = 1; j <= n; ++j)
            mp[i][j] = read();
    build();
    q = read();
    while(q--) {
        int type = read();
        switch(type) {
            case 1: {
                int x = read(), y = read();
                mp[x][y] = read();
                modify(y);
                break;
            }
            case 2: {
                int x1, x2, y1, y2;
                x1 = read(); y1 = read();
                x2 = read(); y2 = read();
                if(y1 > y2) swap(x1, x2), swap(y1, y2);

                Node L = query(1, y1), M = query(y1, y2), R = query(y2, n);
                int ans = 0x7fffffff;
                for(int i = 1; i <= 6; ++i)
                    for(int j = 1; j <= 6; ++j)
                        for(int k = 1; k <= 6; ++k)
                            for(int t = 1; t <= 6; ++t)
                                ans = min(ans,
                                    M.ll[x1][i] + L.rr[i][j] - M.ll[i][i]
                                    +M.lr[j][k] - M.ll[j][j] - M.rr[k][k]
                                    +R.ll[k][t] + M.rr[t][x2] - M.rr[t][t]);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}