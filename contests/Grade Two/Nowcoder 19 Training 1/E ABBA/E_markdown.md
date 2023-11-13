# E. ABBA

## 题目描述
Bobo has a string of length $2(n + m)$ which consists of characters `A` and `B`. The string also has a fascinating property: it can be decomposed into $(n + m)$ sub-sequences of length $2$, and among the $(n + m)$ subsequences $n$ of them are `AB` while other $m$ of them are `BA`.

Given n and m, find the number of possible strings modulo $(10^{9}+7)$.

## 题解
首先研究合法串 s 的性质。
s由$(n+m)$个`A`和$(n+m)$个`B`组成，因此s最多能分解为n+m个`AB`或`BA`。
由于s能分解为n个`AB`和m个`BA`，故考虑一种分解方式：

> s中前n个`A`用于`AB`，之后m个`A`用于`BA`，`B`同理。

考虑到s的任意合法分解方式都能转化为上述分解方式，可以以该分解方式为基础对s计数：

> $f[i][j]$ 表示s的前缀的方案数，这些前缀都由 $i$ 个`A`和 $j$ 个`B`组成。
> 考虑第 $(i+j+1)$ 位 (以第1位为始) 为`A`时：
> 1. 若 $i<n$ ，则该位的`A`与之后的`B`组成`AB`。
> 2. 若 $i>=n$ ，则该位的`A`与之前的`B`组成`BA`。
> 此时必须保证该位之前还有剩余的`B`相匹配，即： $j > i-n$ 。
>
> 故 $i < n || j > i-n$ 时， $f[i+1][j] += f[i][j]$
> 
> 第 $(i+j+1)$ 位 (以第1位为始) 为`B`时，同理有：
> 当 $j < m || i > j-m$ 时， $f[i][j+1] += f[i][j]$

## 代码
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 2, mod = 1e9 + 7;

int n, m;
int f[N][N];

int main()
{
    while(scanf("%d%d", &n, &m) == 2)
    {
        int len = n + m;
        
        for(int i = 0; i <= len; ++i)
            for(int j = 0; j <= len; ++j)
                f[i][j] = 0;
        f[0][0] = 1;

        for(int i = 0; i <= len; ++i)
            for(int j = 0; j <= len; ++j) {
                if((i < n || j > i - n) && ((f[i+1][j] += f[i][j]) >= mod)) f[i+1][j] -= mod;
                if((j < m || i > j - m) && ((f[i][j+1] += f[i][j]) >= mod)) f[i][j+1] -= mod;
            }
        
        printf("%d\n", f[len][len]);
    }
    return 0;
}
```