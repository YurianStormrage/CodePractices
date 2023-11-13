#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}

const int N = 202;

int n, m;
char clo[N][N];
int l[N], r[N];

struct segment
{
    int len, id; 
} seg[N];

inline bool cmp(segment a, segment b) {return a.len > b.len;}

inline int findl(int x) {return x == l[x]? x : l[x] = findl(l[x]);}
inline int findr(int x) {return x == r[x]? x : r[x] = findr(r[x]);}

int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", clo[i]);
        }

        int len[N][N];
        bool vis[N];
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            len[i][m-1] = 1;
            for(int j = m-2; j >= 0; --j)
                len[i][j] = clo[i][j] == clo[i][j+1]? len[i][j+1]+1 : 1;
        }
        for(int j = 0; j < m; ++j)
        {
            for(int i = 0; i < n; ++i)
            {
                seg[i].len = len[i][j];
                seg[i].id = i;
                l[i] = r[i] = i;
                vis[i] = 0;
            }
            sort(seg, seg+n, cmp);
            for(int i = 0; i < n; ++i)
            {
                int now = seg[i].id;
                vis[now] = 1;
                if(now > 0 && vis[now-1] && clo[now][j] == clo[now-1][j])
                {
                    l[now] = now-1;
                    r[now-1] = now;
                }
                if(now < m-1 && vis[now+1] && clo[now][j] == clo[now+1][j])
                {
                    r[now] = now+1;
                    l[now+1] = now;
                }
                ans = max(ans, min(findr(now)-findl(now)+1, seg[i].len));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}