#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)2e6+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int q;
char s[N<<1];
int len, pos;
int main()
{
    scanf("%s", s);
    len = strlen(s);
    for(int i = 0; i < len; ++i)
    {
        s[i+len] = s[i];
    }
    q = read();
    while(q--)
    {
        char mdl = getchar();
        int sym = read();
        if(mdl == 'M')
        {
            pos += sym;
            if(pos >= len) pos -= len;
            else if(pos < 0) pos += len;
            /*
            if(sym > 0)
            {
                pos += sym;
                if(pos >= len) pos -= len;
            }
            else
            {
                pos += sym;
                if(pos < 0) pos += len;
            }
            */
        }
        else printf("%c\n", s[pos+sym-1]);
    }
    return 0;
}