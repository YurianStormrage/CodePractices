#include <cstdio>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = (int)5e5+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int n, k;
int s[N];
unordered_map<int, int> q;
bool b[N];

int main()
{
    for(int T = read(); T--;)
    {
        n = read(); k = read();
        for(int i = 1; i <= n; ++i) s[i] = read();

        q.clear();
        
        if(k >= n)
        {
            int flag = 0;
            for(int i = 1; i <= n; ++i)
                if(q[s[i]]++)
                {
                    if(flag++) break;
                    q.clear();
                    q[s[i]] = 1;
                }
            if(flag <= 1) printf("YES\n");
            else printf("NO\n");
            continue;
        }
        
        int cnt = 0;
        
        for(int i = 1; i <= n; ++i) b[i] = 0;
        
        for(int i = 1; i <= k; ++i)
        {
            if(++q[s[i]] == 1) ++cnt;
            else if(q[s[i]] == 2) --cnt;
        }
        b[1] = cnt == k;
        
        for(int i = k + 1; i <= n; ++i)
        {
            if(!--q[s[i-k]]) --cnt;
            else if(q[s[i-k]] == 1) ++cnt;
            if(++q[s[i]] == 1) ++cnt;
            else if(q[s[i]] == 2) --cnt;
            b[i-k+1] = cnt == k;
        }
        q.clear();
        for(int i = n; i >= n-k+2; --i)
        {
            if(q[s[i]]++) break;
            b[i] = 1;
        }

        //for(int i = 1; i <= n; ++i) printf("%d ", b[i]); puts("");

        bool flag = 0;
        q.clear();
        for(int i = 1, j; i <= k; ++i)
        {
            for(j = i; j <= n-k+1; j += k) if(!b[j]) break;
            if(j > n || (j + k - 1 > n && b[j])) {flag = 1; break;}
            if(q[s[i]]++) break;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}