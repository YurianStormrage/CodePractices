---
title: 二叉树中的第 K 大层和
difficulty: Medium
date: 2024-02-23 17:23:44
url: https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree
tags:
    - BFS
---
# 2583. 二叉树中的第 K 大层和

## 描述

给你一棵二叉树的根节点 `root` 和一个正整数 `k` 。

树中的 **层和** 是指 **同一层** 上节点值的总和。

返回树中第 `k` 大的层和（不一定不同）。如果树少于 `k` 层，则返回 `-1` 。

**注意**，如果两个节点与根节点的距离相同，则认为它们在同一层。

## 样例
### 示例 1

<img alt="" src="https://assets.leetcode.com/uploads/2022/12/14/binaryytreeedrawio-2.png" style="width: 301px; height: 284px;" />

```
输入：root = [5,8,9,2,1,3,7,4,6], k = 2
输出：13
解释：树中每一层的层和分别是：
- Level 1: 5
- Level 2: 8 + 9 = 17
- Level 3: 2 + 1 + 3 + 7 = 13
- Level 4: 4 + 6 = 10
第 2 大的层和等于 13 。
```

### 示例 2

<img alt="" src="https://assets.leetcode.com/uploads/2022/12/14/treedrawio-3.png" style="width: 181px; height: 181px;" />

```
输入：root = [1,2,null,3], k = 1
输出：3
解释：最大的层和是 3 。
```

## 限制

- 树中的节点数为 `n`
- $2 \le n \le 10^{5}$
- $1 \le Node.val \le 10^{6}$
- `1 <= k <= n`


## [思考](code.cpp)
总体简单，写个BFS即可。

但是在BFS中分隔每层的实现，写得不好。
直观思路是：
- 记录上一层和当前层的节点数。
  - 出队时，上层节点数减一；
  - 入队时，该层节点数加一。
- 当上一层节点数为 0 时，可知上一层遍历完成。

该实现较繁琐且引入了不必要的计数操作。

## [题解](solution.cpp)
BFS中使用两层循环。
第一层循环表示枚举每层，第二层循环表示枚举该层的每个节点。

实际上，每次第一层循环开始时，队列中存在的节点即为该层的所有节点，不需要计数。
此时队列大小即为该层节点数。