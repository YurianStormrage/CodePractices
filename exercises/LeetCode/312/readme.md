---
title: 戳气球
difficulty: Hard
date: 2024-07-31 22:32:44
url: https://leetcode.cn/problems/burst-balloons
tags:
    - DP
---
# 312. 戳气球

## 描述

有 `n` 个气球，编号为`0` 到 `n - 1`，每个气球上都标有一个数字，这些数字存在数组 `nums` 中。

现在要求你戳破所有的气球。戳破第 `i` 个气球，你可以获得 `nums[i - 1] * nums[i] * nums[i + 1]` 枚硬币。 这里的 `i - 1` 和 `i + 1` 代表和 `i` 相邻的两个气球的序号。如果 `i - 1`或 `i + 1` 超出了数组的边界，那么就当它是一个数字为 `1` 的气球。

求所能获得硬币的最大数量。

## 样例
### 示例 1

```
输入：nums = [3,1,5,8]
输出：167
解释：
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
```

### 示例 2

```
输入：nums = [1,5]
输出：10
```

## 限制

- `n == nums.length`
- `1 <= n <= 300`
- `0 <= nums[i] <= 100`


## 思考

一直想着怎么把状态`(i, j)`用`(i, k - 1)`和`(k + 1, j)`来表示，
想法一直是首先使用`k`，然后计算剩余的子状态能提供的最大价值。

正确的思路应该是反向思考：保留`k`，即最后使用`k`，
可以顺畅地写出转移方程。

## [题解](solution.cpp)

[leetcode题解](https://leetcode.cn/problems/burst-balloons/solutions/336390/chuo-qi-qiu-by-leetcode-solution/)
