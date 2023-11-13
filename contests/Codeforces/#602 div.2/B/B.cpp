#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N = (int)1e5+2;

int q, n;
int tot, ans[N];
bool used[N];

inline ll read()
{
	ll x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x;
}

int main()
{
    q = read();
    while(q--)
    {
        n = read();
        int x, last = read();
        int rest = last-1, min = 1;
        bool flag = 0;
        ans[tot++] = last;
        used[last] = 1;
        for(int i = 1; i < n; ++i)
        {
            x = read();
            if(x == last)
            {
                if(--rest < 0) flag = 1;
                while(used[min]) ++min;
                ans[tot++] = min;
                used[min] = 1;
            }
            else
            {
                rest += x-last-1;
                ans[tot++] = x;
                used[x] = 1;
                last = x;
            }
        }
        if(rest || flag) printf("-1\n");
        else
        {
            for(int i = 0; i < n; ++i) printf("%d ",ans[i]);
            puts("");
        }
        tot = 0;
        for(int i = 1; i <= n; ++i) used[i] = 0;
    }
    return 0;
}