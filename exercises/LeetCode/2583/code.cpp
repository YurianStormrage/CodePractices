#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int rank = 0;
        vector<long long> ans;
        ans.reserve(30);
        queue<TreeNode*> q;
        q.emplace(root);
        ans.emplace_back(0);
        bool p = false;
        int cnt[2]{0, 1};
        while (!q.empty()) {
            const auto rt = q.front();
            q.pop();
            // cout << "rank = " << rank << ", root = " << rt->val << endl;
            ans[rank] += rt->val;
            if (rt->left) {
                q.emplace(rt->left);
                ++cnt[p];
            }
            if (rt->right) {
                q.emplace(rt->right);
                ++cnt[p];
            }
            if (--cnt[!p] == 0) {
                p ^= 1;
                ans.emplace_back(0);
                ++rank;
            }
        }
        if (k >= ans.size()) [[unlikely]] return -1;
        sort(ans.begin(), ans.end(), greater<long long>());
        return ans[k - 1];
    }
};
