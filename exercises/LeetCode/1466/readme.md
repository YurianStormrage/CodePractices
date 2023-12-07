---
title: 重新规划路线
difficulty: Medium
date: 2023-12-07 16:59:50
url: https://leetcode-cn.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
tags:
    - Search
---
# 1466. 重新规划路线

## 描述

`n` 座城市，从 `0` 到 `n-1` 编号，其间共有 `n-1` 条路线。因此，要想在两座不同城市之间旅行只有唯一一条路线可供选择（路线网形成一颗树）。去年，交通运输部决定重新规划路线，以改变交通拥堵的状况。

路线用 `connections` 表示，其中 `connections[i] = [a, b]` 表示从城市 `a` 到 `b` 的一条有向路线。

今年，城市 0 将会举办一场大型比赛，很多游客都想前往城市 0 。

请你帮助重新规划路线方向，使每个城市都可以访问城市 0 。返回需要变更方向的最小路线数。

题目数据 **保证** 每个城市在重新规划路线方向后都能到达城市 0 。

## 样例
### 示例 1

**<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/30/sample_1_1819.png" style="height: 150px; width: 240px;">**

```
输入：n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
输出：3
解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 
```

### 示例 2

**<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/30/sample_2_1819.png" style="height: 60px; width: 380px;">**

```
输入：n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
输出：2
解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 
```

### 示例 3

```
输入：n = 3, connections = [[1,0],[2,0]]
输出：0
```

## 限制

- `2 <= n <= 5 * 10^4`
- `connections.length == n-1`
- `connections[i].length == 2`
- `0 <= connections[i][0], connections[i][1] <= n-1`
- `connections[i][0] != connections[i][1]`


## [思考](code.cpp)
搜索

统计每个节点的深度

对于每条原有的单向边，若其起点深度小于终点，则答案+1。

## 题解
另一种思路

建图时可以加上边权

原有的单向边边权为 0，额外的反向边边权为 1。DFS统计所有边权和即可。