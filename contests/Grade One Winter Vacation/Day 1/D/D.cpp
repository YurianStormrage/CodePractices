#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)1e3 + 2;
int m;

ll rea()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int main()
{
    char str[N], ans[N];
    int len, cnt;
    while(scanf("%s%d", str, &m) != EOF)
    {
        len = strlen(str);
        if(m == len) {printf("0\n"); continue;}
        cnt = -1;
        for(int i = 0; i < len; ++i)
        {
            while(m && cnt >= 0 && ans[cnt] > str[i]) --cnt, --m;
            ans[++cnt] = str[i];
        }
        while(m--) --cnt;
        int j = 0;
        for(; j < cnt && ans[j] == '0'; ++j);
        for(; j <= cnt; ++j) printf("%c", ans[j]);
        printf("\n");
    }
    return 0;
}