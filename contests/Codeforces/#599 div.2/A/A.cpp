#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int k, n;
int ch[200];
char s[50], t[50];
int main()
{
k = read();
while(k--)
{
n = read();
scanf("%s%s",s,t);
for(int i = 0; i < n; ++i)
{
ch[s[i]]++;
ch[t[i]]++;
}
bool flag = 0;
for(int i = 'a'; i <= 'z'; ++i)
{
if(ch[i]&1) flag = 1;
ch[i] = 0;
}
if(flag) puts("No");
else
{
puts("Yes");
vector<pair<int,int>> ans;
for(int i = 0; i < n; ++i)
{
if(s[i] != t[i])
for(int j = i+1; j < n; ++j)
{
if(s[j] == s[i]) {ans.push_back({j,i}); break;}
if(t[j] == s[i]) {ans.push_back({j,j});ans.push_back({j,i});break;}
}
}
printf("%d",ans.size());
for(auto it:ans) printf("%d %d\n",it.first,it.second);
}
}
}