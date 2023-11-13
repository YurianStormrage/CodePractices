#include <cstdio>
#include <cstring>
typedef long long ll;
const int M = 62;
int n, m;
char num[42][402];
char f[42][M][402];
int pre[42][M];

bool check(char *a, char *b, int T, char *tmp)
{
    int t = T;
    int i;
    strcpy(tmp, b);
    for(i = 0; i < m && t; ++i)
    {
        if(tmp[i] != a[i])
        {
            tmp[i] = a[i];
            --t;
        }
    }
    if(strcmp(tmp, a) >= 0) return 1;
    for(--i; i >= 0 && tmp[i] == '9';) --i;
    if(i < 0) return 0;
    strcpy(tmp, b);
    t = T;
    for(int j = 0; j < i; ++j)
    {
        if(tmp[j] != a[j])
        {
            tmp[j] = a[j];
            --t;
        }
    }
    if(tmp[i] != a[i] + 1)
    {
        tmp[i] = a[i] + 1;
        --t;
    }
    for(++i; i < m && t; ++i)
    {
        tmp[i] = '0';
        if(tmp[i] != b[i]) --t;
    }
    return 1;
}

void print(int i, int j)
{
    if(!i) return;
    print(i - 1, pre[i][j]);
    printf("%s\n", f[i][j]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", num[i]);
    memset(f, 0, sizeof(0));
    for(int i = 0; i < m; ++i) f[0][0][i] = '0';
    f[0][0][m] = '\0';
    memset(pre, -1, sizeof(pre));
    pre[0][0] = 0;
    char tmp[402];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(~pre[i][j])
            {
                for(int k = 0; k <= m && j + k < M; ++k)
                {
                    if(check(f[i][j], num[i+1], k, tmp) && (pre[i+1][j+k] == -1 || strcmp(tmp, f[i+1][j+k]) < 0))
                    {
                        pre[i+1][j+k] = j;
                        strcpy(f[i+1][j+k], tmp);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < M; ++i) if(pre[n][i] != -1) {ans = i; break;}
    print(n, ans);
    return 0;
}