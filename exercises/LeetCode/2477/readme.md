---
title: 到达首都的最少油耗
difficulty: Medium
date: 2023-12-05 23:19:05
url: https://leetcode-cn.com/problems/minimum-fuel-cost-to-report-to-the-capital
tags:
    - DFS
    - 邻接表
---
# 2477. 到达首都的最少油耗

## 描述

给你一棵 `n` 个节点的树（一个无向、连通、无环图），每个节点表示一个城市，编号从 `0` 到 `n - 1` ，且恰好有 `n - 1` 条路。`0` 是首都。给你一个二维整数数组 `roads` ，其中 $roads[i] = [a_{i}, b_{i}]$ ，表示城市 $a_{i}$ 和 $b_{i}$ 之间有一条 **双向路** 。

每个城市里有一个代表，他们都要去首都参加一个会议。

每座城市里有一辆车。给你一个整数 `seats` 表示每辆车里面座位的数目。

城市里的代表可以选择乘坐所在城市的车，或者乘坐其他城市的车。相邻城市之间一辆车的油耗是一升汽油。

请你返回到达首都最少需要多少升汽油。
## 样例
### 示例 1

<img alt="" src="https://assets.leetcode.com/uploads/2022/09/22/a4c380025e3ff0c379525e96a7d63a3.png" style="width: 303px; height: 332px;">

```
输入：roads = [[0,1],[0,2],[0,3]], seats = 5
输出：3
解释：
- 代表 1 直接到达首都，消耗 1 升汽油。
- 代表 2 直接到达首都，消耗 1 升汽油。
- 代表 3 直接到达首都，消耗 1 升汽油。
最少消耗 3 升汽油。
```

### 示例 2

<img alt="" src="https://assets.leetcode.com/uploads/2022/11/16/2.png" style="width: 274px; height: 340px;">

```
输入：roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
输出：7
解释：
- 代表 2 到达城市 3 ，消耗 1 升汽油。
- 代表 2 和代表 3 一起到达城市 1 ，消耗 1 升汽油。
- 代表 2 和代表 3 一起到达首都，消耗 1 升汽油。
- 代表 1 直接到达首都，消耗 1 升汽油。
- 代表 5 直接到达首都，消耗 1 升汽油。
- 代表 6 到达城市 4 ，消耗 1 升汽油。
- 代表 4 和代表 6 一起到达首都，消耗 1 升汽油。
最少消耗 7 升汽油。
```

### 示例 3

<img alt="" src="https://assets.leetcode.com/uploads/2022/09/27/efcf7f7be6830b8763639cfd01b690a.png" style="width: 108px; height: 86px;">

```
输入：roads = [], seats = 1
输出：0
解释：没有代表需要从别的城市到达首都。
```
## 限制
- $1 <= n <= 10^{5}$
- `roads.length == n - 1`
- `roads[i].length == 2`
- $0 <= a_{i}, b_{i} < n$
- $a_{i} != b_{i}$
- `roads` 表示一棵合法的树。
- $1 <= seats <= 10^{5}$


## [思考](code.cpp)
重新建邻接表，跑DFS。

设`size(u)`表示以`u`为根节点的子树大小；设`u`为`v`的父节点，则边`(u,v)`的贡献为$\lceil \frac{size(v)}{seats}\rceil$。

DFS统计各子树大小并同时计算答案即可