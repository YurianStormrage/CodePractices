---
title: first-completely-painted-row-or-column
difficulty: Medium
date: 2023-12-01 22:35:01
url: https://leetcode.cn/problems/first-completely-painted-row-or-column/
tags:
    - Hash
---
# [2661. 找出叠涂元素](https://leetcode.cn/problems/first-completely-painted-row-or-column/)
## 描述
给你一个下标从 **0** 开始的整数数组 ``arr`` 和一个 ``m x n`` 的整数 **矩阵** ``mat`` 。``arr`` 和 ``mat`` 都包含范围 ``[1，m * n]`` 内的 **所有** 整数。

从下标 ``0`` 开始遍历 ``arr`` 中的每个下标 ``i`` ，并将包含整数 ``arr[i]`` 的 ``mat`` 单元格涂色。

请你找出 ``arr`` 中在 ``mat`` 的某一行或某一列上都被涂色且下标最小的元素，并返回其下标 ``i`` 。


## 样例
### 示例 1：
<img alt="image explanation for example 1" src="https://assets.leetcode.com/uploads/2023/01/18/grid1.jpg" style="width: 321px; height: 81px;" />

```
输入：arr = [1,3,4,2], mat = [[1,4],[2,3]]
输出：2
解释：遍历如上图所示，arr[2] 在矩阵中的第一行或第二列上都被涂色。
```

### 示例 2：
<img alt="image explanation for example 2" src="https://assets.leetcode.com/uploads/2023/01/18/grid2.jpg" style="width: 601px; height: 121px;" />

```
输入：arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
输出：3
解释：遍历如上图所示，arr[3] 在矩阵中的第二列上都被涂色。
```


## 限制


- ``m == mat.length``
- ``n = mat[i].length``
- ``arr.length == m * n``
- <code>1 <= m, n <= 10<sup>5</sup></code>
- <code>1 <= m * n <= 10<sup>5</sup></code>
- ``1 <= arr[i], mat[r][c] <= m * n``
- ``arr`` 中的所有整数 **互不相同**
- ``mat`` 中的所有整数 **互不相同**


## [思考](./code.cpp)
建立值->坐标的hash关系

遍历`arr`时记录每行每列的染色个数

若某次染色后行或列的染色个数等于`n`或`m`则返回当前下标

可知必有解

复杂度$O(NM)$