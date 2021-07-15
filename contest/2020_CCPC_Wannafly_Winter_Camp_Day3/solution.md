## C 无向图定向

### description
火山哥手里有一个 $n$ 个点 $m$ 条边的无向图。
现在，火山哥请你把无向图的每条边确定一个方向，使之成为一个$DAG$，并且最小化最长路的长度。
这里一条路径的长度指的是经过边的数量。
#### input
> 第一行两个整数 $n,m$，分别表示图的点数和边数。
> 接下来 $m$ 行，每行两个正整数 $u,v$，表示一条无向图。
> 输入数据保证无重边无自环，点编号从 $1$ 开始。
> $1\le n\le 17$, $1\le m \le 136$。
#### output
> 一个整数，表示最短的最长路。

### example
#### case 1
>##### input
>> 3 3
>> 1 2
>> 2 3
>> 1 3
>##### output
>> 2
#### case 2
>##### input
>> 5 4
>> 1 2
>> 2 3
>> 3 4
>> 4 5
>##### output
>> 1

### hint
> $DAG$指有向无环图

### solution
$Dilworth$定理：对于任意有限偏序集，其最大反链中元素的数目必等于最小链划分中链的数目。此定理的对偶形式亦真，它断言：对于任意有限偏序集，其最长链中元素的数目必等于其最小反链划分中反链的数目。
$DAG$可以视为一个偏序集，所以求$DAG$最长路长度的问题可以转化为求最小反链划分中的反链数目的问题。
具体来说，无向图中两两之间没有边相连的点可以视为一个集合。划分点集，使集合的数目最少即可。最长链的长度为最小数目$-1$。

### code
```cpp
// 偏序集最长链的元素数目等于最小反链划分的反链数目
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    while(ch > '9' || ch < '0') {if(ch == '-') f = 0; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x<<1)+(x<<3)+(ch^48); ch = getchar();}
    return f ? x : -x;
}

const int N = 20;
int n, m;
bool edge[N][N];
int vertex_color[N];
int cnt = 0, ans = N;

bool check_color(const int& u, const int& c)
{
    for(int i = 1; i <= n; ++i)
        if(edge[u][i] && vertex_color[i] == c)
            return false;
    return true;
}

void dfs(const int& u)
{
    if(cnt > ans) return ;
    if(u > n) {
        ans = min(ans, cnt);
        return ;
    }
    for(int i = 1; i <= cnt; ++i) // don't start with 0
        if(check_color(u, i)) {
            vertex_color[u] = i;
            dfs(u + 1);
            vertex_color[u] = 0;
        }
    ++ cnt;
    vertex_color[u] = cnt;
    dfs(u + 1);
    vertex_color[u] = 0;
    -- cnt;
}

int main()
{
    n = read(); m = read();
    for(int i = 0, u, v; i < m; ++i) {
        u = read(), v = read();
        edge[u][v] = edge[v][u] = 1;
    }
    dfs(1);
    printf("%d", ans - 1);
    return 0;
}
```