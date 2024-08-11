---
title: 不相交的线
difficulty: Medium
date: 2024-08-11 22:29:48
url: https://leetcode.cn/problems/uncrossed-lines
tags:
    - 
---
# 1035. 不相交的线

## 描述

在两条独立的水平线上按给定的顺序写下 `nums1` 和 `nums2` 中的整数。

现在，可以绘制一些连接两个数字 `nums1[i]` 和 `nums2[j]` 的直线，这些直线需要同时满足：

-  `nums1[i] == nums2[j]`
- 且绘制的直线不与任何其他连线（非水平线）相交。

请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。

以这种方法绘制线条，并返回可以绘制的最大连线数。

## 样例
### 示例 1
<img alt="" src="https://assets.leetcode.com/uploads/2019/04/26/142.png" style="width: 400px; height: 286px;" />

```
输入：nums1 = <span id="example-input-1-1">[1,4,2]</span>, nums2 = <span id="example-input-1-2">[1,2,4]</span>
输出：<span id="example-output-1">2</span>
解释：可以画出两条不交叉的线，如上图所示。 
但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4 的直线将与从 nums1[2]=2 到 nums2[1]=2 的直线相交。
```

<div>
### 示例 2

```
输入：nums1 = <span id="example-input-2-1">[2,5,1,2,5]</span>, nums2 = <span id="example-input-2-2">[10,5,2,1,5,2]</span>
输出：<span id="example-output-2">3</span>
```

<div>
### 示例 3

```
输入：nums1 = <span id="example-input-3-1">[1,3,7,1,7,5]</span>, nums2 = <span id="example-input-3-2">[1,9,2,5,1]</span>
输出：<span id="example-output-3">2</span>
```

</div>
</div>

## 限制

- `1 <= nums1.length, nums2.length <= 500`
- `1 <= nums1[i], nums2[j] <= 2000`


## [思考](code.cpp)
