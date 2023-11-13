#include <cstdio>
#define Min(a, b) ((a)<(b)? (a):(b))
typedef long long ll;
const int N = (int)1e3+2;
int q, n, m;
int hd[N], nxt[N], to[N], tot;
int dfn[N], low[N], inx, stk[N], fa[N], tmp;
bool ins[N], out[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

inline void addedge(int u, int v) {nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;}

void tarjan(int u)
{
    dfn[u] = low[u] = ++inx;
    ins[stk[++stk[0]] = u] = true;
    for(int i = hd[u]; i; i = nxt[i])
    {
        if(!dfn[to[i]])
        {
            tarjan(to[i]);
            low[u] = Min(low[to[i]], low[u]);
        }
        else if(ins[to[i]]) low[u] = Min(dfn[to[i]], low[u]);
        if(!ins[to[i]]) out[u] = true;
    }

    if(dfn[u] == low[u])
    {
        int top;
        do
        {
            top = stk[stk[0]];
            if(out[top]) out[u] = true;
            fa[top] = u;
            ins[top] = false;
            --stk[0];
        }while(u != top);
        if(!out[u]) tmp = u;
    }
}

int main()
{
    q = read();
    while(q--)
    {
        n = read(); m = read();
        
        tot = 0;
        for(int i = 1; i <= n; ++i) hd[i] = 0;
        while(m--)
        {
            int u = read(), v = read();
            if(u != v) addedge(u, v);
        }

        int cnt = 0;
        inx = 0; tmp = 0;
        for(int i = 1; i <= n; ++i) dfn[i] = low[i] = out[i] = 0, fa[i] = i;
        for(int i = 1; i <= n; ++i)
        {
            if(!dfn[i]) tarjan(i);
            cnt += dfn[i] == low[i];
        }

        if(cnt == 1) printf("No\n");
        else
        {
            int ans[2][N];
            ans[0][0] = ans[1][0] = 0;
            for(int i = 1; i <= n; ++i)
            {
                if(fa[i] == tmp) ans[0][++ans[0][0]] = i;
                else ans[1][++ans[1][0]] = i;
            }
            printf("Yes\n%d %d\n",ans[0][0], ans[1][0]);
            for(int i = 1; i <= ans[0][0]; ++i) printf("%d ",ans[0][i]); printf("\n");
            for(int i = 1; i <= ans[1][0]; ++i) printf("%d ",ans[1][i]); printf("\n");
        }
    }
    return 0;
}