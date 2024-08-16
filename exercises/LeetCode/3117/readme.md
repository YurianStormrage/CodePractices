---
title: 划分数组得到最小的值之和
difficulty: Hard
date: 2024-08-16 20:47:42
url: https://leetcode.cn/problems/minimum-sum-of-values-by-dividing-array
tags:
    - DFS
---
# 3117. 划分数组得到最小的值之和

## 描述

给你两个数组 `nums` 和 `andValues`，长度分别为 `n` 和 `m`。

数组的 **值** 等于该数组的 **最后一个** 元素。

你需要将 `nums` 划分为 `m` 个 **不相交的连续** <span data-keyword="subarray-nonempty">子数组</span>，对于第 $i^{th}$ 个子数组 $[l_{i}, r_{i}]$，子数组元素的按位 `AND` 运算结果等于 `andValues[i]`，换句话说，对所有的 `1 <= i <= m`，$nums[l_{i}] &amp; nums[l_{i} + 1] &amp; ... &amp; nums[r_{i}] == andValues[i]$ ，其中 `&amp;` 表示按位 `AND` 运算符。

返回将 `nums` 划分为 `m` 个子数组所能得到的可能的 **最小** 子数组 **值** 之和。如果无法完成这样的划分，则返回 `-1` 。

## 样例
### 示例 1：

<div class="example-block">
**输入：** <span class="example-io">nums = [1,4,3,3,2], andValues = [0,3,3,2]</span>

**输出：** <span class="example-io">12</span>

**解释：**

唯一可能的划分方法为：

<ol>
- `[1,4]` 因为 `1 &amp; 4 == 0`
- `[3]` 因为单元素子数组的按位 `AND` 结果就是该元素本身
- `[3]` 因为单元素子数组的按位 `AND` 结果就是该元素本身
- `[2]` 因为单元素子数组的按位 `AND` 结果就是该元素本身
</ol>

这些子数组的值之和为 `4 + 3 + 3 + 2 = 12`
</div>

### 示例 2：

<div class="example-block">
**输入：** <span class="example-io">nums = [2,3,5,7,7,7,5], andValues = [0,7,5]</span>

**输出：** <span class="example-io">17</span>

**解释：**

划分 `nums` 的三种方式为：

<ol>
- `[[2,3,5],[7,7,7],[5]]` 其中子数组的值之和为 `5 + 7 + 5 = 17`
- `[[2,3,5,7],[7,7],[5]]` 其中子数组的值之和为 `7 + 7 + 5 = 19`
- `[[2,3,5,7,7],[7],[5]]` 其中子数组的值之和为 `7 + 7 + 5 = 19`
</ol>

子数组值之和的最小可能值为 `17`
</div>

### 示例 3：

<div class="example-block">
**输入：** <span class="example-io">nums = [1,2,3,4], andValues = [2]</span>

**输出：** <span class="example-io">-1</span>

**解释：**

整个数组 `nums` 的按位 `AND` 结果为 `0`。由于无法将 `nums` 划分为单个子数组使得元素的按位 `AND` 结果为 `2`，因此返回 `-1`。
</div>

## 限制

- $1 \le n == nums.length \le 10^{4}$
- `1 <= m == andValues.length <= min(n, 10)`
- $1 \le nums[i] < 10^{5}$
- $0 \le andValues[j] < 10^{5}$


## [思考](code.cpp)

感觉是dp，但是没什么太好的想法。搓了个暴力t了。复杂度$O(mn^2)$

## [题解](solution.cpp)

记忆化搜索：

编写子函数 `dfs(i,j,cur)`。

其中每个状态包含三个变量，`i` 为 `nums` 中下一个元素，`j` 为 `andValues` 中下一个匹配元素，`cur` 为当前子数组元素的按位与运算结果。

在每一次搜索中，计算更新 `cur`。

- 如果当前 `cur` 小于 `andValues[j]`，则匹配失败。
- 如果当前 `cur` 大于 `andValues[j]`，则还需继续进行与运算，进入下一轮搜索。
- 如果当前 `cur` 等于 `andValues[j]`，可以继续进行与运算，也可以开始匹配 `andValues[j+1]`。

每次搜索，我们返回找到的最小值，并存入记忆化搜索的数组中，以避免重复计算。

最后在主程序中调用，返回可能的最小子数组值之和。如果无法完成这样的划分，则返回 `−1`。

复杂度 $O(nmlogV)$，其中 $V$ 是数组 `nums` 的最大值。

### Notes

**关于复杂度为什么不是O(nmV):**

> 想了很久终于明白了时间复杂度是logV，对于cur这个维度，例如最大数是111111，那么在此维度里，最多只能有6种情况，经过前面的&计算去掉这六个中的某一个或者几个，可能的情况就是把这个数和前面的数依次&计算，所以就算一次只剪掉一个1，也就是最多6次，不可能同时有110011和111100这样的情况

