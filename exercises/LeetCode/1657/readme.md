---
title: determine-if-two-strings-are-close
difficulty: Medium
date: 2023-11-30 21:24:21
url: https://leetcode.cn/problems/determine-if-two-strings-are-close/
tags:
    - Simulation
---
# [1657. 确定两个字符串是否接近](https://leetcode.cn/problems/determine-if-two-strings-are-close/)
## 描述
如果可以使用以下操作从一个字符串得到另一个字符串，则认为两个字符串 **接近** ：


- 操作 1：交换任意两个 **现有** 字符。

	
	- 例如，<code>a**b**cd**e** -> a**e**cd**b**</code>
	
	
- 操作 2：将一个 **现有** 字符的每次出现转换为另一个 **现有** 字符，并对另一个字符执行相同的操作。
	
	- 例如，<code>**aa**c**abb** -> **bb**c**baa**</code>（所有 ``a`` 转化为 ``b`` ，而所有的 ``b`` 转换为 ``a`` ）
	
	


你可以根据需要对任意一个字符串多次使用这两种操作。

给你两个字符串，``word1`` 和 ``word2`` 。如果<em> </em>``word1``<em> </em>和<em> </em>``word2``<em> </em>**接近 **，就返回 ``true`` ；否则，返回<em> </em>``false``<em> </em>。


## 样例
### 示例 1：

```
输入：word1 = "abc", word2 = "bca"
输出：true
解释：2 次操作从 word1 获得 word2 。
执行操作 1："abc" -> "acb"
执行操作 1："acb" -> "bca"
```

### 示例 2：

```
输入：word1 = "a", word2 = "aa"
输出：false
解释：不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。
```

### 示例 3：

```
输入：word1 = "cabbba", word2 = "abbccc"
输出：true
解释：3 次操作从 word1 获得 word2 。
执行操作 1："cabbba" -> "caabbb"
执行操作 2："caabbb" -> "baaccc"
执行操作 2："baaccc" -> "abbccc"
```

### 示例 4：

```
输入：word1 = "cabbba", word2 = "aabbss"
输出：false
解释：不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。
```


## 限制


- <code>1 <= word1.length, word2.length <= 10<sup>5</sup></code>
- ``word1`` 和 ``word2`` 仅包含小写英文字母


## [思考](./code.cpp)
统计每个字符的数量

先判断出现的字符的种类是否相同（不能生成**非现有**字符、不能删除**现有**字符）

再判断所有字符的数量能否找到对应

P.S. 给出最小操作数的方案？
