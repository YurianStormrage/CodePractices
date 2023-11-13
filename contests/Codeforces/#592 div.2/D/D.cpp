#include <cstdio>
const int N = (int)1e5+1;
typedef long long ll;
int n;
int c[3][N];
bool flag[N][2];
int hd[N] = {0}, nx[N<<1] = {0}, to[N<<1] = {0}, tot = 0;
int tmp[N], ans[N];

inline int read()
{
    int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

inline void addedge(int u, int v)
{
    nx[++tot] = hd[u]; hd[u] = tot; to[tot] = v;
    nx[++tot] = hd[v]; hd[v] = tot; to[tot] = u;
}

int main()
{
    n = read();
    for(int j = 0; j < 3; ++j)
        for(int i = 1; i <= n; ++i)
            c[j][i] = read();
    for(int i = 1; i < n; ++i)
    {
        int u = read(), v = read();
        addedge(u, v);
        if(flag[u][1] || flag[v][1])
        {
            printf("-1");
            return 0;
        }
        flag[u][flag[u][0]] = true;
        flag[v][flag[v][0]] = true;
    }

    int t = 0, u, v, que[3];
    ll Tmp = 0, Ans = (ll)1e18;
    for(int i = 1; i <= n; ++i) if(!flag[i][1]) {t = i; break;}
    for(int k = 0; k < 3; ++k)
    {
        que[2] = k+1;
        for(int j = 0; j < 2; ++j)
        {
            que[j] = (k+1)%3+1; que[j^1] = (k+2)%3+1;
            u = 0; v = t; Tmp = 0;
            int pt = 0;
            while(v)
            {
                Tmp += c[que[pt]-1][v];
                tmp[v] = que[pt];
                int tmpv = to[hd[v]];
                if(tmpv == u) {u = v; v = to[nx[hd[v]]];}
                else u = v, v = tmpv;
                if(++pt == 3) pt = 0;
            }
            if(Ans > Tmp)
            {
                Ans = Tmp;
                for(int i = 1; i <= n; ++i) ans[i] = tmp[i];
            } 
        }
    }

    printf("%lld\n",Ans);
    for(int i = 1; i <= n; ++i) printf("%d ",ans[i]);
    return 0;
}