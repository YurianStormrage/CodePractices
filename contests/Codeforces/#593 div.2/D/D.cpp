#include <cstdio>
typedef long long ll;
const int N = (int)1e5+1;
int n, m, k;
int hd[N][2], nxt[N<<1], pos[N<<1], tot = 0;
ll ans, tmpAns;
int flag = 0, x = 1, y = 1, tmp, lim[4];
inline int read()
{
    int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline void add(int x, int y)
{
    nxt[++tot] = hd[x][0]; hd[x][0] = tot; pos[tot] = y;
    nxt[++tot] = hd[y][1]; hd[y][1] = tot; pos[tot] = x;
}
inline void solve()
{
    while(true)
    {
        if(flag == 0)
        {
            tmp = lim[0];
            for(int i = hd[x][0]; i; i = nxt[i]) if(y < pos[i] && tmp > pos[i]) tmp = pos[i];
            tmpAns += --tmp-y;
            y = lim[0] = tmp;
            flag = 1;
            if(tmpAns == ans) break;
            else ans = tmpAns;
        }
        else if(flag == 1)
        {
            tmp = lim[1];
            for(int i = hd[y][1]; i; i = nxt[i]) if(x < pos[i] && tmp > pos[i]) tmp = pos[i];
            tmpAns += --tmp-x;
            x = lim[1] = tmp;
            flag = 2;
            if(tmpAns == ans) break;
            else ans = tmpAns;
        }
        else if(flag == 2)
        {
            tmp = lim[2];
            for(int i = hd[x][0]; i; i = nxt[i]) if(y > pos[i] && tmp < pos[i]) tmp = pos[i];
            tmpAns += y-++tmp;
            y = lim[2] = tmp;
            flag = 3;
            if(tmpAns == ans) break;
            else ans = tmpAns;
        }
        else if(flag == 3)
        {
            tmp = lim[3];
            for(int i = hd[y][1]; i; i = nxt[i]) if(x > pos[i] && tmp < pos[i]) tmp = pos[i];
            tmpAns += x-++tmp;
            x = lim[3] = tmp;
            flag = 0;
            if(tmpAns == ans) break;
            else ans = tmpAns;
        }
    }
}
int main()
{
//    n = read(); m = read(); k = read();
//    for(int i = 1; i <= k; ++i) add(read(), read());
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1; i <= k; ++i)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        add(x, y);
    }

    ans = tmpAns = k+1;
    lim[0] = m+1; lim[1] = n+1; lim[2] = 0; lim[3] = 1;
    solve();

    if(ans == (ll)n*m) printf("Yes");
    else
    {
        ans = tmpAns = k+1;
        flag = x = y = 1; lim[0] = m+1; lim[1] = n+1; lim[2] = 0; lim[3] = 1;
        solve();
        if(ans == (ll)n*m) printf("Yes");
        else printf("No");
    }
    return 0;
}