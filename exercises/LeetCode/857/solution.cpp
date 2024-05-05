#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const int n = quality.size();
        vector<int> h(n, 0);
        iota(h.begin(), h.end(), 0);
        sort(h.begin(), h.end(), [&](int& a, int& b) {
            return quality[a] * wage[b] > quality[b] * wage[a];
        });
        priority_queue<int> q;
        double ans = 1e10;
        int tot_quality = 0;
        for (int i = 0; i < k - 1; ++i) {
            auto idx = h[i];
            tot_quality += quality[idx];
            q.push(quality[idx]);
        }
        for (int i = k - 1; i < n; ++i) {
            auto idx = h[i];
            tot_quality += quality[idx];
            q.push(quality[idx]);
            ans = min(ans, (double)wage[idx] / quality[idx] * tot_quality);
            tot_quality -= q.top();
            q.pop();
        }
        return ans;
    }
};