#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int main()
{
    int num[2][3] = {{0}};
    int ans = 0;
    for(int i = 0; i <= 1; ++i)
    {
        char x;
        for(int j = 0; j <= 2; ++j)
        {
            for(int k = 0; k <= 1; ++k)
            {
                x = getchar();
                num[i][j] = num[i][j]*10 + (x^48);
            }
            getchar();
        }
    }
    bool p = 0;
    for(int i = 0; i <= 2; ++i)
    {
        if(num[0][i] < num[1][i])
        {
            p = 1;
            break;
        }
        else if(num[0][i] > num[1][i])
        {
            p = 0;
            break;
        }
    }
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j <= 2; ++j)
            printf("%d ", num[i][j]);
    }
    printf("%d\n", p);
    for(int i = 2; i > 0; --i)
    {
        if(num[p][i] < num[p^1][i])
        {
            num[p][i-1]--;
            num[p][i] += 60;
        }
    }
    ans += (num[p][0]-num[p^1][0])*60*60;
    ans += (num[p][1]-num[p^1][1])*60;
    ans += (num[p][2]-num[p^1][2]);
    printf("%d", ans);
    return 0;
}