#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        constexpr int N = 52, M = N - 1;
        int m = edges.size() + 1;
        int hd[n], to[m << 1], nxt[m << 1], tot = 0;
        memset(hd, 0xff, sizeof(hd));
        auto addedge = [&](int u, int v) {
            nxt[tot] = hd[u]; hd[u] = tot; to[tot++] = v;
            nxt[tot] = hd[v]; hd[v] = tot; to[tot++] = u;
        };
        for (auto& edge : edges) {
            addedge(edge[0], edge[1]);
        }
        int fa[n], h[n], now = 0;
        function<void(int,int)> dfs = [&](int u, int p) {
            fa[u] = p;
            h[u] = now++;
            for (int i = hd[u]; ~i; i = nxt[i]) {
                int v = to[i];
                if (v == p) [[unlikely]]
                    continue;
                dfs(v, u);
            }
            --now;
        };
        dfs(0, 0);
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        for (auto& trip : trips) {
            int u = trip[0];
            int v = trip[1];
            if (h[u] < h[v])
                u ^= v ^= u ^= v;
            // cout << "x = " << u << endl;
            // cout << "y = " << v << endl;
            while (h[u] > h[v]) {
                ++cnt[u];
                u = fa[u];
                // cout << "u = " << u << endl;
                // cout << "v = " << v << endl;
            }
            while (u != v) {
                ++cnt[u];
                ++cnt[v];
                u = fa[u];
                v = fa[v];
                // cout << "u = " << u << endl;
                // cout << "v = " << v << endl;
            }
            ++cnt[v];
        }
        // for (int i = 0; i < n; ++i) {
        //     cout << cnt[i] << endl;
        // }
        // int ans[2] = {0};
        // for (int i = 0; i < n; ++i) {
        //     ans[h[i] & 1] += cnt[i] * price[i];
        // }
        // return min((ans[0] >> 1) + ans[1], ans[0] + (ans[1] >> 1));
        int mem[n][2];
        memset(mem, 0xff, sizeof(mem));
        function<int(int, int, bool)> search_ans = [&](int u, int p, bool flag) {
            if (~mem[u][flag]) return mem[u][flag];
            int res = cnt[u] * price[u] >> flag;
            if(!flag) {
                for (int i = hd[u]; ~i; i = nxt[i]) {
                    int v = to[i];
                    if (v == p) [[unlikely]]
                        continue;
                    res += min(search_ans(v, u, 0), search_ans(v, u, 1));
                }
            }
            else {
                for (int i = hd[u]; ~i; i = nxt[i]) {
                    int v = to[i];
                    if (v == p) [[unlikely]]
                        continue;
                    res += search_ans(v, u, 0);
                }
            }
            return mem[u][flag] = res;
        };
        return min(search_ans(0, 0, 0), search_ans(0, 0, 1));
    }
};

int main() {
    struct Test : Solution {
        int n;
        vector<vector<int>> edges;
        vector<int> price;
        vector<vector<int>> trips;
        void run() {
            auto ans = minimumTotalPrice(n, edges, price, trips);
            cout << ans << endl;
        }
    };

    Test t1 {
        .n = 4,
        .edges = {{0,1},{1,2},{1,3}},
        .price = {2,2,10,6},
        .trips = {{0,3},{2,1},{2,3}}
    };
    Test t2 {
        .n = 2,
        .edges = {{0,1}},
        .price = {2,2},
        .trips = {{0,0}}
    };

    t1.run();
    t2.run();

    return 0;
}