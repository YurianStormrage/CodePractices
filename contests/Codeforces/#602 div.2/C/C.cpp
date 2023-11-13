#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

typedef long long ll;

int q, n, k;
char s[2002], t[2002];
vector<pair<int,int>>ans;

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
        n = read(); k = read();
        scanf("%s",s);
        for(int i = ((k-1)<<1)-1; i > 0; i -= 2)
        {
            t[i-1] = '(';
            t[i] = ')';
        } 
        int l = (k-1)<<1, r = n-1;
        while(l < r)
        {
            t[l] = '(';
            t[r] = ')';
            l++; r--;
        }
        for(int i = 0; i < n; ++i)
        {
            while(i < n && s[i]==t[i]) ++i;
            int j = i;
            if(i == n) break;
            while(j < n && s[j]!=t[i]) ++j;
            ans.push_back({i+1, j+1});
            l = i, r = j;
            while(l < r)
            {
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                ++l, --r;
            }
        }
        printf("%d\n",ans.size());
        for(auto it : ans) printf("%d %d\n",it.first, it.second);
        ans.clear();
    }
    return 0;
}