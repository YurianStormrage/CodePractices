---
title: 找出所有稳定的二进制数组 I
difficulty: Medium
date: 2024-08-06 22:30:59
url: https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-i
tags:
    - 
---
# 3129. 找出所有稳定的二进制数组 I

## 描述

给你 3 个正整数 `zero` ，`one` 和 `limit` 。

一个 <span data-keyword="binary-array">二进制数组</span> `arr` 如果满足以下条件，那么我们称它是 **稳定的** ：

- 0 在 `arr` 中出现次数 **恰好** 为 ****`zero` 。
- 1 在 `arr` 中出现次数 **恰好** 为 `one` 。
- `arr` 中每个长度超过 `limit` 的 <span data-keyword="subarray-nonempty">子数组</span> 都 **同时** 包含 0 和 1 。

请你返回 **稳定** 二进制数组的 *总* 数目。

由于答案可能很大，将它对 $10^{9} + 7$ <b>取余</b> 后返回。

## 样例
### 示例 1：

<div class="example-block">
<span class="example-io"><b>输入：</b>zero = 1, one = 1, limit = 2</span>

<span class="example-io"><b>输出：</b>2</span>

**解释：**

两个稳定的二进制数组为 `[1,0]` 和 `[0,1]` ，两个数组都有一个 0 和一个 1 ，且没有子数组长度大于 2 。
</div>

### 示例 2：

<div class="example-block">
**输入：**<span class="example-io">zero = 1, one = 2, limit = 1</span>

<span class="example-io"><b>输出：</b>1</span>

**解释：**

唯一稳定的二进制数组是 `[1,0,1]` 。

二进制数组 `[1,1,0]` 和 `[0,1,1]` 都有长度为 2 且元素全都相同的子数组，所以它们不稳定。
</div>

### 示例 3：

<div class="example-block">
<span class="example-io"><b>输入：</b>zero = 3, one = 3, limit = 2</span>

<span class="example-io"><b>输出：</b>14</span>

**解释：**

所有稳定的二进制数组包括 `[0,0,1,0,1,1]` ，`[0,0,1,1,0,1]` ，`[0,1,0,0,1,1]` ，`[0,1,0,1,0,1]` ，`[0,1,0,1,1,0]` ，`[0,1,1,0,0,1]` ，`[0,1,1,0,1,0]` ，`[1,0,0,1,0,1]` ，`[1,0,0,1,1,0]` ，`[1,0,1,0,0,1]` ，`[1,0,1,0,1,0]` ，`[1,0,1,1,0,0]` ，`[1,1,0,0,1,0]` 和 `[1,1,0,1,0,0]` 。
</div>

## 限制

- `1 <= zero, one, limit <= 200`


## [思考](code.cpp)
