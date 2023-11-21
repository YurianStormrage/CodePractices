---
title: 2216. 美化数组的最少删除数
difficulty: 中等
date: 2023-11-21
url: https://leetcode.cn/problems/minimum-deletions-to-make-array-beautiful/
tags:
    - Greedy
---
# [2216. 美化数组的最少删除数](https://leetcode.cn/problems/minimum-deletions-to-make-array-beautiful/)

## 描述

给你一个下标从 **0** 开始的整数数组 `nums` ，如果满足下述条件，则认为数组 `nums` 是一个 **美丽数组** ：

- `nums.length` 为偶数
- 对所有满足 `i % 2 == 0` 的下标 `i` ，`nums[i] != nums[i + 1]` 均成立

注意，空数组同样认为是美丽数组。

你可以从 `nums` 中删除任意数量的元素。当你删除一个元素时，被删除元素右侧的所有元素将会向左移动一个单位以填补空缺，而左侧的元素将会保持 **不变** 。

返回使 `nums` 变为美丽数组所需删除的 **最少** 元素数目。

## 样例 

### 示例 1：
```
输入：nums = [1,1,2,3,5]
输出：1
解释：可以删除 nums[0] 或 nums[1] ，这样得到的 nums = [1,2,3,5] 是一个美丽数组。可以证明，要想使 nums 变为美丽数组，至少需要删除 1 个元素。
```

### 示例 2：
```
输入：nums = [1,1,2,2,3,3]
输出：2
解释：可以删除 nums[0] 和 nums[5] ，这样得到的 nums = [1,2,2,3] 是一个美丽数组。可以证明，要想使 nums 变为美丽数组，至少需要删除 2 个元素。
```

## 限制

$1 \le nums.length \le 10^5$

$0 \le nums[i] \le 10^5$

## [思考](./code.cpp)
### 思路一
每个元素都必须被保留或删除

已经确定的偶数长度子序列没有后效性

设状态$(i, a, b), i \in [1, n], a \in [0, 10^5], b \in {0, 1}$

映射$f(i,a,b)$表示到第`i`个元素，保留的最后一个元素为`a`，子序列长度`len`满足`len % 2 = b`的最少删除量。

则
$$
f(i, nums[i], 1) = \min(\min_k f(i-1, k, 0),\ \min_k f(i-1,k,1)+1) \\
f(i, nums[i], 0) = \min(f(i-1,nums[i],0)+1,\min_{k \ne nums[i]}{f(i-1, k, 1)}) \\
f(i,a,b)=f(i-1,a,b),a\ne nums[i]
$$
其中 $k\in{\{nums[j]\ |\ j=0,\cdots,i-1\}}$。

边界条件
$$
f(0,nums[0],1) = 0 \\
f(0,nums[0],0) = inf \\
f(0,a,b) = inf, a \ne nums[0]
$$

> ~~考虑优化，令$g(i,a)=\min_{k \ne a}f(i, k, 1)$，$ans(i,b)=\min_k f(i,k,b)$，则：~~
> $$
> g(i,nums[i])=g(i-1,nums[i])+1 \\
> g(i,a)=g(i-1,a),a\ne nums[i]
> $$
> 
> 复杂度$O(N)$
> 
> **错误思路**：$g(i,a)$的转移方程应为：
> $$
> g(i,a)=\min(ans(i-1,0), g(i,a)+1),a \ne nums[i]
> $$
> 无法实现优化，仍然需要使用数据结构维护 $\min_k f(i,k,0/1)$，导致复杂度达到$O(NlogN)$。

### 思路二
考虑贪心

每次贪心取队首和其后第一个不相等的数，若之后没有不相等的数则全部删除。

讨论：

1. n < 2 时，$ans = n$；
2. n = 2 时，设数组为 `a b`，则 $ans=2\times[a=b]$；
3. n = 3 时，考虑以下情况：\
   1. `a a a`，等价于只取第一个`a`；
   2. `a a b`，等价于取第一个`a`和`b`
   3. `a b a`
   4. `a b b`
   5. `a b c`\
   3 ~ 5均等价于最小子问题`a b`+子问题`a ...`

###### 小结/吐槽
又被智商题卡了......