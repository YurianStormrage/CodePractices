#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
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

inline bool cmp(int a, int b) {return a > b;}

const int N = (int)1e5+2;

int n, m;
int a[N];

int main()
{
    int q = read();
    while(q--)
    {
        n = read(); m = read();
        for(int i = 1; i <= n; ++i) a[i] = read();
        int scr = a[1], rk = 0, M = m;
        bool flag = 0;
        sort(a+1, a+1+n, cmp);
        //printf("%d %d\n", a[1], scr);
        for(int i = 1; i <= n; ++i)
        {
            if(a[i] == scr) flag = 1;
            if(a[i] != scr && flag) {rk = i-1; break;}
        }
        if(!rk) rk = n;
        //printf("%d\n", rk);
        for(int i = n; m > 0 && i >= rk; --i, --m) a[i]++;
        if(!m)
        {
            a[n-M+1]--;
            a[rk]++;
        }
        for(int i = 1; m > 0; --m, ++i) a[i]++;
        //for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
        sort(a+1, a+1+n, cmp);
        scr++; rk = 0; flag = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(a[i] == scr) flag = 1;
            if(a[i] != scr && flag) {rk = i-1; break;}
        }
        if(!rk) rk = n;
        printf("%d\n", rk);
    }
    return 0;
}