#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}

const int N = (int)2e5 + 2;

int n;
int s[N][2], len[N];
int num[26][26];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        char S[10];
        scanf("%s", S);
        s[i][0] = S[0]-'a';
        len[i] = strlen(S);
        s[i][1] = S[len[i]-1]-'a';
    }
    int ans = 0;
    for(int i = n; i >= 1; --i)
    {
        //num[s[i][0]][s[i][0]] = max(num[s[i][0]][s[i][0]], num[s[i][0]][s[i][1]] + num[s[i][1]][s[i][0]]);
        for(int j = 0; j < 26; ++j)
        {
            if(/*j != s[i][0] && */ num[s[i][1]][j])
                num[s[i][0]][j] = max(num[s[i][0]][j], len[i] + num[s[i][1]][j]);
        }
        num[s[i][0]][s[i][1]] = max(num[s[i][0]][s[i][1]], len[i]);
        ans = max(ans, num[s[i][0]][s[i][0]]);
    }
    printf("%d", ans);
    return 0;
}