/* 95pt
 * 最后一个点 0 0 81795575 64
 * 没有特判，计算不了2^64
 * 并且算法实现有些冗余
 */

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f ? x : -x;
}

const int N = 1e6 + 2, M = 1e6 + 2;
const int V = N + 100, E = M << 1;

int n, m, c, k;
ll animals;

pair<int, int> Edge[M];
int to[E], hd[V], nxt[E], tot;
inline void addedge(const int& u, const int& v)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;
    //nxt[++tot] = hd[v]; hd[v] = tot; to[tot] = u;
}

ll allAnimals, answer;

bool vis[64];
// void dfs(int fa, int u)
// {
//     if(u < k) {
//         allAnimals |= 1 << u;
//         if(vis[u] || !(animals & (1 << u))) return ;
//         vis[u] = 1;
//         for(int i = hd[u], v; i; i = nxt[i]) {
//             v = to[i];
//             if(v == fa) continue;
//             dfs(u, v);
//         }
//     }
//     else {
//         for(int i = hd[u], v; i; i = nxt[i]) {
//             v = to[i];
//             if(vis[v]) continue;
//             dfs(u, v);
//         }
//     }
// }

ll calculateNumber(ll animals)
{
    ll result = 1;
    while(animals) {
        if(animals & 1) result <<= 1;
        animals >>= 1;
    }
    return result;
}

// void watch(ll animals)
// {
//     bool res[64] = {0};
//     int i = 0;
//     for(; animals; ++i) {
//         res[i] = animals & 1;
//         animals >>= 1;
//     }
//     for(int j = i - 1; j >= 0; --j) putchar(48 + res[j]);
//     puts("");
// }

int main()
{
    // freopen("zoo3.in", "r", stdin);
    // freopen("zoo3.out", "w", stdout);
    n = read(); m = read();
    c = read(); k = read();
    for(int i = 0; i < n; ++i) {
        animals |= read();
    }

    // watch(animals);

    for(int i = 0; i < m; ++i) {
        Edge[i].second = read();
        Edge[i].first = read();
    }
    sort(Edge, Edge + m);

    int cnt = k;
    for(int i = 0, j = 0; i < m; ++i) {
        if(i == m - 1) {
            if(Edge[i].first == Edge[j].first)
                for(; j <= i; ++j)
                    Edge[j].first = cnt;
            else {
                for(; j < i; ++j)
                    Edge[j].first = cnt;
                Edge[i].first = ++cnt;
            }
            break;
        }
        if(Edge[i].first == Edge[j].first) continue;
        for(; j < i; ++j)
            Edge[j].first = cnt;
        ++ cnt;
    }
    
    for(int i = 0; i < m; ++i) {
        addedge(Edge[i].first, Edge[i].second);
    }

    allAnimals = ((1LL << (k - 1)) - 1) | 1LL << (k - 1);
    int stack[64] = {0}, top = -1;
    for(int u = k; u <= cnt; ++u) {
        bool flag = 0;
        for(int i = hd[u]; i; i = nxt[i]) {
            int v = to[i];
            if(animals & (1LL << v)) flag = 1;
            if(!vis[v]) stack[++top] = v;
        }
        if(flag)
            while(top >= 0) {
                int t = stack[top--];
                vis[t] = 1;
            }
        else 
            while(top >= 0) {
                int t = stack[top--];
                allAnimals &= ~(1LL << t);
            }
        // watch(allAnimals);
    }

    for(int i = 0; i < k; ++i)
        if(vis[i])
            allAnimals |= 1LL << i;

    // watch(allAnimals);

    answer = calculateNumber(allAnimals) - n;

    printf("%lld", answer);

    return 0;
}