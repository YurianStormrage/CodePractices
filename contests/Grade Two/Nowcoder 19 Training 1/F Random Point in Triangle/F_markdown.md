# F. Random Point in Triangle

## 题目描述
Bobo has a triangle ABC with $A(x_1, y_1)$, $B(x_2, y_2)$ and $C(x_3, y_3)$. Picking a point $P$ uniformly in triangle $ABC$, he wants to know the expectation value $E(max\{S_{PAB},S_{PBC},S_{PCA}\})$ where $S_{XYZ}$ denotes the area of triangle $XYZ$.

Print the value of $36\times E$ . It can be proved that it is always an integer.

## 题解
重心、两条中线、顶点及两边围成的区域对应的底边为同一条。
记 $S_{ABC}$ 为 $S$ ,积分得 $E=22 \times S$ 。已知三顶点坐标，用叉乘法计算三角形面即可。

## 代码
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for (; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f ? x : -x;
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    while(scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
        ll a = x2 - x1, b = y2 - y1;
        ll c = x3 - x1, d = y3 - y1;
        ll ans = abs(a * d - b * c);
        printf("%lld\n", ans * 11);
    }
    return 0;
}
```