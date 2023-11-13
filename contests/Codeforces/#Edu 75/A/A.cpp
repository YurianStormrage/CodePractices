#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int q;
char s[502];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    q = read();
    while(q--)
    {
        bool ans[26] = {false};
        scanf("%s",s);
        int lim = strlen(s);
        if(s[0] != s[1]) ans[s[0]-'a'] = 1;
        for(int i = 1; i < lim; ++i)
        {
            if(s[i] != s[i-1] && s[i] != s[i+1]) ans[s[i]-'a'] = 1;
            else if(s[i] == s[i-1]) s[i] = s[i-1] = '0';
        }
        for(int i = 0; i < 26; ++i) if(ans[i]) putchar(i+'a'); printf("\n");
    }
    return 0;
}