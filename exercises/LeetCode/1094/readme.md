---
title: car-pooling
difficulty: Medium
date: 2023-12-02 18:29:47
url: https://leetcode.cn/problems/car-pooling/
tags:
    - 差分
---
# [1094. 拼车](https://leetcode.cn/problems/car-pooling/)
## 描述
车上最初有 ``capacity`` 个空座位。车 **只能 **向一个方向行驶（也就是说，**不允许掉头或改变方向**）

给定整数 ``capacity`` 和一个数组 ``trips`` ,  <code>trip[i] = [numPassengers<sub>i</sub>, from<sub>i</sub>, to<sub>i</sub>]</code> 表示第 ``i`` 次旅行有 <code>numPassengers<sub>i</sub></code> 乘客，接他们和放他们的位置分别是 <code>from<sub>i</sub></code> 和 <code>to<sub>i</sub></code> 。这些位置是从汽车的初始位置向东的公里数。

当且仅当你可以在所有给定的行程中接送所有乘客时，返回 ``true``，否则请返回 ``false``。


## 样例
### 示例 1：

```
输入：trips = [[2,1,5],[3,3,7]], capacity = 4
输出：false
```

### 示例 2：

```
输入：trips = [[2,1,5],[3,3,7]], capacity = 5
输出：true
```


## 限制


- ``1 <= trips.length <= 1000``
- ``trips[i].length == 3``
- <code>1 <= numPassengers<sub>i</sub> <= 100</code>
- <code>0 <= from<sub>i</sub> < to<sub>i</sub> <= 1000</code>
- <code>1 <= capacity <= 10<sup>5</sup></code>


## [思考](./code.cpp)
区间加化为差分

前缀和还原