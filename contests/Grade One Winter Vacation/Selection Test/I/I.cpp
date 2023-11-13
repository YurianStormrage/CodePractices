#include <cstdio>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    if(f) return -x;
    return x;
}
int main()
{
    int n;
    char pic[102][102];
    scanf("%d", &n);
    int l = -1, r = -1;
    for(int i = 0; i < n; ++i) scanf("%s", pic[i]);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(pic[i][j] == '1')
            {
                l = j;
                break;
            }
        }
        for(int j = n-1; j >= 0; --j)
        {
            if(pic[i][j] == '1')
            {
                r = j;
                break;
            }
        }
        if(l == -1) continue;
        int x = r-l-1;
        if(l == r)
        {
            printf("1");
            return 0;
        }
        if(pic[i][r-1] == '0')
        {
            printf("4");
            return 0;
        }
        if(pic[i+1][l] == '0')
        {
            if(pic[i+1+x][l+1] == '0')
            {
                printf("7");
                return 0;
            }
            if(pic[i+2+x][l] == '1')
            {
                printf("2");
                return 0;
            }
            printf("3");
            return 0;
        }
        if(pic[i+1][r] == '0')
        {
            if(pic[i+2+x][l] == '0')
            {
                printf("5");
                return 0;
            }
            printf("6");
            return 0;
        }
        if(pic[i+1+x][l+1] == '0')
        {
            printf("0");
            return 0;
        }
        if(pic[i+2+x][l] == '0')
        {
            printf("9");
            return 0;
        }
        printf("8");
        return 0;
    }
    return 0;
}