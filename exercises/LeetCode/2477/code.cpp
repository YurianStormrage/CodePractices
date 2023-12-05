#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> edge;
    int seats;
    int ans = 0;
    int dfs(int u, int p) {
        int cnt = 1;
        for (auto v : edge[u]) {
            if (v == p)
                continue;
            cnt += dfs(v, u);
        }
        if (u != p)
            ans += (cnt + seats - 1) / seats;
        return cnt;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        this->seats = seats;
        edge.resize(roads.size() + 1);
        for (auto& road : roads) {
            edge[road[0]].push_back(road[1]);
            edge[road[1]].push_back(road[0]);
        }
        dfs(0, 0);
        return ans;
    }
};

int main() {
    struct Test : Solution {
        vector<vector<int>> roads;
        int seats;
        void run() {
            auto ans = minimumFuelCost(roads, seats);
            cout << ans << endl;
        }
    };

    Test t1 {
        .roads = {{0,1},{0,2},{0,3}},
        .seats = 5
    };
    Test t2 {
        .roads = {{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}},
        .seats = 2
    };
    Test t3 {
        .roads = {},
        .seats = 1
    };

    t1.run();
    t2.run();
    t3.run();

    return 0;
}