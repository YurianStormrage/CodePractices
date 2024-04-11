# Gosper's Hack
二进制枚举算法

问题：寻找`n`个二进制位中`k`个`1`的下一个排列。

```c
// Gosper's Hack
int lb = cur & -cur;
int r = cur + lb;
cur = ((cur ^ r) >> 2) / lb | r;
```
`O(1)`复杂度找到下一个二进制排列。
`std::next_permutation()`可以实现类似效果。
但该算法只使用位运算，而库函数需要借助容器表示排列且复杂度更高。