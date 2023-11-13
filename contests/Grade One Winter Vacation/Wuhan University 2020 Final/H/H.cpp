#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch-48);
    if(f) return -x;
    return x;
}

int main()
{
    int q = read();
    char sk[3][10] = {"ora", "muda", "zawaluduo"};
    int len[3] = {3, 4, 9};
    while(q--)
    {
        int n, h;
        scanf("%d%d", &n, &h);
        char s[20010], c;
        int kill[2] = {n+1, n+1}, flag[2] = {0}, dmg[2] = {0};

        for(int k = 0; k <= 1; ++k)
        {
            int p = 0, r = 0;
            scanf("%s", s);
            for(int i = 0; i < n; ++i)
            {
                c = s[i];
                if(c != sk[2][r]) r = 0;
                if(c == sk[2][r]) ++r;
                if(r == len[2])
                {
                    kill[k] = i;
                    flag[k] = 1;
                    break;
                }
                if(c != sk[k][p]) p = 0;
                if(c == sk[k][p]) ++p;
                if(p == len[k])
                {
                    p = 0;
                    if(++dmg[k] == h)
                    {
                        kill[k] = i;
                        break;
                    }
                }
            }
        }
        //printf("%d %d %d\n%d %d %d", kill[0], flag[0], dmg[0], kill[1], flag[1], dmg[1]);
        int t = -1;
        if(kill[0] < kill[1]) t = 0;
        else if(kill[0] > kill[1]) t = 1;
        else if(flag[1]) t = 1;
        else if(flag[0]) t = 0;
        else if(dmg[0] < dmg[1]) t = 1;
        else if(dmg[0] > dmg[1]) t = 0;

        if(t == -1) puts("Kono Dio da");
        else if(t == 0) puts("Wryyyyy");
        else puts("Hinnjaku");
    }
    return 0;
}