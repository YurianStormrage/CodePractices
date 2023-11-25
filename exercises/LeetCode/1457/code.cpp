#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    using Node = TreeNode*;
    #define v(x) ((x)->val)
    #define l(x) ((x)->left)
    #define r(x) ((x)->right)
    int pseudoPalindromicPaths (Node rt) {
        static bitset<10> num;
        if (NULL == rt) return 0;
        num.flip(v(rt));
        int res;
        if (!l(rt) && !r(rt))
            res = num.count() <= 1;
        else
            res = pseudoPalindromicPaths(l(rt)) +
                  pseudoPalindromicPaths(r(rt));
        num.flip(v(rt));
        return res;
    }
    #undef v
    #undef l
    #undef r
// private:
//     int size(Node rt) {
//         if (NULL == rt) return 0;
//         return 1 + size(l(rt)) + size(r(rt));
//     }
//     int dfs(Node rt, Node fa, Node gf) {
//         if (NULL == rt) return 0;
//         if (fa && v(rt) == v(fa)) return size(rt);
//         if (gf && v(rt) == v(gf)) return size(rt);
//         return dfs(l(rt), rt, fa) +
//                dfs(r(rt), rt, fa);
//     }
};