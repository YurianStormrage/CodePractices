#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int hd[n], to[connections.size() << 1], nxt[connections.size() << 1], tot = 0;
        memset(hd, 0xff, sizeof(hd));
        auto addedge = [&](int u, int v) {
            nxt[tot] = hd[u]; hd[u] = tot; to[tot++] = v;
            nxt[tot] = hd[v]; hd[v] = tot; to[tot++] = u;
        };
        for (auto& conn : connections) {
            addedge(conn[0], conn[1]);
        }
        int h[n];
        memset(h, 0xff, sizeof(h));
        int queue[n], head = 0, tail = 0;
        queue[tail++] = 0;
        h[0] = 0;
        while (head < tail) {
            int u = queue[head++];
            for (int i = hd[u]; ~i; i = nxt[i]) {
                int v = to[i];
                if (~h[v]) [[unlikely]]
                    continue;
                h[v] = h[u] + 1;
                queue[tail++] = v;
            }
        }
        int ans = 0;
        for (auto& conn : connections)
            if (h[conn[0]] < h[conn[1]])
                ++ans;
        return ans;
    }
};