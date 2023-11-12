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

const int N = 1e5 + 2, Q = 1e5 + 2;
int n, m;

struct SegmentTree {
    struct Node {
        int mx = 0, lazy = 0;
    } nd[N << 2];

    #define ls(p) ((p) << 1)
    #define rs(p) ((p) << 1 | 1)

    inline void pushdown(const int& p) {
        nd[p << 1].mx += nd[p].lazy;
        nd[p<<1|1].mx += nd[p].lazy;
        nd[p << 1].lazy += nd[p].lazy;
        nd[p<<1|1].lazy += nd[p].lazy;
        nd[p].lazy = 0;
    }

    inline void update(const int& p) {
        nd[p].mx = max(nd[p<<1].mx, nd[p<<1|1].mx);
    }

    void modify(const int& L, const int& R, const int& v, const int& p = 1, const int& l = 1, const int& r = n) {
        if(L <= l && r <= R) {
            nd[p].mx += v;
            nd[p].lazy += v;
            return ;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if(L <= mid) modify(L, R, v, p << 1, l, mid);
        if(mid < R) modify(L, R, v, p << 1 | 1, mid + 1, r);
        update(p);
    }

    int query(const int& L, const int& R, const int& p = 1, const int& l = 1, const int& r = n) {
        if(L <= l && r <= R) {
            return nd[p].mx;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if(L > mid) return query(L, R, rs(p), mid + 1, r);
        if(R <= mid) return query(L, R, ls(p), l, mid); 
        return max(query(L, R, p << 1, l, mid), query(L, R, p << 1 | 1, mid + 1, r));
    }

    #undef ls
    #undef rs
};

SegmentTree t2, t3, t5, t7;

int main()
{
    #if 0
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    n = read(); m = read();
    char type[10];
    for(int i = 1; i <= m; ++i) {
        scanf("%s", type);
        if(type[1] == 'U') {
            int l = read();
            int r = read();
            // int v = read();
            switch (read())
            {
            case 2:
                t2.modify(l, r, 1);
                break;
            case 3:
                t3.modify(l, r, 1);
                break;
            case 4:
                t2.modify(l, r, 2);
                break;
            case 5:
                t5.modify(l, r, 1);
                break;
            case 6:
                t2.modify(l, r, 1);
                t3.modify(l, r, 1);
                break;
            case 7:
                t7.modify(l, r, 1);
                break;
            case 8:
                t2.modify(l, r, 3);
                break;
            case 9:
                t3.modify(l, r, 2);
                break;
            case 10:
                t2.modify(l, r, 1);
                t5.modify(l, r, 1);
            }
        }
        else {
            int l = read();
            int r = read();
            printf("ANSWER %d\n", \
                max(t2.query(l, r), \
                max(t3.query(l, r), \
                max(t5.query(l, r), t7.query(l, r)))));
        }
    }
    return 0;
}
