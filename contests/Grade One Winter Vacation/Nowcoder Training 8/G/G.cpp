#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 260, M = N*N*2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int n;
int card[N][4];
map<string, int> MAP;

int tot, hd[N], nxt[M], to[M];
inline void addedge(int u, int v)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;
    nxt[++tot] = hd[v]; hd[v] = tot; to[tot] = u;
}

inline bool check(int a, int b)
{
    for(int i = 0; i < 4; ++i)
        if(card[a][i] && card[b][i] && card[a][i] == card[b][i])
            return 0;
    return 1;
}

int main()
{
    MAP["*"] = 0;
    MAP["one"] = 1; MAP["two"] = 2; MAP["three"] = 3;
    MAP["diamond"] = 10; MAP["squiggle"] = 20; MAP["oval"] = 30;
    MAP["solid"] = 100; MAP["striped"] = 200; MAP["open"] = 300;
    MAP["red"] = 1000; MAP["green"] = 2000; MAP["purple"] = 3000;
    for(int T = read(); T--;)
    {
        n = read();
        char sta[40], s[10];
        for(int i = 1; i <= n; ++i)
        {
            scanf("%s", sta);
            int len = strlen(sta);
            int cnt = 0;
            for(int j = 0; j < len;)
            {
                if(sta[j++] == '[')
                {
                    int pos = 0;
                    while(sta[j] != ']') s[pos++] = sta[j++];
                    s[pos] = 0;
                    string tmp = s;
                    card[i][cnt++] = MAP[tmp];
                }
            }
        }
        /*
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < 4; ++j) printf("%d ", card[i][j]);
            puts("");
        }
        */
        for(int i = 1; i <= n; ++i)
        {
            for(int j = i + 1; j <= n; ++j)
                if(check(i, j))
                    addedge(i, j);
        }

        for(int i = 1; i <= n; ++i);
    }
    return 0;
}