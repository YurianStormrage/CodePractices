#include <cstdio>
#include <cstring>
const int N = 110;
int q, len;
char s[N];
bool e[26], flag = 0;
inline int read()
{
    int x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
    return f? x : -x;
}
int main()
{
    q = read();
    for(int i = 1; i <= q; ++i)
    {
        scanf("%s",s);
        len = strlen(s);
        for(int j = 0; j < len; ++j) e[s[j]-'a'] = 1;
        scanf("%s",s);
        for(int j = 0; j < len; ++j)
        {
            if(e[s[j]-'a'])
            {
                printf("YES\n");
                flag = true;
                break;
            }
        }
        for(int i = 0; i < 26; ++i) e[i] = 0;
        if(!flag) printf("NO\n");
        flag = false;
    }
    return 0;
}