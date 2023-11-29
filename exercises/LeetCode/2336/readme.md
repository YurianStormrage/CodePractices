---
title: smallest-number-in-infinite-set
difficulty: Medium
date: 2023-11-29 21:55:11
url: https://leetcode.cn/problems/smallest-number-in-infinite-set/
tags:
    - DataStructure
---
# [2336. 无限集中的最小数字](https://leetcode.cn/problems/smallest-number-in-infinite-set/)
## 描述
现有一个包含所有正整数的集合 ``[1, 2, 3, 4, 5, ...]`` 。

实现 ``SmallestInfiniteSet`` 类：


- ``SmallestInfiniteSet()`` 初始化 **SmallestInfiniteSet** 对象以包含 **所有** 正整数。
- ``int popSmallest()`` **移除** 并返回该无限集中的最小整数。
- ``void addBack(int num)`` 如果正整数 ``num`` **不** 存在于无限集中，则将一个 ``num`` **添加** 到该无限集最后。



### 示例：

```
输入
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
输出
[null, null, 1, 2, 3, null, 1, 4, 5]

解释
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 已经在集合中，所以不做任何变更。
smallestInfiniteSet.popSmallest(); // 返回 1 ，因为 1 是最小的整数，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 2 ，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 3 ，并将其从集合中移除。
smallestInfiniteSet.addBack(1);    // 将 1 添加到该集合中。
smallestInfiniteSet.popSmallest(); // 返回 1 ，因为 1 在上一步中被添加到集合中，
                                   // 且 1 是最小的整数，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 4 ，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 5 ，并将其从集合中移除。
```


## 限制


- ``1 <= num <= 1000``
- 最多调用 ``popSmallest`` 和 ``addBack`` 方法 **共计** ``1000`` 次


## [思考](./code.cpp)
bitset

`bitset`的`_Find_first()`方法是分块枚举，每次枚举`sizeof(_WordT)`个字节，其中`_WordT`为`unsigned long`。

## [题解](./solution.cpp)
set

维护假pop的次数`t`，当真正需要插入时（`num < t`时），将`num`插入`set`。
pop时先判断set是否为空。set为空说明没有比`t`小的数存在，`++t`并返回其值；否则返回set中的最小值并删除它。