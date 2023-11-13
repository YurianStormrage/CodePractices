#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)1e6 + 2;
char s[N];
int next[N];
void getNext(char *s, int *next)
{
    int len = strlen(s);
    int i = 0, j = -1;
    next[0] = -1;
    while(i < len)
    {
        if(j == -1 || s[j] == s[i])
        {
            ++i; ++j;
            next[i] = j;
        }
        else j = next[j];
    }
}
int main()
{
    while(scanf("%s", s) != EOF && strcmp(s, "."))
    {
        getNext(s, next);
        int len = strlen(s);
        if(len % (len - next[len]) == 0) printf("%d\n", len / (len - next[len]));
        else printf("1\n");
    }
    return 0;
}