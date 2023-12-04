---
title: binary-search-tree-to-greater-sum-tree
difficulty: Medium
date: 2023-12-04 09:10:25
url: https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/
tags:
    - 二叉树
    - DFS
    - Morris遍历
---
# [1038. 从二叉搜索树到更大和树](https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/)
## 描述
给定一个二叉搜索树``root`` (BST)，请将它的每个节点的值替换成树中大于或者等于该节点值的所有值之和。

提醒一下， *二叉搜索树* 满足下列约束条件：


- 节点的左子树仅包含键 **小于** 节点键的节点。
- 节点的右子树仅包含键 **大于** 节点键的节点。
- 左右子树也必须是二叉搜索树。


## 样例
### 示例 1：

**<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/05/03/tree.png" style="height:273px; width:400px" />**

```
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

### 示例 2：

```
输入：root = [0,null,1]
输出：[1,null,1]
```


## 限制


- 树中的节点数在 ``[1, 100]`` 范围内。
- ``0 <= Node.val <= 100``
- 树中的所有值均 **不重复** 。



**注意**：该题目与 538: <a href="https://leetcode-cn.com/problems/convert-bst-to-greater-tree/">https://leetcode-cn.com/problems/convert-bst-to-greater-tree/  </a>相同

## [思考](./code.cpp)
