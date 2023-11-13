#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)1e6+2, M = (int)2e6+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int p;

bool vis[N];

int main()
{
    //freopen("tabel.out", "r", stdin);
    //freopen("A.out", "w", stdout);
    //int T = read();
    //printf("%d\n", T);
    for(int T = read(); T--;)
    {
        p = read();
        //printf("%d ", p);
        if(p == 2) {printf("1\n"); continue;}
        if(p == 3) {printf("1 2\n"); continue;}
        for(int i = 1; i < p; ++i) vis[i] = 0;
        int tmp = 3 % p, cnt_3 = 1;
        while(tmp != 1)
        {
            vis[tmp] = 1;
            cnt_3++;
            tmp = tmp * 3 % p;
        }
        vis[1] = 1;
        tmp = 2 % p;
        int cnt_2 = 1;
        while(!vis[tmp])
        {
            ++cnt_2;
            tmp = (tmp << 1) % p;
        }
        if(cnt_2 * cnt_3 != p - 1) {printf("-1\n"); continue;}
        printf("1 ");
        tmp = 1;
        for(int i = 2; i < p; ++i)
        {
            if((i - 1) % cnt_3) tmp = tmp * 3 % p;
            else tmp = (tmp << 1) % p;
            printf("%d ", tmp);
        }
        puts("");
    }
    return 0;
}