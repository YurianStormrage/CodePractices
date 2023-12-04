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
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
    int dfs(TreeNode* rt, int sum) {
        if (!rt) return 0;
        rt->val += dfs(rt->right, sum) + sum;
        return dfs(rt->left, rt->val) + rt->val - sum;
    }
};

/**
 * Reverse Inorder Traversal
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution_less_space {
    int sum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return nullptr;
        bstToGst(root->right);
        root->val = sum += root->val;
        bstToGst(root->left);
        return root;
    }
};

/**
 * Morris Traversal
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 反序中序遍历:
 * 1. 如果当前节点的右子节点为空，处理当前节点，并遍历当前节点的左子节点；
 * 2. 如果当前节点的右子节点不为空，找到当前节点右子树的最左节点（该节点为当前节点中序遍历的前驱节点）；
 *  - 如果最左节点的左指针为空，将最左节点的左指针指向当前节点，遍历当前节点的右子节点；
 *  - 如果最左节点的左指针不为空，将最左节点的左指针重新置为空（恢复树的原状），处理当前节点，并将当前节点置为其左节点；
 * 3. 重复步骤 1 和步骤 2，直到遍历结束。
 */
class Solution_Morris {
public:
    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* succ = node->right;
        while (succ->left != nullptr && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;

        while (node != nullptr) {
            if (node->right == nullptr) {
                sum += node->val;
                node->val = sum;
                node = node->left;
            } else {
                TreeNode* succ = getSuccessor(node);
                if (succ->left == nullptr) {
                    succ->left = node;
                    node = node->right;
                } else {
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }

        return root;
    }
};
