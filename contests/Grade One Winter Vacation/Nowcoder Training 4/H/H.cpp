#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)2e5+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int n;
int pri[N], pf[N], cnt;
int gcd(int a, int b) {return b? gcd(b, a%b) : a;}
int main()
{
    for(int i = 2; i < N; ++i)
    {
        if(!pf[i]) pri[++cnt] = pf[i] = i;
        for(int j = 1; j <= cnt && i*pri[j] < N; ++j)
        {
            pf[i*pri[j]] = pri[j];
            if(i%pri[j] == 0) break;
        }
    }

    int T = read();
    while(T--)
    {
        n = read();
        int ans = 0, mat[N] = {0};
        for(int i = 2, lim = n>>1; i <= lim; ++i) if(!mat[i])
            ++ans, mat[i] = i<<1, mat[i<<1] = i;

        int pr[2] = {0};
        bool pt = 0;
        for(int i = (n>>1)+1; i <= n; ++i)
        {
            if(mat[i] || pf[i] == i) continue;
            pr[pt] = i; pt ^= 1;
            if(pt == 0)
            {
                int x = pr[0], y = pr[1];
                int p = pf[x], q = pf[y];
                int ap = mat[p], pq = p*q;
                mat[x] = p;
                mat[p] = x;
                mat[ap] = 0;
                if(ap % q == 0)
                {
                    mat[ap] = y;
                    mat[y] = ap;
                    ++ans;
                }
                else if(mat[pq])
                {
                    if(mat[pq] % q == 0)
                    {
                        mat[mat[pq]] = y;
                        mat[y] = mat[pq];
                        mat[pq] = ap;
                        mat[ap] = pq;
                        ++ans;
                    }
                    else
                    {
                        mat[mat[pq]] = ap;
                        mat[ap] = mat[pq];
                        mat[pq] = y;
                        mat[y] = pq;
                        ++ans;
                    }
                }
                else
                {
                    mat[ap] = pq;
                    mat[pq] = ap;
                    ++ans;
                    pr[0] = pr[1];
                    pt = 1;
                }
            }
        }
        printf("%d\n", ans);
        for(int i = 2; i <= n; ++i) if(mat[i])
        {
            printf("%d %d\n", i, mat[i]);
            mat[mat[i]] = 0;
        }
    }
    return 0;
}