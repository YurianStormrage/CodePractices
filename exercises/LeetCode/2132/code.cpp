#include <bits/stdc++.h>
using namespace std;

template<int N>
struct SegmentTree {
    struct Segment {
        int min = 0;
        int lazy = 0;
        bool has_zero = true;
    };
    /// error 5: 线段树额外空间问题
    // static constexpr int capacity = N << 1;
    static constexpr int capacity = N << 2;
    Segment tree[capacity]{};
    int size;
    int h;
    void Flush(int id) {
        if (id >= capacity || !tree[id].lazy) return;
        auto update = [&](auto& fa, auto& ch) {
            if (fa.lazy == -1) {
                ch.lazy = -1;
                ch.min = 0;
                ch.has_zero = true;
            } else {
                ch.lazy = ch.lazy == -1 ? fa.lazy : ch.lazy + fa.lazy;
                ch.min += fa.lazy;
                ch.has_zero = false;
            }
        };
        if (id << 1 < capacity) update(tree[id], tree[id << 1]);
        if (id << 1 | 1 < capacity) update(tree[id], tree[id << 1 | 1]);
        tree[id].lazy = 0;
    }
    void Update(int id) {
        // if (tree[id << 1].min == 0 || tree[id << 1].min > tree[id << 1 | 1].min)
        /// error 3: 右节点最小值为0时，左节点也会大于右节点
        if (tree[id << 1].min == 0)
            tree[id].min = tree[id << 1 | 1].min;
        else if (tree[id << 1 | 1].min == 0)
            tree[id].min = tree[id << 1].min;
        else
            tree[id].min = min(tree[id << 1].min, tree[id << 1 | 1].min);
        tree[id].has_zero = tree[id << 1].has_zero || tree[id << 1 | 1].has_zero;
    }
    void Add(int L, int R, int v) noexcept {
        auto add = [&](auto&& self, int l, int r, int id = 1) {
            if (R < l || r < L) return;
            Flush(id);
            if (L <= l && r <= R) {
                /// error 4: 0变1会成为新的最小值
                tree[id].lazy = v;
                tree[id].min = tree[id].has_zero ? 1 : tree[id].min + v;
                tree[id].has_zero = false;
                return;
            }
            self(self, l, (l + r) >> 1, id << 1);
            self(self, ((l + r) >> 1) + 1, r, id << 1 | 1);
            Update(id);
        };
        add(add, 0, size - 1);
    }
    auto QueryAndModify(int L, int R) {
        auto query = [&](auto&& self, int l, int r, int id = 1) {
            if (R < l || r < L) return true;
            bool rc;
            if (L <= l && r <= R) {
                rc = !tree[id].min || tree[id].min >= h;
                tree[id].min = 0;
                tree[id].lazy = -1;
                tree[id].has_zero = true;
                return rc;
            }
            Flush(id);
            rc = self(self, l, (l + r) >> 1, id << 1);
            rc &= self(self, ((l + r) >> 1)+ 1, r, id << 1 | 1);
            Update(id);
            return rc;
        };
        return query(query, 0, size - 1);
    }
};
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        constexpr int N = 1e5;
        SegmentTree<N> tree;
        tree.h = stampHeight;
        int n = grid.size(), m = grid[0].size();
        tree.size = m;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = 0;
            while (r < m) {
                if (grid[i][r] == 0) {
                    while (r < m && grid[i][r] == 0) ++r;
                    if (r - l < stampWidth) /// error 1: 忘了判断
                        return false;
                    tree.Add(l, r - 1, 1);
                }
                else {
                    while (r < m && grid[i][r] == 1) ++r;
                    if (tree.QueryAndModify(l, r - 1) == false)
                        return false;
                }
                l = r;
            }
        }
        return tree.QueryAndModify(0, m - 1); /// error 2: 直接返回了true
    }
};

int main() {
    struct Test : Solution {
        vector<int> nums;
        int target;
        void run() {
        }
    };

    return 0;
}